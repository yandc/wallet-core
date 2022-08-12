// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Entry.h"
#include "Address.h"
#include "starcoin_types.hpp"

#include "../HexCoding.h"
#include "../Hash.h"
#include "../PrivateKey.h"

#include "../bcs.hpp"

#include <TrustWalletCore/MiliException.h>
#include <nlohmann/json.hpp>
#include <chrono>


using namespace TW::Starcoin;
using namespace std;
using json = nlohmann::json;
using namespace std::chrono;

// Note: avoid business logic from here, rather just call into classes like Address, Signer, etc.

bool Entry::validateAddress(TWCoinType coin, const string& address, TW::byte, TW::byte, const char*) const {
    return Address::isValid(address);
}

string Entry::deriveAddress(TWCoinType coin, const PublicKey& publicKey, TW::byte, const char*) const {
    return Address(publicKey).string();
}

void Entry::sign(TWCoinType coin, const TW::Data& dataIn, TW::Data& dataOut) const {
    return;
}

const char* GAS_TOKEN_CODE = "0x1::STC::STC";

bool Json2RawTx(const string& jsonTx, starcoin_types::RawUserTransaction& rawTx) {
    json jtx = json::parse(jsonTx);
    uint64_t timestamp = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
    const auto fromAddr = Address(jtx["fromAddress"].get<string>());
    const auto toAddr = Address(jtx["toAddress"].get<string>());

    string token = GAS_TOKEN_CODE;
    if(jtx.contains("token")) {
        jtx["token"].get_to(token);
    }
    size_t pos1 = token.find("::");
    size_t pos2 = token.find("::", pos1+2);
    if (pos1 == string::npos || pos2 == string::npos) {
        return false;
    }
    const auto tokenAddr = Address(token.substr(0, pos1));
    const string tokenModu = token.substr(pos1+2, pos2-pos1-2);
    const string tokenCoin = token.substr(pos2+2, token.size());

    uint64_t amount = jtx["amount"].get<uint64_t>();
    rawTx.chain_id.id = jtx["chainId"].get<uint8_t>();
    rawTx.max_gas_amount = jtx["gasLimit"].get<uint64_t>();
    rawTx.gas_unit_price = jtx["gasPrice"].get<uint64_t>();
    rawTx.sequence_number = jtx["nonce"].get<uint64_t>();
    rawTx.sender.value = fromAddr.bytes;
    rawTx.expiration_timestamp_secs = timestamp + 43200;
    rawTx.gas_token_code = GAS_TOKEN_CODE;

    string payloadHex;
    if(jtx.contains("payload")) {
        jtx["payload"].get_to(payloadHex);
    }

    if(payloadHex.size() > 0) {
        TW::Data payloadData = TW::parse_hex(payloadHex);
        rawTx.payload = serde::BcsDeserialize<starcoin_types::TransactionPayload>(payloadData);

    } else {
        starcoin_types::ScriptFunction scriptFunction;
        scriptFunction.module = starcoin_types::ModuleId {
            .address = starcoin_types::AccountAddress{.value = Address("0x1").bytes},
            .name = starcoin_types::Identifier{.value = "TransferScripts"},
        };
        scriptFunction.function = starcoin_types::Identifier{.value = "peer_to_peer_v2"};
        scriptFunction.ty_args.push_back(starcoin_types::TypeTag{
            .value = starcoin_types::TypeTag::Struct{
                .value = {
                    .address = starcoin_types::AccountAddress{.value = tokenAddr.bytes},
                    .module = starcoin_types::Identifier{.value = tokenModu},
                    .name = starcoin_types::Identifier{.value = tokenCoin},
                }
            }
        });
        scriptFunction.args.push_back(serde::BcsSerialize(starcoin_types::AccountAddress{.value = toAddr.bytes}));
        scriptFunction.args.push_back(serde::BcsSerialize(serde::uint128_t{.high = 0, .low = amount}));

        rawTx.payload = starcoin_types::TransactionPayload{
            .value = starcoin_types::TransactionPayload::ScriptFunction{
                .value = scriptFunction
            }
        };
    }
    return true;
}

string Entry::signJSON(TWCoinType coin, const std::string& jtx, const Data& key) const {
    starcoin_types::RawUserTransaction rawTx;
    if(!Json2RawTx(jtx, rawTx)) {
        throw MiliException{E_PARAM};
    }
    cout << "rawTx: " << hex(serde::BcsSerialize(rawTx)) << endl;;

    string pre = "STARCOIN::RawUserTransaction";
    Data preHash = Hash::sha3_256(pre);
    append(preHash, (Data)serde::BcsSerialize(rawTx));

    PrivateKey privKey(key);
    Data sign = privKey.sign(preHash, TWCurveED25519);
    if(sign.size() == 0) {
        throw MiliException{E_SIGN};
    }

    PublicKey pubKey = privKey.getPublicKey(TWPublicKeyTypeED25519);
    starcoin_types::TransactionAuthenticator auth = {
        .value = starcoin_types::TransactionAuthenticator::Ed25519{
            .public_key = starcoin_types::Ed25519PublicKey{.value = pubKey.bytes},
            .signature = starcoin_types::Ed25519Signature{.value = sign}
        }
    };

    starcoin_types::SignedUserTransaction signedTx = {
        .raw_txn = rawTx,
        .authenticator = auth
    };

    return TW::hex(serde::BcsSerialize(signedTx));
}

TW::Data Entry::hashMessage(TWCoinType coin, const string& msg) const {
    string pre = "STARCOIN::SigningMessage";
    Data preHash = Hash::sha3_256(pre);
    starcoin_types::SigningMessage sigMsg = {
        .value = data(msg),
    };
    append(preHash, (Data)serde::BcsSerialize(sigMsg));
    return preHash;
}