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
/// <param name="enemy">���_����m�[�h</param>
/// <param name="data">���_����r�w�C�r�A�f�[�^</param>
/// <returns>���_���I�����e�m�[�h</returns>
Node* BehaviorTree::Inference(EnemyParameter* enemy, BehaviorData* data)
{
	data->Init();
	return Root_->Inference(enemy, data);
}
/// <summary>
/// �V�[�P���X�m�[�h�𐄘_����֐�
/// </summary>
/// <param name="sequence_node">�V�[�P���X�m�[�h</param>
/// <param name="enemy">���_����G���</param>
/// <param name="data">���_����r�w�C�r�A�f�[�^</param>
/// <returns>���_���I�����m�[�h</returns>
Node* BehaviorTree::SequenceBack(Node* sequence_node, EnemyParameter* enemy, BehaviorData* data)
{
	return sequence_node->Inference(enemy, data);;
}
/// <summary>
/// �m�[�h�ǉ��֐�
/// </summary>
/// <param name="search_name">�m�[�h��</param>
/// <param name="entry_name">�m�[�h��</param>
/// <param name="priority">�D��x</param>
/// <param name="select_rule">���[��</param>
/// <param name="judgment">����N���X</param>
/// <param name="action">�s���N���X</param>
void BehaviorTree::AddNode(std::string search_name, std::string entry_name, int priority, TREE_RULE select_rule, ActionBase* action)
{
	if (search_name == "")
	{
		Root_ = new Node(entry_name, NULL, NULL, priority, select_rule, action, 1);
	}
	else
	{
		Node* search = Root_->SearchNode(search_name);

		if (search != nullptr)
		{
			Node* sibling = search->GetLastChild();
			Add_Node_ = new Node(entry_name, search, sibling, priority, select_rule, action, search->GetHierarchyNumber() + 1);

			search->AddChild(Add_Node_);
		}
	}
}
/// <summary>
/// �X�V�֐�
/// </summary>
/// <param name="enemy">�G���</param>
/// <param name="actionnode">�s���m�[�h</param>
/// <param name="data">�r�w�C�r�A�f�[�^</param>
/// <returns>���[���Ŕ��ʂ��I�����s���m�[�h</returns>
Node* BehaviorTree::Run(EnemyParameter* enemy, Node* actionnode, BehaviorData* data)
{
	ActionBase::STATE state = actionnode->Run(enemy);

	if (state == ActionBase::STATE::COMPLETE)
	{
		Node* sequence_node = data->PopSequenceNode();

		if (sequence_node == nullptr)
		{
			return nullptr;
		}
		else
		{
			return SequenceBack(sequence_node, enemy, data);
		}
	}
	else if (state == ActionBase::STATE::FAILED)
	{
		return nullptr;
	}

	return actionnode;
}
