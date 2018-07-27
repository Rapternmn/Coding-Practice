cmake_minimum_required(VERSION 2.8.3)
project(heap)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

set (CMAKE_CXX_STANDARD 11)

add_executable(heap src/main.cpp src/heap.cpp src/heap.h)

target_link_libraries(heap)