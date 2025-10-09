
COLLECTION
----------
sre@cpp:~/debugging/multi-file/build$ valgrind --tool=helgrind --history-level=full --log-file=helgrind.out ./main
Cleared /tmp/test directories
Created directory: "/tmp/test0"
Created directory: "/tmp/test99"
Directory creation completed. Starting threads...
Thread-15390025641090298316: Scanning path: /tmp/test0
Thread-15390025641090298316: Scanning path: /tmp/test0
Thread-15390025641090298316: Found file: "/tmp/test0/file0.txt"
Thread-15390025641090298316: Found file: "/tmp/test0/file1.txt"
Thread-15390025641090298316: Found file: "/tmp/test0/file2.txt"
Thread-15390025641090298316: Scanned /tmp/test0, dirs: 0, files: 3, total dirs: 0, total files: 3
Thread-15390025641090298316: Scanning path: /tmp/test99
Thread-15390025641090298316: Scanning path: /tmp/test99
Thread-15390025641090298316: Found file: "/tmp/test99/file0.txt"
Thread-15390025641090298316: Found file: "/tmp/test99/file1.txt"
Thread-15390025641090298316: Found file: "/tmp/test99/file2.txt"
Thread-15390025641090298316: Scanned /tmp/test99, dirs: 0, files: 3, total dirs: 0, total files: 297
Thread-15390025641090298316: Stopped.
Thread-16470313854676777498: Stopped.
Main completed. Total dirs: 0, Total files: 300

