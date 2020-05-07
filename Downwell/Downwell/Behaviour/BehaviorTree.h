#pragma once

#include <string>
#include "Node.h"
class ActionBase;
class BehaviourDaba;
class EnemyParameter;
class JudgmentBase;

class BehaviorTree
{
public:
	BehaviorTree(){}
	void AddNode(std::string search_name, std::string entry_name, int priority, TREE_RULE select_rule, JudgmentBase* judgment, ActionBase* action);
	void SetRootNode(std::string& entry_name, Node* parent_node, Node* sibling, int& priority, TREE_RULE& select_rule, JudgmentBase* judgment, ActionBase* action, int hierarchy_number);

private:
	Node Root_;
};