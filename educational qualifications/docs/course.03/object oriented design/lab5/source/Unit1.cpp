#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include <stdlib.h>
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner){}
////////////////////////////������� ������//////////////////////////////////////
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  PAS.VIEW(ScrollBox1);
}
/////////////////////��������� �������//////////////////////////////////////////
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  PAS.RASKLAD(ScrollBox1);
  Button2->Enabled=false;
  Button1->Enabled=false;
}

