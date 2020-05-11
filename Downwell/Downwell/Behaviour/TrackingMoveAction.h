#pragma once
#include "ActionBase.h"
#include "../Constant.h"

class EnemyParameter;

class TrackingMoveAction : public ActionBase
{
public:
	static TrackingMoveAction* GetInstance()
	{
		TrackingMoveAction instance;

		return &instance;
	}

	virtual ActionBase::STATE Run(EnemyParameter* enemy) override;
};