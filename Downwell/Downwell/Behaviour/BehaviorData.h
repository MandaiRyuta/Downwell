#pragma once
#include <vector>
#include <map>
#include <stack>
#include <string>
#include "BehaviorTree.h"
class Node;

class BehaviorData
{
public:
	BehaviorData()
	{
		Init();
	}
	void Release();
	void Init();
	void PushSequenceNode(Node* node);
	Node* PopSequenceNode();
	bool NodeUsedExist(std::string name);
	void EntryUsedNode(std::string name);
	int GetSequenceStep(std::string name);
	void SetSequenceStep(std::string name, int step);
	void ResetUsedNode(std::vector<Node*>* reset_hierachy);
private:
	std::stack<Node*> SequenceStack_;
	std::map<std::string, int> UpdateSequenceStep_;
	std::map<std::string, bool> UsedNode_;
};