#include <iostream>
#include <chrono>
#include <set>
#include <unordered_set>
using namespace std;

void print_result(auto &start_time, string prefix)
{
    auto end_time = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    string elapsed_str = to_string(elapsed.count());
    for(int i=elapsed_str.size()-1, n=1; i>=0; i--, n++) if(n%3 == 0 && i!=0) elapsed_str.insert(i," ");
    cout << prefix+" " << elapsed_str << endl;
}

int main() {
    
    set<string> setStr;
    unordered_set<string> usetStr;
    
    int last = 1000000;
    string lastStr = to_string(last);
    for(int i=0; i<=last; i++)
    {
        string s = to_string(rand());
        setStr.insert(s);
        usetStr.insert(s);
    }
    
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