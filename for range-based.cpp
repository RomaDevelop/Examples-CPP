#include <stdio.h>
#include <iostream>
#include <vector>
#include <span>       //  C++ 20


using namespace std;

int main()
{

int arr[]={1,2,3,4,5};   //array initialization
cout<<"arr elements are: ";
for(int i : arr) std::cout<<i<<" ";
cout<<endl;

int size=6;
int *ar_d=new int [size] {10,20,4,7,8};
cout<<"arr_d elements are: ";
//for(int i : ar_d) std::cout<<i<<" ";              // не работает потому что ar_d это указатель, а не коллекция
for(int i : span(ar_d, size)) cout<<i<<" ";          //  C++ 20
cout<<endl;

vector<int> vec;
vec.push_back(11);
vec.push_back(22);
vec.push_back(33);
vec.push_back(44);
vec.push_back(55);

cout<<endl;

cout<<"vec elements are: ";
for(auto var : vec) { cout<<var<<" "; }

return 0;
}
