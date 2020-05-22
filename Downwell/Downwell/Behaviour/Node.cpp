#include "Node.h"
#include <random>
#include "BehaviorData.h"

/// <summary>
/// �D�揇�ʑI���֐�
/// </summary>
/// <param name="List">�m�[�h���X�g</param>
/// <returns>�D�揇�ʂ��r���I�����m�[�h</returns>
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
/// �����_���I���֐�
/// </summary>
/// <param name="List">�m�[�h���X�g</param>
/// <returns>�����_���I�����I�����m�[�h</returns>
Node* Node::SelectRandom(std::vector<Node*>* List)
{
	std::mt19937 mt;
	std::random_device rnd;
	int lastList = static_cast<int>(List->size());
	std::uniform_int_distribution<> rand(0, lastList);

	return (*List)[rand(mt)];
}
/// <summary>
/// �I���I�t�I���֐�
/// </summary>
/// <param name="List">�m�[�h���X�g</param>
/// <param name="Data">�r�w�C�r�A�f�[�^</param>
/// <returns>���s���Ă��Ȃ��m�[�h</returns>
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
/// �V�[�P���X�I���֐�
/// </summary>
/// <param name="List">�m�[�h���X�g</param>
/// <param name="Data">�r�w�C�r�A�f�[�^</param>
/// <returns>���Ԃɏ]�����m�[�h</returns>
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
/// �m�[�h�����֐�
/// </summary>
/// <param name="SearchName">�T���Ă���m�[�h��</param>
/// <returns>�T���Ă���m�[�h</returns>
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
/// �m�[�h���_�֐�
/// </summary>
/// <param name="Enemy">�G���</param>
/// <param name="Data">�r�w�C�r�A�f�[�^</param>
/// <returns>���_���I�����m�[�h</returns>
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
/// �X�V�֐�
/// </summary>
/// <param name="Enemy">�G���</param>
/// <returns>ActionBase�̃X�e�[�g</returns>
ActionBase::STATE Node::Run(EnemyParameter& Enemy)
{
	if (ActionBase_ != nullptr)
	{
		return ActionBase_->Run(Enemy);
	}

	return ActionBase::STATE::FAILED;
}
