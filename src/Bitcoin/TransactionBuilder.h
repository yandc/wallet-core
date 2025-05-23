// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "SigningInput.h"
#include "Transaction.h"
#include "TransactionPlan.h"
#include "InputSelector.h"
#include "../proto/Bitcoin.pb.h"
#include <TrustWalletCore/TWCoinType.h>

#include <optional>
#include <algorithm>

namespace TW::Bitcoin {

class TransactionBuilder {
public:
    /// Plans a transaction by selecting UTXOs and calculating fees.
    static TransactionPlan plan(const SigningInput& input);

    /// Builds a transaction with the selected input UTXOs, and one main output and an optional change output.
    template <typename Transaction>
    static Transaction build(const TransactionPlan& plan, const SigningInput& input) {
        Transaction tx;
        tx.lockTime = input.lockTime;

        if (input.toAddress.size() > 0) {
            auto outputTo = prepareOutputWithScript(input.toAddress, plan.amount, input.coinType);
            if (!outputTo.has_value()) { return {}; }
            tx.outputs.push_back(outputTo.value());
        }

        for (auto& o: input.outputs) {
            auto output = prepareOutputWithScript(o.first, o.second, input.coinType);
            if (!output.has_value()) { return {}; }
            tx.outputs.push_back(output.value());
        }

        if (plan.change > 0) {
            auto outputChange = prepareOutputWithScript(input.changeAddress, plan.change, input.coinType);
            if (!outputChange.has_value()) { return {}; }
            tx.outputs.push_back(outputChange.value());
        }

        const auto emptyScript = Script();
        for (auto& utxo : plan.utxos) {
            tx.inputs.emplace_back(utxo.outPoint, emptyScript, utxo.outPoint.sequence);
        }

        // Optional OP_RETURN output
        if (plan.outputOpReturn.size() > 0) {
            auto lockingScriptOpReturn = Script::buildOpReturnScript(plan.outputOpReturn);
            auto emplace_at = tx.outputs.end();
            if (input.outputOpReturnIndex >= 0) {
                emplace_at = tx.outputs.begin();
                std::advance(emplace_at, input.outputOpReturnIndex);
            }
            if (emplace_at > tx.outputs.end()) {
                emplace_at = tx.outputs.end();
            }
            tx.outputs.emplace(emplace_at, 0, lockingScriptOpReturn);
        }

        return tx;
    }

    /// Prepares a TransactionOutput with given address and amount, prepares script for it
    static std::optional<TransactionOutput> prepareOutputWithScript(std::string address, Amount amount, enum TWCoinType coin);

    /// The maximum number of UTXOs to consider.  UTXOs above this limit are cut off because it cak take very long.
    static const size_t MaxUtxosHardLimit;
};

} // namespace TW::Bitcoin
