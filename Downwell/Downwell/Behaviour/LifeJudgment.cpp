#include "LifeJudgment.h"
#include "../Actor/EnemyParameter.h"
#include "../Actor/EnemyBird.h"
#include "../Actor/EnemySeaUrchin.h"
#include "../Actor/EnemyTurtle.h"

bool LifeJudgment::Judgment(EnemyParameter* enemy)
{
	if (enemy->GetHp() <= 0)
	{
		enemy->SetbLife(false);
		return false;
	}

	return true;
}
