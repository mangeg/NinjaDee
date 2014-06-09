#include "Application.h"
#include "Win32RenderWindow.h"

using namespace NinjaDee;

class App : public Application
{
public:
	App();	
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Shutdown() override;

	virtual bool ConfigureEngine() override;
	virtual void ShutdownEngine() override;

	virtual std::wstring GetName() override;

protected:
	Win32RenderWindow* m_pRenderWindow;
};