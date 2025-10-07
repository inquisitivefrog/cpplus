#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Range-based for loop: safer, no index errors
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Compare to old-style loop prone to errors
    for (size_t i = 0; i < numbers.size(); ++i) {
        // Mistake: `if (i = 3)` would assign, not compare, causing issues
        if (i == 3) {
            std::cout << "Found index 3: " << numbers[i] << "\n";
        }
    }

    return 0;
}
