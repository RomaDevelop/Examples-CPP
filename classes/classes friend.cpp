#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iostream>

using namespace std;

class A
	{
	int a;

	friend void Set_a(A *a, int a_);
	friend class ManipulatorA;

	public:
	void print() { cout<<a<<endl; }
	
	friend ostream& operator<< (ostream& os, const A& a_)      //  по образцу с https://learn.microsoft.com/ru-ru/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
		{  os << a_.a << " vnutr "; return os;   }             // return os нужно чтобы можно было несколько раз << << << иначе только 1 раз можно
	};

class ManipulatorA
	{
	public:
	static void Set_a(A *a, int a_) { a->a=a_; }     // выдаст ошибку если не сделать friend class
	};

void Set_a(A *a, int a_) { a->a=a_; }       // выдаст ошибку если не сделать friend

int _tmain(int argc, _TCHAR* argv[])
{
A a;
Set_a(&a,50);
a.print();

ManipulatorA::Set_a(&a,1500);
a.print();

getch();
return 0;
}
