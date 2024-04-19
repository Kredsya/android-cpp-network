# android-cross-compile

```shell
$ mkdir build
$ cd build
$ cmake ..
$ make install

# in adb shell
hero2lte:/data/local/tmp $ ./hello-64
Hello, World! 8
```

# Cross Compile between 32bit or 64bit

You can choose with `-DBIT=64`(Default) or `-DBIT=32` of cmake option.

### Example
```shell
$ cmake -DBIT=32 ..
$ make install
```

# Cross Compile between C or C++

Don't mind. It works regardless its language.

# Behavior of `make install`

You can see this in [CMakeLists.txt:14-15](CMakeLists.txt#L14-L15).

``` shell
$ termux-elf-cleaner --api-level ${CMAKE_SYSTEM_VERSION} ${BINARY_NAME}
$ adb push ${BINARY_NAME} /data/local/tmp
```

# 시행착오

`set(CMAKE_SYSTEM_VERSION 25)`

API 버전을 넣는 곳이고, 제가 가지고 있는 갤럭시 S7 엣지의 플랫폼 버전은 Android 7.1.2로 API Level 25입니다.

하지만 Qt에는 API 25 버전이 없었고, [링크 에러](api-error.log#L29-L30)가 발생했습니다.

이는 24 버전으로 바꾸어서 해결하였습니다.

# Reference

1. Largely thanks to [Sharp0802](https://github.com/Sharp0802/hello-android)
1. [Cross Compiling for Android](https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#cross-compiling-for-android)
1. [NDK CMake in Android Developer Guide](https://developer.android.com/ndk/guides/cmake?hl=ko)
1. [android.toolchain.cmake](https://android.googlesource.com/platform/ndk/+/master/build/cmake/android.toolchain.cmake)
1. [cmake-10-모듈](https://keunjun.blog/2018/10/07/cmake-10-%EB%AA%A8%EB%93%88/)
1. [CMake install](https://cmake.org/cmake/help/latest/command/install.html#code)
1. [CMake execute_process](https://cmake.org/cmake/help/latest/command/execute_process.html)
1. [termux-elf-cleaner](https://github.com/termux/termux-elf-cleaner)
