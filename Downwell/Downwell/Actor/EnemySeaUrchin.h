#pragma once
#include "EnemyParameter.h"
#include "../Behaviour/BehaviorTree.h"

class BehaviorData;
class Node;

class EnemySeaUrchin : public EnemyParameter
{
public:
	EnemySeaUrchin(int enemynumber, BehaviorTree aitree, int nhp, int nspeed, VECTOR vposition);
	~EnemySeaUrchin();

	virtual void Update() override;
	virtual void Draw() override;

	static VECTOR& GetPosition();
private:
	BehaviorData* AIData_;
	BehaviorTree AITree_;
	Node* Activenode_;
	int nTexhandle_;
	static VECTOR vSavePosition_;
	bool bHitAction_;
};