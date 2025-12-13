#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Переопределение глобального оператора new
void* operator new(size_t size) {
    cout << "new allocation size: " << size << endl;
    void* ptr = malloc(size);
    if (!ptr) {
        throw bad_alloc();
    }
    return ptr;
}

// Переопределение delete
void operator delete(void* ptr) noexcept {
    // Мы не знаем точный размер здесь, но можем логировать сам факт освобождения
    cout << "delete " << ptr << endl;
    free(ptr);
}

// Переопределение delete с размером
void operator delete(void* ptr, size_t size) noexcept {
    cout << "delete " << ptr << " size: " << size << endl;
    free(ptr);
}

void print(string str) { cout << str << endl; }

int main() {

    string str10 = "tenLetters";
    string str15 = "tenLetterstenLe";
    string str16 = "tenLetterstenLet";
    string str40 = "tenLetterstenLetterstenLetterstenLetters";

    print(str10);
    print(str15);
    print(str16);
    print(str40);

    return 0;
}