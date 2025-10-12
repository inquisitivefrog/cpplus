// Utilities.cpp
#include "Utilities.hpp"
#include <iostream>

std::mutex log_mutex;
std::ofstream log_file;

void init_log() {
    std::lock_guard<std::mutex> lock(log_mutex);
    log_file.open("car_tracker.log", std::ios::out);
    if (!log_file) {
        std::cerr << "Error: Failed to open car_tracker.log\n";
    }
}

void close_log() {
    std::lock_guard<std::mutex> lock(log_mutex);
    if (log_file.is_open()) {
        log_file.close();
    }
}

void log(const std::string& message) {
    std::lock_guard<std::mutex> lock(log_mutex);
    std::cout << message << "\n";
    if (log_file.is_open()) {
        log_file << message << "\n";
    }
}
