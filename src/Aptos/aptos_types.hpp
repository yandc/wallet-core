#pragma once

#include "serde.hpp"

namespace aptos_types {

    struct AccountAddress {
        std::array<uint8_t, 32> value;

        friend bool operator==(const AccountAddress&, const AccountAddress&);
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

    struct AccountAuthenticator {

        struct Ed25519 {
            aptos_types::Ed25519PublicKey public_key;
            aptos_types::Ed25519Signature signature;

            friend bool operator==(const Ed25519&, const Ed25519&);
        };

        struct MultiEd25519 {
            aptos_types::MultiEd25519PublicKey public_key;
            aptos_types::MultiEd25519Signature signature;

            friend bool operator==(const MultiEd25519&, const MultiEd25519&);
        };

        std::variant<Ed25519, MultiEd25519> value;

        friend bool operator==(const AccountAuthenticator&, const AccountAuthenticator&);
    };

    struct TransactionAuthenticator {

        struct Ed25519 {
            aptos_types::Ed25519PublicKey public_key;
            aptos_types::Ed25519Signature signature;

            friend bool operator==(const Ed25519&, const Ed25519&);
        };

        struct MultiEd25519 {
            aptos_types::MultiEd25519PublicKey public_key;
            aptos_types::MultiEd25519Signature signature;

            friend bool operator==(const MultiEd25519&, const MultiEd25519&);
        };

        struct MultiAgent {
            aptos_types::AccountAuthenticator sender;
            std::vector<aptos_types::AccountAddress> secondary_signer_addresses;
            std::vector<aptos_types::AccountAuthenticator> secondary_signers;

            friend bool operator==(const MultiAgent&, const MultiAgent&);
        };

        std::variant<Ed25519, MultiEd25519, MultiAgent> value;

        friend bool operator==(const TransactionAuthenticator&, const TransactionAuthenticator&);
    };

    struct HashValue {
        std::array<uint8_t, 32> hash;

        friend bool operator==(const HashValue&, const HashValue&);
    };

    struct BlockMetadata {
        aptos_types::HashValue id;
        uint64_t epoch;
        uint64_t round;
        aptos_types::AccountAddress proposer;
        std::vector<uint8_t> previous_block_votes_bitvec;
        std::vector<uint32_t> failed_proposer_indices;
        uint64_t timestamp_usecs;

        friend bool operator==(const BlockMetadata&, const BlockMetadata&);
    };

    struct ChainId {
        uint8_t value;

        friend bool operator==(const ChainId&, const ChainId&);
    };

    struct Module {
        std::vector<uint8_t> code;

        friend bool operator==(const Module&, const Module&);
    };

    struct ModuleBundle {
        std::vector<aptos_types::Module> codes;

        friend bool operator==(const ModuleBundle&, const ModuleBundle&);
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
            aptos_types::AccountAddress value;

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

    struct Identifier {
        std::string value;

        friend bool operator==(const Identifier&, const Identifier&);
    };

    struct TypeTag;

    struct StructTag {
        aptos_types::AccountAddress address;
        aptos_types::Identifier module;
        aptos_types::Identifier name;
        std::vector<aptos_types::TypeTag> type_args;

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
            serde::value_ptr<aptos_types::TypeTag> value;

            friend bool operator==(const Vector&, const Vector&);
        };

        struct Struct {
            aptos_types::StructTag value;

            friend bool operator==(const Struct&, const Struct&);
        };

        std::variant<Bool, U8, U64, U128, Address, Signer, Vector, Struct> value;

        friend bool operator==(const TypeTag&, const TypeTag&);
    };

    struct Script {
        std::vector<uint8_t> code;
        std::vector<aptos_types::TypeTag> ty_args;
        std::vector<aptos_types::TransactionArgument> args;

        friend bool operator==(const Script&, const Script&);
    };

    struct ModuleId {
        aptos_types::AccountAddress address;
        aptos_types::Identifier name;

        friend bool operator==(const ModuleId&, const ModuleId&);
    };

    struct ScriptFunction {
        aptos_types::ModuleId module;
        aptos_types::Identifier function;
        std::vector<aptos_types::TypeTag> ty_args;
        std::vector<std::vector<uint8_t>> args;

        friend bool operator==(const ScriptFunction&, const ScriptFunction&);
    };

    struct TransactionPayload {

        struct Script {
            aptos_types::Script value;

            friend bool operator==(const Script&, const Script&);
        };

        struct ModuleBundle {
            aptos_types::ModuleBundle value;

            friend bool operator==(const ModuleBundle&, const ModuleBundle&);
        };

        struct ScriptFunction {
            aptos_types::ScriptFunction value;

            friend bool operator==(const ScriptFunction&, const ScriptFunction&);
        };

        std::variant<Script, ModuleBundle, ScriptFunction> value;

        friend bool operator==(const TransactionPayload&, const TransactionPayload&);
    };

    struct RawTransaction {
        aptos_types::AccountAddress sender;
        uint64_t sequence_number;
        aptos_types::TransactionPayload payload;
        uint64_t max_gas_amount;
        uint64_t gas_unit_price;
        uint64_t expiration_timestamp_secs;
        aptos_types::ChainId chain_id;

        friend bool operator==(const RawTransaction&, const RawTransaction&);
    };

    struct SignedTransaction {
        aptos_types::RawTransaction raw_txn;
        aptos_types::TransactionAuthenticator authenticator;

        friend bool operator==(const SignedTransaction&, const SignedTransaction&);
    };

    struct EventKey {
        uint64_t creation_number;
        aptos_types::AccountAddress account_address;

        friend bool operator==(const EventKey&, const EventKey&);
    };

    struct ContractEventV0 {
        aptos_types::EventKey key;
        uint64_t sequence_number;
        aptos_types::TypeTag type_tag;
        std::vector<uint8_t> event_data;

