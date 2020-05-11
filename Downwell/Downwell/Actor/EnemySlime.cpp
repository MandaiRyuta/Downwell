#include "EnemySlime.h"
#include "../Behaviour/BehaviorData.h"

EnemySlime::EnemySlime(BehaviorTree aitree, int nhp, int nspeed) 
{
	AITree_ = aitree;
	nHp_ = nhp;
	nMaxHp_ = nhp;
	nSpeed_ = nspeed;
	nMaxSpeed_ = nspeed;
	AIData_ = new BehaviorData;
}

EnemySlime::~EnemySlime()
{
	if (AIData_ != nullptr)
	{
		AIData_->PopSequenceNode();
		delete AIData_;
	}
}

void EnemySlime::Update()
{
}

void EnemySlime::Draw()
{
}