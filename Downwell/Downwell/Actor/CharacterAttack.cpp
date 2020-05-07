#include "CharacterAttack.h"
#include "../Input/Input.h"
#include "../DownwellConstant.h"

void CharacterAttack::Attack(bool& bground, int& nstate, VECTOR& vpos, const bool& bJump)
{
	if (!bground)
	{
		if (nstate == 0 && bJump && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x000)
		{
			nstate = 1;
		}

 		if (nstate == 1 && bJump && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001 && nBullet_ > 0)
		{
			if (nAttackFrame_ % 2 == 0)
			{
				vpos.y += 20.0f;
				nBullet_--;
				cBullet_.Create(vpos);
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
