# Main Experience

Compile libpcap that runs on adb shell.

# Full Commands

### Cross Compiling libpcap

```shell
$ wget https://www.tcpdump.org/release/libpcap-1.10.4.tar.xz
$ tar -xf libpcap-1.10.4
$ cd libpcap-1.10.4
$ mkdir build
$ cd build
$ cmake -DCMAKE_TOOLCHAIN_FILE=/path/to/AndroidCrossCompile.cmake \
      -DDISABLE_DBUS=True \
      -DDISABLE_DPDK=True \
      -DCMAKE_INSTALL_PREFIX=/path/to/interface-list/sysroot \
      -DBUILD_SHARED_LIBS=False \
      ..
$ make install
```

### Compile interface-list-64

```shell
$ cd /path/to/interface-list
$ mkdir build
$ cd build
$ cmake ..
$ make install
```

### Run in adb shell

```shell
$ su
$ cd /data/local/tmp
$ ./interface-list-64
```