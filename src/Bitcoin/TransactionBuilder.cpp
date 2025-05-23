// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "TransactionBuilder.h"
#include "Script.h"
#include "TransactionSigner.h"
#include "SignatureBuilder.h"

#include "../Coin.h"
#include "../proto/Bitcoin.pb.h"

#include <algorithm>
#include <cassert>

namespace TW::Bitcoin {


// Above this number of UTXOs a simplified selection is used (optimization)
static const auto SimpleModeLimit = 1000;
// The maximum number of UTXOs to consider.  UTXOs above this limit are cut off because it cak take very long
const size_t TransactionBuilder::MaxUtxosHardLimit = 3000;

std::optional<TransactionOutput> TransactionBuilder::prepareOutputWithScript(std::string address, Amount amount, enum TWCoinType coin) {
    auto lockingScript = Script::lockScriptForAddress(address, coin);
    if (lockingScript.empty()) {
        return {};
    }
    return TransactionOutput(amount, lockingScript);
}


/// Estimate encoded size by simple formula
int64_t estimateSimpleFee(const FeeCalculator& feeCalculator, const TransactionPlan& plan, int outputSize, int64_t byteFee) {
    return feeCalculator.calculate(plan.utxos.size(), outputSize, byteFee);
}

/// Estimate encoded size by invoking sign(sizeOnly), get actual size
int64_t estimateSegwitFee(const FeeCalculator& feeCalculator, const TransactionPlan& plan, int outputSize, const SigningInput& input) {
    TWPurpose coinPurpose = TW::purpose(static_cast<TWCoinType>(input.coinType));
    if (coinPurpose != TWPurposeBIP84) {
        // not segwit, return default simple estimate
        return estimateSimpleFee(feeCalculator, plan, outputSize, input.byteFee);
    }

    // duplicate input, with the current plan
    auto inputWithPlan = std::move(input);
    inputWithPlan.plan = plan;

    auto result = TransactionSigner<Transaction, TransactionBuilder>::sign(inputWithPlan, SigningMode_SizeEstimationOnly);
    if (!result) {
        // signing failed; return default simple estimate
        return estimateSimpleFee(feeCalculator, plan, outputSize, input.byteFee);
    }

    // Obtain the encoded size
    auto transaction = result.payload();
    Data dataNonSegwit;
    transaction.encode(dataNonSegwit, Transaction::SegwitFormatMode::NonSegwit);
    int64_t sizeNonSegwit = dataNonSegwit.size();
    uint64_t vSize = 0;
    // Check if there is segwit
    if (!transaction.hasWitness()) {
        // no segwit, virtual size is defined as non-segwit size
        vSize = sizeNonSegwit;
    } else {
        Data dataWitness;
        transaction.encodeWitness(dataWitness);
        int64_t witnessSize = 2 + dataWitness.size();
        // compute virtual size:  (smaller) non-segwit + 1/4 of the diff (witness-only)
        // (in other way: 3/4 of (smaller) non-segwit + 1/4 of segwit size)
        vSize = sizeNonSegwit + witnessSize/4 + (witnessSize % 4 != 0);
    }
    uint64_t fee = input.byteFee * vSize;

    return fee;
}

int extraOutputCount(const SigningInput& input) {
    int count = int(input.outputOpReturn.size() > 0);
    return count + int(input.outputs.size());
}

TransactionPlan TransactionBuilder::plan(const SigningInput& input) {
    TransactionPlan plan;
    if (input.outputOpReturn.size() > 0) {
        plan.outputOpReturn = input.outputOpReturn;
    }

    bool maxAmount = input.useMaxAmount;
    if (input.amount == 0 && input.outputsAmount == 0 && !maxAmount) {
        plan.error = Common::Proto::Error_zero_amount_requested;
    } else if (input.utxos.empty()) {
        plan.error = Common::Proto::Error_missing_input_utxos;
    } else {
        const auto& feeCalculator = getFeeCalculator(static_cast<TWCoinType>(input.coinType));
        const int64_t dustThreshold = feeCalculator.calculateSingleInput(input.byteFee);
        std::cout << "dust threshold: " << dustThreshold << std::endl;
        if(dustThreshold > input.amount + input.outputsAmount) {
            std::cout << "dust threshold bigger than input amount!" << std::endl;
            plan.amount = 0;
            return plan;
        }
        auto inputSelector = InputSelector<UTXO>(input.utxos, feeCalculator);
        auto inputSum = InputSelector<UTXO>::sum(input.utxos);

        // select UTXOs
        Amount totalAmount = input.amount + input.outputsAmount;

        // if amount requested is the same or more than available amount, it cannot be satisifed, but
        // treat this case as MaxAmount, and send maximum available (which will be less)
        if (!maxAmount && totalAmount >= inputSum) {
            maxAmount = true;
        }

        auto extraOutputs = extraOutputCount(input);
        auto output_size = int(input.toAddress.size() > 0) + extraOutputs;
        UTXOs selectedInputs;
        if (!maxAmount) {
            if (input.utxos.size() <= SimpleModeLimit && input.utxos.size() <= MaxUtxosHardLimit) {
                selectedInputs = inputSelector.select(totalAmount, input.byteFee, output_size);
            } else {
                selectedInputs = inputSelector.selectSimple(totalAmount, input.byteFee, output_size);
            }
        } else {
            selectedInputs = inputSelector.selectMaxAmount(input.byteFee);
        }
        if (selectedInputs.size() <= MaxUtxosHardLimit) {
            plan.utxos = selectedInputs;
        } else {
            // truncate to limit number of selected UTXOs
            plan.utxos.clear();
            for (auto i = 0; i < MaxUtxosHardLimit; ++i) {
                plan.utxos.push_back(selectedInputs[i]);
            }
        }

        if (plan.utxos.size() == 0) {
            plan.amount = 0;
            plan.error = Common::Proto::Error_not_enough_utxos;
        } else {
            plan.availableAmount = InputSelector<UTXO>::sum(plan.utxos);

            // Compute fee.
            // must preliminary set change so that there is a second output
            if (!maxAmount) {
                assert(totalAmount <= plan.availableAmount);
                plan.amount = input.amount;
                plan.change = plan.availableAmount - totalAmount;
                plan.fee = estimateSegwitFee(feeCalculator, plan, output_size + 1, input);
                plan.change = plan.availableAmount - totalAmount - plan.fee;
                if (plan.change < dustThreshold) {//no change
                    plan.change = 0;
                    plan.fee = plan.availableAmount - totalAmount;
                }
            } else {
                plan.amount = plan.availableAmount;
                plan.fee = 0;
                plan.change = 0;
                plan.fee = estimateSegwitFee(feeCalculator, plan, output_size, input);
            }
            // If fee is larger then availableAmount (can happen in special maxAmount case), we reduce it (and hope it will go through)
            plan.fee = std::min(plan.availableAmount, plan.fee);
            assert(plan.fee >= 0 && plan.fee <= plan.availableAmount);

            // adjust/compute amount
            if (!maxAmount) {
                // reduce amount if needed
                plan.amount = std::max(Amount(0), std::min(plan.amount, plan.availableAmount - plan.fee));
            } else {
                // max available amount
                plan.amount = std::max(Amount(0), plan.availableAmount - plan.fee);
            }
            assert(plan.amount >= 0 && plan.amount <= plan.availableAmount);

            // compute change
            //plan.change = plan.availableAmount - plan.amount - plan.fee;
        }
    }
    assert(plan.change >= 0 && plan.change <= plan.availableAmount);
    assert(!maxAmount || plan.change == 0); // change is 0 in max amount case

    assert(plan.amount + input.outputsAmount + plan.change + plan.fee == plan.availableAmount);

    return plan;
}

} // namespace TW::Bitcoin
