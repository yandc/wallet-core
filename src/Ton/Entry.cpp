// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Entry.h"
#include "Address.h"

#include "../HexCoding.h"
#include "../Hash.h"
#include "../Base64.h"
#include "../Base58.h"
#include "../PrivateKey.h"

#include "../bcs.hpp"

#include <TrustWalletCore/MiliException.h>
#include <nlohmann/json.hpp>
#include <chrono>
#include <stdlib.h>

using namespace TW::Ton;
using namespace std;
using json = nlohmann::json;
using namespace std::chrono;

extern string CallGolangRpc(const char* method, const char* params);

// Note: avoid business logic from here, rather just call into classes like Address, Signer, etc.

bool Entry::validateAddress(TWCoinType coin, const string& address, TW::byte, TW::byte, const char*) const {
    return Address::isValid(address);
}

string Entry::deriveAddress(TWCoinType coin, const PublicKey& publicKey, TW::byte, const char* hrp) const {
    return Address(publicKey).string();
}

void Entry::sign(TWCoinType coin, const TW::Data& dataIn, TW::Data& dataOut) const {
    return;
}

string Entry::signJSON(TWCoinType coin, const std::string& jsonTx, const Data& key) const {
    PrivateKey privKey(key);
    PublicKey pubKey = privKey.getPublicKey(TWPublicKeyTypeED25519);

    json params = {hex(pubKey.bytes), jsonTx};
    string res = CallGolangRpc("MakeTonTx", params.dump().c_str());

    json txInfo = json::parse(res);
    string txDigest = txInfo["TxDigest"].get<string>();
    Data digest = parse_hex(txDigest);
    Data sign = privKey.sign(digest, TWCurveED25519);
    if(sign.size() == 0) {
        throw MiliException{E_SIGN};
    }

    params.push_back(hex(sign));
    res = CallGolangRpc("MakeTonTx", params.dump().c_str());
    txInfo = json::parse(res);

    return txInfo["TxHash"].get<string>() + "#" + txInfo["TxBody"].get<string>();
}
