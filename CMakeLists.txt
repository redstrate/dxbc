cmake_minimum_required(VERSION 3.27)
project(dxbc LANGUAGES CXX)

add_library(windows-headers INTERFACE)
target_include_directories(windows-headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/windows)

find_package(Vulkan REQUIRED)

add_subdirectory(src/util)
add_subdirectory(src/spirv)

add_library(dxbc STATIC)
target_sources(dxbc PRIVATE
        src/dxbc/dxbc_analysis.cpp
        src/dxbc/dxbc_analysis.h
        src/dxbc/dxbc_chunk_isgn.cpp
        src/dxbc/dxbc_chunk_isgn.h
        src/dxbc/dxbc_chunk_shex.cpp
        src/dxbc/dxbc_chunk_shex.h
        src/dxbc/dxbc_common.cpp
        src/dxbc/dxbc_common.h
        src/dxbc/dxbc_compiler.cpp
        src/dxbc/dxbc_compiler.h
        src/dxbc/dxbc_decoder.cpp
        src/dxbc/dxbc_decoder.h
        src/dxbc/dxbc_defs.cpp
        src/dxbc/dxbc_defs.h
        src/dxbc/dxbc_enums.h
        src/dxbc/dxbc_header.cpp
        src/dxbc/dxbc_header.h
        src/dxbc/dxbc_include.h
        src/dxbc/dxbc_modinfo.h
        src/dxbc/dxbc_module.cpp
        src/dxbc/dxbc_module.h
        src/dxbc/dxbc_names.cpp
        src/dxbc/dxbc_names.h
        src/dxbc/dxbc_options.cpp
        src/dxbc/dxbc_options.h
        src/dxbc/dxbc_reader.cpp
        src/dxbc/dxbc_reader.h
        src/dxbc/dxbc_tag.h
        src/dxbc/dxbc_util.cpp
        src/dxbc/dxbc_util.h
)
target_include_directories(dxbc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(dxbc PUBLIC dxbc-util dxbc-spirv Vulkan::Vulkan)

add_subdirectory(example)