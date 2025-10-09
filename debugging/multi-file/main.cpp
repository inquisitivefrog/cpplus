#include <iostream>
#include <thread>  
#include <chrono>
#include <stop_token>
#include <mutex>
#include <queue>
#include <string>
#include <vector>
#include <filesystem> 
#include <fstream>
#include <functional>
#include <condition_variable>
#include "DirectoryManager.hpp"

std::queue<std::string> paths;
std::mutex mutex;
std::mutex cout_mutex;
std::mutex cv_mutex;
std::condition_variable cv;
int active_threads = 2;

void scanDirectories(DirectoryManager& manager, std::stop_token stoken) {
    std::string thread_name = "Thread-" + std::to_string(std::hash<std::thread::id>{}(std::this_thread::get_id()));
    while (!stoken.stop_requested()) {
        std::string path;
        {
            std::lock_guard<std::mutex> lock(mutex);
            if (paths.empty()) {
                std::lock_guard<std::mutex> cv_lock(cv_mutex);
                if (--active_threads == 0) {
                    cv.notify_one();
                }
                break;
            }
            path = paths.front();
            paths.pop();
        }

    std::vector<std::string> local_paths;
    {
        std::lock_guard<std::mutex> lock(mutex);
        while (!paths.empty() && local_paths.size() < 10) { // Batch 10 paths
            local_paths.push_back(paths.front());
            paths.pop();
        }
        if (paths.empty()) {
                std::lock_guard<std::mutex> cv_lock(cv_mutex);
            if (--active_threads == 0) {
                cv.notify_one();
            }
        }
    }
    for (const auto& path : local_paths) {
        bool is_verbose = (path == "/tmp/test0" || path == "/tmp/test99");
        if (is_verbose) {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << thread_name << ": Scanning path: " << path << "\n";
        }
        manager.scanDirectory(path, thread_name, is_verbose);
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Simulate work
    }
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << thread_name << ": Stopped.\n";
    }
}

int main() {
    std::filesystem::remove_all("/tmp/test"); // Clear existing test directories
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Cleared /tmp/test directories\n";
    }

    std::vector<std::string> directories;
    directories.reserve(100);

    for (int i = 0; i < 100; ++i) {
        std::string path = "/tmp/test" + std::to_string(i);
        if (!std::filesystem::create_directory(path)) {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cerr << "Failed to create directory: " << path << "\n";
        }
        if (i == 0 || i == 99) {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << "Created directory: \"" << path << "\"\n";
        }
        for (int j = 0; j < 3; ++j) {
            std::string file_path = path + "/file" + std::to_string(j) + ".txt";
            std::ofstream file(file_path, std::ios::out | std::ios::binary);
            if (file) {
                file.write("Test content", 12);
            } else {
                std::lock_guard<std::mutex> lock(cout_mutex);
                std::cerr << "Failed to create file: " << file_path << "\n";
            }
        }
        directories.emplace_back(std::move(path));
    }
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Directory creation completed. Starting threads...\n";
    }

    for (auto& p : directories) {
        paths.push(std::move(p));
    }

    DirectoryManager manager("/tmp");
    std::vector<std::jthread> workers;
    for (int i = 0; i < 2; ++i) {
        workers.emplace_back([&manager](std::stop_token stoken) {
            scanDirectories(manager, stoken);
        });
    }

    // Wait for all threads to finish processing the queue
    {
        std::unique_lock<std::mutex> lock(cv_mutex);
        cv.wait(lock, [] { return active_threads == 0; });
    }

    // Request stop for any threads still running (unlikely)
    for (auto& w : workers) {
        w.request_stop();
    }

    // Retrieve counts before locking cout_mutex
    int dir_count = manager.getDirCount();
    int file_count = manager.getFileCount();
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Main completed. Total dirs: " << dir_count
                  << ", Total files: " << file_count << "\n";
    }
    return 0;
}
