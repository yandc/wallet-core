#pragma once

#include "serde.hpp"

namespace sui_types {

    struct AccountAddress {
        std::array<uint8_t, 20> value;

        friend bool operator==(const AccountAddress&, const AccountAddress&);
    };

    struct ObjectID {
        sui_types::AccountAddress value;

        friend bool operator==(const ObjectID&, const ObjectID&);
    };

    struct CircularObjectOwnership {
        sui_types::ObjectID object;

        friend bool operator==(const CircularObjectOwnership&, const CircularObjectOwnership&);
    };

    struct DeleteKind {

        struct Normal {
            friend bool operator==(const Normal&, const Normal&);
        };

        struct UnwrapThenDelete {
            friend bool operator==(const UnwrapThenDelete&, const UnwrapThenDelete&);
        };

        struct Wrap {
            friend bool operator==(const Wrap&, const Wrap&);
        };

        std::variant<Normal, UnwrapThenDelete, Wrap> value;

        friend bool operator==(const DeleteKind&, const DeleteKind&);
    };

    struct EntryArgumentErrorKind {

        struct TypeMismatch {
            friend bool operator==(const TypeMismatch&, const TypeMismatch&);
        };

        struct InvalidObjectByValue {
            friend bool operator==(const InvalidObjectByValue&, const InvalidObjectByValue&);
        };

        struct InvalidObjectByMuteRef {
            friend bool operator==(const InvalidObjectByMuteRef&, const InvalidObjectByMuteRef&);
        };

        struct ObjectKindMismatch {
            friend bool operator==(const ObjectKindMismatch&, const ObjectKindMismatch&);
        };

        struct UnsupportedPureArg {
            friend bool operator==(const UnsupportedPureArg&, const UnsupportedPureArg&);
        };

        struct ArityMismatch {
            friend bool operator==(const ArityMismatch&, const ArityMismatch&);
        };

        std::variant<TypeMismatch, InvalidObjectByValue, InvalidObjectByMuteRef, ObjectKindMismatch, UnsupportedPureArg, ArityMismatch> value;

        friend bool operator==(const EntryArgumentErrorKind&, const EntryArgumentErrorKind&);
    };

    struct EntryArgumentError {
        uint8_t argument_idx;
        sui_types::EntryArgumentErrorKind kind;

        friend bool operator==(const EntryArgumentError&, const EntryArgumentError&);
    };

    struct InvalidSharedByValue {
        sui_types::ObjectID object;

        friend bool operator==(const InvalidSharedByValue&, const InvalidSharedByValue&);
    };

    struct InvalidSharedChildUse {
        sui_types::ObjectID child;
        sui_types::ObjectID ancestor;

        friend bool operator==(const InvalidSharedChildUse&, const InvalidSharedChildUse&);
    };

    struct SuiAddress {
        std::array<uint8_t, 20> value;

        friend bool operator==(const SuiAddress&, const SuiAddress&);
    };

    struct MissingObjectOwner {
        sui_types::ObjectID child;
        sui_types::SuiAddress parent;

        friend bool operator==(const MissingObjectOwner&, const MissingObjectOwner&);
    };

    struct Identifier {
        std::string value;

        friend bool operator==(const Identifier&, const Identifier&);
    };

    struct ModuleId {
        sui_types::AccountAddress address;
        sui_types::Identifier name;

        friend bool operator==(const ModuleId&, const ModuleId&);
    };

    struct ExecutionFailureStatus {

        struct InsufficientGas {
            friend bool operator==(const InsufficientGas&, const InsufficientGas&);
        };

        struct InvalidGasObject {
            friend bool operator==(const InvalidGasObject&, const InvalidGasObject&);
        };

        struct InvalidTransactionUpdate {
            friend bool operator==(const InvalidTransactionUpdate&, const InvalidTransactionUpdate&);
        };

        struct ModuleNotFound {
            friend bool operator==(const ModuleNotFound&, const ModuleNotFound&);
        };

        struct FunctionNotFound {
            friend bool operator==(const FunctionNotFound&, const FunctionNotFound&);
        };

        struct InvariantViolation {
            friend bool operator==(const InvariantViolation&, const InvariantViolation&);
        };

        struct InvalidTransferObject {
            friend bool operator==(const InvalidTransferObject&, const InvalidTransferObject&);
        };

        struct InvalidTransferSui {
            friend bool operator==(const InvalidTransferSui&, const InvalidTransferSui&);
        };

        struct InvalidTransferSuiInsufficientBalance {
            friend bool operator==(const InvalidTransferSuiInsufficientBalance&, const InvalidTransferSuiInsufficientBalance&);
        };

        struct NonEntryFunctionInvoked {
            friend bool operator==(const NonEntryFunctionInvoked&, const NonEntryFunctionInvoked&);
        };

        struct EntryTypeArityMismatch {
            friend bool operator==(const EntryTypeArityMismatch&, const EntryTypeArityMismatch&);
        };

        struct EntryArgumentError {
            sui_types::EntryArgumentError value;

            friend bool operator==(const EntryArgumentError&, const EntryArgumentError&);
        };

        struct CircularObjectOwnership {
            sui_types::CircularObjectOwnership value;

            friend bool operator==(const CircularObjectOwnership&, const CircularObjectOwnership&);
        };

        struct MissingObjectOwner {
            sui_types::MissingObjectOwner value;

            friend bool operator==(const MissingObjectOwner&, const MissingObjectOwner&);
        };

        struct InvalidSharedChildUse {
            sui_types::InvalidSharedChildUse value;

            friend bool operator==(const InvalidSharedChildUse&, const InvalidSharedChildUse&);
        };

        struct InvalidSharedByValue {
            sui_types::InvalidSharedByValue value;

            friend bool operator==(const InvalidSharedByValue&, const InvalidSharedByValue&);
        };

        struct TooManyChildObjects {
            sui_types::ObjectID object;

            friend bool operator==(const TooManyChildObjects&, const TooManyChildObjects&);
        };

        struct InvalidParentDeletion {
            sui_types::ObjectID parent;
            std::optional<sui_types::DeleteKind> kind;

            friend bool operator==(const InvalidParentDeletion&, const InvalidParentDeletion&);
        };

        struct InvalidParentFreezing {
            sui_types::ObjectID parent;

            friend bool operator==(const InvalidParentFreezing&, const InvalidParentFreezing&);
        };

        struct PublishErrorEmptyPackage {
            friend bool operator==(const PublishErrorEmptyPackage&, const PublishErrorEmptyPackage&);
        };

        struct PublishErrorNonZeroAddress {
            friend bool operator==(const PublishErrorNonZeroAddress&, const PublishErrorNonZeroAddress&);
        };

        struct PublishErrorDuplicateModule {
            friend bool operator==(const PublishErrorDuplicateModule&, const PublishErrorDuplicateModule&);
        };

        struct SuiMoveVerificationError {
            friend bool operator==(const SuiMoveVerificationError&, const SuiMoveVerificationError&);
        };

        struct MovePrimitiveRuntimeError {
            friend bool operator==(const MovePrimitiveRuntimeError&, const MovePrimitiveRuntimeError&);
        };

        struct MoveAbort {
            std::tuple<sui_types::ModuleId, uint64_t> value;

            friend bool operator==(const MoveAbort&, const MoveAbort&);
        };

        struct VMVerificationOrDeserializationError {
            friend bool operator==(const VMVerificationOrDeserializationError&, const VMVerificationOrDeserializationError&);
        };

        struct VMInvariantViolation {
            friend bool operator==(const VMInvariantViolation&, const VMInvariantViolation&);
        };

        std::variant<InsufficientGas, InvalidGasObject, InvalidTransactionUpdate, ModuleNotFound, FunctionNotFound, InvariantViolation, InvalidTransferObject, InvalidTransferSui, InvalidTransferSuiInsufficientBalance, NonEntryFunctionInvoked, EntryTypeArityMismatch, EntryArgumentError, CircularObjectOwnership, MissingObjectOwner, InvalidSharedChildUse, InvalidSharedByValue, TooManyChildObjects, InvalidParentDeletion, InvalidParentFreezing, PublishErrorEmptyPackage, PublishErrorNonZeroAddress, PublishErrorDuplicateModule, SuiMoveVerificationError, MovePrimitiveRuntimeError, MoveAbort, VMVerificationOrDeserializationError, VMInvariantViolation> value;

        friend bool operator==(const ExecutionFailureStatus&, const ExecutionFailureStatus&);
    };

    struct ObjectDigest {
        std::vector<uint8_t> value;

        friend bool operator==(const ObjectDigest&, const ObjectDigest&);
    };

    struct SequenceNumber {
        uint64_t value;

        friend bool operator==(const SequenceNumber&, const SequenceNumber&);
    };

    struct ObjectArg {

        struct ImmOrOwnedObject {
            std::tuple<sui_types::ObjectID, sui_types::SequenceNumber, sui_types::ObjectDigest> value;

            friend bool operator==(const ImmOrOwnedObject&, const ImmOrOwnedObject&);
        };

        struct SharedObject {
            sui_types::ObjectID value;

            friend bool operator==(const SharedObject&, const SharedObject&);
        };

        std::variant<ImmOrOwnedObject, SharedObject> value;

        friend bool operator==(const ObjectArg&, const ObjectArg&);
    };

    struct CallArg {

        struct Pure {
            std::vector<uint8_t> value;

            friend bool operator==(const Pure&, const Pure&);
        };

        struct Object {
            sui_types::ObjectArg value;

            friend bool operator==(const Object&, const Object&);
        };

        std::variant<Pure, Object> value;

        friend bool operator==(const CallArg&, const CallArg&);
    };

    struct TypeTag;

    struct StructTag {
        sui_types::AccountAddress address;
        sui_types::Identifier module;
        sui_types::Identifier name;
        std::vector<sui_types::TypeTag> type_args;

        friend bool operator==(const StructTag&, const StructTag&);
    };

    struct TypeTag {

        struct Bool {
            friend bool operator==(const Bool&, const Bool&);
        };

        struct U8 {
            friend bool operator==(const U8&, const U8&);
        };

        struct U64 {
            friend bool operator==(const U64&, const U64&);
        };

        struct U128 {
            friend bool operator==(const U128&, const U128&);
        };

        struct address {
            friend bool operator==(const address&, const address&);
        };

        struct signer {
            friend bool operator==(const signer&, const signer&);
        };

        struct Vector {
            serde::value_ptr<sui_types::TypeTag> value;

            friend bool operator==(const Vector&, const Vector&);
        };

        struct Struct {
            sui_types::StructTag value;

