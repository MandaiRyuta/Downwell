#pragma once
#include "../Actor/EnemyParameter.h"
#include "../Constant.h"
#include "../DownwellConstant.h"

namespace AliveChecker
{
	/// <summary>
	/// 敵のHPを見て生死を判断する関数
	/// <param name="Enemy">敵情報</param>
	/// </summary>
	bool SetDead(EnemyParameter& Enemy);
}