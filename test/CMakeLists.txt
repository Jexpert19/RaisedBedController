cmake_minimum_required(VERSION 3.10)

# set the project name
project(TestBuild)

# add the executable
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/test_src/test_main.cpp)

# for gtest lib
add_compile_options(-lgtest -lgtest_main -lpthread)
