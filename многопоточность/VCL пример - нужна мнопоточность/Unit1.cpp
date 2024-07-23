//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#pragma hdrstop


#include "Unit1.h"

#include <MyStr.hpp>

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Timer1->Tag--;
Panel1->Caption=Timer1->Tag;
if(Timer1->Tag==0)
	{
	Timer1->Enabled=false;
	Panel1->Caption="Понеслась";
	Panel1->Update();
	int a=5;
	string s;
	for(uint64_t i=0; i<3000000; i++)
		{
		a+=10;
		a-=10;
		s=to_string(a);
		}
	}


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Timer1->Enabled=true;
Timer1->Tag=4;
Panel1->Caption="Сейчас понесётся";
}
//---------------------------------------------------------------------------
