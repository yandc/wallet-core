#pragma once

#include "serde.hpp"

namespace sui_types {

    struct CommandArgumentError {

        struct TypeMismatch {
            friend bool operator==(const TypeMismatch&, const TypeMismatch&);
        };

        struct InvalidBCSBytes {
            friend bool operator==(const InvalidBCSBytes&, const InvalidBCSBytes&);
        };

        struct InvalidUsageOfPureArg {
            friend bool operator==(const InvalidUsageOfPureArg&, const InvalidUsageOfPureArg&);
        };

        struct InvalidArgumentToPrivateEntryFunction {
            friend bool operator==(const InvalidArgumentToPrivateEntryFunction&, const InvalidArgumentToPrivateEntryFunction&);
        };

        struct IndexOutOfBounds {
            uint16_t idx;

            friend bool operator==(const IndexOutOfBounds&, const IndexOutOfBounds&);
        };

        struct SecondaryIndexOutOfBounds {
            uint16_t result_idx;
            uint16_t secondary_idx;

            friend bool operator==(const SecondaryIndexOutOfBounds&, const SecondaryIndexOutOfBounds&);
        };

        struct InvalidResultArity {
            uint16_t result_idx;

            friend bool operator==(const InvalidResultArity&, const InvalidResultArity&);
        };

        struct InvalidGasCoinUsage {
            friend bool operator==(const InvalidGasCoinUsage&, const InvalidGasCoinUsage&);
        };

        struct InvalidUsageOfBorrowedValue {
            friend bool operator==(const InvalidUsageOfBorrowedValue&, const InvalidUsageOfBorrowedValue&);
        };

        struct InvalidUsageOfTakenValue {
            friend bool operator==(const InvalidUsageOfTakenValue&, const InvalidUsageOfTakenValue&);
        };

        struct InvalidObjectByValue {
            friend bool operator==(const InvalidObjectByValue&, const InvalidObjectByValue&);
        };

        struct InvalidObjectByMutRef {
            friend bool operator==(const InvalidObjectByMutRef&, const InvalidObjectByMutRef&);
        };

        std::variant<TypeMismatch, InvalidBCSBytes, InvalidUsageOfPureArg, InvalidArgumentToPrivateEntryFunction, IndexOutOfBounds, SecondaryIndexOutOfBounds, InvalidResultArity, InvalidGasCoinUsage, InvalidUsageOfBorrowedValue, InvalidUsageOfTakenValue, InvalidObjectByValue, InvalidObjectByMutRef> value;

        friend bool operator==(const CommandArgumentError&, const CommandArgumentError&);
    };

    struct AccountAddress {
        std::array<uint8_t, 32> value;

        friend bool operator==(const AccountAddress&, const AccountAddress&);
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
        std::optional<std::string> function_name;

        friend bool operator==(const MoveLocation&, const MoveLocation&);
    };

    struct MoveLocationOpt {
        std::optional<sui_types::MoveLocation> value;

        friend bool operator==(const MoveLocationOpt&, const MoveLocationOpt&);
    };

    struct ObjectID {
        sui_types::AccountAddress value;

        friend bool operator==(const ObjectID&, const ObjectID&);
    };

    struct TypeArgumentError {

        struct TypeNotFound {
            friend bool operator==(const TypeNotFound&, const TypeNotFound&);
        };

        struct ConstraintNotSatisfied {
            friend bool operator==(const ConstraintNotSatisfied&, const ConstraintNotSatisfied&);
        };

        std::variant<TypeNotFound, ConstraintNotSatisfied> value;

        friend bool operator==(const TypeArgumentError&, const TypeArgumentError&);
    };

    struct ExecutionFailureStatus {

        struct InsufficientGas {
            friend bool operator==(const InsufficientGas&, const InsufficientGas&);
        };

        struct InvalidGasObject {
            friend bool operator==(const InvalidGasObject&, const InvalidGasObject&);
        };

        struct InvariantViolation {
            friend bool operator==(const InvariantViolation&, const InvariantViolation&);
        };

        struct FeatureNotYetSupported {
            friend bool operator==(const FeatureNotYetSupported&, const FeatureNotYetSupported&);
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

        struct CircularObjectOwnership {
            sui_types::ObjectID object;

            friend bool operator==(const CircularObjectOwnership&, const CircularObjectOwnership&);
        };

        struct InsufficientCoinBalance {
            friend bool operator==(const InsufficientCoinBalance&, const InsufficientCoinBalance&);
        };

        struct CoinBalanceOverflow {
            friend bool operator==(const CoinBalanceOverflow&, const CoinBalanceOverflow&);
        };

        struct PublishErrorNonZeroAddress {
            friend bool operator==(const PublishErrorNonZeroAddress&, const PublishErrorNonZeroAddress&);
        };

        struct SuiMoveVerificationError {
            friend bool operator==(const SuiMoveVerificationError&, const SuiMoveVerificationError&);
        };

        struct MovePrimitiveRuntimeError {
            sui_types::MoveLocationOpt value;

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

        struct FunctionNotFound {
            friend bool operator==(const FunctionNotFound&, const FunctionNotFound&);
        };

        struct ArityMismatch {
            friend bool operator==(const ArityMismatch&, const ArityMismatch&);
        };

        struct TypeArityMismatch {
            friend bool operator==(const TypeArityMismatch&, const TypeArityMismatch&);
        };

        struct NonEntryFunctionInvoked {
            friend bool operator==(const NonEntryFunctionInvoked&, const NonEntryFunctionInvoked&);
        };

        struct CommandArgumentError {
            uint16_t arg_idx;
            sui_types::CommandArgumentError kind;

            friend bool operator==(const CommandArgumentError&, const CommandArgumentError&);
        };

        struct TypeArgumentError {
            uint16_t argument_idx;
            sui_types::TypeArgumentError kind;

            friend bool operator==(const TypeArgumentError&, const TypeArgumentError&);
        };

        struct UnusedValueWithoutDrop {
            uint16_t result_idx;
            uint16_t secondary_idx;

            friend bool operator==(const UnusedValueWithoutDrop&, const UnusedValueWithoutDrop&);
        };

        struct InvalidPublicFunctionReturnType {
            uint16_t idx;

            friend bool operator==(const InvalidPublicFunctionReturnType&, const InvalidPublicFunctionReturnType&);
        };

        struct InvalidTransferObject {
            friend bool operator==(const InvalidTransferObject&, const InvalidTransferObject&);
        };

