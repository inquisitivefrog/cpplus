

sre@cpp:~/debugging/multi-file/build$ perf stat ./main
Cleared /tmp/test directories
Created directory: "/tmp/test0"
Created directory: "/tmp/test99"
Directory creation completed. Starting threads...
Thread-17636030463682306013: Scanning path: /tmp/test0
Thread-17636030463682306013: Scanning path: /tmp/test0
Thread-17636030463682306013: Found file: "/tmp/test0/file0.txt"
Thread-17636030463682306013: Found file: "/tmp/test0/file1.txt"
Thread-17636030463682306013: Found file: "/tmp/test0/file2.txt"
Thread-17636030463682306013: Scanned /tmp/test0, dirs: 0, files: 3, total dirs: 0, total files: 6
Thread-3103490509649528908: Scanning path: /tmp/test99
Thread-3103490509649528908: Scanning path: /tmp/test99
Thread-3103490509649528908: Found file: "/tmp/test99/file0.txt"
Thread-3103490509649528908: Found file: "/tmp/test99/file1.txt"
Thread-3103490509649528908: Found file: "/tmp/test99/file2.txt"
Thread-3103490509649528908: Scanned /tmp/test99, dirs: 0, files: 3, total dirs: 0, total files: 300
Thread-17636030463682306013: Stopped.
Thread-3103490509649528908: Stopped.
Main completed. Total dirs: 0, Total files: 300

 Performance counter stats for './main':

             21.60 msec task-clock                       #    0.038 CPUs utilized             
               108      context-switches                 #    5.000 K/sec                     
                10      cpu-migrations                   #  463.008 /sec                      
               132      page-faults                      #    6.112 K/sec                     
   <not supported>      cycles                                                                
   <not supported>      instructions                                                          
   <not supported>      branches                                                              
   <not supported>      branch-misses                                                         

       0.568811368 seconds time elapsed

       0.002418000 seconds user
       0.021768000 seconds sys


sre@cpp:~/debugging/multi-file/build$ perf record ./main
Cleared /tmp/test directories
Created directory: "/tmp/test0"
Created directory: "/tmp/test99"
Directory creation completed. Starting threads...
Thread-13228645608551350065: Scanning path: /tmp/test0
Thread-13228645608551350065: Scanning path: /tmp/test0
Thread-13228645608551350065: Found file: "/tmp/test0/file0.txt"
Thread-13228645608551350065: Found file: "/tmp/test0/file1.txt"
Thread-13228645608551350065: Found file: "/tmp/test0/file2.txt"
Thread-13228645608551350065: Scanned /tmp/test0, dirs: 0, files: 3, total dirs: 0, total files: 6
Thread-14765959765916953457: Scanning path: /tmp/test99
Thread-14765959765916953457: Scanning path: /tmp/test99
Thread-14765959765916953457: Found file: "/tmp/test99/file0.txt"
Thread-13228645608551350065: Stopped.
Thread-14765959765916953457: Found file: "/tmp/test99/file1.txt"
Thread-14765959765916953457: Found file: "/tmp/test99/file2.txt"
Thread-14765959765916953457: Scanned /tmp/test99, dirs: 0, files: 3, total dirs: 0, total files: 300
Thread-14765959765916953457: Stopped.
Main completed. Total dirs: 0, Total files: 300
[ perf record: Woken up 1 times to write data ]
[ perf record: Captured and wrote 0.009 MB perf.data (65 samples) ]

sre@cpp:~/debugging/multi-file/build$ ls -l
total 1232
-rw-rw-r-- 1 sre sre  14758 Oct  8 23:31 CMakeCache.txt
drwxrwxr-x 6 sre sre   4096 Oct  8 23:31 CMakeFiles
-rw-rw-r-- 1 sre sre   1641 Oct  8 23:31 cmake_install.cmake
-rwxrwxr-x 2 sre sre 811760 Oct  8 23:31 main
-rw-rw-r-- 1 sre sre   6001 Oct  8 23:31 Makefile
-rw------- 1 sre sre  11568 Oct  8 23:55 perf.data
sre@cpp:~/debugging/multi-file/build$ 

sre@cpp:~/debugging/multi-file/build$ perf report perf.data

