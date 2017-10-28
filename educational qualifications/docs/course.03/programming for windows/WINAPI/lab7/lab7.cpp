//////////////////////////////////////////////////////////////////////////
//
//              ������������� ������ �� �7 �� WinApi
//              �����: ��������� �.�. ��-31 2006�.
//              ���� ����������: 15.03.2006�.
//
//////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "math.h "
#include "resource.h"
#include "COMMDLG.H"
#define SCREEN_X 2024   //��� �������� HBITMAP � hdcmem - ������ ��� ����� ��������
#define SCREEN_Y 2784   //����������� ������ ����������� ������� 
                        //SCREEN_Y-MAX_PLOSHAD_B>784 (784 - ���������� �� ���������)
#define MAX_LOADSTRING 100
//����������� ���� - �� ����, ������� �� ������ ����������� ����������� � Windows ����
#define MAX_PLOSHAD_B 2000 //������������ ������ ������������ ����
#define MAX_PLOSHAD_A 1000  //������������ ����� ������������ ����
//////////////////////////////////////////////////////////////////////////
/////////////////////////���������� ����������////////////////////////////
//////////////////////////////////////////////////////////////////////////
int pos_y,pos_x;                       //���������� ��������� ���������
int max_x,max_y;                       //max ��������� ���������
int min;                               //min ��������� ���������
int x_BUF,y_BUF,a,b,delta_y,delta_x;   //���������� ���������� ������� �����
HINSTANCE hInst;					   //��������� ���������� ����� ���������		
TCHAR szTitle[MAX_LOADSTRING];	       //��������� ����						
TCHAR szWindowClass[MAX_LOADSTRING];   //��������� �� ������������������ ��� ������	
HWND hWnd; //���������� ������������� ����
bool MOUSE_UP_HDC; //����� ��� ��������� �����
HBITMAP hb,hb2; //������ ��� ����� �������� � ��������� ������ - �������� hb,hb2
HDC hdcmem,      //����� - � ������� ������������ ��� ������� ������
    hdcmem2;     //����� - � ������� ���� ������ ������
