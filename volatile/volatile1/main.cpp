#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;


int main()
{
	cout << "Hello world\n\n";

	volatile int *reg = new int(10);
	cout << "*reg = " << *reg << endl;

	int *regadr = (int*)reg;  // получение адреса и вывод полученного адреса volatile переменной
	cout << regadr << endl;

	*regadr += 10;				// проверка меняется ли значение по адресу
	cout << *reg << endl;

	std::ofstream out;
	out.open("../hello.txt");
	if (out.is_open()) out << regadr;
	else cout << "not open" << endl;
	out.close();

	for(;;)
	{
		cout << *reg << "\t";
		std::this_thread::sleep_for(std::chrono::milliseconds(333));
	}

	return 0;
}
