#pragma once
#include "../Constant.h"
#include "ActionBase.h"
class BehaviorTree;
class BehaviorData;

enum class TREE_RULE
{
	NONE,
	PRIORITY,
	SEQUENCE,
	SEQUENTIALLOOP,
	RANDOM,
	ON_OFF,
};

class Node
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="EntryName">エントリー名</param>
	/// <param name="ParentNode">登録したノードの検索</param>
	/// <param name="Sibling">兄弟ノード</param>
	/// <param name="nPriority">優先度</param>
	/// <param name="SelectRule">ビヘイビアツリーの選択ルール</param>
	/// <param name="Action">行動クラス</param>
	/// <param name="HierarchyNumber">子要素にいれているものに登録するヒエラルキー</param>
	Node(std::string EntryName, Node* ParentNode, Node* Sibling, int nPriority, TREE_RULE SelectRule, ActionBase* Action, int HierarchyNumber) :
		sName_(EntryName),
		Parent_(ParentNode),
		Sibiling_(Sibling),
		nPriority_(nPriority),
		BTRuleBase_(SelectRule),
		ActionBase_(Action),
		nHierarchyNumber_(HierarchyNumber),
		ChildNode_(NULL)
	{}
	/// <summary>
	/// デストラクター
	/// </summary>
	/// <returns></returns>
	~Node() {}
	/// <summary>
	/// エントリー名取得関数
	/// </summary>
	/// <returns>エントリー名</returns>
	const std::string& GetName()
	{
		return sName_;
	}
	/// <summary>
	/// 親ノード取得関数
	/// </summary>
	/// <returns>親ノード</returns>
	const Node& GetParent()
	{
		return *Parent_;
	}
	/// <summary>
	/// 子ノード取得関数
	/// </summary>
	/// <param name="nIndex">子ノードの番号</param>
	/// <returns>子ノード</returns>
	const Node* GetChild(int nIndex)
	{
		return ChildNode_.size() >= static_cast<size_t>(nIndex) ? nullptr : ChildNode_[nIndex];
	}
	/// <summary>
	/// 末尾子ノード取得関数
	/// </summary>
	/// <returns>末尾子ノード</returns>
	Node* GetLastChild()
	{
		if (ChildNode_.size() == 0)
		{
			return nullptr;
		}

		return ChildNode_[ChildNode_.size() - 1];
	}
	/// <summary>
	/// 先頭子ノード取得関数
	/// </summary>
	/// <returns>先頭子ノード</returns>
	const Node& GetFirstChildNode()
	{
		return *ChildNode_[0];
	}
	/// <summary>
	/// 兄弟ノード取得関数
	/// </summary>
	/// <returns>兄弟ノード</returns>
	const Node& GetSibiling()
	{
		return *Sibiling_;
	}
	/// <summary>
	/// 階層取得関数
	/// </summary>
	/// <returns>階層</returns>
	const int& GetHierarchyNumber()
	{
		return nHierarchyNumber_;
	}
	/// <summary>
	/// 優先度取得関数
	/// </summary>
	/// <returns>優先度</returns>
	const int& GetPriority()
	{
		return nPriority_;
	}
	/// <summary>
	/// 親ノードを設定する関数
	/// </summary>
	/// <param name="Parent">設定する親ノード</param>
	void SetParent(Node* Parent)
	{
		Parent != nullptr ? Parent_ = Parent : Parent_ = nullptr;
	}
	/// <summary>
	/// 子ノードの追加関数
	/// </summary>
	/// <param name="Child">追加する子ノード</param>
	void AddChild(Node* Child)
	{
		Child != nullptr ? ChildNode_.push_back(Child) : ChildNode_.push_back(nullptr);
	}
	/// <summary>
	/// 兄弟ノードの設定関数
	/// </summary>
	/// <param name="Sibling">設定する兄弟ノード</param>
	void SetSibling(Node* Sibling)
	{
		Sibling != nullptr ? Sibiling_ = Sibling : Sibiling_ = nullptr;
	}
	/// <summary>
	/// 行動ノードの所持確認関数
	/// </summary>
	/// <returns>true : 所持している	false : 所持していない</returns>
	bool CheckNullAction()
	{
		return ActionBase_ != nullptr ? true : false;
	}
	/// <summary>
	/// 優先順位選択関数
	/// </summary>
	/// <param name="List">ノードリスト</param>
	/// <returns>優先順位を比較し終えたノード</returns>
	Node* SelectPriority(std::vector<Node*>* List);
	/// <summary>
	/// ランダム選択関数
	/// </summary>
	/// <param name="List">ノードリスト</param>
	/// <returns>ランダム選択を終えたノード</returns>
	Node* SelectRandom(std::vector<Node*>* List);
	/// <summary>
	/// オンオフ選択関数
	/// </summary>
	/// <param name="List">ノードリスト</param>
	/// <param name="Data">ビヘイビアデータ</param>
	/// <returns>実行していないノード</returns>
	Node* SelectOnOff(std::vector<Node*>* List, BehaviorData* Data);
	/// <summary>
	/// シーケンス選択関数
	/// </summary>
	/// <param name="List">ノードリスト</param>
	/// <param name="Data">ビヘイビアデータ</param>
	/// <returns>順番に従ったノード</returns>
	Node* SelectSequence(std::vector<Node*>* List, BehaviorData* Data);
	/// <summary>
	/// ノード検索関数
	/// </summary>
	/// <param name="SearchName">探しているノード名</param>
	/// <returns>探しているノード</returns>
	Node* SearchNode(std::string SearchName);
	/// <summary>
	/// ノード推論関数
	/// </summary>
	/// <param name="Enemy">敵情報</param>
	/// <param name="Data">ビヘイビアデータ</param>
	/// <returns>推論し終えたノード</returns>
	Node* Inference(EnemyParameter* Enemy, BehaviorData* Data);
	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="Enemy">敵情報</param>
	/// <returns>ActionBaseのステート</returns>
	ActionBase::STATE Run(EnemyParameter& Enemy);
private:
	std::string sName_;	//名前
	TREE_RULE BTRuleBase_;	//選択ルール
	ActionBase* ActionBase_;	//行動クラス
	int nPriority_;	//優先度
	Node* Parent_;	//親ノード
	std::vector<Node*> ChildNode_;	//子ノード
	Node* Sibiling_;	//兄弟ノード
	int nHierarchyNumber_;	//階層番号
};