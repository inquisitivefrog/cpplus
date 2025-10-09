#include <iostream>
#include <thread>
#include <chrono>
#include <stop_token>

void worker_function(std::stop_token stoken, int id) {
    while (!stoken.stop_requested()) {
        std::cout << "Worker " << id << " is running..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "Worker " << id << " stopped." << std::endl;
}

int main() {
    // Create two jthreads
    std::jthread t1(worker_function, 1); // Pass thread ID 1
    std::jthread t2(worker_function, 2); // Pass thread ID 2

    // Simulate some work in the main thread
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Request threads to stop
    t1.request_stop();
    t2.request_stop();

    // No need to call join() explicitly; jthread's destructor handles it
    return 0;
}
