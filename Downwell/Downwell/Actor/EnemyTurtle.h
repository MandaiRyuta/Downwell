#pragma once
#include "EnemyParameter.h"
#include "../Behaviour/BehaviorTree.h"
class BehaviorData;
class Node;

class EnemyTurtle : public EnemyParameter
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="nEnemyNumber">敵の描画番号</param>
	/// <param name="AiTree">ビヘイビアツリー</param>
	/// <param name="nHp">亀のHP</param>
	/// <param name="vPosition">亀が出現する座標</param>
	EnemyTurtle(int nEnemyNumber, BehaviorTree AiTree, int nHp, VECTOR vPosition);
	/// <summary>
	/// デストラクター
	/// </summary>
	~EnemyTurtle();
	/// <summary>
	/// 更新関数
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw() override;
	/// <summary>
	/// クアッドツリー内にいるかどうかを確認する関数
	/// </summary>
	void QuadTreeCheckCollision();
	/// <summary>
	/// プレイヤーやブロックとの衝突判定関数
	/// </summary>
	void TurtleHitCollision();
	/// <summary>
	/// 亀が行動を行う関数
	/// </summary>
	void TurtleMoveAction();
private:
	BehaviorData* AIData_;	//ビヘイビアデータクラス
	BehaviorTree AITree_;	//ビヘイビアツリークラス
	Node* Activenode_;	//ノードクラス
	int nTexhandle_;	//テクスチャーハンドル
	bool bHitAction_;	//衝突フラグ
	bool bActive_;	//アクティブフラグ
};