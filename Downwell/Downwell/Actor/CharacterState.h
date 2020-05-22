#pragma once
#include "../Constant.h"
#include "Bullet.h"
#include "../DownwellConstant.h"

class CharacterState
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	CharacterState() :
		bAttack_(bInitAttack), nAttackFrame_(nInitAttackFrame), nSideAttackFrame_(nInitSideAttackFrame), bAttackJump_(false) 
	{
		nBullet_ = nBulletMaxCount;
	}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~CharacterState() {}
	/// <summary>
	/// �U���J�n����֐�
	/// </summary>
	/// <param name="vPosition">���W</param>
	/// <param name="bJump">�W�����v�t���O</param>
	/// <param name="bAttackjump">�U���W�����v�t���O</param>
	/// <param name="nState">�s���X�e�[�g</param>
	/// <param name="fGravity">�d��</param>
	/// <param name="bShake">�U���t���O</param>
	void Attack(VECTOR& vPosition, bool& bJump, int& nState, float& fGravity, bool& bShake, bool& bAttackJump);
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	void Update();
	/// <summary>
	/// �`��֐�
	/// </summary>
	void Draw();
	/// <summary>
	/// �U���t���O�ݒ�֐�
	/// </summary>
	/// <param name="bAttack">�U���t���O�@true : �U������@false : �U�����Ȃ� </param>
	void SetAttackExist(bool bAttack);
	/// <summary>
	/// �e��[�֐�
	/// </summary>
	/// <param name="nBullet">��[����e�̗�</param>
	static void SetBullet(int nBullet);
	/// <summary>
	/// �e�̎c�e�����󂯎��֐�
	/// </summary>
	/// <returns>�e�̎c�e��</returns>
	static const int& GetBullet();
private:
	bool bAttack_; //�U���t���O
	int nAttackFrame_;	//�U�����̃t���[��
	int nSideAttackFrame_;	//���n��Ԃō��E�̒[����^���ɍU������ۂɃL�[���͂��󂯎��悤�ɂ���t���[��
	bool bAttackJump_;
	static int nBullet_; //�e�̐�
	Bullet cBullet_;	//�e�N���X
};