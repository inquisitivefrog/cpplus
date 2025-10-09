#include <cstring>
#include <filesystem>
#include <iostream>
#include <mutex>
#include <sstream>
#include "DirectoryManager.hpp"

DirectoryManager::DirectoryManager(const std::string& base_path) {
    if (base_path.empty() || base_path.size() > sizeof(base_path_) - 1) {
        throw std::invalid_argument("Invalid path: " + base_path);
    }
    strncpy(base_path_, base_path.c_str(), sizeof(base_path_) - 1);
    base_path_[sizeof(base_path_) - 1] = '\0';
    dir_count_ = 0;
    file_count_ = 0;
}

void DirectoryManager::scanDirectory(std::string_view path, std::string_view thread_name, bool verbose) {
    try {
        std::filesystem::path p(path);
        if (verbose) {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << thread_name << ": Scanning path: " << path << "\n";
        }
        if (!std::filesystem::exists(p)) {
            if (verbose) {
                std::lock_guard<std::mutex> lock(cout_mutex);
                std::cerr << thread_name << ": Directory does not exist: " << path << "\n";
            }
            return;
        }
        if (!std::filesystem::is_directory(p)) {
            if (verbose) {
                std::lock_guard<std::mutex> lock(cout_mutex);
                std::cerr << thread_name << ": Path is not a directory: " << path << "\n";
            }
            return;
        }
        int local_dir_count = 0, local_file_count = 0;
        for (auto it = std::filesystem::directory_iterator(p); it != std::filesystem::directory_iterator(); ++it) {
            auto status = it->status();
            if (status.type() == std::filesystem::file_type::directory) {
                local_dir_count++;
            } else if (status.type() == std::filesystem::file_type::regular) {
                local_file_count++;
                if (verbose) {
                    std::lock_guard<std::mutex> lock(cout_mutex);
                    std::cout << thread_name << ": Found file: " << it->path() << "\n";
                }
            }
        }
        {
            std::lock_guard<std::mutex> lock(count_mutex_);
            dir_count_ += local_dir_count;
            file_count_ += local_file_count;
            if (verbose) {
                std::lock_guard<std::mutex> cout_lock(cout_mutex);
                std::cout << thread_name << ": Scanned " << path << ", dirs: " << local_dir_count
                          << ", files: " << local_file_count << ", total dirs: " << dir_count_
                          << ", total files: " << file_count_ << "\n";
            }
        }
    } catch (const std::filesystem::filesystem_error& e) {
        if (verbose) {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cerr << thread_name << ": Filesystem error: " << e.what() << "\n";
        }
    } catch (const std::exception& e) {
        if (verbose) {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cerr << thread_name << ": Exception: " << e.what() << "\n";
        }
    }
}

int DirectoryManager::getDirCount() const {
    std::lock_guard<std::mutex> lock(count_mutex_);
    return dir_count_;
}

int DirectoryManager::getFileCount() const {
    std::lock_guard<std::mutex> lock(count_mutex_);
    return file_count_;
}
