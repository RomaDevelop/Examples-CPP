#include <iostream>
#include <memory>
using namespace std;

struct I
{
    
    virtual ~I() = default;
    virtual void print() = 0;
    virtual void set(int n) = 0;
};

struct A: public I
{
    int n {44};
    void print() override
    {
        cout << n << "\n";
    }
    void set(int n_) override
    {
        n = n_;
    }
    
};

struct B: public I
{
    int n {44};
    void print() override
    {
        cout << n << "\n";
    }
    void set(int n_) override
    {
        n = n_;
    }
    
};

int main() {
    
    A a;
    B b;
    
    cout<< dynamic_cast<A*>(&a) << endl;
    cout<< dynamic_cast<A*>(&b) << endl;
    
    // таким путём можно разыменовывать абстрактные указатели
    
    return 0;
}