
BUILD
-----
sre@cpp:~/car_tracker/build$ rm -rf *
sre@cpp:~/car_tracker/build$ cmake -Wno-dev ..
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
-- Build files have been written to: /home/sre/car_tracker/build

sre@cpp:~/car_tracker/build$ cmake --build . --clean-first
[  4%] Building CXX object CMakeFiles/car_tracker.dir/main.cpp.o
[  8%] Building CXX object CMakeFiles/car_tracker.dir/Car.cpp.o
[ 12%] Building CXX object CMakeFiles/car_tracker.dir/Engine.cpp.o
[ 16%] Building CXX object CMakeFiles/car_tracker.dir/Transmission.cpp.o
[ 20%] Building CXX object CMakeFiles/car_tracker.dir/Tire.cpp.o
[ 25%] Building CXX object CMakeFiles/car_tracker.dir/Body.cpp.o
[ 29%] Building CXX object CMakeFiles/car_tracker.dir/Cab.cpp.o
[ 33%] Building CXX object CMakeFiles/car_tracker.dir/Location.cpp.o
[ 37%] Building CXX object CMakeFiles/car_tracker.dir/Utilities.cpp.o
[ 41%] Linking CXX executable car_tracker
[ 41%] Built target car_tracker
[ 45%] Building CXX object CMakeFiles/car_tracker_tests.dir/tests/test_car.cpp.o
[ 50%] Building CXX object CMakeFiles/car_tracker_tests.dir/tests/test_engine.cpp.o
[ 54%] Building CXX object CMakeFiles/car_tracker_tests.dir/tests/test_transmission.cpp.o
[ 58%] Building CXX object CMakeFiles/car_tracker_tests.dir/tests/test_body.cpp.o
[ 62%] Building CXX object CMakeFiles/car_tracker_tests.dir/tests/test_cab.cpp.o
[ 66%] Building CXX object CMakeFiles/car_tracker_tests.dir/Car.cpp.o
[ 70%] Building CXX object CMakeFiles/car_tracker_tests.dir/Engine.cpp.o
[ 75%] Building CXX object CMakeFiles/car_tracker_tests.dir/Transmission.cpp.o
[ 79%] Building CXX object CMakeFiles/car_tracker_tests.dir/Tire.cpp.o
[ 83%] Building CXX object CMakeFiles/car_tracker_tests.dir/Body.cpp.o
[ 87%] Building CXX object CMakeFiles/car_tracker_tests.dir/Cab.cpp.o
[ 91%] Building CXX object CMakeFiles/car_tracker_tests.dir/Location.cpp.o
[ 95%] Building CXX object CMakeFiles/car_tracker_tests.dir/Utilities.cpp.o
[100%] Linking CXX executable car_tracker_tests
[100%] Built target car_tracker_tests

sre@cpp:~/car_tracker/build$ make
[ 41%] Built target car_tracker
[100%] Built target car_tracker_tests

sre@cpp:~/car_tracker/build$ ls -l
total 748
-rwxrwxr-x 1 sre sre  91424 Oct 10 17:35 car_tracker
-rwxrwxr-x 1 sre sre 703304 Oct 10 17:35 car_tracker_tests
-rw-rw-r-- 1 sre sre  14890 Oct 10 17:35 CMakeCache.txt
drwxrwxr-x 7 sre sre   4096 Oct 10 17:35 CMakeFiles
-rw-rw-r-- 1 sre sre   1618 Oct 10 17:35 cmake_install.cmake
-rw-rw-r-- 1 sre sre  19226 Oct 10 17:35 Makefile

EXECUTE
-------
sre@cpp:~/car_tracker/build$ ./car_tracker
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

sre@cpp:~/car_tracker/build$ ./car_tracker_tests 
Running main() from ./googletest/src/gtest_main.cc
[==========] Running 8 tests from 5 test suites.
[----------] Global test environment set-up.
[----------] 4 tests from CarTest
[ RUN      ] CarTest.NegativeRefuelThrows
Caught expected error: Negative refuel amount
[       OK ] CarTest.NegativeRefuelThrows (0 ms)
[ RUN      ] CarTest.InvalidTireIndexThrows
Caught expected error: Invalid tire index
[       OK ] CarTest.InvalidTireIndexThrows (0 ms)
[ RUN      ] CarTest.NoFuelThrows
Engine: Fuel drained for testing
Caught expected error: No fuel
[       OK ] CarTest.NoFuelThrows (0 ms)
[ RUN      ] CarTest.FlatTireThrows
Tire 0: Flattened for testing
Caught expected error: Flat tire
[       OK ] CarTest.FlatTireThrows (0 ms)
[----------] 4 tests from CarTest (0 ms total)

[----------] 1 test from EngineTest
[ RUN      ] EngineTest.InvalidParametersThrows
Caught expected error: Invalid engine parameters
[       OK ] EngineTest.InvalidParametersThrows (0 ms)
[----------] 1 test from EngineTest (0 ms total)

[----------] 1 test from TransmissionTest
[ RUN      ] TransmissionTest.InvalidGearThrows
Caught expected error: Invalid gear
[       OK ] TransmissionTest.InvalidGearThrows (0 ms)
[----------] 1 test from TransmissionTest (0 ms total)

[----------] 1 test from BodyTest
[ RUN      ] BodyTest.InvalidParametersThrows
Caught expected error: Invalid body parameters
[       OK ] BodyTest.InvalidParametersThrows (0 ms)
[----------] 1 test from BodyTest (0 ms total)

[----------] 1 test from CabTest
[ RUN      ] CabTest.InvalidParametersThrows
Caught expected error: Invalid passenger count
[       OK ] CabTest.InvalidParametersThrows (0 ms)
[----------] 1 test from CabTest (0 ms total)

[----------] Global test environment tear-down
[==========] 8 tests from 5 test suites ran. (0 ms total)
[  PASSED  ] 8 tests.

VIEW LOGS
----------
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

sre@cpp:~/car_tracker/build$ cat car_tracker.log 
Car drove to (10.000000, 20.000000) at speed 60.000000 km/h, distance traveled: 22.360680 km
Tire: Inflated by 5.000000 PSI. New pressure: 37.000000 PSI
Engine: Refueled 5.000000 gal. New level: 13.881966 gal
Car drove to (30.000000, 40.000000) at speed 80.000000 km/h, distance traveled: 50.644951 km

sre@cpp:~/car_tracker/build$ cat test_car_tracker.log 
Engine: Fuel drained for testing
Tire 0: Flattened for testing

