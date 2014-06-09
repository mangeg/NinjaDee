#pragma once

#include "pch.h"
#include "IWindowProc.h"

namespace NinjaDee
{
	class RenderWindow
	{
	public:
		RenderWindow();
		virtual ~RenderWindow();

		virtual void Initialize(IWindowProc* windowProcObj) = 0;
		virtual void Shutdown() = 0;
		virtual void Paint() = 0;

		void SetHeight(int height);
		void SetWidth(int width);

		int GetWidth();
		int GetHeight();
		int GetLeft();
		int GetTop();

		void SetSize(int width, int height);
		void SetPosition(int left, int top);

	protected:

		virtual void UpdateWindowState();

		int m_iWidth;
		int m_iHeight;		
		int m_iLeft;
		int m_iTop;
	};	
}