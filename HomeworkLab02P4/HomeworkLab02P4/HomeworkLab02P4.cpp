// HomeworkLab02P4.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "commdlg.h"
#include "HomeworkLab02P4.h"


static int hWnd2_x = 100;//user pallet x coordinate
static int hWnd2_speed = 5;//user pallet speed
static int pallet_speed =1;
static int hWnd1_x = 200;  //for setting user pallet and synchronization

HWND hWnd , hWnd1/*ball*/ , hWnd2/*pallet*/, hWnd3/*pallet3*/;//Declare windows 
CHOOSECOLOR ccColour = { 0 };

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
//Adding classes for child windows
ATOM				ClassForBallWindow(HINSTANCE hInstance);
ATOM				ClassForPalletWindow(HINSTANCE hInstance);
ATOM				ClassForPalletWindow3(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);

LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
//Custom procedure for pallete
LRESULT CALLBACK	WndProc1(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	WndProc2(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	WndProc3(HWND, UINT, WPARAM, LPARAM);

INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);





//MAIN FUNCTION
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
					   _In_opt_ HINSTANCE hPrevInstance,
					   _In_ LPTSTR    lpCmdLine,
					   _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_HOMEWORKLAB02P4, szWindowClass, MAX_LOADSTRING);
	
	MyRegisterClass(hInstance);
	ClassForBallWindow(hInstance);
	ClassForPalletWindow(hInstance);
	ClassForPalletWindow3(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_HOMEWORKLAB02P4));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDC_HOMEWORKLAB02P4));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_HOMEWORKLAB02P4);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

ATOM ClassForPalletWindow(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc2;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDC_HOMEWORKLAB02P4));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+3);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_HOMEWORKLAB02P4);
	wcex.lpszClassName	= (LPCWSTR)"pallet";
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

ATOM ClassForPalletWindow3(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc3;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDC_HOMEWORKLAB02P4));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+3);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_HOMEWORKLAB02P4);
	wcex.lpszClassName	= (LPCWSTR)"pallet3";
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

ATOM ClassForBallWindow(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc1;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDC_HOMEWORKLAB02P4));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)CreateSolidBrush(RGB(0,0,255));
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_HOMEWORKLAB02P4);
	wcex.lpszClassName	= (LPCWSTR)"ball";
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}


//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//


	RECT rc;
	LONG GetTop(HWND w){
		GetWindowRect(w,&rc);
		return rc.top;
	}

	LONG GetBottom(HWND w){
		GetWindowRect(w,&rc);
		return rc.bottom;
	}

	LONG GetRight(HWND w){
		GetWindowRect(w,&rc);
		return rc.right;
	}

	LONG GetLeft(HWND w){
		GetWindowRect(w,&rc);
		return rc.left;
	}

	LONG GetWidth(HWND w){
		GetWindowRect(w,&rc);
		return rc.right-rc.left;
	}

	LONG GetHeight(HWND w){
		GetWindowRect(w,&rc);
		return rc.bottom-rc.top;
	}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	

	hInst = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 400, 400, NULL, NULL, hInstance, NULL);
	//bal
	hWnd1 = CreateWindow((LPCWSTR)"ball", szTitle, WS_CHILD,
		200, 200, 16, 16, hWnd, NULL, hInstance, NULL);
	//pallet
	hWnd2 = CreateWindow((LPCWSTR)"pallet", szTitle, WS_CHILD,
     hWnd2_x, 370, 100, 20, hWnd, NULL, hInstance, NULL);
	//Computer Pallet
	hWnd3 = CreateWindow((LPCWSTR)"pallet3", szTitle, WS_CHILD,
     100, 10, 100, 20, hWnd, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	
	LONG lStyle = GetWindowLong(hWnd, GWL_STYLE);
	lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);
	SetWindowLong(hWnd, GWL_STYLE, lStyle);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	HRGN circle=CreateEllipticRgn(0,0,16,16);

	//Set REgion Of the window
	SetWindowRgn(hWnd1, circle, FALSE);

	
	//Showing window
	ShowWindow(hWnd1, nCmdShow);
	UpdateWindow(hWnd1);
	
	//Set focus of keyboard on second pallet
	SetFocus(hWnd2);
	ShowWindow(hWnd2, nCmdShow);
	UpdateWindow(hWnd2);
	
	ShowWindow(hWnd3, nCmdShow);
	UpdateWindow(hWnd3);
	
	
	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	HBRUSH hbrush;
	//for colormenu
	CHOOSECOLOR color;
	static COLORREF acrCustClr[16]; 
	static DWORD rgbCurrent; 
	ZeroMemory(&color, sizeof(CHOOSECOLOR));

	color.lStructSize = sizeof(CHOOSECOLOR);
	color.hwndOwner = hWnd;
	color.lpCustColors = (LPDWORD)acrCustClr;
	color.rgbResult = rgbCurrent;
	color.Flags = CC_FULLOPEN | CC_RGBINIT;
	

	switch (message)
	{
	case WM_GETMINMAXINFO:
		{
			MINMAXINFO* mmi = (MINMAXINFO*)lParam;
			mmi->ptMinTrackSize.x = 400;
			mmi->ptMinTrackSize.y = 400;
			mmi->ptMaxTrackSize.x = 400;
			mmi->ptMaxTrackSize.y = 400;
			return 0;
		}
	case WM_NCRBUTTONDOWN:
	{
			POINT point;
			GetCursorPos(&point);
			//pallet_speed = 0;
			HMENU menu = CreatePopupMenu();
			InsertMenu(menu, 0, 0, ID__CHANGECOLOR, L"change color");
			TrackPopupMenu(menu, TPM_BOTTOMALIGN | TPM_LEFTALIGN, point.x, point.y, 0, hWnd, NULL);
		break;
	}
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
			case ID__CHANGECOLOR:
			{
				 pallet_speed = 0;
				 if (ChooseColor(&color) == TRUE)
					   {
					  RECT rc;
					  GetClientRect(hWnd, &rc);
				      hbrush = CreateSolidBrush(color.rgbResult);
					  SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)hbrush);
					  InvalidateRect(hWnd, &rc, TRUE);
					  pallet_speed = 1;
					}
				 else
				 {
					 pallet_speed = 1;
					 SetFocus(hWnd2);
				 }
		}
		
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

	case WM_CREATE:{
				   
		}
		break;
		//moving window
	case WM_NCHITTEST:{
		LRESULT b = DefWindowProc(hWnd, message, wParam, lParam);
        if (b == HTCLIENT) 
			b = HTCAPTION;
        return b;
			}
		break;
	
	case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
	}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}







// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}


//FOR USER PALLET
//  FUNCTION: WndProc2(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the pallet window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc2(HWND hWnd2, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	

	switch (message)
	{
	case WM_NCHITTEST:{
        return HTCAPTION;
		}
	case WM_MOVING:{
			HWND parent = GetParent(hWnd2);

			RECT parent_rc;
			GetWindowRect(parent, &parent_rc);
			RECT *rc = (RECT*)lParam;

			int pright = parent_rc.right;
			int right = rc->right;
			int pleft = parent_rc.left;
			int left = rc->left;
			int pbottom = parent_rc.bottom;
			int bottom = rc->bottom;
			int ptop = parent_rc.top;
			int top = rc->top;

			int window_height = pbottom - ptop;
			int window_width = pright - pleft;
			int pallet_height = bottom - top;
			int pallet_width = right - left;

			hWnd2_x  = rc->left-parent_rc.left;

			if (right > pright)
			{
				rc->right = pright;
				rc->left = pright - pallet_width;
				hWnd2_x = rc->left - parent_rc.left;
			}
			if (left < pleft)
			{

				rc->left = pleft;
				rc->right = pleft + pallet_width;
				hWnd2_x = rc->left - parent_rc.left;
			}

			if (bottom > pbottom)
			{
				rc->bottom = pbottom - 10;
				rc->top = pbottom - pallet_height - 10;
			}

			if (top > ptop)
			{
				rc->top = pbottom - pallet_height - 10;
				rc->bottom = pbottom - 10;
			}
	}
		break;

	case WM_CREATE:
		SetFocus(hWnd2);
		break;

	case WM_KEYDOWN:{
						RECT rc;
						GetWindowRect(hWnd2, &rc);

					   int height = GetHeight(hWnd2);
					   int width = GetWidth(hWnd2);

						switch (wParam)
						{
							case VK_RIGHT:
							{
								if (hWnd2_x < 400 - 100)
									{
										hWnd2_x += hWnd2_speed;
										SetWindowPos(hWnd2, HWND_TOP, hWnd2_x, 400 - (20 + 10), 100,20, SWP_SHOWWINDOW);
									}
								break;
							}
							case VK_LEFT: {
								if (hWnd2_x > 0){
									hWnd2_x -= hWnd2_speed;
									SetWindowPos(hWnd2, HWND_TOP, hWnd2_x, 400 - (20 + 10), 100, 20, SWP_SHOWWINDOW);
								}
								break;
							}
						}
						break; 
	}

	case WM_COMMAND:
		break;
	case WM_PAINT:
		{
			hdc = BeginPaint(hWnd2, &ps);
			EndPaint(hWnd2, &ps);

		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd2, message, wParam, lParam);
	}
	return 0;
}

