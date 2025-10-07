
sre@cpp:~/package_manager/vcpkg$ mkdir build
sre@cpp:~/package_manager/vcpkg$ cd build
sre@cpp:~/package_manager/vcpkg/build$ vi ../CMakeLists.txt 
sre@cpp:~/package_manager/vcpkg/build$ cmake -Wno-dev ..
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/sre/package_manager/vcpkg
sre@cpp:~/package_manager/vcpkg/build$ cmake --build .
Error: could not load cache
sre@cpp:~/package_manager/vcpkg/build$ cmake --build ..
[100%] Built target main
sre@cpp:~/package_manager/vcpkg/build$ ls -l ../main
-rwxrwxr-x 1 sre sre 1041840 Oct  6 22:08 ../main
sre@cpp:~/package_manager/vcpkg/build$ ./main
-bash: ./main: No such file or directory
sre@cpp:~/package_manager/vcpkg/build$ ../main
Directory already exists or creation failed
sre@cpp:~/package_manager/vcpkg/build$ ls -ld /tmp/test
drwxrwxr-x 2 sre sre 4096 Oct  6 22:12 /tmp/test
sre@cpp:~/package_manager/vcpkg/build$ rmdir /tmp/test
sre@cpp:~/package_manager/vcpkg/build$ ../main
Created directory: "/tmp/test"
sre@cpp:~/package_manager/vcpkg/build$ ls -ld /tmp/test
drwxrwxr-x 2 sre sre 4096 Oct  6 22:14 /tmp/test

sre@cpp:~/package_manager/vcpkg/build$ vi ../main.cpp 
sre@cpp:~/package_manager/vcpkg/build$ cat ../main.cpp
#include <boost/filesystem.hpp>
#include <iostream>

