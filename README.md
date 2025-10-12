# cpplus
Example app and tool using C++ 

g++ → GNU C++ compiler
gcc → GNU C compiler
make → build automation tool
libstdc++ → standard C++ libraries

INSTALLATION
------------
$ sudo apt update
$ sudo apt install python3-dev
$ sudo apt install build-essential
$ sudo apt install gdb
$ sudo apt install libc6-dbg
$ sudo apt install glibc-source
$ sudo tar -xf /usr/src/glibc/glibc-*.tar.* -C /usr/src/glibc
$ sudo apt install libstdc++6-13-dbg
$ sudo apt install libstdc++6 libc6 libgcc1
$ sudo apt install cmake clang lldb valgrind
$ sudo apt install openssh-server
$ sudo systemctl enable --now ssh
$ sudo apt install libgtest-dev
$ cd /usr/src/gtest
$ sudo cmake CMakeLists.txt
$ sudo make
$ sudo cp *.a /usr/lib
$ sudo apt-get install curl zip unzip tar
$ sudo apt-get install pkg-config
$ sudo apt-get install autoconf autoconf-archive automake libtool
$ sudo apt install ninja-build
$ git clone https://github.com/microsoft/vcpkg.git
$ cd vcpkg/
$ ./bootstrap-vcpkg.sh 
$ ./vcpkg integrate install
$ ./vcpkg install boost
$ sudo sh -c 'echo 0 > /proc/sys/kernel/kptr_restrict'
$ sudo mkdir -p /usr/share/doc/perf-tip
$ wget https://raw.githubusercontent.com/torvalds/linux/master/tools/perf/Documentation/tips.txt -O /usr/share/doc/perf-tip/tips.txt
$ sudo chmod 644 /usr/share/doc/perf-tip/tips.txt 

VERSION
-------
$ g++ --version
g++ (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


$ g++ -dM -E -x c++ - < /dev/null | grep -i gnu
#define __GNUC_PATCHLEVEL__ 0
#define __gnu_linux__ 1
#define __GNUC__ 13
#define __GNUC_WIDE_EXECUTION_CHARSET_NAME "UTF-32LE"
#define __GNUG__ 13
#define __GNUC_EXECUTION_CHARSET_NAME "UTF-8"
#define __GNUC_STDC_INLINE__ 1
#define __GNUC_MINOR__ 3
#define _GNU_SOURCE 1

$ gdb --version
GNU gdb (Ubuntu 15.0.50.20240403-0ubuntu1) 15.0.50.20240403-git
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

$ cmake -version
cmake version 3.28.3
CMake suite maintained and supported by Kitware (kitware.com/cmake).

$ make --version
GNU Make 4.3
Built for aarch64-unknown-linux-gnu
Copyright (C) 1988-2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

$ pkg-config --modversion gtest
1.14.0

$ valgrind --version
valgrind-3.22.0

$ perf --version
perf version 6.8.12

$ cg_annotate --version
cg_annotate-3.22.0

CONFIG
------
$ cat ../CMakeLists.txt 
cmake_minimum_required(VERSION 3.28)

set(CMAKE_TOOLCHAIN_FILE "/home/sre/package_manager/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project(MyProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR})

set(Boost_DEBUG ON)
find_package(Boost 1.89.0 COMPONENTS filesystem REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE Boost::filesystem)

$ vi ~/.gdbinit
$ cat ~/.gdbinit
set debuginfod enabled on

ENABLE
------
$ sudo systemctl stop apport.service
$ sudo sysctl -w kernel.core_pattern=core.%p
$ ulimit -c unlimited

PERFORMANCE
-----------
$ sudo apt install linux-tools-generic linux-tools-common
$ sudo sysctl -w kernel.perf_event_paranoid=1
$ sudo perf list
$ perf stat -e cache-misses <program>
$ sudo perf stat -e r04,r08,r03 <program>
$ perf report --stdio perf.data > perf_report.txt
$ perf record -g ./main 
$ perf report --stdio > perf_report_detailed.txt
$ perf record -g -F 9999 ./main  
$ perf record -g -e cycles ./main
$ sudo apt install valgrind
$ valgrind --tool=cachegrind ./main

BUILD
-----
$ cd <feature>
$ vi CMakeLists.txt
$ mkdir build; cd build
$ cmake -Wno-dev ..
$ cmake -Wno-dev -DCMAKE_BUILD_TYPE=Release ..
$ cmake -Wno-dev -DCMAKE_BUILD_TYPE=Debug ..
$ cmake --build . --clean-first
$ make
$ ls -l 
$ ldconfig ./main
$ free -h
$ sudo swapoff -a
$ nm -an ./main | c++filt | grep -E '<known_object>'
$ strip --strip-unneeded ./main

EXAMPLES
--------
$ g++ -g -o hello hello.cpp
$ gdb ./hello
$ g++ -E -o hello hello.cpp
$ cmake -DCMAKE_TOOLCHAIN_FILE=/home/sre/package_manager/vcpkg/scripts/buildsystems/vcpkg.cmake --trace-expand ..
$ cmake -Wno-dev ..
$ cmake -Wno-dev .. --trace-expand > cmake_trace.txt
$ cmake -B /home/sre/package_manager/vcpkg/build -S /home/sre/package_manager/vcpkg -DCMAKE_TOOLCHAIN_FILE=/home/sre/package_manager/vcpkg/scripts/buildsystems/vcpkg.cmake -Wno-dev
$ make
$ ./main
$ gdb ./main
$ gdb ./main ./core.<pid>

