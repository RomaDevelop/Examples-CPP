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
int test_gloabal_a=0;
String thread2_errors;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
String action;
if(RadioButtonPP->Checked) action="++";
if(RadioButtonMM->Checked) action="--";
if(RadioButtonP5->Checked) action="+=5";

MemoLog->Lines->Add("start calc a");

								   // &test_gloabal_a     	���������� ��� ������� ����� ��������
								   // action     			��� ����� ������
								   // &thread2_result    	���� ������� ������
								   // onThrTerminate        ���������� ������� ����������
MyThread2 *Thr = new MyThread2(false, &test_gloabal_a, action, &thread2_errors, onThrTerminate);   // �������� ����� ����������

//MyThread2 *Thr = new MyThread2(true, &test_gloabal_a, action, &thread2_result, onThrTerminate);   // �������� � ������������� ����
//Thr->Resume();        // ������

//Thr->WaitFor();      // ����� ����������  -  �������� ���������������, ����� ����� ����������

//delete Thr;   // ������! ����� ����� ����� �� ��� ����������
}
//---------------------------------------------------------------------------
void __fastcall TForm1::onThrTerminate(TObject *Sender)
{
MemoLog->Lines->Add("end calc a");
if(thread2_errors!="") MemoLog->Lines->Add(thread2_errors);
MemoLog->Lines->Add("a = "+IntToStr(test_gloabal_a));
}
//---------------------------------------------------------------------------
