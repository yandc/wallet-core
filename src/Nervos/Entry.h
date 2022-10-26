// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../CoinEntry.h"

using namespace TW;

namespace TW::Nervos {

/// Entry point for implementation of Nervos coin.
/// Note: do not put the implementation here (no matter how simple), to avoid having coin-specific
/// includes in this file
class Entry: public CoinEntry {
public:
    const std::vector<TWCoinType> coinTypes() const { return {TWCoinTypeNervos}; }
    bool validateAddress(TWCoinType coin, const std::string& address, byte p2pkh, byte p2sh,
                         const char* hrp) const;
    std::string deriveAddress(TWCoinType coin, const PublicKey& publicKey, byte p2pkh,
                              const char* hrp) const;
    void sign(TWCoinType coin, const Data& dataIn, Data& dataOut) const;
    void plan(TWCoinType coin, const Data& dataIn, Data& dataOut) const;
    bool supportsJSONSigning() const { return true; }
    std::string signJSON(TWCoinType coin, const std::string& json, const Data& key) const;
    std::string planJson(TWCoinType coin, const std::string& jsonInput) const;
};

} // namespace TW::Nervos
