// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Entry.h"
#include "Address.h"
#include "casper_types.hpp"

#include "../HexCoding.h"
#include "../Hash.h"
#include "../PrivateKey.h"
#include "../Coin.h"

#include <TrustWalletCore/MiliException.h>
#include <nlohmann/json.hpp>
#include <chrono>
#include <stdlib.h>

using namespace TW::Casper;
using namespace std;
using json = nlohmann::json;
using namespace std::chrono;

const uint64_t STANDARD_PAYMENT_FOR_NATIVE_TRANSFERS = 100000000;
casper_types::TypeEnum correlation_id;

bool Entry::validateAddress(TWCoinType coin, const string& address, TW::byte, TW::byte, const char*) const {
    return Address::isValid(address);
}

string Entry::deriveAddress(TWCoinType coin, const PublicKey& publicKey, TW::byte, const char*) const {
    return Address(publicKey).string();
}

void Entry::sign(TWCoinType coin, const TW::Data& dataIn, TW::Data& dataOut) const {
    return;
}

bool Json2RawTx(json& jsonInput, casper_types::Deploy& deploy, Address& account) {
    string chainName = jsonInput["chainId"].get<string>();
    string toAddr = jsonInput["toAddress"].get<string>();
    uint64_t amount = strtoull(jsonInput["amount"].get<string>().c_str(), NULL, 10);
    uint64_t gasPrice = strtoull(jsonInput["gasPrice"].get<string>().c_str(), NULL, 10);
    TW::Data toAccount = TW::parse_hex(toAddr);

    casper_types::ModuleBytes payment;
    payment.args.push_back(
        casper_types::DeployArgument {
            "amount",
            casper_types::TypeEnum{casper_types::Uint512{STANDARD_PAYMENT_FOR_NATIVE_TRANSFERS * gasPrice}}
        }
    );

    casper_types::Transfer session;
    session.args.push_back(
        casper_types::DeployArgument {
            "amount",
            casper_types::TypeEnum{casper_types::Uint512{amount}}
        }
    );
    session.args.push_back(
        casper_types::DeployArgument {
            "target",
            casper_types::TypeEnum{casper_types::PublicKey{toAccount}}
        }
    );
	srand((unsigned) time(NULL));
    if(jsonInput.contains("correlation_id")) {
        correlation_id.value = jsonInput["timestamp"].get<uint64_t>();
    } else {
        correlation_id.value = (uint64_t)(rand() % 1000000 + 1);
    }
    //correlation_id.value = uint64_t(96134);
    session.args.push_back(
        casper_types::DeployArgument {
            "id",
            casper_types::TypeEnum{casper_types::Option{casper_types::ValuePtr<casper_types::TypeEnum>{ &correlation_id }}}
        }
    );

    casper_types::DeployBody body{ payment, session};
    TW::Data ret = CasperSerialize(body);
    body.hash.value = TW::Hash::blake2b(ret, 32);
    //cout << "=======byte body: " << TW::hex(ret) << endl;

    uint64_t timestamp;
    if(jsonInput.contains("timestamp")) {
        timestamp = jsonInput["timestamp"].get<uint64_t>();
    } else {
        timestamp = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
    }
    //uint64_t timestamp = 1670173440055;
    casper_types::DeployHeader header{
        .account = casper_types::PublicKey{casper_types::ByteArray{account.bytes}},
        .body_hash = body.hash,
        .chain_name = chainName,
        .gas_price = gasPrice,
        .timestamp = timestamp,
        .ttl = 1800000
    };

    ret = CasperSerialize(header);
    //cout << "=======byte header: " << TW::hex(ret) << endl;
    deploy.hash.value = TW::Hash::blake2b(ret, 32);
    deploy.header = header;
    deploy.payment = payment;
    deploy.session = session;
    return true;
}

string Entry::signJSON(TWCoinType coin, const std::string& txInput, const Data& key) const {
    json input = json::parse(txInput);
    casper_types::Deploy deploy;
    auto keyType = TW::publicKeyType(coin);
    PrivateKey privKey(key);
    Address account = Address(privKey.getPublicKey(keyType));
    //Address account = Address("0202efdf1c6b3f16540be8dfacdcadea868cbda63d77bb60563d48c4a58e1f707052");

    if(!Json2RawTx(input, deploy, account)) {
        throw MiliException{E_PARAM};
    }

    Data sign = privKey.sign(deploy.hash.value, TWCurveED25519);
    if(sign.size() == 0) {
        throw MiliException{E_SIGN};
    }
    sign.insert(sign.begin(), 1);

    deploy.approvals.push_back(casper_types::DeployApproval{
        .signer = deploy.header.account,
        .signature = casper_types::ByteArray{sign}
    });

    json jtx{{"deploy", json(deploy)}};
    return hex(deploy.hash.value) + "#" + jtx.dump();
}