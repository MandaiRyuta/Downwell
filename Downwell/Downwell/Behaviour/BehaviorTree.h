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
	/// <param name="enemy">推論するノード</param>
	/// <param name="data">推論するビヘイビアデータ</param>
	/// <returns>推論し終えた親ノード</returns>
	Node* Inference(EnemyParameter* enemy, BehaviorData* data);
	/// <summary>
	/// シーケンスノードを推論する関数
	/// </summary>
	/// <param name="sequence_node">シーケンスノード</param>
	/// <param name="enemy">推論する敵情報</param>
	/// <param name="data">推論するビヘイビアデータ</param>
	/// <returns>推論し終えたノード</returns>
	Node* SequenceBack(Node* sequence_node, EnemyParameter* enemy, BehaviorData* data);
	/// <summary>
	/// ノード追加関数
	/// </summary>
	/// <param name="search_name">ノード名</param>
	/// <param name="entry_name">ノード名</param>
	/// <param name="priority">優先度</param>
	/// <param name="select_rule">ルール</param>
	/// <param name="judgment">判定クラス</param>
	/// <param name="action">行動クラス</param>
	void AddNode(std::string search_name, std::string entry_name, int priority, TREE_RULE select_rule, ActionBase* action);
	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="enemy">敵情報</param>
	/// <param name="actionnode">行動ノード</param>
	/// <param name="data">ビヘイビアデータ</param>
	/// <returns>ルールで判別し終えた行動ノード</returns>
	Node* Run(EnemyParameter* enemy, Node* actionnode, BehaviorData* data);
private:
	Node* Root_;	//親ノード
	Node* Add_Node_;	//追加ノード
};