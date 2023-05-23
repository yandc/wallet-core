// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cosmwasm_wasm_v1_tx.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_cosmwasm_5fwasm_5fv1_5ftx_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_cosmwasm_5fwasm_5fv1_5ftx_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3014000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3014000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "coin.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_cosmwasm_5fwasm_5fv1_5ftx_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_cosmwasm_5fwasm_5fv1_5ftx_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_cosmwasm_5fwasm_5fv1_5ftx_2eproto;
namespace cosmwasm {
namespace wasm {
namespace v1 {
class MsgExecuteContract;
class MsgExecuteContractDefaultTypeInternal;
extern MsgExecuteContractDefaultTypeInternal _MsgExecuteContract_default_instance_;
}  // namespace v1
}  // namespace wasm
}  // namespace cosmwasm
PROTOBUF_NAMESPACE_OPEN
template<> ::cosmwasm::wasm::v1::MsgExecuteContract* Arena::CreateMaybeMessage<::cosmwasm::wasm::v1::MsgExecuteContract>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace cosmwasm {
namespace wasm {
namespace v1 {

// ===================================================================

class MsgExecuteContract PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:cosmwasm.wasm.v1.MsgExecuteContract) */ {
 public:
  inline MsgExecuteContract() : MsgExecuteContract(nullptr) {}
  virtual ~MsgExecuteContract();

  MsgExecuteContract(const MsgExecuteContract& from);
  MsgExecuteContract(MsgExecuteContract&& from) noexcept
    : MsgExecuteContract() {
    *this = ::std::move(from);
  }

  inline MsgExecuteContract& operator=(const MsgExecuteContract& from) {
    CopyFrom(from);
    return *this;
  }
  inline MsgExecuteContract& operator=(MsgExecuteContract&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const MsgExecuteContract& default_instance();

  static inline const MsgExecuteContract* internal_default_instance() {
    return reinterpret_cast<const MsgExecuteContract*>(
               &_MsgExecuteContract_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(MsgExecuteContract& a, MsgExecuteContract& b) {
    a.Swap(&b);
  }
  inline void Swap(MsgExecuteContract* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MsgExecuteContract* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline MsgExecuteContract* New() const final {
    return CreateMaybeMessage<MsgExecuteContract>(nullptr);
  }

  MsgExecuteContract* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<MsgExecuteContract>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const MsgExecuteContract& from);
  void MergeFrom(const MsgExecuteContract& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MsgExecuteContract* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "cosmwasm.wasm.v1.MsgExecuteContract";
  }
  protected:
  explicit MsgExecuteContract(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_cosmwasm_5fwasm_5fv1_5ftx_2eproto);
    return ::descriptor_table_cosmwasm_5fwasm_5fv1_5ftx_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFundsFieldNumber = 5,
    kSenderFieldNumber = 1,
    kContractFieldNumber = 2,
    kMsgFieldNumber = 3,
  };
  // repeated .cosmos.base.v1beta1.Coin funds = 5;
  int funds_size() const;
  private:
  int _internal_funds_size() const;
  public:
  void clear_funds();
  ::cosmos::base::v1beta1::Coin* mutable_funds(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::cosmos::base::v1beta1::Coin >*
      mutable_funds();
  private:
  const ::cosmos::base::v1beta1::Coin& _internal_funds(int index) const;
  ::cosmos::base::v1beta1::Coin* _internal_add_funds();
  public:
  const ::cosmos::base::v1beta1::Coin& funds(int index) const;
  ::cosmos::base::v1beta1::Coin* add_funds();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::cosmos::base::v1beta1::Coin >&
      funds() const;

  // string sender = 1;
  void clear_sender();
  const std::string& sender() const;
  void set_sender(const std::string& value);
  void set_sender(std::string&& value);
  void set_sender(const char* value);
  void set_sender(const char* value, size_t size);
  std::string* mutable_sender();
  std::string* release_sender();
  void set_allocated_sender(std::string* sender);
  private:
  const std::string& _internal_sender() const;
  void _internal_set_sender(const std::string& value);
  std::string* _internal_mutable_sender();
  public:

  // string contract = 2;
  void clear_contract();
  const std::string& contract() const;
  void set_contract(const std::string& value);
  void set_contract(std::string&& value);
  void set_contract(const char* value);
  void set_contract(const char* value, size_t size);
  std::string* mutable_contract();
  std::string* release_contract();
  void set_allocated_contract(std::string* contract);
  private:
  const std::string& _internal_contract() const;
  void _internal_set_contract(const std::string& value);
  std::string* _internal_mutable_contract();
  public:

  // bytes msg = 3;
  void clear_msg();
  const std::string& msg() const;
  void set_msg(const std::string& value);
  void set_msg(std::string&& value);
  void set_msg(const char* value);
  void set_msg(const void* value, size_t size);
  std::string* mutable_msg();
  std::string* release_msg();
  void set_allocated_msg(std::string* msg);
  private:
  const std::string& _internal_msg() const;
  void _internal_set_msg(const std::string& value);
  std::string* _internal_mutable_msg();
  public:

  // @@protoc_insertion_point(class_scope:cosmwasm.wasm.v1.MsgExecuteContract)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::cosmos::base::v1beta1::Coin > funds_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr sender_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr contract_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr msg_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_cosmwasm_5fwasm_5fv1_5ftx_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MsgExecuteContract

// string sender = 1;
inline void MsgExecuteContract::clear_sender() {
  sender_.ClearToEmpty();
}
inline const std::string& MsgExecuteContract::sender() const {
  // @@protoc_insertion_point(field_get:cosmwasm.wasm.v1.MsgExecuteContract.sender)
  return _internal_sender();
}
inline void MsgExecuteContract::set_sender(const std::string& value) {
  _internal_set_sender(value);
  // @@protoc_insertion_point(field_set:cosmwasm.wasm.v1.MsgExecuteContract.sender)
}
inline std::string* MsgExecuteContract::mutable_sender() {
  // @@protoc_insertion_point(field_mutable:cosmwasm.wasm.v1.MsgExecuteContract.sender)
  return _internal_mutable_sender();
}
inline const std::string& MsgExecuteContract::_internal_sender() const {
  return sender_.Get();
}
inline void MsgExecuteContract::_internal_set_sender(const std::string& value) {
  
  sender_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void MsgExecuteContract::set_sender(std::string&& value) {
  
  sender_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:cosmwasm.wasm.v1.MsgExecuteContract.sender)
}
inline void MsgExecuteContract::set_sender(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  sender_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:cosmwasm.wasm.v1.MsgExecuteContract.sender)
}
inline void MsgExecuteContract::set_sender(const char* value,
    size_t size) {
  
  sender_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:cosmwasm.wasm.v1.MsgExecuteContract.sender)
}
inline std::string* MsgExecuteContract::_internal_mutable_sender() {
  
  return sender_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* MsgExecuteContract::release_sender() {
  // @@protoc_insertion_point(field_release:cosmwasm.wasm.v1.MsgExecuteContract.sender)
  return sender_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void MsgExecuteContract::set_allocated_sender(std::string* sender) {
  if (sender != nullptr) {
    
  } else {
    
  }
  sender_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), sender,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:cosmwasm.wasm.v1.MsgExecuteContract.sender)
}

// string contract = 2;
inline void MsgExecuteContract::clear_contract() {
  contract_.ClearToEmpty();
}
inline const std::string& MsgExecuteContract::contract() const {
  // @@protoc_insertion_point(field_get:cosmwasm.wasm.v1.MsgExecuteContract.contract)
  return _internal_contract();
}
inline void MsgExecuteContract::set_contract(const std::string& value) {
  _internal_set_contract(value);
  // @@protoc_insertion_point(field_set:cosmwasm.wasm.v1.MsgExecuteContract.contract)
}
inline std::string* MsgExecuteContract::mutable_contract() {
  // @@protoc_insertion_point(field_mutable:cosmwasm.wasm.v1.MsgExecuteContract.contract)
  return _internal_mutable_contract();
}
inline const std::string& MsgExecuteContract::_internal_contract() const {
  return contract_.Get();
}
inline void MsgExecuteContract::_internal_set_contract(const std::string& value) {
  
  contract_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void MsgExecuteContract::set_contract(std::string&& value) {
  
  contract_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:cosmwasm.wasm.v1.MsgExecuteContract.contract)
}
inline void MsgExecuteContract::set_contract(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  contract_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:cosmwasm.wasm.v1.MsgExecuteContract.contract)
}
inline void MsgExecuteContract::set_contract(const char* value,
    size_t size) {
  
  contract_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:cosmwasm.wasm.v1.MsgExecuteContract.contract)
}
inline std::string* MsgExecuteContract::_internal_mutable_contract() {
  
  return contract_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* MsgExecuteContract::release_contract() {
  // @@protoc_insertion_point(field_release:cosmwasm.wasm.v1.MsgExecuteContract.contract)
  return contract_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void MsgExecuteContract::set_allocated_contract(std::string* contract) {
  if (contract != nullptr) {
    
  } else {
    
  }
  contract_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), contract,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:cosmwasm.wasm.v1.MsgExecuteContract.contract)
}

// bytes msg = 3;
inline void MsgExecuteContract::clear_msg() {
  msg_.ClearToEmpty();
}
inline const std::string& MsgExecuteContract::msg() const {
  // @@protoc_insertion_point(field_get:cosmwasm.wasm.v1.MsgExecuteContract.msg)
  return _internal_msg();
}
inline void MsgExecuteContract::set_msg(const std::string& value) {
  _internal_set_msg(value);
  // @@protoc_insertion_point(field_set:cosmwasm.wasm.v1.MsgExecuteContract.msg)
}
inline std::string* MsgExecuteContract::mutable_msg() {
  // @@protoc_insertion_point(field_mutable:cosmwasm.wasm.v1.MsgExecuteContract.msg)
  return _internal_mutable_msg();
}
inline const std::string& MsgExecuteContract::_internal_msg() const {
  return msg_.Get();
}
inline void MsgExecuteContract::_internal_set_msg(const std::string& value) {
  
  msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void MsgExecuteContract::set_msg(std::string&& value) {
  
  msg_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:cosmwasm.wasm.v1.MsgExecuteContract.msg)
}
inline void MsgExecuteContract::set_msg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:cosmwasm.wasm.v1.MsgExecuteContract.msg)
}
inline void MsgExecuteContract::set_msg(const void* value,
    size_t size) {
  
  msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:cosmwasm.wasm.v1.MsgExecuteContract.msg)
}
inline std::string* MsgExecuteContract::_internal_mutable_msg() {
  
  return msg_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* MsgExecuteContract::release_msg() {
  // @@protoc_insertion_point(field_release:cosmwasm.wasm.v1.MsgExecuteContract.msg)
  return msg_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void MsgExecuteContract::set_allocated_msg(std::string* msg) {
  if (msg != nullptr) {
    
  } else {
    
  }
  msg_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), msg,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:cosmwasm.wasm.v1.MsgExecuteContract.msg)
}

