#include "Node.h"
#include <random>
#include "BehaviorData.h"

/// <summary>
/// 優先順位選択関数
/// </summary>
/// <param name="List">ノードリスト</param>
/// <returns>優先順位を比較し終えたノード</returns>
Node* Node::SelectPriority(std::vector<Node*>* List)
{
	if (List == nullptr) return nullptr;
	
	Node* selectnode = nullptr;
	int priority = -1;

	for (auto itr : *List)
	{
		if (priority < itr->GetPriority())
		{
			selectnode = itr;
			priority = itr->GetPriority();
		}
	}
	
	return selectnode;
}
/// <summary>
/// ランダム選択関数
/// </summary>
/// <param name="List">ノードリスト</param>
/// <returns>ランダム選択を終えたノード</returns>
Node* Node::SelectRandom(std::vector<Node*>* List)
{
	std::mt19937 mt;
	std::random_device rnd;
	int lastList = static_cast<int>(List->size());
	std::uniform_int_distribution<> rand(0, lastList);

	return (*List)[rand(mt)];
}
/// <summary>
/// オンオフ選択関数
/// </summary>
/// <param name="List">ノードリスト</param>
/// <param name="Data">ビヘイビアデータ</param>
/// <returns>実行していないノード</returns>
Node* Node::SelectOnOff(std::vector<Node*>* List, BehaviorData* Data)
{
	std::vector<Node*> offList;

	for (auto itr : *List)
	{
		if (Data->NodeUsedExist(itr->GetName()) == false)
		{
			offList.push_back(itr);
		}
	}

	if (offList.size() == 0)
	{
		Data->ResetUsedNode(&ChildNode_);
		offList = *List;
	}

	Data->EntryUsedNode(offList[0]->GetName());

	return offList[0];
}
/// <summary>
/// シーケンス選択関数
/// </summary>
/// <param name="List">ノードリスト</param>
/// <param name="Data">ビヘイビアデータ</param>
/// <returns>順番に従ったノード</returns>
Node* Node::SelectSequence(std::vector<Node*>* List, BehaviorData* Data)
{
	int SequenceStep = Data->GetSequenceStep(GetName());

	if (SequenceStep >= ChildNode_.size())
	{
		if (BTRuleBase_ != TREE_RULE::SEQUENTIALLOOP)
		{
			return nullptr;
		}
		else
		{
			SequenceStep = 0;
		}
	}

	for (auto itr : *List)
	{
		if (ChildNode_[SequenceStep]->GetName() == (itr)->GetName())
		{
			Data->PushSequenceNode(this);
			Data->SetSequenceStep(GetName(), SequenceStep + 1);
			return ChildNode_[SequenceStep];
		}
	}

	return nullptr;
}
/// <summary>
/// ノード検索関数
/// </summary>
/// <param name="SearchName">探しているノード名</param>
/// <returns>探しているノード</returns>
Node* Node::SearchNode(std::string SearchName)
{
	if (sName_ == SearchName)
	{
		return this;
	}
	else
	{
		for (auto itr : ChildNode_)
		{
			Node* ret = itr->SearchNode(SearchName);

			if (ret != nullptr)
			{
				return ret;
			}
		}
	}
	return nullptr;
}
/// <summary>
/// ノード推論関数
/// </summary>
/// <param name="Enemy">敵情報</param>
/// <param name="Data">ビヘイビアデータ</param>
/// <returns>推論し終えたノード</returns>
Node* Node::Inference(EnemyParameter* Enemy, BehaviorData* Data)
{
	std::vector<Node*> List;
	Node* result = nullptr;

	for (int i = 0; i < ChildNode_.size(); i++)
	{
		List.push_back(ChildNode_[i]);
	}

	switch (BTRuleBase_)
	{
	case TREE_RULE::PRIORITY:
		result = SelectPriority(&List);
		break;
	case TREE_RULE::ON_OFF:
		result = SelectOnOff(&List, Data);
		break;
	case TREE_RULE::RANDOM:
		result = SelectRandom(&List);
		break;
	case TREE_RULE::SEQUENCE:
	case TREE_RULE::SEQUENTIALLOOP:
		result = SelectSequence(&List, Data);
		break;
	default:
		break;
	}

	if (result != nullptr)
	{
		if (result->CheckNullAction())
		{
			return result;
		}
		else
		{
			result = result->Inference(Enemy, Data);
		}
	}

	return result;
}
/// <summary>
/// 更新関数
/// </summary>
/// <param name="Enemy">敵情報</param>
/// <returns>ActionBaseのステート</returns>
ActionBase::STATE Node::Run(EnemyParameter& Enemy)
{
	if (ActionBase_ != nullptr)
	{
		return ActionBase_->Run(Enemy);
	}

	return ActionBase::STATE::FAILED;
}
