#include "LoiteringMoveAction.h"
#include "../Actor/EnemyParameter.h"
#include "../Collision/MapHitCheck.h"
#include "../Constant.h"
#include "../DownwellConstant.h"
#include "../Actor/Stage.h"
/// <summary>
/// 更新関数
/// </summary>
/// <param name="Enemy">敵情報</param>
/// <returns>ステート情報</returns>
ActionBase::STATE LoiterningMoveAction::Run(EnemyParameter& Enemy)
{
	float dammy = 0.0f;
	float gravity = -0.2f;
	
	if (Enemy.GetMoveType() == 0)
	{
		vMove_[Enemy.GetEnemyNumber()] = VGet(1.0f, fDefaultPos, fDefaultPos);
		Enemy.SetMoveType(1);
	}

	//右上
	if (MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x - 8.0f, Enemy.GetPosition().y, 0.0f)) == 10)
	{
		vMove_[Enemy.GetEnemyNumber()].x = fDefaultPos;
		vMove_[Enemy.GetEnemyNumber()].y =-1.0f;
	}
	//右下
	if (MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x, Enemy.GetPosition().y + 8.0f, 0.0f)) == 11)
	{
		vMove_[Enemy.GetEnemyNumber()].x = -1.0f;
		vMove_[Enemy.GetEnemyNumber()].y = fDefaultPos;
	}
	//左下
	if (MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x + 8.0f, Enemy.GetPosition().y, 0.0f)) == 12)
	{
		vMove_[Enemy.GetEnemyNumber()].x = fDefaultPos;
		vMove_[Enemy.GetEnemyNumber()].y = 1.0f;
	}
	//左上
	if (MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x, Enemy.GetPosition().y - 8.0f, 0.0f)) == 13)
	{
		vMove_[Enemy.GetEnemyNumber()].x = 1.0f;
		vMove_[Enemy.GetEnemyNumber()].y = fDefaultPos;
	}

	Enemy.MovePosition(vMove_[Enemy.GetEnemyNumber()]);

	return ActionBase::STATE::COMPLETE;
}
