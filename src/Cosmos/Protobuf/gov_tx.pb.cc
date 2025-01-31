// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: gov_tx.proto

#include "gov_tx.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace cosmos {
namespace gov {
namespace v1beta1 {
class MsgVoteDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<MsgVote> _instance;
} _MsgVote_default_instance_;
}  // namespace v1beta1
}  // namespace gov
}  // namespace cosmos
static void InitDefaultsscc_info_MsgVote_gov_5ftx_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::cosmos::gov::v1beta1::_MsgVote_default_instance_;
    new (ptr) ::cosmos::gov::v1beta1::MsgVote();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_MsgVote_gov_5ftx_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_MsgVote_gov_5ftx_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_gov_5ftx_2eproto[1];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_gov_5ftx_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_gov_5ftx_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_gov_5ftx_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::cosmos::gov::v1beta1::MsgVote, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::cosmos::gov::v1beta1::MsgVote, proposal_id_),
  PROTOBUF_FIELD_OFFSET(::cosmos::gov::v1beta1::MsgVote, voter_),
  PROTOBUF_FIELD_OFFSET(::cosmos::gov::v1beta1::MsgVote, option_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::cosmos::gov::v1beta1::MsgVote)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::cosmos::gov::v1beta1::_MsgVote_default_instance_),
};

const char descriptor_table_protodef_gov_5ftx_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014gov_tx.proto\022\022cosmos.gov.v1beta1\"]\n\007Ms"
  "gVote\022\023\n\013proposal_id\030\001 \001(\004\022\r\n\005voter\030\002 \001("
  "\t\022.\n\006option\030\003 \001(\0162\036.cosmos.gov.v1beta1.V"
  "oteOption*\211\001\n\nVoteOption\022\033\n\027VOTE_OPTION_"
  "UNSPECIFIED\020\000\022\023\n\017VOTE_OPTION_YES\020\001\022\027\n\023VO"
  "TE_OPTION_ABSTAIN\020\002\022\022\n\016VOTE_OPTION_NO\020\003\022"
  "\034\n\030VOTE_OPTION_NO_WITH_VETO\020\004b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_gov_5ftx_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_gov_5ftx_2eproto_sccs[1] = {
  &scc_info_MsgVote_gov_5ftx_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_gov_5ftx_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_gov_5ftx_2eproto = {
  false, false, descriptor_table_protodef_gov_5ftx_2eproto, "gov_tx.proto", 277,
  &descriptor_table_gov_5ftx_2eproto_once, descriptor_table_gov_5ftx_2eproto_sccs, descriptor_table_gov_5ftx_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_gov_5ftx_2eproto::offsets,
  file_level_metadata_gov_5ftx_2eproto, 1, file_level_enum_descriptors_gov_5ftx_2eproto, file_level_service_descriptors_gov_5ftx_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_gov_5ftx_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_gov_5ftx_2eproto)), true);
namespace cosmos {
namespace gov {
namespace v1beta1 {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* VoteOption_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_gov_5ftx_2eproto);
  return file_level_enum_descriptors_gov_5ftx_2eproto[0];
}
bool VoteOption_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class MsgVote::_Internal {
 public:
};

MsgVote::MsgVote(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:cosmos.gov.v1beta1.MsgVote)
}
MsgVote::MsgVote(const MsgVote& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  voter_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_voter().empty()) {
    voter_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_voter(), 
      GetArena());
  }
  ::memcpy(&proposal_id_, &from.proposal_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&option_) -
    reinterpret_cast<char*>(&proposal_id_)) + sizeof(option_));
  // @@protoc_insertion_point(copy_constructor:cosmos.gov.v1beta1.MsgVote)
}

void MsgVote::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_MsgVote_gov_5ftx_2eproto.base);
  voter_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
      reinterpret_cast<char*>(&proposal_id_) - reinterpret_cast<char*>(this)),
      0, static_cast<size_t>(reinterpret_cast<char*>(&option_) -
      reinterpret_cast<char*>(&proposal_id_)) + sizeof(option_));
}

