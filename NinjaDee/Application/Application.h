#pragma once

#include "pch.h"
#include "IWindowProc.h"

namespace NinjaDee
{
	class Application : public IWindowProc
	{
	public:
		Application();
		virtual ~Application();

		static Application* GetApplication();
		virtual bool ConfigureEngine() = 0;
		virtual void ShutdownEngine() = 0;
		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Shutdown() = 0;
		virtual void MessageLoop();
		virtual LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
		virtual void BeforeRegisterWindowClass(WNDCLASSEX &wc);

		virtual std::wstring GetName() = 0;

		void RequestShutdown();

	protected:
		static Application* ms_pApplication;
	};
}