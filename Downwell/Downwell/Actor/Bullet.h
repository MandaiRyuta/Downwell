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
	const VECTOR& GetPosition(int nbulletnumber);
private:
	void CreatePolygon();
private:
	int nBulletTexture_;
	VECTOR vPosition_[10];
	VECTOR vScale_;
	int nSpeed_;
	int nRotate_;
	bool bBullet_;
	int nBulletFrame_;
	int nBulletNumber;
};