# mkdir build && cd build
# cmake [-DBIT=<32|64>] ..

cmake_minimum_required(VERSION 3.29)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
include(AndroidCrossCompile)

project(hello)

set(BINARY_NAME ${CMAKE_PROJECT_NAME}-${BIT})
add_executable(${BINARY_NAME} hello-world.c)

install(CODE "execute_process(COMMAND termux-elf-cleaner --api-level ${CMAKE_SYSTEM_VERSION} ${BINARY_NAME})")
install(CODE "execute_process(COMMAND adb push ${BINARY_NAME} /data/local/tmp)")