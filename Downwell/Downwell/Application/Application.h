#pragma once
#include "../Constant.h"

class Application
{
public:
	//ウィンドウモードの設定と裏画面の描画を指定しました。
	Application();
	~Application();
public:
	void Run(const Function<void()>& OnResolved, const Function<void()>& OnRejected);

	Application& SetWindowMode(bool bWindow);
	Application& SetUse3DFlag(bool bEnabled);
	Application& SetWaitVSyncFlag(bool bEnabled);

	void Init();
	void Update();
	void Release();
};