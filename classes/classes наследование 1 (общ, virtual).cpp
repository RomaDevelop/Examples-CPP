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

class Person     // final будет запред наследования, а если за методом - то будет запрет таких методов в дочерних классах
{
public:

	string name;
	unsigned age;
	float rost;

	Person() : name {"undef"}, age {0} { cout<<"Person()"<<endl; }
	Person(string name_) : name {name_}, age {0} { cout<<"Person(1)"<<endl; }
	Person(string name_, unsigned age_) : name {name_}, age {age_} { cout<<"Person(2)"<<endl; }
	Person(Person &person) { name = person.name; age = person.age; cout<<"Person(Person)"<<endl; }

	virtual ~Person() { cout << "Person "<<name<<" deleted" << endl; }

// виртуальные (абстрактные) методы
	// при динамическом связывании (в указатель типа родителя создается дочерний объект) (зачем так делать - пока не известно)
	// если в дочернем объекте будет такой же метот - будет использоваться дочерний, если в родителе не сделать virtual - будет использовать родительский
	// т.е. если ClassParent *pt {&экземпляр ClassDoch}, то при вызове идентичных методов pt->... будут вызываться методы ClassDoch

	// виртуальный метод не обязательно должен быть переопределён, если не будет - будет рабоать медод родителя как обычно
	// override - если мы в дочернем классе создаём наследник virtual метода - после прототипа ставим override, не обязательно, но помогает избежать ошибок.

	// у виртуальных методов есть своя цена (больше памяти и больше время выполнения, создаётся таблица виртуальных методов)

	//  https://metanit.com/cpp/tutorial/5.11.php
	virtual void cout_() const
		{ cout << "Name: " << name << "\tAge: " << age << endl; }

	virtual void DoSometh() { cout<<"Person::DoSometh()"<<endl; }

// виртуальные конструкторы в С++ сздать нельзя, но есть способы это обойти. Нафига? Пока не знаю
	// обход:        https://habr.com/ru/articles/64369/       и      http://cpp-reference.ru/articles/virtual-constructor/
	// virtual Person() : name {"undef"}, age {0} {}     // нельзя !!!

/* виртуальные деструкторы
	если у нас динамическое связывание, а деструктор не virtual - будет вызван деструктор родителя,
		что является проблемой, деструктор родительского класса обязательно должен быть virtual
	если деструктор virtual, он будет переопределён, вызовется деструктор дочернего класса
	virtual ~Person() { cout << "Person "<<name<<" deleted" << endl; }
	*/

};

class Employee : public Person
{
public:
	string company;

	// конструктор по умолчанию наследуется и вызывается автоматом
	// можно добавить конструктор для дочернего объекта и будут делаться оба
	Employee() : company {"undef"} { cout<<"Employee()"<<endl; }

	using Person::Person;    // наследуем все конструкторы с параметрами

	// можно сложить новый конструктор с унаследованным
	//Employee(string name, unsigned age, string company_): Person(name, age)  { company=company_; }       // обычный
	Employee(std::string name, unsigned age, std::string company): Person(name, age), company{company} { cout<<"Employee(...)"<<endl; }  // список инициализации

	 // конструктор копирования. Только ссылка или указатель в параметре
	Employee(Employee& employee): Person(employee),  company {employee.company} {cout<<"Employee(Employee)"<<endl;}

	// при вызове деструктора дочернего автоматом вызывается деструктор родительского
	~Employee() { cout << "Employee "<<name<<" deleted" << endl; }

	void cout_() const override       // override отметка что этот метод переопределяет виртуальный метод родительского класса
		{ Person::cout_(); cout << "\tCompany: " << company << endl; }  // она не обязательна, но помогает избежать ошибок. Прототипы должны быть одинаковы.

	void DoSometh() override { cout<<"Employee::DoSometh()"<<endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{

	Person tom;
	tom.name = "Tom";
	tom.age = 23;
	tom.cout_();

	Employee bob("Bob");
	bob.cout_();

	Employee bobD("Bob Dilan",31);
	bobD.cout_();

	Employee Kate("Kate", 26, "Yandex");
	Kate.cout_();

	Person anyP;
	anyP.cout_();

	Employee anyE;
	anyE.cout_();

	Employee Kate2(Kate);
	Kate2.cout_();

	Employee virt {"virtN",15, "virtC"};
	Person vipt_p = virt;
	virt.cout_();
	cout<<"statich svas     ";
	vipt_p.cout_();  //  - статическое связывание

	Person *vipt_p_p=&vipt_p;
	cout<<"statich svas+pt  ";
	vipt_p_p->cout_();  //  - все равно статическое связывание

	Person &virt_p_amper {virt};    // присвоение ссылке
	cout<<"dinamich &  svas ";
	virt_p_amper.cout_();   // динамическое связывание

// для чего динамическое связывание https://metanit.com/cpp/tutorial/5.27.php
// Объекты базовых и производных классов можно хранить в одной коллекции
// обойти ограничения на доступ к функциям

	Person *virt_p_pt {&virt};    // присвоение адреса указателю
	cout<<"dinamich pt svas ";
	virt_p_pt->cout_();  // динамическое связывание

	vipt_p.DoSometh();
	virt_p_amper.DoSometh();

	Person *Kate3=new Employee(Kate2); // динамическое связывание
	Kate3->cout_();
	delete Kate3;

getch();
return 0;
}
