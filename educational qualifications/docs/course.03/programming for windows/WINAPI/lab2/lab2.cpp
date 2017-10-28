//////////////////////////////////////////////////////////////////////////
//
//              ������������� ������ �� �2 �� WinApi
//              �����: ��������� �.�. ��-31 2006�.
//              ���� ����������: 3.03.2006�.
//
//////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "resource.h"
#define MAX_LOADSTRING 100
//////////////////////////////////////////////////////////////////////////
/////////////////////////���������� ����������////////////////////////////
//////////////////////////////////////////////////////////////////////////
bool flag;                             //���� �������� �� ����������
HINSTANCE hInst;					   //��������� ���������� ����� ���������		
TCHAR szTitle[MAX_LOADSTRING];	       //��������� ����						
TCHAR szWindowClass[MAX_LOADSTRING];   //��������� �� ������������������ ��� ������			
//////////////////////////////////////////////////////////////////////////
////////////////////��������� ���������� �������//////////////////////////
//////////////////////////////////////////////////////////////////////////
ATOM				LAB2_RegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int); 
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
void                PRINT_HELLO(HDC hdc);
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
	LoadString(hInstance,IDS_LAB2_TITLE,szTitle,MAX_LOADSTRING);
	LoadString(hInstance,IDC_LAB2_CL,szWindowClass,MAX_LOADSTRING);
	LAB2_RegisterClass(hInstance); //������������ ����� ����
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
					   WS_OVERLAPPEDWINDOW,
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
ATOM LAB2_RegisterClass(HINSTANCE hInstance)
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
	wcex.lpszMenuName = (LPCSTR)IDC_LAB2_MENU;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);
	return RegisterClassEx(&wcex);
}
//////////////////////////////////////////////////////////////////////////
/////////////////������� ��������� ��������� ��� ����/////////////////////
//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{	
	int wmId_LAB2;
	wmId_LAB2=LOWORD(wParam); //������������� ��������� ����
	switch (message) 
	{
		case WM_COMMAND:
			switch (wmId_LAB2)
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
			  PRINT_HELLO(hdc);
		   EndPaint(hWnd, &ps);
	       break;
		///////���������� ���� � ���, ��� ��� ����� p��p�����////
		case WM_DESTROY:
		   //���p������ ��������� wm_Quit ������ � ����� �� ��������� wm_Destroy
		   //���� �� ������� ��� ��������� - ���� ���������, � ������� ����� � ������
		   PostQuitMessage(0);
		   break;
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
void PRINT_HELLO(HDC hdc)
{
  int p=0;
  HPEN hPen;
  HBRUSH hBr;
  LOGBRUSH lb;
  /////////////////��� ��������//////////////////////////////
  lb.lbColor=RGB(200,100,10);
  lb.lbStyle=BS_SOLID;
  lb.lbHatch=NULL;
  hBr = CreateBrushIndirect(&lb);
  SelectObject(hdc, hBr);
  ///////////////////////////////////////////////////////////
  hPen = CreatePen(NULL,3,RGB(10,78,90));
  SelectObject(hdc, hPen);
  Arc(hdc,10,10,50,150,p,p,p,p);
  ///////////////////////////////////////////////////////////
  hPen = CreatePen(NULL,8,RGB(100,178,90));
  SelectObject(hdc, hPen);
  Arc(hdc,100,100,150,150,p,p,p,p);
  ///////////////////////////////////////////////////////////
  hPen = CreatePen(NULL,2,RGB(1,240,90));
  SelectObject(hdc, hPen);
  Arc(hdc,100,300,150,350,170,170,10,600);
  ///////////////////////////////////////////////////////////
  hPen = CreatePen(NULL,3,RGB(200,178,90));
  SelectObject(hdc, hPen);
  Rectangle(hdc, 300, 100, 350, 150);
  ///////////////////////////////////////////////////////////
  hPen = CreatePen(PS_DASHDOT,1,RGB(255,1,255));
  SelectObject(hdc, hPen);
  Rectangle(hdc, 400, 200, 450, 250);
  ///////////////////////////////////////////////////////////
  hPen = CreatePen(PS_DASHDOTDOT,1,RGB(25,1,255));
  SelectObject(hdc, hPen);
  MoveToEx(hdc,0,0,NULL);
  LineTo(hdc,800,200);
  ///////////////////////////////////////////////////////////
  DeleteObject(hPen);
  DeleteObject(hBr);
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