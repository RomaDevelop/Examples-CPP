#include <conio.h>
#include <iostream>
#include <thread>
#include <atomic>

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{

	std::atomic<unsigned long long> g_count_a { 0 };

	std::thread t1_a([&]()
	{
		for(auto i = 0; i < 1000000; ++i)
			{
			g_count_a.fetch_add(1);
			}
	});

	std::thread t2_a([&]()
	{
		for(auto i = 0; i < 1000000; ++i)
			{
			g_count_a.fetch_add(1);
			}
	});

	t1_a.join();
	t2_a.join();

	cout<< "g_count_a = " << g_count_a << endl;

	getch();
	return 0;
}


