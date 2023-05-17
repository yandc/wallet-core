// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <TrustWalletCore/TWBitcoinSigHashType.h>

#include "Bitcoin/Transaction.h"
#include "../Data.h"

#include "Address.h"
#include "proto/Kaspa.pb.h"

namespace TW::Kaspa {

struct Transaction: public Bitcoin::Transaction {
public:

  Transaction() {};
  void encode(Data& data) const { append(data, TW::data(proto().SerializeAsString())); };

  Proto::Transaction proto() const;

  Data getSignatureHash(const Bitcoin::Script& scriptCode, size_t index, enum TWBitcoinSigHashType hashType,
                        uint64_t amount, enum Bitcoin::SignatureVersion version) const;

private:
  void hashOutpoint(const Bitcoin::OutPoint& outpoint, Data& data) const;
  void hashOutput(const Bitcoin::TransactionOutput output, Data& data) const;
};

} // namespace TW::Decred
