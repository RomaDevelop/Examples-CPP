//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class MyThread : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
    int *a;
	__fastcall MyThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
