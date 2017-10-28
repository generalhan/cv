//////////////////////////////////////////////////////////////////////////
//
//              ������������� ������ �� �3 �� WinApi
//              �����: ��������� �.�. ��-31 2006�.
//              ���� ����������: 4.03.2006�.
//
//////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "math.h "
#include "resource.h"
#define MAX_LOADSTRING 100
//����������� ���� - �� ����, ������� �� ������ ����������� ����������� � Windows ����
#define MAX_PLOSHAD_B 5000 //������������ ������ ������������ ����
#define MAX_PLOSHAD_A 200  //������������ ����� ������������ ����
//////////////////////////////////////////////////////////////////////////
/////////////////////////���������� ����������////////////////////////////
//////////////////////////////////////////////////////////////////////////
int pos_y,pos_x;                       //���������� ��������� ���������
int max_x,max_y;                       //max ��������� ���������
int min;                               //min ��������� ���������
int x_BUF,y_BUF,a,b,delta_y,delta_x;   //���������� ���������� ������� �����
bool flag;                             //���� �������� �� ����������
HINSTANCE hInst;					   //��������� ���������� ����� ���������		
TCHAR szTitle[MAX_LOADSTRING];	       //��������� ����						
TCHAR szWindowClass[MAX_LOADSTRING];   //��������� �� ������������������ ��� ������			
//////////////////////////////////////////////////////////////////////////
////////////////////��������� ���������� �������//////////////////////////
//////////////////////////////////////////////////////////////////////////
ATOM				LAB3_RegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int); 
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
void                PRINT_HELLO(HDC hdc,short int R,short int G,short int B);
//////////////////////////////////////////////////////////////////////////
/////////////////����� ����� � ���������//////////////////////////////////
//////////////////////////////////////////////////////////////////////////
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
    flag=false; //������ ������ � ����
	MSG msg;    //��������� ��� ���������
	///������������� ���������� �����/////////////////////////////
	LoadString(hInstance,IDS_LAB3_TITLE,szTitle,MAX_LOADSTRING);
	LoadString(hInstance,IDC_LAB3_CL,szWindowClass,MAX_LOADSTRING);
	LAB3_RegisterClass(hInstance); //������������ ����� ����
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}
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
   HWND hWnd;
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
ATOM LAB3_RegisterClass(HINSTANCE hInstance)
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
	wcex.lpszMenuName = (LPCSTR)IDC_LAB3_MENU;
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
	int wmId_LAB3;
	wmId_LAB3=LOWORD(wParam); //������������� ��������� ����
	switch (message) 
	{
	     /////��������� - ���������� �������� ����� (���� � �.�.)//
	     case WM_COMMAND:
			switch (wmId_LAB3)
			{
				case IDM_ABOUT:
				   DialogBox(hInst,(LPCTSTR)IDD_ABOUTBOX,hWnd,(DLGPROC)About);
				   break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
                   break;
				case IDM_PASTE:
                   flag=true; //��������� ��������� �������� �������              			
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
		   if (flag==true)
			  PRINT_HELLO(hdc,200,100,50);
		   EndPaint(hWnd, &ps);
	       break;
		///////���������� ���� � ���, ��� ��� ����� p��p�����////
		case WM_DESTROY:
		   //���p������ ��������� wm_Quit ������ � ����� �� ��������� wm_Destroy
		   //���� �� ������� ��� ��������� - ���� ���������, � ������� ����� � ������
		   PostQuitMessage(0);
		   break;
        //////////�������� ������� ������������� ������������ ���� - �� ��� 
		///////////////////������������� � ����� ����
        case WM_SIZE:
		   cx = LOWORD(lParam);
           cy = HIWORD(lParam);
		   if (cx>0 && cy>0)
		   {
             b=ceil((768/cy)*MAX_PLOSHAD_B);  //768 - ���������� �� ��������� ����
		     a=ceil((1024/cy)*MAX_PLOSHAD_A); //1024 - ���������� �� ����������� ����
		   }
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
		   InvalidateRect(hWnd,NULL,true);
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
		   InvalidateRect(hWnd,NULL,true);
           UpdateWindow(hWnd);
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
////////////////////////������� ����� �� �����////////////////////////////
//////////////////////////////////////////////////////////////////////////
void PRINT_HELLO(HDC hdc,short int R,short int G,short int B)
{
  int NUM_STR=200; //���������� ����� � ���� - ����� ������ ��� ������������ ������
  SetBkColor(hdc,GetSysColor(COLOR_3DDKSHADOW)); //������������� ���� ����
  char * S;
  S="Hello Windows NT!";
  for (int i=0;i<NUM_STR;i++)
  {
	SetTextColor(hdc,RGB(R-i*2,G-i*2,B+i)); //������������� ���� ������
    TextOut(hdc,-x_BUF+delta_x,-y_BUF+delta_y+20*i,S,lstrlen(S));
  };
  S=NULL;
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