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
	/// <param name="nEnemyNumber">�`�悳���G�ԍ�</param>
	/// <param name="nType">�G�̎��</param>
	/// <param name="nHp">�G��HP</param>
	/// <param name="vPosition">�G������������W</param>
	Enemy(int nEnemyNumber, int nType, int nHp, VECTOR vPosition);
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~Enemy();
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
	EnemyParameter* cParameter_;	//�G�̃p�����[�^�[�N���X
};