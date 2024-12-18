// std::sort(...) - Быстрая сортировка. Сложность в среднем O( n*log(n) ), но в худшем случае O( n*n )

// сортировка с применением компаратора функции
bool compareFunction(const std::string& left, const std::string& right) { return left.length() < right.length(); }
std::sort(strings.begin(), end.begin(), compareFunction);

// сортировка с применением компаратора лямбды
auto comlareLambda = [](const std::string& left, const std::string& right) { return left.length() < right.length(); }
std::sort(strings.begin(), end.begin(), comlareLambda);

// чтобы можно было сортировать коллекции класса в этом классе должен быть определён оператор сравнения (или внешняя функция сравнения) 
bool operator< (const T& t) { return value < t.value; }
bool operator< (const T& lhs, const T& rhs) { return lhs.value < rhs.value; } // рекомендуется делать внешнюю функцию, есть разные преимущества
// тогда можно сортировать без компаратора
std::sort(listT.begin(), listT.begin());

// некоторые не std контейнеры возвращают несовместимые итераторы, но ожно получить совместимые при помощи внешних begin-end функций, пример QList
QList<QString> strings;
std::sort(std::begin(strings), std::end(strings), compare);

/*
Сортировка подпоследователности. Гарантированная сложность O( n*log(n) ) в любом случае.
Обычно сортировка в куче выполняется в 2-5 раз медленнее быстрой сортировки sort().
partial_sort( v.begin(), v.end(), v.end() );

Сортировка слиянием. Сложность O( n*log(n) ) или O( n*log(n)*log(n) ),
если без дополнительной памяти
stable_sort( v.begin(), v.end() );

// Сортировка в куче (heap) - вызывают функции, непосредственно работающие с кучей
// (то есть с бинарным деревом, используемым в реализации этих алгоритмов).
// Сложность O( n+n*log(n) )
make_heap( v.begin(), v.end() );
sort_heap( v.begin(), v.end() );
*/

