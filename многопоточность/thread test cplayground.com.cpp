// Hello world! Cplayground is an online sandbox that makes it easy to try out
// code.

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

int main() {
    
    std::string s;
    int a=0;
    for(int i=0; i<5000000; i++)
        {
            a++;
            s=std::to_string(a);
        }
        
    int b=0;
    std::string s2;
    for(int i=0; i<5000000; i++)
        {
            b++;
            s2=std::to_string(b);
        }
        
    std::cout<<a<<" "<<b;
        
    return 0;
}



// первый способ занимает 2.7-2.8 секунд
// второй способ занимает 1.5-1.6 секунд

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <thread>

int main() {
    
    std::string s;
    int a=0;
std::thread t1([&]()
	{
    for(int i=0; i<5000000; i++)
        {
            a++;
            s=std::to_string(a);
        }
	});
        
    int b=0;
    std::string s2;
    
std::thread t2([&]()
	{
    for(int i=0; i<5000000; i++)
        {
            b++;
            s2=std::to_string(b);
        }
	});
	
	t1.join();
	t2.join();
        
    std::cout<<a<<" "<<b;
        
    return 0;
}