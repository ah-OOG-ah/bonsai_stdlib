cmake_minimum_required(VERSION 4.2.1)
set(CMAKE_CXX_STANDARD 26)

# TODO compile with GCC as well
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

# Warnings
add_compile_options(-Wall -Wextra)

# Vector extensions
add_compile_options(-mssse3 -mavx -mavx2 -mfma -mvaes)

project(Bonsai)
add_library(Bonsai SHARED
        src/bonsai/poof_on.h

        src/bonsai/avx2_v3.h
        src/bonsai/bitmap.h
        src/bonsai/bit_tricks.h
        src/bonsai/colors.h
        src/bonsai/console_macros.h
        src/bonsai/counted_string.h
        src/bonsai/c_parser.h
        src/bonsai/c_token.h
        src/bonsai/file.h
        src/bonsai/globals.h
        src/bonsai/heap_allocator.h
        src/bonsai/input.h
        src/bonsai/maff.h
        src/bonsai/memory_arena.h
        src/bonsai/perlin.h
        src/bonsai/platform.h
        src/bonsai/platform/linux/linux_file.h
        src/bonsai/platform/linux/linux_platform.h
        src/bonsai/platform/posix_platform.h
        src/bonsai/platform_struct.h
        src/bonsai/poof_functions.h
        src/bonsai/primitives.h
        src/bonsai/random.h
        src/bonsai/rect.h
        src/bonsai/simd_avx2.h
        src/bonsai/simd_sse.h
        src/bonsai/texture.h
        src/bonsai/thread.h
        src/bonsai/ui/interactable.h
        src/bonsai/ui/ui.h
        src/bonsai/vector.h
        src/bonsai/work_queue.h

        src/bonsai/bitmap.cpp
        src/bonsai/counted_string.cpp
        src/bonsai/c_parser.cpp
        src/bonsai/file.cpp
        src/bonsai/initialize.cpp
        src/bonsai/memory_arena.cpp
        src/bonsai/perlin.cpp
        src/bonsai/platform/linux/linux_file.cpp
        src/bonsai/platform/linux/linux_platform.cpp
        src/bonsai/platform/posix_platform.cpp
        src/bonsai/thread.cpp
        src/bonsai/ui/ui.cpp
        src/bonsai/work_queue.cpp

        bonsai_debug/src/debug_data_system.cpp
        bonsai_debug/src/debug_render_system.cpp
        bonsai_debug/debug.h
        bonsai_debug/debug.cpp
        bonsai_stdlib.h
        bonsai_stdlib.cpp)
install(TARGETS Bonsai DESTINATION ".")

target_include_directories(Bonsai PUBLIC "${CMAKE_SOURCE_DIR}/")
target_include_directories(Bonsai PUBLIC "${CMAKE_SOURCE_DIR}/src/")

if (LINUX)
    add_compile_definitions(BONSAI_LINUX)
endif (LINUX)
if (WIN32)
    add_compile_definitions(BONSAI_WIN32)
endif (WIN32)

