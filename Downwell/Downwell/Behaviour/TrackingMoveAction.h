#pragma once
#include "ActionBase.h"

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