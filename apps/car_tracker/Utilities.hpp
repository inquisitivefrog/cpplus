// Utilities.hpp
#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include <mutex>
#include <string>
#include <fstream>

// log_mutex protects log_file and console output in log and close_log.
// Component print functions must not lock log_mutex or write to log_file.
extern std::mutex log_mutex;
// log_file is opened in init_log (build/car_tracker.log) or SetUp (build/test_car_tracker.log).
extern std::ofstream log_file; 
void log(const std::string& message);
void init_log(); // init_log truncates car_tracker.log for each run.
void close_log(); // Close log file

#endif
