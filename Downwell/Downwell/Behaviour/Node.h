#pragma once
#include "../Constant.h"
#include "JudgmentBase.h"
#include "ActionBase.h"
class BehaviorTree;
class BehaviorData;

enum TREE_RULE
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
	Node() {}
	//エントリー名、登録したノードの検索、兄弟ノード、優先度、ビヘイビアツリーの選択ルール、切り替える判断クラス(残ったHPで行動を判断)、行動クラス、子要素にいれているものに登録するヒエラルキー
	Node(std::string entry_name, Node* parent_node, Node* sibling, int priority, TREE_RULE select_rule, JudgmentBase* judgment, ActionBase* action, int hierarchy_number) :
		Name_(entry_name),
		Parent_(parent_node),
		Sibiling_(sibling),
		Priority_(priority),
		BTRuleBase_(select_rule),
		JudgementBase_(judgment),
		ActionBase_(action),
		HierarchyNumber_(hierarchy_number),
		ChildNode_(NULL)
	{}
	~Node();
public:
	void Release();
	const std::string& GetName()
	{
		return Name_;
	}
	//nullptrをパラメーターとして認めない。
	const Node& GetParent()
	{
		return *Parent_;
	}
	const Node* GetChild(int index)
	{
		return ChildNode_.size() >= index ? nullptr : ChildNode_[index];
	}
	Node* GetLastChild()
	{
		if (ChildNode_.size() == 0)
		{
			return nullptr;
		}

		return ChildNode_[ChildNode_.size() - 1];
	}
	const Node& GetFirstChildNode()
	{
		return *ChildNode_[0];
	}
	const Node& GetSibiling()
	{
		return *Sibiling_;
	}
	const int& GetHierarchyNumber()
	{
		return HierarchyNumber_;
	}
	const int& GetPriority()
	{
		return Priority_;
	}

	void SetParent(Node* parent)
	{
		parent != nullptr ? Parent_ = parent : Parent_ = nullptr;
	}

	void AddChild(Node* child)
	{
		child != nullptr ? ChildNode_.push_back(child) : ChildNode_.push_back(nullptr);
	}

	void SetSibling(Node* sibling)
	{
		sibling != nullptr ? Sibiling_ = sibling : Sibiling_ = nullptr;
	}

	bool CheckNullAction()
	{
		return ActionBase_ != nullptr ? true : false;
	}
public:
	bool Judgment(EnemyParameter* enemy);
	Node* SelectPriority(std::vector<Node*>* list);
	Node* SelectRandom(std::vector<Node*>* list);
	Node* SelectOnOff(std::vector<Node*>* list, BehaviorData* data);
	Node* SelectSequence(std::vector<Node*>* list, BehaviorData* data);
	Node* SearchNode(std::string search_name);
	Node* Inference(EnemyParameter* enemy, BehaviorData* data);
	//void PrintName();
	ActionBase::STATE Run(EnemyParameter* enemy);
protected:
	std::string Name_;
	TREE_RULE BTRuleBase_;
	JudgmentBase* JudgementBase_;
	ActionBase* ActionBase_;
	unsigned int Priority_;
	Node* Parent_;
	std::vector<Node*> ChildNode_;
	Node* Sibiling_;
	int HierarchyNumber_;
};