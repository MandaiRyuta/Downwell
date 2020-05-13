#pragma once
#include "ActionBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"
class EnemyParameter;

class TrackingMoveAction : public ActionBase
{
public:
	static TrackingMoveAction* GetInstance()
	{
		static TrackingMoveAction instance;

		return &instance;
	}

	virtual ActionBase::STATE Run(EnemyParameter* enemy) override;
private:
	//static float fPositiony;
	VECTOR vMove_[nTrackingMoveMaxEnemy];
};