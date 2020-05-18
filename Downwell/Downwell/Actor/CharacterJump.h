#pragma once

#include "../Constant.h"
#include "../DownwellConstant.h"

class CharacterJump
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	CharacterJump() : bBulletJump_(false) {}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~CharacterJump() {}
public:
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	void JumpUpdate();
	/// <summary>
	/// �W�����v�X�e�[�g�֐�
	/// </summary>
	/// <param name="vpos">�v���C���[���W</param>
	/// <param name="vspeed">�v���C���[�ړ���</param>
	/// <param name="fgravity">�d��</param>
	/// <param name="nstate">�s���X�e�[�g</param>
	void JumpState(VECTOR& vpos, VECTOR& vspeed, float& fgravity, int& nstate);
	/// <summary>
	/// �W�����v�t���O�擾�֐�
	/// </summary>
	/// <returns>�W�����v�t���O true : �W�����v���Ă���		false : �W�����v���Ă��Ȃ�</returns>
	static const bool& GetJumpExist();
	/// <summary>
	/// �W�����v�t���O�ݒ�֐�
	/// </summary>
	/// <param name="bjump">�W�����v�t���O�@true : �W�����v����		false : �W�����v���Ȃ�</param>
	void SetJumpExist(bool bjump);
	/// <summary>
	/// �U���W�����v�t���O�擾�֐�
	/// </summary>
	/// <returns>�U���W�����v�t���O�擾�@true : �U���W�����v���Ă���	false : �U���W�����v���Ă��Ȃ�</returns>
	const bool& GetBulletJumpExist();
	/// <summary>
	/// �U���W�����v�t���O�ݒ�֐�
	/// </summary>
	/// <param name="bjump"> true : �U���W�����v����	false : �U���W�����v���Ȃ�</param>
	void SetBulletJumpExist(bool bjump);
private:
	static bool bJump;	//�W�����v�t���O
	bool bBulletJump_;	//�U���W�����v�t���O
};