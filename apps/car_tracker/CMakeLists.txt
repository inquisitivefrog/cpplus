cmake_minimum_required(VERSION 3.20)
project(car_tracker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main executable
add_executable(car_tracker
    main.cpp
    Car.cpp
    Engine.cpp
    Transmission.cpp
    Tire.cpp
    Body.cpp
    Cab.cpp
    Location.cpp
    Utilities.cpp
)
target_link_libraries(car_tracker PRIVATE pthread)

# Strip symbols for Release builds
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_custom_command(TARGET car_tracker POST_BUILD
        COMMAND ${CMAKE_STRIP} --strip-unneeded $<TARGET_FILE:car_tracker>
        COMMENT "Stripping symbols from car_tracker"
    )
endif()

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR})

# Test executable (no stripping, as tests are for development)
add_executable(car_tracker_tests
    tests/test_car.cpp
    tests/test_engine.cpp
    tests/test_transmission.cpp
    tests/test_body.cpp
    tests/test_cab.cpp
    Car.cpp
    Engine.cpp
    Transmission.cpp
    Tire.cpp
    Body.cpp
    Cab.cpp
    Location.cpp
    Utilities.cpp
)
target_link_libraries(car_tracker_tests PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
