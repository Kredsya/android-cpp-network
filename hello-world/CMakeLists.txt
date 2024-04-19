cmake_minimum_required(VERSION 3.29)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
include(AndroidCrossCompile)

project(hello-${BIT})

add_executable(${CMAKE_PROJECT_NAME} hello-world.c)

install(CODE "execute_process(COMMAND termux-elf-cleaner --api-level ${CMAKE_SYSTEM_VERSION} ${CMAKE_PROJECT_NAME})")
install(CODE "execute_process(COMMAND adb push ${CMAKE_PROJECT_NAME} /data/local/tmp)")