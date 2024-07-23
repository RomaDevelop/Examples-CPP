define с параметрами и зачем do ... while(0) в дефйане
https://www.cyberforum.ru/cpp-beginners/thread1962101.html#post17275464

define ZERO_ARRAY(a_, n_) do for (size_t i = 0, n = (n_); i < n; ++i) (a_)[i] = 0; while (0)


дефайны чувствительны к регистру!
#include <iostream>
using namespace std;
 
#define a5 a=5
#define A5 a=6
 
int main() {
    int A5;
    cout << a << "\n";
    a5; 
    cout << a << "\n";
}