REPORTING
---------
sre@cpp:~/debugging/multi-file/build$ cat helgrind.out 
==200300== Helgrind, a thread error detector
==200300== Copyright (C) 2007-2017, and GNU GPL'd, by OpenWorks LLP et al.
==200300== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==200300== Command: ./main
==200300== Parent PID: 191646
==200300== 
==200300== ---Thread-Announcement------------------------------------------
==200300== 
==200300== Thread #1 is the program's root thread
==200300== 
==200300== ----------------------------------------------------------------
==200300== 
==200300== Thread #1: lock order "0x1FFEFFFF10 before 0x1380B8" violated
==200300== 
==200300== Observed (incorrect) order is: acquisition of lock at 0x1380B8
==200300==    at 0x488F940: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-arm64-linux.so)
==200300==    by 0x10E0C7: __gthread_mutex_lock(pthread_mutex_t*) (gthr-default.h:749)
==200300==    by 0x10E387: std::mutex::lock() (std_mutex.h:113)
==200300==    by 0x110A43: std::lock_guard<std::mutex>::lock_guard(std::mutex&) (std_mutex.h:249)
==200300==    by 0x10CE63: main (main.cpp:104)
==200300== 
==200300==  followed by a later acquisition of lock at 0x1FFEFFFF10
==200300==    at 0x488F940: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-arm64-linux.so)
==200300==    by 0x10E0C7: __gthread_mutex_lock(pthread_mutex_t*) (gthr-default.h:749)
==200300==    by 0x10E387: std::mutex::lock() (std_mutex.h:113)
==200300==    by 0x110A43: std::lock_guard<std::mutex>::lock_guard(std::mutex&) (std_mutex.h:249)
==200300==    by 0x11736B: DirectoryManager::getDirCount() const (DirectoryManager.cpp:77)
==200300==    by 0x10CE83: main (main.cpp:106)
==200300== 
==200300== Required order was established by acquisition of lock at 0x1FFEFFFF10
==200300==    at 0x488F940: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-arm64-linux.so)
==200300==    by 0x10E0C7: __gthread_mutex_lock(pthread_mutex_t*) (gthr-default.h:749)
==200300==    by 0x10E387: std::mutex::lock() (std_mutex.h:113)
==200300==    by 0x110A43: std::lock_guard<std::mutex>::lock_guard(std::mutex&) (std_mutex.h:249)
==200300==    by 0x116F27: DirectoryManager::scanDirectory(std::basic_string_view<char, std::char_traits<char> >, std::basic_string_view<char, std::char_traits<char> >, bool) (DirectoryManager.cpp:53)
==200300==    by 0x10C79B: scanDirectories(DirectoryManager&, std::stop_token) (main.cpp:43)
==200300==    by 0x10C96F: main::{lambda(std::stop_token)#1}::operator()(std::stop_token) const (main.cpp:88)
==200300==    by 0x10DC4B: void std::__invoke_impl<void, main::{lambda(std::stop_token)#1}, std::stop_token>(std::__invoke_other, main::{lambda(std::stop_token)#1}&&, std::stop_token&&) (invoke.h:61)
==200300==    by 0x10DBBF: std::__invoke_result<main::{lambda(std::stop_token)#1}, std::stop_token>::type std::__invoke<main::{lambda(std::stop_token)#1}, std::stop_token>(main::{lambda(std::stop_token)#1}&&, std::stop_token&&) (invoke.h:96)
==200300==    by 0x10DB23: void std::thread::_Invoker<std::tuple<main::{lambda(std::stop_token)#1}, std::stop_token> >::_M_invoke<0ul, 1ul>(std::_Index_tuple<0ul, 1ul>) (std_thread.h:292)
==200300==    by 0x10DADB: std::thread::_Invoker<std::tuple<main::{lambda(std::stop_token)#1}, std::stop_token> >::operator()() (std_thread.h:299)
==200300==    by 0x10DABB: std::thread::_State_impl<std::thread::_Invoker<std::tuple<main::{lambda(std::stop_token)#1}, std::stop_token> > >::_M_run() (std_thread.h:244)
==200300== 
==200300==  followed by a later acquisition of lock at 0x1380B8
==200300==    at 0x488F940: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-arm64-linux.so)
==200300==    by 0x10E0C7: __gthread_mutex_lock(pthread_mutex_t*) (gthr-default.h:749)
==200300==    by 0x10E387: std::mutex::lock() (std_mutex.h:113)
==200300==    by 0x110A43: std::lock_guard<std::mutex>::lock_guard(std::mutex&) (std_mutex.h:249)
==200300==    by 0x116F77: DirectoryManager::scanDirectory(std::basic_string_view<char, std::char_traits<char> >, std::basic_string_view<char, std::char_traits<char> >, bool) (DirectoryManager.cpp:57)
==200300==    by 0x10C79B: scanDirectories(DirectoryManager&, std::stop_token) (main.cpp:43)
==200300==    by 0x10C96F: main::{lambda(std::stop_token)#1}::operator()(std::stop_token) const (main.cpp:88)
==200300==    by 0x10DC4B: void std::__invoke_impl<void, main::{lambda(std::stop_token)#1}, std::stop_token>(std::__invoke_other, main::{lambda(std::stop_token)#1}&&, std::stop_token&&) (invoke.h:61)
==200300==    by 0x10DBBF: std::__invoke_result<main::{lambda(std::stop_token)#1}, std::stop_token>::type std::__invoke<main::{lambda(std::stop_token)#1}, std::stop_token>(main::{lambda(std::stop_token)#1}&&, std::stop_token&&) (invoke.h:96)
==200300==    by 0x10DB23: void std::thread::_Invoker<std::tuple<main::{lambda(std::stop_token)#1}, std::stop_token> >::_M_invoke<0ul, 1ul>(std::_Index_tuple<0ul, 1ul>) (std_thread.h:292)
==200300==    by 0x10DADB: std::thread::_Invoker<std::tuple<main::{lambda(std::stop_token)#1}, std::stop_token> >::operator()() (std_thread.h:299)
==200300==    by 0x10DABB: std::thread::_State_impl<std::thread::_Invoker<std::tuple<main::{lambda(std::stop_token)#1}, std::stop_token> > >::_M_run() (std_thread.h:244)
==200300== 
==200300==  Lock at 0x1FFEFFFF10 was first observed
==200300==    at 0x488F940: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-arm64-linux.so)
==200300==    by 0x10E0C7: __gthread_mutex_lock(pthread_mutex_t*) (gthr-default.h:749)
==200300==    by 0x10E387: std::mutex::lock() (std_mutex.h:113)
==200300==    by 0x110A43: std::lock_guard<std::mutex>::lock_guard(std::mutex&) (std_mutex.h:249)
==200300==    by 0x116F27: DirectoryManager::scanDirectory(std::basic_string_view<char, std::char_traits<char> >, std::basic_string_view<char, std::char_traits<char> >, bool) (DirectoryManager.cpp:53)
==200300==    by 0x10C79B: scanDirectories(DirectoryManager&, std::stop_token) (main.cpp:43)
==200300==    by 0x10C96F: main::{lambda(std::stop_token)#1}::operator()(std::stop_token) const (main.cpp:88)
==200300==    by 0x10DC4B: void std::__invoke_impl<void, main::{lambda(std::stop_token)#1}, std::stop_token>(std::__invoke_other, main::{lambda(std::stop_token)#1}&&, std::stop_token&&) (invoke.h:61)
==200300==    by 0x10DBBF: std::__invoke_result<main::{lambda(std::stop_token)#1}, std::stop_token>::type std::__invoke<main::{lambda(std::stop_token)#1}, std::stop_token>(main::{lambda(std::stop_token)#1}&&, std::stop_token&&) (invoke.h:96)
==200300==    by 0x10DB23: void std::thread::_Invoker<std::tuple<main::{lambda(std::stop_token)#1}, std::stop_token> >::_M_invoke<0ul, 1ul>(std::_Index_tuple<0ul, 1ul>) (std_thread.h:292)
==200300==    by 0x10DADB: std::thread::_Invoker<std::tuple<main::{lambda(std::stop_token)#1}, std::stop_token> >::operator()() (std_thread.h:299)
==200300==    by 0x10DABB: std::thread::_State_impl<std::thread::_Invoker<std::tuple<main::{lambda(std::stop_token)#1}, std::stop_token> > >::_M_run() (std_thread.h:244)
==200300==  Address 0x1ffeffff10 is on thread #1's stack
==200300==  in frame #5, created by main (main.cpp:52)
==200300== 
==200300==  Lock at 0x1380B8 was first observed
==200300==    at 0x488F940: ??? (in /usr/libexec/valgrind/vgpreload_helgrind-arm64-linux.so)
==200300==    by 0x10E0C7: __gthread_mutex_lock(pthread_mutex_t*) (gthr-default.h:749)
==200300==    by 0x10E387: std::mutex::lock() (std_mutex.h:113)
==200300==    by 0x110A43: std::lock_guard<std::mutex>::lock_guard(std::mutex&) (std_mutex.h:249)
==200300==    by 0x10CA6F: main (main.cpp:55)
==200300==  Address 0x1380b8 is 0 bytes inside data symbol "cout_mutex"
==200300== 
==200300== 
==200300== 
==200300== Use --history-level=approx or =none to gain increased speed, at
==200300== the cost of reduced accuracy of conflicting-access information
==200300== For lists of detected and suppressed errors, rerun with: -s
==200300== ERROR SUMMARY: 2 errors from 1 contexts (suppressed: 1360 from 12)
sre@cpp:~/debugging/multi-file/build$ 

