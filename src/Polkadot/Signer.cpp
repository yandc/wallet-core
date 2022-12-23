// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"
#include "Extrinsic.h"
#include "../Hash.h"
#include "../PrivateKey.h"
#include "HexCoding.h"
#include <google/protobuf/util/json_util.h>

using namespace TW;
using namespace TW::Polkadot;

static constexpr size_t hashTreshold = 256;

Proto::SigningOutput Signer::sign(const Proto::SigningInput &input) noexcept {
    auto privateKey = PrivateKey(Data(input.private_key().begin(), input.private_key().end()));
    auto publicKey = privateKey.getPublicKey(TWPublicKeyTypeED25519);
    auto extrinsic = Extrinsic(input);
    auto payload = extrinsic.encodePayload();
    // check if need to hash
    if (payload.size() > hashTreshold) {
        payload = Hash::blake2b(payload, 32);
    }
    auto signature = privateKey.sign(payload, TWCurveED25519);
    auto encoded = extrinsic.encodeSignature(publicKey, signature);

    auto protoOutput = Proto::SigningOutput();
    protoOutput.set_encoded(encoded.data(), encoded.size());
    return protoOutput;
}

std::string Signer::signJSON(const std::string& json, const Data& key) {
    auto input = Proto::SigningInput();
    google::protobuf::util::JsonStringToMessage(json, &input);
    input.set_private_key(key.data(), key.size());
    //input.set_nonce(0);
    input.set_network(input.chain_id());
    auto era = input.mutable_era();
    era->set_period(512);
    era->set_block_number(input.block_number());
    auto output = Signer::sign(input);
    return hex(output.encoded());
}
