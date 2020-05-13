#pragma once
#include "JudgmentBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"

class EnemyParameter;
class LifeJudgment : public JudgmentBase
{
public:
	static LifeJudgment* GetInstance()
	{
		static LifeJudgment Instance;
		return &Instance;
	}

	virtual bool Judgment(EnemyParameter* enemy) override;
};