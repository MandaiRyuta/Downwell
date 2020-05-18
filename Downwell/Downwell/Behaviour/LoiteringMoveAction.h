#pragma once
#include "ActionBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"
class EnemyParameter;

class LoiterningMoveAction : public ActionBase
{
private:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	LoiterningMoveAction() : vMove_(){}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~LoiterningMoveAction() {}
public:
	/// <summary>
	/// �C���X�^���X�擾�֐�
	/// </summary>
	/// <returns>�ÓI��LoiterningMoveAction�̃C���X�^���X</returns>
	static LoiterningMoveAction* GetInstance()
	{
		static LoiterningMoveAction instance;
		return &instance;
	}
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	/// <param name="enemy">�G���</param>
	/// <returns>�X�e�[�g���</returns>
	virtual ActionBase::STATE Run(EnemyParameter* enemy);
private:
	VECTOR vMove_[nLoiterningMoveMaxEnemy];	//�G�̈ړ����
};