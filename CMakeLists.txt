cmake_minimum_required(VERSION 3.29)
project(hello)

add_executable(hello main.cpp)

set(CMAKE_SYSTEM_NAME Android)
set(CMAKE_SYSTEM_VERSION 25) # API level
set(CMAKE_ANDROID_ARCH_ABI arm64-v8a)
set(CMAKE_ANDROID_NDK /path/to/android-ndk)
set(CMAKE_ANDROID_STL_TYPE gnustl_static)