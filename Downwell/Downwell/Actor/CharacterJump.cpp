#include "CharacterJump.h"
#include "../Input/Input.h"

void CharacterJump::JumpUpdate()
{
	if (nFrame_ > 30)
	{
		bBulletJump_ = false;
		nFrame_ = 0;
	}
	nFrame_++;
}

void CharacterJump::JumpState(VECTOR& vpos, VECTOR& vspeed, bool& bground, int& nstate)
{
	if (bground)
	{
		if (Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x001 && !bJump)
		{
			vspeed.y = fJump_v0;
			vpos.y += vspeed.y;
			bJump = true;
		}
	}
	else
	{
		vspeed.y += fGravity;
		vpos.y += vspeed.y;

		if (vspeed.y < 180 && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) != 0x001 && bJump)
		{
			vspeed.y *= 0.9f;
		}
	}
}

const bool& CharacterJump::GetJumpExist()
{
	return bJump;
}

void CharacterJump::SetJumpExist(bool bjump)
{
	bJump = bjump;
}

const bool& CharacterJump::GetBulletJumpExist()
{
	return bBulletJump_;
}

void CharacterJump::SetBulletJumpExist(bool bbulletjump)
{
	bBulletJump_ = bbulletjump;
}



