cmake_minimum_required(VERSION 3.10)
project(SquareApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Source files
add_library(square square.cpp)

# Test executable
add_executable(test_square test_square.cpp)
target_link_libraries(test_square square ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
