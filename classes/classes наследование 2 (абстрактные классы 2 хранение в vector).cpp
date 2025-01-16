#include <QCoreApplication>

#include <iostream>
using namespace std;

class abstract{
public:
	virtual void print() = 0;
};

class C1: public abstract {
public:
	int c1;
	C1(): c1{1} {}

	void print() override
	{cout << "c1 = " << c1 << endl;}
};

class C2: public abstract {
public:
	int c1;
	int c2;
	C2(): c1{1}, c2{2} {}

	void print() override
	{cout << "c1 = " << c1 << "; c2 =" << c2 << endl;}
};

class C3: public abstract {
public:
	int c1;
	int c2;
	int c3;
	C3(): c1{1}, c2{2}, c3{3} {}

	void print() override
	{cout << "c1 = " << c1 << "; c2 =" << c2 << "; c3 =" << c3 << endl;}
};

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	cout << "Hello world\n\n";

	C1 c1;
	C2 c2;
	C3 c3;

// нельзя!!! не должен быть вектор экземпляров абстракции. И невозможно в принципе,
// каждый экземпляр может быть разного размера
//	vector<abstract> classes1;
//	classes1.push_back(c1);
//	classes1.push_back(c2);
//	classes1.push_back(c3);
//	for(auto c:classes1)
//		c->print();

	// можно и нужно так! верктор указателей
	vector<abstract*> classes;
	classes.push_back(&c1);
	classes.push_back(&c2);
	classes.push_back(&c3);
	for(auto c:classes)
		c->print();

	// верктор ссылок тоже ругается
	//vector<abstract&> classes3;
	//classes3.push_back(c1);
	//classes3.push_back(c2);
	//classes3.push_back(c3);
	//for(auto c:classes3)
	//	c->print();

	return a.exec();
}
