#include <tchar.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <bitset>

using namespace std;

/* https://metanit.com/cpp/tutorial/2.8.php

практическое применение:
в одну переменную можно запихать несколько значений, если они побитово не пересекутся и не вылезут за предел
еще? хз
*/

int _tmain(int argc, _TCHAR* argv[])
{
int arr[]={1,2,3,8,10,16,100,200,1000,1001,1002};
int size=end(arr)-begin(arr);

const int bitlen=12;
//const int bitlen=sizeof(arr[0])*8;

for(int a:arr) cout<<bitset<bitlen>(a)<<" == "<<a<<endl;
cout<<endl;

cout<<"sdvig vlevo (v verxn razrad)"<<endl<<endl;

for(int a:arr)
	{
	int val=1;
	int a_=a << val;
	cout<<bitset<bitlen>(a)<<" << "<<val<<" "<<bitset<bitlen>(a_)<<" == "<<a<<" -> "<<a_<<endl;
	}
cout<<endl;

for(int a:arr)
	{
	int val=2;
	int a_=a << val;
	cout<<bitset<bitlen>(a)<<" << "<<val<<" "<<bitset<bitlen>(a_)<<" == "<<a<<" -> "<<a_<<endl;
	}
cout<<endl;

for(int a:arr)
	{
	int val=3;
	int a_=a << val;
	cout<<bitset<bitlen>(a)<<" << "<<val<<" "<<bitset<bitlen>(a_)<<" == "<<a<<" -> "<<a_<<endl;
	}
cout<<endl;

for(int a:arr)
	{
	int val=3;
	int a_=a << val;
	int a_p=a*pow(2,val);
	cout<<a<<" << "<<val<<" == "<<a_<<" "<<a<<"*pow(2,"<<val<<") == "<<a_p<<endl;
	}
cout<<endl;


cout<<"sdvig vpravo (v nign razrad)"<<endl<<endl;
for(int a:arr)
	{
	int val=1;
	int a_=a >> val;
	cout<<bitset<bitlen>(a)<<" >> "<<val<<" "<<bitset<bitlen>(a_)<<" == "<<a<<" -> "<<a_<<endl;
	}
cout<<endl;

for(int a:arr)
	{
	int val=2;
	int a_=a >> val;
	cout<<bitset<bitlen>(a)<<" >> "<<val<<" "<<bitset<bitlen>(a_)<<" == "<<a<<" -> "<<a_<<endl;
	}
cout<<endl;

for(int a:arr)
	{
	int val=3;
	int a_=a >> val;
	cout<<bitset<bitlen>(a)<<" >> "<<val<<" "<<bitset<bitlen>(a_)<<" == "<<a<<" -> "<<a_<<endl;
	}
cout<<endl;

cout<<"& kon'unktsia (porazrad i)"<<endl<<endl;
for(int a:arr)
	if(a>20)
	cout<<bitset<bitlen>(a)<<" & "<<endl<<bitset<bitlen>(a/2)<<" == "<<endl<<bitset<bitlen>(a & a/2)<<endl<<endl;
cout<<endl;

cout<<"| diz'unktsia (porazrad ili)"<<endl<<endl;
for(int a:arr)
	if(a>20)
	cout<<bitset<bitlen>(a)<<" | "<<endl<<bitset<bitlen>(a/2)<<" == "<<endl<<bitset<bitlen>(a | a/2)<<endl<<endl;
cout<<endl;

cout<<"^ (porazrad iskluchauschee ili)"<<endl<<endl;
for(int a:arr)
	if(a>20)
	cout<<bitset<bitlen>(a)<<" ^ "<<endl<<bitset<bitlen>(a/2)<<" == "<<endl<<bitset<bitlen>(a ^ a/2)<<endl<<endl;
cout<<endl;

cout<<"~ (porazrad inversiya)"<<endl<<endl;
for(int a:arr)
	if(a>20)
	cout<<bitset<bitlen>(a)<<" ~ "<<" == "<<endl<<bitset<bitlen>(~a)<<endl<<endl;
cout<<endl;

getch();
return 0;
}
