cmake_minimum_required(VERSION 3.10)

# set the project name
project(TestBuild)

# add the executable
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/test_src/test_main.cpp)

message(INFO ${CMAKE_CURRENT_SOURCE_DIR})

# include googletest library
# header
# find_path(LIBGTEST_INC ${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest/include)
# source
# find_library(LIBGTEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest/src/libgtest.a)

# put all together
target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest/src/libgtest.a)
