cmake_minimum_required (VERSION 3.10)
project(xbtbinfileutils)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Os -fno-rtti ")


# Find source files
file(GLOB SOURCES src/*.cpp)

# Include header files
include_directories(include)

# Create shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})





