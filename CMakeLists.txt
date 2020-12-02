cmake_minimum_required(VERSION 2.4)
#C++14 standard enabled
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++14")

project(verbio)
include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)

