// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Coin.h"
#include "HexCoding.h"

#include "CoinEntry.h"
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <TrustWalletCore/TWHRP.h>

#include <map>

// #coin-list# Includes for entry points for coin implementations
#include "Aeternity/Entry.h"
#include "Aion/Entry.h"
#include "Algorand/Entry.h"
#include "Binance/Entry.h"
#include "Bitcoin/Entry.h"
#include "Cardano/Entry.h"
#include "Cosmos/Entry.h"
#include "Decred/Entry.h"
#include "EOS/Entry.h"
#include "Elrond/Entry.h"
#include "Ethereum/Entry.h"
#include "FIO/Entry.h"
#include "Filecoin/Entry.h"
#include "Groestlcoin/Entry.h"
#include "Harmony/Entry.h"
#include "Icon/Entry.h"
#include "IoTeX/Entry.h"
#include "Kusama/Entry.h"
#include "NEAR/Entry.h"
#include "NEO/Entry.h"
#include "NULS/Entry.h"
#include "Nano/Entry.h"
#include "Nebulas/Entry.h"
#include "Nimiq/Entry.h"
#include "Oasis/Entry.h"
#include "Ontology/Entry.h"
#include "Polkadot/Entry.h"
#include "Ripple/Entry.h"
#include "Ronin/Entry.h"
#include "Solana/Entry.h"
#include "Stellar/Entry.h"
#include "THORChain/Entry.h"
#include "Tezos/Entry.h"
#include "Theta/Entry.h"
#include "Tron/Entry.h"
#include "TrustWalletCore/TWCoinType.h"
#include "VeChain/Entry.h"
#include "Waves/Entry.h"
#include "Zcash/Entry.h"
#include "Zilliqa/Entry.h"
#include "Starcoin/Entry.h"
#include "Aptos/Entry.h"
#include "Sui/Entry.h"
#include "Nervos/Entry.h"
#include "Casper/Entry.h"
#include "Kaspa/Entry.h"
#include "Ton/Entry.h"
// end_of_coin_includes_marker_do_not_modify
#include <TrustWalletCore/MiliException.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace TW;
using namespace std;

// #coin-list# Global coin entry dispatcher entries
Aeternity::Entry aeternityDP;
Aion::Entry aionDP;
Algorand::Entry algorandDP;
Binance::Entry binanceDP;
Bitcoin::Entry bitcoinDP;
Cardano::Entry cardanoDP;
Cosmos::Entry cosmosDP;
Elrond::Entry elrondDP;
EOS::Entry eosDP;
Ethereum::Entry ethereumDP;
Decred::Entry decredDP;
Filecoin::Entry filecoinDP;
FIO::Entry fioDP;
Groestlcoin::Entry groestlcoinDP;
Harmony::Entry harmonyDP;
Icon::Entry iconDP;
IoTeX::Entry iotexDP;
Kusama::Entry kusamaDP;
Nano::Entry nanoDP;
NEAR::Entry nearDP;
Nebulas::Entry nebulasDP;
NEO::Entry neoDP;
Nimiq::Entry nimiqDP;
NULS::Entry nulsDP;
Ontology::Entry ontologyDP;
Oasis::Entry oasisDP;
Polkadot::Entry polkadotDP;
Ripple::Entry rippleDP;
Ronin::Entry roninDP;
Solana::Entry solanaDP;
Stellar::Entry stellarDP;
Tezos::Entry tezosDP;
Theta::Entry thetaDP;
THORChain::Entry thorchainDP;
Tron::Entry tronDP;
VeChain::Entry vechainDP;
Waves::Entry wavesDP;
Zcash::Entry zcashDP;
Zilliqa::Entry zilliqaDP;
Starcoin::Entry starcoinDP;
Aptos::Entry aptosDP;
Sui::Entry suiDP;
Nervos::Entry NervosDP;
Casper::Entry CasperDP;
Kaspa::Entry KaspaDP;
Ton::Entry TonDP;
// end_of_coin_dipatcher_declarations_marker_do_not_modify

