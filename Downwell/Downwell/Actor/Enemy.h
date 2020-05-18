#pragma once
#include "Actor.h"
#include "Factory.h"
#include "EnemyParameter.h"

class Enemy : public Actor
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="enemynumber">描画される敵番号</param>
	/// <param name="ntype">敵の種類</param>
	/// <param name="nhp">敵のHP</param>
	/// <param name="nspeed">敵の移動速度</param>
	/// <param name="vposition">敵が発生する座標</param>
	Enemy(int enemynumber, int ntype, int nhp, int nspeed, VECTOR vposition);
	/// <summary>
	/// デストラクター
	/// </summary>
	~Enemy();
public:
	/// <summary>
	/// 更新関数
	/// </summary>
	virtual void Update() override; 
	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw() override;
private:
	Factory* cFactory_;	//ファクトリークラス
	EnemyParameter* cProduct_;	//敵のパラメータークラス
};