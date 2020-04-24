#include "Character.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"

VECTOR Character::Position_ = VGet(0.0f, 0.0f, 0.0f);

Character::Character()
{
	Position_ = VGet(132.0f, 112.0f, 1.0f);
	Scale_ = VGet(1.0f, 1.0f, 0.0f);
    texhandle = LoadGraph("Background.png");
	SizeX_ = 64;
	SizeY_ = 64;
}

Character::~Character()
{
}

void Character::Update()
{


	if (Input::GetInstance().GetKeyPress(KEY_INPUT_UP))
	{
		Position_.y--;
	}
	if (Input::GetInstance().GetKeyPress(KEY_INPUT_DOWN))
	{
		Position_.y++;
	}
	if (Input::GetInstance().GetKeyPress(KEY_INPUT_LEFT))
	{
		if(Position_.x > ScreenWidth / 4)
		Position_.x--;
	}
	if (Input::GetInstance().GetKeyPress(KEY_INPUT_RIGHT))
	{
		if(Position_.x < ScreenWidth - (SizeX_ + (ScreenWidth / 4)))
		Position_.x++;
	}

	PolygonCreate();
}

void Character::Draw()
{
	//DrawBillboard3D(VGet(0.f, 0.f, 0.f), 0.5f, 0.5f, 225, 0, texhandle, true);
    DrawPolygon2D(Vert, 4,texhandle , FALSE);
}

void Character::PolygonCreate()
{

	Vert[0].pos = VGet(0.0f + Position_.x, 0.0f + Position_.y, 0.0f);
	Vert[0].rhw = 1.0f;
	Vert[0].dif = GetColorU8(255, 255, 255, 255);
	Vert[0].u = 0.0f;
	Vert[0].v = 0.0f;

	Vert[1].pos = VGet(SizeX_ + Position_.x, 0.0f + Position_.y, 0.0f);
	Vert[1].rhw = 1.0f;
	Vert[1].dif = GetColorU8(255, 255, 255, 255);
	Vert[1].u = 1.0f;
	Vert[1].v = 0.0f;

	Vert[2].pos = VGet(0.0f + Position_.x, SizeY_ + Position_.y, 0.0f);
	Vert[2].rhw = 1.0f;
	Vert[2].dif = GetColorU8(255, 255, 255, 255);
	Vert[2].u = 0.0f;
	Vert[2].v = 1.0f;

	Vert[3].pos = VGet(SizeX_ + Position_.x, SizeY_ + Position_.y, 0.0f);
	Vert[3].rhw = 1.0f;
	Vert[3].dif = GetColorU8(255, 255, 255, 255);
	Vert[3].u = 1.0f;
	Vert[3].v = 1.0f;

	Vert[4].pos = VGet(0.0f + Position_.x, SizeY_ + Position_.y, 0.0f);
	Vert[4].rhw = 1.0f;
	Vert[4].dif = GetColorU8(255, 255, 255, 255);
	Vert[4].u = 0.0f;
	Vert[4].v = 1.0f;

	Vert[5].pos = VGet(SizeX_ + Position_.x, 0.0f + Position_.y, 0.0f);
	Vert[5].rhw = 1.0f;
	Vert[5].dif = GetColorU8(255, 255, 255, 255);
	Vert[5].u = 1.0f;
	Vert[5].v = 0.0f;
}

VECTOR Character::GetPos()
{
    return Position_;
}
