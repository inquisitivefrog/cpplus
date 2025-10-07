#include <iostream>
#include <memory>
#include <string>

class Node {
public:
    std::string name_;
    std::shared_ptr<Node> partner; // Strong reference
    std::weak_ptr<Node> observer;  // Weak reference to avoid cycles

    Node(const std::string& name) : name_(name) {
        std::cout << "Node " << name_ << " created\n";
    }
    ~Node() {
        std::cout << "Node " << name_ << " destroyed\n";
    }
};

int main() {
    // Create two nodes
    auto node1 = std::make_shared<Node>("A");
    auto node2 = std::make_shared<Node>("B");

    // Create a circular reference with shared_ptr
    node1->partner = node2;
    node2->partner = node1; // This creates a cycle, but we'll break it with weak_ptr

    // Use weak_ptr for observer
    node1->observer = node2;
    node2->observer = node1;

    // Check if weak_ptr is valid
    if (auto temp = node1->observer.lock()) { // Convert weak_ptr to shared_ptr
        std::cout << "Node A observes: " << temp->name_ << "\n";
    } else {
        std::cout << "Node A's observer is expired\n";
    }

    // Reset one shared_ptr to break the cycle
    node2.reset();
    std::cout << "After resetting node2\n";

    if (auto temp = node1->observer.lock()) {
        std::cout << "Node A observes: " << temp->name_ << "\n";
    } else {
        std::cout << "Node A's observer is expired\n";
    }

    return 0;
}
