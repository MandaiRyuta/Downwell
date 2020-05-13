#pragma once

#include "../Constant.h"
#include "../DownwellConstant.h"

class CharacterJump
{
public:
	CharacterJump() : bBulletJump_(false), nFrame_(0) {}
	~CharacterJump() {}
public:
	void JumpUpdate();
	void JumpState(VECTOR& vpos, VECTOR& vspeed, float& fgravity, int& nstate);
	static const bool& GetJumpExist();
	void SetJumpExist(bool bjump);
	const bool& GetBulletJumpExist();
	void SetBulletJumpExist(bool bjump);
private:
	int nFrame_;
	static bool bJump;
	bool bBulletJump_;
};