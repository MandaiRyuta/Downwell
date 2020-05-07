#pragma once
#include "EnemyParameter.h"

class BehaviorData;
class BehaviorTree;

class EnemyBird : public EnemyParameter
{
public:
	EnemyBird(BehaviorTree* aitree, int nhp, int nspeed);
	~EnemyBird();

	virtual void Update() override;
	virtual void Draw() override;
private:
	BehaviorData* AIData_;
	BehaviorTree* AITree_;
};