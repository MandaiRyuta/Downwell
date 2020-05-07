#pragma once
#include "EnemyParameter.h"

class BehaviorData;
class BehaviorTree;

class EnemySoul : public EnemyParameter
{
public:
	EnemySoul(BehaviorTree* aitree, int nhp, int nspeed);
	~EnemySoul();

	virtual void Update() override;
	virtual void Draw() override;
private:
	BehaviorData* AIData_;
	BehaviorTree* AITree_;
};