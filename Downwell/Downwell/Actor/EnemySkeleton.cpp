#include "EnemySkeleton.h"
#include "../Behaviour/BehaviorData.h"

EnemySkeleton::EnemySkeleton(BehaviorTree* aitree, int nhp, int nspeed) :
	AITree_(aitree)
{
	nHp_ = nhp;
	nMaxHp_ = nhp;
	nSpeed_ = nspeed;
	nMaxSpeed_ = nspeed;
	AIData_ = new BehaviorData;
}

EnemySkeleton::~EnemySkeleton()
{
	if (AIData_ != nullptr)
	{
		AIData_->Release();
		delete AIData_;
	}
}

void EnemySkeleton::Update()
{
	
}

void EnemySkeleton::Draw()
{
}

