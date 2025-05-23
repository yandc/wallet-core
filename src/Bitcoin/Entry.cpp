// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Entry.h"

#include "Address.h"
#include "CashAddress.h"
#include "SegwitAddress.h"
#include "Signer.h"
#include <TrustWalletCore/MiliException.h>
#include <nlohmann/json.hpp>

using namespace TW::Bitcoin;
using namespace TW;
using namespace std;

bool Entry::validateAddress(TWCoinType coin, const string& address, byte p2pkh, byte p2sh, const char* hrp) const {
    switch (coin) {
        case TWCoinTypeBitcoin:
        case TWCoinTypeDigiByte:
        case TWCoinTypeLitecoin:
        case TWCoinTypeMonacoin:
        case TWCoinTypeQtum:
        case TWCoinTypeViacoin:
        case TWCoinTypeBitcoinGold:
            return SegwitAddress::isValid(address, hrp)
                || Address::isValid(address, {{p2pkh}, {p2sh}});

        case TWCoinTypeBitcoinCash:
            return BitcoinCashAddress::isValid(address)
                || Address::isValid(address, {{p2pkh}, {p2sh}});

        case TWCoinTypeECash:
            return ECashAddress::isValid(address)
                   || Address::isValid(address, {{p2pkh}, {p2sh}});

        case TWCoinTypeDash:
        case TWCoinTypeDogecoin:
        case TWCoinTypeRavencoin:
        case TWCoinTypeFiro:
        default:
            return Address::isValid(address, {{p2pkh}, {p2sh}});
    }
}

string Entry::normalizeAddress(TWCoinType coin, const string& address) const {
    switch (coin) {
        case TWCoinTypeBitcoinCash:
            // normalized with bitcoincash: prefix
            if (BitcoinCashAddress::isValid(address)) {
                return BitcoinCashAddress(address).string();
            } else {
                return std::string(address);
            }

        case TWCoinTypeECash:
            // normalized with ecash: prefix
            if (ECashAddress::isValid(address)) {
                return ECashAddress(address).string();
            } else {
                return std::string(address);
            }

        default:
            // no change
            return address;
    }
}

string Entry::deriveAddress(TWCoinType coin, const PublicKey& publicKey, byte p2pkh, const char* hrp) const {
    switch (coin) {
        case TWCoinTypeBitcoin:
        case TWCoinTypeDigiByte:
        case TWCoinTypeLitecoin:
        case TWCoinTypeViacoin:
        case TWCoinTypeBitcoinGold:
            return SegwitAddress(publicKey, hrp).string();

        case TWCoinTypeBitcoinCash:
            return BitcoinCashAddress(publicKey).string();

        case TWCoinTypeECash:
            return ECashAddress(publicKey).string();

        case TWCoinTypeDash:
        case TWCoinTypeDogecoin:
        case TWCoinTypeMonacoin:
        case TWCoinTypeQtum:
        case TWCoinTypeRavencoin:
        case TWCoinTypeFiro:
        default:
            return Address(publicKey, p2pkh).string();
    }
}

void Entry::sign(TWCoinType coin, const Data& dataIn, Data& dataOut) const {
    signTemplate<Signer, Proto::SigningInput>(dataIn, dataOut);
}

string Entry::signJSON(TWCoinType coin, const std::string& json, const Data& key) const {
    return Signer::signJSON(coin, json, key);
}

void Entry::plan(TWCoinType coin, const TW::Data& dataIn, TW::Data& dataOut) const {
    planTemplate<Signer, Proto::SigningInput>(dataIn, dataOut);
}

std::string Entry::planJson(TWCoinType coin, const std::string& jsonInput) const {
    const Proto::TransactionPlan& plan = Signer::planJson(coin, jsonInput);
    if(plan.error() != Common::Proto::OK) {
        nlohmann::json j = {{"utxo_size", 0}, {"amount", 0}, {"fee", 0},{"error", ERROR_INFOS[int(plan.error())].what()}};
        return j.dump();
    }
    nlohmann::json j = {
        {"utxo_size", plan.utxos_size()},
        {"amount", plan.amount()},
        {"fee", plan.fee()}
    };
    return j.dump();
}

HashPubkeyList Entry::preImageHashes(TWCoinType coin, const Data& txInputData) const {
    auto input = Proto::SigningInput();
    auto ret = HashPubkeyList();
    if (input.ParseFromArray(txInputData.data(), (int)txInputData.size())) {
        ret = Signer::preImageHashes(input);
    }
    return ret;
}

void Entry::compile(TWCoinType coin, const Data& txInputData, const std::vector<Data>& signatures, const std::vector<PublicKey>& publicKeys, Data& dataOut) const {
    auto input = Proto::SigningInput();
    if (input.ParseFromArray(txInputData.data(), (int)txInputData.size())) {
        HashPubkeyList externalSignatures;
        auto n = std::min(signatures.size(), publicKeys.size());
        for (auto i = 0; i < n; ++i) {
            externalSignatures.push_back(std::make_pair(signatures[i], publicKeys[i].bytes));
        }

        auto serializedOut = Signer::sign(input, externalSignatures).SerializeAsString();
        dataOut.insert(dataOut.end(), serializedOut.begin(), serializedOut.end());
    }
}
