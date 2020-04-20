#include "Application.h"


Application::Application()
{
}

Application::~Application()
{
}

void Application::Run(const Function<void()>& OnResolved, const Function<void()>& OnRejected)
{
	if (DxLib_Init() == -1)
	{
		ErrorLogAdd("Dxlibèâä˙âªé∏îs");
		return;
	}

	Init();

	OnRejected();
}

Application& Application::SetWindowMode(bool bWindow)
{
	ChangeWindowMode(bWindow ? true : false);
	return *this;
}

Application& Application::SetUse3DFlag(bool bEnabled)
{
	DxLib::SetUse3DFlag(bEnabled ? true : false);
	return *this;
}

Application& Application::SetWaitVSyncFlag(bool bEnabled)
{
	DxLib::SetWaitVSyncFlag(bEnabled ? true : false);
	return *this;
}

void Application::Init()
{
	SetGraphMode(640, 480, 32);
	SetDrawScreen(DX_SCREEN_BACK);
}

void Application::Update()
{
	ClearDrawScreen();
}

void Application::Release()
{
	DxLib_End();
}
