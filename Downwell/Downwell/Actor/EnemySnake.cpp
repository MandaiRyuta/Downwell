#include "EnemySnake.h"
#include "../Behaviour/BehaviorData.h"

EnemySnake::EnemySnake(BehaviorTree* aitree, int nhp, int nspeed) :
	AITree_(aitree)
{
	nHp_ = nhp;
	nMaxHp_ = nhp;
	nSpeed_ = nspeed;
	nMaxSpeed_ = nspeed;
	AIData_ = new BehaviorData;
}

EnemySnake::~EnemySnake()
{
	if (AIData_ != nullptr)
	{
		AIData_->PopSequenceNode();
		delete AIData_;
	}
}

void EnemySnake::Update()
{
}

void EnemySnake::Draw()
{
}
