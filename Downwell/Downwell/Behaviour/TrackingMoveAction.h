#pragma once
#include "ActionBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"
class EnemyParameter;

class TrackingMoveAction : public ActionBase
{
private:
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
	/// �C���X�^���X�����֐�
	/// </summary>
	/// <returns>�ÓI��TrackingMoveAction�̃C���X�^���X</returns>
	static TrackingMoveAction* GetInstance()
	{
		static TrackingMoveAction instance;

		return &instance;
	}
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	/// <param name="Enemy">�G���</param>
	/// <returns>�X�e�[�g���</returns>
	virtual ActionBase::STATE Run(EnemyParameter& Enemy) override;
private:
	VECTOR vMove_[nTrackingMoveMaxEnemy];	//�G�̈ړ���
};