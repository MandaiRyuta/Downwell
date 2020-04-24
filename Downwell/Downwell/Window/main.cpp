#include "../Constant.h"

#ifdef DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "../Application/Application.h"
#include "../Fps/FpsCounter.h"
#include "../Level//LevelsResponsible.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"
#else
#include "../Application/Application.h"
#include "../Fps/FpsCounter.h"
#include "../Level//LevelsResponsible.h"
#include "../Input/Input.h"
#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
#ifdef DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Application application;
	FPS::FpsCounter fps;
	Camera::GetInstance().Init(VGet(0.0f, 0.0f, 0.0));
	
	application
		.SetWindowMode(true)
		.SetWaitVSyncFlag(false)
		.SetUse3DFlag(true)
		.Run([&]()
	{
		LevelsResponsible::GetInstance().Init();
		Input::GetInstance().Init();
		auto isLoop = []()
		{
			bool bEscape = CheckHitKey(KEY_INPUT_ESCAPE) == 0x001;

			bool bEnabledProcess = ProcessMessage() == 0;

			bool bEnabledLevel = LevelsResponsible::GetInstance().GetNowLevel() != 0;

			bool bLoop = !bEscape && bEnabledProcess && bEnabledLevel;

			return bLoop;
		};

		int loadtex = LoadGraph("Background.png");
		while (isLoop())
		{
			fps.Update();
			application.Update();

			LevelsResponsible::GetInstance().Update();
			Camera::GetInstance().Update();

			LevelsResponsible::GetInstance().Draw();
			fps.Draw();

			fps.WaitTime();

			ScreenFlip();
		}

		LevelsResponsible::GetInstance().Release();

		application.Release();
	},
	[&]()
	{
		application.Release();
	});
#else 
	Application application;
	FPS::FpsCounter fps;

	application
		.SetWindowMode(true)
		.SetWaitVSyncFlag(false)
		.SetUse3DFlag(true)
		.Run([&]()
	{
		LevelsResponsible::GetInstance().Init();

		auto isLoop = []()
		{
			bool bEscape = CheckHitKey(KEY_INPUT_ESCAPE) == 0x001;

			bool bEnabledProcess = ProcessMessage() == 0;

			bool bEnabledLevel = LevelsResponsible::GetInstance().GetNowLevel() != 0;

			bool bLoop = !bEscape && bEnabledProcess && bEnabledLevel;

			return bLoop;
		};

		while (isLoop())
		{
			fps.Update();
			application.Update();
			LevelsResponsible::GetInstance().Update();

			LevelsResponsible::GetInstance().Draw();
			fps.Draw();

			fps.WaitTime();

			ScreenFlip();
		}

		LevelsResponsible::GetInstance().Release();

		application.Release();
	},
			[&]()
	{
		application.Release();
	});
#endif
#ifdef DEBUG
	_CrtDumpMemoryLeaks();
#endif // DEBUG
	return 0;
}