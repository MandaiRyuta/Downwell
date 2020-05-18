#pragma once

class Level
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	Level() {}
	/// <summary>
	/// デストラクター
	/// </summary>
	virtual ~Level() {};
	
	/// <summary>
	/// 更新関数
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw() = 0;
};