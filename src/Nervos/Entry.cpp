// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Entry.h"

#include "Address.h"
#include "Signer.h"
#include "TransactionPlan.h"
#include <google/protobuf/util/json_util.h>
#include <TrustWalletCore/MiliException.h>
#include <nlohmann/json.hpp>

namespace TW::Nervos {
using namespace std;

bool Address::isTestNet = false;

bool Entry::validateAddress(TWCoinType coin, const string& address, byte, byte,
                            const char* hrp) const {
    return Address::isValid(address, hrp);
}

string Entry::deriveAddress(TWCoinType coin, const PublicKey& publicKey, byte,
                            const char* hrp) const {
    return Address(publicKey, hrp).string();
}

void Entry::sign(TWCoinType coin, const Data& dataIn, Data& dataOut) const {
    signTemplate<Signer, Proto::SigningInput>(dataIn, dataOut);
}

void Entry::plan(TWCoinType coin, const Data& dataIn, Data& dataOut) const {
    planTemplate<Signer, Proto::SigningInput>(dataIn, dataOut);
}

string Entry::signJSON(TWCoinType coin, const std::string& json, const Data& key) const {
    if(coin == TWCoinTypeNervosTest) Address::isTestNet = true;
    return Signer::signJSON(json, key);
}

std::string Entry::planJson(TWCoinType coin, const std::string& jsonInput) const {
    if(coin == TWCoinTypeNervosTest) Address::isTestNet = true;
    auto input = Proto::SigningInput();
    google::protobuf::util::JsonStringToMessage(jsonInput, &input);
    TransactionPlan plan;
    plan.plan(input);
    nlohmann::json j = {
        {"utxo_size", 0},
        {"amount", toString(plan.outputCapacity)},
        {"sudt_amount", toString(plan.outputSudtAmount)},
        {"fee", toString(plan.feeAmount)}
    };
    if(plan.error != Common::Proto::OK) {
        j["error"] = ERROR_INFOS[int(plan.error)].what();
    } else {
        j["utxo_size"] = 1;
    }
    return j.dump();
}
} // namespace TW::Nervos
