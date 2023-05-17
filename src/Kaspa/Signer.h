// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../proto/Bitcoin.pb.h"
#include "../proto/Kaspa.pb.h"
#include "Bitcoin/Signer.h"

#include <memory>
#include <string>
#include <vector>

namespace TW::Kaspa {

/// Helper class that performs Decred transaction signing.
class Signer: public Bitcoin::Signer {
public:
  static Proto::SigningOutput sign(const Bitcoin::Proto::SigningInput& input);
  static std::string signJSON(TWCoinType coin, const std::string& json, const Data& key);
};

} // namespace TW::Decred
