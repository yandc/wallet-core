// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Entry.h"

#include "Address.h"
#include "Signer.h"

using namespace TW::Kaspa;
using namespace std;

bool Entry::validateAddress(TWCoinType coin, const string& address, TW::byte p2pkh, TW::byte p2sh, const char* hrp) const {
    return Address::isValid(address, hrp);
}

string Entry::deriveAddress(TWCoinType coin, const PublicKey& publicKey, TW::byte p2pkh, const char* hrp) const {
    return Address(publicKey, hrp).string();
}

void Entry::sign(TWCoinType coin, const TW::Data& dataIn, TW::Data& dataOut) const {
    signTemplate<Signer, Bitcoin::Proto::SigningInput>(dataIn, dataOut);
}

string Entry::signJSON(TWCoinType coin, const std::string& json, const Data& key) const {
    return Signer::signJSON(coin, json, key);
}
