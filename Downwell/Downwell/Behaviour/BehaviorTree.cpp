#include "BehaviorTree.h"

void BehaviorTree::AddNode(std::string search_name, std::string entry_name, int priority, TREE_RULE select_rule, JudgmentBase* judgment, ActionBase* action)
{
	if (search_name == "")
	{
		Root_.SetNode(entry_name, NULL, NULL, priority, select_rule, judgment, action, 1);
	}
	else
	{
		Node* search = Root_.SearchNode(search_name);

		if (search != nullptr)
		{
			Node* sibling = &search->GetLastChild();
			Node* add_node = new Node(entry_name, search, sibling, priority, select_rule, judgment, action, search->GetHierarchyNumber() + 1);

			search->AddChild(add_node);
		}
	}
}

void BehaviorTree::SetRootNode(std::string& entry_name, Node* parent_node, Node* sibling, int& priority, TREE_RULE& select_rule, JudgmentBase* judgment, ActionBase* action, int hierarchy_number)
{
	Root_.SetNode(entry_name, parent_node, sibling, priority, select_rule, judgment, action, hierarchy_number);
}