int xPos,yPos,xTec,yTec; //���������� ��� ������� ���� � ������� ����������	
COLORREF CR;         //����, ������� ������ ������������
int FIGURA; //1-�������������,2-����������,3-������	
//////////////////////////////////////////////////////////////////////////
////////////////////��������� ���������� �������//////////////////////////
//////////////////////////////////////////////////////////////////////////
ATOM				LAB7_RegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int); 
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
void PRINT_IMAGE(HDC hd); //����������� ���� �����
void RECT_HDCMEM();   //������ �������������� � ������
void RGB_USER();      //���� ���� ���������������
//////////////////////////////////////////////////////////////////////////
/////////////////����� ����� � ���������//////////////////////////////////
//////////////////////////////////////////////////////////////////////////
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;    //��������� ��� ���������
	///������������� ���������� �����/////////////////////////////
	LoadString(hInstance,IDS_LAB7_TITLE,szTitle,MAX_LOADSTRING);
	LoadString(hInstance,IDC_LAB7_CL,szWindowClass,MAX_LOADSTRING);
	LAB7_RegisterClass(hInstance); //������������ ����� ����
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}
	RegisterHotKey(hWnd,1,NULL,VK_F1);
	RegisterHotKey(hWnd,2,NULL,VK_F2);
	RegisterHotKey(hWnd,3,NULL,VK_F3);
	RegisterHotKey(hWnd,4,NULL,VK_F4);
	////////������� ���� ��������� ���������//////////////////////////////
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
//////////////////////////////////////////////////////////////////////////
/////////////////////////������� �������� ����////////////////////////////
//////////////////////////////////////////////////////////////////////////
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
  
   hInst = hInstance;  //hInst - ���������� ����������
   hWnd = CreateWindow(
	                   szWindowClass, 
					   szTitle, 
					   WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL,
                       CW_USEDEFAULT, 
					   0, 
					   CW_USEDEFAULT, 
					   0, 
					   NULL, 
					   NULL, 
					   hInstance, 
					   NULL
					  );
   if (!hWnd)
   {
	   return FALSE;
   }
   ShowWindow(hWnd, nCmdShow);
   return TRUE;
}
//////////////////////////////////////////////////////////////////////////
/////////////////////������� ����������� ������ ����//////////////////////
//////////////////////////////////////////////////////////////////////////
ATOM LAB7_RegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex; //��������� ���������� ���� WNDCLASSEX
	wcex.cbSize = sizeof(WNDCLASSEX); 
	wcex.style	= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)WndProc;
	wcex.cbClsExtra	= 0;
	wcex.cbWndExtra	= 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_MY100);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_3DDKSHADOW+1);
	wcex.lpszMenuName = (LPCSTR)IDC_LAB7_MENU;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);
	return RegisterClassEx(&wcex);
}
//////////////////////////////////////////////////////////////////////////
/////////////////������� ��������� ��������� ��� ����/////////////////////
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{	
    static	int cx,cy,xo,yo;
	int wmId_LAB7;
	wmId_LAB7=LOWORD(wParam); //������������� ��������� ����
	switch (message) 
	{
	     /////��������� - ���������� �������� ����� (���� � �.�.)//
	     case WM_COMMAND:
			switch (wmId_LAB7)
			{
				case IDM_ABOUT:
				   DialogBox(hInst,(LPCTSTR)IDD_ABOUTBOX,hWnd,(DLGPROC)About);
				   break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
                   break;
				case IDM_PASTE:            			
				   InvalidateRect(hWnd,NULL,true);
                   UpdateWindow(hWnd);
				   break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		//////������ ��������� ������ �������� �� ���������� ����//
		case WM_PAINT:
		   PAINTSTRUCT ps;
		   HDC hdc;
           hdc = BeginPaint(hWnd, &ps); 
		   PRINT_IMAGE(hdc);
		   EndPaint(hWnd, &ps);
	       break;
		///////���������� ���� � ���, ��� ��� ����� p��p�����////
		case WM_DESTROY:
		   //���p������ ��������� wm_Quit ������ � ����� �� ��������� wm_Destroy
		   //���� �� ������� ��� ��������� - ���� ���������, � ������� ����� � ������
		   PostQuitMessage(0);
		   break;
		////////��������� - ��� �������� ����////////////////////
		case WM_CREATE:
           //////////������������� �������� ���������////////////
           max_x=100; 
		   max_y=max_x;
           min=0;     
           SetScrollRange(hWnd,SB_VERT,min,max_y,TRUE);
		   SetScrollRange(hWnd,SB_HORZ,min,max_x,TRUE);
           SetScrollPos (hWnd,SB_VERT,0,TRUE); 
           ///////////�������������� ����������//////////////////
		   y_BUF=0;
		   x_BUF=0;
		   a=MAX_PLOSHAD_A;        //����� ������� ������������� 
		   b=MAX_PLOSHAD_B;        //������ ������� ������������� 
		   delta_y=10;   //������ ������ ������
		   delta_x=10;   //������ ������ �����
		   FIGURA=1; //��������� ������� �������� ��������������
           ////////////����� ��� ����������//////////////////////
		   hdcmem = CreateCompatibleDC(GetDC(hWnd));
		   hdcmem2 = CreateCompatibleDC(GetDC(hWnd));	
           hb = CreateCompatibleBitmap(GetDC(hWnd),SCREEN_X,SCREEN_Y);
		   hb2 = CreateCompatibleBitmap(GetDC(hWnd),SCREEN_X,SCREEN_Y);
           SelectObject(hdcmem,hb);		   
           SelectObject(hdcmem2,hb2);   
		   break;
		/////////////������������ ����������/////////////////////
        case WM_VSCROLL:
		   switch(LOWORD(wParam))
		   {
              case SB_LINEUP:
			     //////////////���������� ��������///////////////
                 if (pos_y>min)
				 {
                   pos_y=pos_y-1;
				   SetScrollPos (hWnd,SB_VERT,pos_y,TRUE);
				   y_BUF=ceil(pos_y*(b/max_y)); //��������� ���������� ����� (x_BUF,y_BUF)
				 }
                 break; 
			  case SB_LINEDOWN:
				  if (pos_y<max_y)
				 {
                   pos_y=pos_y+1;
				   SetScrollPos (hWnd,SB_VERT,pos_y,TRUE);
				   y_BUF=ceil(pos_y*(b/max_y)); //��������� ���������� ����� (x_BUF,y_BUF)
				 }
                 break; 
			  case SB_THUMBTRACK:  //������������ ����������� ��������
				  pos_y=HIWORD(wParam);
				  SetScrollPos (hWnd,SB_VERT,pos_y,TRUE);
                  y_BUF=ceil(pos_y*(b/max_y));
			  default:
				 break;
		   };
	       //���������� ���� ����������//////////////////////////
		   SetWindowOrgEx(hdcmem2,-x_BUF,-y_BUF,NULL);
		   InvalidateRect(hWnd,NULL,false); //false - ��� ������� ���� - �� ���� ��������������
           UpdateWindow(hWnd);
          break;
		/////////////�������������� ����������///////////////////
        case WM_HSCROLL:
		   switch(LOWORD(wParam))
		   {
              case SB_LINEUP:
			     //////////////���������� ��������///////////////
                 if (pos_x>min)
				 {
                   pos_x=pos_x-1;
				   SetScrollPos (hWnd,SB_HORZ,pos_x,TRUE);
				   x_BUF=ceil(pos_x*(a/max_x)); //��������� ���������� ����� (x_BUF,y_BUF)
				 }
                 break; 
			  case SB_LINEDOWN:
				 if (pos_x<max_x)
				 {
                   pos_x=pos_x+1;
				   SetScrollPos (hWnd,SB_HORZ,pos_x,TRUE);
				   x_BUF=ceil(pos_x*(a/max_x)); //��������� ���������� ����� (x_BUF,y_BUF)
				 }
                 break; 
			  case SB_THUMBTRACK:  //������������ ����������� ��������
				 pos_x=HIWORD(wParam);
				 SetScrollPos(hWnd,SB_HORZ,pos_x,TRUE);
                 x_BUF=ceil(pos_x*(a/max_x));
			  default:
				 break;
		   };
	       //���������� ���� ����������//////////////////////////
           SetWindowOrgEx(hdcmem2,-x_BUF,-y_BUF,NULL);
		   InvalidateRect(hWnd,NULL,false); //false - ��� ������� ���� - �� ���� ��������������
           UpdateWindow(hWnd);
          break;
		////////////������� �������///////////////////////////////////////
		case WM_HOTKEY:
            switch (HIWORD(lParam))
			{
              case VK_F1:
                RGB_USER(); //�������� ��������� ������ ����� ��� �����
  			    InvalidateRect(hWnd,NULL,false);
                UpdateWindow(hWnd);
				break;
			  case VK_F2:
                FIGURA=1;
				break;
			  case VK_F3:
                FIGURA=2;
				break;
			  case VK_F4:
                FIGURA=3;
				break;
			};
			break;
		//////////////////////////////////////////////////////////////////
		case WM_MOUSEMOVE: 
           if (wParam & MK_LBUTTON) 			
		   {//���� �� ������ �� ����� ������ ���� � ����� ��� �����
             xTec = LOWORD(lParam);  
             yTec = HIWORD(lParam);   
             RECT_HDCMEM(); //����� �� ������ ���������� ������� ��� ������
		   }
		   else
		   {//�� �������� - ������ ���������� ���������� �� ������� - ��� ����� ����������
		     xPos = LOWORD(lParam);  
             yPos = HIWORD(lParam);
		   }
          break;
		////////////////���� �������� ������ ����/////////////////////////
        case WM_LBUTTONUP:
          MOUSE_UP_HDC=true;
          RECT_HDCMEM(); //����� ���������� ���������		  
		  break;
		/////////////////////////////////////////////////////////
		default:
			//������������ ������p���� ��p������ ��������� ��� ���������, ����p�� 
			//���� �� ��p����������� �p�������� �������
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}
//////////////////////////////////////////////////////////////////////////
///////////////////��������� ��������� �������////////////////////////////
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;
		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
//////////////////////////////////////////////////////////////////////////
///////������ ������������� �� ��� ���� - �� ��� ���� ������ ������///////
//////////////////////////////////////////////////////////////////////////
void PRINT_IMAGE(HDC hd)
{ 
 static bool ONE=false;
 if (ONE==false)
 {////���� �������� � ����� ������ - ����� �������� �������������� ���////
  ////����� �� ��� ���� ������ ������/////////////////////////////////////
  HBRUSH hBr;
  HPEN hp;
  LOGBRUSH lb;
  lb.lbColor=GetSysColor(COLOR_3DDKSHADOW); //�������� ���� ����� ������
  lb.lbStyle=BS_SOLID;
  lb.lbHatch=NULL;
  ///////////������� ������ � ������ ����� ���////////////////////////////
  hBr = CreateBrushIndirect(&lb);
  hp = CreatePen(NULL,0,GetSysColor(COLOR_3DDKSHADOW));
  SelectObject(hdcmem2, hBr);
  SelectObject(hdcmem2, hp);
  Rectangle(hdcmem2,0,0,SCREEN_X,SCREEN_Y);	
  DeleteObject(hp);
  DeleteObject(hBr);
  /////���������� ������������� � ���� - �� ��� ��� ������////////////////
  BitBlt(GetDC(hWnd), 0, 0, SCREEN_X, SCREEN_Y, hdcmem2, 0,0,SRCCOPY);
  ONE=true;
 }
 else
 {//����� ���������� ���������� ������ � �������� ����////////////////////
   BitBlt(GetDC(hWnd), 0, 0, SCREEN_X, SCREEN_Y, hdcmem2, 0,0,SRCCOPY);
 }
}
//////////////////////////////////////////////////////////////////////////
/////////������������ ������ ������������� - � ������/////////////////////
//////////////////////////////////////////////////////////////////////////
void RECT_HDCMEM()
{
 HBRUSH hBr;
 HPEN hp;
 LOGBRUSH lb;
 lb.lbColor=CR; //���� ��������������
 lb.lbStyle=BS_SOLID;
 lb.lbHatch=NULL;
 /////////////////////////////////////////////////////////////////////////
 hBr = CreateBrushIndirect(&lb);
 hp = CreatePen(NULL,0,RGB(1,1,1)); //���� ������� ��������������
 SelectObject(hdcmem, hBr);
 SelectObject(hdcmem, hp);
 SelectObject(hdcmem2, hBr);
 SelectObject(hdcmem2, hp);
 if (MOUSE_UP_HDC==true) 
 {//////������������ �������� ���� - ����� ���������� � ������////////////
   SelectObject(hdcmem2,hb); 
   switch (FIGURA)
   {
     case 1:
         Rectangle(hdcmem2,xPos,yPos,xTec,yTec);	 
		 break;
	 case 2:
         int D;
		 D=abs(-xTec+xPos);
		 Ellipse(hdcmem2,xPos,yPos,xPos+D,yPos+D);
		 break;
	 case 3:
         Ellipse(hdcmem2,xPos,yPos,xTec,yTec);
		 break;
   };
   BitBlt(GetDC(hWnd), 0, 0, SCREEN_X, SCREEN_Y, hdcmem2, 0,0,SRCCOPY);
   MOUSE_UP_HDC=false;
 }
 else
 {///////////���� ���������� ��� ������� ������ - �������� hdcmem<=hdcmem2
   BitBlt(hdcmem, 0, 0, SCREEN_X, SCREEN_Y, hdcmem2, 0,0,SRCCOPY); 
   switch (FIGURA)
   {
     case 1:
         Rectangle(hdcmem,xPos,yPos,xTec,yTec);
		 break;
	 case 2:
         int D;
		 D=abs(-xTec+xPos);
		 Ellipse(hdcmem,xPos,yPos,xPos+D,yPos+D);
		 break;
	 case 3:
         Ellipse(hdcmem,xPos,yPos,xTec,yTec);
		 break;
   };
   BitBlt(GetDC(hWnd), 0, 0, SCREEN_X, SCREEN_Y, hdcmem, 0,0,SRCCOPY);
 }
 DeleteObject(hp);
 DeleteObject(hBr);
}
//////////////////////////////////////////////////////////////////////////
////////////////////////////����� �����///////////////////////////////////
//////////////////////////////////////////////////////////////////////////
void RGB_USER()
{
   ///////////////////////////////////////////////////////////////////////
   HBRUSH hbrush;   
   CHOOSECOLOR cc;                 
   static COLORREF acrCustClr[16];                
   ///////////////////////////////////////////////////////////////////////
   ZeroMemory(&cc, sizeof(CHOOSECOLOR));
   cc.lStructSize = sizeof(CHOOSECOLOR);
   cc.hwndOwner = hWnd;
   cc.lpCustColors = (LPDWORD) acrCustClr;
   cc.rgbResult = CR;
   cc.Flags = CC_FULLOPEN | CC_RGBINIT; 
   ///////////////////////////////////////////////////////////////////////
   if (ChooseColor(&cc)==TRUE) 
   {
    hbrush = CreateSolidBrush(cc.rgbResult);
    CR = cc.rgbResult; 
   }
}