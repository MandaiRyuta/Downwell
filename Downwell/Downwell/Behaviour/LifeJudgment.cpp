#include "LifeJudgment.h"
#include "../Actor/EnemyParameter.h"
#include "../Actor/EnemyBird.h"
#include "../Actor/EnemySeaUrchin.h"
#include "../Actor/EnemyTurtle.h"
/// <summary>
/// 敵のHPを見て生死を判断する関数
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
