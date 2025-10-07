#include <fstream>
#include <iostream>

class FileHandler {
public:
    explicit FileHandler(const std::string& filename) : file_(filename, std::ios::out) {
        if (!file_.is_open()) {
            throw std::runtime_error("Failed to open file: " + filename);
        }
    }
    ~FileHandler() {
        if (file_.is_open()) {
            file_.close();
            std::cout << "File closed\n";
        }
    }
    void write(const std::string& data) {
        file_ << data;
    }

private:
    std::fstream file_;
};

int main() {
    try {
        FileHandler file("output.txt");
        file.write("Hello, RAII!\n");
        // File is automatically closed when `file` goes out of scope
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    return 0;
}
