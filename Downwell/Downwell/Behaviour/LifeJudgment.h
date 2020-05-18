#pragma once
#include "JudgmentBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"

class EnemyParameter;	//�G�p�����[�^�N���X

class LifeJudgment : public JudgmentBase
{
public:
	/// <summary>
	/// �C���X�^���X���擾����֐�
	/// </summary>
	/// <returns>�ÓI��LifeJudgment�̃C���X�^���X</returns>
	static LifeJudgment* GetInstance()
	{
		static LifeJudgment Instance;
		return &Instance;
	}
	/// <summary>
	/// ����֐�
	/// </summary>
	/// <param name="enemy">�G���N���X</param>
	/// <returns>����	true : ����I��		false : ���葱�s</returns>
	virtual bool Judgment(EnemyParameter* enemy) override;
};