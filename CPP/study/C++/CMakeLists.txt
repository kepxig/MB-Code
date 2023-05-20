#CMakeLists.txt
cmake_minimum_required (VERSION 3.16)
project(main CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -fno-exceptions")

add_executable(
    ademo.wasm
    ademo.cpp
)
