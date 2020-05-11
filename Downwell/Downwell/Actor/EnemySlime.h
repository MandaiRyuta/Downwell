#pragma once
#include "EnemyParameter.h"
#include "../Behaviour/BehaviorTree.h"
class BehaviorData;

class EnemySlime : public EnemyParameter
{
public:
	EnemySlime(BehaviorTree aitree, int nhp, int nspeed);
	~EnemySlime();

	virtual void Update() override;
	virtual void Draw() override;
private:
	BehaviorData* AIData_;
	BehaviorTree AITree_;
};
