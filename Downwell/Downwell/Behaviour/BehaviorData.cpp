#include "BehaviorData.h"
#include "Node.h"

BehaviorData::~BehaviorData()
{
	UpdateSequenceStep_.clear();
	UsedNode_.clear();

	while (SequenceStack_.size() > 0)
	{
		SequenceStack_.pop();
	}
}

void BehaviorData::Init()
{
	UpdateSequenceStep_.clear();
	while (SequenceStack_.size() > 0)
	{
		SequenceStack_.pop();
	}
}

void BehaviorData::PushSequenceNode(Node* node)
{
	SequenceStack_.push(node);
}

Node* BehaviorData::PopSequenceNode()
{
	if (SequenceStack_.empty() != 0)
	{
		return nullptr;
	}

	Node* node = SequenceStack_.top();

	if (node != nullptr)
	{
		SequenceStack_.pop();
	}

	return node;
}

bool BehaviorData::NodeUsedExist(std::string name)
{
	if (UsedNode_.count(name) == 0)
	{
		return false;
	}

	return UsedNode_[name];
}

void BehaviorData::EntryUsedNode(std::string name)
{
	UsedNode_[name] = true;
}

int BehaviorData::GetSequenceStep(std::string name)
{
	if (UpdateSequenceStep_.count(name) == 0)
	{
		UpdateSequenceStep_[name] = 0;
	}
	return UpdateSequenceStep_[name];
}

void BehaviorData::SetSequenceStep(std::string name, int step)
{
	UpdateSequenceStep_[name] = step;
}

void BehaviorData::ResetUsedNode(std::vector<Node*>* reset_hierachy)
{
	for (auto itr = reset_hierachy->begin(); itr != reset_hierachy->end(); itr++)
	{
		UsedNode_[(*itr)->GetName()] = false;
	}
}





