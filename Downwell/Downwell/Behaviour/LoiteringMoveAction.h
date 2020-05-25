#pragma once
#include "ActionBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"
class EnemyParameter;

class LoiterningMoveAction : public ActionBase
{
public:
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
	/// �X�V�֐�
	/// </summary>
	/// <param name="Enemy">�G���</param>
	/// <returns>�X�e�[�g���</returns>
	virtual ActionBase::STATE Run(EnemyParameter& Enemy);
private:
	VECTOR vMove_[nLoiterningMoveMaxEnemy];	//�G�̈ړ����
};