cmake_minimum_required(VERSION 3.16)

project(QtUiFunctionCompileBenchmark LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BENCH_VARIANT "direct_binding" CACHE STRING
    "Benchmark variant: direct_binding or string_registry")
set_property(CACHE BENCH_VARIANT PROPERTY STRINGS
             direct_binding string_registry)
set(BENCH_ACTION_COUNT "200" CACHE STRING "Number of generated actions")
option(BENCH_USE_PUBLISHED_SOURCES
    "Build the checked-in 200-function source snapshot instead of generated build-tree sources"
    OFF)

set(_valid_variants direct_binding string_registry)
if(NOT BENCH_VARIANT IN_LIST _valid_variants)
    message(FATAL_ERROR
        "Invalid BENCH_VARIANT='${BENCH_VARIANT}'. Expected one of: ${_valid_variants}")
endif()

if(NOT BENCH_ACTION_COUNT MATCHES "^[1-9][0-9]*$")
    message(FATAL_ERROR "BENCH_ACTION_COUNT must be a positive integer")
endif()

find_package(Qt5 5.12 REQUIRED COMPONENTS Widgets)

include(cmake/GenerateBenchmarkSources.cmake)
if(BENCH_USE_PUBLISHED_SOURCES)
    if(NOT BENCH_ACTION_COUNT STREQUAL "200")
        message(FATAL_ERROR
            "BENCH_USE_PUBLISHED_SOURCES requires BENCH_ACTION_COUNT=200")
    endif()
    set(published_source_dir
        "${CMAKE_CURRENT_SOURCE_DIR}/published-sources/${BENCH_VARIANT}")
    if(NOT EXISTS "${published_source_dir}/main.cpp")
        message(FATAL_ERROR
            "Published source snapshot not found: ${published_source_dir}")
    endif()
    file(GLOB generated_sources CONFIGURE_DEPENDS
        "${published_source_dir}/*.cpp"
        "${published_source_dir}/*.h"
    )
else()
    generate_benchmark_sources(
        "${BENCH_VARIANT}"
        "${BENCH_ACTION_COUNT}"
        generated_sources
    )
endif()

add_executable(compile_bench ${generated_sources})
target_link_libraries(compile_bench PRIVATE Qt5::Widgets)
target_compile_definitions(compile_bench PRIVATE
    BENCH_VARIANT_NAME="${BENCH_VARIANT}"
)

if(BENCH_VARIANT STREQUAL "direct_binding")
    set_target_properties(compile_bench PROPERTIES AUTOMOC ON)
endif()

if(MSVC)
    target_compile_options(compile_bench PRIVATE /W4 /permissive-)
else()
    target_compile_options(compile_bench PRIVATE -Wall -Wextra -Wpedantic)
endif()

enable_testing()
get_target_property(qt_qmake_path Qt5::qmake IMPORTED_LOCATION)
get_filename_component(qt_bin_path "${qt_qmake_path}" DIRECTORY)
get_filename_component(qt_install_prefix "${qt_bin_path}" DIRECTORY)
add_test(
    NAME equivalent_behavior
    COMMAND "${CMAKE_COMMAND}" -E env
        "PATH=${qt_bin_path};$ENV{PATH}"
        "QT_PLUGIN_PATH=${qt_install_prefix}/plugins"
        "QT_QPA_PLATFORM=offscreen"
        "$<TARGET_FILE:compile_bench>"
)

message(STATUS "Benchmark variant: ${BENCH_VARIANT}")
message(STATUS "Generated action count: ${BENCH_ACTION_COUNT}")
message(STATUS "Use published sources: ${BENCH_USE_PUBLISHED_SOURCES}")
message(STATUS "Qt version: ${Qt5_VERSION}")
