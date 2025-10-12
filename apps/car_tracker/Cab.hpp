// Cab.hpp
#ifndef CAB_HPP
#define CAB_HPP

#include "Utilities.hpp"

class Cab {
private:
    int passengers;
    bool has_ac;

public:
    Cab(int passengers = 1, bool has_ac = true);
    void add_passenger();
    void print_status() const;
};

#endif
