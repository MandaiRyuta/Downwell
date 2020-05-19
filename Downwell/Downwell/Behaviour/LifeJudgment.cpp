#include "LifeJudgment.h"
#include "../Actor/EnemyParameter.h"
#include "../Actor/EnemyBird.h"
#include "../Actor/EnemySeaUrchin.h"
#include "../Actor/EnemyTurtle.h"

bool AliveChecker::SetDead(EnemyParameter* enemy)
{
	if (enemy->GetHp() <= nZeroLife)
	{
		enemy->SetbLife(false);
		return true;
	}

	return false;
}
