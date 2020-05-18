#include "Enemy.h"
#include "EnemyBird.h"
#include "EnemySeaUrchin.h"
#include "EnemyTurtle.h"
/// <summary>
/// コンストラクター
/// </summary>
/// <param name="enemynumber">描画される敵番号</param>
/// <param name="ntype">敵の種類</param>
/// <param name="nhp">敵のHP</param>
/// <param name="nspeed">敵の移動速度</param>
/// <param name="vposition">敵が発生する座標</param>
Enemy::Enemy(int enemynumber, int ntype, int nhp, int nspeed, VECTOR vposition)
{
	//単体で
	cFactory_ = new CreateFactory();
	//複数で
	cProduct_ = cFactory_->Create(enemynumber, ntype, nhp, nspeed, vposition);
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
	cProduct_->Update();
}
/// <summary>
/// 描画関数
/// </summary>
void Enemy::Draw()
{
	cProduct_->Draw();
}
