cmake_minimum_required(VERSION 3.28)
project(dynamictype VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)

include_directories(include)

# Custom Libraries
find_library(LISTAENCADEADA_LIB listaencadeada PATHS /usr/local/lib)
include_directories(/usr/local/include/custom)

# Main Executable
add_executable(usage
        src/main.c
        src/dynamictype.c)
target_link_libraries(usage ${LISTAENCADEADA_LIB})

# Creating Library
add_library(dynamictype STATIC
        src/dynamictype.c)

# Library Installation
install(TARGETS dynamictype
        LIBRARY DESTINATION /usr/local/lib)
install(FILES include/lista_se.h
        DESTINATION /usr/local/include/custom)

# Configuring Tests
enable_testing()
add_subdirectory(tests)
