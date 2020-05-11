#pragma once
#include "ActionBase.h"
#include "../Constant.h"

class EnemyParameter;

class RiseMoveAction : public ActionBase
{
public:
	static RiseMoveAction* GetInstance()
	{
		RiseMoveAction instance;
		return &instance;
	}

	virtual ActionBase::STATE Run(EnemyParameter* enemy) override;
private:
	VECTOR vMove_;
};