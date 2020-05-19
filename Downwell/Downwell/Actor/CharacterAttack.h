#pragma once
#include "../Constant.h"
#include "Bullet.h"
#include "../DownwellConstant.h"

class CharacterAttack
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	CharacterAttack() : 
		bAttack_(bInitAttack), nAttackFrame_(nInitAttackFrame), nSideAttackFrame_(nInitSideAttackFrame)
	{
		nBullet_ = nBulletMaxCount;
	}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~CharacterAttack() {}
public:
	/// <summary>
	/// �U���J�n����֐�
	/// </summary>
	/// <param name="vpos">���W</param>
	/// <param name="bJump">�W�����v�t���O</param>
	/// <param name="bAttackjump">�U���W�����v�t���O</param>
	/// <param name="nstate">�s���X�e�[�g</param>
	/// <param name="fgravity">�d��</param>
	/// <param name="bshake">�U���t���O</param>
	void Attack(VECTOR& vpos, const bool& bJump, const bool& bAttackjump, int& nstate, float& fgravity, bool& bshake);
	/// <summary>
	/// �`��֐�
	/// </summary>
	void Draw();
	/// <summary>
	/// �U���t���O�ݒ�֐�
	/// </summary>
	/// <param name="battack">�U���t���O�@true : �U������@false : �U�����Ȃ� </param>
	void SetAttackExist(bool battack);
	/// <summary>
	/// �e��[�֐�
	/// </summary>
	/// <param name="nbullet">��[����e�̗�</param>
	static void SetBullet(int nbullet);
	/// <summary>
	/// �e�̎c�e�����󂯎��֐�
	/// </summary>
	/// <returns>�e�̎c�e��</returns>
	static const int& GetBullet();
private:
	bool bAttack_; //�U���t���O
	int nAttackFrame_;	//�U�����̃t���[��
	int nSideAttackFrame_;	//���n��Ԃō��E�̒[����^���ɍU������ۂɃL�[���͂��󂯎��悤�ɂ���t���[��
	static int nBullet_; //�e�̐�
	Bullet cBullet_;	//�e�N���X
};