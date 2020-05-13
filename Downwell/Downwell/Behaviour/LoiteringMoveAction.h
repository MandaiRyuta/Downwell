#pragma once
#include "ActionBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"
class EnemyParameter;

class LoiterningMoveAction : public ActionBase
{
public:
	static LoiterningMoveAction* GetInstance()
	{
		static LoiterningMoveAction instance;
		return &instance;
	}

	virtual ActionBase::STATE Run(EnemyParameter* enemy);
private:
	VECTOR vMove_[nLoiterningMoveMaxEnemy];
};