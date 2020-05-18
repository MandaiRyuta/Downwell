#include "CharacterJump.h"
#include "../Input/Input.h"
#include "../Collision/MapHitCheck.h"
#include "CharacterAttack.h"

bool CharacterJump::bJump = false;	//�W�����v�t���O
/// <summary>
/// �X�V�֐�
/// </summary>
void CharacterJump::JumpUpdate()
{
	if (CharacterAttack::GetBullet() <= 0)
	{
		bBulletJump_ = false;
	}
}
/// <summary>
/// �W�����v�X�e�[�g�֐�
/// </summary>
/// <param name="vpos">�v���C���[���W</param>
/// <param name="vspeed">�v���C���[�ړ���</param>
/// <param name="fgravity">�d��</param>
/// <param name="nstate">�s���X�e�[�g</param>
void CharacterJump::JumpState(VECTOR& vpos, VECTOR& vspeed, float& fgravity, int& nstate)
{
	if (MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 1 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 1 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 2 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 2 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 3 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 3 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 4 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 4 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 5 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 5 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000)
	{
		bJump = true;
		CharacterAttack::SetBullet(10);
		bBulletJump_ = false;
	}
	else if(MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 0 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 0 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000)
	{
		bJump = false;
	}

	if (bJump && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x001)
	{
		nstate = 0;
		bBulletJump_ = true;
		fgravity = fJump_v0;
		bJump = false;
	}
}
/// <summary>
/// �W�����v�t���O�擾�֐�
/// </summary>
/// <returns>�W�����v�t���O true : �W�����v���Ă���		false : �W�����v���Ă��Ȃ�</returns>
const bool& CharacterJump::GetJumpExist()
{
	return bJump;
}
/// <summary>
/// �W�����v�t���O�ݒ�֐�
/// </summary>
/// <param name="bjump">�W�����v�t���O�@true : �W�����v����		false : �W�����v���Ȃ�</param>
void CharacterJump::SetJumpExist(bool bjump)
{
	bJump = bjump;
}
/// <summary>
/// �U���W�����v�t���O�擾�֐�
/// </summary>
/// <returns>�U���W�����v�t���O�擾�@true : �U���W�����v���Ă���	false : �U���W�����v���Ă��Ȃ�</returns>
const bool& CharacterJump::GetBulletJumpExist()
{
	return bBulletJump_;
}
/// <summary>
/// �U���W�����v�t���O�ݒ�֐�
/// </summary>
/// <param name="bjump"> true : �U���W�����v����	false : �U���W�����v���Ȃ�</param>
void CharacterJump::SetBulletJumpExist(bool bbulletjump)
{
	bBulletJump_ = bbulletjump;
}



