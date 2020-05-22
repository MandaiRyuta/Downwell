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
	/// <param name="Node">追加するノード</param>
	void PushSequenceNode(Node* Node);
	/// <summary>
	/// シーケンスノードからノードを取り除く関数
	/// </summary>
	/// <returns>取り除いたシーケンスノード</returns>
	Node* PopSequenceNode();
	/// <summary>
	/// ノードが使われているか確認する関数
	/// </summary>
	/// <param name="Name">ノード名</param>
	/// <returns>true : 使用　false : 未使用</returns>
	bool NodeUsedExist(std::string Name);
	/// <summary>
	/// 指定したノードを使用するときの命令関数
	/// </summary>
	/// <param name="Name">使用するノード名</param>
	void EntryUsedNode(std::string Name);
	/// <summary>
	/// シーケンス番号取得関数
	/// </summary>
	/// <param name="Name">シーケンス名</param>
	/// <returns></returns>
	int GetSequenceStep(std::string Name);
	/// <summary>
	/// シーケンス登録関数
	/// </summary>
	/// <param name="Name">シーケンス名</param>
	/// <param name="nStep">シーケンス番号</param>
	void SetSequenceStep(std::string Name, int nStep);
	/// <summary>
	/// 使用しているノードのリセット関数
	/// </summary>
	/// <param name="ResetHierachy">リセットノード</param>
	void ResetUsedNode(std::vector<Node*>* ResetHierachy);
private:
	std::stack<Node*> SequenceStack_;	//シーケンスノード
	std::map<std::string, int> UpdateSequenceStep_;	//シーケンス番号
	std::map<std::string, bool> UsedNode_;	//シーケンス使用フラグ
};