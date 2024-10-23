#include <iostream>
using namespace std;

struct I
{
    virtual void print() {cout << "I\n";}
};


struct iA: public I
{
    int a=1;
    void print() {cout << "iA " << a << endl;}
    
    void pirntiA() {cout << "iA " << a << endl;}
};

struct iB: public I
{
    float b=2;
    float b1=2;
    void print() {cout << "iB " << b << " " << b1 << endl;}
    
    void pirntiB() {cout << "iB " << b << endl;}
};

int main() {
    
    iA a;
    
    I *ptrI = &a;
    
    ((iB*)ptrI)->print();  	// компилируется, отрабатывает iA::print()
    
    static_cast<iB*>(ptrI)->print();	// компилируется, отрабатывает iA::print()
    
    static_cast<iB*>(ptrI)->pirntiB();	// компилируется, выводит мусор
    
    auto ptrIB = dynamic_cast<iB*>(ptrI);	
    if(!ptrIB) cout<< "wrong cast";		// компилируется, ошибку находит
    
    return 0;
}