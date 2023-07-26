// Copyright © 2017-2023 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"
#include "../proto/Cosmos.pb.h"
#include "JsonSerialization.h"
#include "ProtobufSerialization.h"

#include "PrivateKey.h"
#include "Data.h"
#include "HexCoding.h"

#include <google/protobuf/util/json_util.h>

using namespace TW;
using namespace TW::Cosmos;

namespace TW::Cosmos {

Proto::SigningOutput Signer::sign(const Proto::SigningInput& input) {
    switch (input.signing_mode()) {
        case Proto::JSON:
            return signJsonSerialized(input);

        case Proto::Protobuf:
        default:
            return signProtobuf(input);
    }
}

Proto::SigningOutput Signer::signJsonSerialized(const Proto::SigningInput& input) {
    auto key = PrivateKey(input.private_key());
    auto preimage = Json::signaturePreimageJSON(input).dump();
    auto hash = Hash::sha256(preimage);
    auto signedHash = key.sign(hash, TWCurveSECP256k1);

    auto output = Proto::SigningOutput();
    auto signature = Data(signedHash.begin(), signedHash.end() - 1);
    auto txJson = Json::transactionJSON(input, signature);
    output.set_json(txJson.dump());
    output.set_signature(signature.data(), signature.size());
    output.set_serialized("");
    output.set_error("");
    output.set_signature_json(txJson["tx"]["signatures"].dump());
    return output;
}

Proto::SigningOutput Signer::signProtobuf(const Proto::SigningInput& input) {
    using namespace Protobuf;
    using namespace Json;

    const auto serializedTxBody = buildProtoTxBody(input);
    const auto serializedAuthInfo = buildAuthInfo(input);
    const auto signature = buildSignature(input, serializedTxBody, serializedAuthInfo);
    auto serializedTxRaw = buildProtoTxRaw(serializedTxBody, serializedAuthInfo, signature);
    std::string txid = hex(Hash::sha256(serializedTxRaw));

    auto output = Proto::SigningOutput();
    const std::string jsonSerialized = buildProtoTxJson(input, serializedTxRaw);
    auto publicKey = PrivateKey(input.private_key()).getPublicKey(TWPublicKeyTypeSECP256k1);
    auto signatures = nlohmann::json::array({signatureJSON(signature, publicKey.bytes)});
    output.set_serialized(txid + "#" + jsonSerialized);
    output.set_signature(signature.data(), signature.size());
    output.set_json("");
    output.set_error("");
    output.set_signature_json(signatures.dump());
    return output;
}

std::string Signer::signJSON(const std::string& json, const Data& key) {
    auto input = Proto::SigningInput();
    google::protobuf::util::JsonStringToMessage(json, &input);
    input.set_private_key(key.data(), key.size());
    input.set_signing_mode(Proto::Protobuf);
    auto output = Signer::sign(input);
    return output.serialized();
}

} // namespace TW::Cosmos
