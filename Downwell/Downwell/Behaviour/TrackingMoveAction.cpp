#include "TrackingMoveAction.h"
#include "../Actor/EnemyParameter.h"
#include "../Collision/MapHitCheck.h"
#include "../DownwellConstant.h"
#include "../Actor/Character.h"
#include "../DownwellConstant.h"
/// <summary>
/// 更新関数
/// </summary>
/// <param name="Enemy">敵情報</param>
/// <returns>ステート情報</returns>
ActionBase::STATE TrackingMoveAction::Run(EnemyParameter& Enemy)
{
	float dammy = 0.0f;
	float fmovey = 0.0f;
	float fmovex = 0.0f;
	float flypower = 1.0f;
	float movespeed = 0.5f;

	if (Enemy.GetMoveType() == 0)
	{
		vMove_[Enemy.GetEnemyNumber()] = VGet(fDefaultPos, fDefaultPos, fDefaultPos);
		Enemy.SetMoveType(1);
	}
	fmovey = flypower;
	fmovex = movespeed;
	//修正
	//MapHitChecker::MapHitCollision()　を使用してめり込みを防いでみる
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x - 5.0f, Enemy.GetPosition().y + 9.0f, 0.0f), dammy, fmovey, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x + 5.0f, Enemy.GetPosition().y + 9.0f, 0.0f), dammy, fmovey, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x - 5.0f, Enemy.GetPosition().y + 9.0f, 0.0f), dammy, fmovey, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x + 5.0f, Enemy.GetPosition().y + 9.0f, 0.0f), dammy, fmovey, 0);

	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x - 5.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, fmovey, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x + 5.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, fmovey, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x - 5.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, fmovey, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x + 5.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, fmovey, 0);
	
	if (Character::GetPos().y > Enemy.GetPosition().y)
	{
		if (fmovey == 0.0f)
		{
			vMove_[Enemy.GetEnemyNumber()].y = -1.0f;
		}
		else
		{
			vMove_[Enemy.GetEnemyNumber()].y = 1.0f;
		}
	}
	else if (Character::GetPos().y < Enemy.GetPosition().y)
	{
		if (fmovey == 0.0f)
		{
			vMove_[Enemy.GetEnemyNumber()].y = 1.0f;
		}
		else
		{
			vMove_[Enemy.GetEnemyNumber()].y = -1.0f;
		}
	}

	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x - 9.0f, Enemy.GetPosition().y + 9.0f, 0.0f), fmovex, dammy, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x + 9.0f, Enemy.GetPosition().y + 9.0f, 0.0f), fmovex, dammy, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x - 9.0f, Enemy.GetPosition().y - 9.0f, 0.0f), fmovex, dammy, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x + 9.0f, Enemy.GetPosition().y - 9.0f, 0.0f), fmovex, dammy, 0);

	if (Character::GetPos().x < Enemy.GetPosition().x)
	{
		if (fmovex != 0.0f)
		{
			vMove_[Enemy.GetEnemyNumber()].x = -movespeed;
		}
		else
		{
			vMove_[Enemy.GetEnemyNumber()].x = movespeed;
		}
	}
	else if (Character::GetPos().x >= Enemy.GetPosition().x)
	{
		if (fmovex != 0.0f)
		{
			vMove_[Enemy.GetEnemyNumber()].x = movespeed;
		}
		else
		{
			vMove_[Enemy.GetEnemyNumber()].x = -movespeed;
		}
	}

	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x - 9.0f, Enemy.GetPosition().y + 9.0f, 0.0f), dammy, vMove_[Enemy.GetEnemyNumber()].y, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x + 9.0f, Enemy.GetPosition().y + 9.0f, 0.0f), dammy, vMove_[Enemy.GetEnemyNumber()].y, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x - 9.0f, Enemy.GetPosition().y + 9.0f, 0.0f), dammy, vMove_[Enemy.GetEnemyNumber()].y, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x + 9.0f, Enemy.GetPosition().y + 9.0f, 0.0f), dammy, vMove_[Enemy.GetEnemyNumber()].y, 0);

	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x - 9.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, vMove_[Enemy.GetEnemyNumber()].y, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x + 9.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, vMove_[Enemy.GetEnemyNumber()].y, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x - 9.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, vMove_[Enemy.GetEnemyNumber()].y, 0);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x + 9.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, vMove_[Enemy.GetEnemyNumber()].y, 0);

	Enemy.MovePosition(vMove_[Enemy.GetEnemyNumber()]);

	return ActionBase::STATE::COMPLETE;
}
