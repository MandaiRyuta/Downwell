#include "TrackingMoveAction.h"
#include "../Actor/EnemyParameter.h"
#include "../Collision/MapHitCheck.h"
#include "../DownwellConstant.h"
#include "../Actor/Character.h"
#include "../DownwellConstant.h"
/// <summary>
/// 更新関数
/// </summary>
/// <param name="enemy">敵情報</param>
/// <returns>ステート情報</returns>
ActionBase::STATE TrackingMoveAction::Run(EnemyParameter* enemy)
{
	float dammy = 0.0f;
	float fmovey = 0.0f;
	float fmovex = 0.0f;
	float flypower = 1.0f;
	float movespeed = 0.5f;

	if (enemy->GetMoveType() == 0)
	{
		vMove_[enemy->GetEnemyNumber()] = VGet(fDefaultPos, fDefaultPos, fDefaultPos);
		enemy->SetMoveType(1);
	}
	fmovey = flypower;
	fmovex = movespeed;
	//修正
	//MapHitChecker::MapHitCollision()　を使用してめり込みを防いでみる
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y + 9.0f, 0.0f), dammy, fmovey);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y + 9.0f, 0.0f), dammy, fmovey);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y + 9.0f, 0.0f), dammy, fmovey);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y + 9.0f, 0.0f), dammy, fmovey);

	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, fmovey);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, fmovey);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, fmovey);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, fmovey);
	
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

	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y + 9.0f, 0.0f), dammy, vMove_[enemy->GetEnemyNumber()].y);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y + 9.0f, 0.0f), dammy, vMove_[enemy->GetEnemyNumber()].y);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y + 9.0f, 0.0f), dammy, vMove_[enemy->GetEnemyNumber()].y);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y + 9.0f, 0.0f), dammy, vMove_[enemy->GetEnemyNumber()].y);
	
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, vMove_[enemy->GetEnemyNumber()].y);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, vMove_[enemy->GetEnemyNumber()].y);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, vMove_[enemy->GetEnemyNumber()].y);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dammy, vMove_[enemy->GetEnemyNumber()].y);


	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y + 9.0f, 0.0f), fmovex, dammy);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y + 9.0f, 0.0f), fmovex, dammy);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y - 9.0f, 0.0f), fmovex, dammy);
	MapHitChecker::MapHitCollision(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y - 9.0f, 0.0f), fmovex, dammy);

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
