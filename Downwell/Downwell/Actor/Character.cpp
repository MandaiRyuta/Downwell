#include "Character.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"

VECTOR Character::vPosition_ = VGet(0.0f, 0.0f, 0.0f);

Character::Character()
{
	vPosition_ = VGet(132.0f, 180.0f, 1.0f);
	vScale_ = VGet(1.0f, 1.0f, 0.0f);
    ntexhandle = LoadGraph("Background.png");
	fSizeX_ = 32;
	fSizeY_ = 42;

	vSpeed.x = 0.0f;
	vSpeed.y = 0.0f;
	bGround = false;

	//nSideType_ = -1;
	//unLeftAcceleration_ = -1;
	//unRightAcceleration_ = -1;
	//nMoveFrame_ = 0;
	//fMove_ = 0;
	//MoveRemainingPower_ = 0.0f;

	for (int i = 0; i < 6; i++)
	{
		vtx2d_Vert[i] = {};
	}
}

Character::~Character()
{
}

void Character::Update()
{
	bGround = false;
	cJumpState_.JumpUpdate();

	if (bGround == false)
	{
		if (vPosition_.y > 180)
		{
			bGround = true;
		}
		if (Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x000)
		{
			cJumpState_.SetJumpExist(false);
		}
	}
	
	cJumpState_.JumpState(vPosition_, vSpeed, bGround);

	cMoveState_.SideMove(vPosition_);

	PolygonCreate();
}

void Character::Draw()
{
	//DrawBillboard3D(VGet(0.f, 0.f, 0.f), 0.5f, 0.5f, 225, 0, texhandle, true);
    DrawPolygon2D(vtx2d_Vert, 4,ntexhandle , FALSE);
}

void Character::PolygonCreate()
{
	vtx2d_Vert[0].pos = VGet(0.0f + vPosition_.x, 0.0f + vPosition_.y, 0.0f);
	vtx2d_Vert[0].rhw = 1.0f;
	vtx2d_Vert[0].dif = GetColorU8(255, 255, 255, 255);
	vtx2d_Vert[0].u = 0.0f;
	vtx2d_Vert[0].v = 0.0f;

	vtx2d_Vert[1].pos = VGet(fSizeX_ + vPosition_.x, 0.0f + vPosition_.y, 0.0f);
	vtx2d_Vert[1].rhw = 1.0f;
	vtx2d_Vert[1].dif = GetColorU8(255, 255, 255, 255);
	vtx2d_Vert[1].u = 1.0f;
	vtx2d_Vert[1].v = 0.0f;

	vtx2d_Vert[2].pos = VGet(0.0f + vPosition_.x, fSizeY_ + vPosition_.y, 0.0f);
	vtx2d_Vert[2].rhw = 1.0f;
	vtx2d_Vert[2].dif = GetColorU8(255, 255, 255, 255);
	vtx2d_Vert[2].u = 0.0f;
	vtx2d_Vert[2].v = 1.0f;

	vtx2d_Vert[3].pos = VGet(fSizeX_ + vPosition_.x, fSizeY_ + vPosition_.y, 0.0f);
	vtx2d_Vert[3].rhw = 1.0f;
	vtx2d_Vert[3].dif = GetColorU8(255, 255, 255, 255);
	vtx2d_Vert[3].u = 1.0f;
	vtx2d_Vert[3].v = 1.0f;

	vtx2d_Vert[4].pos = VGet(0.0f + vPosition_.x, fSizeY_ + vPosition_.y, 0.0f);
	vtx2d_Vert[4].rhw = 1.0f;
	vtx2d_Vert[4].dif = GetColorU8(255, 255, 255, 255);
	vtx2d_Vert[4].u = 0.0f;
	vtx2d_Vert[4].v = 1.0f;

	vtx2d_Vert[5].pos = VGet(fSizeX_ + vPosition_.x, 0.0f + vPosition_.y, 0.0f);
	vtx2d_Vert[5].rhw = 1.0f;
	vtx2d_Vert[5].dif = GetColorU8(255, 255, 255, 255);
	vtx2d_Vert[5].u = 1.0f;
	vtx2d_Vert[5].v = 0.0f;
}

VECTOR Character::GetPos()
{
    return vPosition_;
}

