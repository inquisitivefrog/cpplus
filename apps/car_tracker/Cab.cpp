// Cab.cpp
#include "Cab.hpp"
#include <iostream>

Cab::Cab(int passengers, bool has_ac) : passengers(passengers), has_ac(has_ac) {
    if (passengers < 0) throw std::invalid_argument("Invalid passenger count");
}

void Cab::print_status() const {
    std::cout << "Cab: Seats=" << passengers << ", AC=" << (has_ac ? "On" : "Off") << "\n";
}
