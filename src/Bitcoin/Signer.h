// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once
#include "../proto/Bitcoin.pb.h"
#include "Data.h"
#include "CoinEntry.h"

#include <vector>
#include <optional>
#include <utility>
#include <TrustWalletCore/TWCoinType.h>

namespace TW::Bitcoin {

typedef std::vector<std::pair<Data, Data>> SignaturePubkeyList;

class Signer {
  public:
    Signer() = delete;

    /// Returns a transaction plan (utxo selection, fee estimation)
    static Proto::TransactionPlan plan(const Proto::SigningInput& input) noexcept;

    /// Signs a Proto::SigningInput transaction
    static Proto::SigningOutput sign(const Proto::SigningInput& input, std::optional<SignaturePubkeyList> optionalExternalSigs = {});

    /// Collect pre-image hashes to be signed
    static HashPubkeyList preImageHashes(const Proto::SigningInput& input) noexcept;

    /// Signs a json Proto::SigningInput with private key
    static std::string signJSON(TWCoinType coin, const std::string& json, const Data& key);
};

} // namespace TW::Bitcoin
