#pragma once
#include "ActionBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"
class EnemyParameter;

class TrackingMoveAction : public ActionBase
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	TrackingMoveAction() : vMove_() {}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~TrackingMoveAction() {}
public:
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	/// <param name="Enemy">�G���</param>
	/// <returns>�X�e�[�g���</returns>
	virtual ActionBase::STATE Run(EnemyParameter& Enemy) override;
private:
	VECTOR vMove_[nTrackingMoveMaxEnemy];	//�G�̈ړ���
};