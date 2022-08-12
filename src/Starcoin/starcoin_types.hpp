#pragma once

#include "serde.hpp"

namespace starcoin_types {

    struct AccountAddress {
        std::array<uint8_t, 16> value;

        friend bool operator==(const AccountAddress&, const AccountAddress&);
    };

    struct AuthenticationKey {
        std::vector<uint8_t> value;

        friend bool operator==(const AuthenticationKey&, const AuthenticationKey&);
    };

    struct ChainId {
        uint8_t id;

        friend bool operator==(const ChainId&, const ChainId&);
    };

    struct HashValue {
        std::vector<uint8_t> value;

        friend bool operator==(const HashValue&, const HashValue&);
    };

    struct BlockMetadata {
        starcoin_types::HashValue parent_hash;
        uint64_t timestamp;
        starcoin_types::AccountAddress author;
        std::optional<starcoin_types::AuthenticationKey> author_auth_key;
        uint64_t uncles;
        uint64_t number;
        starcoin_types::ChainId chain_id;
        uint64_t parent_gas_used;

        friend bool operator==(const BlockMetadata&, const BlockMetadata&);
    };

    struct SigningMessage {
        std::vector<uint8_t> value;

        friend bool operator==(const SigningMessage&, const SigningMessage&);
    };

    struct Ed25519PublicKey {
        std::vector<uint8_t> value;

        friend bool operator==(const Ed25519PublicKey&, const Ed25519PublicKey&);
    };

    struct Ed25519Signature {
        std::vector<uint8_t> value;

        friend bool operator==(const Ed25519Signature&, const Ed25519Signature&);
    };

    struct MultiEd25519PublicKey {
        std::vector<uint8_t> value;

        friend bool operator==(const MultiEd25519PublicKey&, const MultiEd25519PublicKey&);
    };

    struct MultiEd25519Signature {
        std::vector<uint8_t> value;

        friend bool operator==(const MultiEd25519Signature&, const MultiEd25519Signature&);
    };

    struct TransactionAuthenticator {

        struct Ed25519 {
            starcoin_types::Ed25519PublicKey public_key;
            starcoin_types::Ed25519Signature signature;

            friend bool operator==(const Ed25519&, const Ed25519&);
        };

        struct MultiEd25519 {
            starcoin_types::MultiEd25519PublicKey public_key;
            starcoin_types::MultiEd25519Signature signature;

            friend bool operator==(const MultiEd25519&, const MultiEd25519&);
        };

        std::variant<Ed25519, MultiEd25519> value;

        friend bool operator==(const TransactionAuthenticator&, const TransactionAuthenticator&);
    };

    struct SignedMessage {
        starcoin_types::AccountAddress account;
        starcoin_types::SigningMessage message;
        starcoin_types::TransactionAuthenticator authenticator;
        starcoin_types::ChainId chain_id;

        friend bool operator==(const SignedMessage&, const SignedMessage&);
    };

    struct EventKey {
        std::vector<uint8_t> value;

        friend bool operator==(const EventKey&, const EventKey&);
    };

    struct EventHandle {
        uint64_t count;
        starcoin_types::EventKey key;

        friend bool operator==(const EventHandle&, const EventHandle&);
    };

    struct KeyRotationCapabilityResource {
        starcoin_types::AccountAddress account_address;

        friend bool operator==(const KeyRotationCapabilityResource&, const KeyRotationCapabilityResource&);
    };

    struct WithdrawCapabilityResource {
        starcoin_types::AccountAddress account_address;

        friend bool operator==(const WithdrawCapabilityResource&, const WithdrawCapabilityResource&);
    };

    struct AccountResource {
        std::vector<uint8_t> authentication_key;
        std::optional<starcoin_types::WithdrawCapabilityResource> withdrawal_capability;
        std::optional<starcoin_types::KeyRotationCapabilityResource> key_rotation_capability;
        starcoin_types::EventHandle withdraw_events;
        starcoin_types::EventHandle deposit_events;
        starcoin_types::EventHandle accept_token_events;
        uint64_t sequence_number;

        friend bool operator==(const AccountResource&, const AccountResource&);
    };

    struct Module {
        std::vector<uint8_t> code;

        friend bool operator==(const Module&, const Module&);
    };

    struct Identifier {
        std::string value;

        friend bool operator==(const Identifier&, const Identifier&);
    };

    struct ModuleId {
        starcoin_types::AccountAddress address;
        starcoin_types::Identifier name;

        friend bool operator==(const ModuleId&, const ModuleId&);
    };

    struct TypeTag;

    struct StructTag {
        starcoin_types::AccountAddress address;
        starcoin_types::Identifier module;
        starcoin_types::Identifier name;
        std::vector<starcoin_types::TypeTag> type_args;

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

        struct Address {
            friend bool operator==(const Address&, const Address&);
        };

        struct Signer {
            friend bool operator==(const Signer&, const Signer&);
        };

        struct Vector {
            serde::value_ptr<starcoin_types::TypeTag> value;

            friend bool operator==(const Vector&, const Vector&);
        };

        struct Struct {
            starcoin_types::StructTag value;

            friend bool operator==(const Struct&, const Struct&);
        };

        std::variant<Bool, U8, U64, U128, Address, Signer, Vector, Struct> value;

        friend bool operator==(const TypeTag&, const TypeTag&);
    };

    struct ScriptFunction {
        starcoin_types::ModuleId module;
        starcoin_types::Identifier function;
        std::vector<starcoin_types::TypeTag> ty_args;
        std::vector<std::vector<uint8_t>> args;

        friend bool operator==(const ScriptFunction&, const ScriptFunction&);
    };

    struct Package {
        starcoin_types::AccountAddress package_address;
        std::vector<starcoin_types::Module> modules;
        std::optional<starcoin_types::ScriptFunction> init_script;

        friend bool operator==(const Package&, const Package&);
    };

    struct Script {
        std::vector<uint8_t> code;
        std::vector<starcoin_types::TypeTag> ty_args;
        std::vector<std::vector<uint8_t>> args;

        friend bool operator==(const Script&, const Script&);
    };

    struct TransactionPayload {

        struct Script {
            starcoin_types::Script value;

            friend bool operator==(const Script&, const Script&);
        };

        struct Package {
            starcoin_types::Package value;

            friend bool operator==(const Package&, const Package&);
        };

        struct ScriptFunction {
            starcoin_types::ScriptFunction value;

            friend bool operator==(const ScriptFunction&, const ScriptFunction&);
        };

        std::variant<Script, Package, ScriptFunction> value;

