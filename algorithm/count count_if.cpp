// Hello world! Cplayground is an online sandbox that makes it easy to try out
// code.

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>

using namespace std;

void coutV(vector<int> v, string s="")
    {
    if(s!="") cout<<s;
    for(auto vi:v)
        cout<<vi<<" ";
    cout<<endl;
    }
    
bool chet(int a) { return a%2==0; }

int main() {

    vector<int> v {6,6,3,5,9,2,45,234,789,23,978,345,44};  
    coutV(v);
    
    cout<<"count(v.begin(),v.end(), 6) = "<<std::count(v.begin(),v.end(), 6)<<endl;
    

    cout<<"count_if(v.begin(),v.end(), chet) = "<<std::count_if(v.begin(),v.end(), chet)<<endl;
    
    cout<<"count_if(v.begin(),v.end(), []) = "<<std::count_if(v.begin(),v.end(), 
        [](int a){ return a%2==0; }) <<endl;   // лямбда-выражение
    
    
    
    return 0;
}