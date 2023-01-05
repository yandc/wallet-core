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

    struct EntryTypeArgumentErrorKind {

        struct ModuleNotFound {
            friend bool operator==(const ModuleNotFound&, const ModuleNotFound&);
        };

        struct TypeNotFound {
            friend bool operator==(const TypeNotFound&, const TypeNotFound&);
        };

        struct ArityMismatch {
            friend bool operator==(const ArityMismatch&, const ArityMismatch&);
        };

        struct ConstraintNotSatisfied {
            friend bool operator==(const ConstraintNotSatisfied&, const ConstraintNotSatisfied&);
        };

        std::variant<ModuleNotFound, TypeNotFound, ArityMismatch, ConstraintNotSatisfied> value;

        friend bool operator==(const EntryTypeArgumentErrorKind&, const EntryTypeArgumentErrorKind&);
    };

    struct EntryTypeArgumentError {
        uint16_t argument_idx;
        sui_types::EntryTypeArgumentErrorKind kind;

        friend bool operator==(const EntryTypeArgumentError&, const EntryTypeArgumentError&);
    };

    struct SuiAddress {
        std::array<uint8_t, 20> value;

        friend bool operator==(const SuiAddress&, const SuiAddress&);
    };

    struct InvalidChildObjectArgument {
        sui_types::ObjectID child;
        sui_types::SuiAddress parent;

        friend bool operator==(const InvalidChildObjectArgument&, const InvalidChildObjectArgument&);
    };

    struct InvalidSharedByValue {
        sui_types::ObjectID object;

        friend bool operator==(const InvalidSharedByValue&, const InvalidSharedByValue&);
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

    struct MoveLocation {
        sui_types::ModuleId module;
        uint16_t function;
        uint16_t instruction;

        friend bool operator==(const MoveLocation&, const MoveLocation&);
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

        struct MoveObjectTooBig {
            uint64_t object_size;
            uint64_t max_object_size;

            friend bool operator==(const MoveObjectTooBig&, const MoveObjectTooBig&);
        };

        struct MovePackageTooBig {
            uint64_t object_size;
            uint64_t max_object_size;

            friend bool operator==(const MovePackageTooBig&, const MovePackageTooBig&);
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

        struct InvalidCoinObject {
            friend bool operator==(const InvalidCoinObject&, const InvalidCoinObject&);
        };

        struct EmptyInputCoins {
            friend bool operator==(const EmptyInputCoins&, const EmptyInputCoins&);
        };

        struct EmptyRecipients {
            friend bool operator==(const EmptyRecipients&, const EmptyRecipients&);
        };

        struct RecipientsAmountsArityMismatch {
            friend bool operator==(const RecipientsAmountsArityMismatch&, const RecipientsAmountsArityMismatch&);
        };

        struct InsufficientBalance {
            friend bool operator==(const InsufficientBalance&, const InsufficientBalance&);
        };

        struct CoinTypeMismatch {
            friend bool operator==(const CoinTypeMismatch&, const CoinTypeMismatch&);
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

        struct EntryTypeArgumentError {
            sui_types::EntryTypeArgumentError value;

            friend bool operator==(const EntryTypeArgumentError&, const EntryTypeArgumentError&);
        };

        struct CircularObjectOwnership {
            sui_types::CircularObjectOwnership value;

            friend bool operator==(const CircularObjectOwnership&, const CircularObjectOwnership&);
        };

        struct InvalidChildObjectArgument {
            sui_types::InvalidChildObjectArgument value;

            friend bool operator==(const InvalidChildObjectArgument&, const InvalidChildObjectArgument&);
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
            std::optional<sui_types::MoveLocation> value;

            friend bool operator==(const MovePrimitiveRuntimeError&, const MovePrimitiveRuntimeError&);
        };

        struct MoveAbort {
            std::tuple<sui_types::MoveLocation, uint64_t> value;

            friend bool operator==(const MoveAbort&, const MoveAbort&);
        };

        struct VMVerificationOrDeserializationError {
            friend bool operator==(const VMVerificationOrDeserializationError&, const VMVerificationOrDeserializationError&);
        };

        struct VMInvariantViolation {
            friend bool operator==(const VMInvariantViolation&, const VMInvariantViolation&);
        };

        std::variant<InsufficientGas, InvalidGasObject, InvalidTransactionUpdate, ModuleNotFound, FunctionNotFound, InvariantViolation, MoveObjectTooBig, MovePackageTooBig, InvalidTransferObject, InvalidTransferSui, InvalidTransferSuiInsufficientBalance, InvalidCoinObject, EmptyInputCoins, EmptyRecipients, RecipientsAmountsArityMismatch, InsufficientBalance, CoinTypeMismatch, NonEntryFunctionInvoked, EntryTypeArityMismatch, EntryArgumentError, EntryTypeArgumentError, CircularObjectOwnership, InvalidChildObjectArgument, InvalidSharedByValue, TooManyChildObjects, InvalidParentDeletion, InvalidParentFreezing, PublishErrorEmptyPackage, PublishErrorNonZeroAddress, PublishErrorDuplicateModule, SuiMoveVerificationError, MovePrimitiveRuntimeError, MoveAbort, VMVerificationOrDeserializationError, VMInvariantViolation> value;

        friend bool operator==(const ExecutionFailureStatus&, const ExecutionFailureStatus&);
    };

    struct ChangeEpoch {
        uint64_t epoch;
        uint64_t storage_charge;
        uint64_t computation_charge;
        uint64_t storage_rebate;

        friend bool operator==(const ChangeEpoch&, const ChangeEpoch&);
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
            sui_types::ObjectID id;
            sui_types::SequenceNumber initial_shared_version;

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

        struct ObjVec {
            std::vector<sui_types::ObjectArg> value;

            friend bool operator==(const ObjVec&, const ObjVec&);
        };

        std::variant<Pure, Object, ObjVec> value;

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

        struct U16 {
            friend bool operator==(const U16&, const U16&);
        };

        struct U32 {
            friend bool operator==(const U32&, const U32&);
        };

        struct U256 {
            friend bool operator==(const U256&, const U256&);
        };

        std::variant<Bool, U8, U64, U128, address, signer, Vector, Struct, U16, U32, U256> value;

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

    struct MoveModulePublish {
        std::vector<std::vector<uint8_t>> modules;

        friend bool operator==(const MoveModulePublish&, const MoveModulePublish&);
    };

    struct Pay {
        std::vector<std::tuple<sui_types::ObjectID, sui_types::SequenceNumber, sui_types::ObjectDigest>> coins;
        std::vector<sui_types::SuiAddress> recipients;
        std::vector<uint64_t> amounts;

        friend bool operator==(const Pay&, const Pay&);
    };

    struct PayAllSui {
        std::vector<std::tuple<sui_types::ObjectID, sui_types::SequenceNumber, sui_types::ObjectDigest>> coins;
        sui_types::SuiAddress recipient;

        friend bool operator==(const PayAllSui&, const PayAllSui&);
    };

    struct PaySui {
        std::vector<std::tuple<sui_types::ObjectID, sui_types::SequenceNumber, sui_types::ObjectDigest>> coins;
        std::vector<sui_types::SuiAddress> recipients;
        std::vector<uint64_t> amounts;

        friend bool operator==(const PaySui&, const PaySui&);
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

        struct Pay {
            sui_types::Pay value;

            friend bool operator==(const Pay&, const Pay&);
        };

        struct PaySui {
            sui_types::PaySui value;

            friend bool operator==(const PaySui&, const PaySui&);
        };

        struct PayAllSui {
            sui_types::PayAllSui value;

            friend bool operator==(const PayAllSui&, const PayAllSui&);
        };

        struct ChangeEpoch {
            sui_types::ChangeEpoch value;

            friend bool operator==(const ChangeEpoch&, const ChangeEpoch&);
        };

        std::variant<TransferObject, Publish, Call, TransferSui, Pay, PaySui, PayAllSui, ChangeEpoch> value;

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

        struct U16 {
            friend bool operator==(const U16&, const U16&);
        };

        struct U32 {
            friend bool operator==(const U32&, const U32&);
        };

        struct U256 {
            friend bool operator==(const U256&, const U256&);
        };

        std::variant<Bool, U8, U64, U128, address, Vector, Struct, signer, U16, U32, U256> value;

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

    struct MoveObject {
        sui_types::StructTag type_;
        bool has_public_transfer;
        sui_types::SequenceNumber version;
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

        struct PastObjectInfoDebug {
            std::tuple<sui_types::SequenceNumber, std::optional<sui_types::ObjectFormatOptions>> value;

            friend bool operator==(const PastObjectInfoDebug&, const PastObjectInfoDebug&);
        };

        std::variant<LatestObjectInfo, PastObjectInfo, PastObjectInfoDebug> value;

        friend bool operator==(const ObjectInfoRequestKind&, const ObjectInfoRequestKind&);
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
            sui_types::SequenceNumber initial_shared_version;

            friend bool operator==(const Shared&, const Shared&);
        };

        struct Immutable {
            friend bool operator==(const Immutable&, const Immutable&);
        };

        std::variant<AddressOwner, ObjectOwner, Shared, Immutable> value;

        friend bool operator==(const Owner&, const Owner&);
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

    struct AuthorityPublicKeyBytes {
        std::vector<uint8_t> value;

        friend bool operator==(const AuthorityPublicKeyBytes&, const AuthorityPublicKeyBytes&);
    };

    struct BLS12381KeyPair {
        std::string name;
        std::string secret;

        friend bool operator==(const BLS12381KeyPair&, const BLS12381KeyPair&);
    };

    struct BLS12381Signature {
        std::vector<uint8_t> sig;

        friend bool operator==(const BLS12381Signature&, const BLS12381Signature&);
    };

    struct Ed25519KeyPair {
        std::string name;
        std::string secret;

        friend bool operator==(const Ed25519KeyPair&, const Ed25519KeyPair&);
    };

    struct TransactionDigest {
        std::vector<uint8_t> value;

        friend bool operator==(const TransactionDigest&, const TransactionDigest&);
    };

    struct TransactionEffectsDigest {
        std::vector<uint8_t> value;

        friend bool operator==(const TransactionEffectsDigest&, const TransactionEffectsDigest&);
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

        struct MetricsReporting {
            friend bool operator==(const MetricsReporting&, const MetricsReporting&);
        };

        std::variant<RocksDBError, SerializationError, UnregisteredColumn, CrossDBBatch, MetricsReporting> value;

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

    inline bool operator==(const BLS12381KeyPair &lhs, const BLS12381KeyPair &rhs) {
        if (!(lhs.name == rhs.name)) { return false; }
        if (!(lhs.secret == rhs.secret)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::BLS12381KeyPair>::serialize(const sui_types::BLS12381KeyPair &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    serde::Serializable<decltype(obj.secret)>::serialize(obj.secret, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::BLS12381KeyPair serde::Deserializable<sui_types::BLS12381KeyPair>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::BLS12381KeyPair obj;
    obj.name = serde::Deserializable<decltype(obj.name)>::deserialize(deserializer);
    obj.secret = serde::Deserializable<decltype(obj.secret)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const BLS12381Signature &lhs, const BLS12381Signature &rhs) {
        if (!(lhs.sig == rhs.sig)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::BLS12381Signature>::serialize(const sui_types::BLS12381Signature &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.sig)>::serialize(obj.sig, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::BLS12381Signature serde::Deserializable<sui_types::BLS12381Signature>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::BLS12381Signature obj;
    obj.sig = serde::Deserializable<decltype(obj.sig)>::deserialize(deserializer);
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

    inline bool operator==(const CallArg::ObjVec &lhs, const CallArg::ObjVec &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CallArg::ObjVec>::serialize(const sui_types::CallArg::ObjVec &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::CallArg::ObjVec serde::Deserializable<sui_types::CallArg::ObjVec>::deserialize(Deserializer &deserializer) {
    sui_types::CallArg::ObjVec obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ChangeEpoch &lhs, const ChangeEpoch &rhs) {
        if (!(lhs.epoch == rhs.epoch)) { return false; }
        if (!(lhs.storage_charge == rhs.storage_charge)) { return false; }
        if (!(lhs.computation_charge == rhs.computation_charge)) { return false; }
        if (!(lhs.storage_rebate == rhs.storage_rebate)) { return false; }
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
    serde::Serializable<decltype(obj.storage_rebate)>::serialize(obj.storage_rebate, serializer);
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
    obj.storage_rebate = serde::Deserializable<decltype(obj.storage_rebate)>::deserialize(deserializer);
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
        if (!(lhs.name == rhs.name)) { return false; }
        if (!(lhs.secret == rhs.secret)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Ed25519KeyPair>::serialize(const sui_types::Ed25519KeyPair &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    serde::Serializable<decltype(obj.secret)>::serialize(obj.secret, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Ed25519KeyPair serde::Deserializable<sui_types::Ed25519KeyPair>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Ed25519KeyPair obj;
    obj.name = serde::Deserializable<decltype(obj.name)>::deserialize(deserializer);
    obj.secret = serde::Deserializable<decltype(obj.secret)>::deserialize(deserializer);
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

    inline bool operator==(const EntryTypeArgumentError &lhs, const EntryTypeArgumentError &rhs) {
        if (!(lhs.argument_idx == rhs.argument_idx)) { return false; }
        if (!(lhs.kind == rhs.kind)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::EntryTypeArgumentError>::serialize(const sui_types::EntryTypeArgumentError &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.argument_idx)>::serialize(obj.argument_idx, serializer);
    serde::Serializable<decltype(obj.kind)>::serialize(obj.kind, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::EntryTypeArgumentError serde::Deserializable<sui_types::EntryTypeArgumentError>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::EntryTypeArgumentError obj;
    obj.argument_idx = serde::Deserializable<decltype(obj.argument_idx)>::deserialize(deserializer);
    obj.kind = serde::Deserializable<decltype(obj.kind)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const EntryTypeArgumentErrorKind &lhs, const EntryTypeArgumentErrorKind &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::EntryTypeArgumentErrorKind>::serialize(const sui_types::EntryTypeArgumentErrorKind &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::EntryTypeArgumentErrorKind serde::Deserializable<sui_types::EntryTypeArgumentErrorKind>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::EntryTypeArgumentErrorKind obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const EntryTypeArgumentErrorKind::ModuleNotFound &lhs, const EntryTypeArgumentErrorKind::ModuleNotFound &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::EntryTypeArgumentErrorKind::ModuleNotFound>::serialize(const sui_types::EntryTypeArgumentErrorKind::ModuleNotFound &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::EntryTypeArgumentErrorKind::ModuleNotFound serde::Deserializable<sui_types::EntryTypeArgumentErrorKind::ModuleNotFound>::deserialize(Deserializer &deserializer) {
    sui_types::EntryTypeArgumentErrorKind::ModuleNotFound obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const EntryTypeArgumentErrorKind::TypeNotFound &lhs, const EntryTypeArgumentErrorKind::TypeNotFound &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::EntryTypeArgumentErrorKind::TypeNotFound>::serialize(const sui_types::EntryTypeArgumentErrorKind::TypeNotFound &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::EntryTypeArgumentErrorKind::TypeNotFound serde::Deserializable<sui_types::EntryTypeArgumentErrorKind::TypeNotFound>::deserialize(Deserializer &deserializer) {
    sui_types::EntryTypeArgumentErrorKind::TypeNotFound obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const EntryTypeArgumentErrorKind::ArityMismatch &lhs, const EntryTypeArgumentErrorKind::ArityMismatch &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::EntryTypeArgumentErrorKind::ArityMismatch>::serialize(const sui_types::EntryTypeArgumentErrorKind::ArityMismatch &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::EntryTypeArgumentErrorKind::ArityMismatch serde::Deserializable<sui_types::EntryTypeArgumentErrorKind::ArityMismatch>::deserialize(Deserializer &deserializer) {
    sui_types::EntryTypeArgumentErrorKind::ArityMismatch obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const EntryTypeArgumentErrorKind::ConstraintNotSatisfied &lhs, const EntryTypeArgumentErrorKind::ConstraintNotSatisfied &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::EntryTypeArgumentErrorKind::ConstraintNotSatisfied>::serialize(const sui_types::EntryTypeArgumentErrorKind::ConstraintNotSatisfied &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::EntryTypeArgumentErrorKind::ConstraintNotSatisfied serde::Deserializable<sui_types::EntryTypeArgumentErrorKind::ConstraintNotSatisfied>::deserialize(Deserializer &deserializer) {
    sui_types::EntryTypeArgumentErrorKind::ConstraintNotSatisfied obj;
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

    inline bool operator==(const ExecutionFailureStatus::MoveObjectTooBig &lhs, const ExecutionFailureStatus::MoveObjectTooBig &rhs) {
        if (!(lhs.object_size == rhs.object_size)) { return false; }
        if (!(lhs.max_object_size == rhs.max_object_size)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::MoveObjectTooBig>::serialize(const sui_types::ExecutionFailureStatus::MoveObjectTooBig &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.object_size)>::serialize(obj.object_size, serializer);
    serde::Serializable<decltype(obj.max_object_size)>::serialize(obj.max_object_size, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::MoveObjectTooBig serde::Deserializable<sui_types::ExecutionFailureStatus::MoveObjectTooBig>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::MoveObjectTooBig obj;
    obj.object_size = serde::Deserializable<decltype(obj.object_size)>::deserialize(deserializer);
    obj.max_object_size = serde::Deserializable<decltype(obj.max_object_size)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::MovePackageTooBig &lhs, const ExecutionFailureStatus::MovePackageTooBig &rhs) {
        if (!(lhs.object_size == rhs.object_size)) { return false; }
        if (!(lhs.max_object_size == rhs.max_object_size)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::MovePackageTooBig>::serialize(const sui_types::ExecutionFailureStatus::MovePackageTooBig &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.object_size)>::serialize(obj.object_size, serializer);
    serde::Serializable<decltype(obj.max_object_size)>::serialize(obj.max_object_size, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::MovePackageTooBig serde::Deserializable<sui_types::ExecutionFailureStatus::MovePackageTooBig>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::MovePackageTooBig obj;
    obj.object_size = serde::Deserializable<decltype(obj.object_size)>::deserialize(deserializer);
    obj.max_object_size = serde::Deserializable<decltype(obj.max_object_size)>::deserialize(deserializer);
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

    inline bool operator==(const ExecutionFailureStatus::InvalidCoinObject &lhs, const ExecutionFailureStatus::InvalidCoinObject &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InvalidCoinObject>::serialize(const sui_types::ExecutionFailureStatus::InvalidCoinObject &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InvalidCoinObject serde::Deserializable<sui_types::ExecutionFailureStatus::InvalidCoinObject>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InvalidCoinObject obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::EmptyInputCoins &lhs, const ExecutionFailureStatus::EmptyInputCoins &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::EmptyInputCoins>::serialize(const sui_types::ExecutionFailureStatus::EmptyInputCoins &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::EmptyInputCoins serde::Deserializable<sui_types::ExecutionFailureStatus::EmptyInputCoins>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::EmptyInputCoins obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::EmptyRecipients &lhs, const ExecutionFailureStatus::EmptyRecipients &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::EmptyRecipients>::serialize(const sui_types::ExecutionFailureStatus::EmptyRecipients &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::EmptyRecipients serde::Deserializable<sui_types::ExecutionFailureStatus::EmptyRecipients>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::EmptyRecipients obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::RecipientsAmountsArityMismatch &lhs, const ExecutionFailureStatus::RecipientsAmountsArityMismatch &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::RecipientsAmountsArityMismatch>::serialize(const sui_types::ExecutionFailureStatus::RecipientsAmountsArityMismatch &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::RecipientsAmountsArityMismatch serde::Deserializable<sui_types::ExecutionFailureStatus::RecipientsAmountsArityMismatch>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::RecipientsAmountsArityMismatch obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::InsufficientBalance &lhs, const ExecutionFailureStatus::InsufficientBalance &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InsufficientBalance>::serialize(const sui_types::ExecutionFailureStatus::InsufficientBalance &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InsufficientBalance serde::Deserializable<sui_types::ExecutionFailureStatus::InsufficientBalance>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InsufficientBalance obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::CoinTypeMismatch &lhs, const ExecutionFailureStatus::CoinTypeMismatch &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::CoinTypeMismatch>::serialize(const sui_types::ExecutionFailureStatus::CoinTypeMismatch &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::CoinTypeMismatch serde::Deserializable<sui_types::ExecutionFailureStatus::CoinTypeMismatch>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::CoinTypeMismatch obj;
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

    inline bool operator==(const ExecutionFailureStatus::EntryTypeArgumentError &lhs, const ExecutionFailureStatus::EntryTypeArgumentError &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::EntryTypeArgumentError>::serialize(const sui_types::ExecutionFailureStatus::EntryTypeArgumentError &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::EntryTypeArgumentError serde::Deserializable<sui_types::ExecutionFailureStatus::EntryTypeArgumentError>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::EntryTypeArgumentError obj;
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

    inline bool operator==(const ExecutionFailureStatus::InvalidChildObjectArgument &lhs, const ExecutionFailureStatus::InvalidChildObjectArgument &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InvalidChildObjectArgument>::serialize(const sui_types::ExecutionFailureStatus::InvalidChildObjectArgument &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InvalidChildObjectArgument serde::Deserializable<sui_types::ExecutionFailureStatus::InvalidChildObjectArgument>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InvalidChildObjectArgument obj;
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
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::MovePrimitiveRuntimeError>::serialize(const sui_types::ExecutionFailureStatus::MovePrimitiveRuntimeError &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::MovePrimitiveRuntimeError serde::Deserializable<sui_types::ExecutionFailureStatus::MovePrimitiveRuntimeError>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::MovePrimitiveRuntimeError obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
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

    inline bool operator==(const InvalidChildObjectArgument &lhs, const InvalidChildObjectArgument &rhs) {
        if (!(lhs.child == rhs.child)) { return false; }
        if (!(lhs.parent == rhs.parent)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::InvalidChildObjectArgument>::serialize(const sui_types::InvalidChildObjectArgument &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.child)>::serialize(obj.child, serializer);
    serde::Serializable<decltype(obj.parent)>::serialize(obj.parent, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::InvalidChildObjectArgument serde::Deserializable<sui_types::InvalidChildObjectArgument>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::InvalidChildObjectArgument obj;
    obj.child = serde::Deserializable<decltype(obj.child)>::deserialize(deserializer);
    obj.parent = serde::Deserializable<decltype(obj.parent)>::deserialize(deserializer);
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

    inline bool operator==(const MoveLocation &lhs, const MoveLocation &rhs) {
        if (!(lhs.module == rhs.module)) { return false; }
        if (!(lhs.function == rhs.function)) { return false; }
        if (!(lhs.instruction == rhs.instruction)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveLocation>::serialize(const sui_types::MoveLocation &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.module)>::serialize(obj.module, serializer);
    serde::Serializable<decltype(obj.function)>::serialize(obj.function, serializer);
    serde::Serializable<decltype(obj.instruction)>::serialize(obj.instruction, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::MoveLocation serde::Deserializable<sui_types::MoveLocation>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::MoveLocation obj;
    obj.module = serde::Deserializable<decltype(obj.module)>::deserialize(deserializer);
    obj.function = serde::Deserializable<decltype(obj.function)>::deserialize(deserializer);
    obj.instruction = serde::Deserializable<decltype(obj.instruction)>::deserialize(deserializer);
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

    inline bool operator==(const MoveTypeLayout::U16 &lhs, const MoveTypeLayout::U16 &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveTypeLayout::U16>::serialize(const sui_types::MoveTypeLayout::U16 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::MoveTypeLayout::U16 serde::Deserializable<sui_types::MoveTypeLayout::U16>::deserialize(Deserializer &deserializer) {
    sui_types::MoveTypeLayout::U16 obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveTypeLayout::U32 &lhs, const MoveTypeLayout::U32 &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveTypeLayout::U32>::serialize(const sui_types::MoveTypeLayout::U32 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::MoveTypeLayout::U32 serde::Deserializable<sui_types::MoveTypeLayout::U32>::deserialize(Deserializer &deserializer) {
    sui_types::MoveTypeLayout::U32 obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveTypeLayout::U256 &lhs, const MoveTypeLayout::U256 &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveTypeLayout::U256>::serialize(const sui_types::MoveTypeLayout::U256 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::MoveTypeLayout::U256 serde::Deserializable<sui_types::MoveTypeLayout::U256>::deserialize(Deserializer &deserializer) {
    sui_types::MoveTypeLayout::U256 obj;
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
        if (!(lhs.id == rhs.id)) { return false; }
        if (!(lhs.initial_shared_version == rhs.initial_shared_version)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ObjectArg::SharedObject>::serialize(const sui_types::ObjectArg::SharedObject &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.id)>::serialize(obj.id, serializer);
    serde::Serializable<decltype(obj.initial_shared_version)>::serialize(obj.initial_shared_version, serializer);
}

template <>
template <typename Deserializer>
sui_types::ObjectArg::SharedObject serde::Deserializable<sui_types::ObjectArg::SharedObject>::deserialize(Deserializer &deserializer) {
    sui_types::ObjectArg::SharedObject obj;
    obj.id = serde::Deserializable<decltype(obj.id)>::deserialize(deserializer);
    obj.initial_shared_version = serde::Deserializable<decltype(obj.initial_shared_version)>::deserialize(deserializer);
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

    inline bool operator==(const ObjectInfoRequestKind::PastObjectInfoDebug &lhs, const ObjectInfoRequestKind::PastObjectInfoDebug &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ObjectInfoRequestKind::PastObjectInfoDebug>::serialize(const sui_types::ObjectInfoRequestKind::PastObjectInfoDebug &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::ObjectInfoRequestKind::PastObjectInfoDebug serde::Deserializable<sui_types::ObjectInfoRequestKind::PastObjectInfoDebug>::deserialize(Deserializer &deserializer) {
    sui_types::ObjectInfoRequestKind::PastObjectInfoDebug obj;
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
        if (!(lhs.initial_shared_version == rhs.initial_shared_version)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Owner::Shared>::serialize(const sui_types::Owner::Shared &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.initial_shared_version)>::serialize(obj.initial_shared_version, serializer);
}

template <>
template <typename Deserializer>
sui_types::Owner::Shared serde::Deserializable<sui_types::Owner::Shared>::deserialize(Deserializer &deserializer) {
    sui_types::Owner::Shared obj;
    obj.initial_shared_version = serde::Deserializable<decltype(obj.initial_shared_version)>::deserialize(deserializer);
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

    inline bool operator==(const Pay &lhs, const Pay &rhs) {
        if (!(lhs.coins == rhs.coins)) { return false; }
        if (!(lhs.recipients == rhs.recipients)) { return false; }
        if (!(lhs.amounts == rhs.amounts)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Pay>::serialize(const sui_types::Pay &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.coins)>::serialize(obj.coins, serializer);
    serde::Serializable<decltype(obj.recipients)>::serialize(obj.recipients, serializer);
    serde::Serializable<decltype(obj.amounts)>::serialize(obj.amounts, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Pay serde::Deserializable<sui_types::Pay>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Pay obj;
    obj.coins = serde::Deserializable<decltype(obj.coins)>::deserialize(deserializer);
    obj.recipients = serde::Deserializable<decltype(obj.recipients)>::deserialize(deserializer);
    obj.amounts = serde::Deserializable<decltype(obj.amounts)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const PayAllSui &lhs, const PayAllSui &rhs) {
        if (!(lhs.coins == rhs.coins)) { return false; }
        if (!(lhs.recipient == rhs.recipient)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::PayAllSui>::serialize(const sui_types::PayAllSui &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.coins)>::serialize(obj.coins, serializer);
    serde::Serializable<decltype(obj.recipient)>::serialize(obj.recipient, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::PayAllSui serde::Deserializable<sui_types::PayAllSui>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::PayAllSui obj;
    obj.coins = serde::Deserializable<decltype(obj.coins)>::deserialize(deserializer);
    obj.recipient = serde::Deserializable<decltype(obj.recipient)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const PaySui &lhs, const PaySui &rhs) {
        if (!(lhs.coins == rhs.coins)) { return false; }
        if (!(lhs.recipients == rhs.recipients)) { return false; }
        if (!(lhs.amounts == rhs.amounts)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::PaySui>::serialize(const sui_types::PaySui &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.coins)>::serialize(obj.coins, serializer);
    serde::Serializable<decltype(obj.recipients)>::serialize(obj.recipients, serializer);
    serde::Serializable<decltype(obj.amounts)>::serialize(obj.amounts, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::PaySui serde::Deserializable<sui_types::PaySui>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::PaySui obj;
    obj.coins = serde::Deserializable<decltype(obj.coins)>::deserialize(deserializer);
    obj.recipients = serde::Deserializable<decltype(obj.recipients)>::deserialize(deserializer);
    obj.amounts = serde::Deserializable<decltype(obj.amounts)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
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

    inline bool operator==(const SingleTransactionKind::Pay &lhs, const SingleTransactionKind::Pay &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::SingleTransactionKind::Pay>::serialize(const sui_types::SingleTransactionKind::Pay &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::SingleTransactionKind::Pay serde::Deserializable<sui_types::SingleTransactionKind::Pay>::deserialize(Deserializer &deserializer) {
    sui_types::SingleTransactionKind::Pay obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const SingleTransactionKind::PaySui &lhs, const SingleTransactionKind::PaySui &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::SingleTransactionKind::PaySui>::serialize(const sui_types::SingleTransactionKind::PaySui &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::SingleTransactionKind::PaySui serde::Deserializable<sui_types::SingleTransactionKind::PaySui>::deserialize(Deserializer &deserializer) {
    sui_types::SingleTransactionKind::PaySui obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const SingleTransactionKind::PayAllSui &lhs, const SingleTransactionKind::PayAllSui &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::SingleTransactionKind::PayAllSui>::serialize(const sui_types::SingleTransactionKind::PayAllSui &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::SingleTransactionKind::PayAllSui serde::Deserializable<sui_types::SingleTransactionKind::PayAllSui>::deserialize(Deserializer &deserializer) {
    sui_types::SingleTransactionKind::PayAllSui obj;
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

    inline bool operator==(const TypeTag::U16 &lhs, const TypeTag::U16 &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeTag::U16>::serialize(const sui_types::TypeTag::U16 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TypeTag::U16 serde::Deserializable<sui_types::TypeTag::U16>::deserialize(Deserializer &deserializer) {
    sui_types::TypeTag::U16 obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypeTag::U32 &lhs, const TypeTag::U32 &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeTag::U32>::serialize(const sui_types::TypeTag::U32 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TypeTag::U32 serde::Deserializable<sui_types::TypeTag::U32>::deserialize(Deserializer &deserializer) {
    sui_types::TypeTag::U32 obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypeTag::U256 &lhs, const TypeTag::U256 &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeTag::U256>::serialize(const sui_types::TypeTag::U256 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TypeTag::U256 serde::Deserializable<sui_types::TypeTag::U256>::deserialize(Deserializer &deserializer) {
    sui_types::TypeTag::U256 obj;
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

    inline bool operator==(const TypedStoreError::MetricsReporting &lhs, const TypedStoreError::MetricsReporting &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypedStoreError::MetricsReporting>::serialize(const sui_types::TypedStoreError::MetricsReporting &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TypedStoreError::MetricsReporting serde::Deserializable<sui_types::TypedStoreError::MetricsReporting>::deserialize(Deserializer &deserializer) {
    sui_types::TypedStoreError::MetricsReporting obj;
    return obj;
}
