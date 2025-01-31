// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Data.h"
#include "Hash.h"
#include "DerivationPath.h"
#include "PrivateKey.h"
#include "PublicKey.h"
#include "uint256.h"
#include "CoinEntry.h"

#include <TrustWalletCore/TWBlockchain.h>
#include <TrustWalletCore/TWCoinType.h>
#include <TrustWalletCore/TWCurve.h>
#include <TrustWalletCore/TWHDVersion.h>
#include <TrustWalletCore/TWPurpose.h>
#include <TrustWalletCore/TWAnySigner.h>

#include <string>
#include <vector>

namespace TW {

// Return the set of supported coin types.
std::vector<TWCoinType> getCoinTypes();

/// Validates an address for a particular coin.
bool validateAddress(TWCoinType coin, const std::string& address, const char* hrp=nullptr);

/// Validates and normalizes an address for a particular coin.
std::string normalizeAddress(TWCoinType coin, const std::string& address);

/// Returns the blockchain for a coin type.
TWBlockchain blockchain(TWCoinType coin);

/// Returns the purpose for a coin type.
TWPurpose purpose(TWCoinType coin);

/// Returns the curve that should be used for a coin type.
TWCurve curve(TWCoinType coin);

/// Returns the xpub HD version that should be used for a coin type.
TWHDVersion xpubVersion(TWCoinType coin);

/// Returns the xprv HD version that should be used for a coin type.
TWHDVersion xprvVersion(TWCoinType coin);

/// Returns the default derivation path for a particular coin.
DerivationPath derivationPath(TWCoinType coin);

/// Returns the public key type for a particular coin.
enum TWPublicKeyType publicKeyType(TWCoinType coin);

/// Derives the address for a particular coin from the private key.
std::string deriveAddress(TWCoinType coin, const PrivateKey& privateKey, const char* hrp=nullptr);

/// Derives the address for a particular coin from the public key.
std::string deriveAddress(TWCoinType coin, const PublicKey& publicKey, const char* hrp=nullptr);

/// Hasher for deriving the public key hash.
Hash::Hasher publicKeyHasher(TWCoinType coin);

/// Hasher to use for base 58 checksums.
Hash::Hasher base58Hasher(TWCoinType coin);

/// Returns static prefix for a coin type.
byte staticPrefix(TWCoinType coin);

/// Returns P2PKH prefix for a coin type.
byte p2pkhPrefix(TWCoinType coin);

/// Returns P2SH prefix for a coin type.
byte p2shPrefix(TWCoinType coin);

/// Returns human readable part for a coin type.
enum TWHRP hrp(TWCoinType coin);

// Note: use output parameter to avoid unneeded copies
void anyCoinSign(TWCoinType coinType, const Data& dataIn, Data& dataOut);

uint32_t slip44Id(TWCoinType coin);

std::string handleSignJSON(TWCoinType coinType, const std::string& txInput, const Data& key, enum SignMode mode = SignMili23);
std::string anySignJSON(TWCoinType coinType, const std::string& json, const Data& key);
const char* anySignMessage(TWCoinType coinType, const std::string& msg, const Data& key);

bool supportsJSONSigning(TWCoinType coinType);

void anyCoinPlan(TWCoinType coinType, const Data& dataIn, Data& dataOut);
std::string anyCoinPlanJson(TWCoinType coinType, const std::string& jsonInput);

HashPubkeyList anyCoinPreImageHashes(TWCoinType coinType, const Data& txInputData);

void anyCoinCompileWithSignatures(TWCoinType coinType, const Data& txInputData, const std::vector<Data>& signatures, const std::vector<PublicKey>& publicKeys, Data& txOutputOut);

Data anyCoinBuildTransactionInput(TWCoinType coinType, const std::string& from, const std::string& to, const uint256_t& amount, const std::string& asset, const std::string& memo, const std::string& chainId);

// Return coins handled by the same dispatcher as the given coin (mostly for testing)
const std::vector<TWCoinType> getSimilarCoinTypes(TWCoinType coinType);

// Contains only simple types.
struct CoinInfo {
    const char* id;
    const char* name;
    TWBlockchain blockchain;
    TWPurpose purpose;
    TWCurve curve;
    TWHDVersion xpubVersion;
    TWHDVersion xprvVersion;
    const char* derivationPath;
    TWPublicKeyType publicKeyType;
    byte staticPrefix;
    byte p2pkhPrefix;
    byte p2shPrefix;
    TWHRP hrp;
    Hash::Hasher publicKeyHasher;
    Hash::Hasher base58Hasher;
    const char* symbol;
    int decimals;
    const char* explorerTransactionUrl;
    const char* explorerAccountUrl;
    uint32_t slip44;
};

} // namespace TW
