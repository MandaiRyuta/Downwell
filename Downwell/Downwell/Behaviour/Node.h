#pragma once
#include "../Constant.h"
#include "ActionBase.h"
class BehaviorTree;
class BehaviorData;

enum class TREE_RULE
{
	NONE,
	PRIORITY,
	SEQUENCE,
	SEQUENTIALLOOP,
	RANDOM,
	ON_OFF,
};

class Node
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	/// <param name="entry_name">�G���g���[��</param>
	/// <param name="parent_node">�o�^�����m�[�h�̌���</param>
	/// <param name="sibling">�Z��m�[�h</param>
	/// <param name="priority">�D��x</param>
	/// <param name="select_rule">�r�w�C�r�A�c���[�̑I�����[��</param>
	/// <param name="judgment">�؂�ւ��锻�f�N���X(�c����HP�ōs���𔻒f)</param>
	/// <param name="action">�s���N���X</param>
	/// <param name="hierarchy_number">�q�v�f�ɂ���Ă�����̂ɓo�^����q�G�����L�[</param>
	Node(std::string entry_name, Node* parent_node, Node* sibling, int priority, TREE_RULE select_rule, ActionBase* action, int hierarchy_number) :
		sName_(entry_name),
		Parent_(parent_node),
		Sibiling_(sibling),
		nPriority_(priority),
		BTRuleBase_(select_rule),
		ActionBase_(action),
		nHierarchyNumber_(hierarchy_number),
		ChildNode_(NULL)
	{}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	/// <returns></returns>
	~Node() {}
public:
	/// <summary>
	/// �G���g���[���擾�֐�
	/// </summary>
	/// <returns>�G���g���[��</returns>
	const std::string& GetName()
	{
		return sName_;
	}
	/// <summary>
	/// �e�m�[�h�擾�֐�
	/// </summary>
	/// <returns>�e�m�[�h</returns>
	const Node& GetParent()
	{
		return *Parent_;
	}
	/// <summary>
	/// �q�m�[�h�擾�֐�
	/// </summary>
	/// <param name="index">�q�m�[�h�̔ԍ�</param>
	/// <returns>�q�m�[�h</returns>
	const Node* GetChild(int index)
	{
		return ChildNode_.size() >= static_cast<size_t>(index) ? nullptr : ChildNode_[index];
	}
	/// <summary>
	/// �����q�m�[�h�擾�֐�
	/// </summary>
	/// <returns>�����q�m�[�h</returns>
	Node* GetLastChild()
	{
		if (ChildNode_.size() == 0)
		{
			return nullptr;
		}

		return ChildNode_[ChildNode_.size() - 1];
	}
	/// <summary>
	/// �擪�q�m�[�h�擾�֐�
	/// </summary>
	/// <returns>�擪�q�m�[�h</returns>
	const Node& GetFirstChildNode()
	{
		return *ChildNode_[0];
	}
	/// <summary>
	/// �Z��m�[�h�擾�֐�
	/// </summary>
	/// <returns>�Z��m�[�h</returns>
	const Node& GetSibiling()
	{
		return *Sibiling_;
	}
	/// <summary>
	/// �K�w�擾�֐�
	/// </summary>
	/// <returns>�K�w</returns>
	const int& GetHierarchyNumber()
	{
		return nHierarchyNumber_;
	}
	/// <summary>
	/// �D��x�擾�֐�
	/// </summary>
	/// <returns>�D��x</returns>
	const int& GetPriority()
	{
		return nPriority_;
	}
	/// <summary>
	/// �e�m�[�h��ݒ肷��֐�
	/// </summary>
	/// <param name="parent">�ݒ肷��e�m�[�h</param>
	void SetParent(Node* parent)
	{
		parent != nullptr ? Parent_ = parent : Parent_ = nullptr;
	}
	/// <summary>
	/// �q�m�[�h�̒ǉ��֐�
	/// </summary>
	/// <param name="child">�ǉ�����q�m�[�h</param>
	void AddChild(Node* child)
	{
		child != nullptr ? ChildNode_.push_back(child) : ChildNode_.push_back(nullptr);
	}
	/// <summary>
	/// �Z��m�[�h�̐ݒ�֐�
	/// </summary>
	/// <param name="sibling">�ݒ肷��Z��m�[�h</param>
	void SetSibling(Node* sibling)
	{
		sibling != nullptr ? Sibiling_ = sibling : Sibiling_ = nullptr;
	}
	/// <summary>
	/// �s���m�[�h�̏����m�F�֐�
	/// </summary>
	/// <returns>true : �������Ă���	false : �������Ă��Ȃ�</returns>
	bool CheckNullAction()
	{
		return ActionBase_ != nullptr ? true : false;
	}
public:
	/// <summary>
	/// �D�揇�ʑI���֐�
	/// </summary>
	/// <param name="list">�m�[�h���X�g</param>
	/// <returns>�D�揇�ʂ��r���I�����m�[�h</returns>
	Node* SelectPriority(std::vector<Node*>* list);
	/// <summary>
	/// �����_���I���֐�
	/// </summary>
	/// <param name="list">�m�[�h���X�g</param>
	/// <returns>�����_���I�����I�����m�[�h</returns>
	Node* SelectRandom(std::vector<Node*>* list);
	/// <summary>
	/// �I���I�t�I���֐�
	/// </summary>
	/// <param name="list">�m�[�h���X�g</param>
	/// <param name="data">�r�w�C�r�A�f�[�^</param>
	/// <returns>���s���Ă��Ȃ��m�[�h</returns>
	Node* SelectOnOff(std::vector<Node*>* list, BehaviorData* data);
	/// <summary>
	/// �V�[�P���X�I���֐�
	/// </summary>
	/// <param name="list">�m�[�h���X�g</param>
	/// <param name="data">�r�w�C�r�A�f�[�^</param>
	/// <returns>���Ԃɏ]�����m�[�h</returns>
	Node* SelectSequence(std::vector<Node*>* list, BehaviorData* data);
	/// <summary>
	/// �m�[�h�����֐�
	/// </summary>
	/// <param name="search_name">�T���Ă���m�[�h��</param>
	/// <returns>�T���Ă���m�[�h</returns>
	Node* SearchNode(std::string search_name);
	/// <summary>
	/// �m�[�h���_�֐�
	/// </summary>
	/// <param name="enemy">�G���</param>
	/// <param name="data">�r�w�C�r�A�f�[�^</param>
	/// <returns>���_���I�����m�[�h</returns>
	Node* Inference(EnemyParameter* enemy, BehaviorData* data);
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	/// <param name="enemy">�G���</param>
	/// <returns>ActionBase�̃X�e�[�g</returns>
	ActionBase::STATE Run(EnemyParameter* enemy);
protected:
	std::string sName_;	//���O
	TREE_RULE BTRuleBase_;	//�I�����[��
	ActionBase* ActionBase_;	//�s���N���X
	int nPriority_;	//�D��x
	Node* Parent_;	//�e�m�[�h
	std::vector<Node*> ChildNode_;	//�q�m�[�h
	Node* Sibiling_;	//�Z��m�[�h
	int nHierarchyNumber_;	//�K�w�ԍ�
};