CoinEntry* coinDispatcher(TWCoinType coinType) {
    // switch is preferred instead of a data structure, due to initialization issues
    CoinEntry* entry = nullptr;
    switch (coinType) {
        // #coin-list#
        case TWCoinTypeAeternity: entry = &aeternityDP; break;
        case TWCoinTypeAion: entry = &aionDP; break;
        case TWCoinTypeAlgorand: entry = &algorandDP; break;
        case TWCoinTypeBinance: entry = &binanceDP; break;
        case TWCoinTypeBitcoin: entry = &bitcoinDP; break;
        case TWCoinTypeBitcoinTest: entry = &bitcoinDP; break;
        case TWCoinTypeBitcoinCash: entry = &bitcoinDP; break;
        case TWCoinTypeBitcoinGold: entry = &bitcoinDP; break;
        case TWCoinTypeDash: entry = &bitcoinDP; break;
        case TWCoinTypeDigiByte: entry = &bitcoinDP; break;
        case TWCoinTypeDogecoin: entry = &bitcoinDP; break;
        case TWCoinTypeECash: entry = &bitcoinDP; break;
        case TWCoinTypeLitecoin: entry = &bitcoinDP; break;
        case TWCoinTypeMonacoin: entry = &bitcoinDP; break;
        case TWCoinTypeQtum: entry = &bitcoinDP; break;
        case TWCoinTypeRavencoin: entry = &bitcoinDP; break;
        case TWCoinTypeViacoin: entry = &bitcoinDP; break;
        case TWCoinTypeFiro: entry = &bitcoinDP; break;
        case TWCoinTypeCardano: entry = &cardanoDP; break;
        case TWCoinTypeCosmos: entry = &cosmosDP; break;
        case TWCoinTypeKava: entry = &cosmosDP; break;
        case TWCoinTypeTerra: entry = &cosmosDP; break;
        case TWCoinTypeBandChain: entry = &cosmosDP; break;
        case TWCoinTypeBluzelle: entry = &cosmosDP; break;
        case TWCoinTypeElrond: entry = &elrondDP; break;
        case TWCoinTypeEOS: entry = &eosDP; break;
        case TWCoinTypeCallisto: entry = &ethereumDP; break;
        case TWCoinTypeEthereum: entry = &ethereumDP; break;
        case TWCoinTypeEthereumClassic: entry = &ethereumDP; break;
        case TWCoinTypeGoChain: entry = &ethereumDP; break;
        case TWCoinTypePOANetwork: entry = &ethereumDP; break;
        case TWCoinTypeThunderToken: entry = &ethereumDP; break;
        case TWCoinTypeTomoChain: entry = &ethereumDP; break;
        case TWCoinTypeSmartChainLegacy: entry = &ethereumDP; break;
        case TWCoinTypeSmartChain: entry = &ethereumDP; break;
        case TWCoinTypeDecred: entry = &decredDP; break;
        case TWCoinTypeFilecoin: entry = &filecoinDP; break;
        case TWCoinTypeFIO: entry = &fioDP; break;
        case TWCoinTypeGroestlcoin: entry = &groestlcoinDP; break;
        case TWCoinTypeHarmony: entry = &harmonyDP; break;
        case TWCoinTypeICON: entry = &iconDP; break;
        case TWCoinTypeIoTeX: entry = &iotexDP; break;
        case TWCoinTypeKusama: entry = &kusamaDP; break;
        case TWCoinTypeNano: entry = &nanoDP; break;
        case TWCoinTypeNEAR: entry = &nearDP; break;
        case TWCoinTypeNebulas: entry = &nebulasDP; break;
        case TWCoinTypeNEO: entry = &neoDP; break;
        case TWCoinTypeNimiq: entry = &nimiqDP; break;
        case TWCoinTypeNULS: entry = &nulsDP; break;
        case TWCoinTypeOasis: entry = &oasisDP; break;
        case TWCoinTypeOntology: entry = &ontologyDP; break;
        case TWCoinTypePolkadot: entry = &polkadotDP; break;
        case TWCoinTypeXRP: entry = &rippleDP; break;
        case TWCoinTypeSolana: entry = &solanaDP; break;
        case TWCoinTypeStellar: entry = &stellarDP; break;
        case TWCoinTypeKin: entry = &stellarDP; break;
        case TWCoinTypeTezos: entry = &tezosDP; break;
        case TWCoinTypeTheta: entry = &thetaDP; break;
        case TWCoinTypeTHORChain: entry = &thorchainDP; break;
        case TWCoinTypeTron: entry = &tronDP; break;
        case TWCoinTypeVeChain: entry = &vechainDP; break;
        case TWCoinTypeWanchain: entry = &ethereumDP; break;
        case TWCoinTypeWaves: entry = &wavesDP; break;
        case TWCoinTypeZcash: entry = &zcashDP; break;
        case TWCoinTypeZelcash: entry = &zcashDP; break;
        case TWCoinTypeZilliqa: entry = &zilliqaDP; break;
        case TWCoinTypePolygon: entry = &ethereumDP; break;
        case TWCoinTypeOptimism: entry = &ethereumDP; break;
        case TWCoinTypeArbitrum: entry = &ethereumDP; break;
        case TWCoinTypeECOChain: entry = &ethereumDP; break;
        case TWCoinTypeAvalancheCChain: entry = &ethereumDP; break;
        case TWCoinTypeXDai: entry = &ethereumDP; break;
        case TWCoinTypeFantom: entry = &ethereumDP; break;
        case TWCoinTypeCelo: entry = &ethereumDP; break;
        case TWCoinTypeRonin: entry = &roninDP; break;
        case TWCoinTypeCryptoOrg: entry = &cosmosDP; break;
        case TWCoinTypeOsmosis: entry = &cosmosDP; break;
        case TWCoinTypeCronosChain: entry = &ethereumDP; break;
        case TWCoinTypeSmartBitcoinCash: entry = &ethereumDP; break;
        case TWCoinTypeStarcoin: entry = &starcoinDP; break;
        case TWCoinTypeAptos: entry = &aptosDP; break;
        case TWCoinTypeSui: entry = &suiDP; break;
        case TWCoinTypeNervos: entry = &NervosDP; break;
        case TWCoinTypeNervosTest: entry = &NervosDP; break;
        case TWCoinTypeCasper: entry = &CasperDP; break;
        case TWCoinTypeKaspa: entry = &KaspaDP; break;
        case TWCoinTypeSei: entry = &cosmosDP; break;
        case TWCoinTypeTon: entry = &TonDP; break;
        // end_of_coin_dipatcher_switch_marker_do_not_modify

        default: entry = nullptr; break;
    }
    assert(entry != nullptr);
    return entry;
}

