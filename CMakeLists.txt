cmake_minimum_required(VERSION 3.28)
project(dynamictype C)

set(CMAKE_C_STANDARD 17)

include_directories(include)

add_executable(dynamictype src/main.c)
