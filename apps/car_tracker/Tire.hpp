// Tire.hpp
#ifndef TIRE_HPP
#define TIRE_HPP

#include "Utilities.hpp"

struct Tire {
private:
    double pressure; // PSI
    double wear_level; // 0 (new) to 100 (worn out)
public:
    Tire(double pressure = 32.0, double wear_level = 0.0);
    void wear(double amount);
    bool is_flat() const;
    void inflate(double psi);
    void set_pressure(double psi); // Test-only: Sets tire pressure
    double get_pressure() const { return pressure; }
    double get_wear_level() const { return wear_level; }
};

#endif
