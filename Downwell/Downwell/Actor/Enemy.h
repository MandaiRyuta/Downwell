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
	/// <param name="nEnemyNumber">描画される敵番号</param>
	/// <param name="nType">敵の種類</param>
	/// <param name="nHp">敵のHP</param>
	/// <param name="vPosition">敵が発生する座標</param>
	Enemy(int nEnemyNumber, int nType, int nHp, VECTOR vPosition);
	/// <summary>
	/// デストラクター
	/// </summary>
	~Enemy();
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
	EnemyParameter* cParameter_;	//敵のパラメータークラス
};