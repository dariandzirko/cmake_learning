cmake_minimum_required(VERSION 3.14)
project(cmake_learning)

set(CMAKE_CXX_STANDARD_14)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/hello_test.dir)

find_package(GTest REQUIRED)

enable_testing()

add_executable(
    hello_test
    hello_test.cc
)

add_custom_target(gcov
    COMMAND mkdir -p coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
add_custom_command(TARGET gcov
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/*.cpp -o ${OBJECT_DIR}
    COMMAND echo "-- Coverage files output to ${CMAKE_BINAR_DIR}/coverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
)

add_dependencies(gcov hello_test)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES coverage)

add_custom_target(scrub 
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${OBJECT_DIR}/*.gcno
    COMMAND rm -f ${OBJECT_DIR}/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_link_libraries(
  hello_test
  GTest::gtest_main
)

gtest_discover_tests(hello_test)
