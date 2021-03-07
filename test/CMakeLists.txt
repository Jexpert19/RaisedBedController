cmake_minimum_required(VERSION 3.10)

# set the project name
project(TestBuild)

# for gtest lib
add_compile_options(-lgtest -lgtest_main -lpthread)

# add the executable
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/test_src/test_main.cpp)

# put all together
target_link_libraries(${PROJECT_NAME})
