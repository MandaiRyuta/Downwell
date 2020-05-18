#pragma once
#include "ActionBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"
class EnemyParameter;

class LoiterningMoveAction : public ActionBase
{
private:
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
	/// インスタンス取得関数
	/// </summary>
	/// <returns>静的なLoiterningMoveActionのインスタンス</returns>
	static LoiterningMoveAction* GetInstance()
	{
		static LoiterningMoveAction instance;
		return &instance;
	}
	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="enemy">敵情報</param>
	/// <returns>ステート情報</returns>
	virtual ActionBase::STATE Run(EnemyParameter* enemy);
private:
	VECTOR vMove_[nLoiterningMoveMaxEnemy];	//敵の移動情報
};