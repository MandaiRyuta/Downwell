#include "Application.h"
#include "../DownwellConstant.h"

/// <summary>
/// コンストラクター
/// </summary>
Application::Application()
{
}
/// <summary>
/// デストラクター
/// </summary>
Application::~Application()
{
}
/// <summary>
/// 更新関数
/// </summary>
/// <param name="OnResolved">未解決処理関数</param>
/// <param name="OnRejected">未解決処理が処理されなかった時の関数</param>
void Application::Run(const std::function<void()>& OnResolved, const std::function<void()>& OnRejected)
{
	if (DxLib_Init() == Error)
	{
		ErrorLogAdd("Dxlib初期化失敗");
		return;
	}

	Init();

	OnResolved();
}
/// <summary>
/// ウィンドウモード設定関数
/// </summary>
/// <param name="bWindow">true : ウィンドウモード　false : フルスクリーン</param>
/// <returns>ウィンドウ情報</returns>
Application& Application::SetWindowMode(bool bWindow)
{
	ChangeWindowMode(bWindow ? TRUE : FALSE);
	return *this;
}
/// <summary>
/// 3D設定関数
/// </summary>
/// <param name="bEnabled">true : 3Dに設定する	false : 2Dに設定する</param>
/// <returns>3D設定状況</returns>
Application& Application::SetUse3DFlag(bool bEnabled)
{
	DxLib::SetUse3DFlag(bEnabled ? TRUE : FALSE);
	return *this;
}
/// <summary>
/// 垂直同期設定関数
/// </summary>
/// <param name="bEnabled">true : 垂直同期する	false : 垂直同期しない</param>
/// <returns></returns>
Application& Application::SetWaitVSyncFlag(bool bEnabled)
{
	DxLib::SetWaitVSyncFlag(bEnabled ? TRUE : FALSE);
	return *this;
}
/// <summary>
/// 初期化関数
/// </summary>
void Application::Init()
{
	SetGraphMode(static_cast<int>(ScreenWidth), static_cast<int>(ScreenHeight), 32);
	SetDrawScreen(DX_SCREEN_BACK);
}
/// <summary>
/// 更新関数
/// </summary>
void Application::Update()
{
	ClearDrawScreen();
}
/// <summary>
/// 解放関数
/// </summary>
void Application::Release()
{
	DxLib_End();
}
