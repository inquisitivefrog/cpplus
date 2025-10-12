// Location.cpp
#include "Location.hpp"
#include <cmath>
#include <iostream>

template<typename T>
Location<T>::Location(T x, T y) : x(x), y(y) {}

template<typename T>
double Location<T>::distance_to(const Location<T>& other) const {
    return std::sqrt(std::pow(static_cast<double>(x - other.x), 2) +
                     std::pow(static_cast<double>(y - other.y), 2));
}

template<typename T>
void Location<T>::print() const {
    std::cout << "Location: (" << x << ", " << y << ")\n";
}

template struct Location<double>;
template struct Location<int>;
