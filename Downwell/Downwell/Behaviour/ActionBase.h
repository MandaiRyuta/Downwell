#pragma once

class EnemyParameter;	//敵パラメータークラス

class ActionBase
{
public:
	/// <summary>
	/// ステート
	/// </summary>
	enum class STATE
	{
		MOVE,
		FAILED,
		COMPLETE,
	};
	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="Enemy">敵情報</param>
	/// <returns>ステート情報</returns>
	virtual STATE Run(EnemyParameter& Enemy) = 0;
};