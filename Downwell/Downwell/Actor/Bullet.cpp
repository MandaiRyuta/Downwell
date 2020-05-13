#include "Bullet.h"
#include "../Input/Input.h"
#include <math.h>
#include "../Collision/MapHitCheck.h"
#include "Stage.h"
#include "Character.h"
#include "../Resource/TextureData.h"

VECTOR Bullet::vPosition_[10] = {};
bool Bullet::bBullet_[10] = {};
float Bullet::fBulletspeed_[10] = {};

Bullet::Bullet() : nSpeed_(0),nRotate_(0)
{
	for (int i = 0; i < 10; i++)
	{
		bBullet_[i] = false;
	}
	vScale_.x = 12.0f;
	vScale_.y = 12.0f;

	nBulletFrame_ = 0;
	nBulletNumber = 0;

	nBulletTexture_ = TextureDataBase::TextureData::GetInstance().GetTextureData(TextureDataBase::TextureNumber::Bullet);
	nBulletType_ = 0;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	float dammy = 0.0f;

	
	float halfsize = vScale_.x * 0.5f;
	if (Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001)
	{
		bBullet_[nBulletNumber] = true;
	}

	if (bBullet_[nBulletNumber])
	{
		switch (nBulletType_)
		{
		case 0:
			for (int i = 0; i < 10; i++)
			{
				fBulletspeed_[i] = 17.5f;
				/*if (MapHitCheck::GetChipParam(VGet(vPosition_[i].x - 2.0f, vPosition_[i].y - 1.0f, 0.0f)) == 3 ||
					MapHitCheck::GetChipParam(VGet(vPosition_[i].x + 2.0f, vPosition_[i].y - 1.0f, 0.0f)) == 3)
				{
					int x = (int)(vPosition_[i].x + 12 * 0.5f) / BlockSize - (BlockSize / 2);
					int y = (int)(vPosition_[i].y + 12 * 0.5f) / -BlockSize;
					Stage::SetStageType(0, x, y);
					bBullet_[i] = false;
					bulletspeed[i] = 0.0f;
					vPosition_[i] = VGet(0.0f, 0.0f, 0.0f);
				}*/
				if (vPosition_[i].y < Character::GetPos().y + -250.0f)
				{
					bBullet_[i] = false;
					fBulletspeed_[i] = 0.0f;
					vPosition_[i] = VGet(0.0f, 0.0f, 0.0f);
				}
				if (MapHitCheck::GetChipParam(VGet(vPosition_[i].x - 12 * 0.5f, vPosition_[i].y - (12 * 0.5f + 1.0f), 0.0f)) == 1 ||
					MapHitCheck::GetChipParam(VGet(vPosition_[i].x + 12 * 0.5f, vPosition_[i].y - (12 * 0.5f + 1.0f), 0.0f)) == 1 ||
					MapHitCheck::GetChipParam(VGet(vPosition_[i].x - 12 * 0.5f, vPosition_[i].y - (12 * 0.5f + 1.0f), 0.0f)) == 2 ||
					MapHitCheck::GetChipParam(VGet(vPosition_[i].x + 12 * 0.5f, vPosition_[i].y - (12 * 0.5f + 1.0f), 0.0f)) == 2 ||
					MapHitCheck::GetChipParam(VGet(vPosition_[i].x - 12 * 0.5f, vPosition_[i].y - (12 * 0.5f + 1.0f), 0.0f)) == 4 ||
					MapHitCheck::GetChipParam(VGet(vPosition_[i].x + 12 * 0.5f, vPosition_[i].y - (12 * 0.5f + 1.0f), 0.0f)) == 4 ||
					MapHitCheck::GetChipParam(VGet(vPosition_[i].x - 12 * 0.5f, vPosition_[i].y - (12 * 0.5f + 1.0f), 0.0f)) == 5 ||
					MapHitCheck::GetChipParam(VGet(vPosition_[i].x + 12 * 0.5f, vPosition_[i].y - (12 * 0.5f + 1.0f), 0.0f)) == 5)
				{
					bBullet_[i] = false;
					fBulletspeed_[i] = 0.0f;
					vPosition_[i] = VGet(0.0f, 0.0f, 0.0f);
				}
				vPosition_[i].y -= fBulletspeed_[i];
			}
			break;
		}
	}
}

void Bullet::Draw()
{
	if (bBullet_[nBulletNumber])
	{
		for (int i = 0; i < 10; i++)
		{
			DrawBillboard3D(vPosition_[i], 0.5f, 0.5f, 12, 0, nBulletTexture_, false);
		}
	}
}

void Bullet::Create(const VECTOR& vpos)
{
	if (nBulletNumber >= 10)
	{
		nBulletNumber = 0;
	}

	vPosition_[nBulletNumber].x = vpos.x;
  	vPosition_[nBulletNumber].y = vpos.y;
	vPosition_[nBulletNumber].z = 0.0f;

	if (nBulletNumber < 10)
	{
		nBulletNumber++;
	}
}

const VECTOR& Bullet::Scale()
{
	return vScale_;
}

const VECTOR& Bullet::GetPosition(int nbulletnumber)
{
	return vPosition_[nbulletnumber];
}

void Bullet::ResetSetPosition(int nbulletnumber)
{
	bBullet_[nbulletnumber] = false;
	fBulletspeed_[nbulletnumber] = 0.0f;
	vPosition_[nbulletnumber] = VGet(0.0f, 0.0f, 0.0f);
}
