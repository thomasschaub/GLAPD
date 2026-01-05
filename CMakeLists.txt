cmake_minimum_required(VERSION 3.10)
project(GLAPD)

add_library(glapd-common common.cpp)

add_executable(Single single.c)
target_link_libraries(Single PRIVATE glapd-common)

add_executable(LAMP LAMP.c)
target_link_libraries(LAMP PRIVATE glapd-common)
