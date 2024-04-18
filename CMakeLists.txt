cmake_minimum_required(VERSION 3.29)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
include(Android64)

project(hello)

add_executable(hello hello-world.c)