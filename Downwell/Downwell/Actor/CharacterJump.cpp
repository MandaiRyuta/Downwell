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

void CharacterJump::JumpState(VECTOR& vpos, VECTOR& vspeed, bool& bground)
{
	if (bground)
	{
		if (Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) && !bJump)
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

void CharacterJump::BulletJumpState(VECTOR vpos, VECTOR& vspeed, bool& bground)
{
	if (Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) && !bBulletJump_)
	{
		vspeed.y = -2.0f;
		vpos.y += vspeed.y;
		bBulletJump_ = true;
	}
	if (vspeed.y < 180 && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) != 0x001 && bBulletJump_)
	{
		vspeed.y *= 0.9f;
	}

}

bool CharacterJump::GetJumpExist()
{
	return bJump;
}

void CharacterJump::SetJumpExist(bool bjump)
{
	bJump = bjump;
}

bool CharacterJump::GetBulletJumpExist()
{
	return bBulletJump_;
}

void CharacterJump::SetBulletJumpExist(bool bbulletjump)
{
	bBulletJump_ = bbulletjump;
}


