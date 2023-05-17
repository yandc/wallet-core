// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"
#include "../PublicKey.h"

#include <array>
#include <string>

namespace TW::Kaspa {

class Address {
  public:
    /// Public key hash with prefixes.
    Data bytes;
    std::string hrp_;

    /// Determines whether a string makes a valid  address.
    static bool isValid(const std::string& string, const std::string& hrp) noexcept;

    /// Initializes an address with a string representation.
    explicit Address(const std::string& string);

    /// Initializes an address with a public key.
    explicit Address(const PublicKey& publicKey, const std::string& hrp);

    /// Returns a string representation of the address.
    std::string string() const;
};

inline bool operator==(const Address& lhs, const Address& rhs) {
    return lhs.bytes == rhs.bytes;
}

} // namespace TW::Decred
