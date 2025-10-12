// tests/test_cab.cpp
#include <gtest/gtest.h>
#include "Cab.hpp"
#include "Utilities.hpp"

class CabTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::lock_guard<std::mutex> lock(log_mutex);
        log_file.open("test_car_tracker.log", std::ios::app);
        if (!log_file) {
            std::cerr << "Error: Failed to open test_car_tracker.log\n";
        }
    }

    void TearDown() override {
        std::lock_guard<std::mutex> lock(log_mutex);
        if (log_file.is_open()) {
            log_file.close();
        }
    }
};

TEST_F(CabTest, InvalidParametersThrows) {
    EXPECT_THROW({
        try {
            Cab cab(-1, true); // Negative passengers
        } catch (const std::exception& e) {
            std::lock_guard<std::mutex> lock(log_mutex);
            std::cerr << "Caught expected error: " << e.what() << "\n";
            throw;
        }
    }, std::invalid_argument);
}
