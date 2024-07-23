#include <conio.h>
#include <iostream>
#include <future>

using namespace std;

int64_t GiveSum()
	{
	int64_t a=0;
	int64_t sum=0;
	for(int64_t i=0; i<200000000; i++)
		{
		a=i*i/2;
		a=i;
		a++;
		a=i%2;
		a++;
		sum+=i;
		}
	cout<<"in GiveSum() "<<sum<<endl;
	return sum;
	}

int _tmain(int argc, _TCHAR* argv[])
{

	int64_t a=0;
	int64_t sum=0;

	auto sum_a=std::async(std::launch::async,GiveSum);
	cout<<"dfbdf\n";
	cout<<"auto sum_a.get "<<sum_a.get()<<endl;
	cout<<"dfbdf\n";

	for(int64_t i=0; i<200000000; i++)
		{
		a=i*i/2;
		a=i;
		a++;
		a=i%2;
		a++;
		sum+=i;
		}



	cout<<sum;

	getch();
	return 0;
}
