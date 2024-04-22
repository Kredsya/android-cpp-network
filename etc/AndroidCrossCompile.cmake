cmake_minimum_required(VERSION 3.29)

set(CMAKE_SYSTEM_NAME Android)
set(CMAKE_SYSTEM_VERSION 24)
set(CMAKE_ANDROID_NDK /home/kredsya/Android/Sdk/ndk/25.1.8937393)
set(CMAKE_ANDROID_STL_TYPE c++_static)

if(NOT DEFINED BIT)
    set(BIT 64)
endif()

set(BIT 32)

if(BIT STREQUAL 64)
    set(CMAKE_ANDROID_ARCH_ABI arm64-v8a)
elseif(BIT STREQUAL 32)
    set(CMAKE_ANDROID_ARCH_ABI armeabi-v7a)
    set(CMAKE_ANDROID_ARM_NEON TRUE)
else()
    message(FATAL_ERROR "Unsupported argument BIT: ${BIT}")
endif()