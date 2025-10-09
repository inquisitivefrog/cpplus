#include <boost/filesystem.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class DirectoryManager {
public:
    DirectoryManager(const std::string& base_path) : base_path_(base_path) {
        dir_count_ = 0;
        file_count_ = 0;
        last_error_ = "";
    }

    bool scanDirectory() {
        try {
            boost::filesystem::path p(base_path_);
            if (!boost::filesystem::exists(p)) {
                last_error_ = "Directory does not exist: " + base_path_;
                return false;
            }
            if (!boost::filesystem::is_directory(p)) {
                last_error_ = "Path is not a directory: " + base_path_;
                return false;
            }

            // Intentional crash: dereference a null pointer
            int* ptr = nullptr;
            *ptr = 42; // This will cause a segmentation fault

            for (const auto& entry : boost::filesystem::directory_iterator(p)) {
                if (boost::filesystem::is_directory(entry.path())) {
                    dir_count_++;
                } else if (boost::filesystem::is_regular_file(entry.path())) {
                    file_count_++;
                }
            }
            last_error_ = "Scan completed successfully";
            return true;
        } catch (const boost::filesystem::filesystem_error& e) {
            last_error_ = std::string("Error: ") + e.what();
            return false;
        }
    }

    int getDirCount() const { return dir_count_; }
    int getFileCount() const { return file_count_; }
    std::string getLastError() const { return last_error_; }

private:
    std::string base_path_;
    int dir_count_;
    int file_count_;
    std::string last_error_;
};

int main() {
    std::string path = "/tmp/test";
    int max_files = 5;
    std::vector<std::string> file_list;

    try {
        boost::filesystem::path dir_path(path);
        if (!boost::filesystem::exists(dir_path)) {
            boost::filesystem::create_directory(dir_path);
            std::cout << "Created directory: " << dir_path << "\n";
        }

        for (int i = 0; i < max_files; ++i) {
            std::string file_name = "file" + std::to_string(i) + ".txt";
            boost::filesystem::path file_path = dir_path / file_name;
            std::ofstream ofs(file_path.string());
            if (ofs) {
                ofs << "Test content " << i;
                file_list.push_back(file_path.string());
            }
        }
    } catch (const boost::filesystem::filesystem_error& e) {
        std::cerr << "Error setting up files: " << e.what() << "\n";
        return 1;
    }

    DirectoryManager dir_manager(path);
    bool scan_success = dir_manager.scanDirectory();

    std::cout << "Scan success: " << (scan_success ? "true" : "false") << "\n";
    std::cout << "Directory count: " << dir_manager.getDirCount() << "\n";
    std::cout << "File count: " << dir_manager.getFileCount() << "\n";
    std::cout << "Last error: " << dir_manager.getLastError() << "\n";
    std::cout << "Files created: ";
    for (const auto& file : file_list) {
        std::cout << file << " ";
    }
    std::cout << "\n";

    return 0;
}
