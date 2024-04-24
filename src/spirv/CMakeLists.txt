add_library(dxbc-spirv STATIC)
target_sources(dxbc-spirv PRIVATE
        spirv_code_buffer.cpp
        spirv_code_buffer.h
        spirv_compression.cpp
        spirv_compression.h
        spirv_include.h
        spirv_instruction.h
        spirv_module.cpp
        spirv_module.h
)
target_include_directories(dxbc-spirv SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(dxbc-spirv PUBLIC SPIRV-Headers::SPIRV-Headers)
target_compile_options(dxbc-spirv PRIVATE -w)
if (NOT WIN32)
    target_link_libraries(dxbc-spirv PUBLIC windows-headers)
endif()