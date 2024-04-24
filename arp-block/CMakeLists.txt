cmake_minimum_required(VERSION 3.29)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
include(AndroidCrossCompile)

project(arp-block-${BIT})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sysroot${BIT}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

add_subdirectory(headers)

target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/sysroot${BIT}/lib/libpcap.a)
target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)

install(CODE "execute_process(COMMAND termux-elf-cleaner --api-level ${CMAKE_SYSTEM_VERSION} ${CMAKE_PROJECT_NAME})")
install(CODE "execute_process(COMMAND adb push ${CMAKE_PROJECT_NAME} /data/local/tmp)")