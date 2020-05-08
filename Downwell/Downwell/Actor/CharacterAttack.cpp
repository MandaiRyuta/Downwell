#include "CharacterAttack.h"
#include "../Input/Input.h"
#include "../DownwellConstant.h"
#include "../Collision/MapHitCheck.h"
#include "../Camera/Camera.h"
#include <random>

int CharacterAttack::nBullet_ = 0;

void CharacterAttack::Attack(VECTOR& vpos, const bool& bJump, const bool& bAttackjump, int& nstate, float& fgravity, bool& bshake)
{
	Camera::GetInstance().SetShake(false);
	bshake = false;
	if (nBullet_ <= 0)
	{
		nSideAttackFrame_ = 0;
	}

	if (Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001)
	{
		nSideAttackFrame_++;
	}

	if (nstate == 0 && !bJump && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x000)
	{
		nstate = 1;
	}

 	if (nstate == 1 && !bJump && bAttackjump && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001 && nBullet_ > 0)
	{
       	if (MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 8.0f), 0.0f)) == 0 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 8.0f), 0.0f)) == 0)
		{
			if (nAttackFrame_ % 5 == 0)
			{
				fgravity += 0.4f;
				nBullet_--;
				cBullet_.Create(vpos);
				Camera::GetInstance().SetShake(true);
			}
			if (nAttackFrame_ % 2 == 0)
			{
				bshake = true;
			}
			nAttackFrame_++;
		}
	}
	
	if(nSideAttackFrame_ > 10 && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001 && nBullet_ > 0)
	{
		if (MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 8.0f), 0.0f)) == 0 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 8.0f), 0.0f)) == 0)
		{
			if (nAttackFrame_ % 5 == 0)
			{
				fgravity += 0.4f;
				nBullet_--;
				cBullet_.Create(vpos);
				Camera::GetInstance().SetShake(true);
			}
			if (nAttackFrame_ % 2 == 0)
			{
				bshake = true;
			}
			nAttackFrame_++;
		}
	}

	cBullet_.Update();
}

void CharacterAttack::Draw()
{
	cBullet_.Draw();
}

void CharacterAttack::SetAttackExist(bool battack)
{
	bAttack_ = battack;
}

void CharacterAttack::SetBullet(int nbullet)
{
	nBullet_ = nbullet;
}

void CharacterAttack::SetAttackFrame(int nframe)
{
	nAttackFrame_ = nframe;
}

const int& CharacterAttack::GetBullet()
{
	return nBullet_;
}
