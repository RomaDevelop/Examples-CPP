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
class MyThread2 : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall MyThread2(bool CreateSuspended, int *a_, String action_, String *errors_, TNotifyEvent onTerminate_);

	int *a;
	String action;
	String *errors;

};
//---------------------------------------------------------------------------
#endif
