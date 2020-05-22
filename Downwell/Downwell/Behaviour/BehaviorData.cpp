#include "BehaviorData.h"
#include "Node.h"
#include "../DownwellConstant.h"
/// <summary>
/// �f�X�g���N�^�[
/// </summary>
BehaviorData::~BehaviorData()
{
	UpdateSequenceStep_.clear();
	UsedNode_.clear();

	while (SequenceStack_.size() > nZeroSize)
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
	while (SequenceStack_.size() > nZeroSize)
	{
		SequenceStack_.pop();
	}
}
/// <summary>
/// �V�[�P���X�m�[�h��ǉ�����֐�
/// </summary>
/// <param name="Node">�ǉ�����m�[�h</param>
void BehaviorData::PushSequenceNode(Node* Node)
{
	SequenceStack_.push(Node);
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
/// <param name="Name">�m�[�h��</param>
/// <returns>true : �g�p�@false : ���g�p</returns>
bool BehaviorData::NodeUsedExist(std::string Name)
{
	if (UsedNode_.count(Name) == 0)
	{
		return false;
	}

	return UsedNode_[Name];
}
/// <summary>
/// �w�肵���m�[�h���g�p����Ƃ��̖��ߊ֐�
/// </summary>
/// <param name="Name">�g�p����m�[�h��</param>
void BehaviorData::EntryUsedNode(std::string Name)
{
	UsedNode_[Name] = true;
}
/// <summary>
/// �V�[�P���X�ԍ��擾�֐�
/// </summary>
/// <param name="Name">�V�[�P���X��</param>
/// <returns></returns>
int BehaviorData::GetSequenceStep(std::string Name)
{
	if (UpdateSequenceStep_.count(Name) == 0)
	{
		UpdateSequenceStep_[Name] = 0;
	}
	return UpdateSequenceStep_[Name];
}
/// <summary>
/// �V�[�P���X�o�^�֐�
/// </summary>
/// <param name="Name">�V�[�P���X��</param>
/// <param name="nStep">�V�[�P���X�ԍ�</param>
void BehaviorData::SetSequenceStep(std::string Name, int nStep)
{
	UpdateSequenceStep_[Name] = nStep;
}
/// <summary>
/// �g�p���Ă���m�[�h�̃��Z�b�g�֐�
/// </summary>
/// <param name="ResetHierachy">���Z�b�g�m�[�h</param>
void BehaviorData::ResetUsedNode(std::vector<Node*>* ResetHierachy)
{
	for (auto itr = ResetHierachy->begin(); itr != ResetHierachy->end(); itr++)
	{
		UsedNode_[(*itr)->GetName()] = false;
	}
}





