#include "Node.h"
#include <random>
#include "BehaviorData.h"
/// <summary>
/// 実行確認関数
/// </summary>
/// <param name="enemy">敵情報</param>
/// <returns>true : 実行	false : 中断</returns>
bool Node::Judgment(EnemyParameter* enemy)
{
	if (JudgementBase_ != nullptr)
	{
		return JudgementBase_->Judgment(enemy);
	}

	return true;
}
/// <summary>
/// 優先順位選択関数
/// </summary>
/// <param name="list">ノードリスト</param>
/// <returns>優先順位を比較し終えたノード</returns>
Node* Node::SelectPriority(std::vector<Node*>* list)
{
	if (list == nullptr) return nullptr;
	
	Node* selectnode = nullptr;
	int priority = -1;

	for (auto itr : *list)
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
/// <param name="list">ノードリスト</param>
/// <returns>ランダム選択を終えたノード</returns>
Node* Node::SelectRandom(std::vector<Node*>* list)
{
	std::mt19937 mt;
	std::random_device rnd;
	int lastlist = static_cast<int>(list->size());
	std::uniform_int_distribution<> rand(0, lastlist);

	return (*list)[rand(mt)];
}
/// <summary>
/// オンオフ選択関数
/// </summary>
/// <param name="list">ノードリスト</param>
/// <param name="data">ビヘイビアデータ</param>
/// <returns>実行していないノード</returns>
Node* Node::SelectOnOff(std::vector<Node*>* list, BehaviorData* data)
{
	std::vector<Node*> offlist;

	for (auto itr : *list)
	{
		if (data->NodeUsedExist(itr->GetName()) == false)
		{
			offlist.push_back(itr);
		}
	}

	if (offlist.size() == 0)
	{
		data->ResetUsedNode(&ChildNode_);
		offlist = *list;
	}

	data->EntryUsedNode(offlist[0]->GetName());

	return offlist[0];
}
/// <summary>
/// シーケンス選択関数
/// </summary>
/// <param name="list">ノードリスト</param>
/// <param name="data">ビヘイビアデータ</param>
/// <returns>順番に従ったノード</returns>
Node* Node::SelectSequence(std::vector<Node*>* list, BehaviorData* data)
{
	int SequenceStep = data->GetSequenceStep(GetName());

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

	for (auto itr : *list)
	{
		if (ChildNode_[SequenceStep]->GetName() == (itr)->GetName())
		{
			data->PushSequenceNode(this);
			data->SetSequenceStep(GetName(), SequenceStep + 1);
			return ChildNode_[SequenceStep];
		}
	}

	return nullptr;
}
/// <summary>
/// ノード検索関数
/// </summary>
/// <param name="search_name">探しているノード名</param>
/// <returns>探しているノード</returns>
Node* Node::SearchNode(std::string search_name)
{
	if (sName_ == search_name)
	{
		return this;
	}
	else
	{
		for (auto itr : ChildNode_)
		{
			Node* ret = itr->SearchNode(search_name);

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
/// <param name="enemy">敵情報</param>
/// <param name="data">ビヘイビアデータ</param>
/// <returns>推論し終えたノード</returns>
Node* Node::Inference(EnemyParameter* enemy, BehaviorData* data)
{
	std::vector<Node*> list;
	Node* result = nullptr;

	for (int i = 0; i < ChildNode_.size(); i++)
	{
		if (ChildNode_[i]->JudgementBase_ != nullptr)
		{
			if (ChildNode_[i]->JudgementBase_->Judgment(enemy) == true)
			{
				list.push_back(ChildNode_[i]);
			}
		}
		else
		{
			list.push_back(ChildNode_[i]);
		}
	}

	switch (BTRuleBase_)
	{
	case TREE_RULE::PRIORITY:
		result = SelectPriority(&list);
		break;
	case TREE_RULE::ON_OFF:
		result = SelectOnOff(&list, data);
		break;
	case TREE_RULE::RANDOM:
		result = SelectRandom(&list);
		break;
	case TREE_RULE::SEQUENCE:
	case TREE_RULE::SEQUENTIALLOOP:
		result = SelectSequence(&list, data);
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
			result = result->Inference(enemy, data);
		}
	}

	return result;
}
/// <summary>
/// 更新関数
/// </summary>
/// <param name="enemy">敵情報</param>
/// <returns>ActionBaseのステート</returns>
ActionBase::STATE Node::Run(EnemyParameter* enemy)
{
	if (ActionBase_ != nullptr)
	{
		return ActionBase_->Run(enemy);
	}

	return ActionBase::STATE::FAILED;
}