        friend bool operator==(const TransactionPayload&, const TransactionPayload&);
    };

    struct RawUserTransaction {
        starcoin_types::AccountAddress sender;
        uint64_t sequence_number;
        starcoin_types::TransactionPayload payload;
        uint64_t max_gas_amount;
        uint64_t gas_unit_price;
        std::string gas_token_code;
        uint64_t expiration_timestamp_secs;
        starcoin_types::ChainId chain_id;

        friend bool operator==(const RawUserTransaction&, const RawUserTransaction&);
    };

    struct ArgumentABI {
        std::string name;
        starcoin_types::TypeTag type_tag;

        friend bool operator==(const ArgumentABI&, const ArgumentABI&);
    };

    struct TypeArgumentABI {
        std::string name;

        friend bool operator==(const TypeArgumentABI&, const TypeArgumentABI&);
    };

    struct ScriptFunctionABI {
        std::string name;
        starcoin_types::ModuleId module_name;
        std::string doc;
        std::vector<starcoin_types::TypeArgumentABI> ty_args;
        std::vector<starcoin_types::ArgumentABI> args;

        friend bool operator==(const ScriptFunctionABI&, const ScriptFunctionABI&);
    };

    struct DataPath {

        struct Code {
            starcoin_types::Identifier value;

            friend bool operator==(const Code&, const Code&);
        };

        struct Resource {
            starcoin_types::StructTag value;

            friend bool operator==(const Resource&, const Resource&);
        };

        std::variant<Code, Resource> value;

        friend bool operator==(const DataPath&, const DataPath&);
    };

    struct AccessPath {
        std::tuple<starcoin_types::AccountAddress, starcoin_types::DataPath> value;

        friend bool operator==(const AccessPath&, const AccessPath&);
    };

    struct ContractEventV0 {
        starcoin_types::EventKey key;
        uint64_t sequence_number;
        starcoin_types::TypeTag type_tag;
        std::vector<uint8_t> event_data;

        friend bool operator==(const ContractEventV0&, const ContractEventV0&);
    };

    struct TransactionScriptABI {
        std::string name;
        std::string doc;
        std::vector<uint8_t> code;
        std::vector<starcoin_types::TypeArgumentABI> ty_args;
        std::vector<starcoin_types::ArgumentABI> args;

        friend bool operator==(const TransactionScriptABI&, const TransactionScriptABI&);
    };

    struct ScriptABI {

        struct TransactionScript {
            starcoin_types::TransactionScriptABI value;

            friend bool operator==(const TransactionScript&, const TransactionScript&);
        };

        struct ScriptFunction {
            starcoin_types::ScriptFunctionABI value;

            friend bool operator==(const ScriptFunction&, const ScriptFunction&);
        };

        std::variant<TransactionScript, ScriptFunction> value;

        friend bool operator==(const ScriptABI&, const ScriptABI&);
    };

    struct SignedUserTransaction {
        starcoin_types::RawUserTransaction raw_txn;
        starcoin_types::TransactionAuthenticator authenticator;

        friend bool operator==(const SignedUserTransaction&, const SignedUserTransaction&);
    };

    struct Transaction {

        struct UserTransaction {
            starcoin_types::SignedUserTransaction value;

            friend bool operator==(const UserTransaction&, const UserTransaction&);
        };

        struct BlockMetadata {
            starcoin_types::BlockMetadata value;

            friend bool operator==(const BlockMetadata&, const BlockMetadata&);
        };

        std::variant<UserTransaction, BlockMetadata> value;

        friend bool operator==(const Transaction&, const Transaction&);
    };

    struct WriteOp {

        struct Deletion {
            friend bool operator==(const Deletion&, const Deletion&);
        };

        struct Value {
            std::vector<uint8_t> value;

            friend bool operator==(const Value&, const Value&);
        };

        std::variant<Deletion, Value> value;

        friend bool operator==(const WriteOp&, const WriteOp&);
    };

    struct WriteSetMut {
        std::vector<std::tuple<starcoin_types::AccessPath, starcoin_types::WriteOp>> write_set;

        friend bool operator==(const WriteSetMut&, const WriteSetMut&);
    };

    struct ContractEvent {

        struct V0 {
            starcoin_types::ContractEventV0 value;

            friend bool operator==(const V0&, const V0&);
        };

        std::variant<V0> value;

        friend bool operator==(const ContractEvent&, const ContractEvent&);
    };

    struct TransactionArgument {

        struct U8 {
            uint8_t value;

            friend bool operator==(const U8&, const U8&);
        };

        struct U64 {
            uint64_t value;

            friend bool operator==(const U64&, const U64&);
        };

        struct U128 {
            serde::uint128_t value;

            friend bool operator==(const U128&, const U128&);
        };

        struct Address {
            starcoin_types::AccountAddress value;

            friend bool operator==(const Address&, const Address&);
        };

        struct U8Vector {
            std::vector<uint8_t> value;

            friend bool operator==(const U8Vector&, const U8Vector&);
        };

        struct Bool {
            bool value;

            friend bool operator==(const Bool&, const Bool&);
        };

        std::variant<U8, U64, U128, Address, U8Vector, Bool> value;

        friend bool operator==(const TransactionArgument&, const TransactionArgument&);
    };

    struct WriteSet {
        starcoin_types::WriteSetMut value;

        friend bool operator==(const WriteSet&, const WriteSet&);
    };

    struct DataType {

        struct CODE {
            friend bool operator==(const CODE&, const CODE&);
        };

        struct RESOURCE {
            friend bool operator==(const RESOURCE&, const RESOURCE&);
        };

        std::variant<CODE, RESOURCE> value;

        friend bool operator==(const DataType&, const DataType&);
    };

    struct Ed25519PrivateKey {
        std::vector<uint8_t> value;

        friend bool operator==(const Ed25519PrivateKey&, const Ed25519PrivateKey&);
    };

    struct MultiEd25519PrivateKey {
        std::vector<uint8_t> value;

        friend bool operator==(const MultiEd25519PrivateKey&, const MultiEd25519PrivateKey&);
    };

} // end of namespace starcoin_types


namespace starcoin_types {