// repeated .cosmos.base.v1beta1.Coin funds = 5;
inline int MsgExecuteContract::_internal_funds_size() const {
  return funds_.size();
}
inline int MsgExecuteContract::funds_size() const {
  return _internal_funds_size();
}
inline ::cosmos::base::v1beta1::Coin* MsgExecuteContract::mutable_funds(int index) {
  // @@protoc_insertion_point(field_mutable:cosmwasm.wasm.v1.MsgExecuteContract.funds)
  return funds_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::cosmos::base::v1beta1::Coin >*
MsgExecuteContract::mutable_funds() {
  // @@protoc_insertion_point(field_mutable_list:cosmwasm.wasm.v1.MsgExecuteContract.funds)
  return &funds_;
}
inline const ::cosmos::base::v1beta1::Coin& MsgExecuteContract::_internal_funds(int index) const {
  return funds_.Get(index);
}
inline const ::cosmos::base::v1beta1::Coin& MsgExecuteContract::funds(int index) const {
  // @@protoc_insertion_point(field_get:cosmwasm.wasm.v1.MsgExecuteContract.funds)
  return _internal_funds(index);
}
inline ::cosmos::base::v1beta1::Coin* MsgExecuteContract::_internal_add_funds() {
  return funds_.Add();
}
inline ::cosmos::base::v1beta1::Coin* MsgExecuteContract::add_funds() {
  // @@protoc_insertion_point(field_add:cosmwasm.wasm.v1.MsgExecuteContract.funds)
  return _internal_add_funds();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::cosmos::base::v1beta1::Coin >&
MsgExecuteContract::funds() const {
  // @@protoc_insertion_point(field_list:cosmwasm.wasm.v1.MsgExecuteContract.funds)
  return funds_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace wasm
}  // namespace cosmwasm

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_cosmwasm_5fwasm_5fv1_5ftx_2eproto
