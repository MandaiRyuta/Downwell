#include "BehaviorTree.h"
#include "ActionBase.h"
#include "Node.h"
#include "../Actor/EnemyParameter.h"
#include "BehaviorData.h"
/// <summary>
/// ����֐�
/// </summary>
void BehaviorTree::Release()
{
	if (Add_Node_ != nullptr)
	{
		delete Add_Node_;
	}
	if (Root_ != nullptr)
	{
		delete Root_;
	}
}
/// <summary>
/// ���s�m�[�h�𐄘_����֐�
/// </summary>
/// <param name="Enemy">���_����m�[�h</param>
/// <param name="Data">���_����r�w�C�r�A�f�[�^</param>
/// <returns>���_���I�����e�m�[�h</returns>
Node* BehaviorTree::Inference(EnemyParameter* Enemy, BehaviorData* Data)
{
	Data->Init();
	return Root_->Inference(Enemy, Data);
}
/// <summary>
/// �V�[�P���X�m�[�h�𐄘_����֐�
/// </summary>
/// <param name="SequenceNode">�V�[�P���X�m�[�h</param>
/// <param name="Enemy">���_����G���</param>
/// <param name="Data">���_����r�w�C�r�A�f�[�^</param>
/// <returns>���_���I�����m�[�h</returns>
Node* BehaviorTree::SequenceBack(Node* SequenceNode, EnemyParameter* Enemy, BehaviorData* Data)
{
	return SequenceNode->Inference(Enemy, Data);;
}
/// <summary>
/// �m�[�h�ǉ��֐�
/// </summary>
/// <param name="SearchName">�m�[�h��</param>
/// <param name="EntryName">�m�[�h��</param>
/// <param name="nPriority">�D��x</param>
/// <param name="nSelectRule">���[��</param>
/// <param name="judgment">����N���X</param>
/// <param name="Action">�s���N���X</param>
void BehaviorTree::AddNode(std::string SearchName, std::string EntryName, int nPriority, TREE_RULE nSelectRule, ActionBase* Action)
{
	if (SearchName == "")
	{
		Root_ = new Node(EntryName, NULL, NULL, nPriority, nSelectRule, Action, 1);
	}
	else
	{
		Node* search = Root_->SearchNode(SearchName);

		if (search != nullptr)
		{
			Node* sibling = search->GetLastChild();
			Add_Node_ = new Node(EntryName, search, sibling, nPriority, nSelectRule, Action, search->GetHierarchyNumber() + 1);

			search->AddChild(Add_Node_);
		}
	}
}
/// <summary>
/// �X�V�֐�
/// </summary>
/// <param name="Enemy">�G���</param>
/// <param name="ActionNode">�s���m�[�h</param>
/// <param name="Data">�r�w�C�r�A�f�[�^</param>
/// <returns>���[���Ŕ��ʂ��I�����s���m�[�h</returns>
Node* BehaviorTree::Run(EnemyParameter& Enemy, Node* ActionNode, BehaviorData* Data)
{
	ActionBase::STATE state = ActionNode->Run(Enemy);

	if (state == ActionBase::STATE::COMPLETE)
	{
		Node* SequenceNode = Data->PopSequenceNode();

		if (SequenceNode == nullptr)
		{
			return nullptr;
		}
		else
		{
			return SequenceBack(SequenceNode, &Enemy, Data);
		}
	}
	else if (state == ActionBase::STATE::FAILED)
	{
		return nullptr;
	}

	return ActionNode;
}
