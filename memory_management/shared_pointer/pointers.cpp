#include <iostream>
#include <memory>
#include <string>

class Resource {
public:
    Resource(const std::string& name) : name_(name) {
        std::cout << "Resource " << name_ << " created\n";
    }
    ~Resource() {
        std::cout << "Resource " << name_ << " destroyed\n";
    }
    void doWork() const { std::cout << "Working on " << name_ << "\n"; }

private:
    std::string name_;
};

int main() {
    // Create a shared_ptr
    std::shared_ptr<Resource> ptr1 = std::make_shared<Resource>("Server");
    ptr1->doWork();

    {
        // Share ownership with ptr2
        std::shared_ptr<Resource> ptr2 = ptr1;
        ptr2->doWork();
        std::cout << "Reference count: " << ptr1.use_count() << "\n"; // Prints 2
    } // ptr2 goes out of scope, but Resource is not destroyed (ref count = 1)

    std::cout << "After inner scope, reference count: " << ptr1.use_count() << "\n"; // Prints 1
    ptr1->doWork();

    // Resource is destroyed when ptr1 goes out of scope or is reset
    return 0;
}
