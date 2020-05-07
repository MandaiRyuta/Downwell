#pragma once
#include "EnemyParameter.h"

class BehaviorData;
class BehaviorTree;

class EnemySquid : public EnemyParameter
{
public:
	EnemySquid(BehaviorTree* aitree, int nhp, int nspeed);
	~EnemySquid();

	virtual void Update() override;
	virtual void Draw() override;
private:
	BehaviorData* AIData_;
	BehaviorTree* AITree_;
};