        std::variant<InsufficientGas, InvalidGasObject, InvariantViolation, FeatureNotYetSupported, MoveObjectTooBig, MovePackageTooBig, CircularObjectOwnership, InsufficientCoinBalance, CoinBalanceOverflow, PublishErrorNonZeroAddress, SuiMoveVerificationError, MovePrimitiveRuntimeError, MoveAbort, VMVerificationOrDeserializationError, VMInvariantViolation, FunctionNotFound, ArityMismatch, TypeArityMismatch, NonEntryFunctionInvoked, CommandArgumentError, TypeArgumentError, UnusedValueWithoutDrop, InvalidPublicFunctionReturnType, InvalidTransferObject> value;

        friend bool operator==(const ExecutionFailureStatus&, const ExecutionFailureStatus&);
    };

    struct Argument {

        struct GasCoin {
            friend bool operator==(const GasCoin&, const GasCoin&);
        };

        struct Input {
            uint16_t value;

            friend bool operator==(const Input&, const Input&);
        };

        struct Result {
            uint16_t value;

            friend bool operator==(const Result&, const Result&);
        };

        struct NestedResult {
            std::tuple<uint16_t, uint16_t> value;

            friend bool operator==(const NestedResult&, const NestedResult&);
        };

        std::variant<GasCoin, Input, Result, NestedResult> value;

        friend bool operator==(const Argument&, const Argument&);
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

    struct ProgrammableMoveCall {
        sui_types::ObjectID package;
        sui_types::Identifier module;
        sui_types::Identifier function;
        std::vector<sui_types::TypeTag> type_arguments;
        std::vector<sui_types::Argument> arguments;

        friend bool operator==(const ProgrammableMoveCall&, const ProgrammableMoveCall&);
    };

    struct Command {

        struct MoveCall {
            sui_types::ProgrammableMoveCall value;

            friend bool operator==(const MoveCall&, const MoveCall&);
        };

        struct TransferObjects {
            std::tuple<std::vector<sui_types::Argument>, sui_types::Argument> value;

            friend bool operator==(const TransferObjects&, const TransferObjects&);
        };

        struct SplitCoin {
            std::tuple<sui_types::Argument, std::vector<sui_types::Argument>> value;

            friend bool operator==(const SplitCoin&, const SplitCoin&);
        };

        struct MergeCoins {
            std::tuple<sui_types::Argument, std::vector<sui_types::Argument>> value;

            friend bool operator==(const MergeCoins&, const MergeCoins&);
        };

        struct Publish {
            std::vector<std::vector<uint8_t>> value;

            friend bool operator==(const Publish&, const Publish&);
        };

        struct MakeMoveVec {
            std::tuple<std::optional<sui_types::TypeTag>, std::vector<sui_types::Argument>> value;

            friend bool operator==(const MakeMoveVec&, const MakeMoveVec&);
        };

        struct Upgrade {
            std::tuple<std::vector<std::vector<uint8_t>>, std::vector<sui_types::ObjectID>, sui_types::Argument> value;

            friend bool operator==(const Upgrade&, const Upgrade&);
        };

        std::variant<MoveCall, TransferObjects, SplitCoin, MergeCoins, Publish, MakeMoveVec, Upgrade> value;

        friend bool operator==(const Command&, const Command&);
    };

    struct Sha3Digest {
        std::vector<uint8_t> value;

        friend bool operator==(const Sha3Digest&, const Sha3Digest&);
    };

    struct ObjectDigest {
        sui_types::Sha3Digest value;

        friend bool operator==(const ObjectDigest&, const ObjectDigest&);
    };

    struct SequenceNumber {
        uint64_t value;

        friend bool operator==(const SequenceNumber&, const SequenceNumber&);
    };

    struct SuiAddress {
        std::array<uint8_t, 32> value;

        friend bool operator==(const SuiAddress&, const SuiAddress&);
    };

    struct GasData {
        std::vector<std::tuple<sui_types::ObjectID, sui_types::SequenceNumber, sui_types::ObjectDigest>> payment;
        sui_types::SuiAddress owner;
        uint64_t gas_price;
        uint64_t gas_budget;

        friend bool operator==(const GasData&, const GasData&);
    };

    struct TransactionExpiration {

        struct None {
            friend bool operator==(const None&, const None&);
        };

        struct EpochId {
            uint64_t value;

            friend bool operator==(const EpochId&, const EpochId&);
        };

        std::variant<None, EpochId> value;

        friend bool operator==(const TransactionExpiration&, const TransactionExpiration&);
    };

    struct ProtocolVersion {
        uint64_t value;

        friend bool operator==(const ProtocolVersion&, const ProtocolVersion&);
    };

    struct ChangeEpoch {
        uint64_t epoch;
        sui_types::ProtocolVersion protocol_version;
        uint64_t storage_charge;
        uint64_t computation_charge;
        uint64_t storage_rebate;
        uint64_t epoch_start_timestamp_ms;
        std::vector<std::tuple<sui_types::SequenceNumber, std::vector<std::vector<uint8_t>>>> system_packages;

        friend bool operator==(const ChangeEpoch&, const ChangeEpoch&);
    };

    struct ConsensusCommitPrologue {
        uint64_t epoch;
        uint64_t round;
        uint64_t commit_timestamp_ms;

        friend bool operator==(const ConsensusCommitPrologue&, const ConsensusCommitPrologue&);
    };

    struct MoveObjectType {

        struct Other {
            sui_types::StructTag value;

            friend bool operator==(const Other&, const Other&);
        };

        struct GasCoin {
            friend bool operator==(const GasCoin&, const GasCoin&);
        };

        struct StakedSui {
            friend bool operator==(const StakedSui&, const StakedSui&);
        };

        struct Coin {
            sui_types::TypeTag value;

            friend bool operator==(const Coin&, const Coin&);
        };

        std::variant<Other, GasCoin, StakedSui, Coin> value;

        friend bool operator==(const MoveObjectType&, const MoveObjectType&);
    };

    struct MoveObject {
        sui_types::MoveObjectType type_;
        bool has_public_transfer;
        sui_types::SequenceNumber version;
        std::vector<uint8_t> contents;

        friend bool operator==(const MoveObject&, const MoveObject&);
    };

    struct MovePackage {
        sui_types::ObjectID id;
        sui_types::SequenceNumber version;
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

    struct GenesisObject {

        struct RawObject {
            sui_types::Data data;
            sui_types::Owner owner;

            friend bool operator==(const RawObject&, const RawObject&);
        };

        std::variant<RawObject> value;

        friend bool operator==(const GenesisObject&, const GenesisObject&);
    };

    struct GenesisTransaction {
        std::vector<sui_types::GenesisObject> objects;

        friend bool operator==(const GenesisTransaction&, const GenesisTransaction&);
    };

    struct ObjectArg {

        struct ImmOrOwnedObject {
            std::tuple<sui_types::ObjectID, sui_types::SequenceNumber, sui_types::ObjectDigest> value;

            friend bool operator==(const ImmOrOwnedObject&, const ImmOrOwnedObject&);
        };

