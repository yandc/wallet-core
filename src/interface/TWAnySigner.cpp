// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWAnySigner.h>
#include <TrustWalletCore/MiliException.h>
#include <nlohmann/json.hpp>

#include "Coin.h"
#include "HexCoding.h"

using namespace TW;
using json = nlohmann::json;

TWData* _Nonnull TWAnySignerSign(TWData* _Nonnull data, enum TWCoinType coin) {
    const Data& dataIn = *(reinterpret_cast<const Data*>(data));
    Data dataOut;
    TW::anyCoinSign(coin, dataIn, dataOut);
    return TWDataCreateWithBytes(dataOut.data(), dataOut.size());
}

TWString *_Nonnull TWAnySignerSignJSON(TWString *_Nonnull json, TWData *_Nonnull key, enum TWCoinType coin) {
    const Data& keyData = *(reinterpret_cast<const Data*>(key));
    const std::string& jsonString = *(reinterpret_cast<const std::string*>(json));
    auto result = TW::anySignJSON(coin, jsonString, keyData);
    return TWStringCreateWithUTF8Bytes(result.c_str());
}

TWString *_Nonnull CppJsonTransactionPrivateKey(const char *_Nonnull json, const char *_Nonnull key, enum TWCoinType coin) {
    Data keyData = TW::parse_hex(key);
    std::string jsonTxInput = json;
    auto result = TW::anySignJSON(coin, jsonTxInput, keyData);
    return TWStringCreateWithUTF8Bytes(result.c_str());
}

extern bool TWAnySignerSupportsJSON(enum TWCoinType coin) {
    return TW::supportsJSONSigning(coin);
}

TWData* _Nonnull TWAnySignerPlan(TWData* _Nonnull data, enum TWCoinType coin) {
    const Data& dataIn = *(reinterpret_cast<const Data*>(data));
    Data dataOut;
    TW::anyCoinPlan(coin, dataIn, dataOut);
    return TWDataCreateWithBytes(dataOut.data(), dataOut.size());
}

TWString *_Nonnull CppSignMili23(const char *_Nonnull session, const char *_Nonnull key, const char *_Nonnull preSign, enum TWCoinType coin, const char *_Nonnull msg) {
    std::string miliKey = "mili:";
    miliKey += session;
    miliKey += ":";
    size_t len = miliKey.size();
    miliKey += preSign;
    if(len == miliKey.size()) miliKey += "[]";
    miliKey += key;
    Data keyData = TW::data(miliKey);
    keyData.push_back(0);//确保是cstr的0结尾
    json txJson;
    try {
        txJson["result"] = std::string(TW::anySignMessage(coin, msg, keyData));
        txJson["status"] = true;
        txJson["error"] = "";
    } catch (MiliException& e) {
        txJson["result"] = "";
        txJson["status"] = false;
        txJson["error"] = e.what();
    }
    std::string result = txJson.dump();
    return TWStringCreateWithRawBytes((const uint8_t*)result.c_str(), result.size());
}

TWString *_Nonnull CppJsonTransactionMili23(const char *_Nonnull session, const char *_Nonnull key, const char *_Nonnull preSign, enum TWCoinType coin, const char *_Nonnull input) {
    std::string miliKey = "mili:";
    miliKey += session;
    miliKey += ":";
    size_t len = miliKey.size();
    miliKey += preSign;
    if(len == miliKey.size()) miliKey += "[]";
    miliKey += key;
    Data keyData = TW::data(miliKey);
    keyData.push_back(0);//确保是cstr的0结尾
    const std::string jsonString(input);

    json txJson;
    txJson["txid"] = "";
    txJson["result"] = "";
    txJson["status"] = false;
    txJson["error"] = "";
    try {
        std::string result = TW::anySignJSON(coin, jsonString, keyData);
        size_t pos = result.find("#");
        if (pos != std::string::npos) {
            txJson["txid"] = result.substr(0, pos);
            txJson["result"] = result.substr(pos+1);
            txJson["status"] = true;
        } else {
            txJson["error"] = "loss of txid";
        }
    } catch (MiliException& e) {
        txJson["error"] = e.what();

    } catch (std::invalid_argument& e) {
        txJson["error"] = e.what();
    }
    std::string result = txJson.dump();
    return TWStringCreateWithRawBytes((const uint8_t*)result.c_str(), result.size());
}

TWString *_Nonnull CppUtxoPlan(enum TWCoinType coin, const char *_Nonnull input) {
    std::string result = TW::anyCoinPlanJson(coin, input);
    return TWStringCreateWithRawBytes((const uint8_t*)result.c_str(), result.size());
}