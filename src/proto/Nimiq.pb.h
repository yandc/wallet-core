// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Nimiq.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Nimiq_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Nimiq_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_Nimiq_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Nimiq_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Nimiq_2eproto;
namespace TW {
namespace Nimiq {
namespace Proto {
class SigningInput;
class SigningInputDefaultTypeInternal;
extern SigningInputDefaultTypeInternal _SigningInput_default_instance_;
class SigningOutput;
class SigningOutputDefaultTypeInternal;
extern SigningOutputDefaultTypeInternal _SigningOutput_default_instance_;
}  // namespace Proto
}  // namespace Nimiq
}  // namespace TW
PROTOBUF_NAMESPACE_OPEN
template<> ::TW::Nimiq::Proto::SigningInput* Arena::CreateMaybeMessage<::TW::Nimiq::Proto::SigningInput>(Arena*);
template<> ::TW::Nimiq::Proto::SigningOutput* Arena::CreateMaybeMessage<::TW::Nimiq::Proto::SigningOutput>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace TW {
namespace Nimiq {
namespace Proto {

// ===================================================================

class SigningInput PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:TW.Nimiq.Proto.SigningInput) */ {
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
    return "TW.Nimiq.Proto.SigningInput";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_Nimiq_2eproto);
    return ::descriptor_table_Nimiq_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPrivateKeyFieldNumber = 1,
    kDestinationFieldNumber = 2,
    kValueFieldNumber = 3,
    kFeeFieldNumber = 4,
    kValidityStartHeightFieldNumber = 5,
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

  // string destination = 2;
  void clear_destination();
  const std::string& destination() const;
  void set_destination(const std::string& value);
  void set_destination(std::string&& value);
  void set_destination(const char* value);
  void set_destination(const char* value, size_t size);
  std::string* mutable_destination();
  std::string* release_destination();
  void set_allocated_destination(std::string* destination);
  private:
  const std::string& _internal_destination() const;
  void _internal_set_destination(const std::string& value);
  std::string* _internal_mutable_destination();
  public:

  // uint64 value = 3;
  void clear_value();
  ::PROTOBUF_NAMESPACE_ID::uint64 value() const;
  void set_value(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_value() const;
  void _internal_set_value(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // uint64 fee = 4;
  void clear_fee();
  ::PROTOBUF_NAMESPACE_ID::uint64 fee() const;
  void set_fee(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_fee() const;
  void _internal_set_fee(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // uint32 validity_start_height = 5;
  void clear_validity_start_height();
  ::PROTOBUF_NAMESPACE_ID::uint32 validity_start_height() const;
  void set_validity_start_height(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_validity_start_height() const;
  void _internal_set_validity_start_height(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:TW.Nimiq.Proto.SigningInput)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr private_key_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr destination_;
  ::PROTOBUF_NAMESPACE_ID::uint64 value_;
  ::PROTOBUF_NAMESPACE_ID::uint64 fee_;
  ::PROTOBUF_NAMESPACE_ID::uint32 validity_start_height_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Nimiq_2eproto;
};
// -------------------------------------------------------------------

class SigningOutput PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:TW.Nimiq.Proto.SigningOutput) */ {
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
    return "TW.Nimiq.Proto.SigningOutput";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_Nimiq_2eproto);
    return ::descriptor_table_Nimiq_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kEncodedFieldNumber = 1,
  };
  // bytes encoded = 1;
  void clear_encoded();
  const std::string& encoded() const;
  void set_encoded(const std::string& value);
  void set_encoded(std::string&& value);
  void set_encoded(const char* value);
  void set_encoded(const void* value, size_t size);
  std::string* mutable_encoded();
  std::string* release_encoded();
  void set_allocated_encoded(std::string* encoded);
  private:
  const std::string& _internal_encoded() const;
  void _internal_set_encoded(const std::string& value);
  std::string* _internal_mutable_encoded();
  public:

  // @@protoc_insertion_point(class_scope:TW.Nimiq.Proto.SigningOutput)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr encoded_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Nimiq_2eproto;
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
  // @@protoc_insertion_point(field_get:TW.Nimiq.Proto.SigningInput.private_key)
  return _internal_private_key();
}
inline void SigningInput::set_private_key(const std::string& value) {
  _internal_set_private_key(value);
  // @@protoc_insertion_point(field_set:TW.Nimiq.Proto.SigningInput.private_key)
}
inline std::string* SigningInput::mutable_private_key() {
  // @@protoc_insertion_point(field_mutable:TW.Nimiq.Proto.SigningInput.private_key)
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
  // @@protoc_insertion_point(field_set_rvalue:TW.Nimiq.Proto.SigningInput.private_key)
}
inline void SigningInput::set_private_key(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  private_key_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:TW.Nimiq.Proto.SigningInput.private_key)
}
inline void SigningInput::set_private_key(const void* value,
    size_t size) {
  
  private_key_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:TW.Nimiq.Proto.SigningInput.private_key)
}
inline std::string* SigningInput::_internal_mutable_private_key() {
  
  return private_key_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* SigningInput::release_private_key() {
  // @@protoc_insertion_point(field_release:TW.Nimiq.Proto.SigningInput.private_key)
  return private_key_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SigningInput::set_allocated_private_key(std::string* private_key) {
  if (private_key != nullptr) {
    
  } else {
    
  }
  private_key_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), private_key,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:TW.Nimiq.Proto.SigningInput.private_key)
}

// string destination = 2;
inline void SigningInput::clear_destination() {
  destination_.ClearToEmpty();
}
inline const std::string& SigningInput::destination() const {
  // @@protoc_insertion_point(field_get:TW.Nimiq.Proto.SigningInput.destination)
  return _internal_destination();
}
inline void SigningInput::set_destination(const std::string& value) {
  _internal_set_destination(value);
  // @@protoc_insertion_point(field_set:TW.Nimiq.Proto.SigningInput.destination)
}
inline std::string* SigningInput::mutable_destination() {
  // @@protoc_insertion_point(field_mutable:TW.Nimiq.Proto.SigningInput.destination)
  return _internal_mutable_destination();
}
inline const std::string& SigningInput::_internal_destination() const {
  return destination_.Get();
}
inline void SigningInput::_internal_set_destination(const std::string& value) {
  
  destination_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void SigningInput::set_destination(std::string&& value) {
  
  destination_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:TW.Nimiq.Proto.SigningInput.destination)
}
inline void SigningInput::set_destination(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  destination_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:TW.Nimiq.Proto.SigningInput.destination)
}
inline void SigningInput::set_destination(const char* value,
    size_t size) {
  
  destination_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:TW.Nimiq.Proto.SigningInput.destination)
}
inline std::string* SigningInput::_internal_mutable_destination() {
  
  return destination_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* SigningInput::release_destination() {
  // @@protoc_insertion_point(field_release:TW.Nimiq.Proto.SigningInput.destination)
  return destination_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SigningInput::set_allocated_destination(std::string* destination) {
  if (destination != nullptr) {
    
  } else {
    
  }
  destination_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), destination,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:TW.Nimiq.Proto.SigningInput.destination)
}

