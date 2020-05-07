#include "EnemyBird.h"
#include "../Behaviour/BehaviorData.h"

EnemyBird::EnemyBird(BehaviorTree* aitree, int nhp, int nspeed) : 
	AITree_(aitree)
{
	nHp_ = nhp;
	nMaxHp_ = nhp;
	nSpeed_ = nspeed;
	nMaxSpeed_ = nspeed;
	AIData_ = new BehaviorData;
}

EnemyBird::~EnemyBird()
{
	if (AIData_ != nullptr)
	{
		AIData_->Release();
		delete AIData_;
	}
}

void EnemyBird::Update()
{
}

void EnemyBird::Draw()
{
}