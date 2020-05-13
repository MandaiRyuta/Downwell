#include "TrackingMoveAction.h"
#include "../Actor/EnemyParameter.h"
#include "../Collision/MapHitCheck.h"
#include "../DownwellConstant.h"
#include "../Actor/Character.h"

//float TrackingMoveAction::fmovey = 0.0f;

ActionBase::STATE TrackingMoveAction::Run(EnemyParameter* enemy)
{
	float dammy = 0.0f;
	float fmovey = 0.0f;
	float fmovex = 0.0f;
	float flypower = 1.0f;
	float movespeed = 0.5f;

	if (enemy->GetMoveType() == 0)
	{
		vMove_[enemy->GetEnemyNumber()] = VGet(0.0f, 0.0f, 0.0f);
		enemy->SetMoveType(1);
	}
	fmovey = flypower;
	fmovex = movespeed;
	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y + 9.0f, 0.0f), dammy, fmovey);
	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y + 9.0f, 0.0f), dammy, fmovey);
	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y + 9.0f, 0.0f), dammy, fmovey);
	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y + 9.0f, 0.0f), dammy, fmovey);

	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, fmovey);
	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, fmovey);
	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, fmovey);
	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, fmovey);
	
	if (Character::GetPos().y > enemy->GetPosition().y)
	{
		if (fmovey == 0.0f)
		{
			vMove_[enemy->GetEnemyNumber()].y = -1.5f;
		}
		else
		{
			vMove_[enemy->GetEnemyNumber()].y = fmovey;
		}
	}
	else if (Character::GetPos().y <= enemy->GetPosition().y)
	{
		if (fmovey == 0.0f)
		{
			vMove_[enemy->GetEnemyNumber()].y = 1.5f;
		}
		else
		{
			vMove_[enemy->GetEnemyNumber()].y = -fmovey;
		}
	}

	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y + 9.0f, 0.0f), fmovex, dammy);
	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y + 9.0f, 0.0f), fmovex, dammy);
	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y - 9.0f, 0.0f), fmovex, dammy);
	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y - 9.0f, 0.0f), fmovex, dammy);

	if (Character::GetPos().x < enemy->GetPosition().x)
	{
		if (fmovex != 0.0f)
		{
			vMove_[enemy->GetEnemyNumber()].x = -movespeed;
		}
		else
		{
			vMove_[enemy->GetEnemyNumber()].x = movespeed;
		}
	}
	else if (Character::GetPos().x >= enemy->GetPosition().x)
	{
		if (fmovex != 0.0f)
		{
			vMove_[enemy->GetEnemyNumber()].x = movespeed;
		}
		else
		{
			vMove_[enemy->GetEnemyNumber()].x = -movespeed;
		}
	}

	enemy->MovePosition(vMove_[enemy->GetEnemyNumber()]);

	return ActionBase::STATE::COMPLETE;
}
