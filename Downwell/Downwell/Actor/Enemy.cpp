#include "Enemy.h"
#include "EnemyBird.h"
#include "EnemySeaUrchin.h"
#include "EnemyTurtle.h"
#include "../Behaviour/LifeJudgment.h"
/// <summary>
/// �R���X�g���N�^�[
/// </summary>
/// <param name="nEnemyNumber">�`�悳���G�ԍ�</param>
/// <param name="nType">�G�̎��</param>
/// <param name="nHp">�G��HP</param>
/// <param name="vPosition">�G������������W</param>
Enemy::Enemy(int nEnemyNumber, int nType, int nHp, VECTOR vPosition)
{
	//�P�̂�
	cFactory_ = new CreateFactory();
	//������
	cParameter_ = cFactory_->Create(nEnemyNumber, nType, nHp, vPosition);
}
/// <summary>
/// �f�X�g���N�^�[
/// </summary>
Enemy::~Enemy()
{
	if (cFactory_ != nullptr)
	{
		delete cFactory_;
	}
	if (cParameter_ != nullptr)
	{
		delete cParameter_;
	}
}
/// <summary>
/// �X�V�֐�
/// </summary>
void Enemy::Update()
{
	bool bdead = AliveChecker::SetDead(*cParameter_);

	if (!bdead)
	{
		cParameter_->Update();
	}
}
/// <summary>
/// �`��֐�
/// </summary>
void Enemy::Draw()
{
	cParameter_->Draw();
}
