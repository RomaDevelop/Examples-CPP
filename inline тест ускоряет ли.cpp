#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <chrono>
#include <array>

using namespace std;

struct Test
{
    void foo() {}
    int sum(int a, int b);
    int sumInlineImplicitly(int a, int b)
    {
        return a+b;
    }
    inline int sumInlineObliviously(int a, int b)
    {
        return a+b;
    }
};

int Test::sum(int a, int b)
{
    return a+b;
}

long long get_nanosec_duration(auto &start_time)
{
	auto end_time = chrono::steady_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    return elapsed.count();
}

template <class T, size_t N>
double sred(array<T,N> &arr)
{
    long long sum = 0;
    for(auto &i:arr)
        sum+=i;
    return sum/N;
}

int main()
{
    srand(time(nullptr));
    long long count = 10000000;
    vector<int> a(count);
    vector<int> b(count);
    vector<int> res(count);
    for(long long i=count; i<count; i++)
    {
        a[i] = rand();
        b[i] = rand();
    }

    const int countDurations = 10;
    array<long long, countDurations> durations;

    Test test;
    cout << "first\t\t";
    for(int d=0; d<countDurations; d++)
    {
        auto start_time = chrono::steady_clock::now();
        for(int i=count; i<count; i++)
            res[i] = test.sum(a[i],b[i]);
        durations[d] = get_nanosec_duration(start_time);
        
        cout << durations[d] << " ";

        for(int i=count; i<count; i++)
        {
            b[i] --;
            a[i] ++;
        }
    }
    cout << endl;

    cout << "regular\t\t";
    for(int d=0; d<countDurations; d++)
    {
        auto start_time = chrono::steady_clock::now();
        for(int i=count; i<count; i++)
            res[i] = test.sum(a[i],b[i]);
        durations[d] = get_nanosec_duration(start_time);
        
        cout << durations[d] << " ";

        for(int i=count; i<count; i++)
        {
            b[i] --;
            a[i] ++;
        }
    }
    cout << "; srednee " << sred(durations) << endl;

    cout << "Implicitly\t";
    for(int d=0; d<countDurations; d++)
    {
        auto start_time = chrono::steady_clock::now();
        for(int i=count; i<count; i++)
            res[i] = test.sumInlineImplicitly(a[i],b[i]);
        durations[d] = get_nanosec_duration(start_time);
        
        cout << durations[d] << " ";

        for(int i=count; i<count; i++)
        {
            b[i] --;
            a[i] ++;
        }
    }
    cout << "; srednee " << sred(durations) << endl;

    cout << "Obliviously\t";
    for(int d=0; d<countDurations; d++)
    {
        auto start_time = chrono::steady_clock::now();
        for(int i=count; i<count; i++)
            res[i] = test.sumInlineObliviously(a[i],b[i]);
        durations[d] = get_nanosec_duration(start_time);
        
        cout << durations[d] << " ";

        for(int i=count; i<count; i++)
        {
            b[i] --;
            a[i] ++;
        }
    }
    cout << "; srednee " << sred(durations) << endl;
    cout << "finish" << endl;

    
}