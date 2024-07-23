//---------------------------------------------------------------------------

#include <string>
#include <System.hpp>
#pragma hdrstop

#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall MyThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall MyThread::MyThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall MyThread::Execute()
{
//---- Place thread code here ----
int a_tmp=*a;
std::string s;
for(uint64_t i=0; i<1000000; i++)
	{
	a_tmp++;
	s=std::to_string(a_tmp);
	}
*a=a_tmp;
//ShowMessage(*a);
}
//---------------------------------------------------------------------------
