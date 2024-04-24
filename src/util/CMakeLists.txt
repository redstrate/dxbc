add_library(dxbc-util STATIC)
target_sources(dxbc-util PRIVATE
        com/com_guid.cpp
        com/com_guid.h
        com/com_include.h
        com/com_object.h
        com/com_pointer.h
        com/com_private_data.cpp
        com/com_private_data.h

        log/log_debug.cpp
        log/log_debug.h
        log/log.cpp
        log/log.h

        rc/util_rc_ptr.h
        rc/util_rc.h

        thread.cpp
        thread.h
        util_bit.h
        util_enum.h
        util_env.cpp
        util_env.h
        util_error.h
        util_flags.h
        util_likely.h
        util_math.h
        util_string.cpp
        util_string.h
)
target_include_directories(dxbc-util SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(dxbc-util PRIVATE -w)
if (NOT WIN32)
    target_link_libraries(dxbc-util PUBLIC windows-headers)
endif()