#pragma once
#include "ActionBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"
class EnemyParameter;

class LoiterningMoveAction : public ActionBase
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	LoiterningMoveAction() : vMove_(){}
	/// <summary>
	/// デストラクター
	/// </summary>
	~LoiterningMoveAction() {}
public:
	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="Enemy">敵情報</param>
	/// <returns>ステート情報</returns>
	virtual ActionBase::STATE Run(EnemyParameter& Enemy);
private:
	VECTOR vMove_[nLoiterningMoveMaxEnemy];	//敵の移動情報
};