#include "pch.h"
#include "Win32RenderWindow.h"

using namespace NinjaDee;

LRESULT CALLBACK InternalWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	LONG_PTR ObjPtr = GetWindowLongPtr(hwnd, 0);

	switch (msg)
	{
		case WM_CREATE:
		{
			// Automatically return 0 to allow the window to proceed in the
			// creation process.

			return 0;
		} break;
	}

	if (ObjPtr == 0) {
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
	else {
		return reinterpret_cast<IWindowProc*>(ObjPtr)->WindowProc(hwnd, msg, wparam, lparam);
	}
}

Win32RenderWindow::Win32RenderWindow()
{
	m_sCaption = L"";
	m_hWnd = nullptr;
	m_dStyle = (WS_OVERLAPPEDWINDOW | WS_VISIBLE);
}

Win32RenderWindow::~Win32RenderWindow()
{
	Shutdown();
}

void Win32RenderWindow::Initialize(IWindowProc* windowProcObj)
{
	WNDCLASSEX wc;

	// Setup the window class
	memset(&wc, 0, sizeof(wc));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = InternalWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = sizeof(windowProcObj);
	wc.hInstance = nullptr;
	wc.hIcon = LoadIcon( nullptr, IDI_APPLICATION);
	wc.hCursor = LoadCursor( nullptr, IDC_ARROW);	
	wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = L"HieroglyphWin32";
	wc.hIconSm = LoadIcon( nullptr, IDI_APPLICATION);
	windowProcObj->BeforeRegisterWindowClass(wc);

	// Register the window class
	RegisterClassEx(&wc);

	// Record the desired device size
	RECT rc;
	rc.top = rc.left = 0;
	rc.right = m_iWidth;
	rc.bottom = m_iHeight;

	// Adjust the window size for correct device size
	AdjustWindowRect(&rc, m_dStyle, FALSE);

	long lwidth = rc.right - rc.left;
	long lheight = rc.bottom - rc.top;

	long lleft = static_cast<long>(m_iLeft);
	long ltop = static_cast<long>(m_iTop);


	// Create an instance of the window
	m_hWnd = CreateWindowEx(
		NULL,							// extended style
		wc.lpszClassName, 				// class name
		m_sCaption.c_str(),				// instance title
		m_dStyle,						// window style
		lleft, ltop,					// initial x, y
		lwidth,							// initial width
		lheight,						// initial height
		nullptr,							// handle to parent 
		nullptr,							// handle to menu
		nullptr,							// instance of this application
		nullptr);							// extra creation parms

	if (m_hWnd) {
		// Set in the "extra" bytes the pointer to the IWindowProc object
		// which handles messages for the window
		SetWindowLongPtr(m_hWnd, 0, reinterpret_cast<LONG_PTR>(windowProcObj));
		// Initially display the window
		ShowWindow(m_hWnd, SW_SHOWNORMAL);
		UpdateWindow(m_hWnd);
	}
}

void Win32RenderWindow::Shutdown()
{
	if (m_hWnd)
		DestroyWindow(m_hWnd);

	m_hWnd = nullptr;
}

void Win32RenderWindow::Paint()
{
}

void Win32RenderWindow::UpdateWindowState()
{
	if (m_hWnd != 0)
	{
		RECT ClientRect;
		ClientRect.left = 0;
		ClientRect.top = 0;
		ClientRect.right = m_iWidth;
		ClientRect.bottom = m_iHeight;

		// Adjust the window size for correct device size
		RECT WindowRect = ClientRect;
		AdjustWindowRect(&WindowRect, m_dStyle, FALSE);

		int deltaX = (WindowRect.right - ClientRect.right) / 2;
		int deltaY = (WindowRect.bottom - ClientRect.bottom) / 2;

		MoveWindow(m_hWnd, m_iLeft - deltaX, m_iTop - deltaY,
			m_iWidth + deltaX * 2, m_iHeight + deltaY * 2, true);
	}
}

void Win32RenderWindow::SetCaption(std::wstring caption)
{
	m_sCaption = caption;

	if (m_hWnd != nullptr)
		SetWindowText(m_hWnd, m_sCaption.c_str());
}

void Win32RenderWindow::SetStyle(DWORD style)
{
	m_dStyle = style;

	SetWindowLongPtr(m_hWnd, GWL_EXSTYLE, m_dStyle);
}

DWORD Win32RenderWindow::GetStyle()
{
	return m_dStyle;
}

std::wstring Win32RenderWindow::GetCaption()
{
	return m_sCaption;
}