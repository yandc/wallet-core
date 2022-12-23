#pragma once

#include <ctime>
#include "serde.hpp"
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <nlohmann/json.hpp>
#include "../binary.hpp"
using json = nlohmann::json;

namespace casper_types {

    struct TypeEnum;

    template<typename T> struct ValuePtr { T* ptr; };

    struct Uint128 {
        boost::multiprecision::uint128_t value;
    };

    struct Uint256 {
        boost::multiprecision::uint256_t value;
    };

    struct Uint512 {
        boost::multiprecision::uint512_t value;
    };

    struct ByteArray
    {
        std::vector<uint8_t> value;
    };


    struct Unit{};

    struct Uref {
        enum AccessRright{NONE, READ, WRITE, ADD, READ_WRITE, READ_ADD, ADD_WRITE, READ_ADD_WRITE};
        AccessRright right;
        ByteArray address;
    };

    struct Key {
        enum KeyType{ACCOUNT, HASH, UREF};
        ByteArray identifier;
        KeyType type;
    };

    struct Option {
        ValuePtr<TypeEnum> value;
    };

    struct List {
        size_t size;
        ValuePtr<TypeEnum> value;
    };

    struct Map {
        size_t size;
        ValuePtr<std::pair<TypeEnum, TypeEnum>> value;
    };

    struct Result {};

    struct Tuple1 {
        ValuePtr<TypeEnum> value1;
    };

    struct Tuple2 {
        ValuePtr<TypeEnum> value1;
        ValuePtr<TypeEnum> value2;
    };

    struct Tuple3 {
        ValuePtr<TypeEnum> value1;
        ValuePtr<TypeEnum> value2;
        ValuePtr<TypeEnum> value3;
    };

    struct Any {};

    struct PublicKey {
        ByteArray value;
    };

    struct DeployApproval {
        PublicKey signer;
        ByteArray signature;
    };

    struct TypeEnum {
        std::variant<bool, int32_t, int64_t, uint8_t, uint32_t, uint64_t,
                    Uint128, Uint256, Uint512, Unit, std::string,
                    Key, Uref, Option, List, ByteArray, Result,
                    Map, Tuple1, Tuple2, Tuple3, Any, PublicKey> value;
    };
    const std::string TypeName[] = {
        "Bool", "I32", "I64", "U8", "U32", "U64", "U128", "U256", "U512", "Unit",
        "String", "Key", "URef", "Option", "List", "ByteArray", "Result", "Map",
        "Tuple1", "Tuple2", "Tuple3", "Any", "PublicKey"
    };

    struct DeployArgument {
        std::string name;
        TypeEnum value;
    };

    struct DeployExecutableItem {
        std::vector<DeployArgument> args;
    };

    struct ModuleBytes : DeployExecutableItem {
        std::vector<uint8_t> modBytes;
    };

    struct Transfer : DeployExecutableItem{};

    using ExecutableItem = std::variant<ModuleBytes, Transfer>;

    struct DeployBody {
        ExecutableItem payment;
        ExecutableItem session;
        ByteArray hash;
    };

    struct DeployHeader {
        PublicKey account;
        ByteArray body_hash;
        std::string chain_name;
        std::vector<ByteArray> dependencies;
        uint64_t gas_price;
        uint64_t timestamp;
        uint64_t ttl;
    };

    struct Deploy {
        std::vector<DeployApproval> approvals;
        ByteArray hash;
        DeployHeader header;
        ExecutableItem payment;
        ExecutableItem session;
    };

    class CasperSerializer : public serde::BinarySerializer<CasperSerializer> {
        using Parent = BinarySerializer<CasperSerializer>;

        public:
        CasperSerializer() : Parent(500) {}

        void serialize_len(size_t value) { serialize_u32(value); }
        void serialize_variant_index(uint32_t value) { serialize_u8(value); }

