#pragma once

#include "pch.h"

namespace NinjaDee
{
	class IWindowProc
	{
	public:
		virtual void BeforeRegisterWindowClass(WNDCLASSEX &wc) = 0;
		virtual LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) = 0;
	};
}