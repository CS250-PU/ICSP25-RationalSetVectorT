# CMakeLists.txt at the root of the project

cmake_minimum_required(VERSION 3.0)

# Name SampleClass needs to match one of the Source names in Sources.
set(This SampleClass)

project(${This} C CXX)
set(CMAKE_C_STANDARD 99)
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)


enable_testing()
add_subdirectory(googletest)

set (Headers
    include/SampleClass.h
)

set (Sources
    src/SampleClass.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)