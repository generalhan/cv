//------------------------------------OK----------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "SkinCtrls.hpp"
#include "SkinData.hpp"
#include "SkinBoxCtrls.hpp"
#include <Mask.hpp>
#include <ComCtrls.hpp>
#include "SkinTabs.hpp"
#include "DynamicSkinForm.hpp"
//------------------------------------------------------------------------------
//-----------------------����� ������-------------------------------------------
//------------------------------------------------------------------------------
const CONSTT=10;
class VECTOR
   {
     public:
        //----------------����������� �� ��������� � ����������-----------------
        VECTOR (int=CONSTT); //CONSTT - ����� ��������� � ������� "�� ���������"
        //------------����������� �����������-----------------------------------
        VECTOR::VECTOR(const VECTOR &V);
        //----------------------------����������--------------------------------
        VECTOR::~VECTOR();
        //----------------------------------------------------------------------
        float show(int i); //��������� ������ ��������� �������
        //---------��������� �������� ������������� �������---------------------
        void PROCPOLE(int i); //i - ������� �������
        //--------------���������� ������� �������------------------------------
        int SHOWPOLE();
        //-----------------��������� pole---------------------------------------
        void POLES(int i);
     private:
        int pole; //pole - ������� �������
        float *vect; //vect - ��������� �� ������������ ���
   };
//------------------------------------------------------------------------------
//-----------------------����� �������------------------------------------------
//------------------------------------------------------------------------------
class MATRICA
   {
     public:
        //----------------����������� �� ��������� � ����������-----------------
        MATRICA (int = CONSTT);//CONSTT-����� ��������� � ������� "�� ���������"
        //------------����������� �����������-----------------------------------
        MATRICA::MATRICA(const MATRICA &M);
        //----------------------------����������--------------------------------
        MATRICA::~MATRICA();
        //----------------------------------------------------------------------
        float show(int i, int j); //��������� ������ ��������� �������
        //---------��������� �������� ������������ �������----------------------
        void PROCPOLE(int i); //i - ������� �������
        //--------------���������� ������� �������------------------------------
        int SHOWPOLE();
        //-----------------��������� pole---------------------------------------
        void POLES(int i);
     private:
        int pole; //pole - ������� �������
        float **matr; //matr - ��������� �� ������������ ���
   };
//------------------------------------------------------------------------------
//-----------------------����� ���������----------------------------------------
//------------------------------------------------------------------------------
class CLASSVECTORS
  {
    private:
     int pole; //pole - ������� �������
     float *VECTORS; //����� �������� ��������� ��������� ������� � �������
    public:
     //--------------------����������� �� ��������� � ����������----------------
     CLASSVECTORS (int = CONSTT); //CONSTT - ����� ��������� "�� ���������"
     //-------------------------------����������--------------------------------
     CLASSVECTORS::~CLASSVECTORS();
     //-------------��������� � ��������� �������-------------------------------
     float show(int k);  //���������� �������� ����
     void POLE(int k, int SUM); //������� ����� �������� � ������
     //------------��������� �������� ������������� �������---------------------
     void PROCPOLE(int i); //i - ������� �������
     //-----------------���������� ������� �������------------------------------
     int SHOWPOLE();
     //-----------------��������� pole------------------------------------------
     void POLES(int i);
     //---------------�������� ������������-------------------------------------
     CLASSVECTORS operator =(float *M)
       {
          for (int i=0;i<CLASSVECTORS::SHOWPOLE();i++)
           {
             CLASSVECTORS::POLE(i,M[i]);
           };
       }
  };
//------------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TspDynamicSkinForm *spDynamicSkinForm1;
        TspSkinData *spSkinData1;
        TspSkinGroupBox *spSkinGroupBox1;
        TspSkinPageControl *spSkinPageControl1;
        TspSkinTabSheet *spSkinTabSheet1;
        TspSkinTabSheet *spSkinTabSheet2;
        TspSkinTabSheet *spSkinTabSheet4;
        TspSkinStdLabel *spSkinStdLabel1;
        TMemo *Memo1;
        TspSkinStdLabel *spSkinStdLabel3;
        TMemo *Memo3;
        TspSkinStdLabel *spSkinStdLabel2;
        TspSkinEdit *spSkinEdit2;
        TMemo *Memo2;
        TspSkinButton *spSkinButton1;
        TMemo *Memo4;
        TMemo *Memo5;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall spSkinButton1Click(TObject *Sender);
        void __fastcall FORMRES(TObject *Sender, int &NewWidth,
          int &NewHeight, bool &Resize);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//------------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//------------------------------------------------------------------------------
