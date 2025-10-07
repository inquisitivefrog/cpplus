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
    void doSomething() const { std::cout << "Using " << name_ << "\n"; }

private:
    std::string name_;
};

int main() {
    // unique_ptr ensures automatic cleanup, no manual delete needed
    std::unique_ptr<Resource> ptr = std::make_unique<Resource>("DatabaseConnection");
    ptr->doSomething();

    // No need to call delete; ptr is automatically cleaned up when it goes out of scope
    return 0;
}
