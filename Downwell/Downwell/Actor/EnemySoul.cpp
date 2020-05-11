#include "EnemySoul.h"
#include "../Behaviour/BehaviorData.h"

EnemySoul::EnemySoul(BehaviorTree* aitree, int nhp, int nspeed) :
	AITree_(aitree)
{
	nHp_ = nhp;
	nMaxHp_ = nhp;
	nSpeed_ = nspeed;
	nMaxSpeed_ = nspeed;
	AIData_ = new BehaviorData;
}

EnemySoul::~EnemySoul()
{
	if (AIData_ != nullptr)
	{
		AIData_->PopSequenceNode();
		delete AIData_;
	}
}

void EnemySoul::Update()
{
}

void EnemySoul::Draw()
{
}