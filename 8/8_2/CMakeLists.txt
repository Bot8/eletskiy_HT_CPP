cmake_minimum_required(VERSION 2.8.4)
project(8_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ConsoleApplication1/Source.cpp)

add_executable(8_2 ${SOURCE_FILES})