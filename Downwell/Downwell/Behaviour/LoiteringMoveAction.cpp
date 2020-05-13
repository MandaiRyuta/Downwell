#include "LoiteringMoveAction.h"
#include "../Actor/EnemyParameter.h"
#include "../Collision/MapHitCheck.h"
#include "../Constant.h"
#include "../DownwellConstant.h"
#include "../Actor/Stage.h"

ActionBase::STATE LoiterningMoveAction::Run(EnemyParameter* enemy)
{
	float dammy = 0.0f;
	float gravity = -0.2f;
	
	if (enemy->GetMoveType() == 0)
	{
		vMove_[enemy->GetEnemyNumber()] = VGet(1.0f, 0.0f, 0.0f);
		enemy->SetMoveType(1);
	}

	//‰Eã
	if (MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x - 8.0f, enemy->GetPosition().y, 0.0f)) == 10)
	{
		vMove_[enemy->GetEnemyNumber()].x = 0.0f;
		vMove_[enemy->GetEnemyNumber()].y =-1.0f;
	}
	//‰E‰º
	if (MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x, enemy->GetPosition().y + 8.0f, 0.0f)) == 11)
	{
		vMove_[enemy->GetEnemyNumber()].x = -1.0f;
		vMove_[enemy->GetEnemyNumber()].y =  0.0f;
	}
	//¶‰º
	if (MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x + 8.0f, enemy->GetPosition().y, 0.0f)) == 12)
	{
		vMove_[enemy->GetEnemyNumber()].x = 0.0f;
		vMove_[enemy->GetEnemyNumber()].y = 1.0f;
	}
	//¶ã
	if (MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x, enemy->GetPosition().y - 8.0f, 0.0f)) == 13)
	{
		vMove_[enemy->GetEnemyNumber()].x = 1.0f;
		vMove_[enemy->GetEnemyNumber()].y = 0.0f;
	}


	enemy->MovePosition(vMove_[enemy->GetEnemyNumber()]);

	return ActionBase::STATE::COMPLETE;
}
