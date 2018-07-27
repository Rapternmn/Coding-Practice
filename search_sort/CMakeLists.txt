cmake_minimum_required(VERSION 2.8.3)
project(search_sort)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

set (CMAKE_CXX_STANDARD 11)

add_executable(search_sort src/main.cpp src/search_sort.cpp src/search_sort.h)

target_link_libraries(search_sort)