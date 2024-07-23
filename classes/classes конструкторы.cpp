#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iostream>

using namespace std;



class Person
{

public:

	string name;
	unsigned age;

	// конутрукторы
	// конструкторы могут быть private чтобы снаружи их нельзя было вызвать, только изнутри класса
	// если все конструкторы private, то не получится создать экземпляр класса,
	// но бывают классы в которых всё static и экземпляры не нужны
	Person() : name {"undef"}, age {0} { cout<<"Person()"<<endl; }
	Person(string name_) : name {name_}, age {0} { cout<<"Person(string name_)"<<endl; }
	Person(string name_, unsigned age_) : name {name_}, age {age_} { cout<<"Person(string name_, unsigned age_)"<<endl; }
	
	// конструктор копирования. Только ссылка или указатель в параметре
	Person(Person &person) { name = person.name; age = person.age; cout<<"Person(Person &)"<<endl; } // конструктор копирования. Только ссылка или указатель в параметре

	// деструктор
	// не должен быть private, потому что бессмыслица
	~Person() { cout << "Person "<<name<<" deleted" << endl; }

	void cout_() const { cout << "Name: " << name << "\tAge: " << age << endl; }
};


int _tmain(int argc, _TCHAR* argv[])
{
	Person tom("dfbdfb");
	tom.name = "Tom";
	tom.age = 23;
	tom.cout_();

getch();
return 0;
}