std::vector<std::pair<std::string, TWCoinType>> addressPrefixCoin = {
    {"ronin:", TWCoinTypeRonin},
};

bool TW::validateAddress(TWCoinType coin, const std::string& string, const char* hrp) {
    auto p2pkh = TW::p2pkhPrefix(coin);
    auto p2sh = TW::p2shPrefix(coin);
    if (hrp == nullptr || strlen(hrp) == 0) hrp = stringForHRP(TW::hrp(coin));

    // dispatch
    for(auto& item: addressPrefixCoin) {
        if(string.compare(0, item.first.size(), item.first) == 0) {
            coin =  item.second;
            break;
        }
    }
    auto* dispatcher = coinDispatcher(coin);
    assert(dispatcher != nullptr);
    return dispatcher->validateAddress(coin, string, p2pkh, p2sh, hrp);
}

std::string TW::normalizeAddress(TWCoinType coin, const std::string& address) {
    if (!TW::validateAddress(coin, address)) {
        // invalid address, not normalizing
        return "";
    }

    // dispatch
    auto* dispatcher = coinDispatcher(coin);
    assert(dispatcher != nullptr);
    return dispatcher->normalizeAddress(coin, address);
}

std::string TW::deriveAddress(TWCoinType coin, const PrivateKey& privateKey, const char* hrp) {
    auto keyType = TW::publicKeyType(coin);
    return TW::deriveAddress(coin, privateKey.getPublicKey(keyType), hrp);
}

