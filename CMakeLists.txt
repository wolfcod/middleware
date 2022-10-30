cmake_minimum_required(VERSION 3.23)
project(middleware)

set(CMAKE_CXX_STANDARD 14)

include_directories(./include)
add_executable(middleware src/main.cpp)
