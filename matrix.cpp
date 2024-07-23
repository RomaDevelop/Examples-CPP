// ��������� ����� matrix ��������� �������� � ���������� ��������, ��� � ��������� ��������� � ��������� M[������][�������]
// � ���������, �� �������� ������ ��������� - ��� � 2-3 ���� ����
#include <conio.h>
#include <iostream>

using namespace std;

template <typename T>
class matrix
	{
	T *data;
	int ColCount;
	int RowCount;

public:
	matrix(): data(nullptr), ColCount(0), RowCount(0) {}
	matrix(T *data_, int ColCount_, int RowCount_): data(data_), ColCount(ColCount_), RowCount(RowCount_) {}
	void set(T *data_, int ColCount_, int RowCount_) { data=data_; ColCount=ColCount_; RowCount=RowCount_; }

	T& m(int col, int row) 			{ return data[col+row*ColCount]; }
	const T& m(int col, int row) const 	{ return data[col+row*ColCount]; }

	T* operator[](int row) 			{ return data+row*ColCount; }
	const T* operator[](int row) const 	{ return data+row*ColCount; }

	void print() const
		{
		for(int r=0; r<RowCount; r++)
			{
			for(int c=0; c<ColCount; c++)
				{
				cout<<m(c,r)<<"\t";
				}
			cout<<endl;
			}
		cout<<endl;
		}
	};

int _tmain(int argc, _TCHAR* argv[])
{
	const int n=30;
	int arr[n];
	int cols=10, rows=3;
	for(int i=0; i<n; i++)
		{
		arr[i]=i;
		cout<<arr[i]<<" ";
		}
	cout<<endl<<endl;

	matrix<int> M(arr, cols, rows);

	M.print();

	for(int i=0; i<rows; i++)
		{
		for(int j=0; j<cols; j++)
			cout<<M[i][j]<<"\t";
		cout<<endl;
		}
	cout<<endl;

	M[0][3]=111111;
	M[1][4]=222222;
	M[2][5]=333333;
	int a=M[2][5];
	cout<<endl;

	M.print();

	getch();
	return 0;
}