        friend bool operator==(const ContractEventV0&, const ContractEventV0&);
    };

    struct ContractEvent {

        struct V0 {
            aptos_types::ContractEventV0 value;

            friend bool operator==(const V0&, const V0&);
        };

        std::variant<V0> value;

        friend bool operator==(const ContractEvent&, const ContractEvent&);
    };

    struct AccessPath {
        aptos_types::AccountAddress address;
        std::vector<uint8_t> path;

        friend bool operator==(const AccessPath&, const AccessPath&);
    };

    struct TableHandle {
        serde::uint128_t value;

        friend bool operator==(const TableHandle&, const TableHandle&);
    };

    struct StateKey {

        struct AccessPath {
            aptos_types::AccessPath value;

            friend bool operator==(const AccessPath&, const AccessPath&);
        };

        struct TableItem {
            aptos_types::TableHandle handle;
            std::vector<uint8_t> key;

            friend bool operator==(const TableItem&, const TableItem&);
        };

        struct Raw {
            std::vector<uint8_t> value;

            friend bool operator==(const Raw&, const Raw&);
        };

        std::variant<AccessPath, TableItem, Raw> value;

        friend bool operator==(const StateKey&, const StateKey&);
    };

    struct WriteOp {

        struct Creation {
            std::vector<uint8_t> value;

            friend bool operator==(const Creation&, const Creation&);
        };

        struct Modification {
            std::vector<uint8_t> value;

            friend bool operator==(const Modification&, const Modification&);
        };

        struct Deletion {
            friend bool operator==(const Deletion&, const Deletion&);
        };

        std::variant<Creation, Modification, Deletion> value;

        friend bool operator==(const WriteOp&, const WriteOp&);
    };

    struct WriteSetMut {
        std::vector<std::tuple<aptos_types::StateKey, aptos_types::WriteOp>> write_set;

        friend bool operator==(const WriteSetMut&, const WriteSetMut&);
    };

    struct WriteSetV0 {
        aptos_types::WriteSetMut value;

        friend bool operator==(const WriteSetV0&, const WriteSetV0&);
    };

    struct WriteSet {

        struct V0 {
            aptos_types::WriteSetV0 value;

            friend bool operator==(const V0&, const V0&);
        };

        std::variant<V0> value;

        friend bool operator==(const WriteSet&, const WriteSet&);
    };

    struct ChangeSet {
        aptos_types::WriteSet write_set;
        std::vector<aptos_types::ContractEvent> events;

        friend bool operator==(const ChangeSet&, const ChangeSet&);
    };

    struct WriteSetPayload {

        struct Direct {
            aptos_types::ChangeSet value;

            friend bool operator==(const Direct&, const Direct&);
        };

        struct Script {
            aptos_types::AccountAddress execute_as;
            aptos_types::Script script;

            friend bool operator==(const Script&, const Script&);
        };

        std::variant<Direct, Script> value;

        friend bool operator==(const WriteSetPayload&, const WriteSetPayload&);
    };

    struct Transaction {

        struct UserTransaction {
            aptos_types::SignedTransaction value;

            friend bool operator==(const UserTransaction&, const UserTransaction&);
        };

        struct GenesisTransaction {
            aptos_types::WriteSetPayload value;

            friend bool operator==(const GenesisTransaction&, const GenesisTransaction&);
        };

        struct BlockMetadata {
            aptos_types::BlockMetadata value;

            friend bool operator==(const BlockMetadata&, const BlockMetadata&);
        };

        struct StateCheckpoint {
            aptos_types::HashValue value;

            friend bool operator==(const StateCheckpoint&, const StateCheckpoint&);
        };

        std::variant<UserTransaction, GenesisTransaction, BlockMetadata, StateCheckpoint> value;

        friend bool operator==(const Transaction&, const Transaction&);
    };

} // end of namespace aptos_types


namespace aptos_types {

