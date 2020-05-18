#include "Enemy.h"
#include "EnemyBird.h"
#include "EnemySeaUrchin.h"
#include "EnemyTurtle.h"
/// <summary>
/// �R���X�g���N�^�[
/// </summary>
/// <param name="enemynumber">�`�悳���G�ԍ�</param>
/// <param name="ntype">�G�̎��</param>
/// <param name="nhp">�G��HP</param>
/// <param name="nspeed">�G�̈ړ����x</param>
/// <param name="vposition">�G������������W</param>
Enemy::Enemy(int enemynumber, int ntype, int nhp, int nspeed, VECTOR vposition)
{
	//�P�̂�
	cFactory_ = new CreateFactory();
	//������
	cProduct_ = cFactory_->Create(enemynumber, ntype, nhp, nspeed, vposition);
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
	if (cProduct_ != nullptr)
	{
		delete cProduct_;
	}
}
/// <summary>
/// �X�V�֐�
/// </summary>
void Enemy::Update()
{
	cProduct_->Update();
}
/// <summary>
/// �`��֐�
/// </summary>
void Enemy::Draw()
{
	cProduct_->Draw();
}
