// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Signer.h"

#include "../Hash.h"
#include "Bitcoin/TransactionSigner.h"
#include "Transaction.h"
#include "HexCoding.h"
#include "Bitcoin/SigHashType.h"

#include <google/protobuf/util/json_util.h>
#include <TrustWalletCore/MiliException.h>
#include <nlohmann/json.hpp>

using namespace TW;
using namespace TW::Kaspa;
using json = nlohmann::json;

Proto::SigningOutput Signer::sign(const Bitcoin::Proto::SigningInput& input) {
    Proto::SigningOutput output;
    auto result = Bitcoin::TransactionSigner<Transaction, Bitcoin::TransactionBuilder>::sign(input, false);
    if (!result) {
        output.set_error(result.error());
        return output;
    }
    const auto& tx = result.payload();
    *output.mutable_transaction() = tx.proto();

    Data encoded;
    tx.encode(encoded);
    output.set_encoded(encoded.data(), encoded.size());

    output.set_transaction_id(hex(tx.getTransactionID()));
    return output;
}

std::string Signer::signJSON(TWCoinType coin, const std::string& jsonInput, const Data& key) {
    auto input = Bitcoin::Proto::SigningInput();
    google::protobuf::util::JsonStringToMessage(jsonInput, &input);
    input.add_private_key(key.data(), key.size());
    input.set_coin_type(coin);
    input.set_hash_type(Bitcoin::hashTypeForCoin(coin));

    auto lockingScript = Bitcoin::Script::lockScriptForAddress(input.change_address(), coin);
    for(int i = 0; i < input.utxo_size() && input.utxo(i).script().size() == 0; i++) {
        auto utxo = input.mutable_utxo(i);
        utxo->set_script(lockingScript.bytes.data(), lockingScript.bytes.size());
    }
    auto output = Signer::sign(input);
    if(output.error() != Common::Proto::OK) {
        throw ERROR_INFOS[int(output.error())];
    }
    std::string result;
    google::protobuf::util::JsonPrintOptions options;
    options.always_print_primitive_fields = true;
    google::protobuf::util::MessageToJsonString(output.transaction(), &result, options);

    auto& tx = output.transaction();
    json utxos = json::array();
    for (int i = 0; i < tx.inputs().size(); i++) {
        utxos.push_back(json{
            {"hash", tx.inputs(i).previousoutpoint().transactionid()},
            {"index", tx.inputs(i).previousoutpoint().index()}
        });
    };
    json extendTx = {
        {"tx", result},
        {"utxos", utxos},
        {"owner", input.change_address()}
    };
    return output.transaction_id() + "#" + extendTx.dump();
}
