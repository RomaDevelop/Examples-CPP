
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class A
    {
    private:
	int priv;

    protected:
	int prot;

    public:
	int publ;

    };

class B : public A
    {
    private:
	void Set_priv(int a_)
		{
		// priv=a_;     нельзя
		}

    public:

    int publ;

	void Set_prot(int a_)
		{
		prot=a_;
		}

	void Get_prot()
		{
		cout<<prot<<endl;
		}

    };

int main() {

	B Bobj;
	//Bobj.prot=55;  нельзя, ошибка
	Bobj.Set_prot(5);
	Bobj.Get_prot();
    
    Bobj.publ=56;
	cout<<Bobj.A::publ<<endl;
	cout<<Bobj.publ<<endl;
	
	A *Aptr=new B;
	Aptr->publ=55;
	cout<<Aptr->publ<<endl;
	//cout<<Aptr->B::publ<<endl;  нельзя
	return 0;
}