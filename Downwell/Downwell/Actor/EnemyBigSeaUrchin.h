#pragma once
#include "EnemyParameter.h"

class BehaviorData;
class BehaviorTree;

class EnemyBigSeaUrchin : public EnemyParameter
{
public:
	EnemyBigSeaUrchin(BehaviorTree* aitree, int nhp, int nspeed);

	~EnemyBigSeaUrchin();


	virtual void Update() override;
	virtual void Draw() override;
private:
	BehaviorData* AIData_;
	BehaviorTree* AITree_;
};