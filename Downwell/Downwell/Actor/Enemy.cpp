#include "Enemy.h"
#include "EnemyBird.h"
#include "EnemySeaUrchin.h"
#include "EnemyTurtle.h"
#include "../Behaviour/LifeJudgment.h"
/// <summary>
/// コンストラクター
/// </summary>
/// <param name="nEnemyNumber">描画される敵番号</param>
/// <param name="nType">敵の種類</param>
/// <param name="nHp">敵のHP</param>
/// <param name="vPosition">敵が発生する座標</param>
Enemy::Enemy(int nEnemyNumber, int nType, int nHp, VECTOR vPosition)
{
	//単体で
	cFactory_ = new CreateFactory();
	//複数で
	cProduct_ = cFactory_->Create(nEnemyNumber, nType, nHp, vPosition);
}
/// <summary>
/// デストラクター
/// </summary>
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
/// <summary>
/// 更新関数
/// </summary>
void Enemy::Update()
{
	bool bdead = AliveChecker::SetDead(*cProduct_);

	if (!bdead)
	{
		cProduct_->Update();
	}
}
/// <summary>
/// 描画関数
/// </summary>
void Enemy::Draw()
{
	cProduct_->Draw();
}
