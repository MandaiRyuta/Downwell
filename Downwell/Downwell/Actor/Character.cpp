#include "Character.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"
#include "Stage.h"
VECTOR Character::vPosition_ = VGet(0.0f, 0.0f, 0.0f);

Character::Character()
{
	vPosition_ = VGet(ScreenWidth / 2, -300.0f, 0.0f);
	vOldPosition_ = VGet(ScreenWidth / 2, -300.0f, 0.0f);
	vScale_ = VGet(1.0f, 1.0f, 0.0f);

	fSizeX_ = 16;
	fSizeY_ = 16;

	rPlayer_.x = vPosition_.x;
	rPlayer_.y = vPosition_.y;
	rPlayer_.width = fSizeX_;
	rPlayer_.height = fSizeY_;

    ntexhandle = LoadGraph("Resource/player.png");

	vSpeed_.x = 0.0f;
	vSpeed_.y = 0.0f;
	vSpeed_.z = 0.0f;

	bGround = false;

	fGravity_ = 0.0f;

	nCharacterActionState_ = 0;

	for (int i = 0; i < 6; i++)
	{
		vtx3d_vert[i] = {};
	}
}

Character::~Character()
{
}

void Character::Update()
{
	fGravity_ += fGravity;
	vSpeed_.y = fGravity_;

	cMoveState_.SideMove(vPosition_,vSpeed_.x,vSpeed_.y, fGravity_, fSizeX_, bGround);
	cAttackState_.Attack(vPosition_, cJumpState_.GetJumpExist(), cJumpState_.GetBulletJumpExist(), nCharacterActionState_, fGravity_);
	cJumpState_.JumpState(vPosition_, vSpeed_, fGravity_, nCharacterActionState_);

	vPosition_.y += vSpeed_.y;
}

void Character::Draw()
{
	DrawBillboard3D(VGet(vPosition_.x, vPosition_.y, 0.0f), 0.5f, 0.5f, 16, 0, ntexhandle,false);
	
	cAttackState_.Draw(); 
}

VECTOR Character::GetPos()
{
    return vPosition_;
}

void Character::CreatePolygon()
{
	vtx3d_vert[0].pos = VGet(0.0f + vPosition_.x, 0.0f + vPosition_.y, 0.0f);

	vtx3d_vert[0].dif = GetColorU8(255, 255, 255, 255);
	vtx3d_vert[0].u = 0.0f;
	vtx3d_vert[0].v = 0.0f;
	vtx3d_vert[1].pos = VGet(fSizeX_ + vPosition_.x, 0.0f + vPosition_.y, 0.0f);

	vtx3d_vert[1].dif = GetColorU8(255, 255, 255, 255);
	vtx3d_vert[1].u = 1.0f;
	vtx3d_vert[1].v = 0.0f;
	vtx3d_vert[2].pos = VGet(0.0f + vPosition_.x, fSizeY_ + vPosition_.y, 0.0f);

	vtx3d_vert[2].dif = GetColorU8(255, 255, 255, 255);
	vtx3d_vert[2].u = 0.0f;
	vtx3d_vert[2].v = 1.0f;
	vtx3d_vert[3].pos = VGet(fSizeX_ + vPosition_.x, fSizeY_ + vPosition_.y, 0.0f);

	vtx3d_vert[3].dif = GetColorU8(255, 255, 255, 255);
	vtx3d_vert[3].u = 1.0f;
	vtx3d_vert[3].v = 1.0f;
	vtx3d_vert[4].pos = VGet(0.0f + vPosition_.x, fSizeY_ + vPosition_.y, 0.0f);

	vtx3d_vert[4].dif = GetColorU8(255, 255, 255, 255);
	vtx3d_vert[4].u = 0.0f;
	vtx3d_vert[4].v = 1.0f;
	vtx3d_vert[5].pos = VGet(fSizeX_+ vPosition_.x, 0.0f + vPosition_.y, 0.0f);

	vtx3d_vert[5].dif = GetColorU8(255, 255, 255, 255);
	vtx3d_vert[5].u = 1.0f;
	vtx3d_vert[5].v = 0.0f;
}

