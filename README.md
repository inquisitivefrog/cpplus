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

VERSION
-------
sre@cpp:~$ g++ --version
g++ (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

sre@cpp:~$ gdb --version
GNU gdb (Ubuntu 15.0.50.20240403-0ubuntu1) 15.0.50.20240403-git
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

sre@cpp:~/unit_test$ cmake -version
cmake version 3.28.3
CMake suite maintained and supported by Kitware (kitware.com/cmake).

CONFIG
------
sre@cpp:~/package_manager/vcpkg/build$ cat ../CMakeLists.txt 
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


EXAMPLES
--------
$ g++ -g -o hello hello.cpp
$ gdb ./hello
$ g++ -E -o hello hello.cpp
$ cmake -DCMAKE_TOOLCHAIN_FILE=/home/sre/package_manager/vcpkg/scripts/buildsystems/vcpkg.cmake --trace-expand ..
$ cmake -Wno-dev ..
$ cmake -B /home/sre/package_manager/vcpkg/build -S /home/sre/package_manager/vcpkg -DCMAKE_TOOLCHAIN_FILE=/home/sre/package_manager/vcpkg/scripts/buildsystems/vcpkg.cmake -Wno-dev
$ make
$ ./main
