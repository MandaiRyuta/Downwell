#pragma once

class EnemyParameter;	//�G�p�����[�^�N���X

class JudgmentBase
{
public:
	/// <summary>
	/// ����֐�
	/// </summary>
	/// <param name="enemy">�G���N���X</param>
	/// <returns>����	true : ����I��		false : ���葱�s</returns>
	virtual bool Judgment(EnemyParameter* enemy) = 0;
};