//////////////////////////////////////////////////////////////////////////
//
//              ������������� ������ �� �3 �� MFC
//              �����: ��������� �.�. ��-31 2006�.
//              ���� ����������: 8.03.2006�.
//
//////////////////////////////////////////////////////////////////////////
#include "afxwin.h" 
#include "math.h "
#include "resource.h" 
#include "Dialog_LAB3.h"
//////////////////////////////////////////////////////////////////////////
#define MAX_PLOSHAD_B 1000 //������������ ������ ������������ ����
#define MAX_PLOSHAD_A 200  //������������ ����� ������������ ����
//////////////////////////////////////////////////////////////////////////
/////////////////////////���������� ����������////////////////////////////
//////////////////////////////////////////////////////////////////////////
int pos_y,pos_x;                       //���������� ��������� ���������
int max_x,max_y;                       //max ��������� ���������
int min;                               //min ��������� ���������
int x_BUF,y_BUF,a,b,delta_y,delta_x;   //���������� ���������� ������� �����				
//////////////////////////////////////////////////////////////////////////
//////////////CPaintDC - ����� ��������� ����������///////////////////////
//////////////////////////////////////////////////////////////////////////
class CPaintDC_LAB3: public CPaintDC
{
    public:
	  //////////////////�����������///////////////////////////////////////
      CPaintDC_LAB3(CWnd* pWnd) : CPaintDC(pWnd)
	  {}
	  /////////////////��������� �� ����������� ����//////////////////////
      void DRAW_LAB3()
	  {
        	int p=0;
            CPen cp;
            CBrush hBr;
            LOGBRUSH lb;
			//////////////////////////////////////////////////////////////
	   	    lb.lbColor=RGB(200,100,10);
            lb.lbStyle=BS_SOLID;
            lb.lbHatch=NULL;
			//////////////////////////��� ��������////////////////////////
			hBr.CreateBrushIndirect(&lb);
		    SelectObject(hBr);
            //////////////////////////////////////////////////////////////
	        cp.CreatePen(NULL,3,RGB(10,78,90));
 	        SelectObject(cp);
	        Arc(-x_BUF+10,-y_BUF+10,-x_BUF+50,-y_BUF+150,p,p,p,p);
			cp.DeleteObject();
			//////////////////////////////////////////////////////////////
	        cp.CreatePen(NULL,8,RGB(100,178,90));
 	        SelectObject(cp);
	        Arc(-x_BUF+100,-y_BUF+100,-x_BUF+150,-y_BUF+150,p,p,p,p);
			cp.DeleteObject();
            //////////////////////////////////////////////////////////////
		    cp.CreatePen(NULL,2,RGB(1,240,90));
 	        SelectObject(cp);
	        Arc(-x_BUF+100,-y_BUF+300,-x_BUF+150,-y_BUF+350,170,170,10,600);
			cp.DeleteObject(); 
			//////////////////////////////////////////////////////////////
		    cp.CreatePen(NULL,3,RGB(200,178,90));
 	        SelectObject(cp);
	        Rectangle(-x_BUF+300,-y_BUF+100,-x_BUF+350,-y_BUF+150);
			cp.DeleteObject();
            //////////////////////////////////////////////////////////////
		    cp.CreatePen(PS_DASHDOT,1,RGB(255,1,255));
 	        SelectObject(cp);
	        Rectangle(-x_BUF+400,-y_BUF+200,-x_BUF+450,-y_BUF+250);
			cp.DeleteObject();
            //////////////////////////////////////////////////////////////
		    cp.CreatePen(PS_DASHDOTDOT,1,RGB(25,1,255));
 	        SelectObject(cp);
	        MoveTo(-x_BUF+0,-y_BUF+0);
            LineTo(-x_BUF+800,-y_BUF+200);
			cp.DeleteObject();
	  }
};
//////////////////////////////////////////////////////////////////////////
/////CFrameWnd - ����� ������������ �������������� ����������� ����/////// 
////////////////////����������� ��������� (SDI)///////////////////////////
class CFrameWnd_LAB3 : public CFrameWnd
{
   private:
     bool flag;
   public:
	CMenu Menu_LAB3; //���� ��� ����
	///////////////////////////////�����������////////////////////////////
 	CFrameWnd_LAB3()
	{
        flag=false;
		Create(
			   NULL,
			   "������������ ������ �3",
			   WS_OVERLAPPEDWINDOW | WS_HSCROLL	| WS_VSCROLL,
			   rectDefault,
		       NULL,
			   NULL
			  );
		Menu_LAB3.LoadMenu(IDR_MENU1);
        SetMenu(&Menu_LAB3);
	};
	//////////////////////////////////////////////////////////////////////
    void LAB3_MENU_FUNC1()
	{
		flag=true;       
		InvalidateRect(NULL,true);      
		UpdateWindow();
	};
	//////////////////////////////////////////////////////////////////////
    void LAB3_MENU_FUNC2()
	{
	    CDialog_LAB3 D;
	    D.DoModal();	
	};
    //////////////////////////////////////////////////////////////////////
	void LAB3_MENU_FUNC3()
	{
	  	DestroyWindow();
	};
	//////////////////////////////////////////////////////////////////////
    void OnPaint()
	{
       CPaintDC_LAB3 dc(this);
       CBrush brush(GetSysColor(COLOR_3DDKSHADOW));
       CRect REC;
       GetClientRect(REC);
       dc.FillRect(REC, &brush);
       if (flag==true)
         	dc.DRAW_LAB3(); 
	};
	//////////////////////////////////////////////////////////////////////
	int OnCreate( LPCREATESTRUCT lpCreateStruct )
	{ 
		   //////////������������� �������� ���������////////////
           max_x=100; 
		   max_y=max_x;
           min=0;     
           SetScrollRange(SB_VERT,min,max_y,TRUE);
		   SetScrollRange(SB_HORZ,min,max_x,TRUE);
           SetScrollPos (SB_VERT,0,TRUE); 
           ///////////�������������� ����������//////////////////
		   y_BUF=0;
		   x_BUF=0;
		   a=MAX_PLOSHAD_A;        //����� ������� ������������� 
		   b=MAX_PLOSHAD_B;        //������ ������� ������������� 
		   delta_y=10;   //������ ������ ������
		   delta_x=10;   //������ ������ �����
		   return 0;
	}
	//////////////////////////////////////////////////////////////////////
	void OnSize( UINT nType, int cx, int cy)
	{
	   if (cx>0 && cy>0)
		   {
             b=ceil((768/cy)*MAX_PLOSHAD_B);  //768 - ���������� �� ��������� ����
		     a=ceil((1024/cy)*MAX_PLOSHAD_A); //1024 - ���������� �� ����������� ����
		   }
	}
	//////////////////////////////////////////////////////////////////////
	void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
	{
       switch(nSBCode)
		   {
              case SB_LINEUP:
			     //////////////���������� ��������///////////////
                 if (pos_y>min)
				 {
                   pos_y=pos_y-1;
				   SetScrollPos(SB_VERT,pos_y,TRUE);
				   y_BUF=ceil(pos_y*(b/max_y)); //��������� ���������� ����� (x_BUF,y_BUF)
				 }
                 break; 
			  case SB_LINEDOWN:
				  if (pos_y<max_y)
				 {
                   pos_y=pos_y+1;
				   SetScrollPos(SB_VERT,pos_y,TRUE);
				   y_BUF=ceil(pos_y*(b/max_y)); //��������� ���������� ����� (x_BUF,y_BUF)
				 }
                 break; 
			  case SB_THUMBTRACK:  //������������ ����������� ��������
				  pos_y=nPos;
				  SetScrollPos(SB_VERT,pos_y,TRUE);
                  y_BUF=ceil(pos_y*(b/max_y));
			  default:
				 break;
		   };
	       //���������� ���� ����������//////////////////////////
		   InvalidateRect(NULL,true);
           UpdateWindow();
	}
	//////////////////////////////////////////////////////////////////////
	void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
	{
       switch(nSBCode)
		   {
              case SB_LINEUP:
			     //////////////���������� ��������///////////////
                 if (pos_x>min)
				 {
                   pos_x=pos_x-1;
				   SetScrollPos(SB_HORZ,pos_x,TRUE);
				   x_BUF=ceil(pos_x*(a/max_x)); //��������� ���������� ����� (x_BUF,y_BUF)
				 }
                 break; 
			  case SB_LINEDOWN:
				 if (pos_x<max_x)
				 {
                   pos_x=pos_x+1;
				   SetScrollPos(SB_HORZ,pos_x,TRUE);
				   x_BUF=ceil(pos_x*(a/max_x)); //��������� ���������� ����� (x_BUF,y_BUF)
				 }
                 break; 
			  case SB_THUMBTRACK:  //������������ ����������� ��������
				 pos_x=nPos;
				 SetScrollPos(SB_HORZ,pos_x,TRUE);
                 x_BUF=ceil(pos_x*(a/max_x));
			  default:
				 break;
		   };
	       ////////////���������� ���� ����������/////////////////////////
		   InvalidateRect(NULL,true);
           UpdateWindow();
	}
   private:
	DECLARE_MESSAGE_MAP();
};
//////////////////////////////////////////////////////////////////////////
/////////////////////////////����� ���������//////////////////////////////
//////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(CFrameWnd_LAB3, CFrameWnd)
    ON_WM_PAINT()
	ON_COMMAND(ID_MENUITEM40001,LAB3_MENU_FUNC2)
	ON_COMMAND(ID_MENUITEM40002,LAB3_MENU_FUNC1)
    ON_COMMAND(ID_MENUITEM40003,LAB3_MENU_FUNC3)
    ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()
//////////////////////////////////////////////////////////////////////////
//CWinApp ����� - ����� �� �������� ���������� ������ ���������� ����/////
//////////////////////////////////////////////////////////////////////////
class CWinApp_LAB3 : public CWinApp
{
  public:
    //////////////////////////////////////////////////////////////////////
	CWinApp_LAB3()
	{};
	//////////////////////////////////////////////////////////////////////
	virtual BOOL InitInstance()
	{
       	m_pMainWnd=new CFrameWnd_LAB3();	
	    ASSERT(m_pMainWnd);
 	    m_pMainWnd->ShowWindow(SW_SHOW);
	    m_pMainWnd->UpdateWindow();	
	    return TRUE;
	}
};
///////////////////////////////////////////////////////////////////////////
CWinApp_LAB3 theApp; //������� ���������� ������ ����������	
