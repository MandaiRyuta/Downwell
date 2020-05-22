#pragma once

#include <string>
#include "Node.h"
class ActionBase;	//アクションベースクラス
class BehaviorData;	//ビヘイビアデータクラス
class EnemyParameter;	//敵パラメータークラス

class BehaviorTree
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	BehaviorTree() : Root_(nullptr), Add_Node_(nullptr) {}
	/// <summary>
	/// デストラクター
	/// </summary>
	~BehaviorTree() {}
	/// <summary>
	/// 解放関数
	/// </summary>
	void Release();
	/// <summary>
	/// 実行ノードを推論する関数
	/// </summary>
	/// <param name="Enemy">推論するノード</param>
	/// <param name="Data">推論するビヘイビアデータ</param>
	/// <returns>推論し終えた親ノード</returns>
	Node* Inference(EnemyParameter* Enemy, BehaviorData* Data);
	/// <summary>
	/// シーケンスノードを推論する関数
	/// </summary>
	/// <param name="SequenceNode">シーケンスノード</param>
	/// <param name="Enemy">推論する敵情報</param>
	/// <param name="Data">推論するビヘイビアデータ</param>
	/// <returns>推論し終えたノード</returns>
	Node* SequenceBack(Node* SequenceNode, EnemyParameter* Enemy, BehaviorData* Data);
	/// <summary>
	/// ノード追加関数
	/// </summary>
	/// <param name="SearchName">ノード名</param>
	/// <param name="EntryName">ノード名</param>
	/// <param name="nPriority">優先度</param>
	/// <param name="SelectRule">ルール</param>
	/// <param name="Action">行動クラス</param>
	void AddNode(std::string SearchName, std::string EntryName, int nPriority, TREE_RULE SelectRule, ActionBase* Action);
	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="Enemy">敵情報</param>
	/// <param name="ActionNode">行動ノード</param>
	/// <param name="Data">ビヘイビアデータ</param>
	/// <returns>ルールで判別し終えた行動ノード</returns>
	Node* Run(EnemyParameter& Enemy, Node* ActionNode, BehaviorData* Data);
private:
	Node* Root_;	//親ノード
	Node* Add_Node_;	//追加ノード
};