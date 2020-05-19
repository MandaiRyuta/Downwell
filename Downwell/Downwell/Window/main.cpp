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
#include "../Resource/TextureData.h"
#else
#include "../Application/Application.h"
#include "../Fps/FpsCounter.h"
#include "../Level//LevelsResponsible.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"
#include "../Resource/TextureData.h"
#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Application application;
	FPS::FpsCounter fps;
	Camera::GetInstance().Init(VGet(ScreenWidth / 2 + 20.0f, -300.0f, -30.0));
	int screen = MakeGraph(256, 256);
#ifdef DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SetDrawValidGraphCreateFlag(TRUE);
	SetDrawValidGraphCreateFlag(FALSE);
	application
		.SetWindowMode(true)
		.SetWaitVSyncFlag(true)
		.SetUse3DFlag(true)
		.Run([&]()
	{
		LevelsResponsible::GetInstance().Init();
		Input::GetInstance().Init();
		auto isLoop = []()
		{
			bool bEscape = CheckHitKey(KEY_INPUT_ESCAPE) == 0x001;

			bool bEnabledProcess = ProcessMessage() == 0;

			bool bEnabledLevel = LevelsResponsible::GetInstance().GetNowLevel() != 3;
			bool bTitleLevelCheck = TextureDataBase::TextureData::GetInstance().GetTitleTextureData(TextureDataBase::TitleTextureNumber::TTitleLogo) > 0;
			bool bGameLevelCheck = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GCharacterLife) > 0;
			bool bResultLevelCheck = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::RFailed) > 0;
			bool bLoop = bEnabledProcess && bEnabledLevel && !bEscape && bTitleLevelCheck ||
						bEnabledProcess && bEnabledLevel && !bEscape && bGameLevelCheck ||
						bEnabledProcess && bEnabledLevel && !bEscape && bResultLevelCheck;


			return bLoop;
		};

		while (isLoop())
		{
			fps.Update();
			application.Update();
			Camera::GetInstance().Update();

			LevelsResponsible::GetInstance().Update();
			LevelsResponsible::GetInstance().Draw();
			Camera::GetInstance().DebugCamera();
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
	SetDrawValidGraphCreateFlag(TRUE);
	SetDrawValidGraphCreateFlag(FALSE);
	application
		.SetWindowMode(true)
		.SetWaitVSyncFlag(true)
		.SetUse3DFlag(true)
		.Run([&]()
	{
		LevelsResponsible::GetInstance().Init();
		Input::GetInstance().Init();
		auto isLoop = []()
		{
			bool bEscape = CheckHitKey(KEY_INPUT_ESCAPE) == 0x001;

			bool bEnabledProcess = ProcessMessage() == 0;

			bool bEnabledLevel = LevelsResponsible::GetInstance().GetNowLevel() != 3;
			bool bTitleLevelCheck = TextureDataBase::TextureData::GetInstance().GetTitleTextureData(TextureDataBase::TitleTextureNumber::TTitleLogo) > 0;
			bool bGameLevelCheck = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GCharacterLife) > 0;
			bool bResultLevelCheck = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::RFailed) > 0;
			bool bLoop = bEnabledProcess && bEnabledLevel && !bEscape && bTitleLevelCheck ||
				bEnabledProcess && bEnabledLevel && !bEscape && bGameLevelCheck ||
				bEnabledProcess && bEnabledLevel && !bEscape && bResultLevelCheck;


			return bLoop;
		};

		while (isLoop())
		{
			fps.Update();
			application.Update();
			Camera::GetInstance().Update();

			LevelsResponsible::GetInstance().Update();
			LevelsResponsible::GetInstance().Draw();
			Camera::GetInstance().DebugCamera();
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