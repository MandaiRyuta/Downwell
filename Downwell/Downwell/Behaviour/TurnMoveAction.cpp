#include "TurnMoveAction.h"
#include "../Actor/EnemyParameter.h"
#include "../Collision/MapHitCheck.h"
#include "../DownwellConstant.h"

ActionBase::STATE TurnMoveAction::Run(EnemyParameter* enemy)
{
	float dummy = 0.0f;
	float gravity = -0.2f;

	if (enemy->GetMoveType() == 0)
	{
		Move_[enemy->GetEnemyNumber()] = VGet(1.0f, 0.0f, 0.0f);
		enemy->SetMoveType(1);
	}

	Move_[enemy->GetEnemyNumber()].y += gravity;

	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dummy, Move_[enemy->GetEnemyNumber()].y);
	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dummy, Move_[enemy->GetEnemyNumber()].y);
	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x - 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dummy, Move_[enemy->GetEnemyNumber()].y);
	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x + 5.0f, enemy->GetPosition().y - 9.0f, 0.0f), dummy, Move_[enemy->GetEnemyNumber()].y);
	

	//if (MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x - 10.0f, enemy->GetPosition().y + 10.0f, 0.0f), Move_.x, dummy) ||
	//	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x + 10.0f, enemy->GetPosition().y + 10.0f, 0.0f), Move_.x, dummy) ||
	//	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x - 10.0f, enemy->GetPosition().y - 10.0f, 0.0f), Move_.x, dummy) ||
	//	MapHitCheck::MapHitCollision(VGet(enemy->GetPosition().x + 10.0f, enemy->GetPosition().y - 10.0f, 0.0f), Move_.x, dummy))
	//{
	//	Move_.x = 1.0f;
	//}

	if (MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y, 0.0f)) == 8 && 
		MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y, 0.0f)) == 1 || 
		MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y, 0.0f)) == 1 ||
		MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y, 0.0f)) == 4 ||
		MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y, 0.0f)) == 3 || 
		MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y, 0.0f)) == 8)
	{
		Move_[enemy->GetEnemyNumber()].x = -1.0f;
	}
	else if (MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y, 0.0f)) == 7 && 
		MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y, 0.0f)) == 1 || 
		MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y, 0.0f)) == 1 || 
		MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y, 0.0f)) == 4 ||
		MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x - 9.0f, enemy->GetPosition().y, 0.0f)) == 3 ||
		MapHitCheck::GetChipParam(VGet(enemy->GetPosition().x + 9.0f, enemy->GetPosition().y, 0.0f)) == 7)
	{
		Move_[enemy->GetEnemyNumber()].x = 1.0f;
	}
	
	enemy->MovePosition(Move_[enemy->GetEnemyNumber()]);
	
	return ActionBase::STATE::COMPLETE;
}
