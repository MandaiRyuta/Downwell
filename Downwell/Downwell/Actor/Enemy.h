#pragma once
#include "Actor.h"
#include "Factory.h"
#include "EnemyParameter.h"

class Enemy : public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	/// <param name="enemynumber">�`�悳���G�ԍ�</param>
	/// <param name="ntype">�G�̎��</param>
	/// <param name="nhp">�G��HP</param>
	/// <param name="nspeed">�G�̈ړ����x</param>
	/// <param name="vposition">�G������������W</param>
	Enemy(int enemynumber, int ntype, int nhp, int nspeed, VECTOR vposition);
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~Enemy();
public:
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	virtual void Update() override; 
	/// <summary>
	/// �`��֐�
	/// </summary>
	virtual void Draw() override;
private:
	Factory* cFactory_;	//�t�@�N�g���[�N���X
	EnemyParameter* cProduct_;	//�G�̃p�����[�^�[�N���X
};