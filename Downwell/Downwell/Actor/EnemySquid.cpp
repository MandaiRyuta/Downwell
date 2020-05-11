#include "EnemySquid.h"
#include "../Behaviour/BehaviorData.h"
EnemySquid::EnemySquid(BehaviorTree* aitree, int nhp, int nspeed) : 
	AITree_(aitree)
{
	nHp_ = nhp;
	nMaxHp_ = nhp;
	nSpeed_ = nspeed;
	nMaxSpeed_ = nspeed;
	AIData_ = new BehaviorData;
}

EnemySquid::~EnemySquid()
{
	if (AIData_ != nullptr)
	{
		AIData_->PopSequenceNode();
		delete AIData_;
	}
}

void EnemySquid::Update()
{
}

void EnemySquid::Draw()
{
}
