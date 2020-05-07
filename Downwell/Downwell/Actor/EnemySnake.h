#pragma once
#include "EnemyParameter.h"

class BehaviorData;
class BehaviorTree;

class EnemySnake : public EnemyParameter
{
public:
	EnemySnake(BehaviorTree* aitree, int nhp, int nspeed);
	~EnemySnake();
public:
	virtual void Update() override;
	virtual void Draw() override;
private:
	BehaviorData* AIData_;
	BehaviorTree* AITree_;
};