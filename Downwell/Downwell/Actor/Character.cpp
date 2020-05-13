#include "Character.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"
#include "Stage.h"
#include "EnemyParameter.h"
#include "../Resource/TextureData.h"
#include <random>

VECTOR Character::vPosition_ = VGet(0.0f, 0.0f, 0.0f);
bool Character::bHitEnemy_ = false;
bool Character::bDamage_ = false;
bool Character::bLeftDamage_ = false;
bool Character::bRightDamage_ = false;

Character::Character()
{
	vPosition_ = VGet(ScreenWidth / 2, -300.0f, 0.0f);
	vOldPosition_ = VGet(ScreenWidth / 2, -300.0f, 0.0f);
	vScale_ = VGet(1.0f, 1.0f, 0.0f);
	nLife_ = 5;
	fSizeX_ = 16;
	fSizeY_ = 16;
	bPlayershake_ = false;
	fPlayershake_ = 2.5f;
	rPlayer_.x = vPosition_.x;
	rPlayer_.y = vPosition_.y;
	rPlayer_.width = fSizeX_;
	rPlayer_.height = fSizeY_;

    ntexhandle = TextureDataBase::TextureData::GetInstance().GetTextureData(TextureDataBase::TextureNumber::Player);

	vSpeed_.x = 0.0f;
	vSpeed_.y = 0.0f;
	vSpeed_.z = 0.0f;

	bGround = false;
	bHitEnemy_ = false;
	bLeftDamage_ = false;
	bRightDamage_ = false;
	fGravity_ = 0.0f;
	nCharacterActionState_ = 0;
	nHitCooltime_ = 0;
	bInvincible_ = false;
}

Character::~Character()
{
}

void Character::Update()
{
	if (bInvincible_)
	{
		if (bDamage_)
		{
			bDamage_ = false;
		}
		if (bLeftDamage_)
		{
			bLeftDamage_ = false;
		}
		if (bRightDamage_)
		{
			bRightDamage_ = false;
		}

		if (nHitCooltime_ > 120)
		{
			bInvincible_ = false;
			nHitCooltime_ = 0;
		}

		nHitCooltime_++;
	}
	if (fGravity_ > -10.0f)
	{
		fGravity_ += fGravity;
	}

	vSpeed_.y = fGravity_;

	if (bPlayershake_)
	{
		vSpeed_.y = vSpeed_.y + (fPlayershake_ * -1.0f);
	}

	if(bHitEnemy_)
	{
		vSpeed_.y += 20.0f;
		bHitEnemy_ = false;
	}
	if (bDamage_)
	{
		nLife_ -= 1;
		vPosition_.y += 5.0f;
		bLeftDamage_ = false;
		bInvincible_ = true;
	}
	if (bLeftDamage_)
	{
		nLife_ -= 1;
		vPosition_.y += 5.0f;
		vPosition_.x += 5.0f;
		bLeftDamage_ = false;
		bInvincible_ = true;
	}
	if (bRightDamage_)
	{
		nLife_ -= 1;
		vPosition_.y += 5.0f;
		vPosition_.x -= 5.0f;
		bRightDamage_ = false;
		bInvincible_ = true;
	}

	cMoveState_.SideMove(vPosition_,vSpeed_.x,vSpeed_.y, fGravity_, fSizeX_, bGround);
	cAttackState_.Attack(vPosition_, cJumpState_.GetJumpExist(), cJumpState_.GetBulletJumpExist(), nCharacterActionState_, fGravity_, bPlayershake_);
	cJumpState_.JumpState(vPosition_, vSpeed_, fGravity_, nCharacterActionState_);

	vPosition_.y += vSpeed_.y;
}

void Character::Draw()
{
	DrawBillboard3D(VGet(vPosition_.x, vPosition_.y, 0.0f), 0.5f, 0.5f, 16.0f, 0, ntexhandle,false);
	
	cAttackState_.Draw(); 
}

VECTOR& Character::GetPos()
{
    return vPosition_;
}

void Character::SetHitEnemy(bool bhit)
{
	bHitEnemy_ = bhit;
}

void Character::SetHitDamage(bool bdamage)
{
	bDamage_ = bdamage;
}

void Character::SetHitLeftDamage(bool bdamage)
{
	bLeftDamage_ = bdamage;
}

void Character::SetHitRightDamage(bool bdamage)
{
	bRightDamage_ = bdamage;
}


