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
	bPlayershake_ = false;
	fPlayershake_ = 2.5f;
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
}

Character::~Character()
{
}

void Character::Update()
{
	if (fGravity_ > -20.0f)
	{
		fGravity_ += fGravity;
	}

	vSpeed_.y = fGravity_;

	if (bPlayershake_)
	{
		vSpeed_.y = vSpeed_.y + (fPlayershake_ * -1.0f);
	}
	cMoveState_.SideMove(vPosition_,vSpeed_.x,vSpeed_.y, fGravity_, fSizeX_, bGround);
	cAttackState_.Attack(vPosition_, cJumpState_.GetJumpExist(), cJumpState_.GetBulletJumpExist(), nCharacterActionState_, fGravity_, bPlayershake_);
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


