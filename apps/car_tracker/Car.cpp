// Car.cpp
#include "Car.hpp"
#include <stdexcept>
#include <iostream>

template<typename T>
Car<T>::Car(Location<T> loc)
    : location(loc), engine(), transmission(true), tires(4, Tire(32.0, 0.0)),
      body(), cab(), speed(0.0), distance_traveled(0.0) {}

template<typename T>
void Car<T>::drive(T x, T y, double speed) {
    if (speed < 0) throw std::invalid_argument("Negative speed");
    if (engine.get_fuel_level() == 0.0) throw std::runtime_error("No fuel");
    for (const auto& tire : tires) {
        if (tire.is_flat()) throw std::runtime_error("Flat tire");
    }

    Location<T> new_loc(x, y);
    double distance = location.distance_to(new_loc);
    engine.consume_fuel(distance / 20.0); // 20 km/gallon efficiency
    for (auto& tire : tires) tire.wear(distance / 100.0); // Wear per 100 km
    transmission.auto_shift(speed);
    distance_traveled += distance;
    location = new_loc;
    this->speed = speed;

    log("Car drove to (" + std::to_string(x) + ", " + std::to_string(y) +
        ") at speed " + std::to_string(speed) + " km/h, distance traveled: " +
        std::to_string(distance_traveled) + " km");
}

template<typename T>
void Car<T>::refuel(double amount) {
    engine.refuel(amount);
}

template<typename T>
void Car<T>::inflate_tire(size_t index, double psi) {
    if (index >= tires.size()) throw std::out_of_range("Invalid tire index");
    tires[index].inflate(psi);
}

template<typename T>
void Car<T>::print_status() const {
    std::lock_guard<std::mutex> lock(log_mutex);
    std::cout << "=== Car Status ===\n";
    location.print();
    std::cout << "Speed: " << speed << " km/h, Distance Traveled: "
              << distance_traveled << " km\n";
    engine.print_status();
    transmission.print_status();
    for (size_t i = 0; i < tires.size(); ++i) {
        std::cout << "Tire " << i << ": Pressure=" << tires[i].get_pressure()
                  << " PSI, Wear=" << tires[i].get_wear_level() << "%\n";
    }
    body.print_status();
    cab.print_status();
    std::cout << "=================\n";
}

template<typename T>
void Car<T>::drain_fuel() {
    engine.drain_fuel();
}

template<typename T>
void Car<T>::flatten_tire(size_t index) {
    if (index >= tires.size()) throw std::out_of_range("Invalid tire index");
    tires[index].set_pressure(0.0);
    log("Tire " + std::to_string(index) + ": Flattened for testing");
}

// Explicit template instantiations
template class Car<double>;
template class Car<int>;