int main() {
    boost::filesystem::path p("/tmp/test");
    try {
        if (boost::filesystem::create_directory(p)) {
            std::cout << "Created directory: " << p << "\n";
        } else {
            std::cout << "Directory already exists: " << p << "\n";
        }
    } catch (const boost::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
sre@cpp:~/package_manager/vcpkg/build$ cmake -Wno-dev ..
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/sre/package_manager/vcpkg
sre@cpp:~/package_manager/vcpkg/build$ cmake --build ..
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable main
[100%] Built target main
sre@cpp:~/package_manager/vcpkg/build$ ls -l ../main
-rwxrwxr-x 1 sre sre 1042000 Oct  6 22:16 ../main
sre@cpp:~/package_manager/vcpkg/build$ ../main
Directory already exists: "/tmp/test"
sre@cpp:~/package_manager/vcpkg/build$ ls -ld /tmp/test
drwxrwxr-x 2 sre sre 4096 Oct  6 22:14 /tmp/test
sre@cpp:~/package_manager/vcpkg/build$ rmdir /tmp/test
sre@cpp:~/package_manager/vcpkg/build$ ../main
Created directory: "/tmp/test"
sre@cpp:~/package_manager/vcpkg/build$ ls -ld /tmp/test
drwxrwxr-x 2 sre sre 4096 Oct  6 22:16 /tmp/test
sre@cpp:~/package_manager/vcpkg/build$ 

sre@cpp:~/package_manager/vcpkg/build$ vi ../CMakeLists.txt 
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

find_package(Boost 1.89.0 COMPONENTS filesystem REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE Boost::filesystem)
sre@cpp:~/package_manager/vcpkg/build$ rm -rf *
sre@cpp:~/package_manager/vcpkg/build$ cmake -Wno-dev ..
-- The C compiler identification is GNU 13.3.0
-- The CXX compiler identification is GNU 13.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Boost: /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost/BoostConfig.cmake (found suitable version "1.89.0", minimum required is "1.89.0") found components: filesystem 
-- Configuring done (0.2s)
-- Generating done (0.0s)
-- Build files have been written to: /home/sre/package_manager/vcpkg/build
sre@cpp:~/package_manager/vcpkg/build$ cmake --build .
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable main
[100%] Built target main
sre@cpp:~/package_manager/vcpkg/build$ ls -l
total 1048
-rw-rw-r-- 1 sre sre   23544 Oct  7 00:29 CMakeCache.txt
drwxrwxr-x 6 sre sre    4096 Oct  7 00:30 CMakeFiles
-rw-rw-r-- 1 sre sre    1638 Oct  7 00:29 cmake_install.cmake
-rwxrwxr-x 1 sre sre 1042088 Oct  7 00:30 main
-rw-rw-r-- 1 sre sre    5112 Oct  7 00:29 Makefile
sre@cpp:~/package_manager/vcpkg/build$ ./main
Directory already exists: "/tmp/test"
sre@cpp:~/package_manager/vcpkg/build$ rm /tmp/test
rm: cannot remove '/tmp/test': Is a directory
sre@cpp:~/package_manager/vcpkg/build$ rmdir /tmp/test
sre@cpp:~/package_manager/vcpkg/build$ ./main
Created directory: "/tmp/test"
sre@cpp:~/package_manager/vcpkg/build$ ls -ld /tmp/test
drwxrwxr-x 2 sre sre 4096 Oct  7 00:30 /tmp/test
sre@cpp:~/package_manager/vcpkg/build$ 


sre@cpp:~/package_manager/vcpkg/build$ vi ../main.cpp 
sre@cpp:~/package_manager/vcpkg/build$ cat ../main.cpp 
#include <boost/filesystem.hpp>
#include <iostream>

int main() {
    boost::filesystem::path p("/tmp/test");
    try {
        if (boost::filesystem::exists(p)) {
            std::cout << "Directory already exists: " << p << "\n";
	    for (const auto& entry : boost::filesystem::directory_iterator(p)) {
                std::cout << "Found: " << entry.path() << "\n";
            }
        } else if (boost::filesystem::create_directory(p)) {
            std::cout << "Created directory: " << p << "\n";
        } else {
            std::cout << "Failed to create directory: " << p << "\n";
        }
    } catch (const boost::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
sre@cpp:~/package_manager/vcpkg/build$ rm -rf *
sre@cpp:~/package_manager/vcpkg/build$ cmake -Wno-dev ..
-- The C compiler identification is GNU 13.3.0
-- The CXX compiler identification is GNU 13.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Boost 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost
--   Requested configuration: QUIET REQUIRED COMPONENTS filesystem
-- BoostConfig: find_package(boost_headers 1.89.0 EXACT CONFIG REQUIRED QUIET HINTS /home/sre/package_manager/vcpkg/installed/arm64-linux/share)
-- Found boost_headers 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_headers
-- BoostConfig: find_package(boost_filesystem 1.89.0 EXACT CONFIG REQUIRED QUIET HINTS /home/sre/package_manager/vcpkg/installed/arm64-linux/share)
-- Found boost_filesystem 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_filesystem
-- Found boost_assert 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_assert
-- Found boost_config 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_config
-- Found boost_container_hash 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_container_hash
-- Found boost_describe 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_describe
-- Found boost_mp11 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_mp11
-- Found boost_detail 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_detail
-- Found boost_core 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_core
-- Found boost_static_assert 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_static_assert
-- Found boost_throw_exception 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_throw_exception
-- Found boost_preprocessor 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_preprocessor
-- Found boost_type_traits 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_type_traits
-- Found boost_io 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_io
-- Found boost_iterator 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_iterator
-- Found boost_concept_check 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_concept_check
-- Found boost_fusion 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_fusion
-- Found boost_function_types 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_function_types
-- Found boost_mpl 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_mpl
-- Found boost_predef 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_predef
-- Found boost_utility 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_utility
-- Found boost_tuple 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_tuple
-- Found boost_typeof 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_typeof
-- Found boost_functional 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_functional
-- Found boost_function 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_function
-- Found boost_bind 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_bind
-- Found boost_optional 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_optional
-- Found boost_smart_ptr 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_smart_ptr
-- Found boost_system 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_system
-- Found boost_variant2 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_variant2
-- Found boost_winapi 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_winapi
-- Found boost_scope 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_scope
-- Found boost_atomic 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_atomic
-- Found boost_align 1.89.0 at /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost_align
-- Found Boost: /home/sre/package_manager/vcpkg/installed/arm64-linux/share/boost/BoostConfig.cmake (found suitable version "1.89.0", minimum required is "1.89.0") found components: filesystem 
-- Configuring done (0.2s)
-- Generating done (0.0s)
-- Build files have been written to: /home/sre/package_manager/vcpkg/build
sre@cpp:~/package_manager/vcpkg/build$ cmake --build .
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable main
[100%] Built target main
sre@cpp:~/package_manager/vcpkg/build$ ls -l 
total 1044
-rw-rw-r-- 1 sre sre   23544 Oct  7 00:35 CMakeCache.txt
drwxrwxr-x 6 sre sre    4096 Oct  7 00:35 CMakeFiles
-rw-rw-r-- 1 sre sre    1638 Oct  7 00:35 cmake_install.cmake
-rwxrwxr-x 1 sre sre 1043552 Oct  7 00:35 main
-rw-rw-r-- 1 sre sre    5112 Oct  7 00:35 Makefile
sre@cpp:~/package_manager/vcpkg/build$ ./main
Directory already exists: "/tmp/test"
sre@cpp:~/package_manager/vcpkg/build$ rmdir /tmp/test
sre@cpp:~/package_manager/vcpkg/build$ ./main
Created directory: "/tmp/test"
sre@cpp:~/package_manager/vcpkg/build$ ls -ld /tmp/test
drwxrwxr-x 2 sre sre 4096 Oct  7 00:35 /tmp/test
sre@cpp:~/package_manager/vcpkg/build$ 

