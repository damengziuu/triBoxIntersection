## cmake version
## me project
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
project(triangleBoxIneter)

set(SRC_FILE)
file(GLOB SRC_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(triangleBoxIneter ${SRC_FILE})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)