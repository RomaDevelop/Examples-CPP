#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// компаратор для сортировки по длине слова
bool compareL(const std::string& left, const std::string& right)
	{ return left.length() < right.length(); }

class A{
	public:
	int a;
	A():a{0} {}
	A(int a_):a{a_}{}

	// чтобы можно было сортировать коллекцию класса А нужно перегрузить оператор или использовать компаратор
	bool operator< (A a_) { if(a < a_.a) return true; else return false; }

	// сортировать можно по любому показателю и разным полям класса, например можно отсортировать по остатку от деления на 128
    // для этого нужно создать соответсвующий компаратор
	static bool Compare128(A left, A right)  { if(left.a%128 < right.a%128) return true; else return false; }

};


int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> people {"Tom", "Bob", "Sam", "Alice", "Kate"};
	cout<<"1 Not sorted: "; for(auto vi:people) cout<<vi<<" "; cout<<endl;

	// Быстрая сортировка. Сложность в среднем O( n*log(n) ), но в худшем случае O( n*n )
	sort(begin(people), end(people));
	cout<<"1 ___ Sorted: "; for(auto vi:people) cout<<vi<<" "; cout<<endl;

	people={"Tom", "Bob", "Sam", "Alice", "Kate"};
	cout<<"2 Not sorted: "; for(auto vi:people) cout<<vi<<" "; cout<<endl;

	// в sort передаётся функция компаратор, сортирует по длине
	// А можно передать еще и возвращатель, см посл часть https://metanit.com/cpp/tutorial/16.5.php
	sort(begin(people), end(people), compareL);
	cout<<"2 ___ Sorted: "; for(auto vi:people) cout<<vi<<" "; cout<<endl;

    //people={"Tom", "Bob", "Sam", "Alice", "Kate"};
	//coutV(people,"3 Not sorted: ");
    //// ranges::sort (c++ 20)
    //std::ranges::sort(people);
    //coutV(people,"3 ranges::sort: ");

	vector <A> a={54,654,515,45451,4,884842,5454};
	cout<<"3 Not sorted: "; for(auto vi:a) cout<<vi.a<<" "; cout<<endl;
	sort(begin(a), end(a));
	cout<<"3 ___ sorted: "; for(auto vi:a) cout<<vi.a<<" "; cout<<endl;

	cout<<"left divide 128"<<endl;
	cout<<"4 Not sorted: "; for(auto vi:a) cout<<vi.a%128<<" "; cout<<endl;
	sort(begin(a), end(a), A::Compare128);
	cout<<"4 ___ sorted: "; for(auto vi:a) cout<<vi.a%128<<" "; cout<<endl;
	cout<<"4 ___ sami a: "; for(auto vi:a) cout<<vi.a<<" "; cout<<endl;

	/*
    Ещё
	https://purecodecpp.com/archives/3450

    в sort можно передать функтор сравнения

	Сортировка подпоследователности. Гарантированная сложность O( n*log(n) ) в любом случае.
	Обычно сортировка в куче выполняется в 2-5 раз медленнее быстрой сортировки sort().
    partial_sort( v.begin(), v.end(), v.end() );

    Сортировка слиянием. Сложность O( n*log(n) ) или O( n*log(n)*log(n) ),
	если без дополнительной памяти
    stable_sort( v.begin(), v.end() );

	// Сортировка в куче (heap) - вызывают функции, непосредственно работающие с кучей
    // (то есть с бинарным деревом, используемым в реализации этих алгоритмов).
    // Сложность O( n+n*log(n) )
    make_heap( v.begin(), v.end() );
    sort_heap( v.begin(), v.end() );
	*/

	getch();
	return 0;
}