std::string TW::deriveAddress(TWCoinType coin, const PublicKey& publicKey, const char* hrp) {
    auto p2pkh = TW::p2pkhPrefix(coin);
    if (hrp == nullptr || strlen(hrp) == 0) hrp = stringForHRP(TW::hrp(coin));

    // dispatch
    auto* dispatcher = coinDispatcher(coin);
    assert(dispatcher != nullptr);
    return dispatcher->deriveAddress(coin, publicKey, p2pkh, hrp);
}

void TW::anyCoinSign(TWCoinType coinType, const Data& dataIn, Data& dataOut) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    dispatcher->sign(coinType, dataIn, dataOut);
}

std::string TW::handleSignJSON(TWCoinType coinType, const std::string& txInput, const Data& key, enum SignMode mode) {
    json txJson;
    txJson["txid"] = "";
    txJson["result"] = "";
    txJson["status"] = false;
    txJson["error"] = "";

    bool needSign = true;
    if (mode == SignDigest || mode == PreImage) needSign = false;
    SignGate::GetInstance().Lock(needSign);
    try {
        std::string result = TW::anySignJSON(coinType, txInput, key);
        if (mode == SignDigest) {
            json digests;
            for(auto digest: SignGate::GetInstance().GetDigests()) {
                digests.push_back(hex(digest));
            }
            txJson["result"] = digests;
            txJson["status"] = true;
        } else if (mode == SignMili23 || mode == PreImage) {
            size_t pos = result.find("#");
            if (pos != std::string::npos) {
                txJson["txid"] = result.substr(0, pos);
                txJson["result"] = result.substr(pos+1);
                txJson["status"] = true;
            } else {
                txJson["error"] = "loss of txid";
            }
        }
    } catch (MiliException& e) {
        txJson["error"] = e.what();

    } catch (std::invalid_argument& e) {
        txJson["error"] = e.what();
    }
    SignGate::GetInstance().Unlock();
    return txJson.dump();
}

std::string TW::anySignJSON(TWCoinType coinType, const std::string& json, const Data& key) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    return dispatcher->signJSON(coinType, json, key);
}

const char* TW::anySignMessage(TWCoinType coinType, const std::string& msg, const Data& key) {
    static char sig[512];
    auto dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    Data digest = dispatcher->hashMessage(coinType, msg);
    PrivateKey privKey(key);

    Data sign = privKey.sign(digest, curve(coinType));
    if(coinType == TWCoinTypeEthereum || coinType == TWCoinTypeTron) {
        sign[64] += 27;
    }
    for(int i = 0; i < sign.size(); i++) {
        sprintf(sig+i*2, "%02x", sign[i]);
    }
    sig[sign.size()*2] = 0;
    return sig;
}

bool TW::supportsJSONSigning(TWCoinType coinType) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    return dispatcher->supportsJSONSigning();
}

void TW::anyCoinPlan(TWCoinType coinType, const Data& dataIn, Data& dataOut) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    dispatcher->plan(coinType, dataIn, dataOut);
}

std::string TW::anyCoinPlanJson(TWCoinType coinType, const std::string& jsonInput) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    return dispatcher->planJson(coinType, jsonInput);
}

HashPubkeyList TW::anyCoinPreImageHashes(TWCoinType coinType, const Data& txInputData) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    return dispatcher->preImageHashes(coinType, txInputData);
}

void TW::anyCoinCompileWithSignatures(TWCoinType coinType, const Data& txInputData, const std::vector<Data>& signatures, const std::vector<PublicKey>& publicKeys, Data& txOutputOut) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    dispatcher->compile(coinType, txInputData, signatures, publicKeys, txOutputOut);
}

