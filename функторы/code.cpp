#include <algorithm>
#include <vector>
#include <iostream>

struct GreaterThan {
    GreaterThan() {
        std::cout << "Constructor called" << std::endl;
    }
    
    ~GreaterThan() {
        std::cout << "Destructor called" << std::endl;
    }
    
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs > rhs;
    }
};

int main() {
    std::vector<int> v = {4, 8, 15, 16, 23, 42};
    
    std::cout << "Before sort:" << std::endl;
    for (auto i : v) {
        std::cout << i << ' ';
    }
    std::cout << "\n\n";
    
    std::sort(v.begin(), v.end(), GreaterThan());
    
    std::cout << "After sort:" << std::endl;
    for (auto i : v) {
        std::cout << i << ' ';
    }
    std::cout << "\n\n";
    
    return 0;
}