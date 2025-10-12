// Tire.cpp
#include "Tire.hpp"
#include <stdexcept>

Tire::Tire(double pressure, double wear_level) : pressure(pressure), wear_level(wear_level) {
    if (pressure < 0 || wear_level < 0 || wear_level > 100) {
        throw std::invalid_argument("Invalid tire parameters");
    }
}

void Tire::wear(double amount) {
    wear_level = std::min(100.0, wear_level + amount);
}

bool Tire::is_flat() const {
    return pressure < 10.0;
}

void Tire::inflate(double psi) {
    if (psi < 0) throw std::invalid_argument("Negative PSI");
    pressure = std::min(40.0, pressure + psi);
    log("Tire: Inflated by " + std::to_string(psi) + " PSI. New pressure: " + std::to_string(pressure) + " PSI");
}

void Tire::set_pressure(double psi) {
    pressure = psi;
    // Removed log to avoid duplication with Car::flatten_tire
}