            friend bool operator==(const Struct&, const Struct&);
        };

        std::variant<Bool, U8, U64, U128, address, signer, Vector, Struct> value;

        friend bool operator==(const TypeTag&, const TypeTag&);
    };

    struct MoveCall {
        std::tuple<sui_types::ObjectID, sui_types::SequenceNumber, sui_types::ObjectDigest> package;
        sui_types::Identifier module;
        sui_types::Identifier function;
        std::vector<sui_types::TypeTag> type_arguments;
        std::vector<sui_types::CallArg> arguments;

        friend bool operator==(const MoveCall&, const MoveCall&);
    };

    struct ChangeEpoch {
        uint64_t epoch;
        uint64_t storage_charge;
        uint64_t computation_charge;

        friend bool operator==(const ChangeEpoch&, const ChangeEpoch&);
    };

    struct MoveModulePublish {
        std::vector<std::vector<uint8_t>> modules;

        friend bool operator==(const MoveModulePublish&, const MoveModulePublish&);
    };

    struct TransferObject {
        sui_types::SuiAddress recipient;
        std::tuple<sui_types::ObjectID, sui_types::SequenceNumber, sui_types::ObjectDigest> object_ref;

        friend bool operator==(const TransferObject&, const TransferObject&);
    };

    struct TransferSui {
        sui_types::SuiAddress recipient;
        std::optional<uint64_t> amount;

        friend bool operator==(const TransferSui&, const TransferSui&);
    };

    struct SingleTransactionKind {

        struct TransferObject {
            sui_types::TransferObject value;

            friend bool operator==(const TransferObject&, const TransferObject&);
        };

        struct Publish {
            sui_types::MoveModulePublish value;

            friend bool operator==(const Publish&, const Publish&);
        };

        struct Call {
            sui_types::MoveCall value;

            friend bool operator==(const Call&, const Call&);
        };

        struct TransferSui {
            sui_types::TransferSui value;

            friend bool operator==(const TransferSui&, const TransferSui&);
        };

        struct ChangeEpoch {
            sui_types::ChangeEpoch value;

            friend bool operator==(const ChangeEpoch&, const ChangeEpoch&);
        };

        std::variant<TransferObject, Publish, Call, TransferSui, ChangeEpoch> value;

        friend bool operator==(const SingleTransactionKind&, const SingleTransactionKind&);
    };

    struct TransactionKind {

        struct Single {
            sui_types::SingleTransactionKind value;

            friend bool operator==(const Single&, const Single&);
        };

        struct Batch {
            std::vector<sui_types::SingleTransactionKind> value;

            friend bool operator==(const Batch&, const Batch&);
        };

        std::variant<Single, Batch> value;

        friend bool operator==(const TransactionKind&, const TransactionKind&);
    };

    struct TransactionData {
        sui_types::TransactionKind kind;
        sui_types::SuiAddress sender;
        std::tuple<sui_types::ObjectID, sui_types::SequenceNumber, sui_types::ObjectDigest> gas_payment;
        uint64_t gas_price;
        uint64_t gas_budget;

        friend bool operator==(const TransactionData&, const TransactionData&);
    };

    struct MoveStructLayout;

    struct MoveTypeLayout;

    struct MoveTypeLayout {

        struct Bool {
            friend bool operator==(const Bool&, const Bool&);
        };

        struct U8 {
            friend bool operator==(const U8&, const U8&);
        };

        struct U64 {
            friend bool operator==(const U64&, const U64&);
        };

        struct U128 {
            friend bool operator==(const U128&, const U128&);
        };

        struct address {
            friend bool operator==(const address&, const address&);
        };

        struct Vector {
            serde::value_ptr<sui_types::MoveTypeLayout> value;

            friend bool operator==(const Vector&, const Vector&);
        };

        struct Struct {
            serde::value_ptr<sui_types::MoveStructLayout> value;

            friend bool operator==(const Struct&, const Struct&);
        };

        struct signer {
            friend bool operator==(const signer&, const signer&);
        };

        std::variant<Bool, U8, U64, U128, address, Vector, Struct, signer> value;

        friend bool operator==(const MoveTypeLayout&, const MoveTypeLayout&);
    };

    struct MoveFieldLayout {
        sui_types::Identifier name;
        sui_types::MoveTypeLayout layout;

        friend bool operator==(const MoveFieldLayout&, const MoveFieldLayout&);
    };

    struct MoveStructLayout {

        struct Runtime {
            std::vector<sui_types::MoveTypeLayout> value;

            friend bool operator==(const Runtime&, const Runtime&);
        };

        struct WithFields {
            std::vector<sui_types::MoveFieldLayout> value;

            friend bool operator==(const WithFields&, const WithFields&);
        };

        struct WithTypes {
            sui_types::StructTag type_;
            std::vector<sui_types::MoveFieldLayout> fields;

            friend bool operator==(const WithTypes&, const WithTypes&);
        };

        std::variant<Runtime, WithFields, WithTypes> value;

        friend bool operator==(const MoveStructLayout&, const MoveStructLayout&);
    };

    struct AuthorityPublicKeyBytes {
        std::vector<uint8_t> value;

        friend bool operator==(const AuthorityPublicKeyBytes&, const AuthorityPublicKeyBytes&);
    };

    struct Ed25519Signature {
        std::vector<uint8_t> raw;

        friend bool operator==(const Ed25519Signature&, const Ed25519Signature&);
    };

    struct AuthoritySignInfo {
        uint64_t epoch;
        sui_types::AuthorityPublicKeyBytes authority;
        sui_types::Ed25519Signature signature;

        friend bool operator==(const AuthoritySignInfo&, const AuthoritySignInfo&);
    };

    struct Balance {
        uint64_t value;

        friend bool operator==(const Balance&, const Balance&);
    };

    struct Id {
        sui_types::ObjectID value;

        friend bool operator==(const Id&, const Id&);
    };

    struct UID {
        sui_types::Id value;

        friend bool operator==(const UID&, const UID&);
    };

    struct Coin {
        sui_types::UID id;
        sui_types::Balance balance;

        friend bool operator==(const Coin&, const Coin&);
    };

    struct MoveObject {
        sui_types::StructTag type_;
        bool has_public_transfer;
        sui_types::SequenceNumber version;
        std::optional<uint32_t> child_count;
        std::vector<uint8_t> contents;

        friend bool operator==(const MoveObject&, const MoveObject&);
    };

    struct MovePackage {
        sui_types::ObjectID id;
        std::map<std::string, std::vector<uint8_t>> module_map;

        friend bool operator==(const MovePackage&, const MovePackage&);
    };

    struct Data {

        struct Move {
            sui_types::MoveObject value;

            friend bool operator==(const Move&, const Move&);
        };

        struct Package {
            sui_types::MovePackage value;

            friend bool operator==(const Package&, const Package&);
        };

        std::variant<Move, Package> value;

        friend bool operator==(const Data&, const Data&);
    };

    struct AuthorityBatch {
        uint64_t next_sequence_number;
        uint64_t initial_sequence_number;
        uint64_t size;
        std::optional<std::array<uint8_t, 32>> previous_digest;
        std::array<uint8_t, 32> transactions_digest;

        friend bool operator==(const AuthorityBatch&, const AuthorityBatch&);
    };

    struct Envelope {
        sui_types::AuthorityBatch data;
        sui_types::AuthoritySignInfo auth_signature;

        friend bool operator==(const Envelope&, const Envelope&);
    };

    struct TransactionDigest {
        std::vector<uint8_t> value;

        friend bool operator==(const TransactionDigest&, const TransactionDigest&);
    };

    struct TransactionEffectsDigest {
        std::vector<uint8_t> value;

        friend bool operator==(const TransactionEffectsDigest&, const TransactionEffectsDigest&);
    };

    struct ExecutionDigests {
        sui_types::TransactionDigest transaction;
        sui_types::TransactionEffectsDigest effects;

        friend bool operator==(const ExecutionDigests&, const ExecutionDigests&);
    };

    struct ObjectFormatOptions {
        bool include_types;

        friend bool operator==(const ObjectFormatOptions&, const ObjectFormatOptions&);
    };

    struct ObjectInfoRequestKind {

        struct LatestObjectInfo {
            std::optional<sui_types::ObjectFormatOptions> value;

            friend bool operator==(const LatestObjectInfo&, const LatestObjectInfo&);
        };

        struct PastObjectInfo {
            sui_types::SequenceNumber value;

            friend bool operator==(const PastObjectInfo&, const PastObjectInfo&);
        };

        std::variant<LatestObjectInfo, PastObjectInfo> value;

        friend bool operator==(const ObjectInfoRequestKind&, const ObjectInfoRequestKind&);
    };

    struct Ed25519SuiSignature {
        std::vector<uint8_t> value;

        friend bool operator==(const Ed25519SuiSignature&, const Ed25519SuiSignature&);
    };

    struct Secp256k1SuiSignature {
        std::vector<uint8_t> value;

        friend bool operator==(const Secp256k1SuiSignature&, const Secp256k1SuiSignature&);
    };

    struct Signature {

        struct Ed25519Signature {
            sui_types::Ed25519SuiSignature value;

            friend bool operator==(const Ed25519Signature&, const Ed25519Signature&);
        };

        struct Secp256k1SuiSignature {
            sui_types::Secp256k1SuiSignature value;

            friend bool operator==(const Secp256k1SuiSignature&, const Secp256k1SuiSignature&);
        };

        std::variant<Ed25519Signature, Secp256k1SuiSignature> value;

        friend bool operator==(const Signature&, const Signature&);
    };

    struct SenderSignedData {
        sui_types::TransactionData data;
        sui_types::Signature tx_signature;

        friend bool operator==(const SenderSignedData&, const SenderSignedData&);
    };

    struct UpdateItem {

        struct Transaction {
            std::tuple<uint64_t, sui_types::ExecutionDigests> value;

            friend bool operator==(const Transaction&, const Transaction&);
        };

        struct Batch {
            sui_types::Envelope value;

            friend bool operator==(const Batch&, const Batch&);
        };

        std::variant<Transaction, Batch> value;

        friend bool operator==(const UpdateItem&, const UpdateItem&);
    };

    struct AbortLocation {

        struct Module {
            sui_types::ModuleId value;

            friend bool operator==(const Module&, const Module&);
        };

        struct Script {
            friend bool operator==(const Script&, const Script&);
        };

        std::variant<Module, Script> value;

        friend bool operator==(const AbortLocation&, const AbortLocation&);
    };

    struct Ed25519PublicKey {
        std::string value;

