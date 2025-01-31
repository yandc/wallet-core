// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "CellDep.h"
#include "OutPoint.h"
#include "Data.h"
#include "../HexCoding.h"

#include <string>
#include <unordered_map>

namespace TW::Nervos::Constants {

static const uint64_t gTransactionBaseSize = 72;
static const uint64_t gCellDepSize = 37;
static const uint64_t gHeaderDepSize = 32;
static const uint64_t gSingleInputAndWitnessBaseSize = 44;
static const uint64_t gBlankWitnessBytes = 65;
static const uint64_t gUint32Size = 4;
static const uint64_t gMinCellCapacityForNativeToken = 6100000000;
static const uint64_t gMinCellCapacityForSUDT = 14400000000;

static const Data gHashPersonalization{'c', 'k', 'b', '-', 'd', 'e', 'f', 'a',
                                       'u', 'l', 't', '-', 'h', 'a', 's', 'h'};

static const Data gSecp256k1CodeHash =
    parse_hex("9bd7e06f3ecf4be0f2fcd2188b23f1b9fcc88e5d4b65a8637b17723bbda3cce8");
static const CellDep gSecp256k1CellDep = CellDep(
    OutPoint(parse_hex("71a7ba8fc96349fea0ed3a5c47992e3b4084b031a42264a018e0072e8172e46c"), 0),
    DepType::DepGroup);
static const CellDep gSecp256k1CellDepTestNet = CellDep(
    OutPoint(parse_hex("f8de3bb47d055cdf460d93a2a6e1b05f7432f9777c8c474abf4eec1d4aee5d37"), 0),
    DepType::DepGroup);

static const Data gSUDTCodeHash =
    parse_hex("5e7a36a77e68eecc013dfa2fe6a23f3b6c344b04005808694ae6dd45eea4cfd5");
static const Data gSUDTCodeHashTestNet =
    parse_hex("c5e5dcf215925f7ef4dfaf5f4b4f105bc321c02776d6e7d52a1db3fcd9d011a4");
static const CellDep gSUDTCellDep = CellDep(
    OutPoint(parse_hex("c7813f6a415144643970c2e88e0bb6ca6a8edc5dd7c1022746f628284a9936d5"), 0),
    DepType::Code);
static const CellDep gSUDTCellDepTestNet = CellDep(
    OutPoint(parse_hex("e12877ebd2c3c364dc46c5c992bcfaf4fee33fa13eebdf82c591fc9825aab769"), 0),
    DepType::Code);

static const Data gDAOCodeHash =
    parse_hex("82d76d1b75fe2fd9a27dfbaa65a039221a380d76c926f378d3f81cf3e7e13f2e");
static const CellDep gDAOCellDep = CellDep(
    OutPoint(parse_hex("e2fb199810d49a4d8beec56718ba2593b665db9d52299a0f9e6e75416d73ff5c"), 2),
    DepType::Code);
static const CellDep gDAOCellDepTestNet = CellDep(
    OutPoint(parse_hex("8f8c79eb6671709633fe6a46de93c0fedc9c1b8a6527a18d3983879542635c9f"), 2),
    DepType::Code);

static const CellDep *gCellDep[] = {
    &gSecp256k1CellDep, &gSecp256k1CellDepTestNet,
    &gSUDTCellDep, &gSUDTCellDepTestNet,
    &gDAOCellDep, &gDAOCellDepTestNet,
};

enum CellDepType {
    Secp256k1 = 0,
    SUDT = 1,
    DAO = 2,
};

} // namespace TW::Nervos::Constants
