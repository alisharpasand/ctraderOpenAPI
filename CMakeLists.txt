cmake_minimum_required(VERSION 3.14)
project(ctraderOpenAPI)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)

find_library(LIBPTHREAD pthread)
find_library(LIBSSL ssl)
find_library(LIBCRYPTO crypto)
find_library(LIBPROTOBUF protobuf)

link_libraries(pthread)
link_libraries(ssl)
link_libraries(crypto)
link_libraries(protobuf)

add_custom_command(
            OUTPUT protobuf-compiled/OpenApiCommonMessages.pb.h
                protobuf-compiled/OpenApiCommonModelMessages.pb.h
                protobuf-compiled/OpenApiMessages.pb.h
                protobuf-compiled/OpenApiMessagesFactory.h
                protobuf-compiled/OpenApiModelMessages.pb.h
                protobuf-compiled/OpenApiCommonMessages.pb.cc
                protobuf-compiled/OpenApiCommonModelMessages.pb.cc
                protobuf-compiled/OpenApiMessages.pb.cc
                protobuf-compiled/OpenApiMessagesFactory.cc
                protobuf-compiled/OpenApiModelMessages.pb.cc
            COMMAND mkdir -p ${CMAKE_CURRENT_BINARY_DIR}/protobuf-compiled &&
                protoc -I=${CMAKE_CURRENT_SOURCE_DIR}/protobuf --cpp_out=${CMAKE_CURRENT_BINARY_DIR}/protobuf-compiled
                ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/OpenApiCommonMessages.proto
                ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/OpenApiCommonModelMessages.proto
                ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/OpenApiMessages.proto
                ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/OpenApiModelMessages.proto
            VERBATIM
        )

include_directories(
                /usr/local/include
                /usr/local/opt/openssl/include
                ${CMAKE_CURRENT_BINARY_DIR}/protobuf-compiled
        )

link_directories(
                /usr/local/lib
                /usr/local/opt/openssl/lib
        )

add_compile_options(-Wall -Wno-write-strings -O3)

add_library(ctrader-openapi SHARED
        src/OpenApiMessagesFactory.cpp
        protobuf-compiled/OpenApiCommonMessages.pb.cc
        protobuf-compiled/OpenApiCommonModelMessages.pb.cc
        protobuf-compiled/OpenApiMessages.pb.cc
        protobuf-compiled/OpenApiModelMessages.pb.cc
        src/OpenApi.cpp
        src/NetworkWrapper.cpp)

set_target_properties(ctrader-openapi PROPERTIES
        PUBLIC_HEADER "${CMAKE_CURRENT_BINARY_DIR}/protobuf-compiled/OpenApiCommonMessages.pb.h;${CMAKE_CURRENT_BINARY_DIR}/protobuf-compiled/OpenApiCommonModelMessages.pb.h;${CMAKE_CURRENT_BINARY_DIR}/protobuf-compiled/OpenApiMessages.pb.h;${CMAKE_CURRENT_BINARY_DIR}/protobuf-compiled/OpenApiModelMessages.pb.h;include/OpenApiMessagesFactory.h;include/OpenApi.h;include/NetworkWrapper.h;include/MessageHandler.h;include/Buffer.h;include/NetworkMessage.h"
        )

add_executable(ctraderOpenApiExample
        src/main.cpp
        )

target_link_libraries(ctraderOpenApiExample
        ctrader-openapi
        )

install(TARGETS ctrader-openapi)
