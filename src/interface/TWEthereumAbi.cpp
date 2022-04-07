// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWEthereumAbi.h>
#include <TrustWalletCore/TWEthereumAbiFunction.h>

#include "Data.h"
#include "Ethereum/ABI.h"
#include "Ethereum/ContractCall.h"
#include "HexCoding.h"
#include "uint256.h"

#include <cassert>
#include <string>
#include <vector>

using namespace TW::Ethereum::ABI;
using namespace TW::Ethereum;
using namespace TW;


TWData* _Nonnull TWEthereumAbiEncode(struct TWEthereumAbiFunction* _Nonnull func_in) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    Data encoded;
    function.encode(encoded);
    return TWDataCreateWithData(&encoded);
}

bool TWEthereumAbiDecodeOutput(struct TWEthereumAbiFunction* _Nonnull func_in,
                               TWData* _Nonnull encoded) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;
    assert(encoded != nullptr);
    Data encData = data(TWDataBytes(encoded), TWDataSize(encoded));

    size_t offset = 0;
    return function.decodeOutput(encData, offset);
}

TWString* _Nullable TWEthereumAbiDecodeCall(TWData* _Nonnull callData, TWString* _Nonnull abiString) {
    const Data& call = *(reinterpret_cast<const Data*>(callData));
    const auto& jsonString = *reinterpret_cast<const std::string*>(abiString);
    try {
        auto abi = nlohmann::json::parse(jsonString);
        auto string = decodeCall(call, abi);
        if (!string.has_value()) {
            return nullptr;
        }
        return TWStringCreateWithUTF8Bytes(string->c_str());
    }
    catch(...) {
        return nullptr;
    }
}

TWData* _Nonnull TWEthereumAbiEncodeTyped(TWString* _Nonnull messageJson) {
    Data data;
    try {
        data = ParamStruct::hashStructJson(TWStringUTF8Bytes(messageJson));
    } catch (...) {} // return empty
    return TWDataCreateWithBytes(data.data(), data.size());
}

TWString *_Nonnull CppDecodeEvmCall(const char *_Nonnull callData) {
    const std::string abi = R"({
            "a9059cbb": {"constant":false,"inputs":[{"name":"_to","type":"address"},{"name":"_value","type":"uint256"}],"name":"transfer","outputs":[{"name":"","type":"bool"}],"payable":false,"stateMutability":"nonpayable","type":"function"},
            "095ea7b3": {"constant":false,"inputs":[{"name":"_spender","type":"address"},{"name":"_value","type":"uint256"}],"name":"approve","outputs":[{"name":"","type":"bool"}],"payable":false,"stateMutability":"nonpayable","type":"function"},
            "23b872dd": {"constant":false,"inputs":[{"name":"_from","type":"address"},{"name":"_to","type":"address"},{"name":"_value","type":"uint256"}],"name":"transferFrom","outputs":[{"name":"","type":"bool"}],"payable":false,"stateMutability":"nonpayable","type":"function"},
            "a22cb465": {"constant":false,"inputs":[{"internalType":"address","name":"to","type":"address"},{"internalType":"bool","name":"approved","type":"bool"}],"name":"setApprovalForAll","outputs":[],"payable":false,"stateMutability":"nonpayable","type":"function"},
            "42842e0e": {"constant":false,"inputs":[{"internalType":"address","name":"from","type":"address"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"tokenId","type":"uint256"}],"name":"safeTransferFrom","outputs":[],"payable":false,"stateMutability":"nonpayable","type":"function"},
            "b88d4fde": {"constant":false,"inputs":[{"internalType":"address","name":"from","type":"address"},{"internalType":"address","name":"to","type":"address"},{"internalType":"uint256","name":"tokenId","type":"uint256"},{"internalType":"bytes","name":"_data","type":"bytes"}],"name":"safeTransferFrom","outputs":[],"payable":false,"stateMutability":"nonpayable","type":"function"}
        })";
    Data data = parse_hex(callData);
    return TWEthereumAbiDecodeCall(&data, &abi);
}