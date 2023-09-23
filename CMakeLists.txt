cmake_minimum_required(VERSION 3.27)
project(dxbc LANGUAGES CXX)

option(BUILD_EXAMPLE "Build example application" ON)

find_package(Vulkan REQUIRED)

add_subdirectory(include/windows)
add_subdirectory(src/util)
add_subdirectory(src/spirv)
add_subdirectory(src/dxbc)

if (BUILD_EXAMPLE)
    add_subdirectory(example)
endif()