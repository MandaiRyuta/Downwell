#pragma once
#include "../Constant.h"
#include "Bullet.h"

class CharacterAttack
{
public:
	CharacterAttack() : 
		bAttack_(false), nAttackFrame_(0), fSpeed_(0.0f), nBullet_(5){}
	~CharacterAttack() {}
public:
	void Attack(bool& bground, int& nstate,VECTOR& vpos, const bool& bJump);
	void Draw();
	void SetAttackExist(bool battack);
	void SetBullet(int nbullet);
	void SetAttackFrame(int nframe);
private:
	bool bAttack_;
	int nBulletTexture_;
	int nAttackFrame_;
	float fSpeed_;
	int nBullet_;
	Bullet cBullet_;
};