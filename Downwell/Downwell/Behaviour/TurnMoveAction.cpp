#include "TurnMoveAction.h"
#include "../Actor/EnemyParameter.h"
#include "../Collision/MapHitCheck.h"
#include "../DownwellConstant.h"
/// <summary>
/// 更新関数
/// </summary>
/// <param name="Enemy">敵情報</param>
/// <returns>ステート情報</returns>
ActionBase::STATE TurnMoveAction::Run(EnemyParameter& Enemy)
{
	float dammy = 0.0f;
	float gravity = -0.75f;

	if (Enemy.GetMoveType() == 0)
	{
		vMove_[Enemy.GetEnemyNumber()] = VGet(1.0f, fDefaultPos, fDefaultPos);
		Enemy.SetMoveType(1);
	}
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x - 5.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, gravity, 1);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x + 5.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, gravity, 1);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x - 5.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, gravity, 1);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x + 5.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, gravity, 1);

	if (vMove_[Enemy.GetEnemyNumber()].y >= -2.25f)
	{
		vMove_[Enemy.GetEnemyNumber()].y += gravity;
	}

	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x - 5.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, vMove_[Enemy.GetEnemyNumber()].y, 1);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x + 5.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, vMove_[Enemy.GetEnemyNumber()].y, 1);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x - 5.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, vMove_[Enemy.GetEnemyNumber()].y, 1);
	MapHitChecker::MapHitCollision(VGet(Enemy.GetPosition().x + 5.0f, Enemy.GetPosition().y - 9.0f, 0.0f), dammy, vMove_[Enemy.GetEnemyNumber()].y, 1);

	if (MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x - 9.0f, Enemy.GetPosition().y, 0.0f)) == 8 && 
		MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x + 9.0f, Enemy.GetPosition().y, 0.0f)) == 1 || 
		MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x + 9.0f, Enemy.GetPosition().y, 0.0f)) == 1 ||
		MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x + 9.0f, Enemy.GetPosition().y, 0.0f)) == 4 ||
		MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x + 9.0f, Enemy.GetPosition().y, 0.0f)) == 3 || 
		MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x - 9.0f, Enemy.GetPosition().y, 0.0f)) == 8)
	{
		vMove_[Enemy.GetEnemyNumber()].x = -1.0f;
	}
	else if (MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x + 9.0f, Enemy.GetPosition().y, 0.0f)) == 7 && 
		MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x - 9.0f, Enemy.GetPosition().y, 0.0f)) == 1 || 
		MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x - 9.0f, Enemy.GetPosition().y, 0.0f)) == 1 || 
		MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x - 9.0f, Enemy.GetPosition().y, 0.0f)) == 4 ||
		MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x - 9.0f, Enemy.GetPosition().y, 0.0f)) == 3 ||
		MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x + 9.0f, Enemy.GetPosition().y, 0.0f)) == 7)
	{
		vMove_[Enemy.GetEnemyNumber()].x = 1.0f;
	}
	
	Enemy.MovePosition(vMove_[Enemy.GetEnemyNumber()]);
	
	return ActionBase::STATE::COMPLETE;
}
