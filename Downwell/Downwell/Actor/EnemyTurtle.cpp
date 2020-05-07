#include "EnemyTurtle.h"
#include "../Behaviour/BehaviorData.h"

EnemyTurtle::EnemyTurtle(BehaviorTree* aitree, int nhp, int nspeed) :
	AITree_(aitree)
{
	nHp_ = nhp;
	nMaxHp_ = nhp;
	nSpeed_ = nspeed;
	nMaxSpeed_ = nspeed;
	AIData_ = new BehaviorData;
}

EnemyTurtle::~EnemyTurtle()
{
	if (AIData_ != nullptr)
	{
		AIData_->Release();
		delete AIData_;
	}
}

void EnemyTurtle::Update()
{
}

void EnemyTurtle::Draw()
{
}