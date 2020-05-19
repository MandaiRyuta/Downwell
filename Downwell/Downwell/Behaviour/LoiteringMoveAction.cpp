#include "LoiteringMoveAction.h"
#include "../Actor/EnemyParameter.h"
#include "../Collision/MapHitCheck.h"
#include "../Constant.h"
#include "../DownwellConstant.h"
#include "../Actor/Stage.h"
/// <summary>
/// �X�V�֐�
/// </summary>
/// <param name="enemy">�G���</param>
/// <returns>�X�e�[�g���</returns>
ActionBase::STATE LoiterningMoveAction::Run(EnemyParameter* enemy)
{
	float dammy = 0.0f;
	float gravity = -0.2f;
	
	if (enemy->GetMoveType() == 0)
	{
		vMove_[enemy->GetEnemyNumber()] = VGet(1.0f, fDefaultPos, fDefaultPos);
		enemy->SetMoveType(1);
	}

	//�E��
	if (MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x - 8.0f, enemy->GetPosition().y, 0.0f)) == 10)
	{
		vMove_[enemy->GetEnemyNumber()].x = fDefaultPos;
		vMove_[enemy->GetEnemyNumber()].y =-1.0f;
	}
	//�E��
	if (MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x, enemy->GetPosition().y + 8.0f, 0.0f)) == 11)
	{
		vMove_[enemy->GetEnemyNumber()].x = -1.0f;
		vMove_[enemy->GetEnemyNumber()].y = fDefaultPos;
	}
	//����
	if (MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x + 8.0f, enemy->GetPosition().y, 0.0f)) == 12)
	{
		vMove_[enemy->GetEnemyNumber()].x = fDefaultPos;
		vMove_[enemy->GetEnemyNumber()].y = 1.0f;
	}
	//����
	if (MapHitChecker::GetChipParam(VGet(enemy->GetPosition().x, enemy->GetPosition().y - 8.0f, 0.0f)) == 13)
	{
		vMove_[enemy->GetEnemyNumber()].x = 1.0f;
		vMove_[enemy->GetEnemyNumber()].y = fDefaultPos;
	}

	enemy->MovePosition(vMove_[enemy->GetEnemyNumber()]);

	return ActionBase::STATE::COMPLETE;
}
