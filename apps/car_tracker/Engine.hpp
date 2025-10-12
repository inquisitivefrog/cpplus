// Engine.hpp
#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Utilities.hpp"

class Engine {
private:
    double fuel_level; // Gallons
    double max_fuel; // Gallons
    double horsepower;

public:
    Engine(double fuel_level = 10.0, double max_fuel = 15.0, double horsepower = 200.0);
    void consume_fuel(double amount);
    void refuel(double amount);
    double get_fuel_level() const;
    void print_status() const;
    void drain_fuel(); // For testing
};

#endif
