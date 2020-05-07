#pragma once
#include "ActionBase.h"

class EnemyParameter;

class LoiterningMoveAction : public ActionBase
{
public:
	static LoiterningMoveAction* GetInstance()
	{
		LoiterningMoveAction instance;
		return &instance;
	}

	virtual ActionBase::STATE Run(EnemyParameter* enemy);
};