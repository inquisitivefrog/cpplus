// Body.hpp
#ifndef BODY_HPP
#define BODY_HPP

#include "Utilities.hpp"
#include <string>

class Body {
private:
    std::string color;
    double weight; // kg
    double integrity; // 0 (damaged) to 100 (perfect)

public:
    Body(std::string color = "Red", double weight = 1500.0, double integrity = 100.0);
    void damage(double amount);
    void print_status() const;
};

#endif
