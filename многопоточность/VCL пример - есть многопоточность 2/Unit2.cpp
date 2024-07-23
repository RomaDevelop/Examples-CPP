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
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
								   // *a_     			переменная над которой будем работать
								   // action_     	  	что будем делать
								   // *result_    		куда запишем ошибки
								   // onTerminate_      обработчик события завершения
__fastcall MyThread2::MyThread2(bool CreateSuspended, int *a_, String action_, String *errors_, TNotifyEvent onTerminate_)
	: TThread(CreateSuspended)
{
a=a_;
action=action_;
errors=errors_;
*errors="";                         // очистка переменной для ошибок если вдруг там что-то было
this->OnTerminate=onTerminate_;

FreeOnTerminate = true;  // очистить память по завершению работы потока  (иногда это не нужно делать, если поток понадобится другому потоку
}
//---------------------------------------------------------------------------
void __fastcall MyThread2::Execute()
{             //---- Place thread code here ----
if(a==nullptr) *errors="Ошибка! nullptr";
int a_tmp=*a;
if(action=="++")
	{
	std::string s;
	for(uint64_t i=0; i<1000000; i++)
		{
		a_tmp++;
		s=std::to_string(a_tmp);
		}
	}
	else if(action=="--")
		{
		std::string s;
		for(uint64_t i=0; i<1000000; i++)
			{
			a_tmp--;
			s=std::to_string(a_tmp);
			}
		}
		else if(action=="+=5")
			{
			std::string s;
			for(uint64_t i=0; i<1000000; i++)
				{
				a_tmp+=5;
				s=std::to_string(a_tmp);
				}
			}
			else if(action=="") *errors="Ошибка! empty action";
			else *errors="Ошибка! unnown action";

*a=a_tmp;
}
//---------------------------------------------------------------------------
