#include "Bullet.h"
#include "../Input/Input.h"
Bullet::Bullet()
{
	bBullet_ = false;
	vScale_.x = 25.0f;
	vScale_.y = 35.0f;
	for (int i = 0; i < 5; i++)
	{
		vtx2d_Vert[i] = {};
	}
	nBulletFrame_ = 0;
	nBulletNumber = 0;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001)
	{
		bBullet_ = true;
	}

	if (bBullet_)
	{
		for (int i = 0; i < 10; i++)
		{
			vPosition_[i].y += 20.0f;
		}
	}
}

void Bullet::Draw()
{
	for (int i = 0; i < 10; i++)
	{
		DrawBox(vPosition_[i].x, vPosition_[i].y, vPosition_[i].x + vScale_.x, vPosition_[i].y + vScale_.y, GetColor(255, 255, 255), true);
	}
}

void Bullet::Create(const VECTOR& vpos)
{
	if (nBulletNumber >= 10)
	{
		nBulletNumber = 0;
	}

	vPosition_[nBulletNumber].x = ((32 - vScale_.x) * 0.5) + vpos.x;
	vPosition_[nBulletNumber].y = ((42 - vScale_.y) * 0.5) + vpos.y;

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

//void Bullet::CreatePolygon()
//{
//	vtx2d_Vert[0].pos = VGet(0.0f + vPosition_.x, 0.0f + vPosition_.y, 0.0f);
//	vtx2d_Vert[0].rhw = 1.0f;
//	vtx2d_Vert[0].dif = GetColorU8(255, 255, 255, 255);
//	vtx2d_Vert[0].u = 0.0f;
//	vtx2d_Vert[0].v = 0.0f;
//
//	vtx2d_Vert[1].pos = VGet(vScale_.x + vPosition_.x, 0.0f + vPosition_.y, 0.0f);
//	vtx2d_Vert[1].rhw = 1.0f;
//	vtx2d_Vert[1].dif = GetColorU8(255, 255, 255, 255);
//	vtx2d_Vert[1].u = 1.0f;
//	vtx2d_Vert[1].v = 0.0f;
//
//	vtx2d_Vert[2].pos = VGet(0.0f + vPosition_.x, vScale_.y + vPosition_.y, 0.0f);
//	vtx2d_Vert[2].rhw = 1.0f;
//	vtx2d_Vert[2].dif = GetColorU8(255, 255, 255, 255);
//	vtx2d_Vert[2].u = 0.0f;
//	vtx2d_Vert[2].v = 1.0f;
//
//	vtx2d_Vert[3].pos = VGet(vScale_.x + vPosition_.x, vScale_.y + vPosition_.y, 0.0f);
//	vtx2d_Vert[3].rhw = 1.0f;
//	vtx2d_Vert[3].dif = GetColorU8(255, 255, 255, 255);
//	vtx2d_Vert[3].u = 1.0f;
//	vtx2d_Vert[3].v = 1.0f;
//
//	vtx2d_Vert[4].pos = VGet(0.0f + vPosition_.x, vScale_.y + vPosition_.y, 0.0f);
//	vtx2d_Vert[4].rhw = 1.0f;
//	vtx2d_Vert[4].dif = GetColorU8(255, 255, 255, 255);
//	vtx2d_Vert[4].u = 0.0f;
//	vtx2d_Vert[4].v = 1.0f;
//
//	vtx2d_Vert[5].pos = VGet(vScale_.x + vPosition_.x, 0.0f + vPosition_.y, 0.0f);
//	vtx2d_Vert[5].rhw = 1.0f;
//	vtx2d_Vert[5].dif = GetColorU8(255, 255, 255, 255);
//	vtx2d_Vert[5].u = 1.0f;
//	vtx2d_Vert[5].v = 0.0f;
//}
