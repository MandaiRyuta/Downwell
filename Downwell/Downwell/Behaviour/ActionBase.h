#pragma once

class EnemyParameter;	//�G�p�����[�^�[�N���X

class ActionBase
{
public:
	/// <summary>
	/// �X�e�[�g
	/// </summary>
	enum class STATE
	{
		MOVE,
		FAILED,
		COMPLETE,
	};
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	/// <param name="enemy">�G���</param>
	/// <returns>�X�e�[�g���</returns>
	virtual STATE Run(EnemyParameter* enemy) = 0;
};