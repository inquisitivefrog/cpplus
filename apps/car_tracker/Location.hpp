// Location.hpp
#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "Utilities.hpp"

// Template structure for Location (demonstrates templates)
template<typename T>
struct Location {
    T x, y; // Coordinates (e.g., x=latitude, y=longitude)

    Location(T x = 0, T y = 0);
    double distance_to(const Location<T>& other) const;
    void print() const;
};

#endif
