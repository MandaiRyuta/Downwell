#pragma once
#include "ActionBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"

class EnemyParameter;

class TurnMoveAction : public ActionBase
{
public:
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
	/// 更新関数
	/// </summary>
	/// <param name="Enemy">敵情報</param>
	/// <returns>ステート情報</returns>
	virtual ActionBase:: STATE Run(EnemyParameter& Enemy) override;
private:
	VECTOR vMove_[nTurnMoveMaxEnemy];	//敵の移動量
};