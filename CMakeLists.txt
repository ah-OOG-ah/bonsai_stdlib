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
        bonsai_stdlib.h
        bonsai_stdlib.cpp)
install(TARGETS Bonsai DESTINATION ".")

target_include_directories(Bonsai PUBLIC "${CMAKE_SOURCE_DIR}/")

if (LINUX)
    add_compile_definitions(BONSAI_LINUX)
endif (LINUX)
if (WIN32)
    add_compile_definitions(BONSAI_WIN32)
endif (WIN32)

