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
/// <param name="vPosition">���W</param>
/// <param name="bJump">�W�����v�t���O</param>
/// <param name="bAttackjump">�U���W�����v�t���O</param>
/// <param name="nState">�s���X�e�[�g</param>
/// <param name="fGravity">�d��</param>
/// <param name="bShake">�U���t���O</param>
void CharacterState::Attack(VECTOR& vPosition, bool& bJump, int& nState, float& fGravity, bool& bShake, bool& bAttackJump)
{
	Camera::GetInstance().SetShake(false);

	bShake = false;
	
	if (MapHitChecker::GetChipParam(VGet(vPosition.x - 16 * 0.5f, vPosition.y - (16 * 0.5f + 1.0f), 0.0f)) == 1 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vPosition.x + 16 * 0.5f, vPosition.y - (16 * 0.5f + 1.0f), 0.0f)) == 1 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitChecker::GetChipParam(VGet(vPosition.x - 16 * 0.5f, vPosition.y - (16 * 0.5f + 1.0f), 0.0f)) == 2 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vPosition.x + 16 * 0.5f, vPosition.y - (16 * 0.5f + 1.0f), 0.0f)) == 2 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitChecker::GetChipParam(VGet(vPosition.x - 16 * 0.5f, vPosition.y - (16 * 0.5f + 1.0f), 0.0f)) == 3 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vPosition.x + 16 * 0.5f, vPosition.y - (16 * 0.5f + 1.0f), 0.0f)) == 3 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitChecker::GetChipParam(VGet(vPosition.x - 16 * 0.5f, vPosition.y - (16 * 0.5f + 1.0f), 0.0f)) == 4 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vPosition.x + 16 * 0.5f, vPosition.y - (16 * 0.5f + 1.0f), 0.0f)) == 4 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitChecker::GetChipParam(VGet(vPosition.x - 16 * 0.5f, vPosition.y - (16 * 0.5f + 1.0f), 0.0f)) == 5 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vPosition.x + 16 * 0.5f, vPosition.y - (16 * 0.5f + 1.0f), 0.0f)) == 5 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 && bJump)
	{
		nState = 0;
		bJump = false;
		bAttackJump = false;
		nAttackFrame_ = 0;
		nBullet_ = 10;
	}
	
	if (nState == 1 && bJump && !bAttackJump && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001)
	{
		if (MapHitChecker::GetChipParam(VGet(vPosition.x, vPosition.y - 9.0f, 0.0f)) == 1 ||
			MapHitChecker::GetChipParam(VGet(vPosition.x, vPosition.y - 9.0f, 0.0f)) == 2 ||
			MapHitChecker::GetChipParam(VGet(vPosition.x, vPosition.y - 9.0f, 0.0f)) == 3 ||
			MapHitChecker::GetChipParam(VGet(vPosition.x, vPosition.y - 9.0f, 0.0f)) == 4 ||
			MapHitChecker::GetChipParam(VGet(vPosition.x, vPosition.y - 9.0f, 0.0f)) == 5)
		{
			bAttackJump = false;
			nAttackFrame_ = 0;
			nBullet_ = 10;
		}
		if (nBullet_ <= 0)
		{
			nAttackFrame_ = 0;
			nState = 2;
		}
		if (nAttackFrame_ > 3)
		{
			if (nAttackFrame_ % nGravityFrame == 0)
			{
				fGravity += 0.25f;
				cBullet_.Create(vPosition);
				nBullet_--;
				Camera::GetInstance().SetShake(true);
			}
		}

		nAttackFrame_++;
	}
 
	if (nState == 0 && !bJump && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x001)
	{
		nState = 1;
		fGravity += fJump_v0;
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
/// <param name="bAttack">�U���t���O�@true : �U������@false : �U�����Ȃ� </param>
void CharacterState::SetAttackExist(bool bAttack)
{
	bAttack_ = bAttack;
}
/// <summary>
/// �e��[�֐�
/// </summary>
/// <param name="nBullet">��[����e�̗�</param>
void CharacterState::SetBullet(int nBullet)
{
	nBullet_ = nBullet;
}
/// <summary>
/// �e�̎c�e�����󂯎��֐�
/// </summary>
/// <returns>�e�̎c�e��</returns>
const int& CharacterState::GetBullet()
{
	return nBullet_;
}
