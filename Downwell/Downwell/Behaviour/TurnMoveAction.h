#pragma once
#include "ActionBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"

class EnemyParameter;

class TurnMoveAction : public ActionBase
{
private:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	TurnMoveAction() : vMove_() {}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~TurnMoveAction() {}
public:
	/// <summary>
	/// �C���X�^���X�����֐�
	/// </summary>
	/// <returns>�ÓI��TurnMoveAction�̃C���X�^���X</returns>
	static TurnMoveAction* GetInstance()
	{
		static TurnMoveAction instance;
		return &instance;
	}
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	/// <param name="enemy">�G���</param>
	/// <returns>�X�e�[�g���</returns>
	virtual ActionBase:: STATE Run(EnemyParameter* enemy) override;
private:
	VECTOR vMove_[nTurnMoveMaxEnemy];	//�G�̈ړ���
};