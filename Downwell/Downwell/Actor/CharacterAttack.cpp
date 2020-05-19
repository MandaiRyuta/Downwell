#include "CharacterAttack.h"
#include "../Input/Input.h"
#include "../DownwellConstant.h"
#include "../Collision/MapHitCheck.h"
#include "../Camera/Camera.h"
#include <random>

int CharacterAttack::nBullet_ = nBulletMaxCount;	//�e�̐�
/// <summary>
/// �U���J�n����֐�
/// </summary>
/// <param name="vpos">���W</param>
/// <param name="bJump">�W�����v�t���O</param>
/// <param name="bAttackjump">�U���W�����v�t���O</param>
/// <param name="nstate">�s���X�e�[�g</param>
/// <param name="fgravity">�d��</param>
/// <param name="bshake">�U���t���O</param>
void CharacterAttack::Attack(VECTOR& vpos, const bool& bJump, const bool& bAttackjump, int& nstate, float& fgravity, bool& bshake)
{
	Camera::GetInstance().SetShake(false);
	bshake = false;
	if (nBullet_ <= nBulletNonCount)
	{
		nSideAttackFrame_ = nInitSideAttackFrame;
	}

	if (Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == True)
	{
		nSideAttackFrame_++;
	}

	if (nstate == nCharacterJumping && !bJump && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == False)
	{
		nstate = nCharacterAttackJumping;
	}

 	if (nstate == nCharacterAttackJumping && !bJump && bAttackjump && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001 && nBullet_ > nBulletNonCount)
	{
       	if (MapHitChecker::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 8.0f), 0.0f)) == 0 || MapHitChecker::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 8.0f), 0.0f)) == 0)
		{
			if (nAttackFrame_ % nGravityFrame == 0)
			{
				fgravity += fAddGravity;
				nBullet_--;
				cBullet_.Create(vpos);
				Camera::GetInstance().SetShake(true);
			}
			if (nAttackFrame_ % nShakeFrame == 0)
			{
				bshake = true;
			}
			nAttackFrame_++;
		}
	}
	
	if(nSideAttackFrame_ > 10 && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001 && nBullet_ > 0)
	{
		if (MapHitChecker::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 8.0f), 0.0f)) == 0 || MapHitChecker::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 8.0f), 0.0f)) == 0)
		{
			if (nAttackFrame_ % nGravityFrame == 0)
			{
				fgravity += fAddGravity;
				nBullet_--;
				cBullet_.Create(vpos);
				Camera::GetInstance().SetShake(true);
			}
			if (nAttackFrame_ % nShakeFrame == 0)
			{
				bshake = true;
			}
			nAttackFrame_++;
		}
	}

	cBullet_.Update();
}
/// <summary>
/// �`��֐�
/// </summary>
void CharacterAttack::Draw()
{
	cBullet_.Draw();
}
/// <summary>
/// �U���t���O�ݒ�֐�
/// </summary>
/// <param name="battack">�U���t���O�@true : �U������@false : �U�����Ȃ� </param>
void CharacterAttack::SetAttackExist(bool battack)
{
	bAttack_ = battack;
}
/// <summary>
/// �e��[�֐�
/// </summary>
/// <param name="nbullet">��[����e�̗�</param>
void CharacterAttack::SetBullet(int nbullet)
{
	nBullet_ = nbullet;
}
/// <summary>
/// �e�̎c�e�����󂯎��֐�
/// </summary>
/// <returns>�e�̎c�e��</returns>
const int& CharacterAttack::GetBullet()
{
	return nBullet_;
}
