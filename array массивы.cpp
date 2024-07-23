#include <tchar.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <span>       //  C++ 20

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
int ar[]={1,5,8,3,15};

cout<<"memory "<<sizeof(ar)<<endl;
cout<<"size "<<sizeof(ar)/sizeof(ar[0])<<endl;
cout<<"adress ar = "<<ar<<endl;
cout<<"adress ar+1 = "<<ar+1<<endl;      // ������� �����

// foreach static array
cout<<"ar contains ";
for(int a:ar) cout<<a<<" ";
	cout<<endl;

//ar=ar+1;                               // �������� ������ ���������� ��������
//cout<<"ar contains ";
//for(int a:ar) cout<<a<<" ";
//cout<<endl;

cout<<endl<<"------------------------------------"<<endl;

int size=6;
int *ar_d=new int [size] {10,20,4,7,8};

cout<<"memory "<<sizeof(ar_d)<<endl;                  // �� ��������
cout<<"size "<<sizeof(ar_d)/sizeof(ar_d[0])<<endl;    // �� ��������
cout<<"adress ar_d = "<<ar_d<<endl;
cout<<"adress ar_d+1 = "<<ar_d+1<<endl;      // ������� �����

// foreach dinamic array
cout<<"ar_d contains "<<endl;
//for(int i : ar_d) std::cout<<i<<" ";              // �� �������� ������ ��� ar_d ��� ���������, � �� ���������
for(int i : span(ar_d, size)) cout<<i<<" ";          //  C++ 20
cout<<endl;

ar_d=ar_d+1;
cout<<"ar_d+1 contains "<<endl;
for(int i=0; i<size; i++) cout<<ar_d[i]<<" ";    // ar_d[last] ��������� � ������������
cout<<endl<<"------------------------------------"<<endl;


getch();
return 0;
}

