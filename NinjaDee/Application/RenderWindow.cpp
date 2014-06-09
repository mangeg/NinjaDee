#include "pch.h"
#include "RenderWindow.h"

using namespace NinjaDee;

RenderWindow::RenderWindow()
{
	m_iWidth = 640;
	m_iHeight = 480;	
	m_iTop = 100;
	m_iLeft = 100;
}

RenderWindow::~RenderWindow()
{	
}

int RenderWindow::GetWidth()
{
	return m_iWidth;
}

int RenderWindow::GetHeight()
{
	return m_iHeight;
}

int RenderWindow::GetLeft()
{
	return m_iLeft;
}

int RenderWindow::GetTop()
{
	return m_iTop;
}

void RenderWindow::SetHeight(int height)
{
	m_iHeight = height;
}

void RenderWindow::SetWidth(int width)
{
	m_iWidth = width;
}

void RenderWindow::SetSize(int width, int height)
{
	m_iWidth = width;
	m_iHeight = height;
}

void RenderWindow::SetPosition(int left, int top)
{
	m_iLeft = left;
	m_iTop = top;
}

void RenderWindow::UpdateWindowState()
{
}