#pragma once
#include <vector>
#include <map>
#include <stack>
#include <string>
#include "BehaviorTree.h"
class Node;	//ノードクラス

class BehaviorData
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	BehaviorData()
	{
		Init();
	}
	/// <summary>
	/// デストラクター
	/// </summary>
	~BehaviorData();
	/// <summary>
	/// 初期化関数
	/// </summary>
	void Init();
	/// <summary>
	/// シーケンスノードを追加する関数
	/// </summary>
	/// <param name="node">追加するノード</param>
	void PushSequenceNode(Node* node);
	/// <summary>
	/// シーケンスノードからノードを取り除く関数
	/// </summary>
	/// <returns>取り除いたシーケンスノード</returns>
	Node* PopSequenceNode();
	/// <summary>
	/// ノードが使われているか確認する関数
	/// </summary>
	/// <param name="name">ノード名</param>
	/// <returns>true : 使用　false : 未使用</returns>
	bool NodeUsedExist(std::string name);
	/// <summary>
	/// 指定したノードを使用するときの命令関数
	/// </summary>
	/// <param name="name">使用するノード名</param>
	void EntryUsedNode(std::string name);
	/// <summary>
	/// シーケンス番号取得関数
	/// </summary>
	/// <param name="name">シーケンス名</param>
	/// <returns></returns>
	int GetSequenceStep(std::string name);
	/// <summary>
	/// シーケンス登録関数
	/// </summary>
	/// <param name="name">シーケンス名</param>
	/// <param name="step">シーケンス番号</param>
	void SetSequenceStep(std::string name, int step);
	/// <summary>
	/// 使用しているノードのリセット関数
	/// </summary>
	/// <param name="reset_hierachy">リセットノード</param>
	void ResetUsedNode(std::vector<Node*>* reset_hierachy);
private:
	std::stack<Node*> SequenceStack_;	//シーケンスノード
	std::map<std::string, int> UpdateSequenceStep_;	//シーケンス番号
	std::map<std::string, bool> UsedNode_;	//シーケンス使用フラグ
};