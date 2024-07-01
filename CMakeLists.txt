cmake_minimum_required(VERSION 3.28)
project(dynamictype VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)

include_directories(include)

# Custom Library
find_library(ARVOREBINARIA_LIB arvorebinaria PATHS /usr/local/lib)
include_directories(/usr/local/include/custom)

add_executable(dynamictype src/main.c
        src/dynamictype.c
        include/dynamictype.h)
