// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Transaction.h"
#include "../BinaryCoding.h"
#include "../HexCoding.h"
#include "../Hash.h"

#include <TrezorCrypto/blake2b.h>
#include <google/protobuf/util/json_util.h>

using namespace TW;
using namespace TW::Kaspa;

namespace TW::Kaspa{

Proto::Transaction Transaction::proto() const {
    Data subnetId(20, 0);
    Proto::Transaction protoTx;

    protoTx.set_version(0);
    protoTx.set_locktime(lockTime);
    protoTx.set_subnetworkid(TW::hex(subnetId));
    protoTx.set_gas(0);

    auto protoInputs = protoTx.mutable_inputs();
    for (int i = 0; i < inputs.size(); i++) {
        Proto::TransactionInput* protoInput = protoInputs->Add();
        auto& outpoint = inputs[i].previousOutput;

        protoInput->set_sigopcount(1);
        protoInput->set_signaturescript(TW::hex(inputs[i].script.bytes));
        protoInput->set_sequence(inputs[i].sequence);
        auto protoOutpoint = protoInput->mutable_previousoutpoint();
        protoOutpoint->set_index(outpoint.index);
        protoOutpoint->set_transactionid(TW::hex(outpoint.hash));
    }
    auto protoOutputs = protoTx.mutable_outputs();
    for (int i = 0; i < outputs.size(); i++) {
        Proto::TransactionOutput* protoOutput = protoOutputs->Add();
        protoOutput->set_amount(outputs[i].value);
        auto lockScript = protoOutput->mutable_scriptpublickey();
        lockScript->set_version(0);//Version: addressPublicKeyECDSAScriptPublicKeyVersion
        lockScript->set_scriptpublickey(TW::hex(outputs[i].script.bytes));
    }
    return protoTx;
}

void Transaction::hashOutpoint(const Bitcoin::OutPoint& outpoint, Data& data) const {
    append(data, TW::data(outpoint.hash.data(), 32));
    encode32LE(outpoint.index, data);
}

void Transaction::hashOutput(const Bitcoin::TransactionOutput output, Data& data) const {
    encode64LE(output.value, data);
    encode16LE(0, data);//prevScriptPublicKey.Version: addressPublicKeyECDSAScriptPublicKeyVersion
    encode64LE(output.script.bytes.size(), data);
    append(data, output.script.bytes);
}

/// Generates the signature hash for for scripts other than witness scripts.
Data Transaction::getSignatureHash(const Bitcoin::Script& scriptCode, size_t index, enum TWBitcoinSigHashType hashType,
                                   uint64_t amount, enum Bitcoin::SignatureVersion version) const {
    assert(index < inputs.size());
    Data subnetId(20, 0);
    Data data;
    encode16LE(0, data);//version

    Data hashResult(32, 0);
    std::string key = "TransactionSigningHash";


    Data inputHashData;
    Data seqHashData;
    for (int i = 0; i < inputs.size(); i++) {
        hashOutpoint(inputs[i].previousOutput, inputHashData);
        encode64LE(uint64_t(inputs[i].sequence), seqHashData);
    }
    blake2b_Key(inputHashData.data(), inputHashData.size(), key.c_str(), key.size(), hashResult.data(), 32);
    append(data, hashResult);

    blake2b_Key(seqHashData.data(), seqHashData.size(), key.c_str(), key.size(), hashResult.data(), 32);
    append(data, hashResult);

    Data sigOpCountHashData(inputs.size(), 1);
    blake2b_Key(sigOpCountHashData.data(), sigOpCountHashData.size(), key.c_str(), key.size(), hashResult.data(), 32);
    append(data, hashResult);

    auto input = inputs[index];
    hashOutpoint(input.previousOutput, data);
    encode16LE(0, data);//prevScriptPublicKey.Version: addressPublicKeyECDSAScriptPublicKeyVersion
    encode64LE(scriptCode.bytes.size(), data);
    append(data, scriptCode.bytes);//prevScriptPublicKey.Script

    encode64LE(amount, data);
    encode64LE(input.sequence, data);
    data.push_back(uint8_t(1)); //SigOpCount

    Data outputHashData;
    for (int i = 0; i < outputs.size(); i++) {
        hashOutput(outputs[i], outputHashData);
    }
    blake2b_Key(outputHashData.data(), outputHashData.size(), key.c_str(), key.size(), hashResult.data(), 32);
    append(data, hashResult);

    encode64LE(uint64_t(lockTime), data);
    append(data, subnetId);//SubnetworkID: SubnetworkIDNative
    encode64LE(0, data);//gas
    Data zeroHash(32, 0);//payloadHash: zero hash when SubnetworkIDNative
    append(data, zeroHash);
    data.push_back(static_cast<byte>(TWBitcoinSigHashTypeAll));//hashType: SigHashAll

    blake2b_Key(data.data(), data.size(), key.c_str(), key.size(), hashResult.data(), 32);
    Data finalHashData = Hash::sha256(TW::data("TransactionSigningHashECDSA"));
    append(finalHashData, hashResult);
    return Hash::sha256(finalHashData);
}

Data Transaction::getTransactionID() const {
    Data subnetId(20, 0);
    Data data;
    encode16LE(0, data);//version
    encode64LE(inputs.size(), data);
    for (int i = 0; i < inputs.size(); i++) {//kaspad/domain/consensus/utils/consensushashing/transaction.go:writeTransactionInput
        hashOutpoint(inputs[i].previousOutput, data);
        encode64LE(0, data);//writeVarBytes(w, []byte{})
        encode64LE(uint64_t(inputs[i].sequence), data);
    }
    encode64LE(outputs.size(), data);
    for (int i = 0; i < outputs.size(); i++) {
        hashOutput(outputs[i], data);
    }
    encode64LE(uint64_t(lockTime), data);
    append(data, subnetId);
    encode64LE(0, data);//gas
    encode64LE(0, data);//payload: []bytes

    Data txID(32, 0);
    std::string key = "TransactionID";
    blake2b_Key(data.data(), data.size(), key.c_str(), key.size(), txID.data(), 32);
    return txID;
}

} // namespace
