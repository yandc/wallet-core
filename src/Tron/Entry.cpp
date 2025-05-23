// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Entry.h"

#include "Address.h"
#include "Signer.h"
#include "Hash.h"
#include "HexCoding.h"

using namespace TW::Tron;
using namespace std;

// Note: avoid business logic from here, rather just call into classes like Address, Signer, etc.

bool Entry::validateAddress(TWCoinType coin, const string& address, TW::byte, TW::byte, const char*) const {
    return Address::isValid(address);
}

string Entry::deriveAddress(TWCoinType coin, const PublicKey& publicKey, TW::byte, const char*) const {
    return Address(publicKey).string();
}

void Entry::sign(TWCoinType coin, const TW::Data& dataIn, TW::Data& dataOut) const {
    signTemplate<Signer, Proto::SigningInput>(dataIn, dataOut);
}

string Entry::signJSON(TWCoinType coin, const std::string& json, const Data& key) const {
    return Signer::signJSON(json, key);
}

TW::Data Entry::hashMessage(TWCoinType coin, const string& msg) const {
    string m = "\x19""TRON Signed Message:\n32";
    Data msgData = data(msg);
    if(msg.substr(0, 2) == "0x") {
        msgData = parse_hex(msg, true);
    }
    m.append(msgData.begin(), msgData.end());
    return TW::Hash::keccak256((const byte*)m.c_str(), m.size());
}