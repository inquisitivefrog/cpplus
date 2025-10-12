
BUILD
-----
sre@cpp:~/car_tracker$ cd build/
sre@cpp:~/car_tracker/build$ cmake -Wno-dev ..
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/sre/car_tracker/build
sre@cpp:~/car_tracker/build$ cmake --build . --clean-first
[ 10%] Building CXX object CMakeFiles/car_tracker.dir/main.cpp.o
[ 20%] Building CXX object CMakeFiles/car_tracker.dir/Car.cpp.o
[ 30%] Building CXX object CMakeFiles/car_tracker.dir/Engine.cpp.o
[ 40%] Building CXX object CMakeFiles/car_tracker.dir/Transmission.cpp.o
[ 50%] Building CXX object CMakeFiles/car_tracker.dir/Tire.cpp.o
[ 60%] Building CXX object CMakeFiles/car_tracker.dir/Body.cpp.o
[ 70%] Building CXX object CMakeFiles/car_tracker.dir/Cab.cpp.o
[ 80%] Building CXX object CMakeFiles/car_tracker.dir/Location.cpp.o
[ 90%] Building CXX object CMakeFiles/car_tracker.dir/Utilities.cpp.o
[100%] Linking CXX executable car_tracker
[100%] Built target car_tracker

EXECUTE
-------
sre@cpp:~/car_tracker/build$ ./car_tracker 
=== Car Status ===
^C

DEBUG
-----
NOTE: run, then CTL-C, then bt

sre@cpp:~/car_tracker/build$ gdb ./car_tracker 
GNU gdb (Ubuntu 15.0.50.20240403-0ubuntu1) 15.0.50.20240403-git
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "aarch64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./car_tracker...
(gdb) run
Starting program: /home/sre/car_tracker/build/car_tracker 
Downloading separate debug info for system-supplied DSO at 0xfffff7ffb000
[Thread debugging using libthread_db enabled]                                   
Using host libthread_db library "/lib/aarch64-linux-gnu/libthread_db.so.1".
=== Car Status ===

^C
Program received signal SIGINT, Interrupt.
Download failed: Invalid argument.  Continuing without source file ./nptl/../sysdeps/nptl/futex-internal.h.
futex_wait (private=0, expected=2, futex_word=0xaaaaaaac0028 <log_mutex>)
    at ../sysdeps/nptl/futex-internal.h:146
warning: 146	../sysdeps/nptl/futex-internal.h: No such file or directory
(gdb) bt
#0  futex_wait (private=0, expected=2, futex_word=0xaaaaaaac0028 <log_mutex>)
    at ../sysdeps/nptl/futex-internal.h:146
#1  __GI___lll_lock_wait (futex=futex@entry=0xaaaaaaac0028 <log_mutex>, 
    private=private@entry=0) at ./nptl/lowlevellock.c:49
#2  0x0000fffff7b08c74 in lll_mutex_lock_optimized (
    mutex=0xaaaaaaac0028 <log_mutex>) at ./nptl/pthread_mutex_lock.c:48
#3  ___pthread_mutex_lock (mutex=0xaaaaaaac0028 <log_mutex>)
    at ./nptl/pthread_mutex_lock.c:93
#4  0x0000aaaaaaaa3378 in __gthread_mutex_lock (
    __mutex=0xaaaaaaac0028 <log_mutex>)
    at /usr/include/aarch64-linux-gnu/c++/13/bits/gthr-default.h:749
#5  0x0000aaaaaaaa33dc in std::mutex::lock (this=0xaaaaaaac0028 <log_mutex>)
    at /usr/include/c++/13/bits/std_mutex.h:113
#6  0x0000aaaaaaaa353c in std::lock_guard<std::mutex>::lock_guard (
    this=0xfffffffff070, __m=...) at /usr/include/c++/13/bits/std_mutex.h:249
#7  0x0000aaaaaaaa91b4 in Location<double>::print (this=0xfffffffff108)
    at /home/sre/car_tracker/Location.cpp:17
#8  0x0000aaaaaaaa4680 in Car<double>::print_status (this=0xfffffffff108)
    at /home/sre/car_tracker/Car.cpp:48
#9  0x0000aaaaaaaa3170 in main () at /home/sre/car_tracker/main.cpp:11
(gdb) info locals
_x2tmp = 2
_x0tmp = 187649984561192
_x0 = 187649984561192
_x2 = 2
_x8 = 98
_x3tmp = 0
_x1tmp = <optimized out>
_x1 = 128
_x3 = 0
_sys_result = <optimized out>
__ret = <optimized out>
err = <optimized out>
(gdb) info threads
  Id   Target Id                                        Frame 
* 1    Thread 0xfffff7fef140 (LWP 204257) "car_tracker" futex_wait (private=0, 
    expected=2, futex_word=0xaaaaaaac0028 <log_mutex>)
    at ../sysdeps/nptl/futex-internal.h:146
(gdb) 

