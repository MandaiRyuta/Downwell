#include "TurnMoveAction.h"
#include "../Actor/EnemyParameter.h"
#include "../Collision/MapHitCheck.h"
#include "../DownwellConstant.h"
/// <summary>
/// 更新関数
/// </summary>
/// <param name="enemy">敵情報</param>
/// <returns>ステート情報</returns>
ActionBase::STATE TurnMoveAction::Run(EnemyParameter* enemy)
{
	float dammy = 0.0f;
	float gravity = -0.75f;

	if (enemy->GetMoveType() == 0)
	{
		vMove_[enemy->GetEnemyNumber()] = VGet(1.0f, fDefaultPos, fDefaultPos);
		enemy->SetMoveType(1);
	}

	if (vMove_[enemy->GetEnemyNumber()].y >= -2.25f)
	{
		vMove_[enemy->GetEnemyNumber()].y += gravity;
	}

	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, vMove_[enemy->GetEnemyNumber()].y);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, vMove_[enemy->GetEnemyNumber()].y);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, vMove_[enemy->GetEnemyNumber()].y);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, vMove_[enemy->GetEnemyNumber()].y);

	if (MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y, 0.0f)) == 8 && 
		MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y, 0.0f)) == 1 || 
		MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y, 0.0f)) == 1 ||
		MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y, 0.0f)) == 4 ||
		MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y, 0.0f)) == 3 || 
		MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y, 0.0f)) == 8)
	{
		vMove_[enemy->GetEnemyNumber()].x = -1.0f;
	}
	else if (MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y, 0.0f)) == 7 && 
		MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y, 0.0f)) == 1 || 
		MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y, 0.0f)) == 1 || 
		MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y, 0.0f)) == 4 ||
		MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y, 0.0f)) == 3 ||
		MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y, 0.0f)) == 7)
	{
		vMove_[enemy->GetEnemyNumber()].x = 1.0f;
	}
	
	enemy->MovePosition(vMove_[enemy->GetEnemyNumber()]);
	
	return ActionBase::STATE::COMPLETE;
}
