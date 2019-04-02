// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: OpenApiCommonModelMessages.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_OpenApiCommonModelMessages_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_OpenApiCommonModelMessages_2eproto

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
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_OpenApiCommonModelMessages_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_OpenApiCommonModelMessages_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
void AddDescriptors_OpenApiCommonModelMessages_2eproto();
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

enum ProtoPayloadType {
  PROTO_MESSAGE = 5,
  ERROR_RES = 50,
  HEARTBEAT_EVENT = 51
};
bool ProtoPayloadType_IsValid(int value);
constexpr ProtoPayloadType ProtoPayloadType_MIN = PROTO_MESSAGE;
constexpr ProtoPayloadType ProtoPayloadType_MAX = HEARTBEAT_EVENT;
constexpr int ProtoPayloadType_ARRAYSIZE = ProtoPayloadType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ProtoPayloadType_descriptor();
inline const std::string& ProtoPayloadType_Name(ProtoPayloadType value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ProtoPayloadType_descriptor(), value);
}
inline bool ProtoPayloadType_Parse(
    const std::string& name, ProtoPayloadType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ProtoPayloadType>(
    ProtoPayloadType_descriptor(), name, value);
}
enum ProtoErrorCode {
  UNKNOWN_ERROR = 1,
  UNSUPPORTED_MESSAGE = 2,
  INVALID_REQUEST = 3,
  WRONG_PASSWORD = 4,
  TIMEOUT_ERROR = 5,
  ENTITY_NOT_FOUND = 6,
  CANT_ROUTE_REQUEST = 7,
  FRAME_TOO_LONG = 8,
  MARKET_CLOSED = 9,
  CONCURRENT_MODIFICATION = 10,
  BLOCKED_PAYLOAD_TYPE = 11
};
bool ProtoErrorCode_IsValid(int value);
constexpr ProtoErrorCode ProtoErrorCode_MIN = UNKNOWN_ERROR;
constexpr ProtoErrorCode ProtoErrorCode_MAX = BLOCKED_PAYLOAD_TYPE;
constexpr int ProtoErrorCode_ARRAYSIZE = ProtoErrorCode_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ProtoErrorCode_descriptor();
inline const std::string& ProtoErrorCode_Name(ProtoErrorCode value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ProtoErrorCode_descriptor(), value);
}
inline bool ProtoErrorCode_Parse(
    const std::string& name, ProtoErrorCode* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ProtoErrorCode>(
    ProtoErrorCode_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::ProtoPayloadType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ProtoPayloadType>() {
  return ::ProtoPayloadType_descriptor();
}
template <> struct is_proto_enum< ::ProtoErrorCode> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ProtoErrorCode>() {
  return ::ProtoErrorCode_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_OpenApiCommonModelMessages_2eproto