//FOR Computer PALLET
//  FUNCTION: WndProc2(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the pallet window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc3(HWND hWnd3, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	static bool check=false;
	

	switch (message)
	{
	case WM_CREATE: {
		SetTimer(hWnd3, 7, 100, NULL);
		break;
	}
	case WM_TIMER:
	{
					 RECT rc;
					 RECT parent_rc;
					 HWND parent;
					 parent = GetParent(hWnd3);
					 GetWindowRect(parent, &parent_rc);
					 GetWindowRect(hWnd3, &rc);

					 int width = rc.right - rc.left;
					 int height = rc.bottom - rc.top;
					 
				
					 if ( hWnd1_x<= 400 - width/2-8 && hWnd1_x >= width/2-8){
						 MoveWindow(hWnd3, hWnd1_x-width/2+8, 10, width, height, TRUE);
				 }
	}
	break;
	case WM_COMMAND:
		break;
	case WM_PAINT:
		{
			hdc = BeginPaint(hWnd3, &ps);
			
			EndPaint(hWnd3, &ps);

		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd3, message, wParam, lParam);
	}
	return 0;
}

// BALL Procedure
//  FUNCTION: WndProc2(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the pallet window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc1(HWND hWnd1, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	static int hWnd1_y = 200;
	static bool check_horisontal = true;
	static bool check_vertical = false;
	static bool game_over = false;

	switch (message)
	{
		//Set timer for ball 
	case WM_CREATE:{
		SetTimer(hWnd1,7,1,NULL);		
		}

	case WM_TIMER : {
		//Decide which direction to go horisontaly
		
		
		int diffWidth = GetWidth(hWnd)-GetWidth(hWnd1);
		int diffHeight = GetHeight(hWnd) - GetHeight(hWnd1);

		int hWnd2_width = GetWidth(hWnd2);
		int hWnd1_width = GetWidth(hWnd1);
		int hWnd2_height = GetHeight(hWnd2);
		int hWnd1_height = GetHeight(hWnd1);


		//ball touch right wall 
		if(hWnd1_x >= diffWidth){
			check_horisontal = false;//turn left reflects
		}
		
		//ball touch left wall 
		if(hWnd1_x <= 0){
				check_horisontal = true; // turn right
			}

		//Decide which direction to go vertically
		if(hWnd1_y > 384 || (hWnd1_y == 384-16-10 && hWnd1_x >= hWnd2_x && hWnd1_x+16 <= hWnd2_x + hWnd2_width))
		{
			check_vertical = true;  //goes up
		}
		 
		if(hWnd1_y == hWnd2_height+10){
			check_vertical = false;		
		}

		//reflection from  sides of the pallet
		if((hWnd1_x+16 == hWnd2_x || hWnd1_x == hWnd2_x+hWnd2_width) &&	(hWnd1_y+16>=400-10-GetHeight(hWnd2) && hWnd1_y + 16 <= 390))
		{	
			check_vertical=false;  //goes down
			check_horisontal=!check_horisontal;//right / left
		}

		if(hWnd1_y + 16 == 400 && !game_over){
			game_over = true;
			pallet_speed=0;
			MessageBox(hWnd,L"Game Over",L"Game Over",NULL);
			PostQuitMessage(0);
		}

		//Getting width and height of the ball window
			int width =  (int)GetWidth(hWnd1);
			int height = (int)GetHeight(hWnd1);

		//Changing direction
		if(check_vertical == false && check_horisontal == true){
			hWnd1_x += pallet_speed;
			hWnd1_y += pallet_speed;

		
			MoveWindow(hWnd1, hWnd1_x, hWnd1_y,width,height,TRUE);
		}
		//down left
		else
			if(check_vertical == false && check_horisontal == false){
				hWnd1_x -= pallet_speed;
				hWnd1_y += pallet_speed;

			
				MoveWindow(hWnd1, hWnd1_x, hWnd1_y,width,height,TRUE);
			}
		else
			if (check_vertical == true && check_horisontal == true)
						 {
							 hWnd1_x += pallet_speed;
							 hWnd1_y -= pallet_speed;
						
				MoveWindow(hWnd1, hWnd1_x, hWnd1_y,width,height,TRUE);
						 }
		else	
			if (check_vertical == true && check_horisontal == false)
						 {
							 hWnd1_x -= pallet_speed;
							 hWnd1_y -= pallet_speed;
						
							 MoveWindow(hWnd1, hWnd1_x, hWnd1_y,width,height,TRUE);
						 }
				}
		break;

	case WM_COMMAND:
		break;
	case WM_PAINT:
		{
			hdc = BeginPaint(hWnd1, &ps);
			
			EndPaint(hWnd1, &ps);

		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd1, message, wParam, lParam);
	}
	return 0;
}