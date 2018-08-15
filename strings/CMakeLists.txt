cmake_minimum_required(VERSION 2.8.3)
project(dp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

set (CMAKE_CXX_STANDARD 11)

add_executable(dp src/main.cpp src/dp.cpp src/dp.h)

target_link_libraries(dp)