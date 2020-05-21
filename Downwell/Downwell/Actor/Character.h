#pragma once
#include "Actor.h"
#include "../Constant.h"
#include "CharacterMove.h"
#include "CharacterState.h"

class Character : public Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	/// <param name="nscenenumber">�V�[���ԍ�</param>
	Character(int nscenenumber);
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~Character();
public:
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`��֐�
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// ���W�擾�֐�
	/// </summary>
	/// <returns>�v���C���[���W</returns>
	static const VECTOR& GetPos();
	/// <summary>
	/// �G�̐^��ɑ��������n�����Ƃ��̏Փˊ֐�
	/// </summary>
	/// <param name="bhit"> true : �Փ�   false : ��Փ�</param>
	static void SetHitEnemy(bool bhit);
	/// <summary>
	/// �G�ƏՓˎ��̃_���[�W�֐�
	/// </summary>
	/// <param name="bdamage"> true : �_���[�W���󂯂�  false : �_���[�W���󂯂Ȃ�</param>
	static void SetHitDamage(bool bdamage);
	/// <summary>
	/// ���̃_���[�W����擾�֐�
	/// </summary>
	/// <returns>�����̃_���[�W����t���O</returns>
	static const bool GetLeftDamageExist();
	/// <summary>
	/// �E�̃_���[�W����擾�֐�
	/// </summary>
	/// <returns>�E���̃_���[�W����t���O</returns>
	static const bool GetRightDamageExist();
	/// <summary>
	/// �v���C���[�̑��ʂƓG�̏Փ˔���
	/// </summary>
	/// <param name="bdamage">true : �Փ�  false : ��Փ�</param>
	static void SetHitLeftDamage(bool bdamage);
	/// <summary>
	/// �v���C���[�̑��ʂƓG�̏Փ˔���
	/// </summary>
	/// <param name="bdamage">true : �Փˁ@false : ��Փ�</param>
	static void SetHitRightDamage(bool bdamage);
	/// <summary>
	/// �v���C���[�̎c��HP�擾�֐�
	/// </summary>
	/// <returns>�c��HP</returns>
	static const int& GetCharacterLife();

	/// <summary>
	/// �W�����v�t���O�擾�֐�
	/// </summary>
	/// <returns>�W�����v�t���O true : �W�����v���Ă���		false : �W�����v���Ă��Ȃ�</returns>
	static const bool& GetJumpExist();
private:
	float fJumpPower_;	//�W�����v��
	int nNowScene_;	//���݂̕\���V�[���ԍ�
	static int nLife_;	//�v���C���[HP
	int nCharacterActionState_;	//�L�����N�^�[�s���X�e�[�g
	int nTexhandle_;	//�e�N�X�`���[�n���h��
	static VECTOR vPosition_;	//�v���C���[���W
	float fSize_;	//�摜�̑傫��
	CharacterState CharacterState_;	//�U���X�e�[�g�N���X
	CharacterMove MoveState_;	//�ړ��X�e�[�g�N���X
	VECTOR vSpeed_;	//�ړ���
	VECTOR vOldPosition_;	//1�t���[���O�̍��W
	float fGravity_;	//�d��
	float fPlayershake_;	//�U����
	bool bPlayershake_;	//�U���t���O
	static bool bHitEnemy_;	//�v���C���[�̑������G�̐^�㒅�n�����ۂ̃t���O
	static bool bLeftDamage_;	//�v���C���[�̍����ʂ��G�ɏՓ˂����ۂ̃t���O
	static bool bRightDamage_;	//�v���C���[�̉E���ʂ��G�ɏՓ˂����ۂ̃t���O
	static bool bDamage_;	//�_���[�W�t���O
	int nHitCooltime_;	//�Փ˂��Ă���̃v���C���[���G���ԗp�̕ϐ�
	bool bInvincible_;	//�v���C���[�̖��G��ԃt���O
	static bool bJump_;	//�W�����v�t���O
	bool bAttackJump_;	//�U�����̃W�����v�t���O
};