        template<typename T> void serialize_type(const T& value) {}
        void serialize_type(const ByteArray& value) { serialize_u32(value.value.size()); }
        void serialize_type(const List& value) { serialize_type(value.value.ptr[0]); }
        void serialize_type(const Option& value) { serialize_type(value.value.ptr[0]); }

        void serialize_type(const Tuple1& value) { serialize_type(value.value1.ptr[0]); }

        void serialize_type(const Tuple2& value) {
            serialize_type(value.value1.ptr[0]);
            serialize_type(value.value2.ptr[0]);
        }
        void serialize_type(const Tuple3& value) {
            serialize_type(value.value1.ptr[0]);
            serialize_type(value.value2.ptr[0]);
            serialize_type(value.value3.ptr[0]);
        }
        void serialize_type(const Map& value) {
            serialize_type(value.value.ptr[0].first);
            serialize_type(value.value.ptr[0].second);
        }
        void serialize_type(const TypeEnum& obj) {
            serialize_variant_index(obj.value.index());
            std::visit([this](const auto &arg) {
                this->serialize_type(arg);
            }, obj.value);
        }
    };
} // end of namespace aptos_types

template <typename T>
std::vector<uint8_t> CasperSerialize(const T& obj) {
    casper_types::CasperSerializer ser;
    serde::Serializable<T>::serialize(obj, ser);
    return std::move(ser).bytes();
}

