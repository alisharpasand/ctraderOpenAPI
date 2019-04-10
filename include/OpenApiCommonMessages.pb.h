// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: OpenApiCommonMessages.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_OpenApiCommonMessages_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_OpenApiCommonMessages_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3007000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3007000 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "OpenApiCommonModelMessages.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_OpenApiCommonMessages_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_OpenApiCommonMessages_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
void AddDescriptors_OpenApiCommonMessages_2eproto();
class ProtoErrorRes;
class ProtoErrorResDefaultTypeInternal;
extern ProtoErrorResDefaultTypeInternal _ProtoErrorRes_default_instance_;
class ProtoHeartbeatEvent;
class ProtoHeartbeatEventDefaultTypeInternal;
extern ProtoHeartbeatEventDefaultTypeInternal _ProtoHeartbeatEvent_default_instance_;
class ProtoMessage;
class ProtoMessageDefaultTypeInternal;
extern ProtoMessageDefaultTypeInternal _ProtoMessage_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::ProtoErrorRes* Arena::CreateMaybeMessage<::ProtoErrorRes>(Arena*);
template<> ::ProtoHeartbeatEvent* Arena::CreateMaybeMessage<::ProtoHeartbeatEvent>(Arena*);
template<> ::ProtoMessage* Arena::CreateMaybeMessage<::ProtoMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class ProtoMessage final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ProtoMessage) */ {
 public:
  ProtoMessage();
  virtual ~ProtoMessage();

  ProtoMessage(const ProtoMessage& from);
  ProtoMessage(ProtoMessage&& from) noexcept
    : ProtoMessage() {
    *this = ::std::move(from);
  }

  inline ProtoMessage& operator=(const ProtoMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline ProtoMessage& operator=(ProtoMessage&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const ProtoMessage& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ProtoMessage* internal_default_instance() {
    return reinterpret_cast<const ProtoMessage*>(
               &_ProtoMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(ProtoMessage* other);
  friend void swap(ProtoMessage& a, ProtoMessage& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ProtoMessage* New() const final {
    return CreateMaybeMessage<ProtoMessage>(nullptr);
  }

  ProtoMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ProtoMessage>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ProtoMessage& from);
  void MergeFrom(const ProtoMessage& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ProtoMessage* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ProtoMessage";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bytes payload = 2;
  bool has_payload() const;
  void clear_payload();
  static const int kPayloadFieldNumber = 2;
  const std::string& payload() const;
  void set_payload(const std::string& value);
  void set_payload(std::string&& value);
  void set_payload(const char* value);
  void set_payload(const void* value, size_t size);
  std::string* mutable_payload();
  std::string* release_payload();
  void set_allocated_payload(std::string* payload);

  // optional string clientMsgId = 3;
  bool has_clientmsgid() const;
  void clear_clientmsgid();
  static const int kClientMsgIdFieldNumber = 3;
  const std::string& clientmsgid() const;
  void set_clientmsgid(const std::string& value);
  void set_clientmsgid(std::string&& value);
  void set_clientmsgid(const char* value);
  void set_clientmsgid(const char* value, size_t size);
  std::string* mutable_clientmsgid();
  std::string* release_clientmsgid();
  void set_allocated_clientmsgid(std::string* clientmsgid);

  // required uint32 payloadType = 1;
  bool has_payloadtype() const;
  void clear_payloadtype();
  static const int kPayloadTypeFieldNumber = 1;
  ::PROTOBUF_NAMESPACE_ID::uint32 payloadtype() const;
  void set_payloadtype(::PROTOBUF_NAMESPACE_ID::uint32 value);

  // @@protoc_insertion_point(class_scope:ProtoMessage)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr payload_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr clientmsgid_;
  ::PROTOBUF_NAMESPACE_ID::uint32 payloadtype_;
  friend struct ::TableStruct_OpenApiCommonMessages_2eproto;
};
// -------------------------------------------------------------------

class ProtoErrorRes final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ProtoErrorRes) */ {
 public:
  ProtoErrorRes();
  virtual ~ProtoErrorRes();

  ProtoErrorRes(const ProtoErrorRes& from);
  ProtoErrorRes(ProtoErrorRes&& from) noexcept
    : ProtoErrorRes() {
    *this = ::std::move(from);
  }

  inline ProtoErrorRes& operator=(const ProtoErrorRes& from) {
    CopyFrom(from);
    return *this;
  }
  inline ProtoErrorRes& operator=(ProtoErrorRes&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const ProtoErrorRes& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ProtoErrorRes* internal_default_instance() {
    return reinterpret_cast<const ProtoErrorRes*>(
               &_ProtoErrorRes_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(ProtoErrorRes* other);
  friend void swap(ProtoErrorRes& a, ProtoErrorRes& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ProtoErrorRes* New() const final {
    return CreateMaybeMessage<ProtoErrorRes>(nullptr);
  }

  ProtoErrorRes* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ProtoErrorRes>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ProtoErrorRes& from);
  void MergeFrom(const ProtoErrorRes& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ProtoErrorRes* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ProtoErrorRes";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string errorCode = 2;
  bool has_errorcode() const;
  void clear_errorcode();
  static const int kErrorCodeFieldNumber = 2;
  const std::string& errorcode() const;
  void set_errorcode(const std::string& value);
  void set_errorcode(std::string&& value);
  void set_errorcode(const char* value);
  void set_errorcode(const char* value, size_t size);
  std::string* mutable_errorcode();
  std::string* release_errorcode();
  void set_allocated_errorcode(std::string* errorcode);

  // optional string description = 3;
  bool has_description() const;
  void clear_description();
  static const int kDescriptionFieldNumber = 3;
  const std::string& description() const;
  void set_description(const std::string& value);
  void set_description(std::string&& value);
  void set_description(const char* value);
  void set_description(const char* value, size_t size);
  std::string* mutable_description();
  std::string* release_description();
  void set_allocated_description(std::string* description);

  // optional uint64 maintenanceEndTimestamp = 4;
  bool has_maintenanceendtimestamp() const;
  void clear_maintenanceendtimestamp();
  static const int kMaintenanceEndTimestampFieldNumber = 4;
  ::PROTOBUF_NAMESPACE_ID::uint64 maintenanceendtimestamp() const;
  void set_maintenanceendtimestamp(::PROTOBUF_NAMESPACE_ID::uint64 value);

  // optional .ProtoPayloadType payloadType = 1 [default = ERROR_RES];
  bool has_payloadtype() const;
  void clear_payloadtype();
  static const int kPayloadTypeFieldNumber = 1;
  ::ProtoPayloadType payloadtype() const;
  void set_payloadtype(::ProtoPayloadType value);

  // @@protoc_insertion_point(class_scope:ProtoErrorRes)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr errorcode_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr description_;
  ::PROTOBUF_NAMESPACE_ID::uint64 maintenanceendtimestamp_;
  int payloadtype_;
  friend struct ::TableStruct_OpenApiCommonMessages_2eproto;
};
// -------------------------------------------------------------------

class ProtoHeartbeatEvent final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ProtoHeartbeatEvent) */ {
 public:
  ProtoHeartbeatEvent();
  virtual ~ProtoHeartbeatEvent();

  ProtoHeartbeatEvent(const ProtoHeartbeatEvent& from);
  ProtoHeartbeatEvent(ProtoHeartbeatEvent&& from) noexcept
    : ProtoHeartbeatEvent() {
    *this = ::std::move(from);
  }

  inline ProtoHeartbeatEvent& operator=(const ProtoHeartbeatEvent& from) {
    CopyFrom(from);
    return *this;
  }
  inline ProtoHeartbeatEvent& operator=(ProtoHeartbeatEvent&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const ProtoHeartbeatEvent& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ProtoHeartbeatEvent* internal_default_instance() {
    return reinterpret_cast<const ProtoHeartbeatEvent*>(
               &_ProtoHeartbeatEvent_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(ProtoHeartbeatEvent* other);
  friend void swap(ProtoHeartbeatEvent& a, ProtoHeartbeatEvent& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ProtoHeartbeatEvent* New() const final {
    return CreateMaybeMessage<ProtoHeartbeatEvent>(nullptr);
  }

  ProtoHeartbeatEvent* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ProtoHeartbeatEvent>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ProtoHeartbeatEvent& from);
  void MergeFrom(const ProtoHeartbeatEvent& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ProtoHeartbeatEvent* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ProtoHeartbeatEvent";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .ProtoPayloadType payloadType = 1 [default = HEARTBEAT_EVENT];
  bool has_payloadtype() const;
  void clear_payloadtype();
  static const int kPayloadTypeFieldNumber = 1;
  ::ProtoPayloadType payloadtype() const;
  void set_payloadtype(::ProtoPayloadType value);

  // @@protoc_insertion_point(class_scope:ProtoHeartbeatEvent)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  int payloadtype_;
  friend struct ::TableStruct_OpenApiCommonMessages_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ProtoMessage

// required uint32 payloadType = 1;
inline bool ProtoMessage::has_payloadtype() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ProtoMessage::clear_payloadtype() {
  payloadtype_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 ProtoMessage::payloadtype() const {
  // @@protoc_insertion_point(field_get:ProtoMessage.payloadType)
  return payloadtype_;
}
inline void ProtoMessage::set_payloadtype(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000004u;
  payloadtype_ = value;
  // @@protoc_insertion_point(field_set:ProtoMessage.payloadType)
}

// optional bytes payload = 2;
inline bool ProtoMessage::has_payload() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ProtoMessage::clear_payload() {
  payload_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& ProtoMessage::payload() const {
  // @@protoc_insertion_point(field_get:ProtoMessage.payload)
  return payload_.GetNoArena();
}
inline void ProtoMessage::set_payload(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  payload_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ProtoMessage.payload)
}
inline void ProtoMessage::set_payload(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  payload_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ProtoMessage.payload)
}
inline void ProtoMessage::set_payload(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  payload_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ProtoMessage.payload)
}
inline void ProtoMessage::set_payload(const void* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  payload_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ProtoMessage.payload)
}
inline std::string* ProtoMessage::mutable_payload() {
  _has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_mutable:ProtoMessage.payload)
  return payload_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ProtoMessage::release_payload() {
  // @@protoc_insertion_point(field_release:ProtoMessage.payload)
  if (!has_payload()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return payload_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ProtoMessage::set_allocated_payload(std::string* payload) {
  if (payload != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  payload_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), payload);
  // @@protoc_insertion_point(field_set_allocated:ProtoMessage.payload)
}

// optional string clientMsgId = 3;
inline bool ProtoMessage::has_clientmsgid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ProtoMessage::clear_clientmsgid() {
  clientmsgid_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& ProtoMessage::clientmsgid() const {
  // @@protoc_insertion_point(field_get:ProtoMessage.clientMsgId)
  return clientmsgid_.GetNoArena();
}
inline void ProtoMessage::set_clientmsgid(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  clientmsgid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ProtoMessage.clientMsgId)
}
inline void ProtoMessage::set_clientmsgid(std::string&& value) {
  _has_bits_[0] |= 0x00000002u;
  clientmsgid_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ProtoMessage.clientMsgId)
}
inline void ProtoMessage::set_clientmsgid(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000002u;
  clientmsgid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ProtoMessage.clientMsgId)
}
inline void ProtoMessage::set_clientmsgid(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000002u;
  clientmsgid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ProtoMessage.clientMsgId)
}
inline std::string* ProtoMessage::mutable_clientmsgid() {
  _has_bits_[0] |= 0x00000002u;
  // @@protoc_insertion_point(field_mutable:ProtoMessage.clientMsgId)
  return clientmsgid_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ProtoMessage::release_clientmsgid() {
  // @@protoc_insertion_point(field_release:ProtoMessage.clientMsgId)
  if (!has_clientmsgid()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return clientmsgid_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ProtoMessage::set_allocated_clientmsgid(std::string* clientmsgid) {
  if (clientmsgid != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  clientmsgid_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), clientmsgid);
  // @@protoc_insertion_point(field_set_allocated:ProtoMessage.clientMsgId)
}

// -------------------------------------------------------------------

// ProtoErrorRes

// optional .ProtoPayloadType payloadType = 1 [default = ERROR_RES];
inline bool ProtoErrorRes::has_payloadtype() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void ProtoErrorRes::clear_payloadtype() {
  payloadtype_ = 50;
  _has_bits_[0] &= ~0x00000008u;
}
inline ::ProtoPayloadType ProtoErrorRes::payloadtype() const {
  // @@protoc_insertion_point(field_get:ProtoErrorRes.payloadType)
  return static_cast< ::ProtoPayloadType >(payloadtype_);
}
inline void ProtoErrorRes::set_payloadtype(::ProtoPayloadType value) {
  assert(::ProtoPayloadType_IsValid(value));
  _has_bits_[0] |= 0x00000008u;
  payloadtype_ = value;
  // @@protoc_insertion_point(field_set:ProtoErrorRes.payloadType)
}

// required string errorCode = 2;
inline bool ProtoErrorRes::has_errorcode() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ProtoErrorRes::clear_errorcode() {
  errorcode_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& ProtoErrorRes::errorcode() const {
  // @@protoc_insertion_point(field_get:ProtoErrorRes.errorCode)
  return errorcode_.GetNoArena();
}
inline void ProtoErrorRes::set_errorcode(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  errorcode_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ProtoErrorRes.errorCode)
}
inline void ProtoErrorRes::set_errorcode(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  errorcode_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ProtoErrorRes.errorCode)
}
inline void ProtoErrorRes::set_errorcode(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  errorcode_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ProtoErrorRes.errorCode)
}
inline void ProtoErrorRes::set_errorcode(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  errorcode_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ProtoErrorRes.errorCode)
}
inline std::string* ProtoErrorRes::mutable_errorcode() {
  _has_bits_[0] |= 0x00000001u;
  // @@protoc_insertion_point(field_mutable:ProtoErrorRes.errorCode)
  return errorcode_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ProtoErrorRes::release_errorcode() {
  // @@protoc_insertion_point(field_release:ProtoErrorRes.errorCode)
  if (!has_errorcode()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return errorcode_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ProtoErrorRes::set_allocated_errorcode(std::string* errorcode) {
  if (errorcode != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  errorcode_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), errorcode);
  // @@protoc_insertion_point(field_set_allocated:ProtoErrorRes.errorCode)
}

// optional string description = 3;
inline bool ProtoErrorRes::has_description() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ProtoErrorRes::clear_description() {
  description_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& ProtoErrorRes::description() const {
  // @@protoc_insertion_point(field_get:ProtoErrorRes.description)
  return description_.GetNoArena();
}
inline void ProtoErrorRes::set_description(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  description_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ProtoErrorRes.description)
}
inline void ProtoErrorRes::set_description(std::string&& value) {
  _has_bits_[0] |= 0x00000002u;
  description_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ProtoErrorRes.description)
}
inline void ProtoErrorRes::set_description(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000002u;
  description_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ProtoErrorRes.description)
}
inline void ProtoErrorRes::set_description(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000002u;
  description_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ProtoErrorRes.description)
}
inline std::string* ProtoErrorRes::mutable_description() {
  _has_bits_[0] |= 0x00000002u;
  // @@protoc_insertion_point(field_mutable:ProtoErrorRes.description)
  return description_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ProtoErrorRes::release_description() {
  // @@protoc_insertion_point(field_release:ProtoErrorRes.description)
  if (!has_description()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return description_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ProtoErrorRes::set_allocated_description(std::string* description) {
  if (description != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  description_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), description);
  // @@protoc_insertion_point(field_set_allocated:ProtoErrorRes.description)
}

// optional uint64 maintenanceEndTimestamp = 4;
inline bool ProtoErrorRes::has_maintenanceendtimestamp() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ProtoErrorRes::clear_maintenanceendtimestamp() {
  maintenanceendtimestamp_ = PROTOBUF_ULONGLONG(0);
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 ProtoErrorRes::maintenanceendtimestamp() const {
  // @@protoc_insertion_point(field_get:ProtoErrorRes.maintenanceEndTimestamp)
  return maintenanceendtimestamp_;
}
inline void ProtoErrorRes::set_maintenanceendtimestamp(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _has_bits_[0] |= 0x00000004u;
  maintenanceendtimestamp_ = value;
  // @@protoc_insertion_point(field_set:ProtoErrorRes.maintenanceEndTimestamp)
}

// -------------------------------------------------------------------

// ProtoHeartbeatEvent

// optional .ProtoPayloadType payloadType = 1 [default = HEARTBEAT_EVENT];
inline bool ProtoHeartbeatEvent::has_payloadtype() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ProtoHeartbeatEvent::clear_payloadtype() {
  payloadtype_ = 51;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::ProtoPayloadType ProtoHeartbeatEvent::payloadtype() const {
  // @@protoc_insertion_point(field_get:ProtoHeartbeatEvent.payloadType)
  return static_cast< ::ProtoPayloadType >(payloadtype_);
}
inline void ProtoHeartbeatEvent::set_payloadtype(::ProtoPayloadType value) {
  assert(::ProtoPayloadType_IsValid(value));
  _has_bits_[0] |= 0x00000001u;
  payloadtype_ = value;
  // @@protoc_insertion_point(field_set:ProtoHeartbeatEvent.payloadType)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_OpenApiCommonMessages_2eproto