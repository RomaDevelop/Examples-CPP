#include <conio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <future>

using namespace std;

class burda {int a; float b; double c;};

int _tmain(int argc, _TCHAR* argv[])
{

	std::vector<int> v;
	std::vector<burda> b;
	std::vector<int> r;

	auto cap = v.capacity();
	std::cout << "Initial size: " << v.size() << ", capacity: " << cap << '\n';

    std::cout << "\nDemonstrate the capacity's growth policy."
				 "\nSize:  Capacity:  Ratio:\n" << std::left;

	for(int i=1; i<=1000; i+=10)
		{
		v.resize(i);
		cap = v.capacity();
		std::cout << v.size() << "\t" << cap << "\treserve\t";

		r.reserve(i);
		cap = r.capacity();
		std::cout << r.size() << "\t" << cap << "\tburda resize\t";

		b.resize(i);
		cap = b.capacity();
		std::cout << b.size() << "\t" << cap << '\n';
		}

	for(int i=1; i<=1000; i++)
		{
		v.erase(v.end()-1);
		if(i%10==0 || i > 970)
			std::cout << v.size() << "\t" << cap << "\n";
		}

	std::cout << "\nFinal size: " << v.size() << ", capacity: " << v.capacity() << '\n';

	getch();
	return 0;
}

// редактирование ветора через range-based for
void VP10( vector<int> &v)
{
    for(auto &i:v) i+=10;
}

// transform vector -> list
    vector<int> vi {45,45,78,54,12,485,8,5};
    list<int> li;
    li.resize(10); // размер должен быть выделен заранее!!!
    
    transform(vi.begin(), vi.end(), li.begin(), [](int i) { return i+1; }); // i+1!!! i++ почему-то не меняет!!!
    
    cout << "vector: "<< endl; 
    for(auto &i:vi) cout<< i << "\t"; 
    cout << endl << endl; 
    
    cout << "transform in list: "<< endl; 
    for(auto &i:li) cout<< i << "\t"; 
    cout << endl << endl;
	
	
// перенос map в vector
    vector<pair<int, string>> V;
    V.resize(M.size());  // размер должен быть выделен заранее!!!
    
    copy(M.begin(), M.end(), V.begin()); 
    
    cout << "vector: "<< endl; 
    for(auto &i:V) cout<< i.first << ":" << i.second << "; "; 
    cout << endl << endl;
	
// return vector (семантика перемещения)
#include <iostream>
#include <vector>
using namespace std;

vector<int> Get5()
{
    vector<int> v5o {5,5,5,5,5,6};
    return v5o;
}

int main() {
    
    vector<int> v5o = Get5();
    
    for(auto &i:v5o)
        cout << i << " ";
            
    return 0;
}


// push_back(объект) вызывает деструкторы объектов
	// 1 причина параметр - временный объект передаваемый в функцию push_back
	// 2 причина - релокация вектора, т.е. уничтожение старых и создание новых объектов в новом месте

#include <iostream>
#include <vector>
using namespace std;

class A
{
    int a;
    public:
    A(int val): a{val} {cout<< "A()\n";}
    ~A() {cout<< "~A()\n";}  
};

int main() {
    
    vector<A> vectA;
    
    //vectA.reserve(10);
    for(int i=0; i<10; i++)
        {
        vectA.push_back(i);
        // vectA.push_back(A(i));  // не помогло
        cout<<"push_back did\n";
        }
    
    cout << "end\n";
    
    return 0;
}

// Исследования производительности вектора. Сравнение классического цикла for(i) и итераторного. Классический цикл победил!
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int main() {
    auto start_time = chrono::steady_clock::now();
    auto end_time = chrono::steady_clock::now();
    auto elapsed = end_time - start_time;
    string elapsed_str;
    
    vector<int> vect;
    long count = 30'000'000;
    vect.resize(count);
    
    for(int i=0; i<5; i++)
    {
        cout<< "Round " <<i+1<<"! Fight!!!\n"; 
    	start_time = chrono::steady_clock::now();
    	// арена испытаний
        for(auto &v:vect)
            v = 11;
    	// конец арены
    	end_time = chrono::steady_clock::now();
    	elapsed = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    	elapsed_str = to_string(elapsed.count());
    	for(int i=elapsed_str.size()-1, n=1; i>=0; i--, n++) if(n%3 == 0 && i!=0) elapsed_str.insert(i," ");
    	cout << elapsed_str << endl;
    	
    	start_time = chrono::steady_clock::now();
    	// арена испытаний
        for(long i=0; i<vect.size(); i++)
            vect[i] = 10;
    	// конец арены
    	end_time = chrono::steady_clock::now();
    	elapsed = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    	elapsed_str = to_string(elapsed.count());
    	for(int i=elapsed_str.size()-1, n=1; i>=0; i--, n++) if(n%3 == 0 && i!=0) elapsed_str.insert(i," ");
    	cout << elapsed_str << endl;
    	
    	start_time = chrono::steady_clock::now();
    	// арена испытаний
        for(long i=0; i<count; i++)
            vect[i] = 500;
    	// конец арены
    	end_time = chrono::steady_clock::now();
    	elapsed = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    	elapsed_str = to_string(elapsed.count());
    	for(int i=elapsed_str.size()-1, n=1; i>=0; i--, n++) if(n%3 == 0 && i!=0) elapsed_str.insert(i," ");
    	cout << elapsed_str << endl;
    }
    return 0;
}

Round 1! Fight!!!
430 968 719
235 348 476
187 565 571
Round 2! Fight!!!
510 479 231
211 459 989
188 021 547
Round 3! Fight!!!
453 439 074
230 835 043
191 658 925
Round 4! Fight!!!
399 683 922
207 616 304
186 230 901
Round 5! Fight!!!
390 872 875
227 722 098
184 513 818