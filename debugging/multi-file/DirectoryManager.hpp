#ifndef DIRECTORY_MANAGER_HPP
#define DIRECTORY_MANAGER_HPP

#include <mutex>
#include <string_view>

class DirectoryManager {
public:
    DirectoryManager(const std::string& path);
    void scanDirectory(std::string_view path, std::string_view thread_name, bool verbose);
    int getDirCount() const;  // Add getter for dir_count_
    int getFileCount() const; // Add getter for file_count_
    DirectoryManager(const DirectoryManager&) = delete;
    DirectoryManager(DirectoryManager&&) = delete;
private:
    mutable std::mutex count_mutex_; // Marked mutable to allow locking in const methods
    std::string path_;
    char base_path_[256];
    int dir_count_;
    int file_count_;
};

extern std::mutex cout_mutex;

#endif
