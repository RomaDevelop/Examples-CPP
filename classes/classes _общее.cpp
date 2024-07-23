class Person     
{
public:
	string name;
	unsigned age;

	Person() : name {"undef"}, age {0} { cout<<"Person()"<<endl; }
	Person(string name_) : name {name_}, age {0} { cout<<"Person(1)"<<endl; }
	Person(string name_, unsigned age_) : name {name_}, age {age_} { cout<<"Person(2)"<<endl; }
	Person(Person &person) { name = person.name; age = person.age; cout<<"Person(Person)"<<endl; } 

	~Person() { cout << "Person "<<name<<" deleted" << endl; }
	// ~Person(int a) { cout << "Person "<<name<<" deleted" << endl; }   Нельзя! Деструктор всегда без параметров

	// const метод - точно не изменяет ничего в классе
	void cout_() const        
		{ cout << "Name: " << name << "\tAge: " << age << endl; }


};
