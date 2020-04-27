#pragma once

#include "../Constant.h"
#include "../DownwellConstant.h"

class CharacterJump
{
public:
	CharacterJump() : bJump(false), bBulletJump_(false), nFrame_(0) {}
	~CharacterJump() {}
public:
	void JumpUpdate();
	void JumpState(VECTOR& vpos, VECTOR& vspeed, bool& bground);
	void BulletJumpState(VECTOR vpos, VECTOR& vspeed, bool& bground);
	bool GetJumpExist();
	void SetJumpExist(bool bjump);
	bool GetBulletJumpExist();
	void SetBulletJumpExist(bool bjump);
private:
	int nFrame_;
	bool bJump;
	bool bBulletJump_;
};