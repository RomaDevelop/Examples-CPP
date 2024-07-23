#include <conio.h>
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{

    unsigned long long g_count = 0;

	std::mutex g_count_mutex;

    std::thread t1([&]()
	{
		for(auto i = 0; i < 1000000; ++i) {
            g_count_mutex.lock();
            g_count += 1;
            g_count_mutex.unlock();
        }
    });

    std::thread t2([&]()
    {
		for(auto i = 0; i < 1000000; ++i) {
            g_count_mutex.lock();
            g_count += 1;
            g_count_mutex.unlock();
        }
    });

    t1.join();
    t2.join();

	std::cout << g_count;

	getch();
	return 0;
}


