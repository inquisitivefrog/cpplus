// Transmission.cpp
#include "Transmission.hpp"
#include <stdexcept>
#include <iostream>

Transmission::Transmission(bool is_automatic) : current_gear(0), is_automatic(is_automatic) {}

void Transmission::shift_gear(int gear) {
    if (gear < 0 || gear > 6) throw std::invalid_argument("Invalid gear");
    current_gear = gear;
}

void Transmission::auto_shift(double speed) {
    if (!is_automatic) return;
    current_gear = std::min(6, std::max(0, static_cast<int>(speed / 20.0)));
}

int Transmission::get_gear() const {
    return current_gear;
}

void Transmission::print_status() const {
    std::cout << "Transmission: Gear=" << current_gear
              << (is_automatic ? " (Automatic)" : " (Manual)") << "\n";
}
