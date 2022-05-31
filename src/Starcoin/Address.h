// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Hash.h"
#include "../HexCoding.h"
#include "../Data.h"
#include "../PublicKey.h"

#include <string>

namespace TW::Starcoin {

class Address {
  public:
    static const size_t size = 16;
    std::array<uint8_t, size> bytes;

    /// Determines whether a collection of bytes makes a valid  address.
    static bool isValid(const Data& data) { return data.size() == size; }

    /// Determines whether a string makes a valid address.
    static bool isValid(const std::string& string) {
      if (string.size() != 34 || string[0] != '0' || string[1] != 'x') {
          return false;
      }
      const auto data = parse_hex(string);
      return Address::isValid(data);
    }

    /// Initializes a Kusama address with a string representation.
    Address(const std::string& string) {
      if (!isValid(string)) {
          throw std::invalid_argument("Invalid address data");
      }
      const auto data = parse_hex(string);
      std::copy(data.begin(), data.end(), bytes.begin());
    }

    /// Initializes a Kusama address with a public key.
    Address(const PublicKey& publicKey) {
      Data hash_data(publicKey.bytes.begin(), publicKey.bytes.end());
      append(hash_data, 0);
      auto hash = Hash::sha3_256(hash_data);
      std::copy(hash.begin() + 16, hash.end(), bytes.begin());
    }

    std::string string() const {
      return hexEncoded(bytes);
    }
};
} // namespace TW::Starcoin

