// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Entry.h"
#include "Address.h"
#include "sui_types.hpp"

#include "../HexCoding.h"
#include "../Hash.h"
#include "../Base64.h"
#include "../PrivateKey.h"

#include "../bcs.hpp"

#include <TrustWalletCore/MiliException.h>
#include <nlohmann/json.hpp>
#include <chrono>
#include <stdlib.h>

using namespace TW::Sui;
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

bool Json2RawTx(json& jtx, sui_types::TransactionData& rawTx, uint64_t& realAmount) {
    const auto fromAddr = Address(jtx["fromAddress"].get<string>());
    rawTx.gas_budget = strtoull(jtx["gasLimit"].get<string>().c_str(), NULL, 10);
    rawTx.gas_price = strtoull(jtx["gasPrice"].get<string>().c_str(), NULL, 10);
    rawTx.sender.value = fromAddr.bytes;

    json suiObjs = jtx["suiObjects"].get<json>();
    if(suiObjs.size() == 0) return false;

    typedef pair<uint32_t, uint64_t> SORT_ITEM;
    vector<SORT_ITEM> sortObjs;
    for(int i = 0; i < suiObjs.size(); i++) {
        sortObjs.push_back(SORT_ITEM(i, strtoull(suiObjs[i]["balance"].get<string>().c_str(), NULL, 10)));
    }
    sort(sortObjs.begin(), sortObjs.end(), [](SORT_ITEM x, SORT_ITEM y){ return x.second > y.second; });

    json payment = suiObjs[sortObjs[0].first];
    const auto gasObj = Address(payment["objectId"].get<string>());
    uint64_t seqNo = strtoull(payment["seqNo"].get<string>().c_str(), NULL, 10);
    TW::Data digest = TW::Base64::decode(payment["digest"].get<string>());
    rawTx.gas_payment = {
        sui_types::ObjectID{.value = sui_types::AccountAddress{.value = gasObj.bytes}},
        sui_types::SequenceNumber{.value = seqNo},
        sui_types::ObjectDigest{.value = digest}
    };

    string payloadHex;
    if(jtx.contains("payload")) {
        jtx["payload"].get_to(payloadHex);
    }

    if(payloadHex.size() > 0) {
        TW::Data payloadData = TW::parse_hex(payloadHex);
        serde::BcsDeserialize(payloadData, rawTx.kind);

    } else {
        json action = jtx["action"].get<json>();
        vector<sui_types::SingleTransactionKind> batchTx;
        sui_types::SingleTransactionKind trans;
        if(action.contains("transfer")) {
            sui_types::SingleTransactionKind trans;
            json inner =  action["transfer"].get<json>();
            const auto toAddr = Address(inner["toAddress"].get<string>());

            if(inner.contains("object")) {
                json obj = inner["object"].get<json>();
                const auto objAddr = Address(obj["objectId"].get<string>());
                uint64_t seqNo = strtoull(obj["seqNo"].get<string>().c_str(), NULL, 10);
                TW::Data digest = TW::Base64::decode(obj["digest"].get<string>());
                trans.value = sui_types::SingleTransactionKind::TransferObject{
                    .value = sui_types::TransferObject{
                        .recipient = sui_types::SuiAddress{.value = toAddr.bytes},
                        .object_ref = {
                            sui_types::ObjectID{.value = sui_types::AccountAddress{.value = objAddr.bytes}},
                            sui_types::SequenceNumber{.value = seqNo},
                            sui_types::ObjectDigest{.value = digest}
                        }
                    }
                };
                batchTx.push_back(trans);
            } else {
                realAmount = 0;
                uint64_t amount = strtoull(inner["amount"].get<string>().c_str(), NULL, 10);
                uint64_t gasAmount = rawTx.gas_price * rawTx.gas_budget;
                if(sortObjs[0].second < gasAmount) {//balance insufficient
                    cout << "largest sui object balance insufficient" << endl;
                    return false;
                }

                for(int i = 1; i < sortObjs.size() && sortObjs[0].second < amount + gasAmount; i++) {//最大object余额不够用，用较小的补足
                    uint64_t thisPay = sortObjs[i].second;
                    if(thisPay > amount) continue;//防止多转
                    json obj = suiObjs[sortObjs[i].first];
                    const auto objAddr = Address(obj["objectId"].get<string>());
                    uint64_t seqNo = strtoull(obj["seqNo"].get<string>().c_str(), NULL, 10);
                    TW::Data digest = TW::Base64::decode(obj["digest"].get<string>());
                    trans.value = sui_types::SingleTransactionKind::TransferObject{
                        .value = sui_types::TransferObject{
                            .recipient = sui_types::SuiAddress{.value = toAddr.bytes},
                            .object_ref = {
                                sui_types::ObjectID{.value = sui_types::AccountAddress{.value = objAddr.bytes}},
                                sui_types::SequenceNumber{.value = seqNo},
                                sui_types::ObjectDigest{.value = digest}
                            }
                        }
                    };
                    batchTx.push_back(trans);
                    amount -= thisPay;
                    realAmount += thisPay;
                    cout << "transfer sui object: " << obj["objectId"].get<string>() << endl;
                }
                if(sortObjs[0].second < amount + gasAmount) {//余额不足
                    cout << "insufficient balance" << endl;
                    return false;
                } else if(amount > 0 && batchTx.size() == 0) {
                    trans.value = sui_types::SingleTransactionKind::TransferSui{
                        .value = sui_types::TransferSui{
                            .recipient = sui_types::SuiAddress{.value = toAddr.bytes},
                            .amount = amount
                        }
                    };
                    realAmount += amount;
                    cout << "transfer sui: " << amount << endl;
                }
            }
            if(batchTx.size() == 0) {
                rawTx.kind = sui_types::TransactionKind {
                    .value = sui_types::TransactionKind::Single{
                        .value = trans
                    }
                };
            } else {
                rawTx.kind = sui_types::TransactionKind {
                    .value = sui_types::TransactionKind::Batch{
                        .value = batchTx
                    }
                };
            }
            return true;

        } else if(action.contains("merge")) {
            sui_types::MoveCall merge;
            merge.package = {
                sui_types::ObjectID{.value = sui_types::AccountAddress{.value = Address("0x2").bytes}},
                sui_types::SequenceNumber{.value = 1},
                sui_types::ObjectDigest{.value = TW::Base64::decode("nfn23WvLEc9CrMBIfUO2S1Bj5fpFq/I+69xmyEdLTAE=")}
            };
            merge.function.value = "join";
            merge.module.value = "coin";
            merge.type_arguments.push_back(
                sui_types::TypeTag{
                    .value = sui_types::TypeTag::Struct{
                        .value = sui_types::StructTag{
                            .address = sui_types::AccountAddress{.value = Address("0x2").bytes},
                            .module = sui_types::Identifier{.value = "sui"},
                            .name = sui_types::Identifier{.value = "SUI"},
                        }
                    }
                }
            );

            vector<json> mergeObjs;
            json inner = action["merge"].get<json>();
            for(int i = 0; i < inner.size(); i++) {
                mergeObjs.push_back(inner[i]);
            }
            if(mergeObjs.size() == 0) {
                for(int i = 1; i < sortObjs.size(); i++) {//第一个用于gas payment
                    mergeObjs.push_back(suiObjs[sortObjs[i].first]);
                }
            }
            if(mergeObjs.size() < 2) {//merge数量不足
                cout << "merge object mast more than 2" << endl;
                return false;
            }

            for(int i = 0; i < mergeObjs.size(); i++) {
                sui_types::CallArg arg;
                const auto objAddr = Address(mergeObjs[i]["objectId"].get<string>());
                if(objAddr.bytes == gasObj.bytes) {
                    cout << "gas payment object reuse!" << endl;
                    return false;
                }
                uint64_t seqNo = strtoull(mergeObjs[i]["seqNo"].get<string>().c_str(), NULL, 10);
                TW::Data digest = TW::Base64::decode(mergeObjs[i]["digest"].get<string>());
                arg.value = sui_types::CallArg::Object{
                    .value = sui_types::ObjectArg{
                        .value = sui_types::ObjectArg::ImmOrOwnedObject{
                            .value = {
                                sui_types::ObjectID{.value = sui_types::AccountAddress{.value = objAddr.bytes}},
                                sui_types::SequenceNumber{.value = seqNo},
                                sui_types::ObjectDigest{.value = digest},
                            }
                        }
                    }
                };
                merge.arguments.push_back(arg);
                if(i % 2 == 1) { //两两合并
                    trans.value = sui_types::SingleTransactionKind::Call{.value = merge};
                    batchTx.push_back(trans);
                    merge.arguments.clear();
                }
            }
            rawTx.kind = sui_types::TransactionKind {
                .value = sui_types::TransactionKind::Batch{
                    .value = batchTx
                }
            };
            return true;
        }
    }
    return false;
}

string Entry::signJSON(TWCoinType coin, const std::string& jsonTx, const Data& key) const {
    json jtx = json::parse(jsonTx);
    sui_types::TransactionData rawTx;
    uint64_t realAmount = 0;
    if(!Json2RawTx(jtx, rawTx, realAmount)) {
        throw MiliException{E_PARAM};
    }

    Data sigData = data("TransactionData::");
    append(sigData, (Data)serde::BcsSerialize(rawTx));

    PrivateKey privKey(key);
    Data sign = privKey.sign(sigData, TWCurveED25519);
    if(sign.size() == 0) {
        throw MiliException{E_SIGN};
    }

    PublicKey pubKey = privKey.getPublicKey(TWPublicKeyTypeED25519);

    json sendTx = {
        Base64::encode(sigData),
        "ED25519",
        Base64::encode(sign),
        Base64::encode(data(pubKey.bytes.data(), pubKey.bytes.size()))
    };
    json outTx = {
        {"rawTx", sendTx.dump()},
        {"realAmount", realAmount}
    };
    return outTx.dump();
}