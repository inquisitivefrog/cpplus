
PERF
----
sre@cpp:~/car_tracker/build$ perf record -g ./car_tracker
=== Car Status ===
Location: (0, 0)
Speed: 0 km/h, Distance Traveled: 0 km
Engine: Fuel=10/15 gal, Horsepower=200
Transmission: Gear=0 (Automatic)
Tire 0: Pressure=32 PSI, Wear=0%
Tire 1: Pressure=32 PSI, Wear=0%
Tire 2: Pressure=32 PSI, Wear=0%
Tire 3: Pressure=32 PSI, Wear=0%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
Car drove to (10.000000, 20.000000) at speed 60.000000 km/h, distance traveled: 22.360680 km
=== Car Status ===
Location: (10, 20)
Speed: 60 km/h, Distance Traveled: 22.3607 km
Engine: Fuel=8.88197/15 gal, Horsepower=200
Transmission: Gear=3 (Automatic)
Tire 0: Pressure=32 PSI, Wear=0.223607%
Tire 1: Pressure=32 PSI, Wear=0.223607%
Tire 2: Pressure=32 PSI, Wear=0.223607%
Tire 3: Pressure=32 PSI, Wear=0.223607%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
Tire: Inflated by 5.000000 PSI. New pressure: 37.000000 PSI
=== Car Status ===
Location: (10, 20)
Speed: 60 km/h, Distance Traveled: 22.3607 km
Engine: Fuel=8.88197/15 gal, Horsepower=200
Transmission: Gear=3 (Automatic)
Tire 0: Pressure=37 PSI, Wear=0.223607%
Tire 1: Pressure=32 PSI, Wear=0.223607%
Tire 2: Pressure=32 PSI, Wear=0.223607%
Tire 3: Pressure=32 PSI, Wear=0.223607%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
Engine: Refueled 5.000000 gal. New level: 13.881966 gal
=== Car Status ===
Location: (10, 20)
Speed: 60 km/h, Distance Traveled: 22.3607 km
Engine: Fuel=13.882/15 gal, Horsepower=200
Transmission: Gear=3 (Automatic)
Tire 0: Pressure=37 PSI, Wear=0.223607%
Tire 1: Pressure=32 PSI, Wear=0.223607%
Tire 2: Pressure=32 PSI, Wear=0.223607%
Tire 3: Pressure=32 PSI, Wear=0.223607%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
Car drove to (30.000000, 40.000000) at speed 80.000000 km/h, distance traveled: 50.644951 km
=== Car Status ===
Location: (30, 40)
Speed: 80 km/h, Distance Traveled: 50.645 km
Engine: Fuel=12.4678/15 gal, Horsepower=200
Transmission: Gear=4 (Automatic)
Tire 0: Pressure=37 PSI, Wear=0.50645%
Tire 1: Pressure=32 PSI, Wear=0.50645%
Tire 2: Pressure=32 PSI, Wear=0.50645%
Tire 3: Pressure=32 PSI, Wear=0.50645%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
[ perf record: Woken up 1 times to write data ]
[ perf record: Captured and wrote 0.006 MB perf.data (3 samples) ]

