#include "BehaviorData.h"
#include "Node.h"
/// <summary>
/// �f�X�g���N�^�[
/// </summary>
BehaviorData::~BehaviorData()
{
	UpdateSequenceStep_.clear();
	UsedNode_.clear();

	while (SequenceStack_.size() > 0)
	{
		SequenceStack_.pop();
	}
}
/// <summary>
/// �������֐�
/// </summary>
void BehaviorData::Init()
{
	UpdateSequenceStep_.clear();
	while (SequenceStack_.size() > 0)
	{
		SequenceStack_.pop();
	}
}
/// <summary>
/// �V�[�P���X�m�[�h��ǉ�����֐�
/// </summary>
/// <param name="node">�ǉ�����m�[�h</param>
void BehaviorData::PushSequenceNode(Node* node)
{
	SequenceStack_.push(node);
}
/// <summary>
/// �V�[�P���X�m�[�h����m�[�h����菜���֐�
/// </summary>
/// <returns>��菜�����V�[�P���X�m�[�h</returns>
Node* BehaviorData::PopSequenceNode()
{
	if (SequenceStack_.empty() != 0)
	{
		return nullptr;
	}

	Node* node = SequenceStack_.top();

	if (node != nullptr)
	{
		SequenceStack_.pop();
	}

	return node;
}
/// <summary>
/// �m�[�h���g���Ă��邩�m�F����֐�
/// </summary>
/// <param name="name">�m�[�h��</param>
/// <returns>true : �g�p�@false : ���g�p</returns>
bool BehaviorData::NodeUsedExist(std::string name)
{
	if (UsedNode_.count(name) == 0)
	{
		return false;
	}

	return UsedNode_[name];
}
/// <summary>
/// �w�肵���m�[�h���g�p����Ƃ��̖��ߊ֐�
/// </summary>
/// <param name="name">�g�p����m�[�h��</param>
void BehaviorData::EntryUsedNode(std::string name)
{
	UsedNode_[name] = true;
}
/// <summary>
/// �V�[�P���X�ԍ��擾�֐�
/// </summary>
/// <param name="name">�V�[�P���X��</param>
/// <returns></returns>
int BehaviorData::GetSequenceStep(std::string name)
{
	if (UpdateSequenceStep_.count(name) == 0)
	{
		UpdateSequenceStep_[name] = 0;
	}
	return UpdateSequenceStep_[name];
}
/// <summary>
/// �V�[�P���X�o�^�֐�
/// </summary>
/// <param name="name">�V�[�P���X��</param>
/// <param name="step">�V�[�P���X�ԍ�</param>
void BehaviorData::SetSequenceStep(std::string name, int step)
{
	UpdateSequenceStep_[name] = step;
}
/// <summary>
/// �g�p���Ă���m�[�h�̃��Z�b�g�֐�
/// </summary>
/// <param name="reset_hierachy">���Z�b�g�m�[�h</param>
void BehaviorData::ResetUsedNode(std::vector<Node*>* reset_hierachy)
{
	for (auto itr = reset_hierachy->begin(); itr != reset_hierachy->end(); itr++)
	{
		UsedNode_[(*itr)->GetName()] = false;
	}
}





