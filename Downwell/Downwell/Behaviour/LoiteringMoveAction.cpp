#include "LoiteringMoveAction.h"
#include "../Actor/EnemyParameter.h"
#include "../Collision/MapHitCheck.h"
#include "../Constant.h"
#include "../DownwellConstant.h"
#include "../Actor/Stage.h"
/// <summary>
/// 更新関数
/// </summary>
/// <param name="enemy">敵情報</param>
/// <returns>ステート情報</returns>
ActionBase::STATE LoiterningMoveAction::Run(EnemyParameter* enemy)
{
	float dammy = 0.0f;
	float gravity = -0.2f;
	
	if (enemy->GetMoveType() == 0)
	{
		vMove_[enemy->GetEnemyNumber()] = VGet(1.0f, fDefaultPos, fDefaultPos);
		enemy->SetMoveType(1);
	}

	//右上
	if (MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x - 8.0f, enemy->GetPosition().y, 0.0f)) == 10)
	{
		vMove_[enemy->GetEnemyNumber()].x = fDefaultPos;
		vMove_[enemy->GetEnemyNumber()].y =-1.0f;
	}
	//右下
	if (MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x, enemy->GetPosition().y + 8.0f, 0.0f)) == 11)
	{
		vMove_[enemy->GetEnemyNumber()].x = -1.0f;
		vMove_[enemy->GetEnemyNumber()].y = fDefaultPos;
	}
	//左下
	if (MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x + 8.0f, enemy->GetPosition().y, 0.0f)) == 12)
	{
		vMove_[enemy->GetEnemyNumber()].x = fDefaultPos;
		vMove_[enemy->GetEnemyNumber()].y = 1.0f;
	}
	//左上
	if (MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x, enemy->GetPosition().y - 8.0f, 0.0f)) == 13)
	{
		vMove_[enemy->GetEnemyNumber()].x = 1.0f;
		vMove_[enemy->GetEnemyNumber()].y = fDefaultPos;
	}

	enemy->MovePosition(vMove_[enemy->GetEnemyNumber()]);

	return ActionBase::STATE::COMPLETE;
}
