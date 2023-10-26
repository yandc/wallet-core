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

namespace TW::Sui {

class Address {
  public:
    static const size_t size = 32;
    std::array<uint8_t, size> bytes;

    /// Determines whether a collection of bytes makes a valid  address.
    static bool isValid(const Data& data) { return data.size() == size; }

    /// Determines whether a string makes a valid address.
    static bool isValid(const std::string& address) {
      size_t pos1 = address.find("::");
      if (pos1 != std::string::npos) {
        size_t pos2 = address.find("::", pos1+2);
        if(pos2 == std::string::npos) return false;
        return Address::isValid(address.substr(0, pos1));
      }

      std::string rawAddr = address;
      if (address.find("BFC") == 0) {
        rawAddr = address.substr(3, 64);
        std::string checkSum = hex(Hash::sha256(rawAddr));
        if (address.substr(67, 4) != checkSum.substr(0, 4)) {
            return false;
        }

      } else if (address[0] != '0' || address[1] != 'x') {
          return false;
      }

      const auto data = parse_hex(rawAddr, true);
      return Address::isValid(data);
    }

    Address(const std::string& address) {
      std::string rawAddr = address;
      if (address.find("BFC") == 0) {
        rawAddr = address.substr(3, 64);
        std::string checkSum = hex(Hash::sha256(rawAddr));
        if (address.substr(67, 4) != checkSum.substr(0, 4)) {
            return;
        }
      }
      Data data = parse_hex(rawAddr, true);
      TW::pad_left(data, size);
      if (!isValid(data)) {
          throw std::invalid_argument("Invalid address data");
      }
      std::copy(data.begin(), data.end(), bytes.begin());
    }

    /// Initializes a Kusama address with a public key.
    Address(const PublicKey& publicKey) {
      Data hash_data = {0};
      append(hash_data, Data(publicKey.bytes.begin(), publicKey.bytes.end()));
      auto hash = Hash::blake2b(hash_data, 32);
      std::copy(hash.begin(), hash.begin()+size, bytes.begin());
    }

    std::string string() const {
      return hexEncoded(bytes);
    }
};
} // namespace TW::Aptos