template <typename T>
template <typename Serializer>
void serde::Serializable<T>::serialize(const T& value, Serializer &serializer) {}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::Uint512>::serialize(const casper_types::Uint512 &value, Serializer &serializer) {
    boost::multiprecision::uint512_t val = value.value;
    casper_types::ByteArray encoded;
    do {
        encoded.value.push_back((uint8_t)val);
        val = val >> 8;
    } while ((val & 0xff) != 0);
    serializer.serialize_u8(encoded.value.size());
    serde::Serializable<casper_types::ByteArray>::serialize(encoded, serializer);
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::Uint128>::serialize(const casper_types::Uint128 &value, Serializer &serializer) {
    serde::Serializable<casper_types::Uint512>::serialize(casper_types::Uint512{value.value}, serializer);
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::Uint256>::serialize(const casper_types::Uint256 &value, Serializer &serializer) {
    serde::Serializable<casper_types::Uint512>::serialize(casper_types::Uint512{value.value}, serializer);
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::Uref>::serialize(const casper_types::Uref &obj, Serializer &serializer) {
    serde::Serializable<casper_types::ByteArray>::serialize(obj.address, serializer);
    serializer.serialize_u8(obj.right);
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::Key>::serialize(const casper_types::Key &obj, Serializer &serializer) {
    serializer.serialize_u8(obj.type);
    serde::Serializable<casper_types::ByteArray>::serialize(obj.identifier, serializer);
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::ByteArray>::serialize(const casper_types::ByteArray &obj, Serializer &serializer) {
    for(size_t i = 0; i < obj.value.size(); i++) {
        serializer.serialize_u8(obj.value[i]);
    }
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::PublicKey>::serialize(const casper_types::PublicKey &obj, Serializer &serializer) {
    serde::Serializable<casper_types::ByteArray>::serialize(obj.value, serializer);
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::Option>::serialize(const casper_types::Option &obj, Serializer &serializer) {
    if(obj.value.ptr == NULL) {
        serializer.serialize_u8(0);
    } else {
        serializer.serialize_u8(1);
        using T = typename std::decay<decltype(obj.value.ptr[0])>::type;
        serde::Serializable<T>::serialize(obj.value.ptr[0], serializer);
    }
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::Tuple1>::serialize(const casper_types::Tuple1 &obj, Serializer &serializer) {
    using T = typename std::decay<decltype(obj.value1.ptr[0])>::type;
    serde::Serializable<T>::serialize(obj.value1.ptr[0], serializer);
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::Tuple2>::serialize(const casper_types::Tuple2 &obj, Serializer &serializer) {
    using T = typename std::decay<decltype(obj.value1.ptr[0])>::type;
    using U = typename std::decay<decltype(obj.value2.ptr[0])>::type;
    serde::Serializable<T>::serialize(obj.value1.ptr[0], serializer);
    serde::Serializable<U>::serialize(obj.value2.ptr[0], serializer);
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::Tuple3>::serialize(const casper_types::Tuple3 &obj, Serializer &serializer) {
    using T = typename std::decay<decltype(obj.value1.ptr[0])>::type;
    using U = typename std::decay<decltype(obj.value2.ptr[0])>::type;
    using V = typename std::decay<decltype(obj.value3.ptr[0])>::type;
    serde::Serializable<T>::serialize(obj.value1.ptr[0], serializer);
    serde::Serializable<U>::serialize(obj.value2.ptr[0], serializer);
    serde::Serializable<V>::serialize(obj.value3.ptr[0], serializer);
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::List>::serialize(const casper_types::List &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serializer.serialize_len(obj.size);
    using T = typename std::decay<decltype(obj.value.ptr[0])>::type;
    for(size_t i = 0; i < obj.size; i++) {
        serde::Serializable<T>::serialize(obj.value.ptr[i], serializer);
    }
    serializer.decrease_container_depth();
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::Map>::serialize(const casper_types::Map &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serializer.serialize_len(obj.size);

    using T = typename std::decay<decltype(obj.value.ptr[0].first)>::type;
    using U = typename std::decay<decltype(obj.value.ptr[0].second)>::type;
    for(size_t i = 0; i < obj.size; i++) {
        serde::Serializable<T>::serialize(obj.value.ptr[i].first, serializer);
        serde::Serializable<U>::serialize(obj.value.ptr[i].second, serializer);
    }
    serializer.decrease_container_depth();
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::TypeEnum>::serialize(const casper_types::TypeEnum &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    std::visit(
        [&serializer](const auto &arg) {
            using T = typename std::decay<decltype(arg)>::type;
            Serializable<T>::serialize(arg, serializer);
        }, obj.value);
    serializer.decrease_container_depth();
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::DeployArgument>::serialize(const casper_types::DeployArgument &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    //size_t offset1 = serializer.get_buffer_offset();
    serde::Serializable<decltype(obj.name)>::serialize(obj.name, serializer);
    //size_t offset2 = serializer.get_buffer_offset();
    serde::Serializable<TW::Data>::serialize(CasperSerialize(obj.value), serializer);
    //std::cout << "deploy argument: " << obj.name << ", bytes range: " << offset1 << ": " << offset2 << ": " << serializer.get_buffer_offset() << std::endl;
    // Visit the inner type.
    serializer.serialize_type(obj.value);
    serializer.decrease_container_depth();
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::Transfer>::serialize(const casper_types::Transfer &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serializer.serialize_u8(5);
    serde::Serializable<decltype(obj.args)>::serialize(obj.args, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::ModuleBytes>::serialize(const casper_types::ModuleBytes &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serializer.serialize_u8(0);
    serde::Serializable<decltype(obj.modBytes)>::serialize(obj.modBytes, serializer);
    serde::Serializable<decltype(obj.args)>::serialize(obj.args, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::ExecutableItem>::serialize(const casper_types::ExecutableItem &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    std::visit(
        [&serializer](const auto &arg) {
            using T = typename std::decay<decltype(arg)>::type;
            Serializable<T>::serialize(arg, serializer);
        },
        obj);
    serializer.decrease_container_depth();
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::DeployBody>::serialize(const casper_types::DeployBody &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.payment)>::serialize(obj.payment, serializer);
    serde::Serializable<decltype(obj.session)>::serialize(obj.session, serializer);
    serializer.decrease_container_depth();
}

template <>
template <typename Serializer>
void serde::Serializable<casper_types::DeployHeader>::serialize(const casper_types::DeployHeader &obj, Serializer &serializer) {
    serializer.increase_container_depth();
    serde::Serializable<decltype(obj.account)>::serialize(obj.account, serializer);
    serde::Serializable<decltype(obj.timestamp)>::serialize(obj.timestamp, serializer);
    serde::Serializable<decltype(obj.ttl)>::serialize(obj.ttl, serializer);
    serde::Serializable<decltype(obj.gas_price)>::serialize(obj.gas_price, serializer);
    serde::Serializable<decltype(obj.body_hash)>::serialize(obj.body_hash, serializer);
    serde::Serializable<decltype(obj.dependencies)>::serialize(obj.dependencies, serializer);
    serde::Serializable<decltype(obj.chain_name)>::serialize(obj.chain_name, serializer);
    serializer.decrease_container_depth();
}

namespace casper_types {
    json GetType(const TypeEnum& obj);
    template<typename T>
    json GetType(const T& obj) { return json(TypeName[TypeEnum{obj}.value.index()]); }
    json GetType(const List& obj) { return json{{"List", GetType(obj.value.ptr[0])}}; }
    json GetType(const ByteArray& obj) { return json{{"ByteArray", obj.value.size()}}; }
    json GetType(const Option& obj) { return json{{"Option", GetType(obj.value.ptr[0])}}; }
    json GetType(const Tuple1& obj) { return json{{"Tuple1", GetType(obj.value1.ptr[0])}}; }
    json GetType(const Tuple2& obj) {
        return json{{
            "Tuple2",
            json::array({
                GetType(obj.value1.ptr[0]),
                GetType(obj.value2.ptr[0])
            })
        }};
    }
    json GetType(const Tuple3& obj) {
        return json{{
            "Tuple3",
            json::array({
                GetType(obj.value1.ptr[0]),
                GetType(obj.value2.ptr[0]),
                GetType(obj.value3.ptr[0])
            })
        }};
    }
    json GetType(const Map& obj) {
        return json{{
            "Map", {
                {"key", GetType(obj.value.ptr[0].first)},
                {"value", GetType(obj.value.ptr[0].second)}
            }
        }};
    }
    json GetType(const TypeEnum& obj) {
        json ret;
        std::visit([&ret](const auto &arg) { ret = GetType(arg); }, obj.value);
        return ret;
    }

    void to_json(json& j, const TypeEnum& p);
    void to_json(json& j, const Uint128& value) {
        std::stringstream ss;
        ss << value.value;
        j = ss.str();
    }
    void to_json(json& j, const Uint256& value) {
        std::stringstream ss;
        ss << value.value;
        j = ss.str();
    }
    void to_json(json& j, const Uint512& value) {
        std::stringstream ss;
        ss << value.value;
        j = ss.str();
    }

    void to_json(json& j, const List& obj) {
        for(size_t i = 0; i < obj.size; i++) {
            j.push_back(json(obj.value.ptr[i]));
        }
    }
    void to_json(json& j, const Map& obj) {
        for(size_t i = 0; i < obj.size; i++) {
            j.push_back(json{
                {"key", json(obj.value.ptr[i].first)},
                {"value", json(obj.value.ptr[i].second)},
            });
        }
    }
    void to_json(json& j, const Option& obj) {
        if(obj.value.ptr == NULL) {
            j = json("");
        } else {
            j = json(obj.value.ptr[0]);
        }
    }
    void to_json(json& j, const Tuple1& obj) {
        j.push_back(json(obj.value1.ptr[0]));
    }
    void to_json(json& j, const Tuple2& obj) {
        j.push_back(json(obj.value1.ptr[0]));
        j.push_back(json(obj.value2.ptr[0]));
    }
    void to_json(json& j, const Tuple3& obj) {
        j.push_back(json(obj.value1.ptr[0]));
        j.push_back(json(obj.value2.ptr[0]));
        j.push_back(json(obj.value3.ptr[0]));
    }
    void to_json(json& j, const Unit& obj) {
        j = "";
    }
    void to_json(json& j, const Any& obj) {
        j = "";
    }
    void to_json(json& j, const Result& obj) {
        j = "";
    }
    void to_json(json& j, const Key& obj) {
        std::string prefix;
        if(obj.type == Key::KeyType::ACCOUNT) {
            prefix = "account-hash-";
        } else if(obj.type == Key::KeyType::HASH) {
            prefix = "hash-";
        } else if(obj.type == Key::KeyType::UREF) {
            prefix = "uref-";
        }
        prefix += TW::hex(obj.identifier.value);
        j = prefix;
    }
    void to_json(json& j, const Uref& obj) {
        std::stringstream ss;
        ss << "uref-" << TW::hex(obj.address.value) << obj.right;
        j = ss.str();
    }
    void to_json(json& j, const ByteArray& obj) {
        j = TW::hex(obj.value);
    }
    void to_json(json& j, const PublicKey& obj) {
        j = TW::hex(obj.value.value);
    }
    void to_json(json& j, const TypeEnum& p) {
        std::visit([&j](const auto &arg) { j = json(arg); }, p.value);
    }

    void to_json(json& j, const DeployArgument& obj) {
        j.push_back(obj.name);
        json innerJson, innerType;
        std::visit([&innerJson, &innerType](const auto &arg) { innerJson = json(arg); innerType = GetType(arg); }, obj.value.value);
        j.push_back(json{
            {"cl_type", innerType},
            {"bytes", TW::hex(CasperSerialize(obj.value))},
            {"parsed", innerJson}
        });
    }
    void to_json(json& j, const ModuleBytes& obj) {
        j = json{{
            "ModuleBytes", {
                {"args", json(obj.args)},
                {"module_bytes", TW::hex(obj.modBytes)}
            }}
        };
    }
    void to_json(json& j, const Transfer& obj) {
        j = json{
            {"Transfer", { {"args", json(obj.args)} } }
        };
    }
    void to_json(json& j, const ExecutableItem& obj) {
        std::visit([&j](const auto &arg) { j = json(arg); }, obj);
    }
    void to_json(json& j, const DeployHeader& obj) {
        char buf[32];
        std::stringstream ss;
        time_t ts = (time_t)(obj.timestamp/1000);
        char* p = buf + strftime(buf, sizeof(buf), "%FT%T", gmtime(&ts));
        sprintf(p, ".%03dZ", (int)(obj.timestamp % 1000));

        j = json{
            {"account", json(obj.account)},
            {"body_hash", json(obj.body_hash)},
            {"chain_name", json(obj.chain_name)},
            {"dependencies", json(obj.dependencies)},
            {"gas_price", json(obj.gas_price)},
            {"timestamp", json(buf)},
            {"ttl", json("30m")}
        };
    }

    void from_json(const json& j, Uint512& value) {}
    void from_json(const json& j, Uint256& value) {}
    void from_json(const json& j, Uint128& value) {}
    void from_json(const json& j, List& obj) {}
    void from_json(const json& j, Map& obj) {}
    void from_json(const json& j, Option& obj) {}
    void from_json(const json& j, Tuple1& obj) {}
    void from_json(const json& j, Tuple2& obj) {}
    void from_json(const json& j, Tuple3& obj) {}
    void from_json(const json& j, Unit& obj) {}
    void from_json(const json& j, Any& obj) {}
    void from_json(const json& j, Result& obj) {}
    void from_json(const json& j, Key& obj) {}
    void from_json(const json& j, Uref& obj) {}
    void from_json(const json& j, TypeEnum& obj) {}
    void from_json(const json& j, DeployArgument& obj) {}
    void from_json(const json& j, ModuleBytes& obj) {}
    void from_json(const json& j, Transfer& obj) {}
    void from_json(const json& j, ExecutableItem& obj) {}
    void from_json(const json& j, ByteArray& obj) {}
    void from_json(const json& j, PublicKey& obj) {}
    void from_json(const json& j, DeployHeader& obj) {}

    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(DeployApproval, signer, signature)
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Deploy, approvals, hash, header, payment, session)
}
