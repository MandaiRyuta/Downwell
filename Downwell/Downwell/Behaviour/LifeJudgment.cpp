#include "LifeJudgment.h"
#include "../Actor/EnemyParameter.h"
#include "../Actor/EnemyBird.h"
#include "../Actor/EnemySeaUrchin.h"
#include "../Actor/EnemyTurtle.h"
/// <summary>
/// �G��HP�����Đ����𔻒f����֐�
/// </summary>
bool AliveChecker::SetDead(EnemyParameter& Enemy)
{
	if (Enemy.GetHp() <= nZeroLife)
	{
		Enemy.SetbLife(false);
		return true;
	}

	return false;
}
