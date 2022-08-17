// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Entry.h"
#include "Address.h"
#include "aptos_types.hpp"

#include "../HexCoding.h"
#include "../Hash.h"
#include "../PrivateKey.h"

#include "../bcs.hpp"

#include <TrustWalletCore/MiliException.h>
#include <nlohmann/json.hpp>
#include <chrono>
#include <stdlib.h>

using namespace TW::Aptos;
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

bool SplitToken(string token, string& addr, string& modu, string& coin) {
    size_t pos1 = token.find("::");
    size_t pos2 = token.find("::", pos1+2);
    if (pos1 == string::npos || pos2 == string::npos) {
        return false;
    }
    addr = token.substr(0, pos1);
    modu = token.substr(pos1+2, pos2-pos1-2);
    coin = token.substr(pos2+2, token.size());
    return true;
}
bool Json2RawTx(json& jtx, aptos_types::RawTransaction& rawTx) {
    uint64_t timestamp = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
    const auto fromAddr = Address(jtx["fromAddress"].get<string>());
    const auto toAddr = Address(jtx["toAddress"].get<string>());

    string token = "0x1::aptos_coin::AptosCoin";
    if(jtx.contains("token")) {
        jtx["token"].get_to(token);
    }
    string addr, modu, coin;
    if(!SplitToken(token, addr, modu, coin)) {
        return false;
    };
    const auto tokenAddr = Address(addr);
    const string tokenModu = modu;
    const string tokenCoin = coin;

    uint64_t amount = strtoull(jtx["amount"].get<string>().c_str(), NULL, 10);
    rawTx.chain_id.value = jtx["chainId"].get<uint8_t>();
    rawTx.max_gas_amount = strtoull(jtx["gasLimit"].get<string>().c_str(), NULL, 10);
    rawTx.gas_unit_price = strtoull(jtx["gasPrice"].get<string>().c_str(), NULL, 10);
    rawTx.sequence_number = strtoull(jtx["nonce"].get<string>().c_str(), NULL, 10);
    rawTx.sender.value = fromAddr.bytes;
    rawTx.expiration_timestamp_secs = timestamp + 43200;

    string payloadHex;
    if(jtx.contains("payload")) {
        jtx["payload"].get_to(payloadHex);
    }

    if(payloadHex.size() > 0) {
        TW::Data payloadData = TW::parse_hex(payloadHex);
        serde::BcsDeserialize(payloadData, rawTx.payload);

    } else {
        aptos_types::ScriptFunction scriptFunction;
        if(jtx.contains("createAccount") && jtx["createAccount"].get<bool>()) {
            scriptFunction.module = aptos_types::ModuleId {
                .address = aptos_types::AccountAddress{.value = Address("0x1").bytes},
                .name = aptos_types::Identifier{.value = "account"},
            };
            scriptFunction.function = aptos_types::Identifier{.value = "create_account"};
            scriptFunction.args.push_back(serde::BcsSerialize(aptos_types::AccountAddress{.value = toAddr.bytes}));

        } else if(jtx.contains("registerCoin") && jtx["registerCoin"].get<bool>()) {
            scriptFunction.module = aptos_types::ModuleId {
                .address = aptos_types::AccountAddress{.value = Address("0x1").bytes},
                .name = aptos_types::Identifier{.value = "coins"},
            };
            scriptFunction.function = aptos_types::Identifier{.value = "register"};

            scriptFunction.ty_args.push_back(aptos_types::TypeTag{
                .value = aptos_types::TypeTag::Struct{
                    .value = {
                        .address = aptos_types::AccountAddress{.value = tokenAddr.bytes},
                        .module = aptos_types::Identifier{.value = tokenModu},
                        .name = aptos_types::Identifier{.value = tokenCoin},
                    }
                }
            });
        } else {
            scriptFunction.module = aptos_types::ModuleId {
                .address = aptos_types::AccountAddress{.value = Address("0x1").bytes},
                .name = aptos_types::Identifier{.value = "coin"},
            };
            scriptFunction.function = aptos_types::Identifier{.value = "transfer"};
            scriptFunction.args.push_back(serde::BcsSerialize(aptos_types::AccountAddress{.value = toAddr.bytes}));
            scriptFunction.args.push_back(serde::BcsSerialize(amount));

            scriptFunction.ty_args.push_back(aptos_types::TypeTag{
                .value = aptos_types::TypeTag::Struct{
                    .value = {
                        .address = aptos_types::AccountAddress{.value = tokenAddr.bytes},
                        .module = aptos_types::Identifier{.value = tokenModu},
                        .name = aptos_types::Identifier{.value = tokenCoin},
                    }
                }
            });
        }

        rawTx.payload = aptos_types::TransactionPayload{
            .value = aptos_types::TransactionPayload::ScriptFunction{
                .value = scriptFunction
            }
        };
    }
    return true;
}

string Entry::signJSON(TWCoinType coin, const std::string& jsonTx, const Data& key) const {
    json jtx = json::parse(jsonTx);
    aptos_types::RawTransaction rawTx;
    if(!Json2RawTx(jtx, rawTx)) {
        throw MiliException{E_PARAM};
    }

    string pre = "APTOS::RawTransaction";
    Data preHash = Hash::sha3_256(pre);
    append(preHash, (Data)serde::BcsSerialize(rawTx));

    PrivateKey privKey(key);
    Data sign = privKey.sign(preHash, TWCurveED25519);
    if(sign.size() == 0) {
        throw MiliException{E_SIGN};
    }

    PublicKey pubKey = privKey.getPublicKey(TWPublicKeyTypeED25519);
    aptos_types::TransactionAuthenticator auth = {
        .value = aptos_types::TransactionAuthenticator::Ed25519{
            .public_key = aptos_types::Ed25519PublicKey{.value = pubKey.bytes},
            .signature = aptos_types::Ed25519Signature{.value = sign}
        }
    };

    aptos_types::SignedTransaction signedTx = {
        .raw_txn = rawTx,
        .authenticator = auth
    };
    return TW::hex(serde::BcsSerialize(signedTx));
}