Data TW::anyCoinBuildTransactionInput(TWCoinType coinType, const std::string& from, const std::string& to, const uint256_t& amount, const std::string& asset, const std::string& memo, const std::string& chainId) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    return dispatcher->buildTransactionInput(coinType, from, to, amount, asset, memo, chainId);
}

// Coin info accessors

extern const CoinInfo getCoinInfo(TWCoinType coin); // in generated CoinInfoData.cpp file

TWBlockchain TW::blockchain(TWCoinType coin) {
    return getCoinInfo(coin).blockchain;
}

TWPurpose TW::purpose(TWCoinType coin) {
    return getCoinInfo(coin).purpose;
}

TWCurve TW::curve(TWCoinType coin) {
    return getCoinInfo(coin).curve;
}

TWHDVersion TW::xpubVersion(TWCoinType coin) {
    return getCoinInfo(coin).xpubVersion;
}

TWHDVersion TW::xprvVersion(TWCoinType coin) {
    return getCoinInfo(coin).xprvVersion;
}

DerivationPath TW::derivationPath(TWCoinType coin) {
    return DerivationPath(getCoinInfo(coin).derivationPath);
}

enum TWPublicKeyType TW::publicKeyType(TWCoinType coin) {
    return getCoinInfo(coin).publicKeyType;
}

TW::byte TW::staticPrefix(TWCoinType coin) {
    return getCoinInfo(coin).staticPrefix;
}

TW::byte TW::p2pkhPrefix(TWCoinType coin) {
    return getCoinInfo(coin).p2pkhPrefix;
}

TW::byte TW::p2shPrefix(TWCoinType coin) {
    return getCoinInfo(coin).p2shPrefix;
}

enum TWHRP TW::hrp(TWCoinType coin) {
    return getCoinInfo(coin).hrp;
}

Hash::Hasher TW::publicKeyHasher(TWCoinType coin) {
    return getCoinInfo(coin).publicKeyHasher;
}

Hash::Hasher TW::base58Hasher(TWCoinType coin) {
    return getCoinInfo(coin).base58Hasher;
}

uint32_t TW::slip44Id(TWCoinType coin) {
    return getCoinInfo(coin).slip44;
}

TWString* _Nullable TWCoinTypeConfigurationGetSymbol(enum TWCoinType coin) {
    return TWStringCreateWithUTF8Bytes(getCoinInfo(coin).symbol);
}

int TWCoinTypeConfigurationGetDecimals(enum TWCoinType coin) {
    return getCoinInfo(coin).decimals;
}

TWString* _Nullable TWCoinTypeConfigurationGetTransactionURL(enum TWCoinType coin, TWString* _Nonnull transactionID) {
    std::string txId = TWStringUTF8Bytes(transactionID);
    std::string url = getCoinInfo(coin).explorerTransactionUrl + txId;
    return TWStringCreateWithUTF8Bytes(url.c_str());
}

TWString* _Nullable TWCoinTypeConfigurationGetAccountURL(enum TWCoinType coin, TWString* _Nonnull accountID) {
    std::string accId = TWStringUTF8Bytes(accountID);
    std::string url = getCoinInfo(coin).explorerAccountUrl + accId;
    return TWStringCreateWithUTF8Bytes(url.c_str());
}

TWString* _Nonnull TWCoinTypeConfigurationGetID(enum TWCoinType coin) {
    return TWStringCreateWithUTF8Bytes(getCoinInfo(coin).id);
}

TWString* _Nonnull TWCoinTypeConfigurationGetName(enum TWCoinType coin) {
    return TWStringCreateWithUTF8Bytes(getCoinInfo(coin).name);
}

const std::vector<TWCoinType> TW::getSimilarCoinTypes(TWCoinType coinType) {
    const auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    return dispatcher->coinTypes();
}
