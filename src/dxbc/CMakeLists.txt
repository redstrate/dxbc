add_library(dxbc STATIC)
target_sources(dxbc PRIVATE
        dxbc_analysis.cpp
        dxbc_analysis.h
        dxbc_chunk_isgn.cpp
        dxbc_chunk_isgn.h
        dxbc_chunk_shex.cpp
        dxbc_chunk_shex.h
        dxbc_common.cpp
        dxbc_common.h
        dxbc_compiler.cpp
        dxbc_compiler.h
        dxbc_decoder.cpp
        dxbc_decoder.h
        dxbc_defs.cpp
        dxbc_defs.h
        dxbc_enums.h
        dxbc_header.cpp
        dxbc_header.h
        dxbc_include.h
        dxbc_modinfo.h
        dxbc_module.cpp
        dxbc_module.h
        dxbc_names.cpp
        dxbc_names.h
        dxbc_options.cpp
        dxbc_options.h
        dxbc_reader.cpp
        dxbc_reader.h
        dxbc_tag.h
        dxbc_util.cpp
        dxbc_util.h
)
target_include_directories(dxbc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(dxbc PUBLIC dxbc-util dxbc-spirv Vulkan::Vulkan)
target_compile_options(dxbc PRIVATE -fexceptions)