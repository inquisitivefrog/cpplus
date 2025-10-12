// Transmission.hpp
#ifndef TRANSMISSION_HPP
#define TRANSMISSION_HPP

#include "Utilities.hpp"

class Transmission {
private:
    int current_gear; // 0=neutral, 1-6=gears
    bool is_automatic;

public:
    Transmission(bool is_automatic = true);
    void shift_gear(int gear);
    void auto_shift(double speed);
    int get_gear() const;
    void print_status() const;
};

#endif
