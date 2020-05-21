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
	/// <param name="entry_name">エントリー名</param>
	/// <param name="parent_node">登録したノードの検索</param>
	/// <param name="sibling">兄弟ノード</param>
	/// <param name="priority">優先度</param>
	/// <param name="select_rule">ビヘイビアツリーの選択ルール</param>
	/// <param name="judgment">切り替える判断クラス(残ったHPで行動を判断)</param>
	/// <param name="action">行動クラス</param>
	/// <param name="hierarchy_number">子要素にいれているものに登録するヒエラルキー</param>
	Node(std::string entry_name, Node* parent_node, Node* sibling, int priority, TREE_RULE select_rule, ActionBase* action, int hierarchy_number) :
		sName_(entry_name),
		Parent_(parent_node),
		Sibiling_(sibling),
		nPriority_(priority),
		BTRuleBase_(select_rule),
		ActionBase_(action),
		nHierarchyNumber_(hierarchy_number),
		ChildNode_(NULL)
	{}
	/// <summary>
	/// デストラクター
	/// </summary>
	/// <returns></returns>
	~Node() {}
public:
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
	/// <param name="index">子ノードの番号</param>
	/// <returns>子ノード</returns>
	const Node* GetChild(int index)
	{
		return ChildNode_.size() >= static_cast<size_t>(index) ? nullptr : ChildNode_[index];
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
	/// <param name="parent">設定する親ノード</param>
	void SetParent(Node* parent)
	{
		parent != nullptr ? Parent_ = parent : Parent_ = nullptr;
	}
	/// <summary>
	/// 子ノードの追加関数
	/// </summary>
	/// <param name="child">追加する子ノード</param>
	void AddChild(Node* child)
	{
		child != nullptr ? ChildNode_.push_back(child) : ChildNode_.push_back(nullptr);
	}
	/// <summary>
	/// 兄弟ノードの設定関数
	/// </summary>
	/// <param name="sibling">設定する兄弟ノード</param>
	void SetSibling(Node* sibling)
	{
		sibling != nullptr ? Sibiling_ = sibling : Sibiling_ = nullptr;
	}
	/// <summary>
	/// 行動ノードの所持確認関数
	/// </summary>
	/// <returns>true : 所持している	false : 所持していない</returns>
	bool CheckNullAction()
	{
		return ActionBase_ != nullptr ? true : false;
	}
public:
	/// <summary>
	/// 優先順位選択関数
	/// </summary>
	/// <param name="list">ノードリスト</param>
	/// <returns>優先順位を比較し終えたノード</returns>
	Node* SelectPriority(std::vector<Node*>* list);
	/// <summary>
	/// ランダム選択関数
	/// </summary>
	/// <param name="list">ノードリスト</param>
	/// <returns>ランダム選択を終えたノード</returns>
	Node* SelectRandom(std::vector<Node*>* list);
	/// <summary>
	/// オンオフ選択関数
	/// </summary>
	/// <param name="list">ノードリスト</param>
	/// <param name="data">ビヘイビアデータ</param>
	/// <returns>実行していないノード</returns>
	Node* SelectOnOff(std::vector<Node*>* list, BehaviorData* data);
	/// <summary>
	/// シーケンス選択関数
	/// </summary>
	/// <param name="list">ノードリスト</param>
	/// <param name="data">ビヘイビアデータ</param>
	/// <returns>順番に従ったノード</returns>
	Node* SelectSequence(std::vector<Node*>* list, BehaviorData* data);
	/// <summary>
	/// ノード検索関数
	/// </summary>
	/// <param name="search_name">探しているノード名</param>
	/// <returns>探しているノード</returns>
	Node* SearchNode(std::string search_name);
	/// <summary>
	/// ノード推論関数
	/// </summary>
	/// <param name="enemy">敵情報</param>
	/// <param name="data">ビヘイビアデータ</param>
	/// <returns>推論し終えたノード</returns>
	Node* Inference(EnemyParameter* enemy, BehaviorData* data);
	/// <summary>
	/// 更新関数
	/// </summary>
	/// <param name="enemy">敵情報</param>
	/// <returns>ActionBaseのステート</returns>
	ActionBase::STATE Run(EnemyParameter* enemy);
protected:
	std::string sName_;	//名前
	TREE_RULE BTRuleBase_;	//選択ルール
	ActionBase* ActionBase_;	//行動クラス
	int nPriority_;	//優先度
	Node* Parent_;	//親ノード
	std::vector<Node*> ChildNode_;	//子ノード
	Node* Sibiling_;	//兄弟ノード
	int nHierarchyNumber_;	//階層番号
};