        friend bool operator==(const Ed25519PublicKey&, const Ed25519PublicKey&);
    };

    struct Ed25519KeyPair {
        std::string type;
        sui_types::Ed25519PublicKey name;
        sui_types::Ed25519PublicKey secret;

        friend bool operator==(const Ed25519KeyPair&, const Ed25519KeyPair&);
    };

    struct ExecutionStatus {

        struct Success {
            friend bool operator==(const Success&, const Success&);
        };

        struct Failure {
            sui_types::ExecutionFailureStatus error;

            friend bool operator==(const Failure&, const Failure&);
        };

        std::variant<Success, Failure> value;

        friend bool operator==(const ExecutionStatus&, const ExecutionStatus&);
    };

    struct Owner {

        struct AddressOwner {
            sui_types::SuiAddress value;

            friend bool operator==(const AddressOwner&, const AddressOwner&);
        };

        struct ObjectOwner {
            sui_types::SuiAddress value;

            friend bool operator==(const ObjectOwner&, const ObjectOwner&);
        };

        struct Shared {
            friend bool operator==(const Shared&, const Shared&);
        };

        struct Immutable {
            friend bool operator==(const Immutable&, const Immutable&);
        };

        std::variant<AddressOwner, ObjectOwner, Shared, Immutable> value;

        friend bool operator==(const Owner&, const Owner&);
    };

    struct TypedStoreError {

        struct RocksDBError {
            std::string value;

            friend bool operator==(const RocksDBError&, const RocksDBError&);
        };

        struct SerializationError {
            std::string value;

            friend bool operator==(const SerializationError&, const SerializationError&);
        };

        struct UnregisteredColumn {
            std::string value;

            friend bool operator==(const UnregisteredColumn&, const UnregisteredColumn&);
        };

        struct CrossDBBatch {
            friend bool operator==(const CrossDBBatch&, const CrossDBBatch&);
        };

        std::variant<RocksDBError, SerializationError, UnregisteredColumn, CrossDBBatch> value;

        friend bool operator==(const TypedStoreError&, const TypedStoreError&);
    };

} // end of namespace sui_types


namespace sui_types {

