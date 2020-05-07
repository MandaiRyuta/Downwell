#include "EnemyBigSeaUrchin.h"
#include "../Behaviour/BehaviorData.h"

EnemyBigSeaUrchin::EnemyBigSeaUrchin(BehaviorTree* aitree, int nhp, int nspeed) :
	AITree_(aitree)
{
	nHp_ = nhp;
	nMaxHp_ = nhp;
	nSpeed_ = nspeed;
	nMaxSpeed_ = nspeed;
	AIData_ = new BehaviorData;
}

EnemyBigSeaUrchin::~EnemyBigSeaUrchin()
{
	if (AIData_ != nullptr)
	{
		AIData_->Release();
		delete AIData_;
	}
}

void EnemyBigSeaUrchin::Update()
{
}

void EnemyBigSeaUrchin::Draw()
{
}