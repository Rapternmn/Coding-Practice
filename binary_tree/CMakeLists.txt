cmake_minimum_required(VERSION 2.8.3)
project(Tree)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

set (CMAKE_CXX_STANDARD 11)

add_executable(bin_tree src/main.cpp src/binary_tree.cpp src/binary_tree.h)

target_link_libraries(bin_tree )