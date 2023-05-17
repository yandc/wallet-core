// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Address.h"

#include "../Base58.h"
#include "../Coin.h"
#include "../HexCoding.h"

#include <TrezorCrypto/cash_addr.h>
#include <stdexcept>

using namespace TW;
using namespace TW::Kaspa;


bool Address::isValid(const std::string& string, const std::string& hrp) noexcept {
    size_t outlen;
    std::array<uint8_t, 256> result;
    if(cash_addr_decode(result.data(), &outlen, hrp.c_str(), string.c_str())) {
        return true;
    }
    return false;
}

Address::Address(const std::string& string) {
    size_t outlen;
    std::array<uint8_t, 256> result;
    size_t pos = string.rfind(':');
    if(cash_addr_decode(result.data(), &outlen, string.substr(0, pos).c_str(), string.c_str())) {
        append(bytes, data(result.data(), outlen));
    }
}

Address::Address(const PublicKey& publicKey, const std::string& hrp) {
    hrp_ = hrp;
    bytes.push_back(1);//version
    append(bytes, publicKey.bytes);
}

std::string Address::string() const {
    std::array<char, 256> result;
    cash_addr_encode(result.data(), hrp_.c_str(), bytes.data(), bytes.size());
    return result.data();
}
