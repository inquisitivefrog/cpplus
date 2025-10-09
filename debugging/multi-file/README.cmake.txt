
BUILD
-----
sre@cpp:~/debugging/multi-file/build$ rm -rf /tmp/test* CMakeCache.txt CMakeFiles/ *.out *.txt cmake_install.cmake Makefile main
sre@cpp:~/debugging/multi-file/build$ cmake -Wno-dev ..
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
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE  
-- Configuring done (0.2s)
-- Generating done (0.0s)
-- Build files have been written to: /home/sre/debugging/multi-file/build
sre@cpp:~/debugging/multi-file/build$ cmake --build . --clean-first
[ 33%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[ 66%] Building CXX object CMakeFiles/main.dir/DirectoryManager.cpp.o
[100%] Linking CXX executable main
[100%] Built target main

sre@cpp:~/debugging/multi-file/build$ ls -l
total 712
-rw-rw-r-- 1 sre sre  14758 Oct  8 20:18 CMakeCache.txt
drwxrwxr-x 6 sre sre   4096 Oct  8 20:18 CMakeFiles
-rw-rw-r-- 1 sre sre   1641 Oct  8 20:18 cmake_install.cmake
-rwxrwxr-x 1 sre sre 617792 Oct  8 20:18 main
-rw-rw-r-- 1 sre sre   6001 Oct  8 20:18 Makefile

EXECUTION
---------
sre@cpp:~/debugging/multi-file/build$ ./main
Cleared /tmp/test directories
Created directory: "/tmp/test0"
Created file: "/tmp/test0/file0.txt"
Created file: "/tmp/test0/file1.txt"
Created file: "/tmp/test0/file2.txt"
Created directory: "/tmp/test99"
Created file: "/tmp/test99/file0.txt"
Created file: "/tmp/test99/file1.txt"
Created file: "/tmp/test99/file2.txt"
Directory creation completed. Starting threads...
Thread-263305535222112: Scanning path: /tmp/test0
Thread-263305535222112: Found file: "/tmp/test0/file0.txt"
Thread-263305535222112: Found file: "/tmp/test0/file1.txt"
Thread-263305535222112: Found file: "/tmp/test0/file2.txt"
Thread-263305535222112: Scanned /tmp/test0, dirs: 0, files: 3, total dirs: 0, total files: 21
Thread-263305535222112: Scanning path: /tmp/test99
Thread-263305535222112: Found file: "/tmp/test99/file0.txt"
Thread-263305535222112: Found file: "/tmp/test99/file1.txt"
Thread-263305535222112: Found file: "/tmp/test99/file2.txt"
Thread-263305535222112: Scanned /tmp/test99, dirs: 0, files: 3, total dirs: 0, total files: 300
Main completed. Total dirs: 0, Total files: 300
sre@cpp:~/debugging/multi-file/build$ find /tmp/test* -type f | wc -l
300