    inline bool operator==(const AccessPath &lhs, const AccessPath &rhs) {
        if (!(lhs.address == rhs.address)) { return false; }
        if (!(lhs.path == rhs.path)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::AccessPath>::serialize(const aptos_types::AccessPath &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.address)>::serialize(obj.address, serializer);
    serde::Serializable<decltype(obj.path)>::serialize(obj.path, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::AccessPath serde::Deserializable<aptos_types::AccessPath>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::AccessPath obj;
    obj.address = serde::Deserializable<decltype(obj.address)>::deserialize(deserializer);
    obj.path = serde::Deserializable<decltype(obj.path)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const AccountAddress &lhs, const AccountAddress &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::AccountAddress>::serialize(const aptos_types::AccountAddress &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::AccountAddress serde::Deserializable<aptos_types::AccountAddress>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::AccountAddress obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const AccountAuthenticator &lhs, const AccountAuthenticator &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::AccountAuthenticator>::serialize(const aptos_types::AccountAuthenticator &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::AccountAuthenticator serde::Deserializable<aptos_types::AccountAuthenticator>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::AccountAuthenticator obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const AccountAuthenticator::Ed25519 &lhs, const AccountAuthenticator::Ed25519 &rhs) {
        if (!(lhs.public_key == rhs.public_key)) { return false; }
        if (!(lhs.signature == rhs.signature)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::AccountAuthenticator::Ed25519>::serialize(const aptos_types::AccountAuthenticator::Ed25519 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.public_key)>::serialize(obj.public_key, serializer);
    serde::Serializable<decltype(obj.signature)>::serialize(obj.signature, serializer);
}

template <>
template <typename Deserializer>
aptos_types::AccountAuthenticator::Ed25519 serde::Deserializable<aptos_types::AccountAuthenticator::Ed25519>::deserialize(Deserializer &deserializer) {
    aptos_types::AccountAuthenticator::Ed25519 obj;
    obj.public_key = serde::Deserializable<decltype(obj.public_key)>::deserialize(deserializer);
    obj.signature = serde::Deserializable<decltype(obj.signature)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const AccountAuthenticator::MultiEd25519 &lhs, const AccountAuthenticator::MultiEd25519 &rhs) {
        if (!(lhs.public_key == rhs.public_key)) { return false; }
        if (!(lhs.signature == rhs.signature)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::AccountAuthenticator::MultiEd25519>::serialize(const aptos_types::AccountAuthenticator::MultiEd25519 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.public_key)>::serialize(obj.public_key, serializer);
    serde::Serializable<decltype(obj.signature)>::serialize(obj.signature, serializer);
}

template <>
template <typename Deserializer>
aptos_types::AccountAuthenticator::MultiEd25519 serde::Deserializable<aptos_types::AccountAuthenticator::MultiEd25519>::deserialize(Deserializer &deserializer) {
    aptos_types::AccountAuthenticator::MultiEd25519 obj;
    obj.public_key = serde::Deserializable<decltype(obj.public_key)>::deserialize(deserializer);
    obj.signature = serde::Deserializable<decltype(obj.signature)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const BlockMetadata &lhs, const BlockMetadata &rhs) {
        if (!(lhs.id == rhs.id)) { return false; }
        if (!(lhs.epoch == rhs.epoch)) { return false; }
        if (!(lhs.round == rhs.round)) { return false; }
        if (!(lhs.proposer == rhs.proposer)) { return false; }
        if (!(lhs.previous_block_votes_bitvec == rhs.previous_block_votes_bitvec)) { return false; }
        if (!(lhs.failed_proposer_indices == rhs.failed_proposer_indices)) { return false; }
        if (!(lhs.timestamp_usecs == rhs.timestamp_usecs)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::BlockMetadata>::serialize(const aptos_types::BlockMetadata &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.id)>::serialize(obj.id, serializer);
    serde::Serializable<decltype(obj.epoch)>::serialize(obj.epoch, serializer);
    serde::Serializable<decltype(obj.round)>::serialize(obj.round, serializer);
    serde::Serializable<decltype(obj.proposer)>::serialize(obj.proposer, serializer);
    serde::Serializable<decltype(obj.previous_block_votes_bitvec)>::serialize(obj.previous_block_votes_bitvec, serializer);
    serde::Serializable<decltype(obj.failed_proposer_indices)>::serialize(obj.failed_proposer_indices, serializer);
    serde::Serializable<decltype(obj.timestamp_usecs)>::serialize(obj.timestamp_usecs, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::BlockMetadata serde::Deserializable<aptos_types::BlockMetadata>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::BlockMetadata obj;
    obj.id = serde::Deserializable<decltype(obj.id)>::deserialize(deserializer);
    obj.epoch = serde::Deserializable<decltype(obj.epoch)>::deserialize(deserializer);
    obj.round = serde::Deserializable<decltype(obj.round)>::deserialize(deserializer);
    obj.proposer = serde::Deserializable<decltype(obj.proposer)>::deserialize(deserializer);
    obj.previous_block_votes_bitvec = serde::Deserializable<decltype(obj.previous_block_votes_bitvec)>::deserialize(deserializer);
    obj.failed_proposer_indices = serde::Deserializable<decltype(obj.failed_proposer_indices)>::deserialize(deserializer);
    obj.timestamp_usecs = serde::Deserializable<decltype(obj.timestamp_usecs)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const ChainId &lhs, const ChainId &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::ChainId>::serialize(const aptos_types::ChainId &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::ChainId serde::Deserializable<aptos_types::ChainId>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::ChainId obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const ChangeSet &lhs, const ChangeSet &rhs) {
        if (!(lhs.write_set == rhs.write_set)) { return false; }
        if (!(lhs.events == rhs.events)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::ChangeSet>::serialize(const aptos_types::ChangeSet &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.write_set)>::serialize(obj.write_set, serializer);
    serde::Serializable<decltype(obj.events)>::serialize(obj.events, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::ChangeSet serde::Deserializable<aptos_types::ChangeSet>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::ChangeSet obj;
    obj.write_set = serde::Deserializable<decltype(obj.write_set)>::deserialize(deserializer);
    obj.events = serde::Deserializable<decltype(obj.events)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const ContractEvent &lhs, const ContractEvent &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::ContractEvent>::serialize(const aptos_types::ContractEvent &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::ContractEvent serde::Deserializable<aptos_types::ContractEvent>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::ContractEvent obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const ContractEvent::V0 &lhs, const ContractEvent::V0 &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::ContractEvent::V0>::serialize(const aptos_types::ContractEvent::V0 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::ContractEvent::V0 serde::Deserializable<aptos_types::ContractEvent::V0>::deserialize(Deserializer &deserializer) {
    aptos_types::ContractEvent::V0 obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const ContractEventV0 &lhs, const ContractEventV0 &rhs) {
        if (!(lhs.key == rhs.key)) { return false; }
        if (!(lhs.sequence_number == rhs.sequence_number)) { return false; }
        if (!(lhs.type_tag == rhs.type_tag)) { return false; }
        if (!(lhs.event_data == rhs.event_data)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::ContractEventV0>::serialize(const aptos_types::ContractEventV0 &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.key)>::serialize(obj.key, serializer);
    serde::Serializable<decltype(obj.sequence_number)>::serialize(obj.sequence_number, serializer);
    serde::Serializable<decltype(obj.type_tag)>::serialize(obj.type_tag, serializer);
    serde::Serializable<decltype(obj.event_data)>::serialize(obj.event_data, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::ContractEventV0 serde::Deserializable<aptos_types::ContractEventV0>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::ContractEventV0 obj;
    obj.key = serde::Deserializable<decltype(obj.key)>::deserialize(deserializer);
    obj.sequence_number = serde::Deserializable<decltype(obj.sequence_number)>::deserialize(deserializer);
    obj.type_tag = serde::Deserializable<decltype(obj.type_tag)>::deserialize(deserializer);
    obj.event_data = serde::Deserializable<decltype(obj.event_data)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const Ed25519PublicKey &lhs, const Ed25519PublicKey &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::Ed25519PublicKey>::serialize(const aptos_types::Ed25519PublicKey &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::Ed25519PublicKey serde::Deserializable<aptos_types::Ed25519PublicKey>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::Ed25519PublicKey obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const Ed25519Signature &lhs, const Ed25519Signature &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::Ed25519Signature>::serialize(const aptos_types::Ed25519Signature &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::Ed25519Signature serde::Deserializable<aptos_types::Ed25519Signature>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::Ed25519Signature obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const EventKey &lhs, const EventKey &rhs) {
        if (!(lhs.creation_number == rhs.creation_number)) { return false; }
        if (!(lhs.account_address == rhs.account_address)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::EventKey>::serialize(const aptos_types::EventKey &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.creation_number)>::serialize(obj.creation_number, serializer);
    serde::Serializable<decltype(obj.account_address)>::serialize(obj.account_address, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::EventKey serde::Deserializable<aptos_types::EventKey>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::EventKey obj;
    obj.creation_number = serde::Deserializable<decltype(obj.creation_number)>::deserialize(deserializer);
    obj.account_address = serde::Deserializable<decltype(obj.account_address)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const HashValue &lhs, const HashValue &rhs) {
        if (!(lhs.hash == rhs.hash)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::HashValue>::serialize(const aptos_types::HashValue &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.hash)>::serialize(obj.hash, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::HashValue serde::Deserializable<aptos_types::HashValue>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::HashValue obj;
    obj.hash = serde::Deserializable<decltype(obj.hash)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const Identifier &lhs, const Identifier &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::Identifier>::serialize(const aptos_types::Identifier &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::Identifier serde::Deserializable<aptos_types::Identifier>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::Identifier obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const Module &lhs, const Module &rhs) {
        if (!(lhs.code == rhs.code)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::Module>::serialize(const aptos_types::Module &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.code)>::serialize(obj.code, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::Module serde::Deserializable<aptos_types::Module>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::Module obj;
    obj.code = serde::Deserializable<decltype(obj.code)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const ModuleBundle &lhs, const ModuleBundle &rhs) {
        if (!(lhs.codes == rhs.codes)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::ModuleBundle>::serialize(const aptos_types::ModuleBundle &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.codes)>::serialize(obj.codes, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::ModuleBundle serde::Deserializable<aptos_types::ModuleBundle>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::ModuleBundle obj;
    obj.codes = serde::Deserializable<decltype(obj.codes)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const ModuleId &lhs, const ModuleId &rhs) {
        if (!(lhs.address == rhs.address)) { return false; }
        if (!(lhs.name == rhs.name)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::ModuleId>::serialize(const aptos_types::ModuleId &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.address)>::serialize(obj.address, serializer);
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::ModuleId serde::Deserializable<aptos_types::ModuleId>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::ModuleId obj;
    obj.address = serde::Deserializable<decltype(obj.address)>::deserialize(deserializer);
    obj.name = serde::Deserializable<decltype(obj.name)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const MultiEd25519PublicKey &lhs, const MultiEd25519PublicKey &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::MultiEd25519PublicKey>::serialize(const aptos_types::MultiEd25519PublicKey &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::MultiEd25519PublicKey serde::Deserializable<aptos_types::MultiEd25519PublicKey>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::MultiEd25519PublicKey obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const MultiEd25519Signature &lhs, const MultiEd25519Signature &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::MultiEd25519Signature>::serialize(const aptos_types::MultiEd25519Signature &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::MultiEd25519Signature serde::Deserializable<aptos_types::MultiEd25519Signature>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::MultiEd25519Signature obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const RawTransaction &lhs, const RawTransaction &rhs) {
        if (!(lhs.sender == rhs.sender)) { return false; }
        if (!(lhs.sequence_number == rhs.sequence_number)) { return false; }
        if (!(lhs.payload == rhs.payload)) { return false; }
        if (!(lhs.max_gas_amount == rhs.max_gas_amount)) { return false; }
        if (!(lhs.gas_unit_price == rhs.gas_unit_price)) { return false; }
        if (!(lhs.expiration_timestamp_secs == rhs.expiration_timestamp_secs)) { return false; }
        if (!(lhs.chain_id == rhs.chain_id)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::RawTransaction>::serialize(const aptos_types::RawTransaction &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.sender)>::serialize(obj.sender, serializer);
    serde::Serializable<decltype(obj.sequence_number)>::serialize(obj.sequence_number, serializer);
    serde::Serializable<decltype(obj.payload)>::serialize(obj.payload, serializer);
    serde::Serializable<decltype(obj.max_gas_amount)>::serialize(obj.max_gas_amount, serializer);
    serde::Serializable<decltype(obj.gas_unit_price)>::serialize(obj.gas_unit_price, serializer);
    serde::Serializable<decltype(obj.expiration_timestamp_secs)>::serialize(obj.expiration_timestamp_secs, serializer);
    serde::Serializable<decltype(obj.chain_id)>::serialize(obj.chain_id, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::RawTransaction serde::Deserializable<aptos_types::RawTransaction>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::RawTransaction obj;
    obj.sender = serde::Deserializable<decltype(obj.sender)>::deserialize(deserializer);
    obj.sequence_number = serde::Deserializable<decltype(obj.sequence_number)>::deserialize(deserializer);
    obj.payload = serde::Deserializable<decltype(obj.payload)>::deserialize(deserializer);
    obj.max_gas_amount = serde::Deserializable<decltype(obj.max_gas_amount)>::deserialize(deserializer);
    obj.gas_unit_price = serde::Deserializable<decltype(obj.gas_unit_price)>::deserialize(deserializer);
    obj.expiration_timestamp_secs = serde::Deserializable<decltype(obj.expiration_timestamp_secs)>::deserialize(deserializer);
    obj.chain_id = serde::Deserializable<decltype(obj.chain_id)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const Script &lhs, const Script &rhs) {
        if (!(lhs.code == rhs.code)) { return false; }
        if (!(lhs.ty_args == rhs.ty_args)) { return false; }
        if (!(lhs.args == rhs.args)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::Script>::serialize(const aptos_types::Script &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.code)>::serialize(obj.code, serializer);
    serde::Serializable<decltype(obj.ty_args)>::serialize(obj.ty_args, serializer);
    serde::Serializable<decltype(obj.args)>::serialize(obj.args, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::Script serde::Deserializable<aptos_types::Script>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::Script obj;
    obj.code = serde::Deserializable<decltype(obj.code)>::deserialize(deserializer);
    obj.ty_args = serde::Deserializable<decltype(obj.ty_args)>::deserialize(deserializer);
    obj.args = serde::Deserializable<decltype(obj.args)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const ScriptFunction &lhs, const ScriptFunction &rhs) {
        if (!(lhs.module == rhs.module)) { return false; }
        if (!(lhs.function == rhs.function)) { return false; }
        if (!(lhs.ty_args == rhs.ty_args)) { return false; }
        if (!(lhs.args == rhs.args)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::ScriptFunction>::serialize(const aptos_types::ScriptFunction &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.module)>::serialize(obj.module, serializer);
    serde::Serializable<decltype(obj.function)>::serialize(obj.function, serializer);
    serde::Serializable<decltype(obj.ty_args)>::serialize(obj.ty_args, serializer);
    serde::Serializable<decltype(obj.args)>::serialize(obj.args, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::ScriptFunction serde::Deserializable<aptos_types::ScriptFunction>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::ScriptFunction obj;
    obj.module = serde::Deserializable<decltype(obj.module)>::deserialize(deserializer);
    obj.function = serde::Deserializable<decltype(obj.function)>::deserialize(deserializer);
    obj.ty_args = serde::Deserializable<decltype(obj.ty_args)>::deserialize(deserializer);
    obj.args = serde::Deserializable<decltype(obj.args)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const SignedTransaction &lhs, const SignedTransaction &rhs) {
        if (!(lhs.raw_txn == rhs.raw_txn)) { return false; }
        if (!(lhs.authenticator == rhs.authenticator)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::SignedTransaction>::serialize(const aptos_types::SignedTransaction &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.raw_txn)>::serialize(obj.raw_txn, serializer);
    serde::Serializable<decltype(obj.authenticator)>::serialize(obj.authenticator, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::SignedTransaction serde::Deserializable<aptos_types::SignedTransaction>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::SignedTransaction obj;
    obj.raw_txn = serde::Deserializable<decltype(obj.raw_txn)>::deserialize(deserializer);
    obj.authenticator = serde::Deserializable<decltype(obj.authenticator)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const StateKey &lhs, const StateKey &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::StateKey>::serialize(const aptos_types::StateKey &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::StateKey serde::Deserializable<aptos_types::StateKey>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::StateKey obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const StateKey::AccessPath &lhs, const StateKey::AccessPath &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::StateKey::AccessPath>::serialize(const aptos_types::StateKey::AccessPath &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::StateKey::AccessPath serde::Deserializable<aptos_types::StateKey::AccessPath>::deserialize(Deserializer &deserializer) {
    aptos_types::StateKey::AccessPath obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const StateKey::TableItem &lhs, const StateKey::TableItem &rhs) {
        if (!(lhs.handle == rhs.handle)) { return false; }
        if (!(lhs.key == rhs.key)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::StateKey::TableItem>::serialize(const aptos_types::StateKey::TableItem &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.handle)>::serialize(obj.handle, serializer);
    serde::Serializable<decltype(obj.key)>::serialize(obj.key, serializer);
}

template <>
template <typename Deserializer>
aptos_types::StateKey::TableItem serde::Deserializable<aptos_types::StateKey::TableItem>::deserialize(Deserializer &deserializer) {
    aptos_types::StateKey::TableItem obj;
    obj.handle = serde::Deserializable<decltype(obj.handle)>::deserialize(deserializer);
    obj.key = serde::Deserializable<decltype(obj.key)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const StateKey::Raw &lhs, const StateKey::Raw &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::StateKey::Raw>::serialize(const aptos_types::StateKey::Raw &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::StateKey::Raw serde::Deserializable<aptos_types::StateKey::Raw>::deserialize(Deserializer &deserializer) {
    aptos_types::StateKey::Raw obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const StructTag &lhs, const StructTag &rhs) {
        if (!(lhs.address == rhs.address)) { return false; }
        if (!(lhs.module == rhs.module)) { return false; }
        if (!(lhs.name == rhs.name)) { return false; }
        if (!(lhs.type_args == rhs.type_args)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::StructTag>::serialize(const aptos_types::StructTag &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.address)>::serialize(obj.address, serializer);
    serde::Serializable<decltype(obj.module)>::serialize(obj.module, serializer);
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    serde::Serializable<decltype(obj.type_args)>::serialize(obj.type_args, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::StructTag serde::Deserializable<aptos_types::StructTag>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::StructTag obj;
    obj.address = serde::Deserializable<decltype(obj.address)>::deserialize(deserializer);
    obj.module = serde::Deserializable<decltype(obj.module)>::deserialize(deserializer);
    obj.name = serde::Deserializable<decltype(obj.name)>::deserialize(deserializer);
    obj.type_args = serde::Deserializable<decltype(obj.type_args)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TableHandle &lhs, const TableHandle &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TableHandle>::serialize(const aptos_types::TableHandle &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::TableHandle serde::Deserializable<aptos_types::TableHandle>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::TableHandle obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const Transaction &lhs, const Transaction &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::Transaction>::serialize(const aptos_types::Transaction &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::Transaction serde::Deserializable<aptos_types::Transaction>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::Transaction obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const Transaction::UserTransaction &lhs, const Transaction::UserTransaction &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::Transaction::UserTransaction>::serialize(const aptos_types::Transaction::UserTransaction &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::Transaction::UserTransaction serde::Deserializable<aptos_types::Transaction::UserTransaction>::deserialize(Deserializer &deserializer) {
    aptos_types::Transaction::UserTransaction obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const Transaction::GenesisTransaction &lhs, const Transaction::GenesisTransaction &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::Transaction::GenesisTransaction>::serialize(const aptos_types::Transaction::GenesisTransaction &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::Transaction::GenesisTransaction serde::Deserializable<aptos_types::Transaction::GenesisTransaction>::deserialize(Deserializer &deserializer) {
    aptos_types::Transaction::GenesisTransaction obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const Transaction::BlockMetadata &lhs, const Transaction::BlockMetadata &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::Transaction::BlockMetadata>::serialize(const aptos_types::Transaction::BlockMetadata &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::Transaction::BlockMetadata serde::Deserializable<aptos_types::Transaction::BlockMetadata>::deserialize(Deserializer &deserializer) {
    aptos_types::Transaction::BlockMetadata obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const Transaction::StateCheckpoint &lhs, const Transaction::StateCheckpoint &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::Transaction::StateCheckpoint>::serialize(const aptos_types::Transaction::StateCheckpoint &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::Transaction::StateCheckpoint serde::Deserializable<aptos_types::Transaction::StateCheckpoint>::deserialize(Deserializer &deserializer) {
    aptos_types::Transaction::StateCheckpoint obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionArgument &lhs, const TransactionArgument &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionArgument>::serialize(const aptos_types::TransactionArgument &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::TransactionArgument serde::Deserializable<aptos_types::TransactionArgument>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::TransactionArgument obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionArgument::U8 &lhs, const TransactionArgument::U8 &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionArgument::U8>::serialize(const aptos_types::TransactionArgument::U8 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::TransactionArgument::U8 serde::Deserializable<aptos_types::TransactionArgument::U8>::deserialize(Deserializer &deserializer) {
    aptos_types::TransactionArgument::U8 obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionArgument::U64 &lhs, const TransactionArgument::U64 &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionArgument::U64>::serialize(const aptos_types::TransactionArgument::U64 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::TransactionArgument::U64 serde::Deserializable<aptos_types::TransactionArgument::U64>::deserialize(Deserializer &deserializer) {
    aptos_types::TransactionArgument::U64 obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionArgument::U128 &lhs, const TransactionArgument::U128 &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionArgument::U128>::serialize(const aptos_types::TransactionArgument::U128 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::TransactionArgument::U128 serde::Deserializable<aptos_types::TransactionArgument::U128>::deserialize(Deserializer &deserializer) {
    aptos_types::TransactionArgument::U128 obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionArgument::Address &lhs, const TransactionArgument::Address &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionArgument::Address>::serialize(const aptos_types::TransactionArgument::Address &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::TransactionArgument::Address serde::Deserializable<aptos_types::TransactionArgument::Address>::deserialize(Deserializer &deserializer) {
    aptos_types::TransactionArgument::Address obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionArgument::U8Vector &lhs, const TransactionArgument::U8Vector &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionArgument::U8Vector>::serialize(const aptos_types::TransactionArgument::U8Vector &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::TransactionArgument::U8Vector serde::Deserializable<aptos_types::TransactionArgument::U8Vector>::deserialize(Deserializer &deserializer) {
    aptos_types::TransactionArgument::U8Vector obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionArgument::Bool &lhs, const TransactionArgument::Bool &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionArgument::Bool>::serialize(const aptos_types::TransactionArgument::Bool &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::TransactionArgument::Bool serde::Deserializable<aptos_types::TransactionArgument::Bool>::deserialize(Deserializer &deserializer) {
    aptos_types::TransactionArgument::Bool obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionAuthenticator &lhs, const TransactionAuthenticator &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionAuthenticator>::serialize(const aptos_types::TransactionAuthenticator &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::TransactionAuthenticator serde::Deserializable<aptos_types::TransactionAuthenticator>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::TransactionAuthenticator obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionAuthenticator::Ed25519 &lhs, const TransactionAuthenticator::Ed25519 &rhs) {
        if (!(lhs.public_key == rhs.public_key)) { return false; }
        if (!(lhs.signature == rhs.signature)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionAuthenticator::Ed25519>::serialize(const aptos_types::TransactionAuthenticator::Ed25519 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.public_key)>::serialize(obj.public_key, serializer);
    serde::Serializable<decltype(obj.signature)>::serialize(obj.signature, serializer);
}

template <>
template <typename Deserializer>
aptos_types::TransactionAuthenticator::Ed25519 serde::Deserializable<aptos_types::TransactionAuthenticator::Ed25519>::deserialize(Deserializer &deserializer) {
    aptos_types::TransactionAuthenticator::Ed25519 obj;
    obj.public_key = serde::Deserializable<decltype(obj.public_key)>::deserialize(deserializer);
    obj.signature = serde::Deserializable<decltype(obj.signature)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionAuthenticator::MultiEd25519 &lhs, const TransactionAuthenticator::MultiEd25519 &rhs) {
        if (!(lhs.public_key == rhs.public_key)) { return false; }
        if (!(lhs.signature == rhs.signature)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionAuthenticator::MultiEd25519>::serialize(const aptos_types::TransactionAuthenticator::MultiEd25519 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.public_key)>::serialize(obj.public_key, serializer);
    serde::Serializable<decltype(obj.signature)>::serialize(obj.signature, serializer);
}

template <>
template <typename Deserializer>
aptos_types::TransactionAuthenticator::MultiEd25519 serde::Deserializable<aptos_types::TransactionAuthenticator::MultiEd25519>::deserialize(Deserializer &deserializer) {
    aptos_types::TransactionAuthenticator::MultiEd25519 obj;
    obj.public_key = serde::Deserializable<decltype(obj.public_key)>::deserialize(deserializer);
    obj.signature = serde::Deserializable<decltype(obj.signature)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionAuthenticator::MultiAgent &lhs, const TransactionAuthenticator::MultiAgent &rhs) {
        if (!(lhs.sender == rhs.sender)) { return false; }
        if (!(lhs.secondary_signer_addresses == rhs.secondary_signer_addresses)) { return false; }
        if (!(lhs.secondary_signers == rhs.secondary_signers)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionAuthenticator::MultiAgent>::serialize(const aptos_types::TransactionAuthenticator::MultiAgent &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.sender)>::serialize(obj.sender, serializer);
    serde::Serializable<decltype(obj.secondary_signer_addresses)>::serialize(obj.secondary_signer_addresses, serializer);
    serde::Serializable<decltype(obj.secondary_signers)>::serialize(obj.secondary_signers, serializer);
}

template <>
template <typename Deserializer>
aptos_types::TransactionAuthenticator::MultiAgent serde::Deserializable<aptos_types::TransactionAuthenticator::MultiAgent>::deserialize(Deserializer &deserializer) {
    aptos_types::TransactionAuthenticator::MultiAgent obj;
    obj.sender = serde::Deserializable<decltype(obj.sender)>::deserialize(deserializer);
    obj.secondary_signer_addresses = serde::Deserializable<decltype(obj.secondary_signer_addresses)>::deserialize(deserializer);
    obj.secondary_signers = serde::Deserializable<decltype(obj.secondary_signers)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionPayload &lhs, const TransactionPayload &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionPayload>::serialize(const aptos_types::TransactionPayload &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::TransactionPayload serde::Deserializable<aptos_types::TransactionPayload>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::TransactionPayload obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionPayload::Script &lhs, const TransactionPayload::Script &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionPayload::Script>::serialize(const aptos_types::TransactionPayload::Script &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::TransactionPayload::Script serde::Deserializable<aptos_types::TransactionPayload::Script>::deserialize(Deserializer &deserializer) {
    aptos_types::TransactionPayload::Script obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionPayload::ModuleBundle &lhs, const TransactionPayload::ModuleBundle &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionPayload::ModuleBundle>::serialize(const aptos_types::TransactionPayload::ModuleBundle &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::TransactionPayload::ModuleBundle serde::Deserializable<aptos_types::TransactionPayload::ModuleBundle>::deserialize(Deserializer &deserializer) {
    aptos_types::TransactionPayload::ModuleBundle obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TransactionPayload::ScriptFunction &lhs, const TransactionPayload::ScriptFunction &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TransactionPayload::ScriptFunction>::serialize(const aptos_types::TransactionPayload::ScriptFunction &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::TransactionPayload::ScriptFunction serde::Deserializable<aptos_types::TransactionPayload::ScriptFunction>::deserialize(Deserializer &deserializer) {
    aptos_types::TransactionPayload::ScriptFunction obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TypeTag &lhs, const TypeTag &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TypeTag>::serialize(const aptos_types::TypeTag &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::TypeTag serde::Deserializable<aptos_types::TypeTag>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::TypeTag obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TypeTag::Bool &lhs, const TypeTag::Bool &rhs) {
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TypeTag::Bool>::serialize(const aptos_types::TypeTag::Bool &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
aptos_types::TypeTag::Bool serde::Deserializable<aptos_types::TypeTag::Bool>::deserialize(Deserializer &deserializer) {
    aptos_types::TypeTag::Bool obj;
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TypeTag::U8 &lhs, const TypeTag::U8 &rhs) {
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TypeTag::U8>::serialize(const aptos_types::TypeTag::U8 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
aptos_types::TypeTag::U8 serde::Deserializable<aptos_types::TypeTag::U8>::deserialize(Deserializer &deserializer) {
    aptos_types::TypeTag::U8 obj;
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TypeTag::U64 &lhs, const TypeTag::U64 &rhs) {
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TypeTag::U64>::serialize(const aptos_types::TypeTag::U64 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
aptos_types::TypeTag::U64 serde::Deserializable<aptos_types::TypeTag::U64>::deserialize(Deserializer &deserializer) {
    aptos_types::TypeTag::U64 obj;
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TypeTag::U128 &lhs, const TypeTag::U128 &rhs) {
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TypeTag::U128>::serialize(const aptos_types::TypeTag::U128 &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
aptos_types::TypeTag::U128 serde::Deserializable<aptos_types::TypeTag::U128>::deserialize(Deserializer &deserializer) {
    aptos_types::TypeTag::U128 obj;
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TypeTag::Address &lhs, const TypeTag::Address &rhs) {
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TypeTag::Address>::serialize(const aptos_types::TypeTag::Address &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
aptos_types::TypeTag::Address serde::Deserializable<aptos_types::TypeTag::Address>::deserialize(Deserializer &deserializer) {
    aptos_types::TypeTag::Address obj;
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TypeTag::Signer &lhs, const TypeTag::Signer &rhs) {
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TypeTag::Signer>::serialize(const aptos_types::TypeTag::Signer &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
aptos_types::TypeTag::Signer serde::Deserializable<aptos_types::TypeTag::Signer>::deserialize(Deserializer &deserializer) {
    aptos_types::TypeTag::Signer obj;
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TypeTag::Vector &lhs, const TypeTag::Vector &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TypeTag::Vector>::serialize(const aptos_types::TypeTag::Vector &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::TypeTag::Vector serde::Deserializable<aptos_types::TypeTag::Vector>::deserialize(Deserializer &deserializer) {
    aptos_types::TypeTag::Vector obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const TypeTag::Struct &lhs, const TypeTag::Struct &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::TypeTag::Struct>::serialize(const aptos_types::TypeTag::Struct &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::TypeTag::Struct serde::Deserializable<aptos_types::TypeTag::Struct>::deserialize(Deserializer &deserializer) {
    aptos_types::TypeTag::Struct obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const WriteOp &lhs, const WriteOp &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::WriteOp>::serialize(const aptos_types::WriteOp &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::WriteOp serde::Deserializable<aptos_types::WriteOp>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::WriteOp obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const WriteOp::Creation &lhs, const WriteOp::Creation &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::WriteOp::Creation>::serialize(const aptos_types::WriteOp::Creation &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::WriteOp::Creation serde::Deserializable<aptos_types::WriteOp::Creation>::deserialize(Deserializer &deserializer) {
    aptos_types::WriteOp::Creation obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const WriteOp::Modification &lhs, const WriteOp::Modification &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::WriteOp::Modification>::serialize(const aptos_types::WriteOp::Modification &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::WriteOp::Modification serde::Deserializable<aptos_types::WriteOp::Modification>::deserialize(Deserializer &deserializer) {
    aptos_types::WriteOp::Modification obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const WriteOp::Deletion &lhs, const WriteOp::Deletion &rhs) {
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::WriteOp::Deletion>::serialize(const aptos_types::WriteOp::Deletion &obj, Serializer &serializer) {
}

template <>
template <typename Deserializer>
aptos_types::WriteOp::Deletion serde::Deserializable<aptos_types::WriteOp::Deletion>::deserialize(Deserializer &deserializer) {
    aptos_types::WriteOp::Deletion obj;
    return obj;
}

namespace aptos_types {

    inline bool operator==(const WriteSet &lhs, const WriteSet &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::WriteSet>::serialize(const aptos_types::WriteSet &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::WriteSet serde::Deserializable<aptos_types::WriteSet>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::WriteSet obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const WriteSet::V0 &lhs, const WriteSet::V0 &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::WriteSet::V0>::serialize(const aptos_types::WriteSet::V0 &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::WriteSet::V0 serde::Deserializable<aptos_types::WriteSet::V0>::deserialize(Deserializer &deserializer) {
    aptos_types::WriteSet::V0 obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const WriteSetMut &lhs, const WriteSetMut &rhs) {
        if (!(lhs.write_set == rhs.write_set)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::WriteSetMut>::serialize(const aptos_types::WriteSetMut &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.write_set)>::serialize(obj.write_set, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::WriteSetMut serde::Deserializable<aptos_types::WriteSetMut>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::WriteSetMut obj;
    obj.write_set = serde::Deserializable<decltype(obj.write_set)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const WriteSetPayload &lhs, const WriteSetPayload &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::WriteSetPayload>::serialize(const aptos_types::WriteSetPayload &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::WriteSetPayload serde::Deserializable<aptos_types::WriteSetPayload>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::WriteSetPayload obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}

namespace aptos_types {

    inline bool operator==(const WriteSetPayload::Direct &lhs, const WriteSetPayload::Direct &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::WriteSetPayload::Direct>::serialize(const aptos_types::WriteSetPayload::Direct &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
}

template <>
template <typename Deserializer>
aptos_types::WriteSetPayload::Direct serde::Deserializable<aptos_types::WriteSetPayload::Direct>::deserialize(Deserializer &deserializer) {
    aptos_types::WriteSetPayload::Direct obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const WriteSetPayload::Script &lhs, const WriteSetPayload::Script &rhs) {
        if (!(lhs.execute_as == rhs.execute_as)) { return false; }
        if (!(lhs.script == rhs.script)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::WriteSetPayload::Script>::serialize(const aptos_types::WriteSetPayload::Script &obj, Serializer &serializer) {
    serde::Serializable<decltype(obj.execute_as)>::serialize(obj.execute_as, serializer);
    serde::Serializable<decltype(obj.script)>::serialize(obj.script, serializer);
}

template <>
template <typename Deserializer>
aptos_types::WriteSetPayload::Script serde::Deserializable<aptos_types::WriteSetPayload::Script>::deserialize(Deserializer &deserializer) {
    aptos_types::WriteSetPayload::Script obj;
    obj.execute_as = serde::Deserializable<decltype(obj.execute_as)>::deserialize(deserializer);
    obj.script = serde::Deserializable<decltype(obj.script)>::deserialize(deserializer);
    return obj;
}

namespace aptos_types {

    inline bool operator==(const WriteSetV0 &lhs, const WriteSetV0 &rhs) {
        if (!(lhs.value == rhs.value)) { return false; }
        return true;
    }

} // end of namespace aptos_types

template <>
template <typename Serializer>
void serde::Serializable<aptos_types::WriteSetV0>::serialize(const aptos_types::WriteSetV0 &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.value)>::serialize(obj.value, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Deserializer>
aptos_types::WriteSetV0 serde::Deserializable<aptos_types::WriteSetV0>::deserialize(Deserializer &deserializer) {
    deserializer.increase_container_depth();
    aptos_types::WriteSetV0 obj;
    obj.value = serde::Deserializable<decltype(obj.value)>::deserialize(deserializer);
    deserializer.decrease_container_depth();
    return obj;
}
