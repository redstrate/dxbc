cmake_minimum_required(VERSION 3.20)

project(dxbc LANGUAGES CXX)

option(BUILD_EXAMPLE "Build example application" ON)

find_package(Vulkan REQUIRED)
find_package(SPIRV-Headers REQUIRED)

if (NOT WIN32)
    add_subdirectory(include/windows)
endif()

add_subdirectory(src/util)
add_subdirectory(src/spirv)
add_subdirectory(src/dxbc)

if (BUILD_EXAMPLE)
    add_subdirectory(example)
endif()