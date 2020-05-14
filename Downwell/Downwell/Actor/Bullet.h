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
	const float& Scale();
	const static VECTOR& GetPosition(int nbulletnumber);
	static void ResetSetPosition(int nbulletnumber);
	const static bool& GetBulletExist(int num);
private:
	int nBulletType_;
	int nBulletTexture_;
	static VECTOR vPosition_[10];
	float fScale_;
	static bool bBullet_[10];
	static float fBulletspeed_[10];
	int nBulletFrame_;
	int nBulletNumber;
};