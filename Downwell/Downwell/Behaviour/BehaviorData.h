#pragma once
#include <vector>
#include <map>
#include <stack>
#include <string>
#include "BehaviorTree.h"
class Node;	//�m�[�h�N���X

class BehaviorData
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	BehaviorData()
	{
		Init();
	}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~BehaviorData();
	/// <summary>
	/// �������֐�
	/// </summary>
	void Init();
	/// <summary>
	/// �V�[�P���X�m�[�h��ǉ�����֐�
	/// </summary>
	/// <param name="node">�ǉ�����m�[�h</param>
	void PushSequenceNode(Node* node);
	/// <summary>
	/// �V�[�P���X�m�[�h����m�[�h����菜���֐�
	/// </summary>
	/// <returns>��菜�����V�[�P���X�m�[�h</returns>
	Node* PopSequenceNode();
	/// <summary>
	/// �m�[�h���g���Ă��邩�m�F����֐�
	/// </summary>
	/// <param name="name">�m�[�h��</param>
	/// <returns>true : �g�p�@false : ���g�p</returns>
	bool NodeUsedExist(std::string name);
	/// <summary>
	/// �w�肵���m�[�h���g�p����Ƃ��̖��ߊ֐�
	/// </summary>
	/// <param name="name">�g�p����m�[�h��</param>
	void EntryUsedNode(std::string name);
	/// <summary>
	/// �V�[�P���X�ԍ��擾�֐�
	/// </summary>
	/// <param name="name">�V�[�P���X��</param>
	/// <returns></returns>
	int GetSequenceStep(std::string name);
	/// <summary>
	/// �V�[�P���X�o�^�֐�
	/// </summary>
	/// <param name="name">�V�[�P���X��</param>
	/// <param name="step">�V�[�P���X�ԍ�</param>
	void SetSequenceStep(std::string name, int step);
	/// <summary>
	/// �g�p���Ă���m�[�h�̃��Z�b�g�֐�
	/// </summary>
	/// <param name="reset_hierachy">���Z�b�g�m�[�h</param>
	void ResetUsedNode(std::vector<Node*>* reset_hierachy);
private:
	std::stack<Node*> SequenceStack_;	//�V�[�P���X�m�[�h
	std::map<std::string, int> UpdateSequenceStep_;	//�V�[�P���X�ԍ�
	std::map<std::string, bool> UsedNode_;	//�V�[�P���X�g�p�t���O
};