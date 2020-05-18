#pragma once
#include "Widget.h"

class BulletShotWidget : public Widget
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	BulletShotWidget();
	/// <summary>
	/// デストラクター
	/// </summary>
	~BulletShotWidget();
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
	int nBulletTexture_;	//弾のテクスチャー
	int nNonBulletTexture_;	//弾を使ったときのテクスチャー
	int nBulletCount_;	//弾の残弾数
};