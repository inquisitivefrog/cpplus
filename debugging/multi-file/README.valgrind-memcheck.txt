
sre@cpp:~/debugging/multi-file/build$ valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s ./main
==196775== Memcheck, a memory error detector
==196775== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==196775== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==196775== Command: ./main
==196775== 
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
Thread-94372192: Scanning path: /tmp/test0
Thread-94372192: Found file: "/tmp/test0/file0.txt"
Thread-94372192: Found file: "/tmp/test0/file1.txt"
Thread-94372192: Found file: "/tmp/test0/file2.txt"
Thread-94372192: Scanned /tmp/test0, dirs: 0, files: 3, total dirs: 0, total files: 3
Thread-102826336: Scanning path: /tmp/test99
Thread-102826336: Found file: "/tmp/test99/file0.txt"
Thread-102826336: Found file: "/tmp/test99/file1.txt"
Thread-102826336: Found file: "/tmp/test99/file2.txt"
Thread-102826336: Scanned /tmp/test99, dirs: 0, files: 3, total dirs: 0, total files: 300
Main completed. Total dirs: 0, Total files: 300
==196775== 
==196775== HEAP SUMMARY:
==196775==     in use at exit: 0 bytes in 0 blocks
==196775==   total heap usage: 3,707 allocs, 3,707 frees, 6,315,149 bytes allocated
==196775== 
==196775== All heap blocks were freed -- no leaks are possible
==196775== 
==196775== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

