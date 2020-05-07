#pragma once
#include "EnemyParameter.h"

class BehaviorData;
class BehaviorTree;

class EnemyMask : public EnemyParameter
{
public:
	EnemyMask(BehaviorTree* aitree, int nhp, int nspeed);
	~EnemyMask();

	virtual void Update() override;
	virtual void Draw() override;
private:
	BehaviorData* AIData_;
	BehaviorTree* AITree_;
};