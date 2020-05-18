#pragma once

class Actor
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	Actor(){}
	/// <summary>
	/// 仮想デストラクター
	/// </summary>
	virtual ~Actor(){}
	/// <summary>
	/// 更新関数
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw() = 0;
};