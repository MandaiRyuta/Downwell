#pragma once
#include "../Constant.h"

class Bullet
{
public:
	Bullet();
	~Bullet();
public:
	void Update();
	void Draw();
	void Create(const VECTOR& vpos);
	const VECTOR& Scale();
	const static VECTOR& GetPosition(int nbulletnumber);
	static void ResetSetPosition(int nbulletnumber);
private:
	int nBulletType_;
	int nBulletTexture_;
	static VECTOR vPosition_[10];
	VECTOR vScale_;
	int nSpeed_;
	int nRotate_;
	static bool bBullet_[10];
	static float fBulletspeed_[10];
	int nBulletFrame_;
	int nBulletNumber;
};