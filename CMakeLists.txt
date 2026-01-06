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
        # Enables poof, present in almost every file
        src/bonsai/poof_on.h

        bonsai_debug/src/api.h
        src/bonsai/poof_crutches.h
        src/bonsai/poof_functions.h
        src/bonsai/iterators.h
        src/bonsai/primitives.h
        src/bonsai/assert.h

        src/bonsai/stdlib.h

        src/bonsai/simd_sse.h
        src/bonsai/simd_avx2.h
        src/bonsai/avx2_v3.h

        src/bonsai/console_macros.h
        src/bonsai/globals.h
        src/bonsai/platform.h
        src/bonsai/bit_tricks.h
        src/bonsai/atomic.h
        src/bonsai/thread.h

        src/bonsai/costable.h
        src/bonsai/arccostable.h

        src/bonsai/maff.h
        src/bonsai/memory_arena.h
        src/bonsai/primitive_containers.h
        src/bonsai/file.h
        src/bonsai/filesystem.h
        src/bonsai/vector.h
        src/bonsai/matrix.h
        src/bonsai/colors.h

        src/bonsai/gl.h
        src/bonsai/ui/gl.h

        src/bonsai/texture.h
        src/bonsai/shader.h
        src/bonsai/random.h
        src/bonsai/noise.h
        src/bonsai/perlin.h
        src/bonsai/simplex.h
        src/bonsai/input.h
        src/bonsai/mutex.h
        src/bonsai/work_queue.h

        src/bonsai/mesh.h
        src/bonsai/gpu_mapped_buffer.h
        src/bonsai/framebuffer.h
        src/bonsai/render.h

        src/bonsai/platform_struct.h
        src/bonsai/heap_allocator.h
        src/bonsai/stream.h
        src/bonsai/counted_string.h
        src/bonsai/sort.h
        src/bonsai/console_io.h
        src/bonsai/line.h
        src/bonsai/quaternion.h
        src/bonsai/string_builder.h
        src/bonsai/ansi_stream.h

        src/bonsai/bitmap.h
        src/bonsai/c_parser.h
        src/bonsai/c_token.h
        src/bonsai/platform/linux/linux_file.h
        src/bonsai/platform/linux/linux_platform.h
        src/bonsai/platform/posix_platform.h
        src/bonsai/rect.h
        src/bonsai/ui/interactable.h
        src/bonsai/ui/ui.h

        # cpp files

        src/bonsai/perlin.cpp
        src/bonsai/assert.cpp
        src/bonsai/memory_arena.cpp
        src/bonsai/vector.cpp
        src/bonsai/debug_print.cpp

        src/bonsai/counted_string.cpp
        src/bonsai/sort.cpp
        src/bonsai/rect.cpp
        src/bonsai/primitive_containers.cpp
        src/bonsai/platform.cpp
        src/bonsai/thread.cpp
        src/bonsai/string_builder.cpp
        src/bonsai/ansi_stream.cpp

        #src/bonsai/bitmap.cpp
        #src/bonsai/c_parser.cpp
        #src/bonsai/file.cpp
        #src/bonsai/initialize.cpp
        #src/bonsai/platform/linux/linux_file.cpp
        #src/bonsai/platform/linux/linux_platform.cpp
        #src/bonsai/platform/posix_platform.cpp
        #src/bonsai/ui/ui.cpp
        #src/bonsai/work_queue.cpp

        ## Debugging
        #bonsai_debug/src/debug_data_system.cpp
        #bonsai_debug/src/debug_render_system.cpp
        #bonsai_debug/debug.h
        #bonsai_debug/debug.cpp
        #bonsai_stdlib.h
        #bonsai_stdlib.cpp

        src/bonsai/stdlib.cpp)
install(TARGETS Bonsai DESTINATION ".")

target_include_directories(Bonsai PUBLIC "${CMAKE_SOURCE_DIR}/")
target_include_directories(Bonsai PUBLIC "${CMAKE_SOURCE_DIR}/src/")

if (LINUX)
    add_compile_definitions(BONSAI_LINUX)
endif (LINUX)
if (WIN32)
    add_compile_definitions(BONSAI_WIN32)
endif (WIN32)

