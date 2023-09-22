add_executable(dxbc-example)
target_sources(dxbc-example PRIVATE main.cpp)
target_link_libraries(dxbc-example PRIVATE dxbc spirv-cross-core spirv-cross-glsl)