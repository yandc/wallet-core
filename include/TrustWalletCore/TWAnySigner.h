// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
#pragma once

#include "TWBase.h"
#include "TWCoinType.h"
#include "TWData.h"
#include "TWString.h"

TW_EXTERN_C_BEGIN

/// Helper class to sign any transactions.
struct TWAnySigner;

/// Signs a transaction.
extern TWData *_Nonnull TWAnySignerSign(TWData *_Nonnull input, enum TWCoinType coin);

/// Signs a json transaction with private key.
extern TWString *_Nonnull TWAnySignerSignJSON(TWString *_Nonnull json, TWData *_Nonnull key, enum TWCoinType coin);

extern bool TWAnySignerSupportsJSON(enum TWCoinType coin);

/// Plan a transaction (for UTXO chains).
extern TWData *_Nonnull TWAnySignerPlan(TWData *_Nonnull input, enum TWCoinType coin);

/// 对任意消息签名
extern TWString *_Nonnull CppSignMili23(const char *_Nonnull session, const char *_Nonnull key, const char *_Nonnull preSign, enum TWCoinType coin, const char *_Nonnull msg);

/// mili 钱包交易(json 格式)
extern TWString *_Nonnull CppJsonTransactionMili23(const char *_Nonnull session, const char *_Nonnull key, const char *_Nonnull preSign, enum TWCoinType coin, const char *_Nonnull input);

/// Plan a transaction (for UTXO chains).
extern TWString *_Nonnull CppUtxoPlan(enum TWCoinType coin, const char *_Nonnull input);
TW_EXTERN_C_END
