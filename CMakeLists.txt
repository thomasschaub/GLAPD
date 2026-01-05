cmake_minimum_required(VERSION 3.10)
project(GLAPD)

add_library(glapd-common common.cpp)
target_include_directories(glapd-common PUBLIC .)

add_subdirectory(tests)

add_executable(Single single.c)
target_link_libraries(Single PRIVATE glapd-common)

add_executable(LAMP LAMP.c)
target_link_libraries(LAMP PRIVATE glapd-common)
