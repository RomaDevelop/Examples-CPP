#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iostream>

using namespace std;

/*
__________________________________________
|наследование | у родителя   у наследника |
|  public     | public     ->  public     |
|			  | protected  ->  protected  |
|             | private    ->  private    |
|_____________|___________________________|
|  protected  | public     ->  protected  |
|             | protected  ->  protected  |
|             | private    ->  private    |
|_____________|___________________________|
|  private    | public     ->  private    |
|             | private    ->  private    |
|			  | protected  ->  private    |
|_____________|___________________________|
*/

// безысходность
#include <iostream>
using namespace std;

class A
{
    virtual void get_a() final = 0;
};

int main() {
    
    cout << "Hello world!";
    
    return 0;
}


// Чистые виртуальные функции и абстрактные классы       https://metanit.com/cpp/tutorial/5.12.php
// Абстрактные классы - это классы, которые содержат или наследуют без переопределения хотя бы одну чистую виртуальную функцию.
class Shape{
public:
	// Чистые виртуальные функции - pure virtual functions - завершаеюся значением "=0"
	// Цель подобных функций - просто определить функционал без реализации
	virtual double getSquare() const = 0;     // площадь фигуры
	virtual double getPerimeter() const = 0;  // периметр фигуры

	// абстрактный класс может определять и обычные функции и переменные, может иметь несколько конструкторов,
	// но при этом все равно нельзя создавать объекты этого абстрактного класса
	int x;
	int y;
	void GetXY() {cout<<"x: "<<x<<" y: "<<y<<endl;}
	Shape() {x=0; y=0;}
	Shape(int x_, int y_) {x=x_; y=y_;}
};
// нельзя создать экземпляр абстрактного класса! Shape shape; выдаст ошибку компиляции.

class Pramoug: public Shape{
	public:
	double dlina;
	double shirina;

	Pramoug(double d, double sh): dlina{d}, shirina{sh} {}
	Pramoug(int x, int y, double d, double sh): Shape{x,y}, dlina{d}, shirina{sh} {}

	double getSquare() const override { return dlina*shirina; };
	double getPerimeter() const override { return (dlina+shirina) * 2; };
};


int _tmain(int argc, _TCHAR* argv[])
{
	Pramoug p(10,10,15,20);
	p.x=100;
	cout<<"getSquare: "<<p.getSquare()<<" getPerimeter: "<<p.getPerimeter()<<endl;
	p.GetXY();

	getch();
	return 0;
}
