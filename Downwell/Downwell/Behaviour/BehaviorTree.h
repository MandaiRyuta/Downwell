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
	/// <param name="enemy">���_����m�[�h</param>
	/// <param name="data">���_����r�w�C�r�A�f�[�^</param>
	/// <returns>���_���I�����e�m�[�h</returns>
	Node* Inference(EnemyParameter* enemy, BehaviorData* data);
	/// <summary>
	/// �V�[�P���X�m�[�h�𐄘_����֐�
	/// </summary>
	/// <param name="sequence_node">�V�[�P���X�m�[�h</param>
	/// <param name="enemy">���_����G���</param>
	/// <param name="data">���_����r�w�C�r�A�f�[�^</param>
	/// <returns>���_���I�����m�[�h</returns>
	Node* SequenceBack(Node* sequence_node, EnemyParameter* enemy, BehaviorData* data);
	/// <summary>
	/// �m�[�h�ǉ��֐�
	/// </summary>
	/// <param name="search_name">�m�[�h��</param>
	/// <param name="entry_name">�m�[�h��</param>
	/// <param name="priority">�D��x</param>
	/// <param name="select_rule">���[��</param>
	/// <param name="judgment">����N���X</param>
	/// <param name="action">�s���N���X</param>
	void AddNode(std::string search_name, std::string entry_name, int priority, TREE_RULE select_rule, ActionBase* action);
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	/// <param name="enemy">�G���</param>
	/// <param name="actionnode">�s���m�[�h</param>
	/// <param name="data">�r�w�C�r�A�f�[�^</param>
	/// <returns>���[���Ŕ��ʂ��I�����s���m�[�h</returns>
	Node* Run(EnemyParameter* enemy, Node* actionnode, BehaviorData* data);
private:
	Node* Root_;	//�e�m�[�h
	Node* Add_Node_;	//�ǉ��m�[�h
};