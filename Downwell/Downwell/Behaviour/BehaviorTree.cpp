#include "BehaviorTree.h"
#include "ActionBase.h"
#include "Node.h"
#include "JudgmentBase.h"
#include "../Actor/EnemyParameter.h"
#include "BehaviorData.h"

void BehaviorTree::Release()
{
	if (Add_Node_ != nullptr)
	{
		Add_Node_->Release();
		delete Add_Node_;
	}
	if (Root_ != nullptr)
	{
		Root_->Release();
		delete Root_;
	}
}

Node* BehaviorTree::Inference(EnemyParameter* enemy, BehaviorData* data)
{
	data->Init();
	return Root_->Inference(enemy, data);
}

Node* BehaviorTree::SequenceBack(Node* sequence_node, EnemyParameter* enemy, BehaviorData* data)
{
	return sequence_node->Inference(enemy, data);;
}

void BehaviorTree::AddNode(std::string search_name, std::string entry_name, int priority, TREE_RULE select_rule, JudgmentBase* judgment, ActionBase* action)
{
	if (search_name == "")
	{
		Root_ = new Node(entry_name, NULL, NULL, priority, select_rule, judgment, action, 1);
	}
	else
	{
		Node* search = Root_->SearchNode(search_name);

		if (search != nullptr)
		{
			Node* sibling = search->GetLastChild();
			Add_Node_ = new Node(entry_name, search, sibling, priority, select_rule, judgment, action, search->GetHierarchyNumber() + 1);

			search->AddChild(Add_Node_);
		}
	}
}

Node* BehaviorTree::Run(EnemyParameter* enemy, Node* actionnode, BehaviorData* data)
{
	ActionBase::STATE state = actionnode->Run(enemy);

	if (state == ActionBase::STATE::COMPLETE)
	{
		Node* sequence_node = data->PopSequenceNode();

		if (sequence_node == nullptr)
		{
			return nullptr;
		}
		else
		{
			return SequenceBack(sequence_node, enemy, data);
		}
	}
	else if (state == ActionBase::STATE::FAILED)
	{
		return nullptr;
	}

	return actionnode;
}
