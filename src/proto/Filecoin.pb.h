// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Filecoin.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Filecoin_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Filecoin_2eproto

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
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Filecoin_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Filecoin_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Filecoin_2eproto;
namespace TW {
namespace Filecoin {
namespace Proto {
class SigningInput;
class SigningInputDefaultTypeInternal;
extern SigningInputDefaultTypeInternal _SigningInput_default_instance_;
class SigningOutput;
class SigningOutputDefaultTypeInternal;
extern SigningOutputDefaultTypeInternal _SigningOutput_default_instance_;
}  // namespace Proto
}  // namespace Filecoin
}  // namespace TW
PROTOBUF_NAMESPACE_OPEN
template<> ::TW::Filecoin::Proto::SigningInput* Arena::CreateMaybeMessage<::TW::Filecoin::Proto::SigningInput>(Arena*);
template<> ::TW::Filecoin::Proto::SigningOutput* Arena::CreateMaybeMessage<::TW::Filecoin::Proto::SigningOutput>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace TW {
namespace Filecoin {
namespace Proto {

// ===================================================================

class SigningInput PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:TW.Filecoin.Proto.SigningInput) */ {
 public:
  inline SigningInput() : SigningInput(nullptr) {}
  virtual ~SigningInput();

  SigningInput(const SigningInput& from);
  SigningInput(SigningInput&& from) noexcept
    : SigningInput() {
    *this = ::std::move(from);
  }

  inline SigningInput& operator=(const SigningInput& from) {
    CopyFrom(from);
    return *this;
  }
  inline SigningInput& operator=(SigningInput&& from) noexcept {
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
  static const SigningInput& default_instance();

  static inline const SigningInput* internal_default_instance() {
    return reinterpret_cast<const SigningInput*>(
               &_SigningInput_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SigningInput& a, SigningInput& b) {
    a.Swap(&b);
  }
  inline void Swap(SigningInput* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SigningInput* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SigningInput* New() const final {
    return CreateMaybeMessage<SigningInput>(nullptr);
  }

  SigningInput* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SigningInput>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SigningInput& from);
  void MergeFrom(const SigningInput& from);
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
  void InternalSwap(SigningInput* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "TW.Filecoin.Proto.SigningInput";
  }
  protected:
  explicit SigningInput(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_Filecoin_2eproto);
    return ::descriptor_table_Filecoin_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPrivateKeyFieldNumber = 1,
    kToFieldNumber = 2,
    kValueFieldNumber = 4,
    kGasFeeCapFieldNumber = 6,
    kGasPremiumFieldNumber = 7,
    kNonceFieldNumber = 3,
    kGasLimitFieldNumber = 5,
  };
  // bytes private_key = 1;
  void clear_private_key();
  const std::string& private_key() const;
  void set_private_key(const std::string& value);
  void set_private_key(std::string&& value);
  void set_private_key(const char* value);
  void set_private_key(const void* value, size_t size);
  std::string* mutable_private_key();
  std::string* release_private_key();
  void set_allocated_private_key(std::string* private_key);
  private:
  const std::string& _internal_private_key() const;
  void _internal_set_private_key(const std::string& value);
  std::string* _internal_mutable_private_key();
  public:

  // string to = 2;
  void clear_to();
  const std::string& to() const;
  void set_to(const std::string& value);
  void set_to(std::string&& value);
  void set_to(const char* value);
  void set_to(const char* value, size_t size);
  std::string* mutable_to();
  std::string* release_to();
  void set_allocated_to(std::string* to);
  private:
  const std::string& _internal_to() const;
  void _internal_set_to(const std::string& value);
  std::string* _internal_mutable_to();
  public:

  // bytes value = 4;
  void clear_value();
  const std::string& value() const;
  void set_value(const std::string& value);
  void set_value(std::string&& value);
  void set_value(const char* value);
  void set_value(const void* value, size_t size);
  std::string* mutable_value();
  std::string* release_value();
  void set_allocated_value(std::string* value);
  private:
  const std::string& _internal_value() const;
  void _internal_set_value(const std::string& value);
  std::string* _internal_mutable_value();
  public:

  // bytes gas_fee_cap = 6;
  void clear_gas_fee_cap();
  const std::string& gas_fee_cap() const;
  void set_gas_fee_cap(const std::string& value);
  void set_gas_fee_cap(std::string&& value);
  void set_gas_fee_cap(const char* value);
  void set_gas_fee_cap(const void* value, size_t size);
  std::string* mutable_gas_fee_cap();
  std::string* release_gas_fee_cap();
  void set_allocated_gas_fee_cap(std::string* gas_fee_cap);
  private:
  const std::string& _internal_gas_fee_cap() const;
  void _internal_set_gas_fee_cap(const std::string& value);
  std::string* _internal_mutable_gas_fee_cap();
  public:

  // bytes gas_premium = 7;
  void clear_gas_premium();
  const std::string& gas_premium() const;
  void set_gas_premium(const std::string& value);
  void set_gas_premium(std::string&& value);
  void set_gas_premium(const char* value);
  void set_gas_premium(const void* value, size_t size);
  std::string* mutable_gas_premium();
  std::string* release_gas_premium();
  void set_allocated_gas_premium(std::string* gas_premium);
  private:
  const std::string& _internal_gas_premium() const;
  void _internal_set_gas_premium(const std::string& value);
  std::string* _internal_mutable_gas_premium();
  public:

  // uint64 nonce = 3;
  void clear_nonce();
  ::PROTOBUF_NAMESPACE_ID::uint64 nonce() const;
  void set_nonce(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_nonce() const;
  void _internal_set_nonce(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // int64 gas_limit = 5;
  void clear_gas_limit();
  ::PROTOBUF_NAMESPACE_ID::int64 gas_limit() const;
  void set_gas_limit(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_gas_limit() const;
  void _internal_set_gas_limit(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // @@protoc_insertion_point(class_scope:TW.Filecoin.Proto.SigningInput)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr private_key_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr to_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr value_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr gas_fee_cap_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr gas_premium_;
  ::PROTOBUF_NAMESPACE_ID::uint64 nonce_;
  ::PROTOBUF_NAMESPACE_ID::int64 gas_limit_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Filecoin_2eproto;
};
// -------------------------------------------------------------------

class SigningOutput PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:TW.Filecoin.Proto.SigningOutput) */ {
 public:
  inline SigningOutput() : SigningOutput(nullptr) {}
  virtual ~SigningOutput();

  SigningOutput(const SigningOutput& from);
  SigningOutput(SigningOutput&& from) noexcept
    : SigningOutput() {
    *this = ::std::move(from);
  }

  inline SigningOutput& operator=(const SigningOutput& from) {
    CopyFrom(from);
    return *this;
  }
  inline SigningOutput& operator=(SigningOutput&& from) noexcept {
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
  static const SigningOutput& default_instance();

  static inline const SigningOutput* internal_default_instance() {
    return reinterpret_cast<const SigningOutput*>(
               &_SigningOutput_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(SigningOutput& a, SigningOutput& b) {
    a.Swap(&b);
  }
  inline void Swap(SigningOutput* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SigningOutput* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SigningOutput* New() const final {
    return CreateMaybeMessage<SigningOutput>(nullptr);
  }

  SigningOutput* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SigningOutput>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SigningOutput& from);
  void MergeFrom(const SigningOutput& from);
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
  void InternalSwap(SigningOutput* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "TW.Filecoin.Proto.SigningOutput";
  }
  protected:
  explicit SigningOutput(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_Filecoin_2eproto);
    return ::descriptor_table_Filecoin_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kJsonFieldNumber = 1,
  };
  // string json = 1;
  void clear_json();
  const std::string& json() const;
  void set_json(const std::string& value);
  void set_json(std::string&& value);
  void set_json(const char* value);
  void set_json(const char* value, size_t size);
  std::string* mutable_json();
  std::string* release_json();
  void set_allocated_json(std::string* json);
  private:
  const std::string& _internal_json() const;
  void _internal_set_json(const std::string& value);
  std::string* _internal_mutable_json();
  public:

  // @@protoc_insertion_point(class_scope:TW.Filecoin.Proto.SigningOutput)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr json_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Filecoin_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SigningInput

// bytes private_key = 1;
inline void SigningInput::clear_private_key() {
  private_key_.ClearToEmpty();
}
inline const std::string& SigningInput::private_key() const {
  // @@protoc_insertion_point(field_get:TW.Filecoin.Proto.SigningInput.private_key)
  return _internal_private_key();
}
inline void SigningInput::set_private_key(const std::string& value) {
  _internal_set_private_key(value);
  // @@protoc_insertion_point(field_set:TW.Filecoin.Proto.SigningInput.private_key)
}
inline std::string* SigningInput::mutable_private_key() {
  // @@protoc_insertion_point(field_mutable:TW.Filecoin.Proto.SigningInput.private_key)
  return _internal_mutable_private_key();
}
inline const std::string& SigningInput::_internal_private_key() const {
  return private_key_.Get();
}
inline void SigningInput::_internal_set_private_key(const std::string& value) {
  
  private_key_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void SigningInput::set_private_key(std::string&& value) {
  
  private_key_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:TW.Filecoin.Proto.SigningInput.private_key)
}
inline void SigningInput::set_private_key(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  private_key_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:TW.Filecoin.Proto.SigningInput.private_key)
}
inline void SigningInput::set_private_key(const void* value,
    size_t size) {
  
  private_key_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:TW.Filecoin.Proto.SigningInput.private_key)
}
inline std::string* SigningInput::_internal_mutable_private_key() {
  
  return private_key_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* SigningInput::release_private_key() {
  // @@protoc_insertion_point(field_release:TW.Filecoin.Proto.SigningInput.private_key)
  return private_key_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SigningInput::set_allocated_private_key(std::string* private_key) {
  if (private_key != nullptr) {
    
  } else {
    
  }
  private_key_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), private_key,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:TW.Filecoin.Proto.SigningInput.private_key)
}

// string to = 2;
inline void SigningInput::clear_to() {
  to_.ClearToEmpty();
}
inline const std::string& SigningInput::to() const {
  // @@protoc_insertion_point(field_get:TW.Filecoin.Proto.SigningInput.to)
  return _internal_to();
}
inline void SigningInput::set_to(const std::string& value) {
  _internal_set_to(value);
  // @@protoc_insertion_point(field_set:TW.Filecoin.Proto.SigningInput.to)
}
inline std::string* SigningInput::mutable_to() {
  // @@protoc_insertion_point(field_mutable:TW.Filecoin.Proto.SigningInput.to)
  return _internal_mutable_to();
}
inline const std::string& SigningInput::_internal_to() const {
  return to_.Get();
}
inline void SigningInput::_internal_set_to(const std::string& value) {
  
  to_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void SigningInput::set_to(std::string&& value) {
  
  to_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:TW.Filecoin.Proto.SigningInput.to)
}
inline void SigningInput::set_to(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  to_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:TW.Filecoin.Proto.SigningInput.to)
}
inline void SigningInput::set_to(const char* value,
    size_t size) {
  
  to_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:TW.Filecoin.Proto.SigningInput.to)
}
inline std::string* SigningInput::_internal_mutable_to() {
  
  return to_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* SigningInput::release_to() {
  // @@protoc_insertion_point(field_release:TW.Filecoin.Proto.SigningInput.to)
  return to_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SigningInput::set_allocated_to(std::string* to) {
  if (to != nullptr) {
    
  } else {
    
  }
  to_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), to,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:TW.Filecoin.Proto.SigningInput.to)
}

// uint64 nonce = 3;
inline void SigningInput::clear_nonce() {
  nonce_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 SigningInput::_internal_nonce() const {
  return nonce_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 SigningInput::nonce() const {
  // @@protoc_insertion_point(field_get:TW.Filecoin.Proto.SigningInput.nonce)
  return _internal_nonce();
}
inline void SigningInput::_internal_set_nonce(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  nonce_ = value;
}
inline void SigningInput::set_nonce(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_nonce(value);
  // @@protoc_insertion_point(field_set:TW.Filecoin.Proto.SigningInput.nonce)
}

// bytes value = 4;
inline void SigningInput::clear_value() {
  value_.ClearToEmpty();
}
inline const std::string& SigningInput::value() const {
  // @@protoc_insertion_point(field_get:TW.Filecoin.Proto.SigningInput.value)
  return _internal_value();
}
inline void SigningInput::set_value(const std::string& value) {
  _internal_set_value(value);
  // @@protoc_insertion_point(field_set:TW.Filecoin.Proto.SigningInput.value)
}
inline std::string* SigningInput::mutable_value() {
  // @@protoc_insertion_point(field_mutable:TW.Filecoin.Proto.SigningInput.value)
  return _internal_mutable_value();
}
inline const std::string& SigningInput::_internal_value() const {
  return value_.Get();
}
inline void SigningInput::_internal_set_value(const std::string& value) {
  
  value_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void SigningInput::set_value(std::string&& value) {
  
  value_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:TW.Filecoin.Proto.SigningInput.value)
}
inline void SigningInput::set_value(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  value_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:TW.Filecoin.Proto.SigningInput.value)
}
inline void SigningInput::set_value(const void* value,
    size_t size) {
  
  value_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:TW.Filecoin.Proto.SigningInput.value)
}
inline std::string* SigningInput::_internal_mutable_value() {
  
  return value_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* SigningInput::release_value() {
  // @@protoc_insertion_point(field_release:TW.Filecoin.Proto.SigningInput.value)
  return value_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SigningInput::set_allocated_value(std::string* value) {
  if (value != nullptr) {
    
  } else {
    
  }
  value_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:TW.Filecoin.Proto.SigningInput.value)
}

// int64 gas_limit = 5;
inline void SigningInput::clear_gas_limit() {
  gas_limit_ = PROTOBUF_LONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::int64 SigningInput::_internal_gas_limit() const {
  return gas_limit_;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 SigningInput::gas_limit() const {
  // @@protoc_insertion_point(field_get:TW.Filecoin.Proto.SigningInput.gas_limit)
  return _internal_gas_limit();
}
inline void SigningInput::_internal_set_gas_limit(::PROTOBUF_NAMESPACE_ID::int64 value) {
  
  gas_limit_ = value;
}
inline void SigningInput::set_gas_limit(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_gas_limit(value);
  // @@protoc_insertion_point(field_set:TW.Filecoin.Proto.SigningInput.gas_limit)
}

// bytes gas_fee_cap = 6;
inline void SigningInput::clear_gas_fee_cap() {
  gas_fee_cap_.ClearToEmpty();
}
inline const std::string& SigningInput::gas_fee_cap() const {
  // @@protoc_insertion_point(field_get:TW.Filecoin.Proto.SigningInput.gas_fee_cap)
  return _internal_gas_fee_cap();
}
inline void SigningInput::set_gas_fee_cap(const std::string& value) {
  _internal_set_gas_fee_cap(value);
  // @@protoc_insertion_point(field_set:TW.Filecoin.Proto.SigningInput.gas_fee_cap)
}
inline std::string* SigningInput::mutable_gas_fee_cap() {
  // @@protoc_insertion_point(field_mutable:TW.Filecoin.Proto.SigningInput.gas_fee_cap)
  return _internal_mutable_gas_fee_cap();
}
inline const std::string& SigningInput::_internal_gas_fee_cap() const {
  return gas_fee_cap_.Get();
}
inline void SigningInput::_internal_set_gas_fee_cap(const std::string& value) {
  
  gas_fee_cap_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void SigningInput::set_gas_fee_cap(std::string&& value) {
  
  gas_fee_cap_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:TW.Filecoin.Proto.SigningInput.gas_fee_cap)
}
inline void SigningInput::set_gas_fee_cap(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  gas_fee_cap_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:TW.Filecoin.Proto.SigningInput.gas_fee_cap)
}
inline void SigningInput::set_gas_fee_cap(const void* value,
    size_t size) {
  
  gas_fee_cap_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:TW.Filecoin.Proto.SigningInput.gas_fee_cap)
}
inline std::string* SigningInput::_internal_mutable_gas_fee_cap() {
  
  return gas_fee_cap_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* SigningInput::release_gas_fee_cap() {
  // @@protoc_insertion_point(field_release:TW.Filecoin.Proto.SigningInput.gas_fee_cap)
  return gas_fee_cap_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SigningInput::set_allocated_gas_fee_cap(std::string* gas_fee_cap) {
  if (gas_fee_cap != nullptr) {
    
  } else {
    
  }
  gas_fee_cap_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), gas_fee_cap,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:TW.Filecoin.Proto.SigningInput.gas_fee_cap)
}

// bytes gas_premium = 7;
inline void SigningInput::clear_gas_premium() {
  gas_premium_.ClearToEmpty();
}
inline const std::string& SigningInput::gas_premium() const {
  // @@protoc_insertion_point(field_get:TW.Filecoin.Proto.SigningInput.gas_premium)
  return _internal_gas_premium();
}
inline void SigningInput::set_gas_premium(const std::string& value) {
  _internal_set_gas_premium(value);
  // @@protoc_insertion_point(field_set:TW.Filecoin.Proto.SigningInput.gas_premium)
}
inline std::string* SigningInput::mutable_gas_premium() {
  // @@protoc_insertion_point(field_mutable:TW.Filecoin.Proto.SigningInput.gas_premium)
  return _internal_mutable_gas_premium();
}
inline const std::string& SigningInput::_internal_gas_premium() const {
  return gas_premium_.Get();
}
inline void SigningInput::_internal_set_gas_premium(const std::string& value) {
  
  gas_premium_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void SigningInput::set_gas_premium(std::string&& value) {
  
  gas_premium_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:TW.Filecoin.Proto.SigningInput.gas_premium)
}
inline void SigningInput::set_gas_premium(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  gas_premium_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:TW.Filecoin.Proto.SigningInput.gas_premium)
}
inline void SigningInput::set_gas_premium(const void* value,
    size_t size) {
  
  gas_premium_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:TW.Filecoin.Proto.SigningInput.gas_premium)
}
inline std::string* SigningInput::_internal_mutable_gas_premium() {
  
  return gas_premium_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* SigningInput::release_gas_premium() {
  // @@protoc_insertion_point(field_release:TW.Filecoin.Proto.SigningInput.gas_premium)
  return gas_premium_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SigningInput::set_allocated_gas_premium(std::string* gas_premium) {
  if (gas_premium != nullptr) {
    
  } else {
    
  }
  gas_premium_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), gas_premium,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:TW.Filecoin.Proto.SigningInput.gas_premium)
}

// -------------------------------------------------------------------

// SigningOutput

// string json = 1;
inline void SigningOutput::clear_json() {
  json_.ClearToEmpty();
}
inline const std::string& SigningOutput::json() const {
  // @@protoc_insertion_point(field_get:TW.Filecoin.Proto.SigningOutput.json)
  return _internal_json();
}
inline void SigningOutput::set_json(const std::string& value) {
  _internal_set_json(value);
  // @@protoc_insertion_point(field_set:TW.Filecoin.Proto.SigningOutput.json)
}
inline std::string* SigningOutput::mutable_json() {
  // @@protoc_insertion_point(field_mutable:TW.Filecoin.Proto.SigningOutput.json)
  return _internal_mutable_json();
}
inline const std::string& SigningOutput::_internal_json() const {
  return json_.Get();
}
inline void SigningOutput::_internal_set_json(const std::string& value) {
  
  json_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void SigningOutput::set_json(std::string&& value) {
  
  json_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:TW.Filecoin.Proto.SigningOutput.json)
}
inline void SigningOutput::set_json(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  json_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:TW.Filecoin.Proto.SigningOutput.json)
}
inline void SigningOutput::set_json(const char* value,
    size_t size) {
  
  json_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:TW.Filecoin.Proto.SigningOutput.json)
}
inline std::string* SigningOutput::_internal_mutable_json() {
  
  return json_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* SigningOutput::release_json() {
  // @@protoc_insertion_point(field_release:TW.Filecoin.Proto.SigningOutput.json)
  return json_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SigningOutput::set_allocated_json(std::string* json) {
  if (json != nullptr) {
    
  } else {
    
  }
  json_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), json,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:TW.Filecoin.Proto.SigningOutput.json)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Proto
}  // namespace Filecoin
}  // namespace TW

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Filecoin_2eproto
