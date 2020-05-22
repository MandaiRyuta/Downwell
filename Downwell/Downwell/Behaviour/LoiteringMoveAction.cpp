#include "LoiteringMoveAction.h"
#include "../Actor/EnemyParameter.h"
#include "../Collision/MapHitCheck.h"
#include "../Constant.h"
#include "../DownwellConstant.h"
#include "../Actor/Stage.h"
/// <summary>
/// �X�V�֐�
/// </summary>
/// <param name="Enemy">�G���</param>
/// <returns>�X�e�[�g���</returns>
ActionBase::STATE LoiterningMoveAction::Run(EnemyParameter& Enemy)
{
	float dammy = 0.0f;
	float gravity = -0.2f;
	
	if (Enemy.GetMoveType() == 0)
	{
		vMove_[Enemy.GetEnemyNumber()] = VGet(1.0f, fDefaultPos, fDefaultPos);
		Enemy.SetMoveType(1);
	}

	//�E��
	if (MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x - 8.0f, Enemy.GetPosition().y, 0.0f)) == 10)
	{
		vMove_[Enemy.GetEnemyNumber()].x = fDefaultPos;
		vMove_[Enemy.GetEnemyNumber()].y =-1.0f;
	}
	//�E��
	if (MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x, Enemy.GetPosition().y + 8.0f, 0.0f)) == 11)
	{
		vMove_[Enemy.GetEnemyNumber()].x = -1.0f;
		vMove_[Enemy.GetEnemyNumber()].y = fDefaultPos;
	}
	//����
	if (MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x + 8.0f, Enemy.GetPosition().y, 0.0f)) == 12)
	{
		vMove_[Enemy.GetEnemyNumber()].x = fDefaultPos;
		vMove_[Enemy.GetEnemyNumber()].y = 1.0f;
	}
	//����
	if (MapHitChecker::GetChipParam(VGet(Enemy.GetPosition().x, Enemy.GetPosition().y - 8.0f, 0.0f)) == 13)
	{
		vMove_[Enemy.GetEnemyNumber()].x = 1.0f;
		vMove_[Enemy.GetEnemyNumber()].y = fDefaultPos;
	}

	Enemy.MovePosition(vMove_[Enemy.GetEnemyNumber()]);

	return ActionBase::STATE::COMPLETE;
}
