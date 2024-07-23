//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#pragma hdrstop


#include "Unit1.h"
#include "Unit2.h"

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
#include <thread>
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Timer1->Tag--;
Panel1->Caption=Timer1->Tag;
if(Timer1->Tag==0)
	{
	Timer1->Enabled=false;
	Panel1->Caption="���������";
	Panel1->Update();

//	for(uint64_t i=0; i<3000000; i++)
//			{
//			a+=10;
//			a-=10;
//			s=to_string(a);
//			}


	// ���������� https://rxlib.ru/WinLesson/bles2_1.htm
	int a=0;
	MyThread *Thr = new MyThread(true);   // �������� � ������������� ����

	Thr->a=&a;

	MemoLog->Lines->Add("start calc a");
	Thr->Resume();        // ������


//	while(!Thr->Finished)
//		{
//		Sleep(500);
//		MemoLog->Lines->Add("calc...");
//		}
	MemoLog->Lines->Add("end calc a");
	MemoLog->Lines->Add("a = "+IntToStr(a));
	}


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Timer1->Enabled=true;
Timer1->Tag=1;
Panel1->Caption="������ ��������";
}
//---------------------------------------------------------------------------
int test_gloabal_a=0;
void __fastcall TForm1::Button2Click(TObject *Sender)
{
/*
	// ���.�����
	 https://rxlib.ru/WinLesson/bles2_1.htm
	 https://forum.sources.ru/index.php?showtopic=267870
	 https://forum.vingrad.ru/topic-60076/view-all.html
	 https://www.cyberforum.ru/cpp-builder/thread808201.html
	 https://www.cyberforum.ru/cpp-builder/thread1294673.html

*/

	MyThread *Thr = new MyThread(true);   // �������� � ������������� ����

	Thr->a=&test_gloabal_a;     // ������� � ����� ����� ���������� � ������� ����� ���-�� �������
	Thr->OnTerminate=onThrTerminate;      // �� ���������� ���������� ��� �������

	MemoLog->Lines->Add("start calc a");
	Thr->Resume();        // ������
	//Thr->WaitFor();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
MemoLog->Lines->Add("a = "+IntToStr(test_gloabal_a));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::onThrTerminate(TObject *Sender)
{
MemoLog->Lines->Add("end calc a");
MemoLog->Lines->Add("a = "+IntToStr(test_gloabal_a));
}
//---------------------------------------------------------------------------
