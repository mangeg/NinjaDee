#pragma once

#include "pch.h"
#include "IWindowProc.h"
#include "RenderWindow.h"

namespace NinjaDee
{
	class Win32RenderWindow : public RenderWindow
	{
	public:
		Win32RenderWindow();
		virtual ~Win32RenderWindow() override;

		virtual void Initialize(IWindowProc* windowProcObj) override;
		virtual void Shutdown() override;
		virtual void Paint() override;

		virtual void SetCaption(std::wstring caption);
		virtual void SetStyle(DWORD style);

		virtual DWORD GetStyle();
		virtual std::wstring GetCaption();

	protected:
		virtual void UpdateWindowState() override;

		HWND m_hWnd;
		DWORD m_dStyle;

		std::wstring m_sCaption;
	};
}