MsgVote::~MsgVote() {
  // @@protoc_insertion_point(destructor:cosmos.gov.v1beta1.MsgVote)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void MsgVote::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  voter_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void MsgVote::ArenaDtor(void* object) {
  MsgVote* _this = reinterpret_cast< MsgVote* >(object);
  (void)_this;
}
void MsgVote::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void MsgVote::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const MsgVote& MsgVote::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_MsgVote_gov_5ftx_2eproto.base);
  return *internal_default_instance();
}


void MsgVote::Clear() {
// @@protoc_insertion_point(message_clear_start:cosmos.gov.v1beta1.MsgVote)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  voter_.ClearToEmpty();
  ::memset(&proposal_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&option_) -
      reinterpret_cast<char*>(&proposal_id_)) + sizeof(option_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* MsgVote::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // uint64 proposal_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          proposal_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string voter = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_voter();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "cosmos.gov.v1beta1.MsgVote.voter"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .cosmos.gov.v1beta1.VoteOption option = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_option(static_cast<::cosmos::gov::v1beta1::VoteOption>(val));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* MsgVote::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:cosmos.gov.v1beta1.MsgVote)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 proposal_id = 1;
  if (this->proposal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt64ToArray(1, this->_internal_proposal_id(), target);
  }

  // string voter = 2;
  if (this->voter().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_voter().data(), static_cast<int>(this->_internal_voter().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "cosmos.gov.v1beta1.MsgVote.voter");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_voter(), target);
  }

  // .cosmos.gov.v1beta1.VoteOption option = 3;
  if (this->option() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      3, this->_internal_option(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:cosmos.gov.v1beta1.MsgVote)
  return target;
}

size_t MsgVote::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:cosmos.gov.v1beta1.MsgVote)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string voter = 2;
  if (this->voter().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_voter());
  }

  // uint64 proposal_id = 1;
  if (this->proposal_id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt64Size(
        this->_internal_proposal_id());
  }

  // .cosmos.gov.v1beta1.VoteOption option = 3;
  if (this->option() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_option());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void MsgVote::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:cosmos.gov.v1beta1.MsgVote)
  GOOGLE_DCHECK_NE(&from, this);
  const MsgVote* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<MsgVote>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:cosmos.gov.v1beta1.MsgVote)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:cosmos.gov.v1beta1.MsgVote)
    MergeFrom(*source);
  }
}

void MsgVote::MergeFrom(const MsgVote& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:cosmos.gov.v1beta1.MsgVote)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.voter().size() > 0) {
    _internal_set_voter(from._internal_voter());
  }
  if (from.proposal_id() != 0) {
    _internal_set_proposal_id(from._internal_proposal_id());
  }
  if (from.option() != 0) {
    _internal_set_option(from._internal_option());
  }
}

void MsgVote::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:cosmos.gov.v1beta1.MsgVote)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MsgVote::CopyFrom(const MsgVote& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:cosmos.gov.v1beta1.MsgVote)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MsgVote::IsInitialized() const {
  return true;
}

void MsgVote::InternalSwap(MsgVote* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  voter_.Swap(&other->voter_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(MsgVote, option_)
      + sizeof(MsgVote::option_)
      - PROTOBUF_FIELD_OFFSET(MsgVote, proposal_id_)>(
          reinterpret_cast<char*>(&proposal_id_),
          reinterpret_cast<char*>(&other->proposal_id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata MsgVote::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace v1beta1
}  // namespace gov
}  // namespace cosmos
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::cosmos::gov::v1beta1::MsgVote* Arena::CreateMaybeMessage< ::cosmos::gov::v1beta1::MsgVote >(Arena* arena) {
  return Arena::CreateMessageInternal< ::cosmos::gov::v1beta1::MsgVote >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
