// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../CoinEntry.h"

namespace TW::Bitcoin {

/// Bitcoin entry dispatcher.
/// Note: do not put the implementation here (no matter how simple), to avoid having coin-specific includes in this file
class Entry: public CoinEntry {
public:
    virtual const std::vector<TWCoinType> coinTypes() const {
        return {
            TWCoinTypeBitcoin,
            TWCoinTypeBitcoinCash,
            TWCoinTypeBitcoinGold,
            TWCoinTypeDash,
            TWCoinTypeDigiByte,
            TWCoinTypeDogecoin,
            TWCoinTypeECash,
            TWCoinTypeLitecoin,
            TWCoinTypeMonacoin,
            TWCoinTypeQtum,
            TWCoinTypeRavencoin,
            TWCoinTypeViacoin,
            TWCoinTypeFiro,
        };
    }
    virtual bool validateAddress(TWCoinType coin, const std::string& address, TW::byte p2pkh, TW::byte p2sh, const char* hrp) const;
    virtual std::string normalizeAddress(TWCoinType coin, const std::string& address) const;
    virtual std::string deriveAddress(TWCoinType coin, const PublicKey& publicKey, TW::byte p2pkh, const char* hrp) const;
    virtual void sign(TWCoinType coin, const Data& dataIn, Data& dataOut) const;
    virtual void plan(TWCoinType coin, const Data& dataIn, Data& dataOut) const;
    virtual std::string planJson(TWCoinType coin, const std::string& jsonInput) const;

    virtual HashPubkeyList preImageHashes(TWCoinType coin, const Data& txInputData) const;
    virtual void compile(TWCoinType coin, const Data& txInputData, const std::vector<Data>& signatures, const std::vector<PublicKey>& publicKeys, Data& dataOut) const;
    // Note: buildTransactionInput is not implemented for Binance chain with UTXOs
    virtual bool supportsJSONSigning() const { return true; }
    virtual std::string signJSON(TWCoinType coin, const std::string& json, const Data& key) const;
};

} // namespace TW::Bitcoin
