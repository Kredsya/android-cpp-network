wget https://www.tcpdump.org/release/libpcap-1.10.4.tar.xz
tar -xf libpcap-1.10.4
cd libpcap-1.10.4
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=/home/kredsya/study/android-cpp-network/interface-list/AndroidCrossCompile.cmake \
      -DDISABLE_DBUS=True \
      -DDISABLE_DPDK=True \
      -DCMAKE_INSTALL_PREFIX=/home/kredsya/study/android-cpp-network/interface-list/sysroot \
      -DBUILD_SHARED_LIBS=False \
      ..
make install