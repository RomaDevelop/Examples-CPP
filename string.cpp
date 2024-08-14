#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int _tmain(int argc, _TCHAR* argv[]) {
    string str="some text";                
    cout<<str<<endl;
    
    string str2("other text");
    cout<<str2<<endl;
    
    string str3{"another text"};
    cout<<str3<<endl;
    
    str=str3;
    cout<<str<<endl;
    
    str[0]='A';                             
    cout<<str<<endl;
    
	// преобразование строки в число
	int a=atoi("5"); // #include <stdlib.h>
	float f=atof("5.45");
	int b=std::stoi("10");
	float f=std::stof("10");   
	
	stoi(): преобразует в тип int

	stol(): в long

	stoll(): в long long

	stoul(): в unsigned long

	stoull(): в unsigned long long

	stof(): в float

	stod(): в double

	stold(): в long double
	
	// преобразование числа в строку
	std::string s = std::to_string(a);  // шо инт, шо флоат
	??? s1 = sttod::_wstring(a);
	
	itoa(123,char*,система счисления[можно любую, хоть троичную]);
    
    str="aabbbaaabaabbbaa";
    int count_b=0;
    for(auto c:str)                         // foreach
        {
        if(c=='b') count_b++;
        }
    cout<<"count_b = "<<count_b<<endl;
    
    return 0;
}