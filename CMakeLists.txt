cmake_minimum_required(VERSION 3.28)
project(dynamictype VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)

include_directories(include)

# Custom Libraries
find_library(ARVOREBINARIA_LIB arvorebinaria PATHS /usr/local/lib)
find_library(LISTAENCADEADA_LIB listaencadeada PATHS /usr/local/lib)
find_library(HASH_LIB hash PATHS /usr/local/lib)
include_directories(/usr/local/include/custom)

# Main Executable
add_executable(dynamictype
        src/main.c
        src/dynamictype.c)

# Configuring Tests
enable_testing()
add_subdirectory(tests)
