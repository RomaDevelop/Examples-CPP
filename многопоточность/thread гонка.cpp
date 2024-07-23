#include <conio.h>
#include <iostream>
#include <thread>
#include <atomic>

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{

	unsigned long long g_count = 0;

	std::thread t1([&]()
	{
		for(auto i = 0; i < 5000000; ++i)
			{
			++g_count;
			}
	});

	std::thread t2([&]()
	{
		for(auto i = 0; i < 5000000; ++i)
			{
			++g_count;
			}
	});

	t1.join();
	t2.join();

	cout << "g_count = " << g_count << endl;

	getch();
	return 0;
}


