#include "pch.h"
#include "Application.h"

using namespace NinjaDee;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	Application* pApp = Application::GetApplication();

	if(!pApp->ConfigureEngine())
	{
		pApp->ShutdownEngine();
		return -1;
	}

	pApp->Initialize();

	pApp->MessageLoop();

	pApp->Shutdown();
	pApp->ShutdownEngine();

	return(true);
}