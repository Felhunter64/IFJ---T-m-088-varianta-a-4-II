cmake_minimum_required(VERSION 3.6)
project(first)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)
add_executable(first ${SOURCE_FILES})