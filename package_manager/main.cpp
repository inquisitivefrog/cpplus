#include <boost/filesystem.hpp>
#include <iostream>

int main() {
    boost::filesystem::path p("/tmp/test");
    try {
        if (boost::filesystem::exists(p)) {
            std::cout << "Directory already exists: " << p << "\n";
	    for (const auto& entry : boost::filesystem::directory_iterator(p)) {
                std::cout << "Found: " << entry.path() << "\n";
            }
        } else if (boost::filesystem::create_directory(p)) {
            std::cout << "Created directory: " << p << "\n";
        } else {
            std::cout << "Failed to create directory: " << p << "\n";
        }
    } catch (const boost::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
