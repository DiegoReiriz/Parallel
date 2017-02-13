cmake_minimum_required(VERSION 3.5)
project(MMBasic)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(SOURCE_FILES main.c )

add_executable(MMBasic ${SOURCE_FILES})
target_link_libraries(MMBasic m)