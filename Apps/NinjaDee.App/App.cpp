#include "App.h"
#include "FileSystem.h"
#include "..\..\NinjaDee\Utility\FileInfo.h"
#include "..\..\NinjaDee\Utility\Path.h"

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

	auto fileInfo = FileInfo(LR"(C:\Projects\Cpp\NinjaDee\Apps\NinjaDee.App\App.cpp)");
	std::wstring fullPath = fileInfo.GetFullPath();
	auto lastError = GetLastErrorStdStr();
	std::wstring extension = fileInfo.GetExtension();
	lastError = lastError = GetLastErrorStdStr();
	std::wstring fileName = fileInfo.GetFileName();
	lastError = lastError = GetLastErrorStdStr();
	std::wstring longPath = fileInfo.GetLongPath();
	lastError = lastError = GetLastErrorStdStr();
	std::wstring shortPath = fileInfo.GetShortPath();
	lastError = lastError = GetLastErrorStdStr();
	auto size = fileInfo.GetSize();
	lastError = lastError = GetLastErrorStdStr();
	auto lastWrite = fileInfo.GetLastChanged();
	lastError = lastError = GetLastErrorStdStr();
	
	SYSTEMTIME stUTC, stLocal;

	// Convert the last-write time to local time.
	FileTimeToSystemTime(&lastWrite, &stUTC);
	SystemTimeToTzSpecificLocalTime( nullptr, &stUTC, &stLocal);

	auto local = FormatDateTime(stLocal);
	auto utc = FormatDateTime(stUTC);

	Path::Combine(LR"(C:\Test\\\//\)", LR"(\s)");
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