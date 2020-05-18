#pragma once
#include "Widget.h"

class StageWidget : public Widget
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	StageWidget();
	/// <summary>
	/// デストラクター
	/// </summary>
	~StageWidget();
	/// <summary>
	/// 更新関数
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw() override;
};