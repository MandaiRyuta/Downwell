#include "EnemyTurtle.h"
#include "../Behaviour/BehaviorData.h"
#include "../Behaviour/BehaviorTree.h"
#include "../Behaviour/TurnMoveAction.h"
#include "../Behaviour/Node.h"
#include "../Constant.h"

EnemyTurtle::EnemyTurtle(int enemynumber, BehaviorTree aitree, int nhp, int nspeed, VECTOR vposition) :
	Activenode_(nullptr),
	AIData_(nullptr)
{
	AITree_ = aitree;
	nHp_ = nhp;
	nMaxHp_ = nhp;
	nSpeed_ = nspeed;
	nMaxSpeed_ = nspeed;
	nMoveType_ = 0;
	vMove_ = VGet(0.0f, 0.0f, 0.0f);
	vPosition_ = vposition;
	AIData_ = new BehaviorData;

	nTexhandle_ = LoadGraph("Resource/player.png");

	nEnemyNumber_ = enemynumber;
}

EnemyTurtle::~EnemyTurtle()
{
	if (AIData_ != nullptr)
	{
		delete AIData_;
	}

	AITree_.Release();
}

void EnemyTurtle::Update()
{
	if (Activenode_ == nullptr)
	{
		Activenode_ = AITree_.Inference(this, AIData_);
	}
	if (Activenode_ != nullptr)
	{
		Activenode_ = AITree_.Run(this, Activenode_, AIData_);
	}

	vPosition_.x += vMove_.x;
	vPosition_.y += vMove_.y;
}

void EnemyTurtle::Draw()
{
	DrawBillboard3D(vPosition_,0.5f,0.5f,18,0, nTexhandle_,false);
}