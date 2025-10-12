// tests/test_transmission.cpp
#include <gtest/gtest.h>
#include "Transmission.hpp"
#include "Utilities.hpp"

class TransmissionTest : public ::testing::Test {
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

TEST_F(TransmissionTest, InvalidGearThrows) {
    EXPECT_THROW({
        try {
            Transmission trans(true);
            trans.shift_gear(7);
        } catch (const std::exception& e) {
            std::lock_guard<std::mutex> lock(log_mutex);
            std::cerr << "Caught expected error: " << e.what() << "\n";
            throw;
        }
    }, std::invalid_argument);
}