sre@cpp:~/car_tracker/build$ perf report --stdio > perf_report.txt
sre@cpp:~/car_tracker/build$ wc -l perf_report.txt 
254 perf_report.txt
sre@cpp:~/car_tracker/build$ cat perf_report.txt 
# To display the perf.data header info, please use --header/--header-only options.
#
#
# Total Lost Samples: 0
#
# Samples: 3  of event 'task-clock:ppp'
# Event count (approx.): 750000
#
# Children      Self  Command      Shared Object          Symbol                                                                                                                                                                            
# ........  ........  ...........  .....................  ..................................................................................................................................................................................
#
    66.67%     0.00%  car_tracker  car_tracker            [.] _start
            |
            ---_start
               __libc_start_main@@GLIBC_2.34
               __libc_start_call_main
               |          
               |--33.33%--main
               |          Car<double>::print_status() const
               |          Body::print_status() const
               |          std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
               |          std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
               |          _IO_fwrite
               |          _IO_file_xsputn@@GLIBC_2.17
               |          
                --33.33%--0xedef0ea1f30c
                          __run_exit_handlers
                          _dl_fini
                          _dl_call_fini
                          0xedef0ed36200
                          __cxa_finalize
                          0xedef0ed71620

    66.67%     0.00%  car_tracker  libc.so.6              [.] __libc_start_main@@GLIBC_2.34
            |
            ---__libc_start_main@@GLIBC_2.34
               __libc_start_call_main
               |          
               |--33.33%--main
               |          Car<double>::print_status() const
               |          Body::print_status() const
               |          std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
               |          std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
               |          _IO_fwrite
               |          _IO_file_xsputn@@GLIBC_2.17
               |          
                --33.33%--0xedef0ea1f30c
                          __run_exit_handlers
                          _dl_fini
                          _dl_call_fini
                          0xedef0ed36200
                          __cxa_finalize
                          0xedef0ed71620

    66.67%     0.00%  car_tracker  libc.so.6              [.] __libc_start_call_main
            |
            ---__libc_start_call_main
               |          
               |--33.33%--main
               |          Car<double>::print_status() const
               |          Body::print_status() const
               |          std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
               |          std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
               |          _IO_fwrite
               |          _IO_file_xsputn@@GLIBC_2.17
               |          
                --33.33%--0xedef0ea1f30c
                          __run_exit_handlers
                          _dl_fini
                          _dl_call_fini
                          0xedef0ed36200
                          __cxa_finalize
                          0xedef0ed71620

    33.33%    33.33%  car_tracker  libc.so.6              [.] _IO_file_xsputn@@GLIBC_2.17
            |
            ---_start
               __libc_start_main@@GLIBC_2.34
               __libc_start_call_main
               main
               Car<double>::print_status() const
               Body::print_status() const
               std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
               std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
               _IO_fwrite
               _IO_file_xsputn@@GLIBC_2.17

    33.33%    33.33%  car_tracker  libstdc++.so.6.0.33    [.] 0x00000000000e1620
            |
            ---_start
               __libc_start_main@@GLIBC_2.34
               __libc_start_call_main
               0xedef0ea1f30c
               __run_exit_handlers
               _dl_fini
               _dl_call_fini
               0xedef0ed36200
               __cxa_finalize
               0xedef0ed71620

    33.33%    33.33%  car_tracker  ld-linux-aarch64.so.1  [.] do_lookup_x
            |
            ---_start
               _dl_start
               _dl_sysdep_start
               dl_main
               _dl_relocate_object
               _dl_lookup_symbol_x
               do_lookup_x

    33.33%     0.00%  car_tracker  car_tracker            [.] main
            |
            ---main
               Car<double>::print_status() const
               Body::print_status() const
               std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
               std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
               _IO_fwrite
               _IO_file_xsputn@@GLIBC_2.17

    33.33%     0.00%  car_tracker  ld-linux-aarch64.so.1  [.] _start
            |
            ---_start
               _dl_start
               _dl_sysdep_start
               dl_main
               _dl_relocate_object
               _dl_lookup_symbol_x
               do_lookup_x

    33.33%     0.00%  car_tracker  libc.so.6              [.] 0x0000edef0ea1f30c
            |
            ---0xedef0ea1f30c
               __run_exit_handlers
               _dl_fini
               _dl_call_fini
               0xedef0ed36200
               __cxa_finalize
               0xedef0ed71620

    33.33%     0.00%  car_tracker  car_tracker            [.] Car<double>::print_status() const
            |
            ---Car<double>::print_status() const
               Body::print_status() const
               std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
               std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
               _IO_fwrite
               _IO_file_xsputn@@GLIBC_2.17

    33.33%     0.00%  car_tracker  ld-linux-aarch64.so.1  [.] _dl_start
            |
            ---_dl_start
               _dl_sysdep_start
               dl_main
               _dl_relocate_object
               _dl_lookup_symbol_x
               do_lookup_x

    33.33%     0.00%  car_tracker  libc.so.6              [.] __run_exit_handlers
            |
            ---__run_exit_handlers
               _dl_fini
               _dl_call_fini
               0xedef0ed36200
               __cxa_finalize
               0xedef0ed71620

    33.33%     0.00%  car_tracker  car_tracker            [.] Body::print_status() const
            |
            ---Body::print_status() const
               std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
               std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
               _IO_fwrite
               _IO_file_xsputn@@GLIBC_2.17

    33.33%     0.00%  car_tracker  ld-linux-aarch64.so.1  [.] _dl_fini
            |
            ---_dl_fini
               _dl_call_fini
               0xedef0ed36200
               __cxa_finalize
               0xedef0ed71620

    33.33%     0.00%  car_tracker  ld-linux-aarch64.so.1  [.] _dl_sysdep_start
            |
            ---_dl_sysdep_start
               dl_main
               _dl_relocate_object
               _dl_lookup_symbol_x
               do_lookup_x

    33.33%     0.00%  car_tracker  ld-linux-aarch64.so.1  [.] _dl_call_fini
            |
            ---_dl_call_fini
               0xedef0ed36200
               __cxa_finalize
               0xedef0ed71620

    33.33%     0.00%  car_tracker  ld-linux-aarch64.so.1  [.] dl_main
            |
            ---dl_main
               _dl_relocate_object
               _dl_lookup_symbol_x
               do_lookup_x

    33.33%     0.00%  car_tracker  libstdc++.so.6.0.33    [.] std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
            |
            ---std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*)
               std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
               _IO_fwrite
               _IO_file_xsputn@@GLIBC_2.17

    33.33%     0.00%  car_tracker  ld-linux-aarch64.so.1  [.] _dl_relocate_object
            |
            ---_dl_relocate_object
               _dl_lookup_symbol_x
               do_lookup_x

    33.33%     0.00%  car_tracker  libstdc++.so.6.0.33    [.] std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
            |
            ---std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
               _IO_fwrite
               _IO_file_xsputn@@GLIBC_2.17

    33.33%     0.00%  car_tracker  libstdc++.so.6.0.33    [.] 0x0000edef0ed36200
            |
            ---0xedef0ed36200
               __cxa_finalize
               0xedef0ed71620

    33.33%     0.00%  car_tracker  ld-linux-aarch64.so.1  [.] _dl_lookup_symbol_x
            |
            ---_dl_lookup_symbol_x
               do_lookup_x

    33.33%     0.00%  car_tracker  libc.so.6              [.] _IO_fwrite
            |
            ---_IO_fwrite
               _IO_file_xsputn@@GLIBC_2.17

    33.33%     0.00%  car_tracker  libc.so.6              [.] __cxa_finalize
            |
            ---__cxa_finalize
               0xedef0ed71620

    33.33%     0.00%  car_tracker  libstdc++.so.6.0.33    [.] 0x0000edef0ed71620
            |
            ---0xedef0ed71620



