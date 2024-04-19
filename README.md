# android-cross-compile

```shell
$ mkdir build
$ cd build
$ cmake ..
$ make
$ adb push hello /data/local/tmp

# in adb shell
$ ./hello
```
# change between 64bit and 32bit

modify `include(Android32)` of [CMakeLists.txt:4](CMakeLists.txt) to `Android32` or `Android64`

# 시행착오

set(CMAKE_SYSTEM_VERSION "25")

API 버전을 넣는 곳이고, 제가 가지고 있는 갤럭시 S7 엣지의 플랫폼 버전은 Android 7.1.2로 API Level 25입니다.

하지만 Qt에는 API 25 버전이 없었고, [링크 에러](api-error.log)가 발생했습니다.

이는 24 버전으로 바꾸어서 해결하였습니다.
