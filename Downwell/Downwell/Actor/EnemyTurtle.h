#pragma once
#include "EnemyParameter.h"

class BehaviorData;
class BehaviorTree;

class EnemyTurtle : public EnemyParameter
{
public:
	EnemyTurtle(BehaviorTree* aitree, int nhp, int nspeed);
	~EnemyTurtle();

	virtual void Update() override;
	virtual void Draw() override;

private:
	BehaviorData* AIData_;
	BehaviorTree* AITree_;
};