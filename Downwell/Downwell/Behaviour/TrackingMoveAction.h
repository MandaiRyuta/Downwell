#pragma once
#include "ActionBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"
class EnemyParameter;

class TrackingMoveAction : public ActionBase
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	TrackingMoveAction() : vMove_() {}
	/// <summary>
	/// デストラクター
	/// </summary>
	~TrackingMoveAction() {}
public:
	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="Enemy">敵情報</param>
	/// <returns>ステート情報</returns>
	virtual ActionBase::STATE Run(EnemyParameter& Enemy) override;
private:
	VECTOR vMove_[nTrackingMoveMaxEnemy];	//敵の移動量
};