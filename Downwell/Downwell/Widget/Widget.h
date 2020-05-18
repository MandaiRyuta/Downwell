#pragma once
#include "../Actor/Actor.h"
#include "../Resource/TextureData.h"

class Widget
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	Widget() {}
	/// <summary>
	/// デストラクター
	/// </summary>
	virtual ~Widget() {}
public:
	/// <summary>
	/// 更新関数
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw() = 0;
};