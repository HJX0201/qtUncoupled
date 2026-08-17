cmake_minimum_required(VERSION 3.16)

if(NOT DEFINED OUTPUT_DIR OR OUTPUT_DIR STREQUAL "")
    message(FATAL_ERROR "OUTPUT_DIR is required")
endif()

get_filename_component(output_root "${OUTPUT_DIR}" ABSOLUTE)
include("${CMAKE_CURRENT_LIST_DIR}/GenerateBenchmarkSources.cmake")

generate_benchmark_sources(
    direct_binding
    200
    direct_sources
    "${output_root}"
)
generate_benchmark_sources(
    string_registry
    200
    registry_sources
    "${output_root}"
)

list(LENGTH direct_sources direct_source_count)
list(LENGTH registry_sources registry_source_count)
message(STATUS
    "Published source snapshot exported to ${output_root} "
    "(${direct_source_count} direct files, ${registry_source_count} registry files)")