    inline bool operator==(const AccessPath &lhs, const AccessPath &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::AccessPath>::serialize(const starcoin_types::AccessPath &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::AccessPath serde::Deserializable<starcoin_types::AccessPath>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::AccessPath obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const AccountAddress &lhs, const AccountAddress &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::AccountAddress>::serialize(const starcoin_types::AccountAddress &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::AccountAddress serde::Deserializable<starcoin_types::AccountAddress>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::AccountAddress obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const AccountResource &lhs, const AccountResource &rhs) {
        if (!(lhs.authentication_key == rhs.authentication_key)) { return false; }
        if (!(lhs.withdrawal_capability == rhs.withdrawal_capability)) { return false; }
        if (!(lhs.key_rotation_capability == rhs.key_rotation_capability)) { return false; }
        if (!(lhs.withdraw_events == rhs.withdraw_events)) { return false; }
        if (!(lhs.deposit_events == rhs.deposit_events)) { return false; }
        if (!(lhs.accept_token_events == rhs.accept_token_events)) { return false; }
        if (!(lhs.sequence_number == rhs.sequence_number)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::AccountResource>::serialize(const starcoin_types::AccountResource &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.authentication_key)>::serialize(obj.authentication_key, serializer);
    serde::Serializable<decltype(obj.withdrawal_capability)>::serialize(obj.withdrawal_capability, serializer);
    serde::Serializable<decltype(obj.key_rotation_capability)>::serialize(obj.key_rotation_capability, serializer);
    serde::Serializable<decltype(obj.withdraw_events)>::serialize(obj.withdraw_events, serializer);
    serde::Serializable<decltype(obj.deposit_events)>::serialize(obj.deposit_events, serializer);
    serde::Serializable<decltype(obj.accept_token_events)>::serialize(obj.accept_token_events, serializer);
    serde::Serializable<decltype(obj.sequence_number)>::serialize(obj.sequence_number, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::AccountResource serde::Deserializable<starcoin_types::AccountResource>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::AccountResource obj;
    obj.authentication_key = serde::Deserializable<decltype(obj.authentication_key)>::deserialize(deserializer);
    obj.withdrawal_capability = serde::Deserializable<decltype(obj.withdrawal_capability)>::deserialize(deserializer);
    obj.key_rotation_capability = serde::Deserializable<decltype(obj.key_rotation_capability)>::deserialize(deserializer);
    obj.withdraw_events = serde::Deserializable<decltype(obj.withdraw_events)>::deserialize(deserializer);
    obj.deposit_events = serde::Deserializable<decltype(obj.deposit_events)>::deserialize(deserializer);
    obj.accept_token_events = serde::Deserializable<decltype(obj.accept_token_events)>::deserialize(deserializer);
    obj.sequence_number = serde::Deserializable<decltype(obj.sequence_number)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const ArgumentABI &lhs, const ArgumentABI &rhs) {
        if (!(lhs.name == rhs.name)) { return false; }
        if (!(lhs.type_tag == rhs.type_tag)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::ArgumentABI>::serialize(const starcoin_types::ArgumentABI &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    serde::Serializable<decltype(obj.type_tag)>::serialize(obj.type_tag, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::ArgumentABI serde::Deserializable<starcoin_types::ArgumentABI>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::ArgumentABI obj;
    obj.name = serde::Deserializable<decltype(obj.name)>::deserialize(deserializer);
    obj.type_tag = serde::Deserializable<decltype(obj.type_tag)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const AuthenticationKey &lhs, const AuthenticationKey &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::AuthenticationKey>::serialize(const starcoin_types::AuthenticationKey &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::AuthenticationKey serde::Deserializable<starcoin_types::AuthenticationKey>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::AuthenticationKey obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const BlockMetadata &lhs, const BlockMetadata &rhs) {
        if (!(lhs.parent_hash == rhs.parent_hash)) { return false; }
        if (!(lhs.timestamp == rhs.timestamp)) { return false; }
        if (!(lhs.author == rhs.author)) { return false; }
        if (!(lhs.author_auth_key == rhs.author_auth_key)) { return false; }
        if (!(lhs.uncles == rhs.uncles)) { return false; }
        if (!(lhs.number == rhs.number)) { return false; }
        if (!(lhs.chain_id == rhs.chain_id)) { return false; }
        if (!(lhs.parent_gas_used == rhs.parent_gas_used)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::BlockMetadata>::serialize(const starcoin_types::BlockMetadata &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.parent_hash)>::serialize(obj.parent_hash, serializer);
    serde::Serializable<decltype(obj.timestamp)>::serialize(obj.timestamp, serializer);
    serde::Serializable<decltype(obj.author)>::serialize(obj.author, serializer);
    serde::Serializable<decltype(obj.author_auth_key)>::serialize(obj.author_auth_key, serializer);
    serde::Serializable<decltype(obj.uncles)>::serialize(obj.uncles, serializer);
    serde::Serializable<decltype(obj.number)>::serialize(obj.number, serializer);
    serde::Serializable<decltype(obj.chain_id)>::serialize(obj.chain_id, serializer);
    serde::Serializable<decltype(obj.parent_gas_used)>::serialize(obj.parent_gas_used, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::BlockMetadata serde::Deserializable<starcoin_types::BlockMetadata>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::BlockMetadata obj;
    obj.parent_hash = serde::Deserializable<decltype(obj.parent_hash)>::deserialize(deserializer);
    obj.timestamp = serde::Deserializable<decltype(obj.timestamp)>::deserialize(deserializer);
    obj.author = serde::Deserializable<decltype(obj.author)>::deserialize(deserializer);
    obj.author_auth_key = serde::Deserializable<decltype(obj.author_auth_key)>::deserialize(deserializer);
    obj.uncles = serde::Deserializable<decltype(obj.uncles)>::deserialize(deserializer);
    obj.number = serde::Deserializable<decltype(obj.number)>::deserialize(deserializer);
    obj.chain_id = serde::Deserializable<decltype(obj.chain_id)>::deserialize(deserializer);
    obj.parent_gas_used = serde::Deserializable<decltype(obj.parent_gas_used)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const ChainId &lhs, const ChainId &rhs) {
        if (!(lhs.id == rhs.id)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::ChainId>::serialize(const starcoin_types::ChainId &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.id)>::serialize(obj.id, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::ChainId serde::Deserializable<starcoin_types::ChainId>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::ChainId obj;
    obj.id = serde::Deserializable<decltype(obj.id)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const ContractEvent &lhs, const ContractEvent &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::ContractEvent>::serialize(const starcoin_types::ContractEvent &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::ContractEvent serde::Deserializable<starcoin_types::ContractEvent>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::ContractEvent obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const ContractEvent::V0 &lhs, const ContractEvent::V0 &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::ContractEvent::V0>::serialize(const starcoin_types::ContractEvent::V0 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::ContractEvent::V0 serde::Deserializable<starcoin_types::ContractEvent::V0>::deserialize(Deserializer &deserializer) {
    starcoin_types::ContractEvent::V0 obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const ContractEventV0 &lhs, const ContractEventV0 &rhs) {
        if (!(lhs.key == rhs.key)) { return false; }
        if (!(lhs.sequence_number == rhs.sequence_number)) { return false; }
        if (!(lhs.type_tag == rhs.type_tag)) { return false; }
        if (!(lhs.event_data == rhs.event_data)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::ContractEventV0>::serialize(const starcoin_types::ContractEventV0 &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.key)>::serialize(obj.key, serializer);
    serde::Serializable<decltype(obj.sequence_number)>::serialize(obj.sequence_number, serializer);
    serde::Serializable<decltype(obj.type_tag)>::serialize(obj.type_tag, serializer);
    serde::Serializable<decltype(obj.event_data)>::serialize(obj.event_data, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::ContractEventV0 serde::Deserializable<starcoin_types::ContractEventV0>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::ContractEventV0 obj;
    obj.key = serde::Deserializable<decltype(obj.key)>::deserialize(deserializer);
    obj.sequence_number = serde::Deserializable<decltype(obj.sequence_number)>::deserialize(deserializer);
    obj.type_tag = serde::Deserializable<decltype(obj.type_tag)>::deserialize(deserializer);
    obj.event_data = serde::Deserializable<decltype(obj.event_data)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const DataPath &lhs, const DataPath &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::DataPath>::serialize(const starcoin_types::DataPath &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::DataPath serde::Deserializable<starcoin_types::DataPath>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::DataPath obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const DataPath::Code &lhs, const DataPath::Code &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::DataPath::Code>::serialize(const starcoin_types::DataPath::Code &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::DataPath::Code serde::Deserializable<starcoin_types::DataPath::Code>::deserialize(Deserializer &deserializer) {
    starcoin_types::DataPath::Code obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const DataPath::Resource &lhs, const DataPath::Resource &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::DataPath::Resource>::serialize(const starcoin_types::DataPath::Resource &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::DataPath::Resource serde::Deserializable<starcoin_types::DataPath::Resource>::deserialize(Deserializer &deserializer) {
    starcoin_types::DataPath::Resource obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const DataType &lhs, const DataType &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::DataType>::serialize(const starcoin_types::DataType &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::DataType serde::Deserializable<starcoin_types::DataType>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::DataType obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const DataType::CODE &lhs, const DataType::CODE &rhs) {
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::DataType::CODE>::serialize(const starcoin_types::DataType::CODE &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
starcoin_types::DataType::CODE serde::Deserializable<starcoin_types::DataType::CODE>::deserialize(Deserializer &deserializer) {
    starcoin_types::DataType::CODE obj;
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const DataType::RESOURCE &lhs, const DataType::RESOURCE &rhs) {
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::DataType::RESOURCE>::serialize(const starcoin_types::DataType::RESOURCE &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
starcoin_types::DataType::RESOURCE serde::Deserializable<starcoin_types::DataType::RESOURCE>::deserialize(Deserializer &deserializer) {
    starcoin_types::DataType::RESOURCE obj;
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const Ed25519PrivateKey &lhs, const Ed25519PrivateKey &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::Ed25519PrivateKey>::serialize(const starcoin_types::Ed25519PrivateKey &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::Ed25519PrivateKey serde::Deserializable<starcoin_types::Ed25519PrivateKey>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::Ed25519PrivateKey obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const Ed25519PublicKey &lhs, const Ed25519PublicKey &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::Ed25519PublicKey>::serialize(const starcoin_types::Ed25519PublicKey &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::Ed25519PublicKey serde::Deserializable<starcoin_types::Ed25519PublicKey>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::Ed25519PublicKey obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const Ed25519Signature &lhs, const Ed25519Signature &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::Ed25519Signature>::serialize(const starcoin_types::Ed25519Signature &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::Ed25519Signature serde::Deserializable<starcoin_types::Ed25519Signature>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::Ed25519Signature obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const EventHandle &lhs, const EventHandle &rhs) {
        if (!(lhs.count == rhs.count)) { return false; }
        if (!(lhs.key == rhs.key)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::EventHandle>::serialize(const starcoin_types::EventHandle &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.count)>::serialize(obj.count, serializer);
    serde::Serializable<decltype(obj.key)>::serialize(obj.key, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::EventHandle serde::Deserializable<starcoin_types::EventHandle>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::EventHandle obj;
    obj.count = serde::Deserializable<decltype(obj.count)>::deserialize(deserializer);
    obj.key = serde::Deserializable<decltype(obj.key)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const EventKey &lhs, const EventKey &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::EventKey>::serialize(const starcoin_types::EventKey &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::EventKey serde::Deserializable<starcoin_types::EventKey>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::EventKey obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const HashValue &lhs, const HashValue &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::HashValue>::serialize(const starcoin_types::HashValue &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::HashValue serde::Deserializable<starcoin_types::HashValue>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::HashValue obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const Identifier &lhs, const Identifier &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::Identifier>::serialize(const starcoin_types::Identifier &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::Identifier serde::Deserializable<starcoin_types::Identifier>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::Identifier obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const KeyRotationCapabilityResource &lhs, const KeyRotationCapabilityResource &rhs) {
        if (!(lhs.account_address == rhs.account_address)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::KeyRotationCapabilityResource>::serialize(const starcoin_types::KeyRotationCapabilityResource &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.account_address)>::serialize(obj.account_address, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::KeyRotationCapabilityResource serde::Deserializable<starcoin_types::KeyRotationCapabilityResource>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::KeyRotationCapabilityResource obj;
    obj.account_address = serde::Deserializable<decltype(obj.account_address)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const Module &lhs, const Module &rhs) {
        if (!(lhs.code == rhs.code)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::Module>::serialize(const starcoin_types::Module &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.code)>::serialize(obj.code, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::Module serde::Deserializable<starcoin_types::Module>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::Module obj;
    obj.code = serde::Deserializable<decltype(obj.code)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const ModuleId &lhs, const ModuleId &rhs) {
        if (!(lhs.address == rhs.address)) { return false; }
        if (!(lhs.name == rhs.name)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::ModuleId>::serialize(const starcoin_types::ModuleId &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.address)>::serialize(obj.address, serializer);
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::ModuleId serde::Deserializable<starcoin_types::ModuleId>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::ModuleId obj;
    obj.address = serde::Deserializable<decltype(obj.address)>::deserialize(deserializer);
    obj.name = serde::Deserializable<decltype(obj.name)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const MultiEd25519PrivateKey &lhs, const MultiEd25519PrivateKey &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::MultiEd25519PrivateKey>::serialize(const starcoin_types::MultiEd25519PrivateKey &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::MultiEd25519PrivateKey serde::Deserializable<starcoin_types::MultiEd25519PrivateKey>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::MultiEd25519PrivateKey obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const MultiEd25519PublicKey &lhs, const MultiEd25519PublicKey &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::MultiEd25519PublicKey>::serialize(const starcoin_types::MultiEd25519PublicKey &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::MultiEd25519PublicKey serde::Deserializable<starcoin_types::MultiEd25519PublicKey>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::MultiEd25519PublicKey obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const MultiEd25519Signature &lhs, const MultiEd25519Signature &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::MultiEd25519Signature>::serialize(const starcoin_types::MultiEd25519Signature &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::MultiEd25519Signature serde::Deserializable<starcoin_types::MultiEd25519Signature>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::MultiEd25519Signature obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const Package &lhs, const Package &rhs) {
        if (!(lhs.package_address == rhs.package_address)) { return false; }
        if (!(lhs.modules == rhs.modules)) { return false; }
        if (!(lhs.init_script == rhs.init_script)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::Package>::serialize(const starcoin_types::Package &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.package_address)>::serialize(obj.package_address, serializer);
    serde::Serializable<decltype(obj.modules)>::serialize(obj.modules, serializer);
    serde::Serializable<decltype(obj.init_script)>::serialize(obj.init_script, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::Package serde::Deserializable<starcoin_types::Package>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::Package obj;
    obj.package_address = serde::Deserializable<decltype(obj.package_address)>::deserialize(deserializer);
    obj.modules = serde::Deserializable<decltype(obj.modules)>::deserialize(deserializer);
    obj.init_script = serde::Deserializable<decltype(obj.init_script)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const RawUserTransaction &lhs, const RawUserTransaction &rhs) {
        if (!(lhs.sender == rhs.sender)) { return false; }
        if (!(lhs.sequence_number == rhs.sequence_number)) { return false; }
        if (!(lhs.payload == rhs.payload)) { return false; }
        if (!(lhs.max_gas_amount == rhs.max_gas_amount)) { return false; }
        if (!(lhs.gas_unit_price == rhs.gas_unit_price)) { return false; }
        if (!(lhs.gas_token_code == rhs.gas_token_code)) { return false; }
        if (!(lhs.expiration_timestamp_secs == rhs.expiration_timestamp_secs)) { return false; }
        if (!(lhs.chain_id == rhs.chain_id)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::RawUserTransaction>::serialize(const starcoin_types::RawUserTransaction &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.sender)>::serialize(obj.sender, serializer);
    serde::Serializable<decltype(obj.sequence_number)>::serialize(obj.sequence_number, serializer);
    serde::Serializable<decltype(obj.payload)>::serialize(obj.payload, serializer);
    serde::Serializable<decltype(obj.max_gas_amount)>::serialize(obj.max_gas_amount, serializer);
    serde::Serializable<decltype(obj.gas_unit_price)>::serialize(obj.gas_unit_price, serializer);
    serde::Serializable<decltype(obj.gas_token_code)>::serialize(obj.gas_token_code, serializer);
    serde::Serializable<decltype(obj.expiration_timestamp_secs)>::serialize(obj.expiration_timestamp_secs, serializer);
    serde::Serializable<decltype(obj.chain_id)>::serialize(obj.chain_id, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::RawUserTransaction serde::Deserializable<starcoin_types::RawUserTransaction>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::RawUserTransaction obj;
    obj.sender = serde::Deserializable<decltype(obj.sender)>::deserialize(deserializer);
    obj.sequence_number = serde::Deserializable<decltype(obj.sequence_number)>::deserialize(deserializer);
    obj.payload = serde::Deserializable<decltype(obj.payload)>::deserialize(deserializer);
    obj.max_gas_amount = serde::Deserializable<decltype(obj.max_gas_amount)>::deserialize(deserializer);
    obj.gas_unit_price = serde::Deserializable<decltype(obj.gas_unit_price)>::deserialize(deserializer);
    obj.gas_token_code = serde::Deserializable<decltype(obj.gas_token_code)>::deserialize(deserializer);
    obj.expiration_timestamp_secs = serde::Deserializable<decltype(obj.expiration_timestamp_secs)>::deserialize(deserializer);
    obj.chain_id = serde::Deserializable<decltype(obj.chain_id)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const Script &lhs, const Script &rhs) {
        if (!(lhs.code == rhs.code)) { return false; }
        if (!(lhs.ty_args == rhs.ty_args)) { return false; }
        if (!(lhs.args == rhs.args)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::Script>::serialize(const starcoin_types::Script &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.code)>::serialize(obj.code, serializer);
    serde::Serializable<decltype(obj.ty_args)>::serialize(obj.ty_args, serializer);
    serde::Serializable<decltype(obj.args)>::serialize(obj.args, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::Script serde::Deserializable<starcoin_types::Script>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::Script obj;
    obj.code = serde::Deserializable<decltype(obj.code)>::deserialize(deserializer);
    obj.ty_args = serde::Deserializable<decltype(obj.ty_args)>::deserialize(deserializer);
    obj.args = serde::Deserializable<decltype(obj.args)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const ScriptABI &lhs, const ScriptABI &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::ScriptABI>::serialize(const starcoin_types::ScriptABI &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::ScriptABI serde::Deserializable<starcoin_types::ScriptABI>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::ScriptABI obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const ScriptABI::TransactionScript &lhs, const ScriptABI::TransactionScript &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::ScriptABI::TransactionScript>::serialize(const starcoin_types::ScriptABI::TransactionScript &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::ScriptABI::TransactionScript serde::Deserializable<starcoin_types::ScriptABI::TransactionScript>::deserialize(Deserializer &deserializer) {
    starcoin_types::ScriptABI::TransactionScript obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const ScriptABI::ScriptFunction &lhs, const ScriptABI::ScriptFunction &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::ScriptABI::ScriptFunction>::serialize(const starcoin_types::ScriptABI::ScriptFunction &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::ScriptABI::ScriptFunction serde::Deserializable<starcoin_types::ScriptABI::ScriptFunction>::deserialize(Deserializer &deserializer) {
    starcoin_types::ScriptABI::ScriptFunction obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const ScriptFunction &lhs, const ScriptFunction &rhs) {
        if (!(lhs.module == rhs.module)) { return false; }
        if (!(lhs.function == rhs.function)) { return false; }
        if (!(lhs.ty_args == rhs.ty_args)) { return false; }
        if (!(lhs.args == rhs.args)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::ScriptFunction>::serialize(const starcoin_types::ScriptFunction &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.module)>::serialize(obj.module, serializer);
    serde::Serializable<decltype(obj.function)>::serialize(obj.function, serializer);
    serde::Serializable<decltype(obj.ty_args)>::serialize(obj.ty_args, serializer);
    serde::Serializable<decltype(obj.args)>::serialize(obj.args, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::ScriptFunction serde::Deserializable<starcoin_types::ScriptFunction>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::ScriptFunction obj;
    obj.module = serde::Deserializable<decltype(obj.module)>::deserialize(deserializer);
    obj.function = serde::Deserializable<decltype(obj.function)>::deserialize(deserializer);
    obj.ty_args = serde::Deserializable<decltype(obj.ty_args)>::deserialize(deserializer);
    obj.args = serde::Deserializable<decltype(obj.args)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const ScriptFunctionABI &lhs, const ScriptFunctionABI &rhs) {
        if (!(lhs.name == rhs.name)) { return false; }
        if (!(lhs.module_name == rhs.module_name)) { return false; }
        if (!(lhs.doc == rhs.doc)) { return false; }
        if (!(lhs.ty_args == rhs.ty_args)) { return false; }
        if (!(lhs.args == rhs.args)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::ScriptFunctionABI>::serialize(const starcoin_types::ScriptFunctionABI &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    serde::Serializable<decltype(obj.module_name)>::serialize(obj.module_name, serializer);
    serde::Serializable<decltype(obj.doc)>::serialize(obj.doc, serializer);
    serde::Serializable<decltype(obj.ty_args)>::serialize(obj.ty_args, serializer);
    serde::Serializable<decltype(obj.args)>::serialize(obj.args, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::ScriptFunctionABI serde::Deserializable<starcoin_types::ScriptFunctionABI>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::ScriptFunctionABI obj;
    obj.name = serde::Deserializable<decltype(obj.name)>::deserialize(deserializer);
    obj.module_name = serde::Deserializable<decltype(obj.module_name)>::deserialize(deserializer);
    obj.doc = serde::Deserializable<decltype(obj.doc)>::deserialize(deserializer);
    obj.ty_args = serde::Deserializable<decltype(obj.ty_args)>::deserialize(deserializer);
    obj.args = serde::Deserializable<decltype(obj.args)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const SignedMessage &lhs, const SignedMessage &rhs) {
        if (!(lhs.account == rhs.account)) { return false; }
        if (!(lhs.message == rhs.message)) { return false; }
        if (!(lhs.authenticator == rhs.authenticator)) { return false; }
        if (!(lhs.chain_id == rhs.chain_id)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::SignedMessage>::serialize(const starcoin_types::SignedMessage &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.account)>::serialize(obj.account, serializer);
    serde::Serializable<decltype(obj.message)>::serialize(obj.message, serializer);
    serde::Serializable<decltype(obj.authenticator)>::serialize(obj.authenticator, serializer);
    serde::Serializable<decltype(obj.chain_id)>::serialize(obj.chain_id, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::SignedMessage serde::Deserializable<starcoin_types::SignedMessage>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::SignedMessage obj;
    obj.account = serde::Deserializable<decltype(obj.account)>::deserialize(deserializer);
    obj.message = serde::Deserializable<decltype(obj.message)>::deserialize(deserializer);
    obj.authenticator = serde::Deserializable<decltype(obj.authenticator)>::deserialize(deserializer);
    obj.chain_id = serde::Deserializable<decltype(obj.chain_id)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const SignedUserTransaction &lhs, const SignedUserTransaction &rhs) {
        if (!(lhs.raw_txn == rhs.raw_txn)) { return false; }
        if (!(lhs.authenticator == rhs.authenticator)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::SignedUserTransaction>::serialize(const starcoin_types::SignedUserTransaction &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.raw_txn)>::serialize(obj.raw_txn, serializer);
    serde::Serializable<decltype(obj.authenticator)>::serialize(obj.authenticator, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::SignedUserTransaction serde::Deserializable<starcoin_types::SignedUserTransaction>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::SignedUserTransaction obj;
    obj.raw_txn = serde::Deserializable<decltype(obj.raw_txn)>::deserialize(deserializer);
    obj.authenticator = serde::Deserializable<decltype(obj.authenticator)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const SigningMessage &lhs, const SigningMessage &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::SigningMessage>::serialize(const starcoin_types::SigningMessage &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::SigningMessage serde::Deserializable<starcoin_types::SigningMessage>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::SigningMessage obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const StructTag &lhs, const StructTag &rhs) {
        if (!(lhs.address == rhs.address)) { return false; }
        if (!(lhs.module == rhs.module)) { return false; }
        if (!(lhs.name == rhs.name)) { return false; }
        if (!(lhs.type_args == rhs.type_args)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::StructTag>::serialize(const starcoin_types::StructTag &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.address)>::serialize(obj.address, serializer);
    serde::Serializable<decltype(obj.module)>::serialize(obj.module, serializer);
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    serde::Serializable<decltype(obj.type_args)>::serialize(obj.type_args, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::StructTag serde::Deserializable<starcoin_types::StructTag>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::StructTag obj;
    obj.address = serde::Deserializable<decltype(obj.address)>::deserialize(deserializer);
    obj.module = serde::Deserializable<decltype(obj.module)>::deserialize(deserializer);
    obj.name = serde::Deserializable<decltype(obj.name)>::deserialize(deserializer);
    obj.type_args = serde::Deserializable<decltype(obj.type_args)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const Transaction &lhs, const Transaction &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::Transaction>::serialize(const starcoin_types::Transaction &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::Transaction serde::Deserializable<starcoin_types::Transaction>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::Transaction obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const Transaction::UserTransaction &lhs, const Transaction::UserTransaction &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::Transaction::UserTransaction>::serialize(const starcoin_types::Transaction::UserTransaction &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::Transaction::UserTransaction serde::Deserializable<starcoin_types::Transaction::UserTransaction>::deserialize(Deserializer &deserializer) {
    starcoin_types::Transaction::UserTransaction obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const Transaction::BlockMetadata &lhs, const Transaction::BlockMetadata &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::Transaction::BlockMetadata>::serialize(const starcoin_types::Transaction::BlockMetadata &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::Transaction::BlockMetadata serde::Deserializable<starcoin_types::Transaction::BlockMetadata>::deserialize(Deserializer &deserializer) {
    starcoin_types::Transaction::BlockMetadata obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionArgument &lhs, const TransactionArgument &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionArgument>::serialize(const starcoin_types::TransactionArgument &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::TransactionArgument serde::Deserializable<starcoin_types::TransactionArgument>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::TransactionArgument obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionArgument::U8 &lhs, const TransactionArgument::U8 &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionArgument::U8>::serialize(const starcoin_types::TransactionArgument::U8 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::TransactionArgument::U8 serde::Deserializable<starcoin_types::TransactionArgument::U8>::deserialize(Deserializer &deserializer) {
    starcoin_types::TransactionArgument::U8 obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionArgument::U64 &lhs, const TransactionArgument::U64 &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionArgument::U64>::serialize(const starcoin_types::TransactionArgument::U64 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::TransactionArgument::U64 serde::Deserializable<starcoin_types::TransactionArgument::U64>::deserialize(Deserializer &deserializer) {
    starcoin_types::TransactionArgument::U64 obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionArgument::U128 &lhs, const TransactionArgument::U128 &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionArgument::U128>::serialize(const starcoin_types::TransactionArgument::U128 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::TransactionArgument::U128 serde::Deserializable<starcoin_types::TransactionArgument::U128>::deserialize(Deserializer &deserializer) {
    starcoin_types::TransactionArgument::U128 obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionArgument::Address &lhs, const TransactionArgument::Address &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionArgument::Address>::serialize(const starcoin_types::TransactionArgument::Address &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::TransactionArgument::Address serde::Deserializable<starcoin_types::TransactionArgument::Address>::deserialize(Deserializer &deserializer) {
    starcoin_types::TransactionArgument::Address obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionArgument::U8Vector &lhs, const TransactionArgument::U8Vector &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionArgument::U8Vector>::serialize(const starcoin_types::TransactionArgument::U8Vector &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::TransactionArgument::U8Vector serde::Deserializable<starcoin_types::TransactionArgument::U8Vector>::deserialize(Deserializer &deserializer) {
    starcoin_types::TransactionArgument::U8Vector obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionArgument::Bool &lhs, const TransactionArgument::Bool &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionArgument::Bool>::serialize(const starcoin_types::TransactionArgument::Bool &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::TransactionArgument::Bool serde::Deserializable<starcoin_types::TransactionArgument::Bool>::deserialize(Deserializer &deserializer) {
    starcoin_types::TransactionArgument::Bool obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionAuthenticator &lhs, const TransactionAuthenticator &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionAuthenticator>::serialize(const starcoin_types::TransactionAuthenticator &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::TransactionAuthenticator serde::Deserializable<starcoin_types::TransactionAuthenticator>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::TransactionAuthenticator obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionAuthenticator::Ed25519 &lhs, const TransactionAuthenticator::Ed25519 &rhs) {
        if (!(lhs.public_key == rhs.public_key)) { return false; }
        if (!(lhs.signature == rhs.signature)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionAuthenticator::Ed25519>::serialize(const starcoin_types::TransactionAuthenticator::Ed25519 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.public_key)>::serialize(obj.public_key, serializer);
    serde::Serializable<decltype(obj.signature)>::serialize(obj.signature, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::TransactionAuthenticator::Ed25519 serde::Deserializable<starcoin_types::TransactionAuthenticator::Ed25519>::deserialize(Deserializer &deserializer) {
    starcoin_types::TransactionAuthenticator::Ed25519 obj;
    obj.public_key = serde::Deserializable<decltype(obj.public_key)>::deserialize(deserializer);
    obj.signature = serde::Deserializable<decltype(obj.signature)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionAuthenticator::MultiEd25519 &lhs, const TransactionAuthenticator::MultiEd25519 &rhs) {
        if (!(lhs.public_key == rhs.public_key)) { return false; }
        if (!(lhs.signature == rhs.signature)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionAuthenticator::MultiEd25519>::serialize(const starcoin_types::TransactionAuthenticator::MultiEd25519 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.public_key)>::serialize(obj.public_key, serializer);
    serde::Serializable<decltype(obj.signature)>::serialize(obj.signature, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::TransactionAuthenticator::MultiEd25519 serde::Deserializable<starcoin_types::TransactionAuthenticator::MultiEd25519>::deserialize(Deserializer &deserializer) {
    starcoin_types::TransactionAuthenticator::MultiEd25519 obj;
    obj.public_key = serde::Deserializable<decltype(obj.public_key)>::deserialize(deserializer);
    obj.signature = serde::Deserializable<decltype(obj.signature)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionPayload &lhs, const TransactionPayload &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionPayload>::serialize(const starcoin_types::TransactionPayload &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::TransactionPayload serde::Deserializable<starcoin_types::TransactionPayload>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::TransactionPayload obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionPayload::Script &lhs, const TransactionPayload::Script &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionPayload::Script>::serialize(const starcoin_types::TransactionPayload::Script &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::TransactionPayload::Script serde::Deserializable<starcoin_types::TransactionPayload::Script>::deserialize(Deserializer &deserializer) {
    starcoin_types::TransactionPayload::Script obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionPayload::Package &lhs, const TransactionPayload::Package &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionPayload::Package>::serialize(const starcoin_types::TransactionPayload::Package &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::TransactionPayload::Package serde::Deserializable<starcoin_types::TransactionPayload::Package>::deserialize(Deserializer &deserializer) {
    starcoin_types::TransactionPayload::Package obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionPayload::ScriptFunction &lhs, const TransactionPayload::ScriptFunction &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionPayload::ScriptFunction>::serialize(const starcoin_types::TransactionPayload::ScriptFunction &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::TransactionPayload::ScriptFunction serde::Deserializable<starcoin_types::TransactionPayload::ScriptFunction>::deserialize(Deserializer &deserializer) {
    starcoin_types::TransactionPayload::ScriptFunction obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TransactionScriptABI &lhs, const TransactionScriptABI &rhs) {
        if (!(lhs.name == rhs.name)) { return false; }
        if (!(lhs.doc == rhs.doc)) { return false; }
        if (!(lhs.code == rhs.code)) { return false; }
        if (!(lhs.ty_args == rhs.ty_args)) { return false; }
        if (!(lhs.args == rhs.args)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TransactionScriptABI>::serialize(const starcoin_types::TransactionScriptABI &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    serde::Serializable<decltype(obj.doc)>::serialize(obj.doc, serializer);
    serde::Serializable<decltype(obj.code)>::serialize(obj.code, serializer);
    serde::Serializable<decltype(obj.ty_args)>::serialize(obj.ty_args, serializer);
    serde::Serializable<decltype(obj.args)>::serialize(obj.args, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::TransactionScriptABI serde::Deserializable<starcoin_types::TransactionScriptABI>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::TransactionScriptABI obj;
    obj.name = serde::Deserializable<decltype(obj.name)>::deserialize(deserializer);
    obj.doc = serde::Deserializable<decltype(obj.doc)>::deserialize(deserializer);
    obj.code = serde::Deserializable<decltype(obj.code)>::deserialize(deserializer);
    obj.ty_args = serde::Deserializable<decltype(obj.ty_args)>::deserialize(deserializer);
    obj.args = serde::Deserializable<decltype(obj.args)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TypeArgumentABI &lhs, const TypeArgumentABI &rhs) {
        if (!(lhs.name == rhs.name)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TypeArgumentABI>::serialize(const starcoin_types::TypeArgumentABI &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::TypeArgumentABI serde::Deserializable<starcoin_types::TypeArgumentABI>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::TypeArgumentABI obj;
    obj.name = serde::Deserializable<decltype(obj.name)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TypeTag &lhs, const TypeTag &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TypeTag>::serialize(const starcoin_types::TypeTag &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::TypeTag serde::Deserializable<starcoin_types::TypeTag>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::TypeTag obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TypeTag::Bool &lhs, const TypeTag::Bool &rhs) {
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TypeTag::Bool>::serialize(const starcoin_types::TypeTag::Bool &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
starcoin_types::TypeTag::Bool serde::Deserializable<starcoin_types::TypeTag::Bool>::deserialize(Deserializer &deserializer) {
    starcoin_types::TypeTag::Bool obj;
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TypeTag::U8 &lhs, const TypeTag::U8 &rhs) {
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TypeTag::U8>::serialize(const starcoin_types::TypeTag::U8 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
starcoin_types::TypeTag::U8 serde::Deserializable<starcoin_types::TypeTag::U8>::deserialize(Deserializer &deserializer) {
    starcoin_types::TypeTag::U8 obj;
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TypeTag::U64 &lhs, const TypeTag::U64 &rhs) {
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TypeTag::U64>::serialize(const starcoin_types::TypeTag::U64 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
starcoin_types::TypeTag::U64 serde::Deserializable<starcoin_types::TypeTag::U64>::deserialize(Deserializer &deserializer) {
    starcoin_types::TypeTag::U64 obj;
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TypeTag::U128 &lhs, const TypeTag::U128 &rhs) {
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TypeTag::U128>::serialize(const starcoin_types::TypeTag::U128 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
starcoin_types::TypeTag::U128 serde::Deserializable<starcoin_types::TypeTag::U128>::deserialize(Deserializer &deserializer) {
    starcoin_types::TypeTag::U128 obj;
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TypeTag::Address &lhs, const TypeTag::Address &rhs) {
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TypeTag::Address>::serialize(const starcoin_types::TypeTag::Address &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
starcoin_types::TypeTag::Address serde::Deserializable<starcoin_types::TypeTag::Address>::deserialize(Deserializer &deserializer) {
    starcoin_types::TypeTag::Address obj;
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TypeTag::Signer &lhs, const TypeTag::Signer &rhs) {
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TypeTag::Signer>::serialize(const starcoin_types::TypeTag::Signer &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
starcoin_types::TypeTag::Signer serde::Deserializable<starcoin_types::TypeTag::Signer>::deserialize(Deserializer &deserializer) {
    starcoin_types::TypeTag::Signer obj;
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TypeTag::Vector &lhs, const TypeTag::Vector &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TypeTag::Vector>::serialize(const starcoin_types::TypeTag::Vector &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::TypeTag::Vector serde::Deserializable<starcoin_types::TypeTag::Vector>::deserialize(Deserializer &deserializer) {
    starcoin_types::TypeTag::Vector obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const TypeTag::Struct &lhs, const TypeTag::Struct &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::TypeTag::Struct>::serialize(const starcoin_types::TypeTag::Struct &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::TypeTag::Struct serde::Deserializable<starcoin_types::TypeTag::Struct>::deserialize(Deserializer &deserializer) {
    starcoin_types::TypeTag::Struct obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const WithdrawCapabilityResource &lhs, const WithdrawCapabilityResource &rhs) {
        if (!(lhs.account_address == rhs.account_address)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::WithdrawCapabilityResource>::serialize(const starcoin_types::WithdrawCapabilityResource &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.account_address)>::serialize(obj.account_address, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::WithdrawCapabilityResource serde::Deserializable<starcoin_types::WithdrawCapabilityResource>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::WithdrawCapabilityResource obj;
    obj.account_address = serde::Deserializable<decltype(obj.account_address)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const WriteOp &lhs, const WriteOp &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::WriteOp>::serialize(const starcoin_types::WriteOp &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::WriteOp serde::Deserializable<starcoin_types::WriteOp>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::WriteOp obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const WriteOp::Deletion &lhs, const WriteOp::Deletion &rhs) {
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::WriteOp::Deletion>::serialize(const starcoin_types::WriteOp::Deletion &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
starcoin_types::WriteOp::Deletion serde::Deserializable<starcoin_types::WriteOp::Deletion>::deserialize(Deserializer &deserializer) {
    starcoin_types::WriteOp::Deletion obj;
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const WriteOp::Value &lhs, const WriteOp::Value &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::WriteOp::Value>::serialize(const starcoin_types::WriteOp::Value &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
starcoin_types::WriteOp::Value serde::Deserializable<starcoin_types::WriteOp::Value>::deserialize(Deserializer &deserializer) {
    starcoin_types::WriteOp::Value obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const WriteSet &lhs, const WriteSet &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::WriteSet>::serialize(const starcoin_types::WriteSet &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::WriteSet serde::Deserializable<starcoin_types::WriteSet>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::WriteSet obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace starcoin_types {

    inline bool operator==(const WriteSetMut &lhs, const WriteSetMut &rhs) {
        if (!(lhs.write_set == rhs.write_set)) { return false; }
        return true;
    }

} // end of namespace starcoin_types

template <>
template <typename Serializer>
void serde::Serializable<starcoin_types::WriteSetMut>::serialize(const starcoin_types::WriteSetMut &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.write_set)>::serialize(obj.write_set, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
starcoin_types::WriteSetMut serde::Deserializable<starcoin_types::WriteSetMut>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    starcoin_types::WriteSetMut obj;
    obj.write_set = serde::Deserializable<decltype(obj.write_set)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}
