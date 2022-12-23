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

namespace TW::Casper {

class Address {
  public:
    std::vector<uint8_t> bytes;

    /// Determines whether a collection of bytes makes a valid  address.
    static bool isValid(const Data& data) { return data.size() == 33 || data.size() == 34; }

    /// Determines whether a string makes a valid address.
    static bool isValid(const std::string& address) {
      std::string pubType = address.substr(0, 2);

      if ((pubType == "01" && address.size() == 66) ||
          (pubType == "02" && address.size() == 68)) {
          return true;
      }
      return false;
    }

    Address(const std::string& string) {
      if(!isValid(string)) {
        throw std::invalid_argument("Invalid address data");
      }
      Data data = parse_hex(string, true);
      bytes.insert(bytes.end(), data.begin(), data.end());
    }

    Address(const PublicKey& publicKey) {
      bytes.push_back(1); //1: eddsa key, 2: ecdsa key
      bytes.insert(bytes.end(), publicKey.bytes.begin(), publicKey.bytes.end());
    }

    std::string string() const {
      return hex(bytes);
    }
};
} // namespace TW::Aptos

