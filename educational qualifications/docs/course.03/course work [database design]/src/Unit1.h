/////////////////////////////////OK/////////////////////////////////////////////
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <stdio.h>
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *StatusBar1;
        TGroupBox *GroupBox1;
        TButton *Button1;
        TGroupBox *GroupBox2;
        TBitBtn *BitBtn1;
        TGroupBox *GroupBox3;
        TButton *Button2;
        TButton *Button5;
        TButton *Button6;
        TButton *Button3;
        TButton *Button4;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TButton *Button9;
        TBitBtn *BitBtn5;
        TBitBtn *BitBtn6;
        TBitBtn *BitBtn7;
        TBitBtn *BitBtn8;
        TImageList *ImageList1;
        TBitBtn *BitBtn9;
        TTreeView *TreeView1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall CHANGE(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall BitBtn8Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall TREEMOUSE(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall TREEKEY(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn9Click(TObject *Sender);
        void __fastcall BitBtn7Click(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
        void __fastcall TreeView1Collapsing(TObject *Sender,
          TTreeNode *Node, bool &AllowCollapse);
        void __fastcall TreeView1Expanding(TObject *Sender,
          TTreeNode *Node, bool &AllowExpansion);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        /////////////////////////////���������, ����������� ����////////////////
        TForm *FORMES; //��������� �� ����
        struct OKN_SP
             {
               HWND HAND; //������������� ����
               OKN_SP * NEXT;
             };
        OKN_SP * FIRST, * worker, * buf ;
        void CLEARWINDOW();  //�������� ���� ���� ������������
/////////////////////////�������� ������////////////////////////////////////////
class TABL_CLASS
 {
   private:
      ///////////////////////��������� �1 ������ ��/////////////////////////////
      struct STRTAB1
       {
        unsigned int COD; //���������� ����� ������
        unsigned int COD_TOVAR2;//��������� �� ������� STRTAB2::COD
        unsigned int COD_TOVAR3; //��������� �� ������� STRTAB3::COD
        unsigned int COD_TOVAR4; //��������� �� ������� STRTAB4::COD
        unsigned int COD_TOVAR5; //��������� �� ������� STRTAB5::COD
        float ROZN;
        float ZAK;
        char DATA[11];   //������ ��� �������� ���� ���� 01.01.1998
        char DATA_SKLAD[11];  //������ ��� �������� ���� ���� 01.01.1998
        unsigned int NAKL; //����� ���������
        unsigned int NUM; //�������� ����� - ���������� �����
       };
      ////////////////////��������� �2 ������ �� - ���������////////////////////
      struct STRTAB2
       {
        unsigned int COD; //���������� ����� ������
        char NAME[256];   //255 ���� - ���������� ����
       };
      ////////////////////��������� �3 ������ �� - �����////////////////////////
      struct STRTAB3
       {
        unsigned int COD; //���������� ����� ������
        char NAME[256];   //255 ����
       };
      ////////////////////��������� �4 ������ �� - ������///////////////////////
      struct STRTAB4
       {
        unsigned int COD; //���������� ����� ������
        char NAME[256];   //255 ����
       };
      ////////////////////��������� �4 ������ �� - ���������////////////////////
      struct STRTAB5
       {
        unsigned int COD; //���������� ����� ������
        char NAME[256];   //255 ����
       };
      ////////////////////��������� ��� ���������� ������///////////////////////
      struct MARK
       {
        int m;
        MARK * NEXT;
       };
      struct KATEGOR
       {
        int k;
        KATEGOR * NEXT;
        MARK * NEXTMARK;
       };
      struct KOREN
       {
        int k;
        KOREN * NEXTKOR;
        KATEGOR * NEXTKAT;
       };
      /////////////////////��������� �� ��������� ������////////////////////////
      KOREN *PK,*PKFIRST, *BUFER3;
      KATEGOR *PKO, *BUFER2;
      MARK *PM, *BUFER1;
      ///////////////////////��� �������� � ��������� ����//////////////////////
      struct INDEXTREE
       {
        int m;
        INDEXTREE * NEXT;
       };
      INDEXTREE *PI,*PIFIRST, *BUF;
      TTreeNode * TN1;
      ///////////////////�������� ������////////////////////////////////////////
      int NDS;
      float DOLLAR;
   public:
      TADOConnection *ADOC; //��� ���������� � ��
      TADOConnection *ADOCI; //��� ���������� � �� (�������������)
      /////////////////////////������� ��///////////////////////////////////////
      TADOTable *ADOT1;     //STRTAB1
      TADOTable *ADOT2;     //STRTAB2
      TADOTable *ADOT3;     //STRTAB3
      TADOTable *ADOT4;     //STRTAB4
      TADOTable *ADOT5;     //STRTAB5
      TADOTable *ADOI;      //BAZA
      /////////////////////////������� ���������////////////////////////////////
      TADOTable *RASH;
      TADOTable *PRIH;     
      TADOTable *PERM;
      //////////////////////������ ������///////////////////////////////////////
      void NOTCONNECT(); //������������� �� ��
      boolean CONNECT(AnsiString Z); //����� ���������� � �� - true - ������ ��
                                     //Z-���������
      boolean TABLE_ACTIV(); //����� ������� ADOTAble ��� ������ � ���������
      void PROC_KATEGOR_ADD(TListBox * LIST, TADOTable * ADOPROC); //��������� � ���� ���������
      void PROC_COMBO_READ(TComboBox *CB, TADOTable *ADOTAB);  //������ �� ������ � "������������ ������"
      /////////////////��������� ������ � ����� ������//////////////////////////
      boolean WRITE_STRTAB1(int CT2, int CT3, int CT4, int CT5,
                         int ROZN, int ZAK, int NAKL, int NUM,
                         AnsiString DATA, AnsiString DATA_SKLAD); 
      int FUNC_STRING_IN_INT(AnsiString S, TADOTable * ADO); //����������� ���� �� �����
      void PROC_DEREVO(TADOTable * ADOTAB, TADOTable * ADOTAB1); //������ ������ �� ������� �1
      void PROC_DEREVO_DELETE(); //������� ������ ����� �������������
      AnsiString FUNC_INT_IN_STRING(int i, TADOTable * ADO); //�� ����� - ���
      void TREE_VIEW(TTreeView * TV);  //�������� ������� �� ���� �������
      int SET_TREE_WINDWOW(TTreeView *TV, TTreeNode * TN1); //������� ������ ����������� ������
      void ADDINDEX(int j);  //��������� � ������ ����� ��� ����������� �� � ����
      void DELETEINDEX(); //������� ������ ����� ��� �����������
      AnsiString TABL_CLASS::GETSKLAD(int j); //����������� ������ ������
      TTreeNode * GETTREENODE(); //���������� ��������� �� TN1
      void SETTREENODE(); //���������� ��� TN1=NULL ��� ��������� ��������
      int GETABSOLUTINDEX(TTreeNode * TNODE); //���������� ���������� ������� ������ � ������
      void SETINDEXTREE(TTreeView *TV); //������������� ������ ���� ��������� �����
      void FIND(TEdit *S1,TEdit *S2,TEdit *S3,TEdit *S4,
                TEdit *S5,TEdit *S6,TEdit *S7,TEdit *S8,
                TEdit *S9,TEdit *S10); //����� ������
      void CHANGESKLAD(TEdit *S1,TEdit *S2,TEdit *S3,TComboBox *CB); //����������� ������ �� ������ �����
      void DELETETOVAR(TEdit * ED1);
      ///////////////////������ ���������///////////////////////////////////////
      void NAKLPERM(int NUM, AnsiString S1);  //S1=����� ����������
      void NAKLPRIH(int NUM, AnsiString S1, AnsiString S2, AnsiString S3,
                    float DOLLAR, int NDS,  float ZAK);
      void NAKLRASH(int NUM, float DOLLAR, int NDS);
      ///////////////////////������/////////////////////////////////////////////
      void OTCHET_PRODAGA(AnsiString S, AnsiString KAT);
      void OTCHET_PRODAGA_ONE(AnsiString S, AnsiString S1);
      void FILESS(FILE * files, AnsiString BD, AnsiString BUFER);
      void LINIA(FILE * files);
      void MESSAGES(FILE * files, AnsiString MES);
      void OTCHET_KATEGOR(AnsiString S, AnsiString KAT);
      void OTCHET_ZAGOLOVOK(FILE * files, AnsiString S);
      /////////////////////����� � ����������� ������///////////////////////////
      void OTCHET_PERM(AnsiString S, int NUM);
      //////////////////////����� � ������� ������//////////////////////////////
      void OTCHET_POKUPKA_ONE(AnsiString S, AnsiString C);
      void OTCHET_POKUPKA(AnsiString S, AnsiString C);
      void OTCHET_POK_KATEGOR(AnsiString S, AnsiString C);
      ////////////////////��� ������ � ��������/////////////////////////////////
      float PROC_DOLLAR();
      int PROC_NDS();
      boolean SETNDSDOLLAR(AnsiString DOL, AnsiString ND);
      //////////////////////������ ��///////////////////////////////////////////
      void IMPORT(TEdit *Edi);
 };
//////////////////////��������� ������//////////////////////////////////////////
TABL_CLASS TBL;
};
extern PACKAGE TForm1 *Form1;

