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

	OnResolved();
}

Application& Application::SetWindowMode(bool bWindow)
{
	ChangeWindowMode(bWindow ? TRUE : FALSE);
	return *this;
}

Application& Application::SetUse3DFlag(bool bEnabled)
{
	DxLib::SetUse3DFlag(bEnabled ? TRUE : FALSE);
	return *this;
}

Application& Application::SetWaitVSyncFlag(bool bEnabled)
{
	DxLib::SetWaitVSyncFlag(bEnabled ? TRUE : FALSE);
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
