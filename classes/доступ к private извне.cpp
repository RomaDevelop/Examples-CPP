#include <iostream>
using namespace std;
 
class A
{
  int a {45};  
  void a34() {a=34;}
};
 
class B
{
    
    int a;
    
    public:
    int GetA() {return a;}
};
 
class C
{
    public:
    int a;  // даже так работает
};

int main() {
    
    A Aobj;
    A *apt = &Aobj; 
    
    cout << ((B*)apt)->GetA() << endl;
    cout << ((C*)apt)->a << endl;
    
    ((C*)apt)->a = 666;
    
    cout << ((C*)apt)->a << endl;
    
    return 0;
}

несколько способов
ru.stackoverflow.com/questions/1524726/Как-получить-доступ-к-приватному-члену-класса

самое интересное:

Персона грата №4: адвокат

Многие из нас недаром больше боятся хорошо одетых и улыбающихся адвокатов, чем (других) преступников.
Рассмотрим следующий код.

// Файл x.h 
// 
class X { 
public:
    X() : private_(1) { /*...*/ }
    template<class T>
    void f( const T& t ) { /*...*/ }
    int Value() { return private_; }
    // ...
private: 
    int private_; 
};

Персона грата №4: адвокат

// Пример 15-4: проныра-законник
//
namespace {
    struct Y {};
}
template<>
void X::f( const Y& ) {
    private_ = 2;               // Злобный смех
}
void Test() {
    X x;
    cout << x.Value() << endl;  // Выводит 1
    x.f( Y() );
    cout << x.Value() << endl;  // Выводит 2
}
Этот человек — адвокат, который знает все лазейки. Его невозможно поймать, поскольку он слишком осторожен, чтобы нарушить букву закона, при этом нарушая его дух. Запомните и избегайте таких неджентльменов.
Как бы мне ни хотелось сказать “Конечно, то, что делает адвокат, — не законно”, увы, я не могу этого сделать, поскольку все сделанное в последнем примере законно. Почему? В примере 15-4 использован тот факт, что у X есть шаблон функции-члена. Приведенный код соответствует стандарту, так что последний гарантирует, что он будет работать так, как ожидается.

и похожее, но менее понятное:

template<typename x_Ptr>
struct Get
{
    static inline x_Ptr ptr;
};

template<auto x_ptr>
struct Access
{
    static inline int dummy{(Get<decltype(x_ptr)>::ptr = x_ptr, 0)};
};

#include <string>
#include <iostream>

// класс без изменений!
class Something {
public:
    Something() {
        topSecretValue = 42;
    }
    bool somePublicBool;
    int somePublicInt;
    std::string somePublicString;
private:
    int topSecretValue;
};

template struct Access<&Something::topSecretValue>;

int main()
{
    Something something{};
    ::std::cout << something.*(Get<int Something::*>::ptr);
}

