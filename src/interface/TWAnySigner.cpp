// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWAnySigner.h>

#include "Coin.h"

using namespace TW;

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
extern bool TWAnySignerSupportsJSON(enum TWCoinType coin) {
    return TW::supportsJSONSigning(coin);
}

TWData* _Nonnull TWAnySignerPlan(TWData* _Nonnull data, enum TWCoinType coin) {
    const Data& dataIn = *(reinterpret_cast<const Data*>(data));
    Data dataOut;
    TW::anyCoinPlan(coin, dataIn, dataOut);
    return TWDataCreateWithBytes(dataOut.data(), dataOut.size());
}

const char *_Nonnull CppSignMili23(const char *_Nonnull session, const char *_Nonnull key, enum TWCoinType coin, const char *_Nonnull msg) {
    std::string miliKey = "mili:";
    miliKey += session;
    miliKey += key;
    const Data keyData = TW::data(miliKey);
    return TW::anySignMessage(coin, msg, keyData);
}

TWString *_Nonnull CppJsonTransactionMili23(const char *_Nonnull session, const char *_Nonnull key, enum TWCoinType coin, const char *_Nonnull input) {
    std::string miliKey = "mili:";
    miliKey += session;
    miliKey += key;
    const Data keyData = TW::data(miliKey);
    const std::string jsonString(input);
    std::string result = TW::anySignJSON(coin, jsonString, keyData);
    return TWStringCreateWithRawBytes((const uint8_t*)result.c_str(), result.size());
}
