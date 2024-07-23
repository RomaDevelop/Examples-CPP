#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



class A{
	public:
	int a;
	string s;
	A():a{0} {}
	A(int a_):a{a_}{}

	bool operator== (A a_) { if(a==a_.a) return true; else return false; }            // чтобы работал find нужно перегрузить операцию сравнения
	bool operator== (string s_) { if(s==s_) return true; else return false; }            // чтобы работал find нужно перегрузить операцию сравнения
	//bool operator< (A a_) { if(a < a_.a) return true; else return false; }
	//bool operator> (A a_) { if(a > a_.a) return true; else return false; }
};

bool Compare1(A a) {if(a.s=="test" && a.a > 100) return true; else return false; }
int Compare2Val=100;
bool Compare2(A a) {if(a.s=="test" && a.a > Compare2Val) return true; else return false; }

void coutV(vector<A> a, string s="")
	{
	if(s!="") cout<<s;
	for(auto ai:a)
		cout<<ai.a<<" ";
	cout<<endl;
	}

int _tmain(int argc, _TCHAR* argv[])
{

	vector <int> i={54,654,515,45451,4,884842,5454};

	auto f=find(begin(i), end(i),4);
	if(f!=end(i)) cout<<"pos "<<f - begin(i)<<endl;
		else  cout<<"not found "<<endl;

	vector <A> a={54,654,515,45451,4,884842,5454};
	auto fa=find(begin(a), end(a), 4);
	if(fa!=end(a)) cout<<"pos "<<fa - begin(a)<<endl;
		else  cout<<"not found "<<endl;

	a[6].s=a[0].s=a[1].s="test";
	auto fas=find(begin(a), end(a), "test");
	if(fas!=end(a)) cout<<"pos "<<fas - begin(a)<<endl;
		else  cout<<"not found "<<endl;

	fas=find_if(begin(a), end(a), Compare1);
	if(fas!=end(a)) cout<<"pos "<<fas - begin(a)<<" value "<<(*fas).a<<endl;
		else  cout<<"not found "<<endl;

	Compare2Val=10000;
	fas=find_if(begin(a), end(a), Compare2);
	if(fas!=end(a)) cout<<"pos "<<fas - begin(a)<<endl;
		else  cout<<"not found "<<endl;

	getch();
	return 0;
}

