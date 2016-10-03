cmake_minimum_required(VERSION 3.6)
project(IFJ_88)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(SOURCE_FILES main.c scanner.c scanner.h)
add_executable(IFJ_88 ${SOURCE_FILES})