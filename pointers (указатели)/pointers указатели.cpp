#include <tchar.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

float kvadrat(float x) { return x*x; }
int Plus5(int a) {return a+5;}
int Plus10(int a) {return a+10;}
int Plus20(int a) {return a+20;}

void *GetMemory1(int size)
	{
	//void *ptv=new [1000];   		// ������
	char *mem=new char [size];
	void *ptv=mem;               	// �����
	return ptv;
	}

// ������� � ���������� *
void plus5_1(int *a) { *a=*a+5; }
// ������� � ���������� &
void plus5_2(int &a) { a=a+5; }

// ��������� �� �������, ������� �������, ������� ��� �������� �������� � �������
int (*arr_func[3]) (int) = {Plus5,Plus10,Plus20};     // ���������� ������� �� ��� �������, ����� ������� �� ������� ������� � main

void do_func(int *a, void(*func)(int*)) { func(a); }      // ������� ��������� �������� ��������� �� ������� (����� �������� void �������� - ��������� �� int)

// ���������� ��������� ������� ��������
// ��������������� ������� ���������� ����������
float integral(float x1, float x2, float shag, float(*podintegral_func)(float))					// https://www.youtube.com/watch?v=WC3Lxf3IUSc&ab_channel=StudyProf
{																								// https://math.semestr.ru/optim/trapezoid-formula.php
float s=0;
for(float x=x1; x<x2; x+=shag)
	{
	s = s + shag * 0.5 * ((podintegral_func(x)) + (podintegral_func(x + shag)));
	}
return s;
}

// ������ ����������� ������� ��������
//std::function<int(int)> lfib = [&lfib](int n) {return n < 2 ? 1 : lfib(n-1) + lfib(n-2);};

int _tmain(int argc, _TCHAR* argv[])
{
cout<<"-----���������, ������, ����������, ��������� ���������"<<endl;
int a=20;
int b=30;
cout<<"a "<<a<<endl;
//cout<<"*a "<<*a<<endl;     // ������, ����
cout<<"&a "<<&a<<endl;

int *pt=new int;
int *pt2=new int;
*pt=50;
cout<<"pt "<<pt<<endl;
cout<<"*pt "<<*pt<<endl;
cout<<"&pt "<<&pt<<endl;

int *&pRef {pt};
cout<<"*pt "<<*pt<<endl;
pRef=&a;
cout<<"*pt "<<*pt<<endl;
*pRef=70;
cout<<"*pt "<<*pt<<endl;

cout<<"pt == pRef"<<" "<<(pt == pRef)<<endl;
pt=&b;
cout<<"pt == pRef"<<" "<<(pt == pRef)<<endl;
pRef=&a;
cout<<"pt == pRef"<<" "<<(pt == pRef)<<endl;
pRef=pt2;
cout<<"pt == pRef"<<" "<<(pt == pt2)<<endl;
cout<<"---------------------------------------------"<<endl;
cout<<"-------------------------��������� ��� ������"<<endl;
int *arr5=new int [10] {3,3,76,9,3,1};
for(int i=0; i<10; i++) cout<<arr5[i]<<" ";
cout<<endl;
delete [] arr5;
for(int i=0; i<10; i++) cout<<arr5[i]<<" ";
cout<<endl;

cout<<"---------------------------------------------------"<<endl;
cout<<"----��������� void ������ ��������, ����� ���������"<<endl;
cout<<"-----------------------��������� ��� � �����������"<<endl;
cout<<"----------------------------------����� ���������??"<<endl;

int *arr=(int*)GetMemory1(12);
int *ptarr=arr;
for(int i=0; i<3; i++) arr[i]=rand();

for(int i=0; i<3; i++) cout<<arr[i]<<" ";
cout<<endl;

cout<<"arr%10 = "<<(int)arr%10<<endl;

arr+=1;
cout<<"arr+=1; arr%10 = "<<(int)arr%10<<endl;
for(int i=0; i<3; i++) cout<<arr[i]<<" ";
cout<<endl;

arr+=1;
cout<<"arr+=1; arr%10 = "<<(int)arr%10<<endl;
for(int i=0; i<3; i++) cout<<arr[i]<<" ";
cout<<endl;

arr+=1;
cout<<"arr+=1; arr%10 = "<<(int)arr%10<<endl;
for(int i=0; i<3; i++) cout<<arr[i]<<" ";
cout<<endl;

cout<<"data at ptarr ";
for(int i=0; i<3; i++) cout<<ptarr[i]<<" ";
cout<<endl;

delete [] ptarr;
cout<<"data at ptarr after delete [] ptarr ";
for(int i=0; i<3; i++) cout<<ptarr[i]<<" ";
cout<<endl;

int aaa=7;
cout<<aaa<<"\t";
plus5_1(&aaa);
cout<<aaa<<"\t";
plus5_2(aaa);
cout<<aaa<<"\t";
do_func(&aaa,plus5_1);
cout<<aaa<<"\t";
// do_func(&aaa,plus5_2);  // ������ �� ������������ ���� ������������ �������
cout<<aaa<<"\t";
cout<<endl;


cout<<integral(0,10,1,kvadrat)<<endl;                		// �������� ��������� �� ������� ������������ ����
cout<<integral(0,10,1, [](float x){return x*x;} )<<endl;    // �������� ������� ������-����������
cout<<endl;

int a1=0;
cout<<a1<<"\t";
for(int i=0; i<3; i++) a1=arr_func[i](a1);   // ����� ������� �� ������� �������
cout<<a1<<"\t";

getch();
return 0;
}

