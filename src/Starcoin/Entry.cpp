// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Entry.h"

#include "Address.h"

#ifdef PLATFORM_WEB
#include <emscripten/emscripten.h>
#endif

using namespace TW::Starcoin;
using namespace std;

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
    let rawTx = GoStcJsonTransactionMili23(UTF8ToString(key), UTF8ToString(jsonTxParam));
    if (!rawTx) {
        return "";
    }
    var len = lengthBytesUTF8(rawTx)+1;
    var stringOnWasmHeap = _malloc(len);
    stringToUTF8(rawTx, stringOnWasmHeap, len);
    return stringOnWasmHeap;
});

string GoStcJsonTransactionMili23(const char* key, const char* jsonTxParam) {
    char* rawTx = StcJsonTransactionMili23(key, jsonTxParam);
    string rawTxString(rawTx);
    free(rawTx);
    return rawTxString;
}

#else

extern "C" {
    extern const char* GoStcJsonTransactionMili23(const char* key, const char* jsonTxParam);
}

#endif

string Entry::signJSON(TWCoinType coin, const std::string& json, const Data& key) const {
    return GoStcJsonTransactionMili23((const char*)key.data(), json.c_str());
}