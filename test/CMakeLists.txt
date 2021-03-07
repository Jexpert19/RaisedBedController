cmake_minimum_required(VERSION 3.10)

# set the project name
project(TestBuild)

# add the executable
add_executable(TestBuild ./test_src/test.cpp)

# include googletest library
INCLUDE_DIRECTORIES(./lib/googletest/include)
LINK_DIRECTORIES(./lib/googletest/src)

# put all together
TARGET_LINK_LIBRARIES(TestBuild libgtest_main.a)
