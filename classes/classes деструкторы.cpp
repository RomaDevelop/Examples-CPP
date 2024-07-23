// push_back(объект) вызывает деструкторы объектов
	// 1 причина параметр - временный объект передаваемый в функцию push_back
	// 2 причина - релокация вектора, т.е. уничтожение старых и создание новых объектов в новом месте

#include <iostream>
#include <vector>
using namespace std;

class A
{
    int a;
    public:
    A(int val): a{val} {cout<< "A()\n";}
    ~A() {cout<< "~A()\n";}  
};

int main() {
    
    vector<A> vectA;
    
    //vectA.reserve(10);
    for(int i=0; i<10; i++)
        {
        vectA.push_back(i);
        // vectA.push_back(A(i));  // не помогло
        cout<<"push_back did\n";
        }
    
    cout << "end\n";
    
    return 0;
}

// абстрактный деструктор нельзя 

#include <iostream>
using namespace std;

class Ival
{
    public:
    //virtual ~Ival() = 0;   // error
    /* clang++ -o /cplayground/cplayground /cplayground/code.cpp -I/cplayground/include -L/cplayground/lib -std=c++20 -O0 -Wall -no-pie -lm -pthread
/usr/bin/ld: /cplayground/tmp/code-7420fd.o: in function `valueInt::~valueInt()':
code.cpp:(.text._ZN8valueIntD2Ev[_ZN8valueIntD2Ev]+0x37): undefined reference to `Ival::~Ival()'
/usr/bin/ld: code.cpp:(.text._ZN8valueIntD2Ev[_ZN8valueIntD2Ev]+0x50): undefined reference to `Ival::~Ival()'
clang: error: linker command failed with exit code 1 (use -v to see invocation) */
    // virtual ~Ival() = default;    // norm
    //virtual ~Ival() {};     // norm
    virtual void print() = 0;
};

class valueInt: public Ival
{
    int a{10};
    
    public:
    ~valueInt() override {cout<< "~valueInt\n";}
    void print() override  {cout<<a<<"\n";}; 
};

int main() {
    
    Ival *v = new valueInt;
    
    v->print();
    
    delete v;
    
    return 0;
}


