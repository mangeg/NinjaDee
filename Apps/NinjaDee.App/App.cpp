#include "App.h"
#include "FileSystem.h"
#include "FileInfo.h"
#include "Path.h"
#include "Log.h"

using namespace NinjaDee;

App AppInstance;

App::App()
{	
	//_crtBreakAlloc = 144;
}

std::wstring App::GetName()
{
	return std::wstring(L"Basic Application");
}

void App::Initialize()
{	
}

void App::Update()
{
	LOG_F(1 == 1);
}

void App::Shutdown()
{
}

bool App::ConfigureEngine()
{
	m_pRenderWindow = NNEW Win32RenderWindow();
	m_pRenderWindow->Initialize(this);
	m_pRenderWindow->SetCaption(GetName());

	return true;
}
void App::ShutdownEngine()
{
	if (m_pRenderWindow)
	{
		m_pRenderWindow->Shutdown();		
		SAFE_DELETE(m_pRenderWindow);
	}
}