cmake_minimum_required(VERSION 2.8.4)
project(15)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(15 ${SOURCE_FILES})