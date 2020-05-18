#pragma once
#include "Widget.h"

class ResultWidget : public Widget
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	ResultWidget();
	/// <summary>
	/// デストラクター
	/// </summary>
	~ResultWidget();
public:
	/// <summary>
	/// 更新関数
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw() override;
private:
	int nResultLogoTexture_;	//リザルトのロゴテクスチャー
	int nClearTexture_;	//ゲームクリアテクスチャー
	int nFailedTexture_;	//ゲームオーバーテクスチャー
};