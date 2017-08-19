cmake_minimum_required(VERSION 3.6)
project(glad)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src include)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(glad src/glad.c)
