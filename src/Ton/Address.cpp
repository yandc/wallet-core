// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Address.h"
#include <nlohmann/json.hpp>
#include <iostream>

using namespace TW::Ton;
using json = nlohmann::json;

extern std::string CallGolangRpc(const char* method, const char* params);

Address::Address(const PublicKey& publicKey) {
      if (publicKey.bytes.size() != PublicKey::ed25519Size) {
          throw std::invalid_argument("Invalid public key data size");
      }
      std::string res = CallGolangRpc("GetTonAccountInfo", hex(publicKey.bytes).c_str());
      json accountInfo = json::parse(res);
      std::string address = accountInfo["Address"].get<std::string>();
      bytes = Base64::decodeBase64Url(address);
}