    inline bool operator==(const AbortLocation &lhs, const AbortLocation &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::AbortLocation>::serialize(const sui_types::AbortLocation &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::AbortLocation serde::Deserializable<sui_types::AbortLocation>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::AbortLocation obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const AbortLocation::Module &lhs, const AbortLocation::Module &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::AbortLocation::Module>::serialize(const sui_types::AbortLocation::Module &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::AbortLocation::Module serde::Deserializable<sui_types::AbortLocation::Module>::deserialize(Deserializer &deserializer) {
    sui_types::AbortLocation::Module obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const AbortLocation::Script &lhs, const AbortLocation::Script &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::AbortLocation::Script>::serialize(const sui_types::AbortLocation::Script &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::AbortLocation::Script serde::Deserializable<sui_types::AbortLocation::Script>::deserialize(Deserializer &deserializer) {
    sui_types::AbortLocation::Script obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const AccountAddress &lhs, const AccountAddress &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::AccountAddress>::serialize(const sui_types::AccountAddress &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::AccountAddress serde::Deserializable<sui_types::AccountAddress>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::AccountAddress obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const AuthorityBatch &lhs, const AuthorityBatch &rhs) {
        if (!(lhs.next_sequence_number == rhs.next_sequence_number)) { return false; }
        if (!(lhs.initial_sequence_number == rhs.initial_sequence_number)) { return false; }
        if (!(lhs.size == rhs.size)) { return false; }
        if (!(lhs.previous_digest == rhs.previous_digest)) { return false; }
        if (!(lhs.transactions_digest == rhs.transactions_digest)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::AuthorityBatch>::serialize(const sui_types::AuthorityBatch &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.next_sequence_number)>::serialize(obj.next_sequence_number, serializer);
    serde::Serializable<decltype(obj.initial_sequence_number)>::serialize(obj.initial_sequence_number, serializer);
    serde::Serializable<decltype(obj.size)>::serialize(obj.size, serializer);
    serde::Serializable<decltype(obj.previous_digest)>::serialize(obj.previous_digest, serializer);
    serde::Serializable<decltype(obj.transactions_digest)>::serialize(obj.transactions_digest, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::AuthorityBatch serde::Deserializable<sui_types::AuthorityBatch>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::AuthorityBatch obj;
    obj.next_sequence_number = serde::Deserializable<decltype(obj.next_sequence_number)>::deserialize(deserializer);
    obj.initial_sequence_number = serde::Deserializable<decltype(obj.initial_sequence_number)>::deserialize(deserializer);
    obj.size = serde::Deserializable<decltype(obj.size)>::deserialize(deserializer);
    obj.previous_digest = serde::Deserializable<decltype(obj.previous_digest)>::deserialize(deserializer);
    obj.transactions_digest = serde::Deserializable<decltype(obj.transactions_digest)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const AuthorityPublicKeyBytes &lhs, const AuthorityPublicKeyBytes &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::AuthorityPublicKeyBytes>::serialize(const sui_types::AuthorityPublicKeyBytes &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::AuthorityPublicKeyBytes serde::Deserializable<sui_types::AuthorityPublicKeyBytes>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::AuthorityPublicKeyBytes obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const AuthoritySignInfo &lhs, const AuthoritySignInfo &rhs) {
        if (!(lhs.epoch == rhs.epoch)) { return false; }
        if (!(lhs.authority == rhs.authority)) { return false; }
        if (!(lhs.signature == rhs.signature)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::AuthoritySignInfo>::serialize(const sui_types::AuthoritySignInfo &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.epoch)>::serialize(obj.epoch, serializer);
    serde::Serializable<decltype(obj.authority)>::serialize(obj.authority, serializer);
    serde::Serializable<decltype(obj.signature)>::serialize(obj.signature, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::AuthoritySignInfo serde::Deserializable<sui_types::AuthoritySignInfo>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::AuthoritySignInfo obj;
    obj.epoch = serde::Deserializable<decltype(obj.epoch)>::deserialize(deserializer);
    obj.authority = serde::Deserializable<decltype(obj.authority)>::deserialize(deserializer);
    obj.signature = serde::Deserializable<decltype(obj.signature)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const Balance &lhs, const Balance &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Balance>::serialize(const sui_types::Balance &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Balance serde::Deserializable<sui_types::Balance>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Balance obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const CallArg &lhs, const CallArg &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CallArg>::serialize(const sui_types::CallArg &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::CallArg serde::Deserializable<sui_types::CallArg>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::CallArg obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const CallArg::Pure &lhs, const CallArg::Pure &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CallArg::Pure>::serialize(const sui_types::CallArg::Pure &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::CallArg::Pure serde::Deserializable<sui_types::CallArg::Pure>::deserialize(Deserializer &deserializer) {
    sui_types::CallArg::Pure obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const CallArg::Object &lhs, const CallArg::Object &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CallArg::Object>::serialize(const sui_types::CallArg::Object &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::CallArg::Object serde::Deserializable<sui_types::CallArg::Object>::deserialize(Deserializer &deserializer) {
    sui_types::CallArg::Object obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ChangeEpoch &lhs, const ChangeEpoch &rhs) {
        if (!(lhs.epoch == rhs.epoch)) { return false; }
        if (!(lhs.storage_charge == rhs.storage_charge)) { return false; }
        if (!(lhs.computation_charge == rhs.computation_charge)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ChangeEpoch>::serialize(const sui_types::ChangeEpoch &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.epoch)>::serialize(obj.epoch, serializer);
    serde::Serializable<decltype(obj.storage_charge)>::serialize(obj.storage_charge, serializer);
    serde::Serializable<decltype(obj.computation_charge)>::serialize(obj.computation_charge, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::ChangeEpoch serde::Deserializable<sui_types::ChangeEpoch>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ChangeEpoch obj;
    obj.epoch = serde::Deserializable<decltype(obj.epoch)>::deserialize(deserializer);
    obj.storage_charge = serde::Deserializable<decltype(obj.storage_charge)>::deserialize(deserializer);
    obj.computation_charge = serde::Deserializable<decltype(obj.computation_charge)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const CircularObjectOwnership &lhs, const CircularObjectOwnership &rhs) {
        if (!(lhs.object == rhs.object)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CircularObjectOwnership>::serialize(const sui_types::CircularObjectOwnership &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.object)>::serialize(obj.object, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::CircularObjectOwnership serde::Deserializable<sui_types::CircularObjectOwnership>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::CircularObjectOwnership obj;
    obj.object = serde::Deserializable<decltype(obj.object)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const Coin &lhs, const Coin &rhs) {
        if (!(lhs.id == rhs.id)) { return false; }
        if (!(lhs.balance == rhs.balance)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Coin>::serialize(const sui_types::Coin &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.id)>::serialize(obj.id, serializer);
    serde::Serializable<decltype(obj.balance)>::serialize(obj.balance, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Coin serde::Deserializable<sui_types::Coin>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Coin obj;
    obj.id = serde::Deserializable<decltype(obj.id)>::deserialize(deserializer);
    obj.balance = serde::Deserializable<decltype(obj.balance)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const Data &lhs, const Data &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Data>::serialize(const sui_types::Data &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Data serde::Deserializable<sui_types::Data>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Data obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const Data::Move &lhs, const Data::Move &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Data::Move>::serialize(const sui_types::Data::Move &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Data::Move serde::Deserializable<sui_types::Data::Move>::deserialize(Deserializer &deserializer) {
    sui_types::Data::Move obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const Data::Package &lhs, const Data::Package &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Data::Package>::serialize(const sui_types::Data::Package &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Data::Package serde::Deserializable<sui_types::Data::Package>::deserialize(Deserializer &deserializer) {
    sui_types::Data::Package obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const DeleteKind &lhs, const DeleteKind &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::DeleteKind>::serialize(const sui_types::DeleteKind &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::DeleteKind serde::Deserializable<sui_types::DeleteKind>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::DeleteKind obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const DeleteKind::Normal &lhs, const DeleteKind::Normal &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::DeleteKind::Normal>::serialize(const sui_types::DeleteKind::Normal &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::DeleteKind::Normal serde::Deserializable<sui_types::DeleteKind::Normal>::deserialize(Deserializer &deserializer) {
    sui_types::DeleteKind::Normal obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const DeleteKind::UnwrapThenDelete &lhs, const DeleteKind::UnwrapThenDelete &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::DeleteKind::UnwrapThenDelete>::serialize(const sui_types::DeleteKind::UnwrapThenDelete &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::DeleteKind::UnwrapThenDelete serde::Deserializable<sui_types::DeleteKind::UnwrapThenDelete>::deserialize(Deserializer &deserializer) {
    sui_types::DeleteKind::UnwrapThenDelete obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const DeleteKind::Wrap &lhs, const DeleteKind::Wrap &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::DeleteKind::Wrap>::serialize(const sui_types::DeleteKind::Wrap &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::DeleteKind::Wrap serde::Deserializable<sui_types::DeleteKind::Wrap>::deserialize(Deserializer &deserializer) {
    sui_types::DeleteKind::Wrap obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const Ed25519KeyPair &lhs, const Ed25519KeyPair &rhs) {
        if (!(lhs.type == rhs.type)) { return false; }
        if (!(lhs.name == rhs.name)) { return false; }
        if (!(lhs.secret == rhs.secret)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Ed25519KeyPair>::serialize(const sui_types::Ed25519KeyPair &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.type)>::serialize(obj.type, serializer);
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    serde::Serializable<decltype(obj.secret)>::serialize(obj.secret, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Ed25519KeyPair serde::Deserializable<sui_types::Ed25519KeyPair>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Ed25519KeyPair obj;
    obj.type = serde::Deserializable<decltype(obj.type)>::deserialize(deserializer);
    obj.name = serde::Deserializable<decltype(obj.name)>::deserialize(deserializer);
    obj.secret = serde::Deserializable<decltype(obj.secret)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const Ed25519PublicKey &lhs, const Ed25519PublicKey &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Ed25519PublicKey>::serialize(const sui_types::Ed25519PublicKey &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Ed25519PublicKey serde::Deserializable<sui_types::Ed25519PublicKey>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Ed25519PublicKey obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const Ed25519Signature &lhs, const Ed25519Signature &rhs) {
        if (!(lhs.raw == rhs.raw)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Ed25519Signature>::serialize(const sui_types::Ed25519Signature &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.raw)>::serialize(obj.raw, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Ed25519Signature serde::Deserializable<sui_types::Ed25519Signature>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Ed25519Signature obj;
    obj.raw = serde::Deserializable<decltype(obj.raw)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const Ed25519SuiSignature &lhs, const Ed25519SuiSignature &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Ed25519SuiSignature>::serialize(const sui_types::Ed25519SuiSignature &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Ed25519SuiSignature serde::Deserializable<sui_types::Ed25519SuiSignature>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Ed25519SuiSignature obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const EntryArgumentError &lhs, const EntryArgumentError &rhs) {
        if (!(lhs.argument_idx == rhs.argument_idx)) { return false; }
        if (!(lhs.kind == rhs.kind)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::EntryArgumentError>::serialize(const sui_types::EntryArgumentError &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.argument_idx)>::serialize(obj.argument_idx, serializer);
    serde::Serializable<decltype(obj.kind)>::serialize(obj.kind, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::EntryArgumentError serde::Deserializable<sui_types::EntryArgumentError>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::EntryArgumentError obj;
    obj.argument_idx = serde::Deserializable<decltype(obj.argument_idx)>::deserialize(deserializer);
    obj.kind = serde::Deserializable<decltype(obj.kind)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const EntryArgumentErrorKind &lhs, const EntryArgumentErrorKind &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::EntryArgumentErrorKind>::serialize(const sui_types::EntryArgumentErrorKind &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::EntryArgumentErrorKind serde::Deserializable<sui_types::EntryArgumentErrorKind>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::EntryArgumentErrorKind obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const EntryArgumentErrorKind::TypeMismatch &lhs, const EntryArgumentErrorKind::TypeMismatch &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::EntryArgumentErrorKind::TypeMismatch>::serialize(const sui_types::EntryArgumentErrorKind::TypeMismatch &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::EntryArgumentErrorKind::TypeMismatch serde::Deserializable<sui_types::EntryArgumentErrorKind::TypeMismatch>::deserialize(Deserializer &deserializer) {
    sui_types::EntryArgumentErrorKind::TypeMismatch obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const EntryArgumentErrorKind::InvalidObjectByValue &lhs, const EntryArgumentErrorKind::InvalidObjectByValue &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::EntryArgumentErrorKind::InvalidObjectByValue>::serialize(const sui_types::EntryArgumentErrorKind::InvalidObjectByValue &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::EntryArgumentErrorKind::InvalidObjectByValue serde::Deserializable<sui_types::EntryArgumentErrorKind::InvalidObjectByValue>::deserialize(Deserializer &deserializer) {
    sui_types::EntryArgumentErrorKind::InvalidObjectByValue obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const EntryArgumentErrorKind::InvalidObjectByMuteRef &lhs, const EntryArgumentErrorKind::InvalidObjectByMuteRef &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::EntryArgumentErrorKind::InvalidObjectByMuteRef>::serialize(const sui_types::EntryArgumentErrorKind::InvalidObjectByMuteRef &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::EntryArgumentErrorKind::InvalidObjectByMuteRef serde::Deserializable<sui_types::EntryArgumentErrorKind::InvalidObjectByMuteRef>::deserialize(Deserializer &deserializer) {
    sui_types::EntryArgumentErrorKind::InvalidObjectByMuteRef obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const EntryArgumentErrorKind::ObjectKindMismatch &lhs, const EntryArgumentErrorKind::ObjectKindMismatch &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::EntryArgumentErrorKind::ObjectKindMismatch>::serialize(const sui_types::EntryArgumentErrorKind::ObjectKindMismatch &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::EntryArgumentErrorKind::ObjectKindMismatch serde::Deserializable<sui_types::EntryArgumentErrorKind::ObjectKindMismatch>::deserialize(Deserializer &deserializer) {
    sui_types::EntryArgumentErrorKind::ObjectKindMismatch obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const EntryArgumentErrorKind::UnsupportedPureArg &lhs, const EntryArgumentErrorKind::UnsupportedPureArg &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::EntryArgumentErrorKind::UnsupportedPureArg>::serialize(const sui_types::EntryArgumentErrorKind::UnsupportedPureArg &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::EntryArgumentErrorKind::UnsupportedPureArg serde::Deserializable<sui_types::EntryArgumentErrorKind::UnsupportedPureArg>::deserialize(Deserializer &deserializer) {
    sui_types::EntryArgumentErrorKind::UnsupportedPureArg obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const EntryArgumentErrorKind::ArityMismatch &lhs, const EntryArgumentErrorKind::ArityMismatch &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::EntryArgumentErrorKind::ArityMismatch>::serialize(const sui_types::EntryArgumentErrorKind::ArityMismatch &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::EntryArgumentErrorKind::ArityMismatch serde::Deserializable<sui_types::EntryArgumentErrorKind::ArityMismatch>::deserialize(Deserializer &deserializer) {
    sui_types::EntryArgumentErrorKind::ArityMismatch obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const Envelope &lhs, const Envelope &rhs) {
        if (!(lhs.data == rhs.data)) { return false; }
        if (!(lhs.auth_signature == rhs.auth_signature)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Envelope>::serialize(const sui_types::Envelope &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.data)>::serialize(obj.data, serializer);
    serde::Serializable<decltype(obj.auth_signature)>::serialize(obj.auth_signature, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Envelope serde::Deserializable<sui_types::Envelope>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Envelope obj;
    obj.data = serde::Deserializable<decltype(obj.data)>::deserialize(deserializer);
    obj.auth_signature = serde::Deserializable<decltype(obj.auth_signature)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionDigests &lhs, const ExecutionDigests &rhs) {
        if (!(lhs.transaction == rhs.transaction)) { return false; }
        if (!(lhs.effects == rhs.effects)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionDigests>::serialize(const sui_types::ExecutionDigests &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.transaction)>::serialize(obj.transaction, serializer);
    serde::Serializable<decltype(obj.effects)>::serialize(obj.effects, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::ExecutionDigests serde::Deserializable<sui_types::ExecutionDigests>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ExecutionDigests obj;
    obj.transaction = serde::Deserializable<decltype(obj.transaction)>::deserialize(deserializer);
    obj.effects = serde::Deserializable<decltype(obj.effects)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus &lhs, const ExecutionFailureStatus &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus>::serialize(const sui_types::ExecutionFailureStatus &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus serde::Deserializable<sui_types::ExecutionFailureStatus>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ExecutionFailureStatus obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::InsufficientGas &lhs, const ExecutionFailureStatus::InsufficientGas &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InsufficientGas>::serialize(const sui_types::ExecutionFailureStatus::InsufficientGas &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InsufficientGas serde::Deserializable<sui_types::ExecutionFailureStatus::InsufficientGas>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InsufficientGas obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::InvalidGasObject &lhs, const ExecutionFailureStatus::InvalidGasObject &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InvalidGasObject>::serialize(const sui_types::ExecutionFailureStatus::InvalidGasObject &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InvalidGasObject serde::Deserializable<sui_types::ExecutionFailureStatus::InvalidGasObject>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InvalidGasObject obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::InvalidTransactionUpdate &lhs, const ExecutionFailureStatus::InvalidTransactionUpdate &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InvalidTransactionUpdate>::serialize(const sui_types::ExecutionFailureStatus::InvalidTransactionUpdate &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InvalidTransactionUpdate serde::Deserializable<sui_types::ExecutionFailureStatus::InvalidTransactionUpdate>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InvalidTransactionUpdate obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::ModuleNotFound &lhs, const ExecutionFailureStatus::ModuleNotFound &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::ModuleNotFound>::serialize(const sui_types::ExecutionFailureStatus::ModuleNotFound &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::ModuleNotFound serde::Deserializable<sui_types::ExecutionFailureStatus::ModuleNotFound>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::ModuleNotFound obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::FunctionNotFound &lhs, const ExecutionFailureStatus::FunctionNotFound &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::FunctionNotFound>::serialize(const sui_types::ExecutionFailureStatus::FunctionNotFound &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::FunctionNotFound serde::Deserializable<sui_types::ExecutionFailureStatus::FunctionNotFound>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::FunctionNotFound obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::InvariantViolation &lhs, const ExecutionFailureStatus::InvariantViolation &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InvariantViolation>::serialize(const sui_types::ExecutionFailureStatus::InvariantViolation &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InvariantViolation serde::Deserializable<sui_types::ExecutionFailureStatus::InvariantViolation>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InvariantViolation obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::InvalidTransferObject &lhs, const ExecutionFailureStatus::InvalidTransferObject &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InvalidTransferObject>::serialize(const sui_types::ExecutionFailureStatus::InvalidTransferObject &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InvalidTransferObject serde::Deserializable<sui_types::ExecutionFailureStatus::InvalidTransferObject>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InvalidTransferObject obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::InvalidTransferSui &lhs, const ExecutionFailureStatus::InvalidTransferSui &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InvalidTransferSui>::serialize(const sui_types::ExecutionFailureStatus::InvalidTransferSui &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InvalidTransferSui serde::Deserializable<sui_types::ExecutionFailureStatus::InvalidTransferSui>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InvalidTransferSui obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::InvalidTransferSuiInsufficientBalance &lhs, const ExecutionFailureStatus::InvalidTransferSuiInsufficientBalance &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InvalidTransferSuiInsufficientBalance>::serialize(const sui_types::ExecutionFailureStatus::InvalidTransferSuiInsufficientBalance &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InvalidTransferSuiInsufficientBalance serde::Deserializable<sui_types::ExecutionFailureStatus::InvalidTransferSuiInsufficientBalance>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InvalidTransferSuiInsufficientBalance obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::NonEntryFunctionInvoked &lhs, const ExecutionFailureStatus::NonEntryFunctionInvoked &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::NonEntryFunctionInvoked>::serialize(const sui_types::ExecutionFailureStatus::NonEntryFunctionInvoked &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::NonEntryFunctionInvoked serde::Deserializable<sui_types::ExecutionFailureStatus::NonEntryFunctionInvoked>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::NonEntryFunctionInvoked obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::EntryTypeArityMismatch &lhs, const ExecutionFailureStatus::EntryTypeArityMismatch &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::EntryTypeArityMismatch>::serialize(const sui_types::ExecutionFailureStatus::EntryTypeArityMismatch &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::EntryTypeArityMismatch serde::Deserializable<sui_types::ExecutionFailureStatus::EntryTypeArityMismatch>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::EntryTypeArityMismatch obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::EntryArgumentError &lhs, const ExecutionFailureStatus::EntryArgumentError &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::EntryArgumentError>::serialize(const sui_types::ExecutionFailureStatus::EntryArgumentError &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::EntryArgumentError serde::Deserializable<sui_types::ExecutionFailureStatus::EntryArgumentError>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::EntryArgumentError obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::CircularObjectOwnership &lhs, const ExecutionFailureStatus::CircularObjectOwnership &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::CircularObjectOwnership>::serialize(const sui_types::ExecutionFailureStatus::CircularObjectOwnership &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::CircularObjectOwnership serde::Deserializable<sui_types::ExecutionFailureStatus::CircularObjectOwnership>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::CircularObjectOwnership obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::MissingObjectOwner &lhs, const ExecutionFailureStatus::MissingObjectOwner &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::MissingObjectOwner>::serialize(const sui_types::ExecutionFailureStatus::MissingObjectOwner &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::MissingObjectOwner serde::Deserializable<sui_types::ExecutionFailureStatus::MissingObjectOwner>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::MissingObjectOwner obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::InvalidSharedChildUse &lhs, const ExecutionFailureStatus::InvalidSharedChildUse &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InvalidSharedChildUse>::serialize(const sui_types::ExecutionFailureStatus::InvalidSharedChildUse &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InvalidSharedChildUse serde::Deserializable<sui_types::ExecutionFailureStatus::InvalidSharedChildUse>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InvalidSharedChildUse obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::InvalidSharedByValue &lhs, const ExecutionFailureStatus::InvalidSharedByValue &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InvalidSharedByValue>::serialize(const sui_types::ExecutionFailureStatus::InvalidSharedByValue &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InvalidSharedByValue serde::Deserializable<sui_types::ExecutionFailureStatus::InvalidSharedByValue>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InvalidSharedByValue obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::TooManyChildObjects &lhs, const ExecutionFailureStatus::TooManyChildObjects &rhs) {
        if (!(lhs.object == rhs.object)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::TooManyChildObjects>::serialize(const sui_types::ExecutionFailureStatus::TooManyChildObjects &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.object)>::serialize(obj.object, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::TooManyChildObjects serde::Deserializable<sui_types::ExecutionFailureStatus::TooManyChildObjects>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::TooManyChildObjects obj;
    obj.object = serde::Deserializable<decltype(obj.object)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::InvalidParentDeletion &lhs, const ExecutionFailureStatus::InvalidParentDeletion &rhs) {
        if (!(lhs.parent == rhs.parent)) { return false; }
        if (!(lhs.kind == rhs.kind)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InvalidParentDeletion>::serialize(const sui_types::ExecutionFailureStatus::InvalidParentDeletion &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.parent)>::serialize(obj.parent, serializer);
    serde::Serializable<decltype(obj.kind)>::serialize(obj.kind, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InvalidParentDeletion serde::Deserializable<sui_types::ExecutionFailureStatus::InvalidParentDeletion>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InvalidParentDeletion obj;
    obj.parent = serde::Deserializable<decltype(obj.parent)>::deserialize(deserializer);
    obj.kind = serde::Deserializable<decltype(obj.kind)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::InvalidParentFreezing &lhs, const ExecutionFailureStatus::InvalidParentFreezing &rhs) {
        if (!(lhs.parent == rhs.parent)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InvalidParentFreezing>::serialize(const sui_types::ExecutionFailureStatus::InvalidParentFreezing &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.parent)>::serialize(obj.parent, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InvalidParentFreezing serde::Deserializable<sui_types::ExecutionFailureStatus::InvalidParentFreezing>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InvalidParentFreezing obj;
    obj.parent = serde::Deserializable<decltype(obj.parent)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::PublishErrorEmptyPackage &lhs, const ExecutionFailureStatus::PublishErrorEmptyPackage &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::PublishErrorEmptyPackage>::serialize(const sui_types::ExecutionFailureStatus::PublishErrorEmptyPackage &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::PublishErrorEmptyPackage serde::Deserializable<sui_types::ExecutionFailureStatus::PublishErrorEmptyPackage>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::PublishErrorEmptyPackage obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::PublishErrorNonZeroAddress &lhs, const ExecutionFailureStatus::PublishErrorNonZeroAddress &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::PublishErrorNonZeroAddress>::serialize(const sui_types::ExecutionFailureStatus::PublishErrorNonZeroAddress &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::PublishErrorNonZeroAddress serde::Deserializable<sui_types::ExecutionFailureStatus::PublishErrorNonZeroAddress>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::PublishErrorNonZeroAddress obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::PublishErrorDuplicateModule &lhs, const ExecutionFailureStatus::PublishErrorDuplicateModule &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::PublishErrorDuplicateModule>::serialize(const sui_types::ExecutionFailureStatus::PublishErrorDuplicateModule &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::PublishErrorDuplicateModule serde::Deserializable<sui_types::ExecutionFailureStatus::PublishErrorDuplicateModule>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::PublishErrorDuplicateModule obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::SuiMoveVerificationError &lhs, const ExecutionFailureStatus::SuiMoveVerificationError &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::SuiMoveVerificationError>::serialize(const sui_types::ExecutionFailureStatus::SuiMoveVerificationError &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::SuiMoveVerificationError serde::Deserializable<sui_types::ExecutionFailureStatus::SuiMoveVerificationError>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::SuiMoveVerificationError obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::MovePrimitiveRuntimeError &lhs, const ExecutionFailureStatus::MovePrimitiveRuntimeError &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::MovePrimitiveRuntimeError>::serialize(const sui_types::ExecutionFailureStatus::MovePrimitiveRuntimeError &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::MovePrimitiveRuntimeError serde::Deserializable<sui_types::ExecutionFailureStatus::MovePrimitiveRuntimeError>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::MovePrimitiveRuntimeError obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::MoveAbort &lhs, const ExecutionFailureStatus::MoveAbort &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::MoveAbort>::serialize(const sui_types::ExecutionFailureStatus::MoveAbort &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::MoveAbort serde::Deserializable<sui_types::ExecutionFailureStatus::MoveAbort>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::MoveAbort obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::VMVerificationOrDeserializationError &lhs, const ExecutionFailureStatus::VMVerificationOrDeserializationError &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::VMVerificationOrDeserializationError>::serialize(const sui_types::ExecutionFailureStatus::VMVerificationOrDeserializationError &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::VMVerificationOrDeserializationError serde::Deserializable<sui_types::ExecutionFailureStatus::VMVerificationOrDeserializationError>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::VMVerificationOrDeserializationError obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::VMInvariantViolation &lhs, const ExecutionFailureStatus::VMInvariantViolation &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::VMInvariantViolation>::serialize(const sui_types::ExecutionFailureStatus::VMInvariantViolation &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::VMInvariantViolation serde::Deserializable<sui_types::ExecutionFailureStatus::VMInvariantViolation>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::VMInvariantViolation obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionStatus &lhs, const ExecutionStatus &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionStatus>::serialize(const sui_types::ExecutionStatus &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::ExecutionStatus serde::Deserializable<sui_types::ExecutionStatus>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ExecutionStatus obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionStatus::Success &lhs, const ExecutionStatus::Success &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionStatus::Success>::serialize(const sui_types::ExecutionStatus::Success &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionStatus::Success serde::Deserializable<sui_types::ExecutionStatus::Success>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionStatus::Success obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionStatus::Failure &lhs, const ExecutionStatus::Failure &rhs) {
        if (!(lhs.error == rhs.error)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionStatus::Failure>::serialize(const sui_types::ExecutionStatus::Failure &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.error)>::serialize(obj.error, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionStatus::Failure serde::Deserializable<sui_types::ExecutionStatus::Failure>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionStatus::Failure obj;
    obj.error = serde::Deserializable<decltype(obj.error)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const Id &lhs, const Id &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Id>::serialize(const sui_types::Id &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Id serde::Deserializable<sui_types::Id>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Id obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const Identifier &lhs, const Identifier &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Identifier>::serialize(const sui_types::Identifier &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Identifier serde::Deserializable<sui_types::Identifier>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Identifier obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const InvalidSharedByValue &lhs, const InvalidSharedByValue &rhs) {
        if (!(lhs.object == rhs.object)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::InvalidSharedByValue>::serialize(const sui_types::InvalidSharedByValue &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.object)>::serialize(obj.object, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::InvalidSharedByValue serde::Deserializable<sui_types::InvalidSharedByValue>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::InvalidSharedByValue obj;
    obj.object = serde::Deserializable<decltype(obj.object)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const InvalidSharedChildUse &lhs, const InvalidSharedChildUse &rhs) {
        if (!(lhs.child == rhs.child)) { return false; }
        if (!(lhs.ancestor == rhs.ancestor)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::InvalidSharedChildUse>::serialize(const sui_types::InvalidSharedChildUse &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.child)>::serialize(obj.child, serializer);
    serde::Serializable<decltype(obj.ancestor)>::serialize(obj.ancestor, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::InvalidSharedChildUse serde::Deserializable<sui_types::InvalidSharedChildUse>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::InvalidSharedChildUse obj;
    obj.child = serde::Deserializable<decltype(obj.child)>::deserialize(deserializer);
    obj.ancestor = serde::Deserializable<decltype(obj.ancestor)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const MissingObjectOwner &lhs, const MissingObjectOwner &rhs) {
        if (!(lhs.child == rhs.child)) { return false; }
        if (!(lhs.parent == rhs.parent)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MissingObjectOwner>::serialize(const sui_types::MissingObjectOwner &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.child)>::serialize(obj.child, serializer);
    serde::Serializable<decltype(obj.parent)>::serialize(obj.parent, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::MissingObjectOwner serde::Deserializable<sui_types::MissingObjectOwner>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::MissingObjectOwner obj;
    obj.child = serde::Deserializable<decltype(obj.child)>::deserialize(deserializer);
    obj.parent = serde::Deserializable<decltype(obj.parent)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const ModuleId &lhs, const ModuleId &rhs) {
        if (!(lhs.address == rhs.address)) { return false; }
        if (!(lhs.name == rhs.name)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ModuleId>::serialize(const sui_types::ModuleId &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.address)>::serialize(obj.address, serializer);
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::ModuleId serde::Deserializable<sui_types::ModuleId>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ModuleId obj;
    obj.address = serde::Deserializable<decltype(obj.address)>::deserialize(deserializer);
    obj.name = serde::Deserializable<decltype(obj.name)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveCall &lhs, const MoveCall &rhs) {
        if (!(lhs.package == rhs.package)) { return false; }
        if (!(lhs.module == rhs.module)) { return false; }
        if (!(lhs.function == rhs.function)) { return false; }
        if (!(lhs.type_arguments == rhs.type_arguments)) { return false; }
        if (!(lhs.arguments == rhs.arguments)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveCall>::serialize(const sui_types::MoveCall &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.package)>::serialize(obj.package, serializer);
    serde::Serializable<decltype(obj.module)>::serialize(obj.module, serializer);
    serde::Serializable<decltype(obj.function)>::serialize(obj.function, serializer);
    serde::Serializable<decltype(obj.type_arguments)>::serialize(obj.type_arguments, serializer);
    serde::Serializable<decltype(obj.arguments)>::serialize(obj.arguments, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::MoveCall serde::Deserializable<sui_types::MoveCall>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::MoveCall obj;
    obj.package = serde::Deserializable<decltype(obj.package)>::deserialize(deserializer);
    obj.module = serde::Deserializable<decltype(obj.module)>::deserialize(deserializer);
    obj.function = serde::Deserializable<decltype(obj.function)>::deserialize(deserializer);
    obj.type_arguments = serde::Deserializable<decltype(obj.type_arguments)>::deserialize(deserializer);
    obj.arguments = serde::Deserializable<decltype(obj.arguments)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveFieldLayout &lhs, const MoveFieldLayout &rhs) {
        if (!(lhs.name == rhs.name)) { return false; }
        if (!(lhs.layout == rhs.layout)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveFieldLayout>::serialize(const sui_types::MoveFieldLayout &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    serde::Serializable<decltype(obj.layout)>::serialize(obj.layout, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::MoveFieldLayout serde::Deserializable<sui_types::MoveFieldLayout>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::MoveFieldLayout obj;
    obj.name = serde::Deserializable<decltype(obj.name)>::deserialize(deserializer);
    obj.layout = serde::Deserializable<decltype(obj.layout)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveModulePublish &lhs, const MoveModulePublish &rhs) {
        if (!(lhs.modules == rhs.modules)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveModulePublish>::serialize(const sui_types::MoveModulePublish &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.modules)>::serialize(obj.modules, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::MoveModulePublish serde::Deserializable<sui_types::MoveModulePublish>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::MoveModulePublish obj;
    obj.modules = serde::Deserializable<decltype(obj.modules)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveObject &lhs, const MoveObject &rhs) {
        if (!(lhs.type_ == rhs.type_)) { return false; }
        if (!(lhs.has_public_transfer == rhs.has_public_transfer)) { return false; }
        if (!(lhs.version == rhs.version)) { return false; }
        if (!(lhs.child_count == rhs.child_count)) { return false; }
        if (!(lhs.contents == rhs.contents)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveObject>::serialize(const sui_types::MoveObject &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.type_)>::serialize(obj.type_, serializer);
    serde::Serializable<decltype(obj.has_public_transfer)>::serialize(obj.has_public_transfer, serializer);
    serde::Serializable<decltype(obj.version)>::serialize(obj.version, serializer);
    serde::Serializable<decltype(obj.child_count)>::serialize(obj.child_count, serializer);
    serde::Serializable<decltype(obj.contents)>::serialize(obj.contents, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::MoveObject serde::Deserializable<sui_types::MoveObject>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::MoveObject obj;
    obj.type_ = serde::Deserializable<decltype(obj.type_)>::deserialize(deserializer);
    obj.has_public_transfer = serde::Deserializable<decltype(obj.has_public_transfer)>::deserialize(deserializer);
    obj.version = serde::Deserializable<decltype(obj.version)>::deserialize(deserializer);
    obj.child_count = serde::Deserializable<decltype(obj.child_count)>::deserialize(deserializer);
    obj.contents = serde::Deserializable<decltype(obj.contents)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const MovePackage &lhs, const MovePackage &rhs) {
        if (!(lhs.id == rhs.id)) { return false; }
        if (!(lhs.module_map == rhs.module_map)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MovePackage>::serialize(const sui_types::MovePackage &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.id)>::serialize(obj.id, serializer);
    serde::Serializable<decltype(obj.module_map)>::serialize(obj.module_map, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::MovePackage serde::Deserializable<sui_types::MovePackage>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::MovePackage obj;
    obj.id = serde::Deserializable<decltype(obj.id)>::deserialize(deserializer);
    obj.module_map = serde::Deserializable<decltype(obj.module_map)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveStructLayout &lhs, const MoveStructLayout &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveStructLayout>::serialize(const sui_types::MoveStructLayout &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::MoveStructLayout serde::Deserializable<sui_types::MoveStructLayout>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::MoveStructLayout obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveStructLayout::Runtime &lhs, const MoveStructLayout::Runtime &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveStructLayout::Runtime>::serialize(const sui_types::MoveStructLayout::Runtime &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::MoveStructLayout::Runtime serde::Deserializable<sui_types::MoveStructLayout::Runtime>::deserialize(Deserializer &deserializer) {
    sui_types::MoveStructLayout::Runtime obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveStructLayout::WithFields &lhs, const MoveStructLayout::WithFields &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveStructLayout::WithFields>::serialize(const sui_types::MoveStructLayout::WithFields &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::MoveStructLayout::WithFields serde::Deserializable<sui_types::MoveStructLayout::WithFields>::deserialize(Deserializer &deserializer) {
    sui_types::MoveStructLayout::WithFields obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveStructLayout::WithTypes &lhs, const MoveStructLayout::WithTypes &rhs) {
        if (!(lhs.type_ == rhs.type_)) { return false; }
        if (!(lhs.fields == rhs.fields)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveStructLayout::WithTypes>::serialize(const sui_types::MoveStructLayout::WithTypes &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.type_)>::serialize(obj.type_, serializer);
    serde::Serializable<decltype(obj.fields)>::serialize(obj.fields, serializer);
}

template <>
template <typename Deserializer>
sui_types::MoveStructLayout::WithTypes serde::Deserializable<sui_types::MoveStructLayout::WithTypes>::deserialize(Deserializer &deserializer) {
    sui_types::MoveStructLayout::WithTypes obj;
    obj.type_ = serde::Deserializable<decltype(obj.type_)>::deserialize(deserializer);
    obj.fields = serde::Deserializable<decltype(obj.fields)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveTypeLayout &lhs, const MoveTypeLayout &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveTypeLayout>::serialize(const sui_types::MoveTypeLayout &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::MoveTypeLayout serde::Deserializable<sui_types::MoveTypeLayout>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::MoveTypeLayout obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveTypeLayout::Bool &lhs, const MoveTypeLayout::Bool &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveTypeLayout::Bool>::serialize(const sui_types::MoveTypeLayout::Bool &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::MoveTypeLayout::Bool serde::Deserializable<sui_types::MoveTypeLayout::Bool>::deserialize(Deserializer &deserializer) {
    sui_types::MoveTypeLayout::Bool obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveTypeLayout::U8 &lhs, const MoveTypeLayout::U8 &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveTypeLayout::U8>::serialize(const sui_types::MoveTypeLayout::U8 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::MoveTypeLayout::U8 serde::Deserializable<sui_types::MoveTypeLayout::U8>::deserialize(Deserializer &deserializer) {
    sui_types::MoveTypeLayout::U8 obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveTypeLayout::U64 &lhs, const MoveTypeLayout::U64 &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveTypeLayout::U64>::serialize(const sui_types::MoveTypeLayout::U64 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::MoveTypeLayout::U64 serde::Deserializable<sui_types::MoveTypeLayout::U64>::deserialize(Deserializer &deserializer) {
    sui_types::MoveTypeLayout::U64 obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveTypeLayout::U128 &lhs, const MoveTypeLayout::U128 &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveTypeLayout::U128>::serialize(const sui_types::MoveTypeLayout::U128 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::MoveTypeLayout::U128 serde::Deserializable<sui_types::MoveTypeLayout::U128>::deserialize(Deserializer &deserializer) {
    sui_types::MoveTypeLayout::U128 obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveTypeLayout::address &lhs, const MoveTypeLayout::address &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveTypeLayout::address>::serialize(const sui_types::MoveTypeLayout::address &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::MoveTypeLayout::address serde::Deserializable<sui_types::MoveTypeLayout::address>::deserialize(Deserializer &deserializer) {
    sui_types::MoveTypeLayout::address obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveTypeLayout::Vector &lhs, const MoveTypeLayout::Vector &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveTypeLayout::Vector>::serialize(const sui_types::MoveTypeLayout::Vector &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::MoveTypeLayout::Vector serde::Deserializable<sui_types::MoveTypeLayout::Vector>::deserialize(Deserializer &deserializer) {
    sui_types::MoveTypeLayout::Vector obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveTypeLayout::Struct &lhs, const MoveTypeLayout::Struct &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveTypeLayout::Struct>::serialize(const sui_types::MoveTypeLayout::Struct &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::MoveTypeLayout::Struct serde::Deserializable<sui_types::MoveTypeLayout::Struct>::deserialize(Deserializer &deserializer) {
    sui_types::MoveTypeLayout::Struct obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveTypeLayout::signer &lhs, const MoveTypeLayout::signer &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveTypeLayout::signer>::serialize(const sui_types::MoveTypeLayout::signer &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::MoveTypeLayout::signer serde::Deserializable<sui_types::MoveTypeLayout::signer>::deserialize(Deserializer &deserializer) {
    sui_types::MoveTypeLayout::signer obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ObjectArg &lhs, const ObjectArg &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ObjectArg>::serialize(const sui_types::ObjectArg &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::ObjectArg serde::Deserializable<sui_types::ObjectArg>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ObjectArg obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const ObjectArg::ImmOrOwnedObject &lhs, const ObjectArg::ImmOrOwnedObject &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ObjectArg::ImmOrOwnedObject>::serialize(const sui_types::ObjectArg::ImmOrOwnedObject &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::ObjectArg::ImmOrOwnedObject serde::Deserializable<sui_types::ObjectArg::ImmOrOwnedObject>::deserialize(Deserializer &deserializer) {
    sui_types::ObjectArg::ImmOrOwnedObject obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ObjectArg::SharedObject &lhs, const ObjectArg::SharedObject &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ObjectArg::SharedObject>::serialize(const sui_types::ObjectArg::SharedObject &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::ObjectArg::SharedObject serde::Deserializable<sui_types::ObjectArg::SharedObject>::deserialize(Deserializer &deserializer) {
    sui_types::ObjectArg::SharedObject obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ObjectDigest &lhs, const ObjectDigest &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ObjectDigest>::serialize(const sui_types::ObjectDigest &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::ObjectDigest serde::Deserializable<sui_types::ObjectDigest>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ObjectDigest obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const ObjectFormatOptions &lhs, const ObjectFormatOptions &rhs) {
        if (!(lhs.include_types == rhs.include_types)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ObjectFormatOptions>::serialize(const sui_types::ObjectFormatOptions &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.include_types)>::serialize(obj.include_types, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::ObjectFormatOptions serde::Deserializable<sui_types::ObjectFormatOptions>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ObjectFormatOptions obj;
    obj.include_types = serde::Deserializable<decltype(obj.include_types)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const ObjectID &lhs, const ObjectID &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ObjectID>::serialize(const sui_types::ObjectID &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::ObjectID serde::Deserializable<sui_types::ObjectID>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ObjectID obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const ObjectInfoRequestKind &lhs, const ObjectInfoRequestKind &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ObjectInfoRequestKind>::serialize(const sui_types::ObjectInfoRequestKind &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::ObjectInfoRequestKind serde::Deserializable<sui_types::ObjectInfoRequestKind>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ObjectInfoRequestKind obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const ObjectInfoRequestKind::LatestObjectInfo &lhs, const ObjectInfoRequestKind::LatestObjectInfo &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ObjectInfoRequestKind::LatestObjectInfo>::serialize(const sui_types::ObjectInfoRequestKind::LatestObjectInfo &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::ObjectInfoRequestKind::LatestObjectInfo serde::Deserializable<sui_types::ObjectInfoRequestKind::LatestObjectInfo>::deserialize(Deserializer &deserializer) {
    sui_types::ObjectInfoRequestKind::LatestObjectInfo obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ObjectInfoRequestKind::PastObjectInfo &lhs, const ObjectInfoRequestKind::PastObjectInfo &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ObjectInfoRequestKind::PastObjectInfo>::serialize(const sui_types::ObjectInfoRequestKind::PastObjectInfo &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::ObjectInfoRequestKind::PastObjectInfo serde::Deserializable<sui_types::ObjectInfoRequestKind::PastObjectInfo>::deserialize(Deserializer &deserializer) {
    sui_types::ObjectInfoRequestKind::PastObjectInfo obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const Owner &lhs, const Owner &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Owner>::serialize(const sui_types::Owner &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Owner serde::Deserializable<sui_types::Owner>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Owner obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const Owner::AddressOwner &lhs, const Owner::AddressOwner &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Owner::AddressOwner>::serialize(const sui_types::Owner::AddressOwner &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Owner::AddressOwner serde::Deserializable<sui_types::Owner::AddressOwner>::deserialize(Deserializer &deserializer) {
    sui_types::Owner::AddressOwner obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const Owner::ObjectOwner &lhs, const Owner::ObjectOwner &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Owner::ObjectOwner>::serialize(const sui_types::Owner::ObjectOwner &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Owner::ObjectOwner serde::Deserializable<sui_types::Owner::ObjectOwner>::deserialize(Deserializer &deserializer) {
    sui_types::Owner::ObjectOwner obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const Owner::Shared &lhs, const Owner::Shared &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Owner::Shared>::serialize(const sui_types::Owner::Shared &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::Owner::Shared serde::Deserializable<sui_types::Owner::Shared>::deserialize(Deserializer &deserializer) {
    sui_types::Owner::Shared obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const Owner::Immutable &lhs, const Owner::Immutable &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Owner::Immutable>::serialize(const sui_types::Owner::Immutable &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::Owner::Immutable serde::Deserializable<sui_types::Owner::Immutable>::deserialize(Deserializer &deserializer) {
    sui_types::Owner::Immutable obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const Secp256k1SuiSignature &lhs, const Secp256k1SuiSignature &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Secp256k1SuiSignature>::serialize(const sui_types::Secp256k1SuiSignature &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Secp256k1SuiSignature serde::Deserializable<sui_types::Secp256k1SuiSignature>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Secp256k1SuiSignature obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const SenderSignedData &lhs, const SenderSignedData &rhs) {
        if (!(lhs.data == rhs.data)) { return false; }
        if (!(lhs.tx_signature == rhs.tx_signature)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::SenderSignedData>::serialize(const sui_types::SenderSignedData &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.data)>::serialize(obj.data, serializer);
    serde::Serializable<decltype(obj.tx_signature)>::serialize(obj.tx_signature, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::SenderSignedData serde::Deserializable<sui_types::SenderSignedData>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::SenderSignedData obj;
    obj.data = serde::Deserializable<decltype(obj.data)>::deserialize(deserializer);
    obj.tx_signature = serde::Deserializable<decltype(obj.tx_signature)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const SequenceNumber &lhs, const SequenceNumber &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::SequenceNumber>::serialize(const sui_types::SequenceNumber &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::SequenceNumber serde::Deserializable<sui_types::SequenceNumber>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::SequenceNumber obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const Signature &lhs, const Signature &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Signature>::serialize(const sui_types::Signature &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Signature serde::Deserializable<sui_types::Signature>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Signature obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const Signature::Ed25519Signature &lhs, const Signature::Ed25519Signature &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Signature::Ed25519Signature>::serialize(const sui_types::Signature::Ed25519Signature &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Signature::Ed25519Signature serde::Deserializable<sui_types::Signature::Ed25519Signature>::deserialize(Deserializer &deserializer) {
    sui_types::Signature::Ed25519Signature obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const Signature::Secp256k1SuiSignature &lhs, const Signature::Secp256k1SuiSignature &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Signature::Secp256k1SuiSignature>::serialize(const sui_types::Signature::Secp256k1SuiSignature &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Signature::Secp256k1SuiSignature serde::Deserializable<sui_types::Signature::Secp256k1SuiSignature>::deserialize(Deserializer &deserializer) {
    sui_types::Signature::Secp256k1SuiSignature obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const SingleTransactionKind &lhs, const SingleTransactionKind &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::SingleTransactionKind>::serialize(const sui_types::SingleTransactionKind &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::SingleTransactionKind serde::Deserializable<sui_types::SingleTransactionKind>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::SingleTransactionKind obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const SingleTransactionKind::TransferObject &lhs, const SingleTransactionKind::TransferObject &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::SingleTransactionKind::TransferObject>::serialize(const sui_types::SingleTransactionKind::TransferObject &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::SingleTransactionKind::TransferObject serde::Deserializable<sui_types::SingleTransactionKind::TransferObject>::deserialize(Deserializer &deserializer) {
    sui_types::SingleTransactionKind::TransferObject obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const SingleTransactionKind::Publish &lhs, const SingleTransactionKind::Publish &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::SingleTransactionKind::Publish>::serialize(const sui_types::SingleTransactionKind::Publish &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::SingleTransactionKind::Publish serde::Deserializable<sui_types::SingleTransactionKind::Publish>::deserialize(Deserializer &deserializer) {
    sui_types::SingleTransactionKind::Publish obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const SingleTransactionKind::Call &lhs, const SingleTransactionKind::Call &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::SingleTransactionKind::Call>::serialize(const sui_types::SingleTransactionKind::Call &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::SingleTransactionKind::Call serde::Deserializable<sui_types::SingleTransactionKind::Call>::deserialize(Deserializer &deserializer) {
    sui_types::SingleTransactionKind::Call obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const SingleTransactionKind::TransferSui &lhs, const SingleTransactionKind::TransferSui &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::SingleTransactionKind::TransferSui>::serialize(const sui_types::SingleTransactionKind::TransferSui &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::SingleTransactionKind::TransferSui serde::Deserializable<sui_types::SingleTransactionKind::TransferSui>::deserialize(Deserializer &deserializer) {
    sui_types::SingleTransactionKind::TransferSui obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const SingleTransactionKind::ChangeEpoch &lhs, const SingleTransactionKind::ChangeEpoch &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::SingleTransactionKind::ChangeEpoch>::serialize(const sui_types::SingleTransactionKind::ChangeEpoch &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::SingleTransactionKind::ChangeEpoch serde::Deserializable<sui_types::SingleTransactionKind::ChangeEpoch>::deserialize(Deserializer &deserializer) {
    sui_types::SingleTransactionKind::ChangeEpoch obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const StructTag &lhs, const StructTag &rhs) {
        if (!(lhs.address == rhs.address)) { return false; }
        if (!(lhs.module == rhs.module)) { return false; }
        if (!(lhs.name == rhs.name)) { return false; }
        if (!(lhs.type_args == rhs.type_args)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::StructTag>::serialize(const sui_types::StructTag &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.address)>::serialize(obj.address, serializer);
    serde::Serializable<decltype(obj.module)>::serialize(obj.module, serializer);
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    serde::Serializable<decltype(obj.type_args)>::serialize(obj.type_args, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::StructTag serde::Deserializable<sui_types::StructTag>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::StructTag obj;
    obj.address = serde::Deserializable<decltype(obj.address)>::deserialize(deserializer);
    obj.module = serde::Deserializable<decltype(obj.module)>::deserialize(deserializer);
    obj.name = serde::Deserializable<decltype(obj.name)>::deserialize(deserializer);
    obj.type_args = serde::Deserializable<decltype(obj.type_args)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const SuiAddress &lhs, const SuiAddress &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::SuiAddress>::serialize(const sui_types::SuiAddress &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::SuiAddress serde::Deserializable<sui_types::SuiAddress>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::SuiAddress obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransactionData &lhs, const TransactionData &rhs) {
        if (!(lhs.kind == rhs.kind)) { return false; }
        if (!(lhs.sender == rhs.sender)) { return false; }
        if (!(lhs.gas_payment == rhs.gas_payment)) { return false; }
        if (!(lhs.gas_price == rhs.gas_price)) { return false; }
        if (!(lhs.gas_budget == rhs.gas_budget)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionData>::serialize(const sui_types::TransactionData &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.kind)>::serialize(obj.kind, serializer);
    serde::Serializable<decltype(obj.sender)>::serialize(obj.sender, serializer);
    serde::Serializable<decltype(obj.gas_payment)>::serialize(obj.gas_payment, serializer);
    serde::Serializable<decltype(obj.gas_price)>::serialize(obj.gas_price, serializer);
    serde::Serializable<decltype(obj.gas_budget)>::serialize(obj.gas_budget, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::TransactionData serde::Deserializable<sui_types::TransactionData>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::TransactionData obj;
    obj.kind = serde::Deserializable<decltype(obj.kind)>::deserialize(deserializer);
    obj.sender = serde::Deserializable<decltype(obj.sender)>::deserialize(deserializer);
    obj.gas_payment = serde::Deserializable<decltype(obj.gas_payment)>::deserialize(deserializer);
    obj.gas_price = serde::Deserializable<decltype(obj.gas_price)>::deserialize(deserializer);
    obj.gas_budget = serde::Deserializable<decltype(obj.gas_budget)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransactionDigest &lhs, const TransactionDigest &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionDigest>::serialize(const sui_types::TransactionDigest &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::TransactionDigest serde::Deserializable<sui_types::TransactionDigest>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::TransactionDigest obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransactionEffectsDigest &lhs, const TransactionEffectsDigest &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionEffectsDigest>::serialize(const sui_types::TransactionEffectsDigest &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::TransactionEffectsDigest serde::Deserializable<sui_types::TransactionEffectsDigest>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::TransactionEffectsDigest obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransactionKind &lhs, const TransactionKind &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionKind>::serialize(const sui_types::TransactionKind &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::TransactionKind serde::Deserializable<sui_types::TransactionKind>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::TransactionKind obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransactionKind::Single &lhs, const TransactionKind::Single &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionKind::Single>::serialize(const sui_types::TransactionKind::Single &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::TransactionKind::Single serde::Deserializable<sui_types::TransactionKind::Single>::deserialize(Deserializer &deserializer) {
    sui_types::TransactionKind::Single obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransactionKind::Batch &lhs, const TransactionKind::Batch &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionKind::Batch>::serialize(const sui_types::TransactionKind::Batch &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::TransactionKind::Batch serde::Deserializable<sui_types::TransactionKind::Batch>::deserialize(Deserializer &deserializer) {
    sui_types::TransactionKind::Batch obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransferObject &lhs, const TransferObject &rhs) {
        if (!(lhs.recipient == rhs.recipient)) { return false; }
        if (!(lhs.object_ref == rhs.object_ref)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransferObject>::serialize(const sui_types::TransferObject &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.recipient)>::serialize(obj.recipient, serializer);
    serde::Serializable<decltype(obj.object_ref)>::serialize(obj.object_ref, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::TransferObject serde::Deserializable<sui_types::TransferObject>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::TransferObject obj;
    obj.recipient = serde::Deserializable<decltype(obj.recipient)>::deserialize(deserializer);
    obj.object_ref = serde::Deserializable<decltype(obj.object_ref)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransferSui &lhs, const TransferSui &rhs) {
        if (!(lhs.recipient == rhs.recipient)) { return false; }
        if (!(lhs.amount == rhs.amount)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransferSui>::serialize(const sui_types::TransferSui &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.recipient)>::serialize(obj.recipient, serializer);
    serde::Serializable<decltype(obj.amount)>::serialize(obj.amount, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::TransferSui serde::Deserializable<sui_types::TransferSui>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::TransferSui obj;
    obj.recipient = serde::Deserializable<decltype(obj.recipient)>::deserialize(deserializer);
    obj.amount = serde::Deserializable<decltype(obj.amount)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypeTag &lhs, const TypeTag &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeTag>::serialize(const sui_types::TypeTag &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::TypeTag serde::Deserializable<sui_types::TypeTag>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::TypeTag obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypeTag::Bool &lhs, const TypeTag::Bool &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeTag::Bool>::serialize(const sui_types::TypeTag::Bool &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TypeTag::Bool serde::Deserializable<sui_types::TypeTag::Bool>::deserialize(Deserializer &deserializer) {
    sui_types::TypeTag::Bool obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypeTag::U8 &lhs, const TypeTag::U8 &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeTag::U8>::serialize(const sui_types::TypeTag::U8 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TypeTag::U8 serde::Deserializable<sui_types::TypeTag::U8>::deserialize(Deserializer &deserializer) {
    sui_types::TypeTag::U8 obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypeTag::U64 &lhs, const TypeTag::U64 &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeTag::U64>::serialize(const sui_types::TypeTag::U64 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TypeTag::U64 serde::Deserializable<sui_types::TypeTag::U64>::deserialize(Deserializer &deserializer) {
    sui_types::TypeTag::U64 obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypeTag::U128 &lhs, const TypeTag::U128 &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeTag::U128>::serialize(const sui_types::TypeTag::U128 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TypeTag::U128 serde::Deserializable<sui_types::TypeTag::U128>::deserialize(Deserializer &deserializer) {
    sui_types::TypeTag::U128 obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypeTag::address &lhs, const TypeTag::address &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeTag::address>::serialize(const sui_types::TypeTag::address &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TypeTag::address serde::Deserializable<sui_types::TypeTag::address>::deserialize(Deserializer &deserializer) {
    sui_types::TypeTag::address obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypeTag::signer &lhs, const TypeTag::signer &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeTag::signer>::serialize(const sui_types::TypeTag::signer &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TypeTag::signer serde::Deserializable<sui_types::TypeTag::signer>::deserialize(Deserializer &deserializer) {
    sui_types::TypeTag::signer obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypeTag::Vector &lhs, const TypeTag::Vector &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeTag::Vector>::serialize(const sui_types::TypeTag::Vector &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::TypeTag::Vector serde::Deserializable<sui_types::TypeTag::Vector>::deserialize(Deserializer &deserializer) {
    sui_types::TypeTag::Vector obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypeTag::Struct &lhs, const TypeTag::Struct &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeTag::Struct>::serialize(const sui_types::TypeTag::Struct &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::TypeTag::Struct serde::Deserializable<sui_types::TypeTag::Struct>::deserialize(Deserializer &deserializer) {
    sui_types::TypeTag::Struct obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypedStoreError &lhs, const TypedStoreError &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypedStoreError>::serialize(const sui_types::TypedStoreError &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::TypedStoreError serde::Deserializable<sui_types::TypedStoreError>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::TypedStoreError obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypedStoreError::RocksDBError &lhs, const TypedStoreError::RocksDBError &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypedStoreError::RocksDBError>::serialize(const sui_types::TypedStoreError::RocksDBError &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::TypedStoreError::RocksDBError serde::Deserializable<sui_types::TypedStoreError::RocksDBError>::deserialize(Deserializer &deserializer) {
    sui_types::TypedStoreError::RocksDBError obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypedStoreError::SerializationError &lhs, const TypedStoreError::SerializationError &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypedStoreError::SerializationError>::serialize(const sui_types::TypedStoreError::SerializationError &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::TypedStoreError::SerializationError serde::Deserializable<sui_types::TypedStoreError::SerializationError>::deserialize(Deserializer &deserializer) {
    sui_types::TypedStoreError::SerializationError obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypedStoreError::UnregisteredColumn &lhs, const TypedStoreError::UnregisteredColumn &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypedStoreError::UnregisteredColumn>::serialize(const sui_types::TypedStoreError::UnregisteredColumn &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::TypedStoreError::UnregisteredColumn serde::Deserializable<sui_types::TypedStoreError::UnregisteredColumn>::deserialize(Deserializer &deserializer) {
    sui_types::TypedStoreError::UnregisteredColumn obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypedStoreError::CrossDBBatch &lhs, const TypedStoreError::CrossDBBatch &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypedStoreError::CrossDBBatch>::serialize(const sui_types::TypedStoreError::CrossDBBatch &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TypedStoreError::CrossDBBatch serde::Deserializable<sui_types::TypedStoreError::CrossDBBatch>::deserialize(Deserializer &deserializer) {
    sui_types::TypedStoreError::CrossDBBatch obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const UID &lhs, const UID &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::UID>::serialize(const sui_types::UID &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::UID serde::Deserializable<sui_types::UID>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::UID obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const UpdateItem &lhs, const UpdateItem &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::UpdateItem>::serialize(const sui_types::UpdateItem &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::UpdateItem serde::Deserializable<sui_types::UpdateItem>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::UpdateItem obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const UpdateItem::Transaction &lhs, const UpdateItem::Transaction &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::UpdateItem::Transaction>::serialize(const sui_types::UpdateItem::Transaction &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::UpdateItem::Transaction serde::Deserializable<sui_types::UpdateItem::Transaction>::deserialize(Deserializer &deserializer) {
    sui_types::UpdateItem::Transaction obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const UpdateItem::Batch &lhs, const UpdateItem::Batch &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::UpdateItem::Batch>::serialize(const sui_types::UpdateItem::Batch &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::UpdateItem::Batch serde::Deserializable<sui_types::UpdateItem::Batch>::deserialize(Deserializer &deserializer) {
    sui_types::UpdateItem::Batch obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}
