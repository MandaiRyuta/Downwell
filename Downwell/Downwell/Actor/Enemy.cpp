#include "Enemy.h"
#include "EnemyBigSeaUrchin.h"
#include "EnemyBird.h"
#include "EnemyMask.h"
#include "EnemySeaUrchin.h"
#include "EnemySkeleton.h"
#include "EnemySlime.h"
#include "EnemySnake.h"
#include "EnemySoul.h"
#include "EnemySquid.h"
#include "EnemyTurtle.h"

Enemy::Enemy(int enemynumber, int ntype, int nhp, int nspeed, VECTOR vposition)
{
	//’P‘Ì‚Å
	cFactory_ = new CreateFactory();
	//•¡”‚Å
	cProduct_ = cFactory_->Create(enemynumber, ntype, nhp, nspeed, vposition);
}

Enemy::~Enemy()
{
	if (cFactory_ != nullptr)
	{
		delete cFactory_;
	}
	if (cProduct_ != nullptr)
	{
		delete cProduct_;
	}
}

void Enemy::Update()
{
	cProduct_->Update();
}

void Enemy::Draw()
{
	cProduct_->Draw();
}
