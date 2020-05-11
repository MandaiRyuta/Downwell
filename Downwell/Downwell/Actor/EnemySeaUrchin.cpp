#include "EnemySeaUrchin.h"
#include "../Behaviour/BehaviorData.h"

EnemySeaUrchin::EnemySeaUrchin(BehaviorTree* aitree, int nhp, int nspeed) :
 AITree_(aitree)
{
	nHp_ = nhp;
	nMaxHp_ = nhp;
	nSpeed_ = nspeed;
	nMaxSpeed_ = nspeed;
	AIData_ = new BehaviorData;
}

EnemySeaUrchin::~EnemySeaUrchin()
{
	if (AIData_ != nullptr)
	{
		AIData_->PopSequenceNode();
		delete AIData_;
	}
}

void EnemySeaUrchin::Update()
{
}

void EnemySeaUrchin::Draw()
{
}