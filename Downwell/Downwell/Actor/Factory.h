#pragma once
#include <string>
#include "../Constant.h"
class EnemyParameter;	//�G�p�����[�^�[�N���X

class Factory
{
public:
	/// <summary>
	/// �쐬�N���X
	/// </summary>
	/// <param name="nEnemyNumber">�G�̕`��ԍ�</param>
	/// <param name="nType">�G�̎��</param>
	/// <param name="nHp">�G��HP</param>
	/// <param name="vPosition">�G�̏o�����W</param>
	/// <returns></returns>
	EnemyParameter* Create(int nEnemyNumber, int nType, int nHp, VECTOR vPosition)
	{
		return CreateInstance(nEnemyNumber, nType, nHp, vPosition);
	}
private:
	/// <summary>
	/// �G�����֐�
	/// </summary>
	/// <param name="nEnemyNumber">�G�̕`��ԍ�</param>
	/// <param name="nType">�G�̎��</param>
	/// <param name="nHp">�G��HP</param>
	/// <param name="vPosition">�G�̏o�����W</param>
	/// <returns></returns>
	virtual EnemyParameter* CreateInstance(int nEnemyNumber, int nType, int nHp, VECTOR vPosition) = 0;
};

class CreateFactory : public Factory
{
private:
	/// <summary>
	/// �G�����֐�
	/// </summary>
	/// <param name="nEnemyNumber">�G�̕`��ԍ�</param>
	/// <param name="nType">�G�̎��</param>
	/// <param name="nHp">�G��HP</param>
	/// <param name="vPosition">�G�̏o�����W</param>
	/// <returns></returns>
	EnemyParameter* CreateInstance(int nEnemyNumber, int nType, int nHp, VECTOR vPosition);
};