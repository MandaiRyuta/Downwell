#pragma once
#include "EnemyParameter.h"
#include "../Behaviour/BehaviorTree.h"
class BehaviorData;
class Node;

class EnemyTurtle : public EnemyParameter
{
public:
	EnemyTurtle(int enemynumber, BehaviorTree aitree, int nhp, int nspeed, VECTOR vposition);
	~EnemyTurtle();

	virtual void Update() override;
	virtual void Draw() override;

private:
	BehaviorData* AIData_;
	BehaviorTree AITree_;
	Node* Activenode_;
	int nTexhandle_;
	int nThisEnemyNumber_;
};