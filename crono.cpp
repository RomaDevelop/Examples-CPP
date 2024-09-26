#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

long long get_nanosec_duration(auto &start_time)
{
	auto end_time = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    return elapsed.count();
}

void print_result(auto &start_time, string prefix = "")
{
    string elapsed_str = to_string(get_nanosec_duration(start_time));
    for(int i=elapsed_str.size()-1, n=1; i>=0; i--, n++) if(n%3 == 0 && i!=0) elapsed_str.insert(i," ");
	if(!prefix.empty())
		cout << prefix+" ";
	cout << elapsed_str << endl;
}

int main() {

	// подготовка измеряемых
    vector<int> vect;
    long count = 30'000'000;
    vect.resize(count);
    
	// подготовка измерителя
    auto start_time = chrono::steady_clock::now();
    for(int i=0; i<5; i++)
    {
        cout<< "\nRound " << i+1 << "\n"; 
		
		// test 1
    	start_time = chrono::steady_clock::now();
		// start
        setStr.count(lastStr);
    	// finish
        print_result(start_time, "set duration");
		// end test
    	
		// test 2
    	start_time = chrono::steady_clock::now();
		// start
		usetStr.count(lastStr);
		// finish
    	print_result(start_time, "uset duration");
    	// end test
    }
	
    return 0;
}