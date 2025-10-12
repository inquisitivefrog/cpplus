// Body.cpp
#include "Body.hpp"
#include <stdexcept>
#include <iostream>

Body::Body(std::string color, double weight, double integrity)
    : color(color), weight(weight), integrity(integrity) {
    if (weight <= 0 || integrity < 0 || integrity > 100) {
        throw std::invalid_argument("Invalid body parameters");
    }
}

void Body::damage(double amount) {
    integrity = std::max(0.0, integrity - amount);
}

void Body::print_status() const {
    std::cout << "Body: Color=" << color << ", Weight=" << weight
              << " kg, Integrity=" << integrity << "%\n";
}
