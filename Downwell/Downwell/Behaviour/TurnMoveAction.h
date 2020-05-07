#pragma once

#include "ActionBase.h"

class EnemyParameter;

class TurnMoveAction : public ActionBase
{
public:
	static TurnMoveAction* GetInstance()
	{
		static TurnMoveAction instance;
		return &instance;
	}

	virtual ActionBase:: STATE Run(EnemyParameter* enemy) override;
};