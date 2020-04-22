#include "Character.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"

Character::Character()
{
	Position_ = VGet(0.0f, 0.0f, 0.0f);
	Scale_ = VGet(1.0f, 1.0f, 0.0f);
    texhandle = LoadGraph("Background.png");
    pshandle = LoadPixelShader("PixelShader.hlsl");

}

Character::~Character()
{
}

void Character::Update()
{
	float SizeX = 64;
	float SizeY = 64;

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
		Position_.x--;
	}
	if (Input::GetInstance().GetKeyPress(KEY_INPUT_RIGHT))
	{
		Position_.x++;
	}

    // �Q�|���S�����̒��_�̃f�[�^���Z�b�g�A�b�v
    Vert[0].pos = VGet(Position_.x, Position_.y, 0.0f);
    Vert[0].rhw = 1.0f;
    Vert[0].dif = GetColorU8(255, 255, 255, 255);
    Vert[0].spc = GetColorU8(0, 0, 0, 0);
    Vert[0].u = 0.0f;
    Vert[0].v = 0.0f;
    Vert[0].su = 0.0f;
    Vert[0].sv = 0.0f;

    Vert[1].pos = VGet(256.0f + Position_.x, Position_.y, 0.0f);
    Vert[1].rhw = 1.0f;
    Vert[1].dif = GetColorU8(255, 255, 255, 255);
    Vert[1].spc = GetColorU8(0, 0, 0, 0);
    Vert[1].u = 1.0f;
    Vert[1].v = 0.0f;
    Vert[1].su = 1.0f;
    Vert[1].sv = 0.0f;

    Vert[2].pos = VGet(Position_.x, 256.0f + Position_.y, 0.0f);
    Vert[2].rhw = 1.0f;
    Vert[2].dif = GetColorU8(255, 255, 255, 255);
    Vert[2].spc = GetColorU8(0, 0, 0, 0);
    Vert[2].u = 0.0f;
    Vert[2].v = 1.0f;
    Vert[2].su = 0.0f;
    Vert[2].sv = 1.0f;

    Vert[3].pos = VGet(256.0f + Position_.x, 256.0f + Position_.y, 0.0f);
    Vert[3].rhw = 1.0f;
    Vert[3].dif = GetColorU8(255, 255, 255, 255);
    Vert[3].spc = GetColorU8(0, 0, 0, 0);
    Vert[3].u = 1.0f;
    Vert[3].v = 1.0f;
    Vert[3].su = 1.0f;
    Vert[3].sv = 1.0f;

    // �Q�|���S�����̒��_�ԍ��z��̃Z�b�g�A�b�v
    Index[0] = 0;
    Index[1] = 1;
    Index[2] = 2;
    Index[3] = 2;
    Index[4] = 1;
    Index[5] = 3;

	Camera::GetInstance().SetPosition(Position_);
}

void Character::Draw()
{
    // �g�p����e�N�X�`�����O�ԂɃZ�b�g
    SetUseTextureToShader(0, texhandle);

    // �g�p����s�N�Z���V�F�[�_�[���Z�b�g
    SetUsePixelShader(pshandle);

    // �V�F�[�_�[���g�p�����Q�c�̂Q�|���S���̕`��
    DrawPolygonIndexed2DToShader(Vert, 4, Index, 2);
}
