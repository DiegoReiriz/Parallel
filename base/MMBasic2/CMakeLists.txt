cmake_minimum_required(VERSION 3.5)
project(MMBasic2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp read_data.hh)
add_executable(MMBasic2 ${SOURCE_FILES})