        struct SharedObject {
            sui_types::ObjectID id;
            sui_types::SequenceNumber initial_shared_version;
            bool Mutable;

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

    struct ProgrammableTransaction {
        std::vector<sui_types::CallArg> inputs;
        std::vector<sui_types::Command> commands;

        friend bool operator==(const ProgrammableTransaction&, const ProgrammableTransaction&);
    };

    struct TransactionKind {

        struct ProgrammableTransaction {
            sui_types::ProgrammableTransaction value;

            friend bool operator==(const ProgrammableTransaction&, const ProgrammableTransaction&);
        };

        struct ChangeEpoch {
            sui_types::ChangeEpoch value;

            friend bool operator==(const ChangeEpoch&, const ChangeEpoch&);
        };

        struct Genesis {
            sui_types::GenesisTransaction value;

            friend bool operator==(const Genesis&, const Genesis&);
        };

        struct ConsensusCommitPrologue {
            sui_types::ConsensusCommitPrologue value;

            friend bool operator==(const ConsensusCommitPrologue&, const ConsensusCommitPrologue&);
        };

        std::variant<ProgrammableTransaction, ChangeEpoch, Genesis, ConsensusCommitPrologue> value;

        friend bool operator==(const TransactionKind&, const TransactionKind&);
    };

    struct TransactionDataV1 {
        sui_types::TransactionKind kind;
        sui_types::SuiAddress sender;
        sui_types::GasData gas_data;
        sui_types::TransactionExpiration expiration;

        friend bool operator==(const TransactionDataV1&, const TransactionDataV1&);
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
            std::optional<uint64_t> command;

            friend bool operator==(const Failure&, const Failure&);
        };

        std::variant<Success, Failure> value;

        friend bool operator==(const ExecutionStatus&, const ExecutionStatus&);
    };

    struct ObjectInfoRequestKind {

        struct LatestObjectInfo {
            friend bool operator==(const LatestObjectInfo&, const LatestObjectInfo&);
        };

        struct PastObjectInfoDebug {
            sui_types::SequenceNumber value;

            friend bool operator==(const PastObjectInfoDebug&, const PastObjectInfoDebug&);
        };

        std::variant<LatestObjectInfo, PastObjectInfoDebug> value;

        friend bool operator==(const ObjectInfoRequestKind&, const ObjectInfoRequestKind&);
    };

    struct TransactionData {

        struct V1 {
            sui_types::TransactionDataV1 value;

            friend bool operator==(const V1&, const V1&);
        };

        std::variant<V1> value;

        friend bool operator==(const TransactionData&, const TransactionData&);
    };

    struct TransactionDigest {
        sui_types::Sha3Digest value;

        friend bool operator==(const TransactionDigest&, const TransactionDigest&);
    };

    struct TransactionEffectsDigest {
        sui_types::Sha3Digest value;

        friend bool operator==(const TransactionEffectsDigest&, const TransactionEffectsDigest&);
    };

    struct AuthorityPublicKeyBytes {
        std::vector<uint8_t> value;

        friend bool operator==(const AuthorityPublicKeyBytes&, const AuthorityPublicKeyBytes&);
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

        struct RetryableTransactionError {
            friend bool operator==(const RetryableTransactionError&, const RetryableTransactionError&);
        };

        std::variant<RocksDBError, SerializationError, UnregisteredColumn, CrossDBBatch, MetricsReporting, RetryableTransactionError> value;

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

