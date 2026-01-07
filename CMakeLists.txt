cmake_minimum_required(VERSION 4.2.1)
set(CMAKE_CXX_STANDARD 26)

project(Bonsai)

# POOF_COLOR_FLAG="--colors-off"

if (LINUX)
    add_link_options(-lpthread -lX11 -ldl -lGL)
    add_compile_options(-ggdb)
    # SHARED_LIBRARY_FLAGS="-shared -fPIC"
    add_compile_definitions(BONSAI_LINUX)
endif (LINUX)
if (WIN32)
    add_compile_definitions(BONSAI_WIN32)
endif (WIN32)

# TODO compile with GCC as well
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

# Warnings
add_compile_options(-ferror-limit=2000)
add_compile_options(-Wall -Wextra)

# Vector extensions
add_compile_options(-mssse3 -mavx -mavx2 -mfma -mvaes)

# Defines
add_compile_definitions(BONSAI_INTERNAL=1)

add_library(perlin_avx2 SHARED
    src/iterators.h
    src/primitives.h
    src/simd.h
    src/simd_avx2.h
    src/perlin_avx2.h
    src/perlin_avx2.cpp)
install(TARGETS perlin_avx2 DESTINATION "./bonsai/")

target_include_directories(perlin_avx2 PUBLIC "${CMAKE_SOURCE_DIR}/")

