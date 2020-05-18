#pragma once
#include "Widget.h"

class TitleWidget : public Widget
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	TitleWidget();
	/// <summary>
	/// デストラクター
	/// </summary>
	~TitleWidget();
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
	int nTitleLogoTexture_;	//タイトルロゴテクスチャー
};