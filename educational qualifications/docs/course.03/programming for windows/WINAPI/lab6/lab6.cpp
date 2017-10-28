//////////////////////////////////////////////////////////////////////////
//
//              ������������� ������ �� �6 �� WinApi
//              �����: ��������� �.�. ��-31 2006�.
//              ���� ����������: 6.03.2006�.
//
//////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "math.h "
#include "resource.h"
#include "process.h"
#define MAX_LOADSTRING 100
//////////////////////////////////////////////////////////////////////////
/////////////////////////���������� ����������////////////////////////////
//////////////////////////////////////////////////////////////////////////
HBITMAP hBitmap;     //���������� ��� �������� ����� BMP
CRITICAL_SECTION csCriticalSection_hBitmap; //����������� ������ ��� hBitmap
//////////////////////////////////////////////////////////////////////////
HWND hWnd;	         //���������� ����
HWND child;          //���������� ��������� ����
HANDLE hThrd;        //���������� ������
HINSTANCE hInst;					   //��������� ���������� ����� ���������
TCHAR szTitle[MAX_LOADSTRING];	       //��������� ����						
TCHAR szWindowClass[MAX_LOADSTRING];   //��������� �� ������������������ ��� ������
//////////////////////////////////////////////////////////////////////////
bool FLAG_END_THREAD;    //true - ��������� ��������� �����, false - ���
bool FLAG_THREAD_ES_END; //true - ����� ��������, ��� �� ����� �����������
bool END_KONTRAST_USER;  //���� �������� �� ���������� - ��������� ������ ���� ����� 
bool FLAG_CHILD;         //���� ������ ����� ���� �� ������ 2 ����
char * S, * KON;     //���� � ����� BMP � �������������		
int KONTR;  //������������� �����������
//////////////////////////////////////////////////////////////////////////
////////////////////��������� ���������� �������//////////////////////////
//////////////////////////////////////////////////////////////////////////
ATOM				LAB6_RegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int); 
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ChildProc(HWND hwnd, UINT Message, WPARAM wparam,LPARAM lparam);
LRESULT CALLBACK    BMP_PROC(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
//////////////////////////////////////////////////////////////////////////
void DRAW_BMP(HDC hdc, int xStart, int yStart);
void UPDATE_USER(HWND hw);
void CHILD_REG();
int BEGIN_THREAD();
int END_THREAD();
int GET_RGB(int B);
DWORD ThreadFunc(HWND hwnd);
//////////////////////////////////////////////////////////////////////////
/////////��������� ��������� ��� ��������� ���� - BMP/////////////////////
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK ChildProc(HWND hwnd, UINT Message, WPARAM wparam,LPARAM lparam)
{
	switch (Message) 
	{
	    case WM_CREATE:
		   FLAG_CHILD=true;
           hBitmap = (HBITMAP) LoadImage(hInst,PCHAR(S),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		   if (hBitmap!=0) //���� � ����� ��������� � ������ BMP
		      BEGIN_THREAD(); //�������������� � ��������� �����
		   break;
		case WM_PAINT:
		   PAINTSTRUCT ps;
		   HDC hdc;
           hdc = BeginPaint(hwnd, &ps); 
		   if (hBitmap!=0)
              DRAW_BMP(GetDC(hwnd),0,0);  //������� � ���� BMP
		   EndPaint(hwnd, &ps);
	       break;
        case WM_DESTROY:
		   FLAG_CHILD=false;
		   FLAG_END_THREAD=true;     //��������� ������ �����������
		   END_KONTRAST_USER=false;  //������� �� ������� �����
		   //���� ����� �� ������ - ������ ����� �� ����� � ThreadFunc
		   //� ���������� ���� true
		   while (FLAG_THREAD_ES_END!=true) {}
           END_THREAD(); //������������� �����
		   KONTR=0;      //������ ����� ���� ��������� � ���������� 0
		default:
		  return DefWindowProc(hwnd, Message, wparam, lparam);
   }
   return 0; 
}
//////////////////////////////////////////////////////////////////////////
//////////////����� ���������� ������������� �����������//////////////////
//////////////////////////////////////////////////////////////////////////
DWORD ThreadFunc(HWND hwnd) 
{ 
 ///////////����� ����� ������////////////////////////////////////////////
 FLAG_END_THREAD=false;   //���� false - ����� ��������� ������
                          //�������� ����������������� � ����������� �������
 FLAG_THREAD_ES_END=false; //��������� ������ � ��� ��� �� ����� �����������
 /////////////////////////////////////////////////////////////////////////	
 BITMAP bm;
 long int CO;
 int * lpvBits;
 long int f;
 int Value;
 while (FLAG_END_THREAD==false)
 {
 /////////////////////////////////////////////////////////////////////////
	EnterCriticalSection(&csCriticalSection_hBitmap); 	
    hBitmap=(HBITMAP) LoadImage(hInst,PCHAR(S),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	GetObject(hBitmap,sizeof(BITMAP),&bm); 
    CO=bm.bmWidthBytes*bm.bmHeight*bm.bmPlanes;
    lpvBits = new int[CO];
    f=GetBitmapBits(hBitmap,CO,lpvBits);	
	Value = KONTR; //��������� ��������
    LeaveCriticalSection(&csCriticalSection_hBitmap); 
    //////////�������� ��������///////////////////////////////////////////
    short int mB= 128;
    double vd;
    if (Value > 0) 
	{
      vd = 1 + (Value / 10);
	}
    else
	{ 
      vd = 1 - (sqrt(-Value) / 10);
	}
    for (int i=0;i<CO;i++)
	{
      short int b,g,r;
	  b=GetBValue(lpvBits[i]);
	  g=GetGValue(lpvBits[i]);
	  r=GetRValue(lpvBits[i]);
	  b = GET_RGB(mB + ceil((b - mB) * vd));
	  g = GET_RGB(mB + ceil((g - mB) * vd));
	  r = GET_RGB(mB + ceil((r - mB) * vd));
	  lpvBits[i]=RGB(r,g,b);
	}
    //////////////////////////////////////////////////////////////////////
    EnterCriticalSection(&csCriticalSection_hBitmap); 
    SetBitmapBits(hBitmap,CO,lpvBits);
    LeaveCriticalSection(&csCriticalSection_hBitmap); 
    //////////////////////////////////////////////////////////////////////
    delete [] lpvBits;
    lpvBits=NULL;
	UPDATE_USER(child);
    /////////////�������� - ����� �� �������� ��������////////////////////
	END_KONTRAST_USER=true;  //���� - ������ ���� ������
	while (END_KONTRAST_USER==true)
	{
		Sleep(100);
	}
 /////////////////////////////////////////////////////////////////////////
 }
 //////���� ���������� - ���� ������������ ��������� ������///////////////
 //////� �������� ����� FLAG_END_THREAD==true/////////////////////////////
 //////� ���� ������� �� �������� � ���, ��� ����� ����� �����������//////
 FLAG_THREAD_ES_END=true;  //����� ����� ����� �������� END_THREAD()//////
 return 0; 
} 
//////////////////////////////////////////////////////////////////////////
//////////////////////////������ ������ BMP///////////////////////////////
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK BMP_PROC(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK) 
			{
				if (FLAG_CHILD==false)
				{
				  GetDlgItemText(hDlg,IDC_EDIT1,PCHAR(S), 255);
			      CHILD_REG();    //������� ����
				};
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			if (LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			if (LOWORD(wParam) == IDC_BUTTON1) 
			{
                if (hBitmap!=0) //���� BMP ��������
				{
				  GetDlgItemText(hDlg,IDC_EDIT2,KON, 255);
			  	  KONTR=atoi(KON);   
				  END_KONTRAST_USER=false; //������ ����� ������� ���� � �����
				};
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
//////////////////////////////////////////////////////////////////////////
////////////�������� � ����� � ���� ������ *.BMP//////////////////////////
//////////////////////////////////////////////////////////////////////////
int GET_RGB(int B)
{
    if (B < 0) 
      return 0;
	if (B > 255) 
      return 255;
    return B;
}
//////////////////////////////////////////////////////////////////////////
/////////////////������� ��������� ��������� ��� �������� ����////////////
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{	
	switch (message) 
	{	 
	    case WM_COMMAND:
		  switch (LOWORD(wParam))
			{
				case MENU_1:		 	
		   	       DialogBox(hInst,(LPCTSTR)IDD_BMP,hWnd,(DLGPROC)BMP_PROC);	  
				   break;
				case MENU_2:
                   DestroyWindow(hWnd);
                   break;
				   break;
				case IDM_ABOUT:
				   DialogBox(hInst,(LPCTSTR)IDD_ABOUTBOX,hWnd,(DLGPROC)About);
                   break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
		  break;
		case WM_PAINT:
		   PAINTSTRUCT ps;
		   HDC hdc;
           hdc = BeginPaint(hWnd, &ps); 		
		   EndPaint(hWnd, &ps);
	       break;
		case WM_DESTROY:
           DeleteCriticalSection(&csCriticalSection_hBitmap);
		   PostQuitMessage(0);
		   break;
		case WM_CREATE:		
		   InitializeCriticalSection(&csCriticalSection_hBitmap);	
		   S = new char[255]; //�������� ������ ��� ���� BMP
		   KON = new char[255];  //�������� ������ ��� ����� ���������
		   break;
		default:
		  return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}
//////////////////////////////////////////////////////////////////////////
/////////������� ������ ���� hBitmap ������� ��� � ����///////////////////
//////////////////////////////////////////////////////////////////////////
void DRAW_BMP(HDC hdc, int xStart, int yStart)
{	
  HDC hdcMem;
  POINT ptSize, ptOrg; 
  BITMAP bm;
  hdcMem = CreateCompatibleDC(hdc);
  ////////////////////////////////////////////////////////////////////////
  EnterCriticalSection(&csCriticalSection_hBitmap); 
  GetObject(hBitmap,sizeof(BITMAP),&bm); 
  SelectObject(hdcMem, hBitmap);
  LeaveCriticalSection(&csCriticalSection_hBitmap);
  ////////////////////////////////////////////////////////////////////////
  SetMapMode(hdcMem,GetMapMode(hdc));
  ptOrg.x = 0;
  ptOrg.y = 0;
  ptSize.x = bm.bmWidth;
  ptSize.y = bm.bmHeight;
  DPtoLP(hdc,&ptSize,1);
  DPtoLP(hdcMem,&ptOrg,1);
  BitBlt(hdc,xStart,yStart,ptSize.x,ptSize.y,hdcMem,ptOrg.x,ptOrg.y,SRCCOPY);
  DeleteDC(hdcMem);
}
//////////////////////////////////////////////////////////////////////////
///////////////���������� ���� ����������/////////////////////////////////
//////////////////////////////////////////////////////////////////////////
void UPDATE_USER(HWND hw)
{
  InvalidateRect(hw,NULL,true);
  UpdateWindow(hw);
}
//////////////////////////////////////////////////////////////////////////
///////////////����������� ������ ��������� ����//////////////////////////
//////////////////////////////////////////////////////////////////////////
void CHILD_REG()
{
  WNDCLASS w;
  memset(&w,0,sizeof(WNDCLASS));
  w.style=CS_HREDRAW | CS_VREDRAW;
  w.lpfnWndProc = ChildProc;
  w.hInstance = hInst;
  w.hbrBackground = (HBRUSH)(COLOR_3DDKSHADOW+1);
  w.lpszClassName = "ChildWClass";
  w.hCursor=NULL; 
  RegisterClass(&w);
  child=CreateWindowEx(0,"ChildWClass",(LPCTSTR) NULL,WS_CHILDWINDOW|WS_OVERLAPPEDWINDOW, 10,10,500,200,hWnd,NULL,hInst,NULL);
  ShowWindow(child,SW_SHOWNORMAL);
  UPDATE_USER(child);
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////���������� ������///////////////////////////
//////////////////////////////////////////////////////////////////////////
int BEGIN_THREAD()
{
  DWORD IDThread; 
  hThrd = CreateThread(NULL, 
                       0,             
                       (LPTHREAD_START_ROUTINE) ThreadFunc, 
                       (LPVOID)hWnd, 
                       CREATE_SUSPENDED,
                       &IDThread);      
  SetThreadPriority(hThrd,THREAD_PRIORITY_NORMAL);
  ResumeThread(hThrd);
  return 0;
}
//////////////////////////////////////////////////////////////////////////
///////////////////////////���������� ������ ������///////////////////////
//////////////////////////////////////////////////////////////////////////
int END_THREAD()
{
  DWORD IDThread; 
  TerminateThread(hThrd,IDThread);
  return 0;
}
//////////////////////////////////////////////////////////////////////////
/////////////////����� ����� � ���������//////////////////////////////////
//////////////////////////////////////////////////////////////////////////
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;    //��������� ��� ���������
	///������������� ���������� �����/////////////////////////////////////
	LoadString(hInstance,IDS_LAB6_TITLE,szTitle,MAX_LOADSTRING);
	LoadString(hInstance,IDC_LAB6_CL,szWindowClass,MAX_LOADSTRING);
	LAB6_RegisterClass(hInstance); //������������ ����� ����
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
//////////////////////////������ � ���������//////////////////////////////
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
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
/////////////////////������� ����������� ������ ����//////////////////////
//////////////////////////////////////////////////////////////////////////
ATOM LAB6_RegisterClass(HINSTANCE hInstance)
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
	wcex.lpszMenuName = (LPCSTR)IDC_LAB6_MENU;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);
	return RegisterClassEx(&wcex);
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
					   WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
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