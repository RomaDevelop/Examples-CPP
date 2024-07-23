#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// ���������� ��� ���������� �� ����� �����
bool compareL(const std::string& left, const std::string& right)
	{ return left.length() < right.length(); }

class A{
	public:
	int a;
	A():a{0} {}
	A(int a_):a{a_}{}

	// ����� ����� ���� ����������� ��������� ������ � ����� ����������� �������� ��� ������������ ����������
	bool operator< (A a_) { if(a < a_.a) return true; else return false; }

	// ����������� ����� �� ������ ���������� � ������ ����� ������, �������� ����� ������������� �� ������� �� ������� �� 128
    // ��� ����� ����� ������� �������������� ����������
	static bool Compare128(A left, A right)  { if(left.a%128 < right.a%128) return true; else return false; }

};


int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> people {"Tom", "Bob", "Sam", "Alice", "Kate"};
	cout<<"1 Not sorted: "; for(auto vi:people) cout<<vi<<" "; cout<<endl;

	// ������� ����������. ��������� � ������� O( n*log(n) ), �� � ������ ������ O( n*n )
	sort(begin(people), end(people));
	cout<<"1 ___ Sorted: "; for(auto vi:people) cout<<vi<<" "; cout<<endl;

	people={"Tom", "Bob", "Sam", "Alice", "Kate"};
	cout<<"2 Not sorted: "; for(auto vi:people) cout<<vi<<" "; cout<<endl;

	// � sort ��������� ������� ����������, ��������� �� �����
	// � ����� �������� ��� � ������������, �� ���� ����� https://metanit.com/cpp/tutorial/16.5.php
	sort(begin(people), end(people), compareL);
	cout<<"2 ___ Sorted: "; for(auto vi:people) cout<<vi<<" "; cout<<endl;

    //people={"Tom", "Bob", "Sam", "Alice", "Kate"};
	//coutV(people,"3 Not sorted: ");
    //// ranges::sort (c++ 20)
    //std::ranges::sort(people);
    //coutV(people,"3 ranges::sort: ");

	vector <A> a={54,654,515,45451,4,884842,5454};
	cout<<"3 Not sorted: "; for(auto vi:a) cout<<vi.a<<" "; cout<<endl;
	sort(begin(a), end(a));
	cout<<"3 ___ sorted: "; for(auto vi:a) cout<<vi.a<<" "; cout<<endl;

	cout<<"left divide 128"<<endl;
	cout<<"4 Not sorted: "; for(auto vi:a) cout<<vi.a%128<<" "; cout<<endl;
	sort(begin(a), end(a), A::Compare128);
	cout<<"4 ___ sorted: "; for(auto vi:a) cout<<vi.a%128<<" "; cout<<endl;
	cout<<"4 ___ sami a: "; for(auto vi:a) cout<<vi.a<<" "; cout<<endl;

	/*
    ���
	https://purecodecpp.com/archives/3450

    � sort ����� �������� ������� ���������

	���������� ��������������������. ��������������� ��������� O( n*log(n) ) � ����� ������.
	������ ���������� � ���� ����������� � 2-5 ��� ��������� ������� ���������� sort().
    partial_sort( v.begin(), v.end(), v.end() );

    ���������� ��������. ��������� O( n*log(n) ) ��� O( n*log(n)*log(n) ),
	���� ��� �������������� ������
    stable_sort( v.begin(), v.end() );

	// ���������� � ���� (heap) - �������� �������, ��������������� ���������� � �����
    // (�� ���� � �������� �������, ������������ � ���������� ���� ����������).
    // ��������� O( n+n*log(n) )
    make_heap( v.begin(), v.end() );
    sort_heap( v.begin(), v.end() );
	*/

	getch();
	return 0;
}

