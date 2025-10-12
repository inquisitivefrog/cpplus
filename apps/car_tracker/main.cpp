// main.cpp
#include "Car.hpp"
#include "Utilities.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        init_log();
        Car<double> car(Location<double>(0.0, 0.0));
        car.print_status();
        car.drive(10.0, 20.0, 60.0);
        car.print_status();
        car.inflate_tire(0, 5.0);
        car.print_status();
        car.refuel(5.0);
        car.print_status();
        car.drive(30.0, 40.0, 80.0);
        car.print_status();
        close_log();
    } catch (const std::exception& e) {
        std::lock_guard<std::mutex> lock(log_mutex);
        std::cerr << "Error: " << e.what() << "\n";
        close_log();
        return 1;
    }
    return 0;
}
