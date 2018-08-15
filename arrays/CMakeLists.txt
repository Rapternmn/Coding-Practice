cmake_minimum_required(VERSION 2.8.3)
project(array)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

set (CMAKE_CXX_STANDARD 11)

add_executable(array src/main.cpp src/array.cpp src/array.h)

target_link_libraries(array)