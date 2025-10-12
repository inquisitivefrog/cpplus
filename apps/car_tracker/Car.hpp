// Car.hpp
#ifndef CAR_HPP
#define CAR_HPP

#include "Location.hpp"
#include "Engine.hpp"
#include "Transmission.hpp"
#include "Tire.hpp"
#include "Body.hpp"
#include "Cab.hpp"
#include <vector>

template<typename T>
class Car {
private:
    Location<T> location;
    Engine engine;
    Transmission transmission;
    std::vector<Tire> tires;
    Body body;
    Cab cab;
    double speed; // km/h
    double distance_traveled; // km

public:
    Car(Location<T> loc = Location<T>(0, 0));
    void drive(T x, T y, double speed);
    void refuel(double amount);
    void inflate_tire(size_t index, double psi);
    void print_status() const;
    void drain_fuel(); // Test-only: Drains engine fuel to 0 for testing no-fuel conditions
    void flatten_tire(size_t index); // Test-only: Sets tire[0].pressure to 0 for testing flat tire conditions
};

#endif
