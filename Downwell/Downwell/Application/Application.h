#pragma once
#include "../Constant.h"

class Application
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	Application();
	/// <summary>
	/// デストラクター
	/// </summary>
	~Application();
public:
	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="OnResolved">未解決処理関数</param>
	/// <param name="OnRejected">未解決処理が処理されなかった時の関数</param>
	void Run(const Function<void()>& OnResolved, const Function<void()>& OnRejected);

	/// <summary>
	/// ウィンドウモード設定関数
	/// </summary>
	/// <param name="bWindow">true : ウィンドウモード　false : フルスクリーン</param>
	/// <returns>ウィンドウ情報</returns>
	Application& SetWindowMode(bool bWindow);
	/// <summary>
	/// 3D設定関数
	/// </summary>
	/// <param name="bEnabled">true : 3Dに設定する	false : 2Dに設定する</param>
	/// <returns>3D設定状況</returns>
	Application& SetUse3DFlag(bool bEnabled);
	/// <summary>
	/// 垂直同期設定関数
	/// </summary>
	/// <param name="bEnabled">true : 垂直同期する	false : 垂直同期しない</param>
	/// <returns></returns>
	Application& SetWaitVSyncFlag(bool bEnabled);

	/// <summary>
	/// 初期化関数
	/// </summary>
	void Init();
	/// <summary>
	/// 更新関数
	/// </summary>
	void Update();
	/// <summary>
	/// 解放関数
	/// </summary>
	void Release();
};