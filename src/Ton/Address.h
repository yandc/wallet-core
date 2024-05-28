// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../HexCoding.h"
#include "../Data.h"
#include "../PublicKey.h"
#include "../Base64.h"

#include <string>

namespace TW::Ton {

class Address {
  public:
    static const size_t size = 36;
    Data bytes;

    /// Determines whether a collection of bytes makes a valid  address.
    static bool isValid(const Data& data) { return data.size() == size; }

    /// Determines whether a string makes a valid address.
    static bool isValid(const std::string& address) {
      const auto data = Base64::decodeBase64Url(address);
      return Address::isValid(data);
    }

    Address(const std::string& address) {
      bytes = Base64::decodeBase64Url(address);
    }

    Address(const PublicKey& publicKey);

    std::string string() const {
      return Base64::encodeBase64Url(bytes);
    }
};
} // namespace TW::Aptos
