
COLLECTION
----------
sre@cpp:~/debugging/multi-file/build$ valgrind --tool=massif --massif-out-file=massif_opt.out ./main
==196599== Massif, a heap profiler
==196599== Copyright (C) 2003-2017, and GNU GPL'd, by Nicholas Nethercote
==196599== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==196599== Command: ./main
==196599== 
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
Thread-94306656: Scanning path: /tmp/test0
Thread-94306656: Found file: "/tmp/test0/file0.txt"
Thread-94306656: Found file: "/tmp/test0/file1.txt"
Thread-94306656: Found file: "/tmp/test0/file2.txt"
Thread-94306656: Scanned /tmp/test0, dirs: 0, files: 3, total dirs: 0, total files: 228
Thread-102760800: Scanning path: /tmp/test99
Thread-102760800: Found file: "/tmp/test99/file0.txt"
Thread-102760800: Found file: "/tmp/test99/file1.txt"
Thread-102760800: Found file: "/tmp/test99/file2.txt"
Thread-102760800: Scanned /tmp/test99, dirs: 0, files: 3, total dirs: 0, total files: 300
Main completed. Total dirs: 0, Total files: 300
==196599== 

ANALYSIS
--------
sre@cpp:~/debugging/multi-file/build$ ms_print massif_opt.out > massif_opt.txt
sre@cpp:~/debugging/multi-file/build$ head -n 20 massif_opt.txt
--------------------------------------------------------------------------------
Command:            ./main
Massif arguments:   --massif-out-file=massif_opt.out
ms_print arguments: massif_opt.out
--------------------------------------------------------------------------------


    KB
146.9^                                                  ::                    
     |                                                # :::: ::@::@:::@:::@:::
     |                                                # :::: ::@::@:::@:::@:::
     |                                                # :::: ::@::@:::@:::@:::
     |                                                # :::: ::@::@:::@:::@:::
     |                                                #::::::::@::@:::@:::@:::
     |                                                #::::::::@::@:::@:::@:::
     |                                                #::::::::@::@:::@:::@:::
     |                                                #::::::::@::@:::@:::@:::
     |                      @                         #::::::::@::@:::@:::@:::
     |                      @@:::::::::::::::::::::@:@#::::::::@::@:::@:::@:::
     |                     :@@:::::::::::::::::::::@:@#::::::::@::@:::@:::@:::
sre@cpp:~/debugging/multi-file/build$ 

