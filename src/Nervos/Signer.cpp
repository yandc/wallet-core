// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"
#include "Transaction.h"
#include "TransactionPlan.h"
#include <TrustWalletCore/MiliException.h>
#include <google/protobuf/util/json_util.h>

namespace TW::Nervos {

Proto::TransactionPlan Signer::plan(const Proto::SigningInput& signingInput) noexcept {
    TransactionPlan txPlan;
    txPlan.plan(signingInput);
    return txPlan.proto();
}

Proto::SigningOutput Signer::sign(const Proto::SigningInput& signingInput) {
    Proto::SigningOutput output;
    TransactionPlan txPlan;
    if (signingInput.has_plan()) {
        txPlan = TransactionPlan(signingInput.plan());
    } else {
        txPlan.plan(signingInput);
    }
    if (txPlan.error != Common::Proto::OK) {
        // Planning failed
        output.set_error(txPlan.error);
        return output;
    }

    Transaction tx;
    tx.build(txPlan);
    std::vector<PrivateKey> privateKeys;
    privateKeys.reserve(signingInput.private_key_size());
    for (auto&& privateKey : signingInput.private_key()) {
        privateKeys.emplace_back(privateKey);
    }
    auto error = tx.sign(privateKeys);
    if (error != Common::Proto::OK) {
        // Signing failed
        output.set_error(error);
        return output;
    }

    output.set_transaction_json(tx.json().dump());
    output.set_transaction_id(hexEncoded(tx.hash()));
    output.set_error(Common::Proto::OK);
    return output;
}

std::string Signer::signJSON(const std::string& json, const Data& key) {
    auto input = Proto::SigningInput();
    google::protobuf::util::JsonStringToMessage(json, &input);
    input.add_private_key(key.data(), key.size());
    auto output = Signer::sign(input);
    if(output.error() != Common::Proto::OK) {
        throw ERROR_INFOS[int(output.error())];
    }
    return output.transaction_json();
}

} // namespace TW::Nervos
