#include "LifeJudgment.h"
#include "../Actor/EnemyParameter.h"
#include "../Actor/EnemyBird.h"
#include "../Actor/EnemySeaUrchin.h"
#include "../Actor/EnemyTurtle.h"

/// <summary>
/// 判定関数
/// </summary>
/// <param name="enemy">敵情報クラス</param>
/// <returns>判定	true : 判定終了		false : 判定続行</returns>
bool LifeJudgment::Judgment(EnemyParameter* enemy)
{
	if (enemy->GetHp() <= 0)
	{
		enemy->SetbLife(false);
		return false;
	}

	return true;
}
