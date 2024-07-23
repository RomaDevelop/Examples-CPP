//===================================================================================
//===================================================================================
Десять возможностей C++11, которые должен использовать каждый C++ разработчик
//===================================================================================

#1 — auto
auto i = 42;        // i - int
auto l = 42LL;      // l - long long
auto p = new foo(); // p - foo*
auto i = begin(v); 	// iterator


#2 — nullptr 
int* p2 = nullptr;
if(p2) ... ; // можно и нужно
bool f = nullptr;
int i = nullptr; // ошибка: для преобразования в int надо использовать reinterpret_cast


#3 — range-based циклы
for(auto v: kvp)
for(int &e: arr)
	
#4 — override и final
class D : public B
{
   void f(int) override final { }
};

class a final
{
	
};


#5 — строго-типизированный enum
enum class Options {None = 1, One = 10, All = 1000};
int one = static_cast<int>(Options::One);


#6 — интеллектуальные указатели
unique_ptr: должен использоваться, когда ресурс памяти не должен был разделяемым (у него нет конструктора копирования), но он может быть передан другому unique_ptr
shared_ptr: должен использоваться, когда ресурс памяти должен быть разделяемым
weak_ptr: содержит ссылку на объект, которым управляет shared_ptr, но не осуществляет подсчет ссылок; позволяет избавиться от циклической зависимости


#7 — лямбды
std::for_each(std::begin(v), std::end(v), [](int n) {std::cout << n << std::endl;});


#8 — non-member begin() и end()
Они работают со всеми контейнерами STL и могут быть расширены для работы с любым типом.
И тогда можно использовать всю STL для любой сущности


#9 — static_assert и классы свойств
проверяет утверждение во время компиляции. Если утверждение — истина, то ничего не происходит. Если — ложь, то компилятор выводит указанное сообщение об ошибке.
static_assert(Size > 3, "Size is too small");
template <typename T1>
static_assert(std::is_integral<T1>::value, "Type T1 must be integral");


#10 — семантика перемещения

//===================================================================================
//===================================================================================
# 21 фича современного C++, которые вам обязательно пригодятся
https://habr.com/ru/companies/otus/articles/741428/
//===================================================================================

#Псевдонимы типов
template <typename T>
using dyn_arr = std::vector<T>;
dyn_arr<int> nums; // эквивалентно std::vector<int>, похоже на использование typedef, однако псевдонимы типов легче читаются и совместимы с шаблонами С++

# Пользовательские литералы
using ull = unsigned long long;
constexpr ull operator"" _KB(ull no) { return no * 1024; }
constexpr ull operator"" _MB(ull no) { return no * (1024_KB); }
cout<<1_KB<<endl;
cout<<5_MB<<endl;

# Инициализация полей при объявлении
class demo
{
private:
    uint32_t m_var_1 = 0;
	cpu_t m_cpu{2, 3.2_GHz};
	const static int m_var = 0;  // только конст статик.
};

# Списки инициализации std::initializer_list
std::vector<int> v = {1, 2, 3, 4, 5};
// Не работает для адаптеров (stack, queue, priority_queue)

# auto & decltype
template <typename X, typename Y>
auto add(X x, Y y) -> decltype(x + y) { return x + y; }
add(1, 2);     // == 3
add(1, 2.0);   // == 3.0
add(1.5, 1.5); // == 3.0

# Строго типизированные перечисления
enum class STATUS_t : uint32_t
{ PASS = 0 };

# Приведение типов
explicit запрет Си-шного преобразования, только через static_cast и dynamic_cast

# Move-семантика
если ресурс после копирования уничтожается, можено делать 
нечто2 = std::move(нечто1);
(для классов нужно переопределить оператор присваивания перемещением и конструктор перемещения)

Move семантика - возврат контейнеров по значению теперь вполне идиоматичен:
std::vector<A> getAs(...);
auto as = getAs(); // vector is moved (not copied) which is cheap

осторожно - иногда она и вредна, особенно в более поздних стандартах, там всё делает компилятор и еще быстрее

# Универсальные ссылки
освоить повторно

# Шаблоны с переменным количеством аргументов (вариативные шаблоны)
освоить повторно

# constexpr
выражения, вычисляемые компилятором во время компиляции

# Удаленные и дефолтные функции
struct demo
{
    demo() = default;
	demo(int x) : m_x(x){};
    demo(const demo &) = delete;
    demo &operator=(const demo &) = delete;
};

# Делегирование конструкторов
можно вызывать конструкторы из конструкторов в списке инициализации
struct demo
{
    int m_var;
    demo(int var) : m_var(var) {}
    demo() : demo(0) {}
};

# Лямбда-выражения
можно объявлять функции где угодно, и это не стоит никаких дополнительных расходов
auto generator = [i = 0]() mutable { return ++i; };

# Операторы ветвления с инициализатором
switch (auto STATUS = window.status()) // Объявляем объект прямо в операторе ветвления
{
case PASS:// делаем что-то
    break;
case FAIL:// делаем что-то
    break;
}

if(int res = getErrCode())
{
	cout << ErrToStr(res);
}

# std::tuple
auto get_employee_detail()
{
    // делаем что-нибудь . . . 
    return std::make_tuple(32, " Vishal Chovatiya", "Bangalore");
}

string name;
std::tie(std::ignore, name, std::ignore) = get_employee_detail();



