#include <iostream>
#include <vector>
using namespace std;

class T
{
public:
    T() { cout << "T()\n"; }
    ~T() { cout << "~T()\n"; }
    T(const T& src) { cout << "copy T\n"; }
    T(T&& src) { cout << "move T\n"; }
};

int main() {
   
    cout << "\nend\n\n";
    return 0;
}