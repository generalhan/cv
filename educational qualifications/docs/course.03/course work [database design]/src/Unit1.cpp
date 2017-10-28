////////////////////////////////+OK+////////////////////////////////////////////
#include <vcl.h>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
#include "Unit9.h"
#include <stdio.h>
#include <dstring.h>;
#pragma hdrstop
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner){}
////////////////////////////////////////////////////////////////////////////////
///////////////////+������� �� ������� ��������� �����+/////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TForm1::CHANGE(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
  TreeView1->Height=Form1->Height-255;
  GroupBox1->Height=Form1->Height-124;
}
////////////////////////////////////////////////////////////////////////////////
///////////////////////+������������� �� ��+////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
  TBL.NOTCONNECT();
  Form1->StatusBar1->Panels->Items[1]->Text= "��� ���������� � ��";
  Form1->BitBtn2->Enabled=false;
  Form1->BitBtn3->Enabled=false;
  Form1->BitBtn4->Enabled=false;
  Form1->BitBtn5->Enabled=false;
  Form1->BitBtn6->Enabled=false;
  Form1->BitBtn7->Enabled=false;
  Form1->BitBtn8->Enabled=false;
  Form1->BitBtn1->Enabled=true;
  GroupBox1->Visible=false;
  Form1->TreeView1->Items->Clear();
  /////////////////////���������� ��� ������ �� ������ ����� ���������//////////
  CLEARWINDOW();  //����� ��������� ���������� ���������� ��� ���� �������
  TBL.SETTREENODE();  //�������� ��������� �� NODE
  TBL.DELETEINDEX(); //������� ������ ����� ��� ��������� ������ ������
}
////////////////////////////////////////////////////////////////////////////////
///////////////////////////+�������������+//////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  Form1->StatusBar1->Panels->Items[1]->Text= "��� ���������� � ��";
  Form1->BitBtn2->Enabled=false;
  Form1->BitBtn3->Enabled=false;
  Form1->BitBtn4->Enabled=false;
  Form1->BitBtn5->Enabled=false;
  Form1->BitBtn6->Enabled=false;
  Form1->BitBtn7->Enabled=false;
  Form1->BitBtn8->Enabled=false;
  GroupBox1->Visible=false;
  Form1->Height=581;
  Form1->Width=905;
  Form1->Top=93;
  Form1->Left=86;
  Form1->FormStyle=fsMDIForm;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////+������ � ������+///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TForm1::TreeView1Collapsing(TObject *Sender,
      TTreeNode *Node, bool &AllowCollapse)
{
   Node->ImageIndex=0;  //�����������
   Node->SelectedIndex=0;
}
void __fastcall TForm1::TreeView1Expanding(TObject *Sender,
      TTreeNode *Node, bool &AllowExpansion)
{
   Node->ImageIndex=1;   //�������������
   Node->SelectedIndex=1;
}
////////////////////////////////////////////////////////////////////////////////
//////////////////////+��������� ���������� � ����� ������+/////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
 Form5->Top=311;
 Form5->Left=307;
 Form5->Edit1->Text="";
 Form5->ShowModal();
 if (TBL.CONNECT(Form5->Edit1->Text) && TBL.TABLE_ACTIV()) //Form5->Edit1->Text=���������
  {
   Form1->StatusBar1->Panels->Items[1]->Text= "�� ��������� � ��: "+Form5->Edit1->Text;
   Form1->BitBtn2->Enabled=true;
   Form1->BitBtn3->Enabled=true;
   Form1->BitBtn4->Enabled=true;
   Form1->BitBtn5->Enabled=true;
   Form1->BitBtn6->Enabled=true;
   Form1->BitBtn7->Enabled=true;
   Form1->BitBtn8->Enabled=true;
   Form1->BitBtn1->Enabled=false;
   GroupBox1->Visible=true;
   Form1->TreeView1->Items->Clear();
   ShowMessage("��� ���������� ��������� �������� ��������� - ���� $ � ���!!!");
  }
 else
  {
    ShowMessage("�� ������� ���������� ����������!");
  };
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::NOTCONNECT()
{
   ADOC->Connected=false;
   ADOT1->Active=false;
   ADOT2->Active=false;
   ADOT3->Active=false;
   ADOT4->Active=false;
   ADOT5->Active=false;
   RASH->Active=false;
   PRIH->Active=false;
   PERM->Active=false;
   ADOC->Destroying();
   ADOT1->Destroying();
   ADOT2->Destroying();
   ADOT3->Destroying();
   ADOT4->Destroying();
   ADOT5->Destroying();
   RASH->Destroying();
   PRIH->Destroying();
   PERM->Destroying();
}
//////////////////////+����� ������+////////////////////////////////////////////
boolean TForm1::TABL_CLASS::CONNECT(AnsiString Z)
{
 try
 {
  AnsiString S;
  S="Provider=MSDASQL.1;Persist Security Info=False;Data Source=";
  S=S+Z;
  ADOC=new TADOConnection(ADOC);
  ADOC->ConnectionString=S;
  ADOC->Provider="MSDASQL.1";
  ADOC->LoginPrompt=false;
  ADOC->Connected=true;
  if (ADOC->Connected)
   {
     return (true);
   }
  else
   {
     return (false);
   }
 }
 catch (...)
  {
  return (false);
  };
};
//////////////////////+����� ������+////////////////////////////////////////////
boolean TForm1::TABL_CLASS::TABLE_ACTIV()
{
 try
 {
  /////////////////������� �1 - �������/////////////////////////////////////////
  ADOT1=new TADOTable(ADOT1);
  ADOT1->TableName="STRTAB1";
  ADOT1->Connection=ADOC;
  ADOT1->Active=true;
  /////////////////������� �2///////////////////////////////////////////////////
  ADOT2=new TADOTable(ADOT2);
  ADOT2->TableName="STRTAB2";
  ADOT2->Connection=ADOC;
  ADOT2->Active=true;
  /////////////////������� �3///////////////////////////////////////////////////
  ADOT3=new TADOTable(ADOT3);
  ADOT3->TableName="STRTAB3";
  ADOT3->Connection=ADOC;
  ADOT3->Active=true;
  /////////////////������� �4///////////////////////////////////////////////////
  ADOT4=new TADOTable(ADOT4);
  ADOT4->TableName="STRTAB4";
  ADOT4->Connection=ADOC;
  ADOT4->Active=true;
  /////////////////������� �5///////////////////////////////////////////////////
  ADOT5=new TADOTable(ADOT5);
  ADOT5->TableName="STRTAB5";
  ADOT5->Connection=ADOC;
  ADOT5->Active=true;
  ///////////////////////���������//////////////////////////////////////////////
  RASH=new TADOTable(RASH);
  RASH->TableName="NAKLADNAARASH";
  RASH->Connection=ADOC;
  RASH->Active=true;
  PRIH=new TADOTable(PRIH);
  PRIH->TableName="NAKLADNAAPRIH";
  PRIH->Connection=ADOC;
  PRIH->Active=true;
  PERM=new TADOTable(PERM);
  PERM->TableName="NAKLADNAAPERM";
  PERM->Connection=ADOC;
  PERM->Active=true;
  //////////////////////////////////////////////////////////////////////////////
  if (ADOT1->Active==true && ADOT2->Active==true && ADOT3->Active==true
      && ADOT4->Active==true && ADOT5->Active==true &&  RASH->Active==true &&
      PRIH->Active==true && PERM->Active==true)
   {
    return (true);
   }
  else
   {
    return (false);
   }
 }
 catch (...)
   {
     return (false);
   };
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////+���������� ��+/////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TForm1::BitBtn8Click(TObject *Sender)
{
 Form4->Edit5->Text="";
 Form4->Edit3->Text="";
 Form4->Edit4->Text="";
 Form4->Label1->Visible=false;
 Form4->Button4->Enabled=true;
 Form4->Button8->Enabled=true;
 Form4->Top=180;
 Form4->Left=319;
 Form4->ListBox1->Clear();
 Form4->ListBox2->Clear();
 Form4->Tag=0;
 Form4->ShowModal();
 switch (Form4->Tag)
  {
   case 1: TBL.PROC_KATEGOR_ADD(Form4->ListBox1,TBL.ADOT2); break;
   case 2: TBL.PROC_KATEGOR_ADD(Form4->ListBox2,TBL.ADOT4); break;
 }
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::PROC_KATEGOR_ADD(TListBox * LIST, TADOTable * ADOPROC)
{
   ADOPROC->Last(); //��������� � ��������� ������
   for (int i=0;i<LIST->Count;i++)
    {
      Variant TRES;
      Variant KeyValues=LIST->Items->Strings[i];
      AnsiString KeyFields="NAME";
      AnsiString Result="NAME";
      TRES=ADOPROC->Lookup(KeyFields,KeyValues,Result);
      if (VarIsNull(TRES))
        {
         ADOPROC->Insert(); //��������� ����� �������
         ADOPROC->FieldByName("NAME")->AsString=LIST->Items->Strings[i];
         ADOPROC->Post();
         ADOPROC->Last();
        }
      else
        ShowMessage("���� �� �������� ������ ��� ���� � �� - ��� �� ����� �������� ��������!");
    };
   ADOPROC->Active=false;
   ADOPROC->Active=true;
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////+������������ ������+///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TForm1::BitBtn5Click(TObject *Sender)
{
  Form2->Edit10->Text="";
  Form2->Edit2->Text="";
  Form2->Edit3->Text="";
  Form2->Edit4->Text="";
  Form2->Edit5->Text="";
  Form2->Edit6->Text="";
  Form2->Edit7->Text="";
  Form2->Edit9->Text="";
  Form2->Tag=0;  //�� ���������� � ����
  Form2->Top=232;
  Form2->Left=339;
  Form2->ComboBox1->Clear();
  Form2->ComboBox2->Clear();
  TBL.PROC_COMBO_READ(Form2->ComboBox1,TBL.ADOT2);
  TBL.PROC_COMBO_READ(Form2->ComboBox2,TBL.ADOT4);
  Form2->ShowModal();
  if (Form2->Tag==1)     
   {
    if (Form2->ComboBox1->Text!="" && Form2->ComboBox2->Text!="")
     {
      int CT2=TBL.FUNC_STRING_IN_INT(Form2->ComboBox1->Text,TBL.ADOT2);
      int CT3=TBL.FUNC_STRING_IN_INT(Form2->Edit4->Text,TBL.ADOT3);
      int CT4=TBL.FUNC_STRING_IN_INT(Form2->ComboBox2->Text,TBL.ADOT4);
      int CT5=TBL.FUNC_STRING_IN_INT(Form2->Edit10->Text,TBL.ADOT5);
      int ROZN=StrToInt(Form2->Edit3->Text);
      int ZAK=StrToInt(Form2->Edit2->Text);
      int NAKL=StrToInt(Form2->Edit6->Text);
      int NUM=StrToInt(Form2->Edit7->Text);
      AnsiString DATA=Form2->Edit5->Text;
      AnsiString DATA_SKLAD=Form2->Edit9->Text;
      if (TBL.WRITE_STRTAB1(CT2,CT3,CT4,CT5,ROZN,ZAK,NAKL,NUM,DATA,DATA_SKLAD)==true)
        {
          TBL.NAKLPRIH(NUM,Form2->ComboBox1->Text,Form2->Edit10->Text,
                    Form2->ComboBox2->Text,TBL.PROC_DOLLAR(),TBL.PROC_NDS(), ZAK);
        }
      else
       {
         ShowMessage("��� ���������� �������� � �� ��������� ������ - �������� �������� ����� ��� ���� � ��!");
       };
     }
    else ShowMessage("�� �� ��������� ���� ��������� ��� �������!");
   };
}
/////////////////////��� �����//////////////////////////////////////////////////
float TForm1::TABL_CLASS::PROC_DOLLAR()
{
  return DOLLAR;
};
int TForm1::TABL_CLASS::PROC_NDS()
{
  return NDS;
};
boolean TForm1::TABL_CLASS::SETNDSDOLLAR(AnsiString DOL, AnsiString ND)
{
 try
  {
    StrToFloat(DOL);
    StrToInt(ND);
    if (StrToInt(ND)>=0 && StrToInt(ND)<101)
     {
      NDS=StrToInt(ND);
      DOLLAR=StrToFloat(DOL);
     }
    else
     return false;
  }
 catch (...)
  {return false;};
};
/////////////////�������������� ��//////////////////////////////////////////////
void TForm1::TABL_CLASS::IMPORT(TEdit *Edi)
{
  AnsiString S;
  S="Provider=MSDASQL.1;Persist Security Info=False;Data Source=";
  S=S+Edi->Text;
  ADOCI=new TADOConnection(ADOCI);
  ADOCI->ConnectionString=S;
  ADOCI->Provider="MSDASQL.1";
  ADOCI->LoginPrompt=false;
  ADOCI->Connected=true;
  if (ADOCI->Connected)
   {
     ADOI=new TADOTable(ADOI);
     ADOI->TableName="BAZA";
     ADOI->Connection=ADOCI;
     ADOI->Active=true;
     //////////////////��� ������///////////////////////////////////////////////
     ADOI->First();
     while (ADOI->Eof==NULL)
      {
       int CT2=FUNC_STRING_IN_INT(ADOI->FieldByName("��������� ������")->AsString,ADOT2);
       int CT3=FUNC_STRING_IN_INT(ADOI->FieldByName("�����")->AsString,ADOT3);
       int CT4=FUNC_STRING_IN_INT(ADOI->FieldByName("�����")->AsString,ADOT4);
       int CT5=FUNC_STRING_IN_INT(ADOI->FieldByName("���������� ������")->AsString,ADOT5);
       float ROZN=ADOI->FieldByName("��������� ����")->AsFloat;
       float ZAK=ADOI->FieldByName("���������� ����")->AsFloat;
       int NAKL=ADOI->FieldByName("����� ���������")->AsInteger;
       int NUM=ADOI->FieldByName("�������� ����� ������")->AsInteger;
       AnsiString DATA=DateToStr(ADOI->FieldByName("���� �������")->AsDateTime);
       AnsiString DATA_SKLAD=DateToStr(ADOI->FieldByName("���� ��������� �������")->AsDateTime);
       if (WRITE_STRTAB1(CT2,CT3,CT4,CT5,ROZN,ZAK,NAKL,NUM,DATA,DATA_SKLAD)==true)
         {
            NAKLPRIH(NUM,ADOI->FieldByName("��������� ������")->AsString,
                         ADOI->FieldByName("���������� ������")->AsString,
                         ADOI->FieldByName("�����")->AsString,
                         PROC_DOLLAR(),PROC_NDS(), ZAK);
         }
        ADOI->Next();
      };
     ShowMessage("������ ���������� ������!");
   }
  else
   {
     ShowMessage("�� ������� ���������� ����������!");
     return;
   }
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::NAKLPRIH(int NUM, AnsiString S1, AnsiString S2,
                                  AnsiString S3, float DOLLAR, int NDS, float ZAK)
{
  PRIH->Insert();
  PRIH->FieldByName("NUM")->AsInteger=NUM;
  float CENA=ZAK;
  float CENA_=CENA*((NDS*0.01)+1);
  PRIH->FieldByName("NDS")->AsFloat=CENA_;
  PRIH->FieldByName("ZAK")->AsFloat=CENA;
  PRIH->FieldByName("DOLLAR")->AsFloat=DOLLAR;
  PRIH->FieldByName("NAIMENOVANIE")->AsString=S1;
  PRIH->FieldByName("VID")->AsString=S2;
  PRIH->FieldByName("SKLAD_POLUCHATEL")->AsString=S3;
  PRIH->Post();
  PRIH->Active=false;
  PRIH->Active=true;
};
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::PROC_COMBO_READ(TComboBox *CB, TADOTable *ADOTAB)
{
  ADOTAB->First();
  while (ADOTAB->Eof==NULL)
     {
       CB->Items->Add(ADOTAB->FieldByName("NAME")->AsString);
       ADOTAB->Next();
     };
};
//////////////////////+����� ������+////////////////////////////////////////////
boolean TForm1::TABL_CLASS::WRITE_STRTAB1(int CT2, int CT3, int CT4, int CT5,
                                       int ROZN, int ZAK, int NAKL, int NUM,
                                       AnsiString DATA, AnsiString DATA_SKLAD)
{
  Variant TRES;
  Variant KeyValues=NUM;
  AnsiString KeyFields="NUM";
  AnsiString Result="NUM";
  TRES=ADOT1->Lookup(KeyFields,KeyValues,Result);
  ///////////////////��������� ��������� ������/////////////////////////////////
  if (VarIsNull(TRES))
   {////////////////////����� ������ ��� - ��������� � ����/////////////////////
    ADOT1->Last();
    ADOT1->Insert(); //��������� ����� �������
    ADOT1->FieldByName("COD_TOVAR2")->AsInteger=CT2;
    ADOT1->FieldByName("COD_TOVAR3")->AsInteger=CT3;
    ADOT1->FieldByName("COD_TOVAR4")->AsInteger=CT4;
    ADOT1->FieldByName("COD_TOVAR5")->AsInteger=CT5;
    ADOT1->FieldByName("ROZN")->AsInteger=ROZN;
    ADOT1->FieldByName("ZAK")->AsInteger=ZAK;
    ADOT1->FieldByName("NAKL")->AsInteger=NAKL;
    ADOT1->FieldByName("NUM")->AsInteger=NUM;
    ADOT1->FieldByName("DATA")->AsString=DATA;
    ADOT1->FieldByName("DATA_SKLAD")->AsString=DATA_SKLAD;
    ADOT1->Post();
    /////////////////////��������� ������///////////////////////////////////////
    ADOT1->Active=false;
    ADOT1->Active=true;
    return (true);
   }
  else
   {
    return (false);
   };
};
//////////////////////+����� ������+////////////////////////////////////////////
int TForm1::TABL_CLASS::FUNC_STRING_IN_INT(AnsiString S, TADOTable * ADO)
{
  Variant TRES;
  Variant KeyValues=S;
  AnsiString KeyFields="NAME";
  AnsiString Result="COD";
  ///////////////////////���� �������� COD//////////////////////////////////////
  int k=0;
  ADO->First();
  while (ADO->Eof==NULL)
   {
     if (ADO->FieldByName("COD")->AsInteger>=k)
      k=ADO->FieldByName("COD")->AsInteger;
     ADO->Next();
   };
  //////////////////////////////////////////////////////////////////////////////
  TRES=ADO->Lookup(KeyFields,KeyValues,Result);
  ///////////////////��������� ��������� ������/////////////////////////////////
  if (VarIsNull(TRES))
   {////////////////////����� ������ ��� - ��������� � ����/////////////////////
    ADO->Insert(); //��������� ����� �������
    ADO->FieldByName("NAME")->AsString=S;
    ADO->Post(); //����������
    ADO->Active=false;
    ADO->Active=true;
    return (k+1);
   }
  else
   {
    return (TRES);
   };
};
//////////////////////+����� ������+////////////////////////////////////////////
AnsiString TForm1::TABL_CLASS::FUNC_INT_IN_STRING(int i, TADOTable * ADO)
{
  Variant TRES;
  Variant KeyValues=i;
  AnsiString KeyFields="COD";
  AnsiString Result="NAME";
  TRES=ADO->Lookup(KeyFields,KeyValues,Result);
  return (TRES);
};
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::PROC_DEREVO_DELETE()
{
  ////////////////////������� �������������/////////////////////////////////////
  PK=PKFIRST;
  BUFER1=NULL;
  while (PK!=NULL)
      {
        PKO=PK->NEXTKAT;
        while (PKO!=NULL)
         {
           /////////////////////////////////////////////////////////////////////
           PM=PKO->NEXTMARK;
           while (PM!=NULL)
             {
               BUFER1=PM->NEXT;
               delete PM;
               PM=BUFER1;
             };
           PKO->NEXTMARK=NULL;
           /////////////////////////////////////////////////////////////////////
           PKO=PKO->NEXT;
         };
        PK=PK->NEXTKOR;
      };
  ///////////////////////������� ����������/////////////////////////////////////
  PK=PKFIRST;
  BUFER2=NULL;
  while (PK!=NULL)
      {
        ////////////////////////////////////////////////////////////////////////
        PKO=PK->NEXTKAT;
        while (PKO!=NULL)
         {
           BUFER2=PKO->NEXT;
           delete PKO;
           PKO=BUFER2;
         };
        PK->NEXTKAT=NULL;
        ////////////////////////////////////////////////////////////////////////
        PK=PK->NEXTKOR;
      };
  /////////////////////////������� �����////////////////////////////////////////
  PK=PKFIRST;
  BUFER3=NULL;
  while (PK!=NULL)
      {
        BUFER3=PK->NEXTKOR;
        delete PK;
        PK=BUFER3;
      };
  delete PK;
  delete PKFIRST;
};
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::PROC_DEREVO(TADOTable * ADOTAB, TADOTable * ADOTAB1)
{
  //////////////////////////������ �����////////////////////////////////////////
  ADOTAB->First();
  while (ADOTAB->Eof==NULL)
    {
      if (PK==NULL)
       {
         PK=new (KOREN);
         PKFIRST=PK;
         PK->k=ADOTAB->FieldByName("COD")->AsInteger;
         PK->NEXTKOR=NULL;
         PK->NEXTKAT=NULL;
         ADOTAB->Next();
       }
      else
       {
         PK->NEXTKOR = new (KOREN);
         PK=PK->NEXTKOR;
         PK->k=ADOTAB->FieldByName("COD")->AsInteger;
         PK->NEXTKOR=NULL;
         PK->NEXTKAT=NULL;
         ADOTAB->Next();
       };
    };
  ///////////////////������ ������ - ���������//////////////////////////////////
  ADOTAB1->First();
  while (ADOTAB1->Eof==NULL)
    {
     int SKL=ADOTAB1->FieldByName("COD_TOVAR4")->AsInteger; //SKL = ����� ������ � ������� �1
     PK=PKFIRST;
     //���� �� ������ ������
     while (PK!=NULL)
      {
        if (SKL==PK->k)
         {//////////////����� ����� � ������ �������////////////////////////////
          if (PK->NEXTKAT==NULL)
           {////////���� � ������ ������ ��� �� ����� ��������� - �� �������////
            PK->NEXTKAT=new(KATEGOR);
            PKO=PK->NEXTKAT;
            PKO->k=ADOTAB1->FieldByName("COD_TOVAR2")->AsInteger;
            PKO->NEXT=NULL;
            PKO->NEXTMARK=new(MARK);
            PM=PKO->NEXTMARK;
            PM->m=ADOTAB1->FieldByName("COD_TOVAR5")->AsInteger;
            PM->NEXT=NULL;
           }
          else
           {//////////��������� ��� ����////////////////////////////////////////
            boolean flag=false;
            PKO=PK->NEXTKAT;
            KATEGOR * buf; //����������
            while (PKO!=NULL)
             {
               if (PKO->k==ADOTAB1->FieldByName("COD_TOVAR2")->AsInteger)
                {
                  flag=true;
                  /////////////////��������� ���� - � �����?////////////////////
                  //////����� ��� ���� ���� �� ���� �����///////////////////////
                  boolean flag_=false;
                  PM=PKO->NEXTMARK;
                  MARK * buf_;
                  while (PM!=NULL)
                      {
                        if (PM->m==ADOTAB1->FieldByName("COD_TOVAR5")->AsInteger)
                         {//////////������ ����� ��� ����///////////////////////
                          flag_=true;
                         }
                        buf_=PM;
                        PM=PM->NEXT;
                      };
                  if (flag_==false)
                    {/////////������ ����� ��� ���//////////////////////////////
                     PM=buf_;
                     PM->NEXT=new(MARK);
                     PM=PM->NEXT;
                     PM->m=ADOTAB1->FieldByName("COD_TOVAR5")->AsInteger;
                     PM->NEXT=NULL;
                    }
                  ///////////////////////END MARK///////////////////////////////
                };
               buf=PKO;
               PKO=PKO->NEXT;
             };
            if (flag==false)
             {////////�� ����� � ������ ���������///////////////////////////////
              PKO=buf;
              PKO->NEXT=new(KATEGOR);
              PKO=PKO->NEXT;
              PKO->k=ADOTAB1->FieldByName("COD_TOVAR2")->AsInteger;
              PKO->NEXT=NULL;
              //////////�.�. ��������� ��� ���, �� � ����� ����� ������/////////
              PKO->NEXTMARK=new(MARK);
              PM=PKO->NEXTMARK;
              PM->m=ADOTAB1->FieldByName("COD_TOVAR5")->AsInteger;
              PM->NEXT=NULL;
             };
           };
         };
        PK=PK->NEXTKOR;
      };
     ADOTAB1->Next();
   };
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////+�������� ��+///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  CLEARWINDOW();  //����� ��������� ���������� ���������� ��� ���� �������
  TBL.SETTREENODE();  //�������� ��������� �� NODE
  TBL.DELETEINDEX(); //������� ������ ����� ��� ��������� ������ ������
  TBL.PROC_DEREVO_DELETE();  //��������� ������, �� �������� �������� �� �����
  /////////////////////�������� ������//////////////////////////////////////////
  TBL.PROC_DEREVO(TBL.ADOT4, TBL.ADOT1);
  TBL.TREE_VIEW(Form1->TreeView1);
};
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::TREE_VIEW(TTreeView * TV)
{
  ADDINDEX(0);
  //////////////////////////////////////////////////////////////////////////////
  TTreeNode * Node1;
  int SKL=0; //������� �������
  int KAT=0;
  int MAR=0;
  int index=0;
  int BUF_KAT=0;
  TV->Items->Clear();
  PK=PKFIRST;
  while (PK!=NULL)
      {
        AnsiString SS=FUNC_INT_IN_STRING(PK->k,ADOT4);
        TV->Items->Add(NULL,SS);
        ////////////////��������� ����������////////////////////////////////////
        PKO=PK->NEXTKAT;
        while (PKO!=NULL)
         {
           AnsiString SS=FUNC_INT_IN_STRING(PKO->k,ADOT2);
           Node1 = TV->Items->Item[BUF_KAT];
           TV->Items->AddChild(Node1,SS);
           /////////////��������� �������������/////////////////////////////////
           PM=PKO->NEXTMARK;
           int PAR=MAR;
           while (PM!=NULL)
             {
               AnsiString SS=FUNC_INT_IN_STRING(PM->m,ADOT5);
               Node1 = TV->Items->Item[KAT+PAR+SKL+1];
               TV->Items->AddChild(Node1,SS);
               PM=PM->NEXT;
               MAR++;
             };
           /////////////////////////////////////////////////////////////////////
           PKO=PKO->NEXT;
           KAT++;
         };
        ////////////////////////////////////////////////////////////////////////
        PK=PK->NEXTKOR;
        SKL++;
        ////////////
        BUF_KAT=SKL+KAT+MAR;
        //////////////////����� ��� �������� � ��������� ����///////////////////
        ADDINDEX(BUF_KAT);
      };
};
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::ADDINDEX(int j)
{
  if (PIFIRST==NULL)
   {
     PIFIRST=new(INDEXTREE);
     PI=PIFIRST;
     PI->m=j;
     PI->NEXT=NULL;
   }
  else
   {
     PI->NEXT=new(INDEXTREE);
     PI=PI->NEXT;
     PI->m=j;
     PI->NEXT=NULL;
   };
};
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::DELETEINDEX()
{
   PI=PIFIRST;
   while (PI!=NULL)
    {
     BUF=PI->NEXT;
     delete PI;
     PI=BUF;
    };
   PI=NULL;
   BUF=NULL;
   PIFIRST=NULL;;
}
//////////////////////+����� ������+////////////////////////////////////////////
AnsiString TForm1::TABL_CLASS::GETSKLAD(int j)
{
 int COUNT=1; //� ��� �� � ����� ��������� 1,2,3,..
 PI=PIFIRST;
 while (PI!=NULL)
  {
    BUF=PI->NEXT;
    if (j>=PI->m && j<BUF->m)
     {
       return (FUNC_INT_IN_STRING(COUNT, ADOT4));
     };
    PI=PI->NEXT;
    COUNT++;
  };
};
////////////////////////////////////////////////////////////////////////////////
///////////////////+�������� � ��������� ����+//////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//////////////////+������� �����, ��������� ����+///////////////////////////////
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 if (Form1->TBL.GETTREENODE()!=NULL)
 {
 ///////////////////////////////////////////////////////////////////////////////
  FORMES= new TForm(Form1);
  FORMES->FormStyle=fsMDIChild;
  FORMES->BorderStyle=bsSizeToolWin;
  if (FIRST==NULL)
   {
     FIRST = new (OKN_SP);
     worker = FIRST;
     worker->HAND = FORMES->Handle;
     worker->NEXT=NULL;
     /////////////////////������� ������ ���������//////////////////////////////
     TTreeView * TV = new TTreeView(Form1);
     TV->Parent=FORMES;
     TV->Align=alClient;
     TV->Color=cl3DLight;
     TBL.SET_TREE_WINDWOW(TV,TBL.GETTREENODE());
     FORMES->Caption=TBL.GETSKLAD(TBL.GETABSOLUTINDEX(TBL.GETTREENODE()));
   }
  else
   {
     worker->NEXT = new (OKN_SP);
     worker=worker->NEXT;
     worker->HAND= FORMES->Handle;
     worker->NEXT=NULL;
     /////////////////////������� ������ ���������//////////////////////////////
     TTreeView * TV = new TTreeView(Form1);
     TV->Parent=FORMES;
     TV->Align=alClient;
     TV->Color=cl3DLight;
     TBL.SET_TREE_WINDWOW(TV,TBL.GETTREENODE());
     FORMES->Caption=TBL.GETSKLAD(TBL.GETABSOLUTINDEX(TBL.GETTREENODE()));
   };
 ///////////////////////////////////////////////////////////////////////////////
 }
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::SETINDEXTREE(TTreeView *TV)
{
  TN1=TV->Selected;
}
//////////////////////+����� ������+////////////////////////////////////////////
int TForm1::TABL_CLASS::GETABSOLUTINDEX(TTreeNode * TNODE)
{
  return TNODE->AbsoluteIndex;
}
//////////////////////+����� ������+////////////////////////////////////////////
TTreeNode * TForm1::TABL_CLASS::GETTREENODE()
{
  return TN1;
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::SETTREENODE()
{
  TN1=NULL;
}
//////////////////////+����� ������+////////////////////////////////////////////
int TForm1::TABL_CLASS::SET_TREE_WINDWOW(TTreeView *TV, TTreeNode * TN1)
{
  TTreeNode * Node1;
  int SKL=0; //������� �������
  int KAT=0;
  int MAR=0;
  int index=0;
  int BUF_KAT=0;
  TV->Items->Clear();
  PK=PKFIRST;
  while (PK!=NULL)
      {
      if (FUNC_STRING_IN_INT(GETSKLAD(TN1->AbsoluteIndex), ADOT4)==PK->k)
       {
        AnsiString SS=FUNC_INT_IN_STRING(PK->k,ADOT4);
        TV->Items->Add(NULL,SS);
        ////////////////��������� ����������////////////////////////////////////
        PKO=PK->NEXTKAT;
        while (PKO!=NULL)
         {
           AnsiString SS=FUNC_INT_IN_STRING(PKO->k,ADOT2);
           Node1 = TV->Items->Item[BUF_KAT];
           TV->Items->AddChild(Node1,SS);
           /////////////��������� �������������/////////////////////////////////
           PM=PKO->NEXTMARK;
           int PAR=MAR;
           while (PM!=NULL)
             {
               AnsiString SS=FUNC_INT_IN_STRING(PM->m,ADOT5);
               Node1 = TV->Items->Item[KAT+PAR+SKL+1];
               TV->Items->AddChild(Node1,SS);
               PM=PM->NEXT;
               MAR++;
             };
           /////////////////////////////////////////////////////////////////////
           PKO=PKO->NEXT;
           KAT++;
         };
        ////////////////////////////////////////////////////////////////////////
       SKL++;
       ////////////
       BUF_KAT=SKL+KAT+MAR;
       }
       PK=PK->NEXTKOR;
      };
};
///////////////////+������������ ����+//////////////////////////////////////////
void __fastcall TForm1::Button6Click(TObject *Sender)
{
  Form1->Cascade();
}
void __fastcall TForm1::Button9Click(TObject *Sender)
{
 Form1->Tile();
}
///////////////////+������� � ���������� ����+//////////////////////////////////
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Form1->Next();
}
///////////////////+������� � ����������� ����+/////////////////////////////////
void __fastcall TForm1::Button4Click(TObject *Sender)
{
 Form1->Previous();
}
/////////////////////////////+�������� ����+////////////////////////////////////
void __fastcall TForm1::Button5Click(TObject *Sender)
{
   //////////����� Form1->MDIChildren[0] - MDI ����, ������� ����� �����////////
   if (FIRST!=NULL) //���� ���� ������
   {
    if (FIRST->NEXT!=NULL) //���� ����� ��������� ������ >1
    {
     worker=FIRST;
     buf=NULL;
     boolean flag=false;
     /////////////////���� ������ ������� ������////////////////////////////////
     while (worker!=NULL && flag!=true)
        if (Form1->MDIChildren[0]->Handle == worker->HAND)
         {
           flag=true;
         }
        else
         {
          buf = worker;
          worker=worker->NEXT;
         };
     ///////////worker = ����, ������� ������������ ����� �������///////////////
     if (flag==true)
       {
        if (buf != NULL) //���� ��������� ������� �� ������
          {
           buf->NEXT=worker->NEXT; //������������ ���������
           delete worker; //����������� ������ �� ��� ����
          }
         else //���� ��������� ������� ������
          {
            FIRST=worker->NEXT;
            delete worker;
          };
        delete(Form1->MDIChildren[0]);
       };
     ///////////////////////////////////////////////////////////////////////////
    }
    else //���� � ������ ����� ���� �������
     {
      worker=FIRST;
      delete worker;
      delete(Form1->MDIChildren[0]);
      FIRST=NULL;
     };
   };
}
///////////////////�������, ����������� ��� ������ �� ���������/////////////////
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  CLEARWINDOW();
}
///////////////////��������� �������� ���� ����/////////////////////////////////
void TForm1::CLEARWINDOW()
{
     worker=FIRST;
     buf=NULL;
     while (worker!=NULL)
       {
            buf = worker->NEXT;
            delete worker;
            delete(Form1->MDIChildren[0]);
            worker=buf;
       };
     FIRST=NULL;
     buf=NULL;
}
///�������, ����������� ��� ������ ������ ��� ����������� ��� � ��������� ����//
void __fastcall TForm1::TREEMOUSE(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
 TBL.SETINDEXTREE(Form1->TreeView1);
}
void __fastcall TForm1::TREEKEY(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 TBL.SETINDEXTREE(Form1->TreeView1);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////+����� ������ �� ��������� ������+//////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
  Form6->Edit1->Text="";
  Form6->Edit2->Text="";
  Form6->Edit3->Text="";
  Form6->Edit4->Text="";
  Form6->Edit5->Text="";
  Form6->Edit6->Text="";
  Form6->Edit7->Text="";
  Form6->Edit8->Text="";
  Form6->Edit9->Text="";
  Form6->Edit10->Text="";   
  Form6->Left=290;
  Form6->Top=241;
  Form6->ShowModal();
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::FIND(TEdit *S1,TEdit *S2,TEdit *S3,TEdit *S4,
                              TEdit *S5,TEdit *S6,TEdit *S7,TEdit *S8,
                              TEdit *S9,TEdit *S10)
{
  ADOT1->First();
  while (ADOT1->Eof==NULL)
    {/////////////���� �� ������� �1////////////////////////////////////////////
     if (ADOT1->FieldByName("NUM")->AsInteger==StrToInt(S1->Text))
       {//////////����� ������//////////////////////////////////////////////////
        S2->Text=FUNC_INT_IN_STRING(ADOT1->FieldByName("COD_TOVAR2")->AsInteger,ADOT2);
        S3->Text=FUNC_INT_IN_STRING(ADOT1->FieldByName("COD_TOVAR5")->AsInteger,ADOT5);
        S4->Text=FUNC_INT_IN_STRING(ADOT1->FieldByName("COD_TOVAR3")->AsInteger,ADOT3);
        S5->Text=FUNC_INT_IN_STRING(ADOT1->FieldByName("COD_TOVAR4")->AsInteger,ADOT4);
        S6->Text=ADOT1->FieldByName("NAKL")->AsInteger;
        S7->Text=ADOT1->FieldByName("DATA")->AsString;
        S8->Text=ADOT1->FieldByName("DATA_SKLAD")->AsString;
        S9->Text=ADOT1->FieldByName("ZAK")->AsInteger;
        S10->Text=ADOT1->FieldByName("ROZN")->AsInteger;
       };
     ADOT1->Next();
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////+HELP+//////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TForm1::BitBtn9Click(TObject *Sender)
{
 Form7->Left=247;
 Form7->Top=141;
 Form7->ShowModal();
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////+����������� ������+////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TForm1::BitBtn7Click(TObject *Sender)
{
 Form8->Edit1->Text="";
 Form8->Edit2->Text="";
 Form8->Edit3->Text="";
 Form8->Left=294;
 Form8->Top=268;
 Form8->ComboBox1->Clear();
 TBL.PROC_COMBO_READ(Form8->ComboBox1,TBL.ADOT4);
 Form8->ShowModal();
 try
 {
  TDateTime dtDate = StrToDate(Form8->Edit3->Text);
  if ((StrToInt(Form8->Edit1->Text)) && (Form8->Edit1->Text!="") &&
      (StrToInt(Form8->Edit2->Text)) && Form8->ComboBox1->Text!="")
   {///////////������������ ���� ������ ������//////////////////////////////////
    TBL.NAKLPERM(StrToInt(Form8->Edit1->Text), Form8->ComboBox1->Text); //�� ������ ������ ������ � ����� �����
    TBL.CHANGESKLAD(Form8->Edit1,Form8->Edit2,Form8->Edit3,Form8->ComboBox1);
   }
 }
 catch (...)
  {ShowMessage("�� ���������� ����� ��������!");}
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::NAKLPERM(int NUM, AnsiString S1)
{
  ADOT1->First();
  while (ADOT1->Eof==NULL)
    {///////////////////////����� �� ��������� ������///////////////////////////
    if (ADOT1->FieldByName("NUM")->AsInteger==NUM)
      {
        PERM->Insert();
        PERM->FieldByName("NUM")->AsInteger=NUM;
        PERM->FieldByName("NAIMENOVANIE")->AsString=
          FUNC_INT_IN_STRING(ADOT1->FieldByName("COD_TOVAR2")->AsInteger,ADOT2);
        PERM->FieldByName("VID")->AsString=
          FUNC_INT_IN_STRING(ADOT1->FieldByName("COD_TOVAR5")->AsInteger,ADOT5);
        PERM->FieldByName("SKLAD_POL")->AsString=S1;
        PERM->FieldByName("SKLAD_OTPR")->AsString=
          FUNC_INT_IN_STRING(ADOT1->FieldByName("COD_TOVAR4")->AsInteger,ADOT4);
        PERM->Post();
        PERM->Active=false;
        PERM->Active=true;
        return; //���������� 23.12.2005
      };
    ADOT1->Next();
    };
};
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::CHANGESKLAD(TEdit *S1,TEdit *S2,TEdit *S3,TComboBox *CB)
{
  ADOT1->First();
  while (ADOT1->Eof==NULL)
    {/////////////���� �� ������� �1////////////////////////////////////////////
     if (ADOT1->FieldByName("NUM")->AsInteger==StrToInt(S1->Text))
       {//////////����� ������//////////////////////////////////////////////////
        ADOT1->Edit();
        ADOT1->FieldByName("COD_TOVAR4")->AsInteger=FUNC_STRING_IN_INT(CB->Text, ADOT4);
        ADOT1->FieldByName("NAKL")->AsInteger=StrToInt(S2->Text);
        ADOT1->FieldByName("DATA_SKLAD")->AsString=S3->Text;
        ADOT1->Post();
        ADOT1->Active=false;
        ADOT1->Active=true;
        return;  //���������� 23.12.2005
       };
     ADOT1->Next();
    }
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////+������� ������+////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TForm1::BitBtn6Click(TObject *Sender)
{
  Form9->Edit1->Text="";
  Form9->Left=327;
  Form9->Top=326;
  Form9->ShowModal();
  try
   {
    StrToInt(Form9->Edit1->Text);
    TBL.NAKLRASH(StrToInt(Form9->Edit1->Text),TBL.PROC_DOLLAR(),TBL.PROC_NDS()); //����� ��� ��� ������� - �������� ���������
    TBL.DELETETOVAR(Form9->Edit1);
   }
  catch (...)
   {ShowMessage("��� ������ �������� ������!");};
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::NAKLRASH(int NUM, float DOLLAR, int NDS)
{
  boolean FLAG=false;
  ADOT1->First();
  while (ADOT1->Eof==NULL)
    {///////////////////////����� �� ��������� ������///////////////////////////
    if (ADOT1->FieldByName("NUM")->AsInteger==NUM)
        {
           RASH->Insert();
           RASH->FieldByName("NUM")->AsInteger=NUM;
           float CENA=ADOT1->FieldByName("ROZN")->AsFloat;
           float CENA_=CENA*((NDS*0.01)+1);
           RASH->FieldByName("NDS")->AsFloat=CENA_;
           RASH->FieldByName("ROZN")->AsFloat=CENA;
           RASH->FieldByName("DOLLAR")->AsFloat=DOLLAR;
           RASH->FieldByName("NAIMENOVANIE")->AsString=
             FUNC_INT_IN_STRING(ADOT1->FieldByName("COD_TOVAR2")->AsInteger,ADOT2);
           RASH->FieldByName("VID")->AsString=
             FUNC_INT_IN_STRING(ADOT1->FieldByName("COD_TOVAR5")->AsInteger,ADOT5);
           RASH->FieldByName("SKLAD_OTPRAVITEL")->AsString=
             FUNC_INT_IN_STRING(ADOT1->FieldByName("COD_TOVAR4")->AsInteger,ADOT4);
           RASH->Post();
           RASH->Active=false;
           RASH->Active=true;
           FLAG=true;
           return;  //���������� 23.12.2005
        };
    ADOT1->Next();
    };
  if (FLAG==false)
   {ShowMessage("������ � ������ �������� ������� ��� � ��!");};
};
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::DELETETOVAR(TEdit * ED1)
{
  ADOT1->First();
  while (ADOT1->Eof==NULL)
    {/////////////���� �� ������� �1////////////////////////////////////////////
     if (ADOT1->FieldByName("NUM")->AsInteger==StrToInt(ED1->Text))
       {
        ADOT1->Delete();
        ADOT1->Active=false;
        ADOT1->Active=true;
        return;
       };
     ADOT1->Next();
    }
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////+���������� ��������+///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
 Form3->Edit1->Text="";
 Form3->ComboBox5->Text="";
 Form3->Edit3->Text="";
 Form3->ComboBox6->Text="";
 Form3->Edit4->Text="";
 Form3->Edit2->Text="";
 Form3->RadioButton11->Checked=true;
 Form3->RadioButton14->Checked=true;
 Form3->RadioButton6->Checked=true;
 Form3->Label13->Visible=true;
 Form3->Edit1->Visible=true;
 Form3->RadioButton8->Checked=true;
 Form3->Label15->Visible=true;
 Form3->Edit3->Visible=true;
 Form3->Edit4->Visible=true;
 Form3->Top=143;
 Form3->Left=211;
 Form3->ComboBox5->Clear();
 Form3->ComboBox6->Clear();
 TBL.PROC_COMBO_READ(Form3->ComboBox5,TBL.ADOT2);
 TBL.PROC_COMBO_READ(Form3->ComboBox6,TBL.ADOT2);
 Form3->Show();
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::FILESS(FILE * files, AnsiString BD, AnsiString BUFER)
{
   char HTML[1000];
   AnsiString BUF;
   BUF="<h3>";
   BUF=BUF+BUFER;
   BUF=BUF+BD;
   StrCopy(HTML,BUF.c_str());
   int LEN=strlen(HTML);
   fseek(files, 0, SEEK_END);
   fwrite(&HTML, LEN, 1, files);
   //////////////////////////
   BUF="</h3>";
   StrCopy(HTML,BUF.c_str());
   LEN=strlen(HTML);
   fseek(files, 0, SEEK_END);
   fwrite(&HTML, LEN, 1, files);
};
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::LINIA(FILE * files)
{
  char HTML[1000];
  AnsiString BUF="<hr size=4>";
  StrCopy(HTML,BUF.c_str());
  int LEN=strlen(HTML);
  fseek(files, 0, SEEK_END);
  fwrite(&HTML, LEN, 1, files);
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::MESSAGES(FILE * files, AnsiString MES)
{
   char HTML[1000];
   AnsiString BUF;
   BUF="<h3>";
   BUF=BUF+MES;
   StrCopy(HTML,BUF.c_str());
   int LEN=strlen(HTML);
   fseek(files, 0, SEEK_END);
   fwrite(&HTML, LEN, 1, files);
   //////////////////////////
   BUF="</h3>";
   StrCopy(HTML,BUF.c_str());
   LEN=strlen(HTML);
   fseek(files, 0, SEEK_END);
   fwrite(&HTML, LEN, 1, files);
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::OTCHET_ZAGOLOVOK(FILE * files, AnsiString S)
{
  char HTML[1000];
  StrCopy(HTML,"<html>");
  int LEN=strlen(HTML);
  fseek(files, 0, SEEK_END);
  fwrite(&HTML, LEN, 1, files);
  //////////////////////////
  StrCopy(HTML,"<body bgcolor=20B2AA>");
  LEN=strlen(HTML);
  fseek(files, 0, SEEK_END);
  fwrite(&HTML, LEN, 1, files);
  //////////////////////////
  AnsiString SS="<h1 align=center>";
  SS=SS+S;
  SS=SS+"</h1>";
  StrCopy(HTML,SS.c_str());
  LEN=strlen(HTML);
  fseek(files, 0, SEEK_END);
  fwrite(&HTML, LEN, 1, files);
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::OTCHET_PRODAGA(AnsiString S, AnsiString KAT)
{
  FILE * files;
  AnsiString F=S;
  F=F+".html";
  if ((files=fopen(F.c_str(), "w"))==NULL)
    {
      ShowMessage("���������� ������� ����!");
      return;
    };
  //������� ���� � �������
  //////////////////////////////////////////////////////////////////////////////
  OTCHET_ZAGOLOVOK(files,"����� �� ������� ������� �� ��������� � ����");
  //////////////////////////////////////////////////////////////////////////////
  RASH->First();
  while (RASH->Eof==NULL)
    {
     if (RASH->FieldByName("NAIMENOVANIE")->AsString==KAT)
       {
        FILESS(files,RASH->FieldByName("NUM")->AsString,"�������� ����� ������: ");
        FILESS(files,RASH->FieldByName("NAIMENOVANIE")->AsString,"��������� ������: ");
        FILESS(files,RASH->FieldByName("VID")->AsString,"��� ������: ");
        FILESS(files,RASH->FieldByName("ROZN")->AsString,"��������� ���� ������: ");
        FILESS(files,RASH->FieldByName("NDS")->AsString,"��������� ���� ������ � ������ ���: ");
        FILESS(files,RASH->FieldByName("DOLLAR")->AsString,"���� $: ");
        FILESS(files,RASH->FieldByName("SKLAD_OTPRAVITEL")->AsString,"����� �����������: ");
        LINIA(files);
       }
     RASH->Next();
    };
  //////////////////////////////////////////////////////////////////////////////
  fclose(files);
  ShellExecute(NULL,"open",F.c_str(),NULL,NULL,SW_MAXIMIZE); //��������� ���� � �������
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::OTCHET_PRODAGA_ONE(AnsiString S, AnsiString S1)
{
  FILE * files;AnsiString F=S;F=F+".html";
  if ((files = fopen(F.c_str(), "w"))==NULL)
    {
      ShowMessage("���������� ������� ����!");
      return;
    };
  //////////////////////////////////////////////////////////////////////////////
  OTCHET_ZAGOLOVOK(files,"����� �� ������� ������ �� ��������� ������");
  //////////////////////////////////////////////////////////////////////////////
  RASH->First();
  while (RASH->Eof==NULL)
    {
     if (RASH->FieldByName("NUM")->AsString==StrToInt(S1))
       {
        FILESS(files,RASH->FieldByName("NUM")->AsString,"�������� ����� ������: ");
        FILESS(files,RASH->FieldByName("NAIMENOVANIE")->AsString,"��������� ������: ");
        FILESS(files,RASH->FieldByName("VID")->AsString,"��� ������: ");
        FILESS(files,RASH->FieldByName("ROZN")->AsString,"��������� ���� ������: ");
        FILESS(files,RASH->FieldByName("NDS")->AsString,"��������� ���� ������ � ������ ���: ");
        FILESS(files,RASH->FieldByName("DOLLAR")->AsString,"���� $: ");
        FILESS(files,RASH->FieldByName("SKLAD_OTPRAVITEL")->AsString,"����� �����������: ");
        LINIA(files);
       }
     RASH->Next();
    };
  //////////////////////////////////////////////////////////////////////////////
  fclose(files);
  ShellExecute(NULL,"open",F.c_str(),NULL,NULL,SW_MAXIMIZE); //��������� ���� � �������
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::OTCHET_KATEGOR(AnsiString S, AnsiString KAT)
{
  FILE * files;AnsiString F=S;F=F+".html";
  if ((files = fopen(F.c_str(), "w"))==NULL)
    {
      ShowMessage("���������� ������� ����!");
      return;
    };
  OTCHET_ZAGOLOVOK(files,"����� �� ������� ������� �� ���������");
  FILESS(files,KAT,"��������� ������: ");
  //////////////////////////////////////////////////////////////////////////////
  RASH->First();
  int j=0;
  while (RASH->Eof==NULL)
    {
     if (RASH->FieldByName("NAIMENOVANIE")->AsString==KAT)
       {
        FILESS(files,RASH->FieldByName("VID")->AsString,"��� ������: ");
        j++;
       }
     RASH->Next();
    };
  ////////////////////���������� ���������� ������//////////////////////////////
  AnsiString I;
  I="���� ������� �����: ";
  I=I+VarToStr(j);
  I=I+" ��.";
  MESSAGES(files,I);
  //////////////////////////////////////////////////////////////////////////////
  fclose(files);
  ShellExecute(NULL,"open",F.c_str(),NULL,NULL,SW_MAXIMIZE); //��������� ���� � �������
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::OTCHET_PERM(AnsiString S, int NUM)
{
  FILE * files;AnsiString F=S;F=F+".html";
  if ((files = fopen(F.c_str(), "w"))==NULL)
    {
      ShowMessage("���������� ������� ����!");
      return;
    };
  OTCHET_ZAGOLOVOK(files,"����� �� ����������� ������ �� �������");
  /////////////������� ������������ ������//////////////////////////////////////
  PERM->First();
  while (PERM->Eof==NULL)
    {
     if (PERM->FieldByName("NUM")->AsInteger==NUM)
       {
        FILESS(files,PERM->FieldByName("NAIMENOVANIE")->AsString,"��������� ������: ");
        FILESS(files,PERM->FieldByName("VID")->AsString,"��� ������: ");
        PERM->Last();
       }
     PERM->Next();
    };
  LINIA(files);
  /////////////////������� ���� �� �������//////////////////////////////////////
  AnsiString PUT;
  int p=0;
  PERM->First();
  while (PERM->Eof==NULL)
    {
     if (PERM->FieldByName("NUM")->AsInteger==NUM)
       {
        p++;
        PUT="����������� �";
        PUT=PUT+VarToStr(p);
        MESSAGES(files,PUT);
        FILESS(files,PERM->FieldByName("SKLAD_OTPR")->AsString,"��������� �� ������: ");
        FILESS(files,PERM->FieldByName("SKLAD_POL")->AsString,"����������� �� �����: ");
       }
     PERM->Next();
    };
  fclose(files);
  ShellExecute(NULL,"open",F.c_str(),NULL,NULL,SW_MAXIMIZE); //��������� ���� � �������
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::OTCHET_POKUPKA_ONE(AnsiString S, AnsiString C)
{
  FILE * files;AnsiString F=S;F=F+".html";
  if ((files = fopen(F.c_str(), "w"))==NULL)
    {
      ShowMessage("���������� ������� ����!");
      return;
    };
  //////////////////////////////////////////////////////////////////////////////
  OTCHET_ZAGOLOVOK(files,"����� �� ������� ������ �� ��������� ������");
  //////////////////////////////////////////////////////////////////////////////
  PRIH->First();
  while (PRIH->Eof==NULL)
    {
     if (PRIH->FieldByName("NUM")->AsString==StrToInt(C))
       {
        FILESS(files,PRIH->FieldByName("NUM")->AsString,"�������� ����� ������: ");
        FILESS(files,PRIH->FieldByName("NAIMENOVANIE")->AsString,"��������� ������: ");
        FILESS(files,PRIH->FieldByName("VID")->AsString,"��� ������: ");
        FILESS(files,PRIH->FieldByName("ZAK")->AsString,"���������� ���� ������: ");
        FILESS(files,PRIH->FieldByName("NDS")->AsString,"���������� ���� ������ � ������ ���: ");
        FILESS(files,PRIH->FieldByName("DOLLAR")->AsString,"���� $: ");
        FILESS(files,PRIH->FieldByName("SKLAD_POLUCHATEL")->AsString,"����� ����������: ");
        LINIA(files);
       }
     PRIH->Next();
    };
  //////////////////////////////////////////////////////////////////////////////
  fclose(files);
  ShellExecute(NULL,"open",F.c_str(),NULL,NULL,SW_MAXIMIZE); //��������� ���� � �������
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::OTCHET_POKUPKA(AnsiString S, AnsiString C)
{
  FILE * files;
  AnsiString F=S;
  F=F+".html";
  if ((files = fopen(F.c_str(), "w"))==NULL)
    {
      ShowMessage("���������� ������� ����!");
      return;
    };
  OTCHET_ZAGOLOVOK(files,"����� �� ������� ������� �� ��������� � ����");
  PRIH->First();
  while (PRIH->Eof==NULL)
    {
     if (PRIH->FieldByName("NAIMENOVANIE")->AsString==C)
       {
        FILESS(files,PRIH->FieldByName("NUM")->AsString,"�������� ����� ������: ");
        FILESS(files,PRIH->FieldByName("NAIMENOVANIE")->AsString,"��������� ������: ");
        FILESS(files,PRIH->FieldByName("VID")->AsString,"��� ������: ");
        FILESS(files,PRIH->FieldByName("ZAK")->AsString,"���������� ���� ������: ");
        FILESS(files,PRIH->FieldByName("NDS")->AsString,"���������� ���� ������ � ������ ���: ");
        FILESS(files,PRIH->FieldByName("DOLLAR")->AsString,"���� $: ");
        FILESS(files,PRIH->FieldByName("SKLAD_POLUCHATEL")->AsString,"����� ����������: ");
        LINIA(files);
       }
     PRIH->Next();
    };
  fclose(files);
  ShellExecute(NULL,"open",F.c_str(),NULL,NULL,SW_MAXIMIZE); //��������� ���� � �������
}
//////////////////////+����� ������+////////////////////////////////////////////
void TForm1::TABL_CLASS::OTCHET_POK_KATEGOR(AnsiString S, AnsiString C)
{
  FILE * files;AnsiString F=S;F=F+".html";
  if ((files = fopen(F.c_str(), "w"))==NULL)
    {
      ShowMessage("���������� ������� ����!");
      return;
    };
  OTCHET_ZAGOLOVOK(files,"����� �� ������� ������� �� ���������");
  FILESS(files,C,"��������� ������: ");
  //////////////////////////////////////////////////////////////////////////////
  PRIH->First();
  int j=0;
  while (PRIH->Eof==NULL)
    {
     if (PRIH->FieldByName("NAIMENOVANIE")->AsString==C)
       {
        FILESS(files,PRIH->FieldByName("VID")->AsString,"��� ������: ");
        j++;
       }
     PRIH->Next();
    };
  ////////////////////���������� ���������� ������//////////////////////////////
  AnsiString I;
  I="���� ������� �����: ";
  I=I+VarToStr(j);
  I=I+" ��.";
  MESSAGES(files,I);
  //////////////////////////////////////////////////////////////////////////////
  fclose(files);
  ShellExecute(NULL,"open",F.c_str(),NULL,NULL,SW_MAXIMIZE); //��������� ���� � �������
}




