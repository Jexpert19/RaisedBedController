cmake_minimum_required(VERSION 3.10)

# set the project name
project(TestBuild)

# add the executable
add_executable(${PROJECT_NAME} ./test_src/test.cpp)

# include googletest library
INCLUDE_DIRECTORIES(./lib/googletest/include)
add_library(libgtest_main ./lib/googletest/src/libgtest_main.a)

# put all together
TARGET_LINK_LIBRARIES(${PROJECT_NAME} libgtest_main)
