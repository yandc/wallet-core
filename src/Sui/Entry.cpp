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
#include "../Base58.h"
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

string Entry::deriveAddress(TWCoinType coin, const PublicKey& publicKey, TW::byte, const char* hrp) const {
    if (hrp != nullptr && strlen(hrp) > 0) {
        string addr = hrp;
        if (addr == "BFC") {
            string rawAddr = Address(publicKey).string().substr(2);
            string checkSum = hex(Hash::sha256(rawAddr));
            return addr + rawAddr + checkSum.substr(0, 4);
        }
    }
    return Address(publicKey).string();
}

void Entry::sign(TWCoinType coin, const TW::Data& dataIn, TW::Data& dataOut) const {
    return;
}

bool Json2RawTx(json& jtx, sui_types::TransactionDataV1& rawTx, uint64_t& realAmount) {
    const auto fromAddr = Address(jtx["fromAddress"].get<string>());
    uint64_t gasLimit = strtoull(jtx["gasLimit"].get<string>().c_str(), NULL, 10);
    rawTx.gas_data.gas_price = strtoull(jtx["gasPrice"].get<string>().c_str(), NULL, 10);
    rawTx.gas_data.gas_budget = gasLimit * rawTx.gas_data.gas_price;
    rawTx.sender.value = fromAddr.bytes;
    rawTx.gas_data.owner.value = fromAddr.bytes;
    rawTx.expiration.value = sui_types::TransactionExpiration::None{};
    json suiObjs = jtx["suiObjects"].get<json>();
    if(suiObjs.size() == 0) return false;

    typedef pair<uint32_t, uint64_t> SORT_ITEM;
    vector<SORT_ITEM> sortObjs;
    for(int i = 0; i < suiObjs.size(); i++) {
        if(suiObjs[i].contains("balance")) {
            sortObjs.push_back(SORT_ITEM(i, strtoull(suiObjs[i]["balance"].get<string>().c_str(), NULL, 10)));
        } else {
            sortObjs.push_back(SORT_ITEM(i, 0));
        }
    }
    stable_sort(sortObjs.begin(), sortObjs.end(), [](SORT_ITEM x, SORT_ITEM y){ return x.second > y.second; });

    json action = jtx["action"].get<json>();
    sui_types::TransactionKind trans;
    if(action.contains("transfer")) {
        json inner =  action["transfer"].get<json>();
        const auto toAddr = Address(inner["toAddress"].get<string>());

        vector<sui_types::CallArg> inputs;
        vector<sui_types::Argument> coins;
        vector<sui_types::Command> commands;

        uint64_t txAmount = 0;
        uint64_t gasAmount = rawTx.gas_data.gas_budget;
        uint64_t suiAmount = gasAmount;
        uint64_t tokenAmount = 0;
        if(inner.contains("amount")) {
            txAmount = strtoull(inner["amount"].get<string>().c_str(), NULL, 10);
        }
        if(inner.contains("token")) {
            tokenAmount = txAmount;
        } else {
            suiAmount += txAmount;
        }

        realAmount = 0;
        for(int i = 0; i < sortObjs.size() && realAmount < suiAmount; i++) { // collect gas object
            uint64_t leftAmount = suiAmount - realAmount;
            uint64_t thisPay = sortObjs[i].second > leftAmount ? leftAmount : sortObjs[i].second;

            json suiObj = suiObjs[sortObjs[i].first];
            if(suiObj.contains("token")) continue;

            const auto id = Address(suiObj["objectId"].get<string>());
            uint64_t seqNo = strtoull(suiObj["seqNo"].get<string>().c_str(), NULL, 10);
            TW::Data digest = TW::Base58::bitcoin.decode(suiObj["digest"].get<string>());

            rawTx.gas_data.payment.push_back({
                sui_types::ObjectID{.value = sui_types::AccountAddress{.value = id.bytes}},
                sui_types::SequenceNumber{.value = seqNo},
                sui_types::ObjectDigest{.value = sui_types::Sha3Digest{.value = digest}}
            });
            realAmount += thisPay;
            cout << "pay sui object: " << suiObj["objectId"].get<string>() << endl;
        }
        if(realAmount < suiAmount) {//余额不足
            cout << "insufficient balance" << endl;
            throw MiliException{"insufficient balance"};
        }
        realAmount = txAmount;

        if(inner.contains("nft")) {
            string nftAddr = inner["nft"].get<string>();
            for(int i = 0; i < sortObjs.size(); i++) {
                json suiObj = suiObjs[sortObjs[i].first];
                if(!suiObj.contains("nft")) continue;
                if(suiObj["nft"].get<string>() != nftAddr) continue;

                const auto id = Address(suiObj["objectId"].get<string>());
                uint64_t seqNo = strtoull(suiObj["seqNo"].get<string>().c_str(), NULL, 10);
                TW::Data digest = TW::Base58::bitcoin.decode(suiObj["digest"].get<string>());

                coins.push_back(sui_types::Argument{
                    .value = sui_types::Argument::Input{
                        .value = (uint16_t)inputs.size()
                    }
                });
                inputs.push_back(sui_types::CallArg{
                    .value = sui_types::CallArg::Object{
                        .value = sui_types::ObjectArg {
                            .value = sui_types::ObjectArg::ImmOrOwnedObject{
                                .value = {
                                    sui_types::ObjectID{.value = sui_types::AccountAddress{.value = id.bytes}},
                                    sui_types::SequenceNumber{.value = seqNo},
                                    sui_types::ObjectDigest{.value = sui_types::Sha3Digest{.value = digest}}
                                }
                            }
                        }
                    }
                });
            }
            if(inputs.size() == 0) {
                cout << "empty nft object" << endl;
                return false;
            }
        } else if(suiAmount > gasAmount) { //split coin object and transfer object
            coins.push_back(sui_types::Argument{
                .value = sui_types::Argument::Result{
                    .value = (uint16_t)commands.size()
                }
            });
            commands.push_back(sui_types::Command{
                .value = sui_types::Command::SplitCoin{
                    .value = {
                        sui_types::Argument{.value = sui_types::Argument::GasCoin{}},
                        vector<sui_types::Argument>{sui_types::Argument{.value = sui_types::Argument::Input{.value = (uint16_t)inputs.size()}}}
                    }
                }
            });
            inputs.push_back(sui_types::CallArg{
                .value = sui_types::CallArg::Pure{
                    .value = serde::BcsSerialize(txAmount)
                }
            });
        } else if(tokenAmount > 0) {
            realAmount = 0;
            string tokenAddr = inner["token"].get<string>();
            for(int i = 0; i < sortObjs.size() && realAmount < tokenAmount; i++) {
                uint64_t leftAmount = tokenAmount - realAmount;
                uint64_t thisPay = sortObjs[i].second > leftAmount ? leftAmount : sortObjs[i].second;

                json suiObj = suiObjs[sortObjs[i].first];
                if(!suiObj.contains("token")) continue;
                if(suiObj["token"].get<string>() != tokenAddr) continue;

                const auto id = Address(suiObj["objectId"].get<string>());
                uint64_t seqNo = strtoull(suiObj["seqNo"].get<string>().c_str(), NULL, 10);
                TW::Data digest = TW::Base58::bitcoin.decode(suiObj["digest"].get<string>());

                if(thisPay == sortObjs[i].second) {
                    coins.push_back(sui_types::Argument{
                        .value = sui_types::Argument::Input{
                            .value = (uint16_t)inputs.size()
                        }
                    });
                }
                inputs.push_back(sui_types::CallArg{
                    .value = sui_types::CallArg::Object{
                        .value = sui_types::ObjectArg {
                            .value = sui_types::ObjectArg::ImmOrOwnedObject{
                                .value = {
                                    sui_types::ObjectID{.value = sui_types::AccountAddress{.value = id.bytes}},
                                    sui_types::SequenceNumber{.value = seqNo},
                                    sui_types::ObjectDigest{.value = sui_types::Sha3Digest{.value = digest}}
                                }
                            }
                        }
                    }
                });
                realAmount += thisPay;
                cout << "pay sui object: " << suiObj["objectId"].get<string>() << endl;

                if(thisPay < sortObjs[i].second) { //split
                    coins.push_back(sui_types::Argument{
                        .value = sui_types::Argument::Result{
                            .value = (uint16_t)commands.size()
                        }
                    });
                    commands.push_back(sui_types::Command{
                        .value = sui_types::Command::SplitCoin{
                            .value = {
                                sui_types::Argument{.value = sui_types::Argument::Input{.value = (uint16_t)(inputs.size()-1)}},
                                vector<sui_types::Argument>{sui_types::Argument{.value = sui_types::Argument::Input{.value = (uint16_t)inputs.size()}}}
                            }
                        }
                    });
                    inputs.push_back(sui_types::CallArg{
                        .value = sui_types::CallArg::Pure{
                            .value = serde::BcsSerialize(thisPay)
                        }
                    });
                }
            }
            if(realAmount < txAmount) {//余额不足
                cout << "insufficient balance" << endl;
                throw MiliException{"insufficient balance"};
            }
            realAmount = txAmount;
        }
        commands.push_back(sui_types::Command{
            .value = sui_types::Command::TransferObjects{
                .value = { coins, sui_types::Argument{.value = sui_types::Argument::Input{.value = (uint16_t)inputs.size()}}}
            }
        });
        inputs.push_back(sui_types::CallArg{
            .value = sui_types::CallArg::Pure{
                .value = serde::BcsSerialize(sui_types::SuiAddress{.value = toAddr.bytes})
            }
        });
        trans.value = sui_types::TransactionKind::ProgrammableTransaction{
            .value = sui_types::ProgrammableTransaction{
                .inputs = inputs,
                .commands = commands
            }
        };
    }
    rawTx.kind = trans;
    return true;
}

