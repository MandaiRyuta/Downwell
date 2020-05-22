#pragma once

#include <string>
#include "Node.h"
class ActionBase;	//�A�N�V�����x�[�X�N���X
class BehaviorData;	//�r�w�C�r�A�f�[�^�N���X
class EnemyParameter;	//�G�p�����[�^�[�N���X

class BehaviorTree
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	BehaviorTree() : Root_(nullptr), Add_Node_(nullptr) {}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~BehaviorTree() {}
	/// <summary>
	/// ����֐�
	/// </summary>
	void Release();
	/// <summary>
	/// ���s�m�[�h�𐄘_����֐�
	/// </summary>
	/// <param name="Enemy">���_����m�[�h</param>
	/// <param name="Data">���_����r�w�C�r�A�f�[�^</param>
	/// <returns>���_���I�����e�m�[�h</returns>
	Node* Inference(EnemyParameter* Enemy, BehaviorData* Data);
	/// <summary>
	/// �V�[�P���X�m�[�h�𐄘_����֐�
	/// </summary>
	/// <param name="SequenceNode">�V�[�P���X�m�[�h</param>
	/// <param name="Enemy">���_����G���</param>
	/// <param name="Data">���_����r�w�C�r�A�f�[�^</param>
	/// <returns>���_���I�����m�[�h</returns>
	Node* SequenceBack(Node* SequenceNode, EnemyParameter* Enemy, BehaviorData* Data);
	/// <summary>
	/// �m�[�h�ǉ��֐�
	/// </summary>
	/// <param name="SearchName">�m�[�h��</param>
	/// <param name="EntryName">�m�[�h��</param>
	/// <param name="nPriority">�D��x</param>
	/// <param name="SelectRule">���[��</param>
	/// <param name="Action">�s���N���X</param>
	void AddNode(std::string SearchName, std::string EntryName, int nPriority, TREE_RULE SelectRule, ActionBase* Action);
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	/// <param name="Enemy">�G���</param>
	/// <param name="ActionNode">�s���m�[�h</param>
	/// <param name="Data">�r�w�C�r�A�f�[�^</param>
	/// <returns>���[���Ŕ��ʂ��I�����s���m�[�h</returns>
	Node* Run(EnemyParameter& Enemy, Node* ActionNode, BehaviorData* Data);
private:
	Node* Root_;	//�e�m�[�h
	Node* Add_Node_;	//�ǉ��m�[�h
};