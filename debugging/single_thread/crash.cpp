#include <iostream>

int main() {
    int* ptr = nullptr; // Initialize a null pointer
    std::cout << "About to dereference a null pointer..." << std::endl;
    *ptr = 42; // This will cause a segmentation fault
    std::cout << "This line won't be reached." << std::endl;
    return 0;
}
