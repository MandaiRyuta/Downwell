#pragma once
#include "EnemyParameter.h"

class BehaviorData;
class BehaviorTree;

class EnemySkeleton : public EnemyParameter
{
public:
	EnemySkeleton(BehaviorTree* aitree, int nhp, int nspeed);
	~EnemySkeleton();

	virtual void Update() override;
	virtual void Draw() override;
private:
	BehaviorData* AIData_;
	BehaviorTree* AITree_;
};
