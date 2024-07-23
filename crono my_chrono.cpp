
#include <conio.h>
#include <string>
#include <iostream>
#include <chrono>
#include <MyStrSTL.hpp>

using namespace std;

class my_chrono
	{
	chrono::time_point<std::chrono::system_clock> Start;
	chrono::time_point<std::chrono::system_clock> End;

public:
	my_chrono() { start(); }

	void start() { Start=chrono::steady_clock::now(); }
	void end() { End=chrono::steady_clock::now(); }
	void print()
		{
		auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
		string nano=std::to_string(elapsed_ns.count());
		nano=MyStr::AsNumberDigits(nano);
		cout << nano << " ns\n";
		}
	};



int _tmain(int argc, _TCHAR* argv[])
{
auto   start_time = std::chrono::steady_clock::now();
auto   end_time = std::chrono::steady_clock::now();
auto   elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
string nano=std::to_string(elapsed_ns.count());

	//string s="sdvsdv";
//	int64_t sad=345334534;
//	int64_t n=90000000;
//	int *arr=new int [n];
//	int cols=9, rows=10000000;
//	for(int i=0; i<n; i++)
//		{
//		arr[i]=i;
//		//cout<<arr[i]<<" ";
//		}
//	//cout<<endl<<endl;
//
//	matrix<int> M(arr, cols, rows);
//
//	cout<< "start" << endl;
//
//	start_time = std::chrono::steady_clock::now();
//	my_chrono mc;
//	for(int i=0; i<rows; i++)
//		for(int j=0; j<cols; j++)
//			M[i][j]=i+j;
//	mc.end();
//	mc.print();
//    end_time = std::chrono::steady_clock::now();
//    elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
//	nano=std::to_string(elapsed_ns.count());
//	cout << nano << " ns\n";
//
//	start_time = std::chrono::steady_clock::now();
//	mc.start();
//	for(int i=0; i<rows; i++)
//		for(int j=0; j<cols; j++)
//			arr[j+i*cols]=i+j;
//	mc.end();
//	mc.print();
//
//    end_time = std::chrono::steady_clock::now();
//    elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
//    nano=std::to_string(elapsed_ns.count());
//	cout << nano << " ns\n";

	getch();
	return 0;
}

