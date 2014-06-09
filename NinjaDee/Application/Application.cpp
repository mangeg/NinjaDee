#include "pch.h"
#include "Application.h"

using namespace NinjaDee;

Application* Application::ms_pApplication = nullptr;

Application::Application()
{
	ms_pApplication = this;
}

Application::~Application()
{	
}

Application* Application::GetApplication()
{
	return ms_pApplication;
}

void Application::MessageLoop()
{
	MSG msg;

	while (true)
	{
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				return;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Update();
	}
}

void Application::BeforeRegisterWindowClass(WNDCLASSEX &wc)
{
}

LRESULT Application::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
		case WM_CREATE:
		{
			// Automatically return 0 to allow the window to proceed in the
			// creation process.

			return 0;
		} break;

		case WM_CLOSE:
		{
			// This message is sent when a window or an application should
			// terminate.
		} break;

		case WM_DESTROY:
		{
			// This message is sent when a window has been destroyed.
			PostQuitMessage(0);
			return 0;
		} break;
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}


void Application::RequestShutdown()
{
	PostQuitMessage(0);
}