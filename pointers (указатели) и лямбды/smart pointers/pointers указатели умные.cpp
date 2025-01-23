
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <typeinfo>

using namespace std;

Умные указатели в современном C++ с точки зрения новичка
https://habr.com/ru/companies/piter/articles/706866/

C++ без new и delete
https://habr.com/ru/companies/aligntechnology/articles/283352/
(местами делает херню, предлагает убирать new, чтобы его убрать)

Без new: Указатели будут удалены из C++ - 1-апрелькая шутка
https://habr.com/ru/articles/352570/

Концепция умного указателя static_ptr<T> в C++
https://habr.com/ru/articles/665632/

int main() {

//умные указатели
    // выделяется динамическая память для хранения числа 125, 
    // и указатель ptr_u указывает на эту память.
	// указывать (значение) обязательно, иначе потом не даёт изменить
    unique_ptr<int> ptr_u { make_unique<int>(125) };   
    
    // тоже самое, число 126
    auto ptr_u1 { make_unique<int>(126) };
    
    // в стиле С++11
    unique_ptr<int> ptr_u2 { new int(127) };    // работает
    //auto ptr_u3 { new int(128) };    // это будет обычная динамическая память!!!
    
    int *pt2=ptr_u2.get();                    
    
    cout<<"typeid pt2 и ptr_u3:             "<<typeid(pt2).name()<<" и "<<typeid(ptr_u2).name()<<endl;
    cout<<"адрес pt2 и значени по адресу    "<<pt2<<" "<<*pt2<<endl;
    cout<<"вывод адресов: "<<ptr_u<<" "<<ptr_u1<<" "<<ptr_u2<<endl;      // до C++ 20 ptr_u.get();     
    cout<<"*ptr_u(_,1,2): "<<*ptr_u<<" "<<*ptr_u1<<" "<<*ptr_u2<<endl;
    cout<<"__________________________________________________________"<<endl<<endl;
    
	
	Если потребуется освободить память, на которую указывает указатель, то можно применить функцию reset():
	После выполнения функции reset() указатель получает значение nullptr
	Также можно передать в функцию reset() новый объект, для которого будет выделяться память и на который будет указывать указатель.

//массив одномерный
    int n=10;
    unique_ptr<int[]> arr { make_unique<int[]>(n) }; // не нашел способ сразу проинициализировать
    //for(auto i:arr) i=5;  // к сожалению нельзя
    for(int i=0; i<n; i++) { arr[i]=i*2; cout<<arr[i]<<" "; } 
    cout<<endl<<endl;
    
//массив двумерный    
    struct T
	{
		T() { static int i=0; i++; cout << "created " << i << "\n"; }
		~T() { static int i=0; i++; cout << "deleted " << i << "\n"; }
	};

	{
		int rc=10, cc=5;
		typedef unique_ptr<T[]> row;
		auto arr2 { make_unique<row[]>(rc) };
		for(int i=0; i<rc; i++)
			arr2[i] = make_unique<T[]>(cc);
		
		cout << "\n\nend\n\n";
	}
        

    return 0;
}
