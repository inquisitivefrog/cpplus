// SportsCar.hpp
#ifndef SPORTS_CAR_HPP
#define SPORTS_CAR_HPP
#include "Car.hpp"
template<typename T>
class SportsCar : public Car<T> {
public:
    SportsCar(Location<T> loc = Location<T>(0, 0)) : Car<T>(loc) {}
    void boost() { log("SportsCar: Boost activated!"); }
};
#endif