string Entry::signJSON(TWCoinType coin, const std::string& jsonTx, const Data& key) const {
    json jtx = json::parse(jsonTx);
    sui_types::TransactionDataV1 rawTx;
    uint64_t realAmount = 0;
    string payloadHex;

    if(jtx.contains("payload")) {
        jtx["payload"].get_to(payloadHex);
    }

    if(payloadHex.size() > 0) {
        TW::Data payloadData = TW::parse_hex(payloadHex);
        serde::BcsDeserialize(TW::subData(payloadData, 1), rawTx);

    } else if(!Json2RawTx(jtx, rawTx, realAmount)) {
        throw MiliException{E_PARAM};
    }

    Data sigData = {0, 0, 0};
    Data rawData = serde::BcsSerialize(sui_types::TransactionData{.value = sui_types::TransactionData::V1{.value = rawTx}});
    append(sigData, rawData);

    PrivateKey privKey(key);
    Data sign = privKey.sign(Hash::blake2b(sigData, 32), TWCurveED25519);
    if(sign.size() == 0) {
        throw MiliException{E_SIGN};
    }

    Data prefix = data("TransactionData::");
    append(prefix, rawData);
    string txDigest = TW::Base58::bitcoin.encode(Hash::blake2b(prefix, 32));

    PublicKey pubKey = privKey.getPublicKey(TWPublicKeyTypeED25519);
    Data serSign = {0};//flag, ed25519
    append(serSign, sign);
    append(serSign, pubKey.bytes);

    json sendTx = {
        Base64::encode(rawData),
        {
            Base64::encode(serSign)
        },
        {
            {"showInput", true},
            {"showRawInput", true},
            {"showEffects", true},
            {"showEvents", true},
            {"showObjectChanges", true},
            {"showBalanceChanges", true}
        },
        "WaitForLocalExecution"
    };

    if(payloadHex.size() > 0) {
        return txDigest + "#" + sendTx.dump();
    }
    json outTx = {
        {"rawTx", sendTx.dump()},
        {"realAmount", realAmount}
    };
    return txDigest + "#" + outTx.dump();
}