#
# (Tip: To show IPC for sampling periods use perf record -e '{cycles,instructions}:S' and then browse context)
#
sre@cpp:~/car_tracker/build$ 

VALGRIND HELGRIND
-----------------

sre@cpp:~/car_tracker/build$ valgrind --tool=helgrind --history-level=full --log-file=helgrind.out ./car_tracker
=== Car Status ===
Location: (0, 0)
Speed: 0 km/h, Distance Traveled: 0 km
Engine: Fuel=10/15 gal, Horsepower=200
Transmission: Gear=0 (Automatic)
Tire 0: Pressure=32 PSI, Wear=0%
Tire 1: Pressure=32 PSI, Wear=0%
Tire 2: Pressure=32 PSI, Wear=0%
Tire 3: Pressure=32 PSI, Wear=0%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
Car drove to (10.000000, 20.000000) at speed 60.000000 km/h, distance traveled: 22.360680 km
=== Car Status ===
Location: (10, 20)
Speed: 60 km/h, Distance Traveled: 22.3607 km
Engine: Fuel=8.88197/15 gal, Horsepower=200
Transmission: Gear=3 (Automatic)
Tire 0: Pressure=32 PSI, Wear=0.223607%
Tire 1: Pressure=32 PSI, Wear=0.223607%
Tire 2: Pressure=32 PSI, Wear=0.223607%
Tire 3: Pressure=32 PSI, Wear=0.223607%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
Tire: Inflated by 5.000000 PSI. New pressure: 37.000000 PSI
=== Car Status ===
Location: (10, 20)
Speed: 60 km/h, Distance Traveled: 22.3607 km
Engine: Fuel=8.88197/15 gal, Horsepower=200
Transmission: Gear=3 (Automatic)
Tire 0: Pressure=37 PSI, Wear=0.223607%
Tire 1: Pressure=32 PSI, Wear=0.223607%
Tire 2: Pressure=32 PSI, Wear=0.223607%
Tire 3: Pressure=32 PSI, Wear=0.223607%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
Engine: Refueled 5.000000 gal. New level: 13.881966 gal
=== Car Status ===
Location: (10, 20)
Speed: 60 km/h, Distance Traveled: 22.3607 km
Engine: Fuel=13.882/15 gal, Horsepower=200
Transmission: Gear=3 (Automatic)
Tire 0: Pressure=37 PSI, Wear=0.223607%
Tire 1: Pressure=32 PSI, Wear=0.223607%
Tire 2: Pressure=32 PSI, Wear=0.223607%
Tire 3: Pressure=32 PSI, Wear=0.223607%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
Car drove to (30.000000, 40.000000) at speed 80.000000 km/h, distance traveled: 50.644951 km
=== Car Status ===
Location: (30, 40)
Speed: 80 km/h, Distance Traveled: 50.645 km
Engine: Fuel=12.4678/15 gal, Horsepower=200
Transmission: Gear=4 (Automatic)
Tire 0: Pressure=37 PSI, Wear=0.50645%
Tire 1: Pressure=32 PSI, Wear=0.50645%
Tire 2: Pressure=32 PSI, Wear=0.50645%
Tire 3: Pressure=32 PSI, Wear=0.50645%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
sre@cpp:~/car_tracker/build$ ls -l
total 784
-rwxrwxr-x 1 sre sre  91424 Oct 10 17:35 car_tracker
-rw-rw-r-- 1 sre sre    302 Oct 10 18:04 car_tracker.log
-rwxrwxr-x 1 sre sre 703304 Oct 10 17:35 car_tracker_tests
-rw-rw-r-- 1 sre sre  14890 Oct 10 17:35 CMakeCache.txt
drwxrwxr-x 7 sre sre   4096 Oct 10 17:35 CMakeFiles
-rw-rw-r-- 1 sre sre   1618 Oct 10 17:35 cmake_install.cmake
-rw-r--r-- 1 sre sre    580 Oct 10 18:04 helgrind.out
-rw-rw-r-- 1 sre sre  19226 Oct 10 17:35 Makefile
-rw------- 1 sre sre   9068 Oct 10 18:02 perf.data
-rw-rw-r-- 1 sre sre  11629 Oct 10 18:02 perf_report.txt
-rw-rw-r-- 1 sre sre     63 Oct 10 17:35 test_car_tracker.log
sre@cpp:~/car_tracker/build$ wc -l helgrind.out 
11 helgrind.out
sre@cpp:~/car_tracker/build$ cat helgrind.out 
==211025== Helgrind, a thread error detector
==211025== Copyright (C) 2007-2017, and GNU GPL'd, by OpenWorks LLP et al.
==211025== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==211025== Command: ./car_tracker
==211025== Parent PID: 204205
==211025== 
==211025== 
==211025== Use --history-level=approx or =none to gain increased speed, at
==211025== the cost of reduced accuracy of conflicting-access information
==211025== For lists of detected and suppressed errors, rerun with: -s
==211025== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
sre@cpp:~/car_tracker/build$ 

