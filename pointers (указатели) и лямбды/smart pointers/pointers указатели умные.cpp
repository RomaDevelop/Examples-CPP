
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <typeinfo>

using namespace std;

”мные указатели в современном C++ с точки зрени€ новичка
https://habr.com/ru/companies/piter/articles/706866/

C++ без new и delete
https://habr.com/ru/companies/aligntechnology/articles/283352/
(местами делает херню, предлагает убирать new, чтобы его убрать)

Ѕез new: ”казатели будут удалены из C++ - 1-апрелька€ шутка
https://habr.com/ru/articles/352570/

 онцепци€ умного указател€ static_ptr<T> в C++
https://habr.com/ru/articles/665632/

int main() {

//умные указатели
    // выдел€етс€ динамическа€ пам€ть дл€ хранени€ числа 125, 
    // и указатель ptr_u указывает на эту пам€ть.
	// указывать (значение) об€зательно, иначе потом не даЄт изменить
    unique_ptr<int> ptr_u { make_unique<int>(125) };   
    
    // тоже самое, число 126
    auto ptr_u1 { make_unique<int>(126) };
    
    // в стиле —++11
    unique_ptr<int> ptr_u2 { new int(127) };    // работает
    //auto ptr_u3 { new int(128) };    // это будет обычна€ динамическа€ пам€ть!!!
    
    int *pt2=ptr_u2.get();                    
    
    cout<<"typeid pt2 и ptr_u3:             "<<typeid(pt2).name()<<" и "<<typeid(ptr_u2).name()<<endl;
    cout<<"адрес pt2 и значени по адресу    "<<pt2<<" "<<*pt2<<endl;
    cout<<"вывод адресов: "<<ptr_u<<" "<<ptr_u1<<" "<<ptr_u2<<endl;      // до C++ 20 ptr_u.get();     
    cout<<"*ptr_u(_,1,2): "<<*ptr_u<<" "<<*ptr_u1<<" "<<*ptr_u2<<endl;
    cout<<"__________________________________________________________"<<endl<<endl;
    
	
	≈сли потребуетс€ освободить пам€ть, на которую указывает указатель, то можно применить функцию reset():
	ѕосле выполнени€ функции reset() указатель получает значение nullptr
	“акже можно передать в функцию reset() новый объект, дл€ которого будет выдел€тьс€ пам€ть и на который будет указывать указатель.
	
//массив одномерный
    int n=10;
    unique_ptr<int[]> arr { make_unique<int[]>(n) }; // не нашел способ сразу проинициализировать
    //for(auto i:arr) i=5;  // к сожалению нельз€
    for(int i=0; i<n; i++) { arr[i]=i*2; cout<<arr[i]<<" "; } 
    cout<<endl<<endl;
    
//массив двумерный    
    int rc=10, cc=5;
    typedef unique_ptr<int[]> row;
    auto arr2 { make_unique<row[]>(rc) };
    for(int i=0; i<rc; i++)
        arr2[i] = make_unique<int[]>(cc);
        
    for(int i=0; i<rc; i++)
        {
        for(int j=0; j<cc; j++)  
            {
            cout<<arr2[i][j]<<" ";
            }
        cout<<endl;
        }
    cout<<endl<<endl;
    
    for(int i=0; i<rc; i++)
        {
        for(int j=0; j<cc; j++)  
            {
            arr2[i][j] = j;
            cout<<arr2[i][j]<<" ";
            }
        cout<<endl;
        }
        

    return 0;
}
