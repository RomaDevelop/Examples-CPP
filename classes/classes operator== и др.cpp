#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class A{
public:
	int a;
	A(int a_):a{a_} {}

	A operator+ (A a_) { return A(a+a_.a); }
	A operator+ (int a_) { return A(a+a_); }

	bool operator== (A a_) { if(a==a_.a) return true; else return false; }
	bool operator< (A a_) { if(a < a_.a) return true; else return false; }
	bool operator> (A a_) { if(a > a_.a) return true; else return false; }

	void operator<< (int a_) { a=a_; }

	friend ostream& operator<< (ostream& os, const A& a_)      //  по образцу с https://learn.microsoft.com/ru-ru/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
		{  os << a_.a << " vnutr "; return os;   }             // return os нужно чтобы можно было несколько раз << << << иначе только 1 раз можно
};

ostream& operator << (ostream &os, A &a)     // можно также и внешнюю  https://metanit.com/cpp/tutorial/8.4.php
	{ os << a.a << " vnesh "; return os; }

int _tmain(int argc, _TCHAR* argv[])
{
	A a1(15);
	A a2(25);
	cout<<a1<<endl;
	cout<<a1.a<<" + A = ";
	a1=a1+a2;
	cout<<a1.a<<endl;

	cout<<a1.a<<" + 10 = ";
	a1=a1+10;
	cout<<a1.a<<endl;

	cout<<a1<<" "<<a2;
	if(a1==a2) cout<<" true "; else cout<<" false ";
	if(a1<a2) cout<<" true "; else cout<<" false ";
	if(a1>a2) cout<<" true "; else cout<<" false ";
	cout<<endl;

	a1<<5;
	cout<<a1<<endl;

	getch();
	return 0;
}

