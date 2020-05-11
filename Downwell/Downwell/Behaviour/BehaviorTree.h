#pragma once

#include <string>
#include "Node.h"
class ActionBase;
class JudgmentBase;
class BehaviorData;
class EnemyParameter;
class JudgmentBase;

class BehaviorTree
{
public:
	BehaviorTree() : Root_(nullptr) {}
	~BehaviorTree() {}
	void Release();
	Node* Inference(EnemyParameter* enemy, BehaviorData* data);
	Node* SequenceBack(Node* sequence_node, EnemyParameter* enemy, BehaviorData* data);
	void AddNode(std::string search_name, std::string entry_name, int priority, TREE_RULE select_rule, JudgmentBase* judgment, ActionBase* action);
	Node* Run(EnemyParameter* enemy, Node* actionnode, BehaviorData* data);
private:
	Node* Root_;
	Node* Add_Node_;
};