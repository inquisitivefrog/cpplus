
sre@cpp:~/car_tracker/build$ ls -l
total 756
-rwxrwxr-x 1 sre sre  91424 Oct 10 17:35 car_tracker
-rw-rw-r-- 1 sre sre    302 Oct 10 17:35 car_tracker.log
-rwxrwxr-x 1 sre sre 703304 Oct 10 17:35 car_tracker_tests
-rw-rw-r-- 1 sre sre  14890 Oct 10 17:35 CMakeCache.txt
drwxrwxr-x 7 sre sre   4096 Oct 10 17:35 CMakeFiles
-rw-rw-r-- 1 sre sre   1618 Oct 10 17:35 cmake_install.cmake
-rw-rw-r-- 1 sre sre  19226 Oct 10 17:35 Makefile
-rw-rw-r-- 1 sre sre     63 Oct 10 17:35 test_car_tracker.log

sre@cpp:~/car_tracker/build$ nm -an ./car_tracker | c++filt | grep -E 'Car|Engine|Location'
0000000000000000 a Car.cpp
0000000000000000 a Engine.cpp
0000000000000000 a Location.cpp
00000000000028f8 W Car<double>::~Car()
00000000000028f8 W Car<double>::~Car()
0000000000002eac W Car<double>::Car(Location<double>)
0000000000002eac W Car<double>::Car(Location<double>)
00000000000030ec W Car<double>::drive(double, double, double)
00000000000036e4 W Car<double>::refuel(double)
0000000000003710 W Car<double>::inflate_tire(unsigned long, double)
00000000000037c4 W Car<double>::print_status() const
0000000000003a0c W Car<double>::drain_fuel()
0000000000003a30 W Car<double>::flatten_tire(unsigned long)
0000000000003c24 W Car<int>::Car(Location<int>)
0000000000003c24 W Car<int>::Car(Location<int>)
0000000000003e4c W Car<int>::drive(int, int, double)
000000000000443c W Car<int>::refuel(double)
0000000000004468 W Car<int>::inflate_tire(unsigned long, double)
000000000000451c W Car<int>::print_status() const
0000000000004764 W Car<int>::drain_fuel()
0000000000004788 W Car<int>::flatten_tire(unsigned long)
0000000000005fe4 T Engine::Engine(double, double, double)
0000000000005fe4 T Engine::Engine(double, double, double)
00000000000060a4 T Engine::consume_fuel(double)
00000000000061dc T Engine::refuel(double)
0000000000006460 T Engine::get_fuel_level() const
0000000000006478 T Engine::print_status() const
000000000000651c T Engine::drain_fuel()
0000000000007070 W Location<double>::Location(double, double)
0000000000007070 W Location<double>::Location(double, double)
00000000000070a4 W Location<double>::distance_to(Location<double> const&) const
0000000000007108 W Location<double>::print() const
0000000000007184 W Location<int>::Location(int, int)
0000000000007184 W Location<int>::Location(int, int)
00000000000071b8 W Location<int>::distance_to(Location<int> const&) const
0000000000007224 W Location<int>::print() const


sre@cpp:~/car_tracker/build$ strings ./car_tracker | c++filt | grep -E 'Car|Engine|Location|Out of fuel'
Car drove to (
=== Car Status ===
Engine: Out of fuel!
Engine: Refueled 
Engine: Fuel=
Engine: Fuel drained for testing
Location: (
Car.cpp
Engine.cpp
Location.cpp
Location<int>::Location(int, int)
Engine::Engine(double, double, double)
Engine::refuel(double)
Engine::print_status() const
Car<double>::Car(Location<double>)
Location<int>::print() const
Engine::drain_fuel()
Location<double>::Location(double, double)
Engine::get_fuel_level() const
Engine::consume_fuel(double)
Car<double>::drive(double, double, double)
Location<double>::distance_to(Location<double> const&) const
Engine::Engine(double, double, double)
Car<double>::~Car()
Car<double>::drain_fuel()
Car<int>::drain_fuel()
Car<double>::~Car()
Car<double>::print_status() const
Car<int>::Car(Location<int>)
Location<double>::print() const
Car<int>::print_status() const
Car<double>::inflate_tire(unsigned long, double)
Car<int>::inflate_tire(unsigned long, double)
Location<int>::Location(int, int)
Car<double>::refuel(double)
Car<int>::refuel(double)
Location<double>::Location(double, double)
Car<double>::flatten_tire(unsigned long)
Car<int>::flatten_tire(unsigned long)
Car<double>::Car(Location<double>)
Location<int>::distance_to(Location<int> const&) const
Car<int>::drive(int, int, double)
Car<int>::Car(Location<int>)
sre@cpp:~/car_tracker/build$ 

STRIP SYMBOLS
-------------
sre@cpp:~/car_tracker/build$ ls -l
total 784
-rwxrwxr-x 1 sre sre  91424 Oct 10 17:35 car_tracker
-rw-rw-r-- 1 sre sre    302 Oct 10 18:04 car_tracker.log
-rwxrwxr-x 1 sre sre 703304 Oct 10 17:35 car_tracker_tests

sre@cpp:~/car_tracker/build$ strip --strip-unneeded car_tracker
sre@cpp:~/car_tracker/build$ ls -l
total 780
-rwxrwxr-x 1 sre sre  67592 Oct 10 18:06 car_tracker
-rw-rw-r-- 1 sre sre    302 Oct 10 18:04 car_tracker.log
-rwxrwxr-x 1 sre sre 703304 Oct 10 17:35 car_tracker_tests

