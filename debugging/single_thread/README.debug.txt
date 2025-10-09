
sre@cpp:~/debugging/build$ rm -rf CMakeFiles/
sre@cpp:~/debugging/build$ rm CMakeCache.txt 
sre@cpp:~/debugging/build$ cmake -B /home/sre/debugging/build/ -S /home/sre/package_manager/vcpkg -DCMAKE_TOOLCHAIN_FILE=/home/sre/package_manager/vcpkg/scripts/buildsystems/vcpkg.cmake -Wno-dev
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
-- Configuring done (0.3s)
-- Generating done (0.0s)
-- Build files have been written to: /home/sre/debugging/build
sre@cpp:~/debugging/build$ make
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable main
[100%] Built target main
sre@cpp:~/debugging/build$ ls -l
total 1052
-rw-rw-r-- 1 sre sre   23496 Oct  7 17:32 CMakeCache.txt
drwxrwxr-x 6 sre sre    4096 Oct  7 17:32 CMakeFiles
-rw-rw-r-- 1 sre sre    1626 Oct  7 17:32 cmake_install.cmake
-rw-rw-r-- 1 sre sre     634 Oct  7 17:27 CMakeLists.txt
-rwxrwxr-x 1 sre sre 1043552 Oct  7 17:32 main
-rw-rw-r-- 1 sre sre    3460 Oct  7 16:59 main.cpp
-rw-rw-r-- 1 sre sre    5064 Oct  7 17:32 Makefile

sre@cpp:~/debugging/build$ ./main 
Directory already exists: "/tmp/test"
sre@cpp:~/debugging/build$ rmdir /tmp/test
sre@cpp:~/debugging/build$ ./main 
Created directory: "/tmp/test"
sre@cpp:~/debugging/build$ ls -ld /tmp/test
drwxrwxr-x 2 sre sre 4096 Oct  7 17:33 /tmp/test

sre@cpp:~/debugging/build$ make clean
sre@cpp:~/debugging/build$ make
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable main
[100%] Built target main
sre@cpp:~/debugging/build$ ls -l main
-rwxrwxr-x 1 sre sre 1043552 Oct  7 17:35 main
sre@cpp:~/debugging/build$ date
Tue Oct  7 05:35:18 PM UTC 2025

