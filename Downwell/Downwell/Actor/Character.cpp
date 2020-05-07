#include "Character.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"

VECTOR Character::vPosition_ = VGet(0.0f, 0.0f, 0.0f);

Character::Character()
{
	vPosition_ = VGet(ScreenWidth / 2, -300.0f, 0.0f);
	vScale_ = VGet(1.0f, 1.0f, 0.0f);

	fSizeX_ = 18;
	fSizeY_ = 18;

    ntexhandle = LoadGraph("Resource/player.png");

	vSpeed.x = 0.0f;
	vSpeed.y = 0.0f;
	bGround = false;

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
	bGround = false;
	cJumpState_.JumpUpdate();
	
	//if (Input::GetInstance().GetKeyPress(KEY_INPUT_DOWN) )
	//{
	//	vPosition_.y--;
	//}
	//if (Input::GetInstance().GetKeyPress(KEY_INPUT_UP))
	//{
	//	vPosition_.y++;
	//}
	if (bGround == false)
	{
		if (vPosition_.y <= -350)
		{
			bGround = true;

			nCharacterActionState_ = 0;

			if (Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x000)
			{
				cAttackState_.SetAttackExist(false);
				cAttackState_.SetBullet(8);
				cAttackState_.SetAttackFrame(0);
				cJumpState_.SetBulletJumpExist(false);
				cJumpState_.SetJumpExist(false);
			}
		}
	}
	CreatePolygon();


 	cJumpState_.JumpState(vPosition_, vSpeed, bGround, nCharacterActionState_);

	cAttackState_.Attack(bGround, nCharacterActionState_, vPosition_, cJumpState_.GetJumpExist());

	cMoveState_.SideMove(vPosition_);
}

void Character::Draw()
{
	DrawBillboard3D(VGet(vPosition_.x, vPosition_.y, 0.0f), 0.5f, 0.5f, 25, 0, ntexhandle,false);
	//DrawPolygon3D(vtx3d_vert, 4, ntexhandle, false);
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

