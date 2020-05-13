#pragma once
#include "EnemyParameter.h"
#include "../Behaviour/BehaviorTree.h"

class BehaviorData;
class Node;

class EnemyBird : public EnemyParameter
{
public:
	EnemyBird(int enemynumber, BehaviorTree aitree, int nhp, int nspeed, VECTOR vposition);
	~EnemyBird();

	virtual void Update() override;
	virtual void Draw() override;
private:
	BehaviorData* AIData_;
	BehaviorTree AITree_;
	Node* Activenode_;
	int nTexhandle_;
	bool bHitAction_;
};