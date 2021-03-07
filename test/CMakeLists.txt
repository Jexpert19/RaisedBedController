cmake_minimum_required(VERSION 3.10)

# set the project name
project(TestBuild)

# add the executable
add_executable(${PROJECT_NAME} "./test_src/test_main.cpp")

# include googletest library
# header
find_path(LIBGTEST_INC "./lib/googletest/include")
include_directories(${LIBGTEST_INC})
# source
find_library(LIBGTEST_SRC "./lib/googletest/src/libgtest.a")

# put all together
target_link_libraries(${PROJECT_NAME} ${LIBGTEST_SRC})
