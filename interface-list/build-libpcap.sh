wget https://www.tcpdump.org/release/libpcap-1.10.4.tar.xz
tar -xf libpcap-1.10.4
cd libpcap-1.10.4
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../../android-cpp-network/etc/AndroidCrossCompile.cmake \
	-DDISABLE_DBUS=True \
	-DDISABLE_DPDK=True \
	-DCMAKE_INSTALL_PREFIX=../../libpcapCross/sysroot64 \
	-DBUILD_SHARED_LIBS=False \
	.. \
make install