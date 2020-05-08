#pragma once
#include "../Constant.h"
#include "Bullet.h"

class CharacterAttack
{
public:
	CharacterAttack() : 
		bAttack_(false), nAttackFrame_(0), fSpeed_(0.0f)
	{
		nBullet_ = 10;
	}
	~CharacterAttack() {}
public:
	void Attack(VECTOR& vpos, const bool& bJump, const bool& bAttackjump, int& nstate, float& fgravity, bool& bshake);
	void Draw();
	void SetAttackExist(bool battack);
	static void SetBullet(int nbullet);
	void SetAttackFrame(int nframe);
	static const int& GetBullet();
private:
	bool bAttack_;
	int nAttackFrame_;
	float fSpeed_;
	static int nBullet_;
	Bullet cBullet_;
};