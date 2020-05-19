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
	/// <param name="enemynumber">�G�̕`��ԍ�</param>
	/// <param name="ntype">�G�̎��</param>
	/// <param name="nhp">�G��HP</param>
	/// <param name="nspeed">�G�̈ړ���</param>
	/// <param name="vposition">�G�̏o�����W</param>
	/// <returns></returns>
	EnemyParameter* Create(int enemynumber, int ntype, int nhp, VECTOR vposition) {
		return CreateInstance(enemynumber, ntype, nhp, vposition);
	}
private:
	/// <summary>
	/// �G�����֐�
	/// </summary>
	/// <param name="enemynumber">�G�̕`��ԍ�</param>
	/// <param name="ntype">�G�̎��</param>
	/// <param name="nhp">�G��HP</param>
	/// <param name="nspeed">�G�̈ړ���</param>
	/// <param name="vposition">�G�̏o�����W</param>
	/// <returns></returns>
	virtual EnemyParameter* CreateInstance(int enemynumber, int ntype, int nhp, VECTOR vposition) = 0;
};

class CreateFactory : public Factory
{
private:
	/// <summary>
	/// �G�����֐�
	/// </summary>
	/// <param name="enemynumber">�G�̕`��ԍ�</param>
	/// <param name="ntype">�G�̎��</param>
	/// <param name="nhp">�G��HP</param>
	/// <param name="nspeed">�G�̈ړ���</param>
	/// <param name="vposition">�G�̏o�����W</param>
	/// <returns></returns>
	EnemyParameter* CreateInstance(int enemynumber, int ntype, int nhp, VECTOR vposition);
};