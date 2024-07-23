#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>

using namespace std;


int main()
{
	cout << "Hello world\n\n";

	int *regadr;
	cout << regadr << endl;

	string s;

	std::ifstream in;
	in.open("../hello.txt");
	if (in.is_open()) in >> s;
	else cout << "not open"  << endl;
	in.close();

	cout << s << endl;

	regadr = (int*)stoul(s,nullptr,16);

	cout << regadr << endl;

	*regadr = 100;

	cout << *regadr << endl;

	return 0;
}
