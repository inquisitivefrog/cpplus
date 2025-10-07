
sre@cpp:~/unit_test$ vi square.h
sre@cpp:~/unit_test$ vi square.cpp
sre@cpp:~/unit_test$ mv square.cpp test_square.cpp
sre@cpp:~/unit_test$ vi square.cpp
sre@cpp:~/unit_test$ g++ -std=c++17 test_square.cpp square.cpp -lgtest -lgtest_main -pthread -o test_square

sre@cpp:~/unit_test$ ls -l
total 532
-rw-rw-r-- 1 sre sre     56 Oct  6 19:04 square.cpp
-rw-rw-r-- 1 sre sre     32 Oct  6 19:03 square.h
-rwxrwxr-x 1 sre sre 536152 Oct  6 19:04 test_square
-rw-rw-r-- 1 sre sre    603 Oct  6 19:03 test_square.cpp
sre@cpp:~/unit_test$ ./test_square 
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

