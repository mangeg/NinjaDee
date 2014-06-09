#include "App.h"
#include "FileSystem.h"

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
	auto folderExits = FileSystem::FolderExists(L"C:\\Projects\\Cpp\\NinjaDee\\Apps.props");
	auto fileExists = FileSystem::FileExists(L"C:\\Projects\\Cpp\\NinjaDee\\Apps.props");
}
void App::Update()
{
}
void App::Shutdown()
{
}

bool App::ConfigureEngine()
{
	m_pRenderWindow = new Win32RenderWindow();
	m_pRenderWindow->Initialize(this);
	m_pRenderWindow->SetCaption(GetName());

	return true;
}
void App::ShutdownEngine()
{
	if (m_pRenderWindow)
	{
		m_pRenderWindow->Shutdown();		
		delete m_pRenderWindow;
		m_pRenderWindow = nullptr;
	}
}