cmake_minimum_required(VERSION 3.10)

# set the project name
project(TestBuild)

# add the executable
add_executable(${PROJECT_NAME} "./test_src/test_main.cpp")

# include googletest library
include_directories(./lib/googletest/include/)

# put all together
target_link_libraries(${PROJECT_NAME} "./lib/googletest/src/libgtest.a")
