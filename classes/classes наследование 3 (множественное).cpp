#include <conio.h>
#include <string>
#include <iostream>

using namespace std;

/*
__________________________________________
|наследование | у родителя   у наследника |
|  public     | public     ->  public     |
|             | protected  ->  protected  |
|             | private    ->  private    |
|_____________|___________________________|
|  protected  | public     ->  protected  |
|             | protected  ->  protected  |
|             | private    ->  private    |
|_____________|___________________________|
|  private    | public     ->  private    |
|             | private    ->  private    |
|             | protected  ->  private    |
|_____________|___________________________|
*/


// Множественное наследование

// наследование 2 (А и В) -> 1 (С)
class A{
public:
	string dataA;
	A(){dataA="dataA"; cout<<"dataA created"<<endl;}
	~A(){cout<<"dataA destoyed"<<endl;}
	void print() { cout<<dataA<<endl; }
};

class B{
public:
	string dataB;
	B(){dataB="dataB"; cout<<"dataB created"<<endl;}
	~B(){cout<<"dataB destoyed"<<endl;}
	void print() { cout<<dataB<<endl; }
};

class C: public A, public B{
public:
	string dataC;

	// конструкторы - первым вызывается конструктор класса, который указан первым среди базовых классов
	// десрукторы - вызываются в обратном порядке, первым вызывается десруктор класса, который указан последним среди базовых классов
	C(){dataC="dataC"; cout<<"dataC created"<<endl;}
	~C(){cout<<"dataC destoyed"<<endl;}

	// методы могут быть перегружены. Чтобы вызвать конкретный нужно указывать конкретный ClassEkzemplar.ClassName::Metod()
	// по умолчанию вызывается собственный метод, если он есть
	// если собственный не определён - выдается ошибка при компиляции
	// нужно вызывать конкретный, использовать ClassEkzemplar.ClassName::Metod()
	void print() { cout<<dataC<<endl; }

};


// наследование 1(А) -> 2(B1 и B2) -> 1 (С1)
// проблема!!! конструкторы и деструкторы А вызовутся 2 раза!!!
// решение - классы должны наследоваться как virtual!!!

// class B1: public A{  // неправильно, конструкторы и деструкторы А вызовутся 2 раза!!!
class B1: public virtual A{    // правильно
public:
	string dataB1;
	B1(){dataB1="dataB1"; cout<<"dataB1 created"<<endl;}
	~B1(){cout<<"dataB1 destoyed"<<endl;}
	void print() { cout<<dataB1<<endl; }
};

//class B2: public A{  // неправильно, конструкторы и деструкторы А вызовутся 2 раза!!!
class B2: public virtual A{   // правильно
public:
	string dataB2;
	B2(){dataB2="dataB2"; cout<<"dataB2 created"<<endl;}
	~B2(){cout<<"dataB2 destoyed"<<endl;}
	void print() { cout<<dataB2<<endl; }
};

class C1: public B1, public B2{
public:
	string dataC1;
	C1(){dataC1="dataC1"; cout<<"dataC1 created"<<endl;}
	~C1(){cout<<"dataC1 destoyed"<<endl;}
};

int _tmain(int argc, _TCHAR* argv[]){
	cout<<"inheritance 1 -> 2\n";
	C c;
	c.print();
	c.A::print();
	c.B::print();
	c.C::print();

	cout<<"\ninheritance 1 -> 2 - 1\n";
		{
		C1 c1;
		}
	//c1.print();

	getch();
	return 0;
}
