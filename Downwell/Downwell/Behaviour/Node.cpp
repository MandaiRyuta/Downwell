#include "Node.h"
#include <random>
#include "BehaviorData.h"
/// <summary>
/// ���s�m�F�֐�
/// </summary>
/// <param name="enemy">�G���</param>
/// <returns>true : ���s	false : ���f</returns>
bool Node::Judgment(EnemyParameter* enemy)
{
	if (JudgementBase_ != nullptr)
	{
		return JudgementBase_->Judgment(enemy);
	}

	return true;
}
/// <summary>
/// �D�揇�ʑI���֐�
/// </summary>
/// <param name="list">�m�[�h���X�g</param>
/// <returns>�D�揇�ʂ��r���I�����m�[�h</returns>
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
/// �����_���I���֐�
/// </summary>
/// <param name="list">�m�[�h���X�g</param>
/// <returns>�����_���I�����I�����m�[�h</returns>
Node* Node::SelectRandom(std::vector<Node*>* list)
{
	std::mt19937 mt;
	std::random_device rnd;
	int lastlist = static_cast<int>(list->size());
	std::uniform_int_distribution<> rand(0, lastlist);

	return (*list)[rand(mt)];
}
/// <summary>
/// �I���I�t�I���֐�
/// </summary>
/// <param name="list">�m�[�h���X�g</param>
/// <param name="data">�r�w�C�r�A�f�[�^</param>
/// <returns>���s���Ă��Ȃ��m�[�h</returns>
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
/// �V�[�P���X�I���֐�
/// </summary>
/// <param name="list">�m�[�h���X�g</param>
/// <param name="data">�r�w�C�r�A�f�[�^</param>
/// <returns>���Ԃɏ]�����m�[�h</returns>
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
/// �m�[�h�����֐�
/// </summary>
/// <param name="search_name">�T���Ă���m�[�h��</param>
/// <returns>�T���Ă���m�[�h</returns>
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
/// �m�[�h���_�֐�
/// </summary>
/// <param name="enemy">�G���</param>
/// <param name="data">�r�w�C�r�A�f�[�^</param>
/// <returns>���_���I�����m�[�h</returns>
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
/// �X�V�֐�
/// </summary>
/// <param name="enemy">�G���</param>
/// <returns>ActionBase�̃X�e�[�g</returns>
ActionBase::STATE Node::Run(EnemyParameter* enemy)
{
	if (ActionBase_ != nullptr)
	{
		return ActionBase_->Run(enemy);
	}

	return ActionBase::STATE::FAILED;
}