    inline bool operator==(const Argument &lhs, const Argument &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Argument>::serialize(const sui_types::Argument &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Argument serde::Deserializable<sui_types::Argument>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Argument obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const Argument::GasCoin &lhs, const Argument::GasCoin &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Argument::GasCoin>::serialize(const sui_types::Argument::GasCoin &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::Argument::GasCoin serde::Deserializable<sui_types::Argument::GasCoin>::deserialize(Deserializer &deserializer) {
    sui_types::Argument::GasCoin obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const Argument::Input &lhs, const Argument::Input &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Argument::Input>::serialize(const sui_types::Argument::Input &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Argument::Input serde::Deserializable<sui_types::Argument::Input>::deserialize(Deserializer &deserializer) {
    sui_types::Argument::Input obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const Argument::Result &lhs, const Argument::Result &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Argument::Result>::serialize(const sui_types::Argument::Result &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Argument::Result serde::Deserializable<sui_types::Argument::Result>::deserialize(Deserializer &deserializer) {
    sui_types::Argument::Result obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const Argument::NestedResult &lhs, const Argument::NestedResult &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Argument::NestedResult>::serialize(const sui_types::Argument::NestedResult &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Argument::NestedResult serde::Deserializable<sui_types::Argument::NestedResult>::deserialize(Deserializer &deserializer) {
    sui_types::Argument::NestedResult obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
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
        if (!(lhs.protocol_version == rhs.protocol_version)) { return false; }
        if (!(lhs.storage_charge == rhs.storage_charge)) { return false; }
        if (!(lhs.computation_charge == rhs.computation_charge)) { return false; }
        if (!(lhs.storage_rebate == rhs.storage_rebate)) { return false; }
        if (!(lhs.epoch_start_timestamp_ms == rhs.epoch_start_timestamp_ms)) { return false; }
        if (!(lhs.system_packages == rhs.system_packages)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ChangeEpoch>::serialize(const sui_types::ChangeEpoch &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.epoch)>::serialize(obj.epoch, serializer);
    serde::Serializable<decltype(obj.protocol_version)>::serialize(obj.protocol_version, serializer);
    serde::Serializable<decltype(obj.storage_charge)>::serialize(obj.storage_charge, serializer);
    serde::Serializable<decltype(obj.computation_charge)>::serialize(obj.computation_charge, serializer);
    serde::Serializable<decltype(obj.storage_rebate)>::serialize(obj.storage_rebate, serializer);
    serde::Serializable<decltype(obj.epoch_start_timestamp_ms)>::serialize(obj.epoch_start_timestamp_ms, serializer);
    serde::Serializable<decltype(obj.system_packages)>::serialize(obj.system_packages, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::ChangeEpoch serde::Deserializable<sui_types::ChangeEpoch>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ChangeEpoch obj;
    obj.epoch = serde::Deserializable<decltype(obj.epoch)>::deserialize(deserializer);
    obj.protocol_version = serde::Deserializable<decltype(obj.protocol_version)>::deserialize(deserializer);
    obj.storage_charge = serde::Deserializable<decltype(obj.storage_charge)>::deserialize(deserializer);
    obj.computation_charge = serde::Deserializable<decltype(obj.computation_charge)>::deserialize(deserializer);
    obj.storage_rebate = serde::Deserializable<decltype(obj.storage_rebate)>::deserialize(deserializer);
    obj.epoch_start_timestamp_ms = serde::Deserializable<decltype(obj.epoch_start_timestamp_ms)>::deserialize(deserializer);
    obj.system_packages = serde::Deserializable<decltype(obj.system_packages)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const Command &lhs, const Command &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Command>::serialize(const sui_types::Command &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Command serde::Deserializable<sui_types::Command>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Command obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const Command::MoveCall &lhs, const Command::MoveCall &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Command::MoveCall>::serialize(const sui_types::Command::MoveCall &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Command::MoveCall serde::Deserializable<sui_types::Command::MoveCall>::deserialize(Deserializer &deserializer) {
    sui_types::Command::MoveCall obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const Command::TransferObjects &lhs, const Command::TransferObjects &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Command::TransferObjects>::serialize(const sui_types::Command::TransferObjects &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Command::TransferObjects serde::Deserializable<sui_types::Command::TransferObjects>::deserialize(Deserializer &deserializer) {
    sui_types::Command::TransferObjects obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const Command::SplitCoin &lhs, const Command::SplitCoin &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Command::SplitCoin>::serialize(const sui_types::Command::SplitCoin &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Command::SplitCoin serde::Deserializable<sui_types::Command::SplitCoin>::deserialize(Deserializer &deserializer) {
    sui_types::Command::SplitCoin obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const Command::MergeCoins &lhs, const Command::MergeCoins &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Command::MergeCoins>::serialize(const sui_types::Command::MergeCoins &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Command::MergeCoins serde::Deserializable<sui_types::Command::MergeCoins>::deserialize(Deserializer &deserializer) {
    sui_types::Command::MergeCoins obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const Command::Publish &lhs, const Command::Publish &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Command::Publish>::serialize(const sui_types::Command::Publish &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Command::Publish serde::Deserializable<sui_types::Command::Publish>::deserialize(Deserializer &deserializer) {
    sui_types::Command::Publish obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const Command::MakeMoveVec &lhs, const Command::MakeMoveVec &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Command::MakeMoveVec>::serialize(const sui_types::Command::MakeMoveVec &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Command::MakeMoveVec serde::Deserializable<sui_types::Command::MakeMoveVec>::deserialize(Deserializer &deserializer) {
    sui_types::Command::MakeMoveVec obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const Command::Upgrade &lhs, const Command::Upgrade &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Command::Upgrade>::serialize(const sui_types::Command::Upgrade &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::Command::Upgrade serde::Deserializable<sui_types::Command::Upgrade>::deserialize(Deserializer &deserializer) {
    sui_types::Command::Upgrade obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const CommandArgumentError &lhs, const CommandArgumentError &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CommandArgumentError>::serialize(const sui_types::CommandArgumentError &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::CommandArgumentError serde::Deserializable<sui_types::CommandArgumentError>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::CommandArgumentError obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const CommandArgumentError::TypeMismatch &lhs, const CommandArgumentError::TypeMismatch &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CommandArgumentError::TypeMismatch>::serialize(const sui_types::CommandArgumentError::TypeMismatch &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::CommandArgumentError::TypeMismatch serde::Deserializable<sui_types::CommandArgumentError::TypeMismatch>::deserialize(Deserializer &deserializer) {
    sui_types::CommandArgumentError::TypeMismatch obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const CommandArgumentError::InvalidBCSBytes &lhs, const CommandArgumentError::InvalidBCSBytes &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CommandArgumentError::InvalidBCSBytes>::serialize(const sui_types::CommandArgumentError::InvalidBCSBytes &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::CommandArgumentError::InvalidBCSBytes serde::Deserializable<sui_types::CommandArgumentError::InvalidBCSBytes>::deserialize(Deserializer &deserializer) {
    sui_types::CommandArgumentError::InvalidBCSBytes obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const CommandArgumentError::InvalidUsageOfPureArg &lhs, const CommandArgumentError::InvalidUsageOfPureArg &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CommandArgumentError::InvalidUsageOfPureArg>::serialize(const sui_types::CommandArgumentError::InvalidUsageOfPureArg &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::CommandArgumentError::InvalidUsageOfPureArg serde::Deserializable<sui_types::CommandArgumentError::InvalidUsageOfPureArg>::deserialize(Deserializer &deserializer) {
    sui_types::CommandArgumentError::InvalidUsageOfPureArg obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const CommandArgumentError::InvalidArgumentToPrivateEntryFunction &lhs, const CommandArgumentError::InvalidArgumentToPrivateEntryFunction &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CommandArgumentError::InvalidArgumentToPrivateEntryFunction>::serialize(const sui_types::CommandArgumentError::InvalidArgumentToPrivateEntryFunction &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::CommandArgumentError::InvalidArgumentToPrivateEntryFunction serde::Deserializable<sui_types::CommandArgumentError::InvalidArgumentToPrivateEntryFunction>::deserialize(Deserializer &deserializer) {
    sui_types::CommandArgumentError::InvalidArgumentToPrivateEntryFunction obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const CommandArgumentError::IndexOutOfBounds &lhs, const CommandArgumentError::IndexOutOfBounds &rhs) {
        if (!(lhs.idx == rhs.idx)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CommandArgumentError::IndexOutOfBounds>::serialize(const sui_types::CommandArgumentError::IndexOutOfBounds &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.idx)>::serialize(obj.idx, serializer);
}

template <>
template <typename Deserializer>
sui_types::CommandArgumentError::IndexOutOfBounds serde::Deserializable<sui_types::CommandArgumentError::IndexOutOfBounds>::deserialize(Deserializer &deserializer) {
    sui_types::CommandArgumentError::IndexOutOfBounds obj;
    obj.idx = serde::Deserializable<decltype(obj.idx)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const CommandArgumentError::SecondaryIndexOutOfBounds &lhs, const CommandArgumentError::SecondaryIndexOutOfBounds &rhs) {
        if (!(lhs.result_idx == rhs.result_idx)) { return false; }
        if (!(lhs.secondary_idx == rhs.secondary_idx)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CommandArgumentError::SecondaryIndexOutOfBounds>::serialize(const sui_types::CommandArgumentError::SecondaryIndexOutOfBounds &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.result_idx)>::serialize(obj.result_idx, serializer);
    serde::Serializable<decltype(obj.secondary_idx)>::serialize(obj.secondary_idx, serializer);
}

template <>
template <typename Deserializer>
sui_types::CommandArgumentError::SecondaryIndexOutOfBounds serde::Deserializable<sui_types::CommandArgumentError::SecondaryIndexOutOfBounds>::deserialize(Deserializer &deserializer) {
    sui_types::CommandArgumentError::SecondaryIndexOutOfBounds obj;
    obj.result_idx = serde::Deserializable<decltype(obj.result_idx)>::deserialize(deserializer);
    obj.secondary_idx = serde::Deserializable<decltype(obj.secondary_idx)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const CommandArgumentError::InvalidResultArity &lhs, const CommandArgumentError::InvalidResultArity &rhs) {
        if (!(lhs.result_idx == rhs.result_idx)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CommandArgumentError::InvalidResultArity>::serialize(const sui_types::CommandArgumentError::InvalidResultArity &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.result_idx)>::serialize(obj.result_idx, serializer);
}

template <>
template <typename Deserializer>
sui_types::CommandArgumentError::InvalidResultArity serde::Deserializable<sui_types::CommandArgumentError::InvalidResultArity>::deserialize(Deserializer &deserializer) {
    sui_types::CommandArgumentError::InvalidResultArity obj;
    obj.result_idx = serde::Deserializable<decltype(obj.result_idx)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const CommandArgumentError::InvalidGasCoinUsage &lhs, const CommandArgumentError::InvalidGasCoinUsage &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CommandArgumentError::InvalidGasCoinUsage>::serialize(const sui_types::CommandArgumentError::InvalidGasCoinUsage &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::CommandArgumentError::InvalidGasCoinUsage serde::Deserializable<sui_types::CommandArgumentError::InvalidGasCoinUsage>::deserialize(Deserializer &deserializer) {
    sui_types::CommandArgumentError::InvalidGasCoinUsage obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const CommandArgumentError::InvalidUsageOfBorrowedValue &lhs, const CommandArgumentError::InvalidUsageOfBorrowedValue &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CommandArgumentError::InvalidUsageOfBorrowedValue>::serialize(const sui_types::CommandArgumentError::InvalidUsageOfBorrowedValue &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::CommandArgumentError::InvalidUsageOfBorrowedValue serde::Deserializable<sui_types::CommandArgumentError::InvalidUsageOfBorrowedValue>::deserialize(Deserializer &deserializer) {
    sui_types::CommandArgumentError::InvalidUsageOfBorrowedValue obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const CommandArgumentError::InvalidUsageOfTakenValue &lhs, const CommandArgumentError::InvalidUsageOfTakenValue &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CommandArgumentError::InvalidUsageOfTakenValue>::serialize(const sui_types::CommandArgumentError::InvalidUsageOfTakenValue &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::CommandArgumentError::InvalidUsageOfTakenValue serde::Deserializable<sui_types::CommandArgumentError::InvalidUsageOfTakenValue>::deserialize(Deserializer &deserializer) {
    sui_types::CommandArgumentError::InvalidUsageOfTakenValue obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const CommandArgumentError::InvalidObjectByValue &lhs, const CommandArgumentError::InvalidObjectByValue &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CommandArgumentError::InvalidObjectByValue>::serialize(const sui_types::CommandArgumentError::InvalidObjectByValue &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::CommandArgumentError::InvalidObjectByValue serde::Deserializable<sui_types::CommandArgumentError::InvalidObjectByValue>::deserialize(Deserializer &deserializer) {
    sui_types::CommandArgumentError::InvalidObjectByValue obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const CommandArgumentError::InvalidObjectByMutRef &lhs, const CommandArgumentError::InvalidObjectByMutRef &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::CommandArgumentError::InvalidObjectByMutRef>::serialize(const sui_types::CommandArgumentError::InvalidObjectByMutRef &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::CommandArgumentError::InvalidObjectByMutRef serde::Deserializable<sui_types::CommandArgumentError::InvalidObjectByMutRef>::deserialize(Deserializer &deserializer) {
    sui_types::CommandArgumentError::InvalidObjectByMutRef obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ConsensusCommitPrologue &lhs, const ConsensusCommitPrologue &rhs) {
        if (!(lhs.epoch == rhs.epoch)) { return false; }
        if (!(lhs.round == rhs.round)) { return false; }
        if (!(lhs.commit_timestamp_ms == rhs.commit_timestamp_ms)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ConsensusCommitPrologue>::serialize(const sui_types::ConsensusCommitPrologue &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.epoch)>::serialize(obj.epoch, serializer);
    serde::Serializable<decltype(obj.round)>::serialize(obj.round, serializer);
    serde::Serializable<decltype(obj.commit_timestamp_ms)>::serialize(obj.commit_timestamp_ms, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::ConsensusCommitPrologue serde::Deserializable<sui_types::ConsensusCommitPrologue>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ConsensusCommitPrologue obj;
    obj.epoch = serde::Deserializable<decltype(obj.epoch)>::deserialize(deserializer);
    obj.round = serde::Deserializable<decltype(obj.round)>::deserialize(deserializer);
    obj.commit_timestamp_ms = serde::Deserializable<decltype(obj.commit_timestamp_ms)>::deserialize(deserializer);
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

    inline bool operator==(const ExecutionFailureStatus::FeatureNotYetSupported &lhs, const ExecutionFailureStatus::FeatureNotYetSupported &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::FeatureNotYetSupported>::serialize(const sui_types::ExecutionFailureStatus::FeatureNotYetSupported &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::FeatureNotYetSupported serde::Deserializable<sui_types::ExecutionFailureStatus::FeatureNotYetSupported>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::FeatureNotYetSupported obj;
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

    inline bool operator==(const ExecutionFailureStatus::CircularObjectOwnership &lhs, const ExecutionFailureStatus::CircularObjectOwnership &rhs) {
        if (!(lhs.object == rhs.object)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::CircularObjectOwnership>::serialize(const sui_types::ExecutionFailureStatus::CircularObjectOwnership &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.object)>::serialize(obj.object, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::CircularObjectOwnership serde::Deserializable<sui_types::ExecutionFailureStatus::CircularObjectOwnership>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::CircularObjectOwnership obj;
    obj.object = serde::Deserializable<decltype(obj.object)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::InsufficientCoinBalance &lhs, const ExecutionFailureStatus::InsufficientCoinBalance &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InsufficientCoinBalance>::serialize(const sui_types::ExecutionFailureStatus::InsufficientCoinBalance &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InsufficientCoinBalance serde::Deserializable<sui_types::ExecutionFailureStatus::InsufficientCoinBalance>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InsufficientCoinBalance obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::CoinBalanceOverflow &lhs, const ExecutionFailureStatus::CoinBalanceOverflow &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::CoinBalanceOverflow>::serialize(const sui_types::ExecutionFailureStatus::CoinBalanceOverflow &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::CoinBalanceOverflow serde::Deserializable<sui_types::ExecutionFailureStatus::CoinBalanceOverflow>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::CoinBalanceOverflow obj;
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

    inline bool operator==(const ExecutionFailureStatus::ArityMismatch &lhs, const ExecutionFailureStatus::ArityMismatch &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::ArityMismatch>::serialize(const sui_types::ExecutionFailureStatus::ArityMismatch &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::ArityMismatch serde::Deserializable<sui_types::ExecutionFailureStatus::ArityMismatch>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::ArityMismatch obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::TypeArityMismatch &lhs, const ExecutionFailureStatus::TypeArityMismatch &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::TypeArityMismatch>::serialize(const sui_types::ExecutionFailureStatus::TypeArityMismatch &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::TypeArityMismatch serde::Deserializable<sui_types::ExecutionFailureStatus::TypeArityMismatch>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::TypeArityMismatch obj;
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

    inline bool operator==(const ExecutionFailureStatus::CommandArgumentError &lhs, const ExecutionFailureStatus::CommandArgumentError &rhs) {
        if (!(lhs.arg_idx == rhs.arg_idx)) { return false; }
        if (!(lhs.kind == rhs.kind)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::CommandArgumentError>::serialize(const sui_types::ExecutionFailureStatus::CommandArgumentError &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.arg_idx)>::serialize(obj.arg_idx, serializer);
    serde::Serializable<decltype(obj.kind)>::serialize(obj.kind, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::CommandArgumentError serde::Deserializable<sui_types::ExecutionFailureStatus::CommandArgumentError>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::CommandArgumentError obj;
    obj.arg_idx = serde::Deserializable<decltype(obj.arg_idx)>::deserialize(deserializer);
    obj.kind = serde::Deserializable<decltype(obj.kind)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::TypeArgumentError &lhs, const ExecutionFailureStatus::TypeArgumentError &rhs) {
        if (!(lhs.argument_idx == rhs.argument_idx)) { return false; }
        if (!(lhs.kind == rhs.kind)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::TypeArgumentError>::serialize(const sui_types::ExecutionFailureStatus::TypeArgumentError &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.argument_idx)>::serialize(obj.argument_idx, serializer);
    serde::Serializable<decltype(obj.kind)>::serialize(obj.kind, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::TypeArgumentError serde::Deserializable<sui_types::ExecutionFailureStatus::TypeArgumentError>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::TypeArgumentError obj;
    obj.argument_idx = serde::Deserializable<decltype(obj.argument_idx)>::deserialize(deserializer);
    obj.kind = serde::Deserializable<decltype(obj.kind)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::UnusedValueWithoutDrop &lhs, const ExecutionFailureStatus::UnusedValueWithoutDrop &rhs) {
        if (!(lhs.result_idx == rhs.result_idx)) { return false; }
        if (!(lhs.secondary_idx == rhs.secondary_idx)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::UnusedValueWithoutDrop>::serialize(const sui_types::ExecutionFailureStatus::UnusedValueWithoutDrop &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.result_idx)>::serialize(obj.result_idx, serializer);
    serde::Serializable<decltype(obj.secondary_idx)>::serialize(obj.secondary_idx, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::UnusedValueWithoutDrop serde::Deserializable<sui_types::ExecutionFailureStatus::UnusedValueWithoutDrop>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::UnusedValueWithoutDrop obj;
    obj.result_idx = serde::Deserializable<decltype(obj.result_idx)>::deserialize(deserializer);
    obj.secondary_idx = serde::Deserializable<decltype(obj.secondary_idx)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const ExecutionFailureStatus::InvalidPublicFunctionReturnType &lhs, const ExecutionFailureStatus::InvalidPublicFunctionReturnType &rhs) {
        if (!(lhs.idx == rhs.idx)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionFailureStatus::InvalidPublicFunctionReturnType>::serialize(const sui_types::ExecutionFailureStatus::InvalidPublicFunctionReturnType &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.idx)>::serialize(obj.idx, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionFailureStatus::InvalidPublicFunctionReturnType serde::Deserializable<sui_types::ExecutionFailureStatus::InvalidPublicFunctionReturnType>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionFailureStatus::InvalidPublicFunctionReturnType obj;
    obj.idx = serde::Deserializable<decltype(obj.idx)>::deserialize(deserializer);
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
        if (!(lhs.command == rhs.command)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ExecutionStatus::Failure>::serialize(const sui_types::ExecutionStatus::Failure &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.error)>::serialize(obj.error, serializer);
    serde::Serializable<decltype(obj.command)>::serialize(obj.command, serializer);
}

template <>
template <typename Deserializer>
sui_types::ExecutionStatus::Failure serde::Deserializable<sui_types::ExecutionStatus::Failure>::deserialize(Deserializer &deserializer) {
    sui_types::ExecutionStatus::Failure obj;
    obj.error = serde::Deserializable<decltype(obj.error)>::deserialize(deserializer);
    obj.command = serde::Deserializable<decltype(obj.command)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const GasData &lhs, const GasData &rhs) {
        if (!(lhs.payment == rhs.payment)) { return false; }
        if (!(lhs.owner == rhs.owner)) { return false; }
        if (!(lhs.gas_price == rhs.gas_price)) { return false; }
        if (!(lhs.gas_budget == rhs.gas_budget)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::GasData>::serialize(const sui_types::GasData &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.payment)>::serialize(obj.payment, serializer);
    serde::Serializable<decltype(obj.owner)>::serialize(obj.owner, serializer);
    serde::Serializable<decltype(obj.gas_price)>::serialize(obj.gas_price, serializer);
    serde::Serializable<decltype(obj.gas_budget)>::serialize(obj.gas_budget, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::GasData serde::Deserializable<sui_types::GasData>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::GasData obj;
    obj.payment = serde::Deserializable<decltype(obj.payment)>::deserialize(deserializer);
    obj.owner = serde::Deserializable<decltype(obj.owner)>::deserialize(deserializer);
    obj.gas_price = serde::Deserializable<decltype(obj.gas_price)>::deserialize(deserializer);
    obj.gas_budget = serde::Deserializable<decltype(obj.gas_budget)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const GenesisObject &lhs, const GenesisObject &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::GenesisObject>::serialize(const sui_types::GenesisObject &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::GenesisObject serde::Deserializable<sui_types::GenesisObject>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::GenesisObject obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const GenesisObject::RawObject &lhs, const GenesisObject::RawObject &rhs) {
        if (!(lhs.data == rhs.data)) { return false; }
        if (!(lhs.owner == rhs.owner)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::GenesisObject::RawObject>::serialize(const sui_types::GenesisObject::RawObject &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.data)>::serialize(obj.data, serializer);
    serde::Serializable<decltype(obj.owner)>::serialize(obj.owner, serializer);
}

template <>
template <typename Deserializer>
sui_types::GenesisObject::RawObject serde::Deserializable<sui_types::GenesisObject::RawObject>::deserialize(Deserializer &deserializer) {
    sui_types::GenesisObject::RawObject obj;
    obj.data = serde::Deserializable<decltype(obj.data)>::deserialize(deserializer);
    obj.owner = serde::Deserializable<decltype(obj.owner)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const GenesisTransaction &lhs, const GenesisTransaction &rhs) {
        if (!(lhs.objects == rhs.objects)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::GenesisTransaction>::serialize(const sui_types::GenesisTransaction &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.objects)>::serialize(obj.objects, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::GenesisTransaction serde::Deserializable<sui_types::GenesisTransaction>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::GenesisTransaction obj;
    obj.objects = serde::Deserializable<decltype(obj.objects)>::deserialize(deserializer);
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
        if (!(lhs.function_name == rhs.function_name)) { return false; }
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
    serde::Serializable<decltype(obj.function_name)>::serialize(obj.function_name, serializer);
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
    obj.function_name = serde::Deserializable<decltype(obj.function_name)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveLocationOpt &lhs, const MoveLocationOpt &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveLocationOpt>::serialize(const sui_types::MoveLocationOpt &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::MoveLocationOpt serde::Deserializable<sui_types::MoveLocationOpt>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::MoveLocationOpt obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
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

    inline bool operator==(const MoveObjectType &lhs, const MoveObjectType &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveObjectType>::serialize(const sui_types::MoveObjectType &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::MoveObjectType serde::Deserializable<sui_types::MoveObjectType>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::MoveObjectType obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveObjectType::Other &lhs, const MoveObjectType::Other &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveObjectType::Other>::serialize(const sui_types::MoveObjectType::Other &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::MoveObjectType::Other serde::Deserializable<sui_types::MoveObjectType::Other>::deserialize(Deserializer &deserializer) {
    sui_types::MoveObjectType::Other obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveObjectType::GasCoin &lhs, const MoveObjectType::GasCoin &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveObjectType::GasCoin>::serialize(const sui_types::MoveObjectType::GasCoin &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::MoveObjectType::GasCoin serde::Deserializable<sui_types::MoveObjectType::GasCoin>::deserialize(Deserializer &deserializer) {
    sui_types::MoveObjectType::GasCoin obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveObjectType::StakedSui &lhs, const MoveObjectType::StakedSui &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveObjectType::StakedSui>::serialize(const sui_types::MoveObjectType::StakedSui &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::MoveObjectType::StakedSui serde::Deserializable<sui_types::MoveObjectType::StakedSui>::deserialize(Deserializer &deserializer) {
    sui_types::MoveObjectType::StakedSui obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const MoveObjectType::Coin &lhs, const MoveObjectType::Coin &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MoveObjectType::Coin>::serialize(const sui_types::MoveObjectType::Coin &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::MoveObjectType::Coin serde::Deserializable<sui_types::MoveObjectType::Coin>::deserialize(Deserializer &deserializer) {
    sui_types::MoveObjectType::Coin obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const MovePackage &lhs, const MovePackage &rhs) {
        if (!(lhs.id == rhs.id)) { return false; }
        if (!(lhs.version == rhs.version)) { return false; }
        if (!(lhs.module_map == rhs.module_map)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::MovePackage>::serialize(const sui_types::MovePackage &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.id)>::serialize(obj.id, serializer);
    serde::Serializable<decltype(obj.version)>::serialize(obj.version, serializer);
    serde::Serializable<decltype(obj.module_map)>::serialize(obj.module_map, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::MovePackage serde::Deserializable<sui_types::MovePackage>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::MovePackage obj;
    obj.id = serde::Deserializable<decltype(obj.id)>::deserialize(deserializer);
    obj.version = serde::Deserializable<decltype(obj.version)>::deserialize(deserializer);
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
        if (!(lhs.Mutable == rhs.Mutable)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ObjectArg::SharedObject>::serialize(const sui_types::ObjectArg::SharedObject &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.id)>::serialize(obj.id, serializer);
    serde::Serializable<decltype(obj.initial_shared_version)>::serialize(obj.initial_shared_version, serializer);
    serde::Serializable<decltype(obj.Mutable)>::serialize(obj.Mutable, serializer);
}

template <>
template <typename Deserializer>
sui_types::ObjectArg::SharedObject serde::Deserializable<sui_types::ObjectArg::SharedObject>::deserialize(Deserializer &deserializer) {
    sui_types::ObjectArg::SharedObject obj;
    obj.id = serde::Deserializable<decltype(obj.id)>::deserialize(deserializer);
    obj.initial_shared_version = serde::Deserializable<decltype(obj.initial_shared_version)>::deserialize(deserializer);
    obj.Mutable = serde::Deserializable<decltype(obj.Mutable)>::deserialize(deserializer);
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
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ObjectInfoRequestKind::LatestObjectInfo>::serialize(const sui_types::ObjectInfoRequestKind::LatestObjectInfo &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::ObjectInfoRequestKind::LatestObjectInfo serde::Deserializable<sui_types::ObjectInfoRequestKind::LatestObjectInfo>::deserialize(Deserializer &deserializer) {
    sui_types::ObjectInfoRequestKind::LatestObjectInfo obj;
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

    inline bool operator==(const ProgrammableMoveCall &lhs, const ProgrammableMoveCall &rhs) {
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
void serde::Serializable<sui_types::ProgrammableMoveCall>::serialize(const sui_types::ProgrammableMoveCall &obj, Serializer &serializer) {
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
sui_types::ProgrammableMoveCall serde::Deserializable<sui_types::ProgrammableMoveCall>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ProgrammableMoveCall obj;
    obj.package = serde::Deserializable<decltype(obj.package)>::deserialize(deserializer);
    obj.module = serde::Deserializable<decltype(obj.module)>::deserialize(deserializer);
    obj.function = serde::Deserializable<decltype(obj.function)>::deserialize(deserializer);
    obj.type_arguments = serde::Deserializable<decltype(obj.type_arguments)>::deserialize(deserializer);
    obj.arguments = serde::Deserializable<decltype(obj.arguments)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const ProgrammableTransaction &lhs, const ProgrammableTransaction &rhs) {
        if (!(lhs.inputs == rhs.inputs)) { return false; }
        if (!(lhs.commands == rhs.commands)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ProgrammableTransaction>::serialize(const sui_types::ProgrammableTransaction &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.inputs)>::serialize(obj.inputs, serializer);
    serde::Serializable<decltype(obj.commands)>::serialize(obj.commands, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::ProgrammableTransaction serde::Deserializable<sui_types::ProgrammableTransaction>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ProgrammableTransaction obj;
    obj.inputs = serde::Deserializable<decltype(obj.inputs)>::deserialize(deserializer);
    obj.commands = serde::Deserializable<decltype(obj.commands)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const ProtocolVersion &lhs, const ProtocolVersion &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::ProtocolVersion>::serialize(const sui_types::ProtocolVersion &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::ProtocolVersion serde::Deserializable<sui_types::ProtocolVersion>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::ProtocolVersion obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
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

    inline bool operator==(const Sha3Digest &lhs, const Sha3Digest &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::Sha3Digest>::serialize(const sui_types::Sha3Digest &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::Sha3Digest serde::Deserializable<sui_types::Sha3Digest>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::Sha3Digest obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
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
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionData>::serialize(const sui_types::TransactionData &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::TransactionData serde::Deserializable<sui_types::TransactionData>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::TransactionData obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransactionData::V1 &lhs, const TransactionData::V1 &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionData::V1>::serialize(const sui_types::TransactionData::V1 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::TransactionData::V1 serde::Deserializable<sui_types::TransactionData::V1>::deserialize(Deserializer &deserializer) {
    sui_types::TransactionData::V1 obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransactionDataV1 &lhs, const TransactionDataV1 &rhs) {
        if (!(lhs.kind == rhs.kind)) { return false; }
        if (!(lhs.sender == rhs.sender)) { return false; }
        if (!(lhs.gas_data == rhs.gas_data)) { return false; }
        if (!(lhs.expiration == rhs.expiration)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionDataV1>::serialize(const sui_types::TransactionDataV1 &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.kind)>::serialize(obj.kind, serializer);
    serde::Serializable<decltype(obj.sender)>::serialize(obj.sender, serializer);
    serde::Serializable<decltype(obj.gas_data)>::serialize(obj.gas_data, serializer);
    serde::Serializable<decltype(obj.expiration)>::serialize(obj.expiration, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::TransactionDataV1 serde::Deserializable<sui_types::TransactionDataV1>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::TransactionDataV1 obj;
    obj.kind = serde::Deserializable<decltype(obj.kind)>::deserialize(deserializer);
    obj.sender = serde::Deserializable<decltype(obj.sender)>::deserialize(deserializer);
    obj.gas_data = serde::Deserializable<decltype(obj.gas_data)>::deserialize(deserializer);
    obj.expiration = serde::Deserializable<decltype(obj.expiration)>::deserialize(deserializer);
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

    inline bool operator==(const TransactionExpiration &lhs, const TransactionExpiration &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionExpiration>::serialize(const sui_types::TransactionExpiration &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::TransactionExpiration serde::Deserializable<sui_types::TransactionExpiration>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::TransactionExpiration obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransactionExpiration::None &lhs, const TransactionExpiration::None &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionExpiration::None>::serialize(const sui_types::TransactionExpiration::None &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TransactionExpiration::None serde::Deserializable<sui_types::TransactionExpiration::None>::deserialize(Deserializer &deserializer) {
    sui_types::TransactionExpiration::None obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransactionExpiration::EpochId &lhs, const TransactionExpiration::EpochId &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionExpiration::EpochId>::serialize(const sui_types::TransactionExpiration::EpochId &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::TransactionExpiration::EpochId serde::Deserializable<sui_types::TransactionExpiration::EpochId>::deserialize(Deserializer &deserializer) {
    sui_types::TransactionExpiration::EpochId obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
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

    inline bool operator==(const TransactionKind::ProgrammableTransaction &lhs, const TransactionKind::ProgrammableTransaction &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionKind::ProgrammableTransaction>::serialize(const sui_types::TransactionKind::ProgrammableTransaction &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::TransactionKind::ProgrammableTransaction serde::Deserializable<sui_types::TransactionKind::ProgrammableTransaction>::deserialize(Deserializer &deserializer) {
    sui_types::TransactionKind::ProgrammableTransaction obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransactionKind::ChangeEpoch &lhs, const TransactionKind::ChangeEpoch &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionKind::ChangeEpoch>::serialize(const sui_types::TransactionKind::ChangeEpoch &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::TransactionKind::ChangeEpoch serde::Deserializable<sui_types::TransactionKind::ChangeEpoch>::deserialize(Deserializer &deserializer) {
    sui_types::TransactionKind::ChangeEpoch obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransactionKind::Genesis &lhs, const TransactionKind::Genesis &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionKind::Genesis>::serialize(const sui_types::TransactionKind::Genesis &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::TransactionKind::Genesis serde::Deserializable<sui_types::TransactionKind::Genesis>::deserialize(Deserializer &deserializer) {
    sui_types::TransactionKind::Genesis obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const TransactionKind::ConsensusCommitPrologue &lhs, const TransactionKind::ConsensusCommitPrologue &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TransactionKind::ConsensusCommitPrologue>::serialize(const sui_types::TransactionKind::ConsensusCommitPrologue &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
sui_types::TransactionKind::ConsensusCommitPrologue serde::Deserializable<sui_types::TransactionKind::ConsensusCommitPrologue>::deserialize(Deserializer &deserializer) {
    sui_types::TransactionKind::ConsensusCommitPrologue obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypeArgumentError &lhs, const TypeArgumentError &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeArgumentError>::serialize(const sui_types::TypeArgumentError &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
sui_types::TypeArgumentError serde::Deserializable<sui_types::TypeArgumentError>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    sui_types::TypeArgumentError obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypeArgumentError::TypeNotFound &lhs, const TypeArgumentError::TypeNotFound &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeArgumentError::TypeNotFound>::serialize(const sui_types::TypeArgumentError::TypeNotFound &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TypeArgumentError::TypeNotFound serde::Deserializable<sui_types::TypeArgumentError::TypeNotFound>::deserialize(Deserializer &deserializer) {
    sui_types::TypeArgumentError::TypeNotFound obj;
    return obj;
}

namespace sui_types {

    inline bool operator==(const TypeArgumentError::ConstraintNotSatisfied &lhs, const TypeArgumentError::ConstraintNotSatisfied &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypeArgumentError::ConstraintNotSatisfied>::serialize(const sui_types::TypeArgumentError::ConstraintNotSatisfied &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TypeArgumentError::ConstraintNotSatisfied serde::Deserializable<sui_types::TypeArgumentError::ConstraintNotSatisfied>::deserialize(Deserializer &deserializer) {
    sui_types::TypeArgumentError::ConstraintNotSatisfied obj;
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

namespace sui_types {

    inline bool operator==(const TypedStoreError::RetryableTransactionError &lhs, const TypedStoreError::RetryableTransactionError &rhs) {
        return true;
    }

} // end of namespace sui_types

template <>
template <typename Serializer>
void serde::Serializable<sui_types::TypedStoreError::RetryableTransactionError>::serialize(const sui_types::TypedStoreError::RetryableTransactionError &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
sui_types::TypedStoreError::RetryableTransactionError serde::Deserializable<sui_types::TypedStoreError::RetryableTransactionError>::deserialize(Deserializer &deserializer) {
    sui_types::TypedStoreError::RetryableTransactionError obj;
    return obj;
}
