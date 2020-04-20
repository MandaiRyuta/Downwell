#include "../Constant.h"

#ifdef DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "../Application/Application.h"
#include "../Fps/FpsCounter.h"
#else
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
#ifdef DEBUG
	Application application;
	FPS::FpsCounter fps;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	application
		.SetWindowMode(true)
		.SetWaitVSyncFlag(false)
		.SetUse3DFlag(true)
		.Run([&]()
	{
		auto isLoop = []()
		{
			bool bEscape = CheckHitKey(KEY_INPUT_ESCAPE) == 0x001;

			bool bEnabledProcess = ProcessMessage() == 0;

			bool bLoop = !bEscape && bEnabledProcess;

			return bLoop;
		};

		while (isLoop())
		{
			fps.Update();
			application.Update();

			fps.Draw();
			fps.WaitTime();

			ScreenFlip();
		}


		application.Release();
	},[&]()
	{
		application.Release();
	});
#else

#endif

	_CrtDumpMemoryLeaks();
	return 0;
}