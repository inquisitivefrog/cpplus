#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Range-based: safe, no index errors
    for (const int& num : numbers) {
        // if (num = 3) // Error: cannot assign to const
        if (num == 3) {
            std::cout << "Found 3\n";
        }
    }

    // Index-based: prone to errors
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i = 3) { // Bug: assignment, not comparison
            std::cout << "Mistake: i set to 3\n";
            break; // Prevents infinite loop, but logic is wrong
        }
    }

    return 0;
}
