// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"
#include "Hash.h"
#include "HexCoding.h"
#include "Transaction.h"
#include "TransactionBuilder.h"
#include "TransactionSigner.h"
#include <google/protobuf/util/json_util.h>
#include "SigHashType.h"
#include <TrustWalletCore/MiliException.h>

using namespace TW;
using namespace TW::Bitcoin;

Proto::TransactionPlan Signer::plan(const Proto::SigningInput& input) noexcept {
    auto plan = TransactionSigner<Transaction, TransactionBuilder>::plan(input);
    return plan.proto();
}

Proto::TransactionPlan Signer::planJson(TWCoinType coin, const std::string& jsonInput) noexcept {
    auto input = Proto::SigningInput();
    google::protobuf::util::JsonStringToMessage(jsonInput, &input);
    input.set_coin_type(coin);
    input.set_hash_type(hashTypeForCoin(coin));
    auto lockingScript = Script::lockScriptForAddress(input.change_address(), coin);
    for(int i = 0; i < input.utxo_size() && input.utxo(i).script().size() == 0; i++) {
        auto utxo = input.mutable_utxo(i);
        utxo->set_script(lockingScript.bytes.data(), lockingScript.bytes.size());
    }
    auto plan = TransactionSigner<Transaction, TransactionBuilder>::plan(input);
    return plan.proto();
}

Proto::SigningOutput Signer::sign(const Proto::SigningInput &input, std::optional<SignaturePubkeyList> optionalExternalSigs) {
    Proto::SigningOutput output;
    auto result = TransactionSigner<Transaction, TransactionBuilder>::sign(input, false, optionalExternalSigs);
    if (!result) {
        output.set_error(result.error());
        return output;
    }

    const auto& tx = result.payload();
    *output.mutable_transaction() = tx.proto();

    Data encoded;
    tx.encode(encoded);
    output.set_encoded(encoded.data(), encoded.size());

    Data txHashData = encoded;
    if (tx.hasWitness()) {
        txHashData.clear();
        tx.encode(txHashData, Transaction::SegwitFormatMode::NonSegwit);
    }
    auto txHash = Hash::sha256d(txHashData.data(), txHashData.size());
    std::reverse(txHash.begin(), txHash.end());
    output.set_transaction_id(hex(txHash));
    return output;
}

HashPubkeyList Signer::preImageHashes(const Proto::SigningInput& input) noexcept {
    return TransactionSigner<Transaction, TransactionBuilder>::preImageHashes(input);
}
std::string Signer::signJSON(TWCoinType coin, const std::string& json, const Data& key) {
    auto input = Proto::SigningInput();
    google::protobuf::util::JsonStringToMessage(json, &input);
    input.add_private_key(key.data(), key.size());
    input.set_coin_type(coin);
    input.set_hash_type(hashTypeForCoin(coin));
    auto lockingScript = Script::lockScriptForAddress(input.change_address(), coin);
    for(int i = 0; i < input.utxo_size() && input.utxo(i).script().size() == 0; i++) {
        auto utxo = input.mutable_utxo(i);
        utxo->set_script(lockingScript.bytes.data(), lockingScript.bytes.size());
    }
    auto output = Signer::sign(input);
    if(output.error() != Common::Proto::OK) {
        throw ERROR_INFOS[int(output.error())];
    }
    return output.transaction_id() + "#" + hex(output.encoded());
}
