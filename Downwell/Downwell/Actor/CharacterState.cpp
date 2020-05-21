#include "CharacterState.h"
#include "../Input/Input.h"
#include "../DownwellConstant.h"
#include "../Collision/MapHitCheck.h"
#include "../Camera/Camera.h"
#include <random>

int CharacterState::nBullet_ = 10;
/// <summary>
/// �U���J�n����֐�
/// </summary>
/// <param name="vpos">���W</param>
/// <param name="bJump">�W�����v�t���O</param>
/// <param name="bAttackjump">�U���W�����v�t���O</param>
/// <param name="nstate">�s���X�e�[�g</param>
/// <param name="fgravity">�d��</param>
/// <param name="bshake">�U���t���O</param>
void CharacterState::Attack(VECTOR& vpos, bool& bJump, int& nstate, float& fgravity, bool& bshake, bool& bAttackJump)
{
	Camera::GetInstance().SetShake(false);

	bshake = false;
	
	if (MapHitChecker::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 1 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 1 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitChecker::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 2 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 2 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitChecker::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 3 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 3 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitChecker::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 4 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 4 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitChecker::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 5 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 5 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 && bJump)
	{
		nstate = 0;
		bJump = false;
		bAttackJump = false;
		nAttackFrame_ = 0;
		nBullet_ = 10;
	}
	
	if (nstate == 1 && bJump && !bAttackJump && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001)
	{
		if (MapHitChecker::GetChipParam(VGet(vpos.x, vpos.y - 9.0f, 0.0f)) == 1 ||
			MapHitChecker::GetChipParam(VGet(vpos.x, vpos.y - 9.0f, 0.0f)) == 2 ||
			MapHitChecker::GetChipParam(VGet(vpos.x, vpos.y - 9.0f, 0.0f)) == 3 ||
			MapHitChecker::GetChipParam(VGet(vpos.x, vpos.y - 9.0f, 0.0f)) == 4 ||
			MapHitChecker::GetChipParam(VGet(vpos.x, vpos.y - 9.0f, 0.0f)) == 5)
		{
			bAttackJump = false;
			nAttackFrame_ = 0;
			nBullet_ = 10;
		}
		if (nBullet_ <= 0)
		{
			nAttackFrame_ = 0;
			nstate = 2;
		}
		if (nAttackFrame_ > 3)
		{
			if (nAttackFrame_ % nGravityFrame == 0)
			{
				fgravity += 0.25f;
				cBullet_.Create(vpos);
				nBullet_--;
				Camera::GetInstance().SetShake(true);
			}
		}

		nAttackFrame_++;
	}
 
	if (nstate == 0 && !bJump && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x001)
	{
		nstate = 1;
		fgravity += fJump_v0;
		bJump = true;
	}
}
/// <summary>
/// �X�V�֐�
/// </summary>
void CharacterState::Update()
{
	cBullet_.Update();
}
/// <summary>
/// �`��֐�
/// </summary>
void CharacterState::Draw()
{
	cBullet_.Draw();
}
/// <summary>
/// �U���t���O�ݒ�֐�
/// </summary>
/// <param name="battack">�U���t���O�@true : �U������@false : �U�����Ȃ� </param>
void CharacterState::SetAttackExist(bool battack)
{
	bAttack_ = battack;
}
/// <summary>
/// �e��[�֐�
/// </summary>
/// <param name="nbullet">��[����e�̗�</param>
void CharacterState::SetBullet(int nbullet)
{
	nBullet_ = nbullet;
}
/// <summary>
/// �e�̎c�e�����󂯎��֐�
/// </summary>
/// <returns>�e�̎c�e��</returns>
const int& CharacterState::GetBullet()
{
	return nBullet_;
}