// uint64 value = 3;
inline void SigningInput::clear_value() {
  value_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 SigningInput::_internal_value() const {
  return value_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 SigningInput::value() const {
  // @@protoc_insertion_point(field_get:TW.Nimiq.Proto.SigningInput.value)
  return _internal_value();
}
inline void SigningInput::_internal_set_value(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  value_ = value;
}
inline void SigningInput::set_value(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_value(value);
  // @@protoc_insertion_point(field_set:TW.Nimiq.Proto.SigningInput.value)
}

// uint64 fee = 4;
inline void SigningInput::clear_fee() {
  fee_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 SigningInput::_internal_fee() const {
  return fee_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 SigningInput::fee() const {
  // @@protoc_insertion_point(field_get:TW.Nimiq.Proto.SigningInput.fee)
  return _internal_fee();
}
inline void SigningInput::_internal_set_fee(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  fee_ = value;
}
inline void SigningInput::set_fee(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_fee(value);
  // @@protoc_insertion_point(field_set:TW.Nimiq.Proto.SigningInput.fee)
}

// uint32 validity_start_height = 5;
inline void SigningInput::clear_validity_start_height() {
  validity_start_height_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SigningInput::_internal_validity_start_height() const {
  return validity_start_height_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SigningInput::validity_start_height() const {
  // @@protoc_insertion_point(field_get:TW.Nimiq.Proto.SigningInput.validity_start_height)
  return _internal_validity_start_height();
}
inline void SigningInput::_internal_set_validity_start_height(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  validity_start_height_ = value;
}
inline void SigningInput::set_validity_start_height(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_validity_start_height(value);
  // @@protoc_insertion_point(field_set:TW.Nimiq.Proto.SigningInput.validity_start_height)
}

// -------------------------------------------------------------------

// SigningOutput

// bytes encoded = 1;
inline void SigningOutput::clear_encoded() {
  encoded_.ClearToEmpty();
}
inline const std::string& SigningOutput::encoded() const {
  // @@protoc_insertion_point(field_get:TW.Nimiq.Proto.SigningOutput.encoded)
  return _internal_encoded();
}
inline void SigningOutput::set_encoded(const std::string& value) {
  _internal_set_encoded(value);
  // @@protoc_insertion_point(field_set:TW.Nimiq.Proto.SigningOutput.encoded)
}
inline std::string* SigningOutput::mutable_encoded() {
  // @@protoc_insertion_point(field_mutable:TW.Nimiq.Proto.SigningOutput.encoded)
  return _internal_mutable_encoded();
}
inline const std::string& SigningOutput::_internal_encoded() const {
  return encoded_.Get();
}
inline void SigningOutput::_internal_set_encoded(const std::string& value) {
  
  encoded_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void SigningOutput::set_encoded(std::string&& value) {
  
  encoded_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:TW.Nimiq.Proto.SigningOutput.encoded)
}
inline void SigningOutput::set_encoded(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  encoded_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:TW.Nimiq.Proto.SigningOutput.encoded)
}
inline void SigningOutput::set_encoded(const void* value,
    size_t size) {
  
  encoded_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:TW.Nimiq.Proto.SigningOutput.encoded)
}
inline std::string* SigningOutput::_internal_mutable_encoded() {
  
  return encoded_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* SigningOutput::release_encoded() {
  // @@protoc_insertion_point(field_release:TW.Nimiq.Proto.SigningOutput.encoded)
  return encoded_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SigningOutput::set_allocated_encoded(std::string* encoded) {
  if (encoded != nullptr) {
    
  } else {
    
  }
  encoded_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), encoded,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:TW.Nimiq.Proto.SigningOutput.encoded)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Proto
}  // namespace Nimiq
}  // namespace TW

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Nimiq_2eproto
