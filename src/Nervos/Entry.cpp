// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Entry.h"

#include "Address.h"
#include "Signer.h"
#include <google/protobuf/util/json_util.h>
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
    auto input = Proto::SigningInput();
    google::protobuf::util::JsonStringToMessage(jsonInput, &input);
    auto plan = Signer::plan(input);
    uint64_t inputCapacity(0), outputCapacity(0);
    for(int i=0; i < plan.selected_cells_size(); i++) {
        inputCapacity += plan.selected_cells(i).capacity();
    }
    for(int i=0; i < plan.outputs_size(); i++) {
        outputCapacity += plan.outputs(i).capacity();
    }
    nlohmann::json  planJson = {
        {"utxo_size", plan.selected_cells_size()},
        {"amount", plan.outputs(0).capacity()},
        {"fee", inputCapacity-outputCapacity}
    };
    return planJson.dump();
}
} // namespace TW::Nervos
