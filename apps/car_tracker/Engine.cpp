// Engine.cpp
#include "Engine.hpp"
#include <stdexcept>
#include <iostream>

Engine::Engine(double fuel_level, double max_fuel, double horsepower)
    : fuel_level(fuel_level), max_fuel(max_fuel), horsepower(horsepower) {
    if (fuel_level < 0 || max_fuel < fuel_level || horsepower <= 0) {
        throw std::invalid_argument("Invalid engine parameters");
    }
}

void Engine::consume_fuel(double amount) {
    fuel_level = std::max(0.0, fuel_level - amount);
    if (fuel_level == 0.0) {
        log("Engine: Out of fuel!");
    }
}

void Engine::refuel(double amount) {
    if (amount < 0) throw std::invalid_argument("Negative refuel amount");
    fuel_level = std::min(max_fuel, fuel_level + amount);
    log("Engine: Refueled " + std::to_string(amount) + " gal. New level: " + std::to_string(fuel_level) + " gal");
}

double Engine::get_fuel_level() const {
    return fuel_level;
}

void Engine::print_status() const {
    std::cout << "Engine: Fuel=" << fuel_level << "/" << max_fuel
              << " gal, Horsepower=" << horsepower << "\n";
}

void Engine::drain_fuel() {
    fuel_level = 0.0;
    log("Engine: Fuel drained for testing");
}
