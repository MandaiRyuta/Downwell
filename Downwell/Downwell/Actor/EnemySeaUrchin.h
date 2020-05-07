#pragma once
#include "EnemyParameter.h"

class BehaviorData;
class BehaviorTree;

class EnemySeaUrchin : public EnemyParameter
{
public:
	EnemySeaUrchin(BehaviorTree* aitree, int nhp, int nspeed);
	~EnemySeaUrchin();

	virtual void Update() override;
	virtual void Draw() override;
private:
	BehaviorData* AIData_;
	BehaviorTree* AITree_;
};