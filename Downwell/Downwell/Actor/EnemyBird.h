#pragma once
#include "EnemyParameter.h"
#include "../Behaviour/BehaviorTree.h"

class BehaviorData;	//ビヘイビアデータクラス
class Node;	//ノードクラス

class EnemyBird : public EnemyParameter
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="nEnemyNumber">敵の描画番号</param>
	/// <param name="AiTree">ビヘイビアツリー</param>
	/// <param name="nHp">鳥のHP</param>
	/// <param name="vPosition">鳥が出現する座標</param>
	EnemyBird(int nEnemyNumber, BehaviorTree AiTree, int nHp, VECTOR vPosition);
	/// <summary>
	/// デストラクター
	/// </summary>
	~EnemyBird();
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
	void BirdHitCollision();
	/// <summary>
	/// 鳥が行動を行う関数
	/// </summary>
	void BirdMoveAction();
private:
	BehaviorData* AIData_;	//ビヘイビアデータクラス
	BehaviorTree AITree_;	//ビヘイビアツリークラス
	Node* Activenode_;	//ノードクラス
	int nTexhandle_;	//テクスチャーハンドル
	bool bHitAction_;	//衝突フラグ
	bool bActive_;	//アクティブフラグ
};