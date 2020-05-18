#pragma once
#include "ActionBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"

class EnemyParameter;

class TurnMoveAction : public ActionBase
{
private:
	/// <summary>
	/// コンストラクター
	/// </summary>
	TurnMoveAction() : vMove_() {}
	/// <summary>
	/// デストラクター
	/// </summary>
	~TurnMoveAction() {}
public:
	/// <summary>
	/// インスタンス生成関数
	/// </summary>
	/// <returns>静的なTurnMoveActionのインスタンス</returns>
	static TurnMoveAction* GetInstance()
	{
		static TurnMoveAction instance;
		return &instance;
	}
	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="enemy">敵情報</param>
	/// <returns>ステート情報</returns>
	virtual ActionBase:: STATE Run(EnemyParameter* enemy) override;
private:
	VECTOR vMove_[nTurnMoveMaxEnemy];	//敵の移動量
};