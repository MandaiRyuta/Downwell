#pragma once
#include "Widget.h"

class LifeWidget : public Widget
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	LifeWidget();
	/// <summary>
	/// デストラクター
	/// </summary>
	~LifeWidget();
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
	int nTextureWidth_;	//テクスチャー幅
	int nGameCharacterLifeTexture_;	//プレイヤーの体力テクスチャー
};