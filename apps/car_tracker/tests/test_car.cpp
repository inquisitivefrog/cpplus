// tests/test_car.cpp
#include <gtest/gtest.h>
#include "Car.hpp"
#include "Utilities.hpp"

// Test fixture for Car tests
class CarTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::lock_guard<std::mutex> lock(log_mutex);
        log_file.open("test_car_tracker.log", std::ios::app);
        if (!log_file) {
            std::cerr << "Error: Failed to open test_car_tracker.log\n";
        }
        car = std::make_unique<Car<double>>(Location<double>(0.0, 0.0));
    }

    void TearDown() override {
        std::lock_guard<std::mutex> lock(log_mutex);
        if (log_file.is_open()) {
            log_file.close();
        }
    }

    std::unique_ptr<Car<double>> car;
};

TEST_F(CarTest, NegativeRefuelThrows) {
    EXPECT_THROW({
        try {
            car->refuel(-5.0);
        } catch (const std::exception& e) {
            std::lock_guard<std::mutex> lock(log_mutex);
            std::cerr << "Caught expected error: " << e.what() << "\n";
            throw;
        }
    }, std::invalid_argument);
}

TEST_F(CarTest, InvalidTireIndexThrows) {
    EXPECT_THROW({
        try {
            car->inflate_tire(4, 5.0);
        } catch (const std::exception& e) {
            std::lock_guard<std::mutex> lock(log_mutex);
            std::cerr << "Caught expected error: " << e.what() << "\n";
            throw;
        }
    }, std::out_of_range);
}

TEST_F(CarTest, NoFuelThrows) {
    EXPECT_THROW({
        try {
            car->drain_fuel();
            car->drive(10.0, 20.0, 60.0);
        } catch (const std::exception& e) {
            std::lock_guard<std::mutex> lock(log_mutex);
            std::cerr << "Caught expected error: " << e.what() << "\n";
            throw;
        }
    }, std::runtime_error);
}

TEST_F(CarTest, FlatTireThrows) {
    EXPECT_THROW({
        try {
            car->flatten_tire(0);
            car->drive(10.0, 20.0, 60.0);
        } catch (const std::exception& e) {
            std::lock_guard<std::mutex> lock(log_mutex);
            std::cerr << "Caught expected error: " << e.what() << "\n";
            throw;
        }
    }, std::runtime_error);
}