VALGRIND MEMCHECK
-----------------

sre@cpp:~/car_tracker/build$ valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all -s ./car_tracker
==211035== Memcheck, a memory error detector
==211035== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==211035== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==211035== Command: ./car_tracker
==211035== 
=== Car Status ===
Location: (0, 0)
Speed: 0 km/h, Distance Traveled: 0 km
Engine: Fuel=10/15 gal, Horsepower=200
Transmission: Gear=0 (Automatic)
Tire 0: Pressure=32 PSI, Wear=0%
Tire 1: Pressure=32 PSI, Wear=0%
Tire 2: Pressure=32 PSI, Wear=0%
Tire 3: Pressure=32 PSI, Wear=0%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
Car drove to (10.000000, 20.000000) at speed 60.000000 km/h, distance traveled: 22.360680 km
=== Car Status ===
Location: (10, 20)
Speed: 60 km/h, Distance Traveled: 22.3607 km
Engine: Fuel=8.88197/15 gal, Horsepower=200
Transmission: Gear=3 (Automatic)
Tire 0: Pressure=32 PSI, Wear=0.223607%
Tire 1: Pressure=32 PSI, Wear=0.223607%
Tire 2: Pressure=32 PSI, Wear=0.223607%
Tire 3: Pressure=32 PSI, Wear=0.223607%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
Tire: Inflated by 5.000000 PSI. New pressure: 37.000000 PSI
=== Car Status ===
Location: (10, 20)
Speed: 60 km/h, Distance Traveled: 22.3607 km
Engine: Fuel=8.88197/15 gal, Horsepower=200
Transmission: Gear=3 (Automatic)
Tire 0: Pressure=37 PSI, Wear=0.223607%
Tire 1: Pressure=32 PSI, Wear=0.223607%
Tire 2: Pressure=32 PSI, Wear=0.223607%
Tire 3: Pressure=32 PSI, Wear=0.223607%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
Engine: Refueled 5.000000 gal. New level: 13.881966 gal
=== Car Status ===
Location: (10, 20)
Speed: 60 km/h, Distance Traveled: 22.3607 km
Engine: Fuel=13.882/15 gal, Horsepower=200
Transmission: Gear=3 (Automatic)
Tire 0: Pressure=37 PSI, Wear=0.223607%
Tire 1: Pressure=32 PSI, Wear=0.223607%
Tire 2: Pressure=32 PSI, Wear=0.223607%
Tire 3: Pressure=32 PSI, Wear=0.223607%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
Car drove to (30.000000, 40.000000) at speed 80.000000 km/h, distance traveled: 50.644951 km
=== Car Status ===
Location: (30, 40)
Speed: 80 km/h, Distance Traveled: 50.645 km
Engine: Fuel=12.4678/15 gal, Horsepower=200
Transmission: Gear=4 (Automatic)
Tire 0: Pressure=37 PSI, Wear=0.50645%
Tire 1: Pressure=32 PSI, Wear=0.50645%
Tire 2: Pressure=32 PSI, Wear=0.50645%
Tire 3: Pressure=32 PSI, Wear=0.50645%
Body: Color=Red, Weight=1500 kg, Integrity=100%
Cab: Seats=1, AC=On
=================
==211035== 
==211035== HEAP SUMMARY:
==211035==     in use at exit: 0 bytes in 0 blocks
==211035==   total heap usage: 15 allocs, 15 frees, 84,090 bytes allocated
==211035== 
==211035== All heap blocks were freed -- no leaks are possible
==211035== 
==211035== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

