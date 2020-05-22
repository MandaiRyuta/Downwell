#pragma once
#include "EnemyParameter.h"
#include "../Behaviour/BehaviorTree.h"

class BehaviorData;	//ビヘイビアデータクラス
class Node;	//ノードクラス

class EnemySeaUrchin : public EnemyParameter
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="nEnemyNumber">敵の描画番号</param>
	/// <param name="AiTree">ビヘイビアツリー</param>
	/// <param name="nHp">ウニのHP</param>
	/// <param name="vPosition">ウニが出現する座標</param>
	EnemySeaUrchin(int nEnemyNumber, BehaviorTree AiTree, int nHp, VECTOR vPosition);
	/// <summary>
	/// デストラクター
	/// </summary>
	~EnemySeaUrchin();

	/// <summary>
	/// 更新関数
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw() override;
private:
	BehaviorData* AIData_;	//ビヘイビアデータクラス
	BehaviorTree AITree_;	//ビヘイビアツリークラス
	Node* Activenode_;	//ノードクラス
	int nTexhandle_;	//テクスチャーハンドル
	bool bHitAction_;	//衝突フラグ
	bool bActive_;	//アクティブフラグ
};