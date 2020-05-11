#include "EnemyMask.h"
#include "../Behaviour/BehaviorData.h"

EnemyMask::EnemyMask(BehaviorTree* aitree, int nhp, int nspeed) :
	AITree_(aitree)
{
	nHp_ = nhp;
	nMaxHp_ = nhp;
	nSpeed_ = nspeed;
	nMaxSpeed_ = nspeed;
	AIData_ = new BehaviorData;
}

EnemyMask::~EnemyMask()
{
	if (AIData_ != nullptr)
	{
		AIData_->PopSequenceNode();
		delete AIData_;
	}
}

void EnemyMask::Update()
{
}

void EnemyMask::Draw()
{
}
