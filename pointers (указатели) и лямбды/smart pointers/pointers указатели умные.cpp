
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <typeinfo>

using namespace std;

����� ��������� � ����������� C++ � ����� ������ �������
https://habr.com/ru/companies/piter/articles/706866/

C++ ��� new � delete
https://habr.com/ru/companies/aligntechnology/articles/283352/
(������� ������ �����, ���������� ������� new, ����� ��� ������)

��� new: ��������� ����� ������� �� C++ - 1-��������� �����
https://habr.com/ru/articles/352570/

��������� ������ ��������� static_ptr<T> � C++
https://habr.com/ru/articles/665632/

int main() {

//����� ���������
    // ���������� ������������ ������ ��� �������� ����� 125, 
    // � ��������� ptr_u ��������� �� ��� ������.
	// ��������� (��������) �����������, ����� ����� �� ��� ��������
    unique_ptr<int> ptr_u { make_unique<int>(125) };   
    
    // ���� �����, ����� 126
    auto ptr_u1 { make_unique<int>(126) };
    
    // � ����� �++11
    unique_ptr<int> ptr_u2 { new int(127) };    // ��������
    //auto ptr_u3 { new int(128) };    // ��� ����� ������� ������������ ������!!!
    
    int *pt2=ptr_u2.get();                    
    
    cout<<"typeid pt2 � ptr_u3:             "<<typeid(pt2).name()<<" � "<<typeid(ptr_u2).name()<<endl;
    cout<<"����� pt2 � ������� �� ������    "<<pt2<<" "<<*pt2<<endl;
    cout<<"����� �������: "<<ptr_u<<" "<<ptr_u1<<" "<<ptr_u2<<endl;      // �� C++ 20 ptr_u.get();     
    cout<<"*ptr_u(_,1,2): "<<*ptr_u<<" "<<*ptr_u1<<" "<<*ptr_u2<<endl;
    cout<<"__________________________________________________________"<<endl<<endl;
    
	
	���� ����������� ���������� ������, �� ������� ��������� ���������, �� ����� ��������� ������� reset():
	����� ���������� ������� reset() ��������� �������� �������� nullptr
	����� ����� �������� � ������� reset() ����� ������, ��� �������� ����� ���������� ������ � �� ������� ����� ��������� ���������.
	
//������ ����������
    int n=10;
    unique_ptr<int[]> arr { make_unique<int[]>(n) }; // �� ����� ������ ����� �������������������
    //for(auto i:arr) i=5;  // � ��������� ������
    for(int i=0; i<n; i++) { arr[i]=i*2; cout<<arr[i]<<" "; } 
    cout<<endl<<endl;
    
//������ ���������    
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
