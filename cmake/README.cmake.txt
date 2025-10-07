
sre@cpp:~/cmake$ vi square.h
sre@cpp:~/cmake$ vi square.cpp
sre@cpp:~/cmake$ vi test_square.cpp
sre@cpp:~/cmake$ vi CMakeLists.txt

sre@cpp:~/cmake$ cmake .
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
-- Found GTest: /usr/lib/aarch64-linux-gnu/cmake/GTest/GTestConfig.cmake (found version "1.14.0")  
-- Configuring done (0.2s)
-- Generating done (0.0s)
-- Build files have been written to: /home/sre/cmake

sre@cpp:~/cmake$ make
[ 25%] Building CXX object CMakeFiles/square.dir/square.cpp.o
[ 50%] Linking CXX static library libsquare.a
[ 50%] Built target square
[ 75%] Building CXX object CMakeFiles/test_square.dir/test_square.cpp.o
[100%] Linking CXX executable test_square
[100%] Built target test_square

sre@cpp:~/cmake$ ./test_square 
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from SquareTest
[ RUN      ] SquareTest.PositiveNumbers
[       OK ] SquareTest.PositiveNumbers (0 ms)
[ RUN      ] SquareTest.NegativeNumbers
[       OK ] SquareTest.NegativeNumbers (0 ms)
[----------] 2 tests from SquareTest (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 2 tests.

sre@cpp:~/cmake$ ls -l
total 572
-rw-rw-r-- 1 sre sre  14369 Oct  6 19:08 CMakeCache.txt
drwxrwxr-x 7 sre sre   4096 Oct  6 19:08 CMakeFiles
-rw-rw-r-- 1 sre sre   1600 Oct  6 19:08 cmake_install.cmake
-rw-rw-r-- 1 sre sre    414 Oct  6 19:08 CMakeLists.txt
-rw-rw-r-- 1 sre sre   1444 Oct  6 19:08 libsquare.a
-rw-rw-r-- 1 sre sre   6377 Oct  6 19:08 Makefile
-rw-rw-r-- 1 sre sre     56 Oct  6 19:07 square.cpp
-rw-rw-r-- 1 sre sre     32 Oct  6 19:07 square.h
-rwxrwxr-x 1 sre sre 536152 Oct  6 19:08 test_square
-rw-rw-r-- 1 sre sre    603 Oct  6 19:07 test_square.cpp

