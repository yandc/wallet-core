// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Entry.h"

#include "Address.h"
#include <TrustWalletCore/MiliException.h>
#include <nlohmann/json.hpp>

#ifdef PLATFORM_WEB
#include <emscripten/emscripten.h>
#endif

using namespace TW::Starcoin;
using namespace std;
using json = nlohmann::json;

// Note: avoid business logic from here, rather just call into classes like Address, Signer, etc.

bool Entry::validateAddress(TWCoinType coin, const string& address, TW::byte, TW::byte, const char*) const {
    return Address::isValid(address);
}

string Entry::deriveAddress(TWCoinType coin, const PublicKey& publicKey, TW::byte, const char*) const {
    return Address(publicKey).string();
}

void Entry::sign(TWCoinType coin, const TW::Data& dataIn, TW::Data& dataOut) const {
    return;
}

#ifdef PLATFORM_WEB

EM_JS(char*, StcJsonTransactionMili23, (const char* key, const char* jsonTxParam), {
    let jsonTx = GoStcJsonTransactionMili23(UTF8ToString(key), UTF8ToString(jsonTxParam));
    if (!jsonTx) {
        return null;
    }
    var len = lengthBytesUTF8(jsonTx)+1;
    var stringOnWasmHeap = _malloc(len);
    stringToUTF8(jsonTx, stringOnWasmHeap, len);
    return stringOnWasmHeap;
});

string GoStcJsonTransactionMili23(const char* key, const char* jsonTxParam) {
    char* jsonTx = StcJsonTransactionMili23(key, jsonTxParam);
    if(jsonTx == NULL) {
        throw ERROR_INFOS[2];
    }
    json signJson = json::parse(jsonTx);
    free(jsonTx);

    bool status = signJson["status"].get<bool>();
    if(status == false) {
        throw MiliException{signJson["error"].get<std::string>()};
    }
    return signJson["result"].get<std::string>();
}

#else

extern "C" {
    extern const char* GoStcJsonTransactionMili23(const char* key, const char* jsonTxParam);
}

#endif

string Entry::signJSON(TWCoinType coin, const std::string& json, const Data& key) const {
    return GoStcJsonTransactionMili23((const char*)key.data(), json.c_str());
}