#pragma once
#include "../Constant.h"

class Application
{
public:
	//�E�B���h�E���[�h�̐ݒ�Ɨ���ʂ̕`����w�肵�܂����B
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