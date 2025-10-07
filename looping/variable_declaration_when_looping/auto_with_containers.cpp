#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30};

    // Old way: verbose and error-prone
    std::vector<int>::const_iterator it = vec.begin();
    while (it != vec.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\n";

    // Modern way: clean and safe with auto
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Even better: range-based for loop
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
