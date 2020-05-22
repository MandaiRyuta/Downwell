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
	/// <param name="EntryName">�G���g���[��</param>
	/// <param name="ParentNode">�o�^�����m�[�h�̌���</param>
	/// <param name="Sibling">�Z��m�[�h</param>
	/// <param name="nPriority">�D��x</param>
	/// <param name="SelectRule">�r�w�C�r�A�c���[�̑I�����[��</param>
	/// <param name="Action">�s���N���X</param>
	/// <param name="HierarchyNumber">�q�v�f�ɂ���Ă�����̂ɓo�^����q�G�����L�[</param>
	Node(std::string EntryName, Node* ParentNode, Node* Sibling, int nPriority, TREE_RULE SelectRule, ActionBase* Action, int HierarchyNumber) :
		sName_(EntryName),
		Parent_(ParentNode),
		Sibiling_(Sibling),
		nPriority_(nPriority),
		BTRuleBase_(SelectRule),
		ActionBase_(Action),
		nHierarchyNumber_(HierarchyNumber),
		ChildNode_(NULL)
	{}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	/// <returns></returns>
	~Node() {}
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
	/// <param name="nIndex">�q�m�[�h�̔ԍ�</param>
	/// <returns>�q�m�[�h</returns>
	const Node* GetChild(int nIndex)
	{
		return ChildNode_.size() >= static_cast<size_t>(nIndex) ? nullptr : ChildNode_[nIndex];
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
	/// <param name="Parent">�ݒ肷��e�m�[�h</param>
	void SetParent(Node* Parent)
	{
		Parent != nullptr ? Parent_ = Parent : Parent_ = nullptr;
	}
	/// <summary>
	/// �q�m�[�h�̒ǉ��֐�
	/// </summary>
	/// <param name="Child">�ǉ�����q�m�[�h</param>
	void AddChild(Node* Child)
	{
		Child != nullptr ? ChildNode_.push_back(Child) : ChildNode_.push_back(nullptr);
	}
	/// <summary>
	/// �Z��m�[�h�̐ݒ�֐�
	/// </summary>
	/// <param name="Sibling">�ݒ肷��Z��m�[�h</param>
	void SetSibling(Node* Sibling)
	{
		Sibling != nullptr ? Sibiling_ = Sibling : Sibiling_ = nullptr;
	}
	/// <summary>
	/// �s���m�[�h�̏����m�F�֐�
	/// </summary>
	/// <returns>true : �������Ă���	false : �������Ă��Ȃ�</returns>
	bool CheckNullAction()
	{
		return ActionBase_ != nullptr ? true : false;
	}
	/// <summary>
	/// �D�揇�ʑI���֐�
	/// </summary>
	/// <param name="List">�m�[�h���X�g</param>
	/// <returns>�D�揇�ʂ��r���I�����m�[�h</returns>
	Node* SelectPriority(std::vector<Node*>* List);
	/// <summary>
	/// �����_���I���֐�
	/// </summary>
	/// <param name="List">�m�[�h���X�g</param>
	/// <returns>�����_���I�����I�����m�[�h</returns>
	Node* SelectRandom(std::vector<Node*>* List);
	/// <summary>
	/// �I���I�t�I���֐�
	/// </summary>
	/// <param name="List">�m�[�h���X�g</param>
	/// <param name="Data">�r�w�C�r�A�f�[�^</param>
	/// <returns>���s���Ă��Ȃ��m�[�h</returns>
	Node* SelectOnOff(std::vector<Node*>* List, BehaviorData* Data);
	/// <summary>
	/// �V�[�P���X�I���֐�
	/// </summary>
	/// <param name="List">�m�[�h���X�g</param>
	/// <param name="Data">�r�w�C�r�A�f�[�^</param>
	/// <returns>���Ԃɏ]�����m�[�h</returns>
	Node* SelectSequence(std::vector<Node*>* List, BehaviorData* Data);
	/// <summary>
	/// �m�[�h�����֐�
	/// </summary>
	/// <param name="SearchName">�T���Ă���m�[�h��</param>
	/// <returns>�T���Ă���m�[�h</returns>
	Node* SearchNode(std::string SearchName);
	/// <summary>
	/// �m�[�h���_�֐�
	/// </summary>
	/// <param name="Enemy">�G���</param>
	/// <param name="Data">�r�w�C�r�A�f�[�^</param>
	/// <returns>���_���I�����m�[�h</returns>
	Node* Inference(EnemyParameter* Enemy, BehaviorData* Data);
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	/// <param name="Enemy">�G���</param>
	/// <returns>ActionBase�̃X�e�[�g</returns>
	ActionBase::STATE Run(EnemyParameter& Enemy);
private:
	std::string sName_;	//���O
	TREE_RULE BTRuleBase_;	//�I�����[��
	ActionBase* ActionBase_;	//�s���N���X
	int nPriority_;	//�D��x
	Node* Parent_;	//�e�m�[�h
	std::vector<Node*> ChildNode_;	//�q�m�[�h
	Node* Sibiling_;	//�Z��m�[�h
	int nHierarchyNumber_;	//�K�w�ԍ�
};