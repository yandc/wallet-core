// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <TrustWalletCore/TWHDWallet.h>
#include <TrustWalletCore/MiliException.h>

#include "../Coin.h"
#include "../HDWallet.h"
#include "../Mnemonic.h"
#include "../HexCoding.h"
#include "../Hash.h"

using namespace TW;


struct TWHDWallet *_Nullable TWHDWalletCreate(int strength, TWString *_Nonnull passphrase) {
    try {
        return new TWHDWallet{ HDWallet(strength, TWStringUTF8Bytes(passphrase)) };
    } catch (...) {
        return nullptr;
    }
}

struct TWHDWallet *_Nullable TWHDWalletCreateWithMnemonic(TWString *_Nonnull mnemonic, TWString *_Nonnull passphrase) {
    try {
        return new TWHDWallet{ HDWallet(TWStringUTF8Bytes(mnemonic), TWStringUTF8Bytes(passphrase)) };
    } catch (...) {
        return nullptr;
    }
}

struct TWHDWallet *_Nullable TWHDWalletCreateWithMnemonicCheck(TWString *_Nonnull mnemonic, TWString *_Nonnull passphrase, bool check) {
    try {
        return new TWHDWallet{ HDWallet(TWStringUTF8Bytes(mnemonic), TWStringUTF8Bytes(passphrase), check) };
    } catch (...) {
        return nullptr;
    }
}

struct TWHDWallet *_Nullable TWHDWalletCreateWithEntropy(TWData *_Nonnull entropy, TWString *_Nonnull passphrase) {
    try {
        auto* d = reinterpret_cast<const Data*>(entropy);
        return new TWHDWallet{ HDWallet(*d, TWStringUTF8Bytes(passphrase)) };
    } catch (...) {
        return nullptr;
    }
}

void TWHDWalletDelete(struct TWHDWallet *wallet) {
    delete wallet;
}

TWData *_Nonnull TWHDWalletSeed(struct TWHDWallet *_Nonnull wallet) {
    return TWDataCreateWithBytes(wallet->impl.getSeed().data(), HDWallet::seedSize);
}

TWString *_Nonnull TWHDWalletMnemonic(struct TWHDWallet *_Nonnull wallet){
    return TWStringCreateWithUTF8Bytes(wallet->impl.getMnemonic().c_str());
}

TWData *_Nonnull TWHDWalletEntropy(struct TWHDWallet *_Nonnull wallet) {
    return TWDataCreateWithBytes(wallet->impl.getEntropy().data(), wallet->impl.getEntropy().size());
}

const char *_Nonnull CppCreateHDWallet(int strength, const char *_Nonnull passphrase) {
    static char wallet[1024];
    HDWallet w = HDWallet(strength, passphrase);
    std::string a = hex(Hash::sha256(w.getMnemonic()));
    a += ",";
    a += hex(w.getEntropy());
    memcpy(wallet, a.c_str(), a.size());
    wallet[a.size()] = 0;
    return wallet;
}

const char *_Nonnull CppDeriveAddressFromHDWallet(const char *_Nonnull wallet, const char *_Nonnull passphrase, enum TWCoinType coin, int index) {
    static char addr[512];
    std::string parts(wallet);
    size_t pos = parts.find(",");
    if (pos == std::string::npos) {
        return addr;
    }

    addr[0] = 0;
    auto w = HDWallet(parse_hex(parts.substr(pos+1)), passphrase);
    if (hex(Hash::sha256(w.getMnemonic())) != parts.substr(0, pos)) {
        return addr;
    }

    auto derivationPath = TW::derivationPath(coin);
    derivationPath.setAddress(index);
    PrivateKey privateKey = w.getKey(coin, derivationPath);
    std::string address = deriveAddress(coin, privateKey);
    memcpy(addr, address.c_str(), address.size());
    addr[address.size()] = 0;
    return addr;
}

TWString *_Nonnull CppJsonTransactionHDWallet(const char *_Nonnull txInput, const char *_Nonnull wallet, const char *_Nonnull passphrase, enum TWCoinType coin, int index) {
    std::string result;
    std::string parts(wallet);
    size_t pos = parts.find(",");
    if (pos == std::string::npos) {
        return TWStringCreateWithUTF8Bytes(result.c_str());
    }
    auto w = HDWallet(parse_hex(parts.substr(pos+1)), passphrase);
    if (hex(Hash::sha256(w.getMnemonic())) != parts.substr(0, pos)) {
        return TWStringCreateWithUTF8Bytes(result.c_str());
    }
    auto derivationPath = TW::derivationPath(coin);
    derivationPath.setAddress(index);
    PrivateKey privateKey = w.getKey(coin, derivationPath);

    result = handleSignJSON(coin, txInput, privateKey.bytes);
    return TWStringCreateWithUTF8Bytes(result.c_str());
}

struct TWPrivateKey *_Nonnull TWHDWalletGetMasterKey(struct TWHDWallet *_Nonnull wallet, TWCurve curve) {
    return new TWPrivateKey{ wallet->impl.getMasterKey(curve) };
}

struct TWPrivateKey *_Nonnull TWHDWalletGetKeyForCoin(struct TWHDWallet *wallet, TWCoinType coin) {
    auto derivationPath = TW::derivationPath(coin);
    return new TWPrivateKey{ wallet->impl.getKey(coin, derivationPath) };
}

TWString *_Nonnull TWHDWalletGetAddressForCoin(struct TWHDWallet *wallet, TWCoinType coin) {
    auto derivationPath = TW::derivationPath(coin);
    PrivateKey privateKey = wallet->impl.getKey(coin, derivationPath);
    std::string address = deriveAddress(coin, privateKey);
    return TWStringCreateWithUTF8Bytes(address.c_str());
}

struct TWPrivateKey *_Nonnull TWHDWalletGetKey(struct TWHDWallet *_Nonnull wallet, enum TWCoinType coin, TWString *_Nonnull derivationPath) {
    auto& s = *reinterpret_cast<const std::string*>(derivationPath);
    const auto path = DerivationPath(s);
    return new TWPrivateKey{ wallet->impl.getKey(coin, path) };
}

struct TWPrivateKey *_Nonnull TWHDWalletGetDerivedKey(struct TWHDWallet *_Nonnull wallet, enum TWCoinType coin, uint32_t account, uint32_t change, uint32_t address) {
    const auto derivationPath = DerivationPath(TW::purpose(coin), TW::slip44Id(coin), account, change, address);
    return new TWPrivateKey{ wallet->impl.getKey(coin, derivationPath) };
}

TWString *_Nonnull TWHDWalletGetExtendedPrivateKey(struct TWHDWallet *wallet, TWPurpose purpose, TWCoinType coin, TWHDVersion version) {
    return new std::string(wallet->impl.getExtendedPrivateKey(purpose, coin, version));
}

TWString *_Nonnull TWHDWalletGetExtendedPublicKey(struct TWHDWallet *wallet, TWPurpose purpose, TWCoinType coin, TWHDVersion version) {
    return new std::string(wallet->impl.getExtendedPublicKey(purpose, coin, version));
}

TWPublicKey *TWHDWalletGetPublicKeyFromExtended(TWString *_Nonnull extended, enum TWCoinType coin, TWString *_Nonnull derivationPath) {
    const auto derivationPathObject = DerivationPath(*reinterpret_cast<const std::string*>(derivationPath));
    auto publicKey = HDWallet::getPublicKeyFromExtended(*reinterpret_cast<const std::string*>(extended), coin, derivationPathObject);
    if (!publicKey) {
        return nullptr;
    }
    return new TWPublicKey{ PublicKey(*publicKey) };
}
