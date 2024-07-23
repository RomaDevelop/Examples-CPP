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
	// мат.часть
	 https://rxlib.ru/WinLesson/bles2_1.htm
	 https://forum.sources.ru/index.php?showtopic=267870
	 https://forum.vingrad.ru/topic-60076/view-all.html
	 https://www.cyberforum.ru/cpp-builder/thread808201.html
	 https://www.cyberforum.ru/cpp-builder/thread1294673.html

*/

	MyThread *Thr = new MyThread(true);   // создание в остановленном виде

	Thr->a=&test_gloabal_a;     // передаём в поток адрес переменной с которой нужно что-то сделать
	Thr->OnTerminate=onThrTerminate;      // по завершению выполнится это событие

	MemoLog->Lines->Add("start calc a");
	Thr->Resume();        // запуск
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
String action;
if(RadioButtonPP->Checked) action="++";
if(RadioButtonMM->Checked) action="--";
if(RadioButtonP5->Checked) action="+=5";

MemoLog->Lines->Add("start calc a");

								   // &test_gloabal_a     	переменная над которой будем работать
								   // action     			что будем делать
								   // &thread2_result    	куда запишем ошибки
								   // onThrTerminate        обработчик события завершения
MyThread2 *Thr = new MyThread2(false, &test_gloabal_a, action, &thread2_errors, onThrTerminate);   // создание сразу запущенным

//MyThread2 *Thr = new MyThread2(true, &test_gloabal_a, action, &thread2_result, onThrTerminate);   // создание в остановленном виде
//Thr->Resume();        // запуск

//Thr->WaitFor();      // ждать завершения  -  теряется многопоточность, форма будет заморожена

//delete Thr;   // нельзя! поток будет удалён до его выполнения
}
//---------------------------------------------------------------------------
void __fastcall TForm1::onThrTerminate(TObject *Sender)
{
MemoLog->Lines->Add("end calc a");
if(thread2_errors!="") MemoLog->Lines->Add(thread2_errors);
MemoLog->Lines->Add("a = "+IntToStr(test_gloabal_a));
}
//---------------------------------------------------------------------------
