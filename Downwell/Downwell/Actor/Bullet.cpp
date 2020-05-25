#include "Bullet.h"
#include "../Input/Input.h"
#include <math.h>
#include "../Collision/MapHitCheck.h"
#include "Stage.h"
#include "Character.h"
#include "../Resource/TextureData.h"
#include "../Level/LevelsResponsible.h"
VECTOR Bullet::vBulletsPosition_[10] = {};	//�e�̍��W
bool Bullet::bBullet_[10] = {};	//�e�̕\���t���O
float Bullet::fBulletspeed_[10] = {};	//�e�̈ړ�����

/// <summary>
/// �R���X�g���N�^�[
/// </summary>
Bullet::Bullet() : nBulletCount_()
{
	for (int i = 0; i < nBulletMaxCount; ++i)
	{
		bBullet_[i] = false;
		nBulletCount_[i] = nBulletInitCount;
	}
	fScale_ = fBulletScale;
	nBulletNumber = nBulletInitNumber;

	if (LevelsResponsible::GetInstance().GetNowLevel() == nTitleLevel)
	{
		nBulletTexture_ = TextureDataBase::TextureData::GetInstance().GetTitleTextureData(TextureDataBase::TitleTextureNumber::TBullet);
	}
	else if (LevelsResponsible::GetInstance().GetNowLevel() == nGameLevel)
	{
		nBulletTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GBullet);
	}
	nBulletType_ = nBulletInitType;
}
/// <summary>
/// �f�X�g���N�^�[
/// </summary>
Bullet::~Bullet()
{
}
/// <summary>
/// �X�V�֐�
/// </summary>
void Bullet::Update()
{
	BulletFlagSet();

	BulletMove();
}
/// <summary>
/// �`��֐�
/// </summary>
void Bullet::Draw()
{
	if (bBullet_[nBulletNumber])
	{
		for (int i = 0; i < nBulletMaxCount; ++i)
		{
			DrawBillboard3D(vBulletsPosition_[i], 0.5f, 0.5f, fScale_, 0, nBulletTexture_, false);
		}
	}
}
/// <summary>
/// �e���\������\���ɐ؂�ւ���֐�
/// </summary>
void Bullet::BulletFlagSet()
{
	if (Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001)
	{
		bBullet_[nBulletNumber] = true;
	}
}
/// <summary>
/// �e�̈ړ��֐�
/// </summary>
void Bullet::BulletMove()
{

	if (!bBullet_[nBulletNumber]) return;

	switch (nBulletType_)
	{
	case 0:
		for (int i = 0; i < nBulletMaxCount; ++i)
		{
			fBulletspeed_[i] = fBulletSpeed;

			if (nBulletCount_[i] > nBulletDeadMaxCount)
			{
				nBulletCount_[i] = 0;
				bBullet_[i] = false;
				fBulletspeed_[i] = fBulletInitSpeed;
				vBulletsPosition_[i] = VGet(fDefaultPos, fDefaultPos, fDefaultPos);
			}
			if (LevelsResponsible::GetInstance().GetNowLevel() == 0)
			{
				if (MapHitChecker::GetChipParam(VGet(vBulletsPosition_[i].x - (fScale_ * 0.5f), vBulletsPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 1 ||
					MapHitChecker::GetChipParam(VGet(vBulletsPosition_[i].x + (fScale_ * 0.5f), vBulletsPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 1 ||
					MapHitChecker::GetChipParam(VGet(vBulletsPosition_[i].x - (fScale_ * 0.5f), vBulletsPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 2 ||
					MapHitChecker::GetChipParam(VGet(vBulletsPosition_[i].x + (fScale_ * 0.5f), vBulletsPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 2 ||
					MapHitChecker::GetChipParam(VGet(vBulletsPosition_[i].x - (fScale_ * 0.5f), vBulletsPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 4 ||
					MapHitChecker::GetChipParam(VGet(vBulletsPosition_[i].x + (fScale_ * 0.5f), vBulletsPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 4 ||
					MapHitChecker::GetChipParam(VGet(vBulletsPosition_[i].x - (fScale_ * 0.5f), vBulletsPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 5 ||
					MapHitChecker::GetChipParam(VGet(vBulletsPosition_[i].x + (fScale_ * 0.5f), vBulletsPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 5)
				{
					bBullet_[i] = false;
					fBulletspeed_[i] = fBulletInitSpeed;
					vBulletsPosition_[i] = VGet(fDefaultPos, fDefaultPos, fDefaultPos);
				}
			}
			else
			{
				if (MapHitChecker::GetChipParam(VGet(vBulletsPosition_[i].x - (fScale_ * 0.5f), vBulletsPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 2 ||
					MapHitChecker::GetChipParam(VGet(vBulletsPosition_[i].x + (fScale_ * 0.5f), vBulletsPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 2 ||
					MapHitChecker::GetChipParam(VGet(vBulletsPosition_[i].x - (fScale_ * 0.5f), vBulletsPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 4 ||
					MapHitChecker::GetChipParam(VGet(vBulletsPosition_[i].x + (fScale_ * 0.5f), vBulletsPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 4 ||
					MapHitChecker::GetChipParam(VGet(vBulletsPosition_[i].x - (fScale_ * 0.5f), vBulletsPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 5 ||
					MapHitChecker::GetChipParam(VGet(vBulletsPosition_[i].x + (fScale_ * 0.5f), vBulletsPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 5)
				{
					bBullet_[i] = false;
					fBulletspeed_[i] = fBulletInitSpeed;
					vBulletsPosition_[i] = VGet(fDefaultPos, fDefaultPos, fDefaultPos);
				}
			}
			vBulletsPosition_[i].y -= fBulletspeed_[i];
			nBulletCount_[i]++;
		}
		break;
	}
}
/// <summary>
/// �e�쐬�֐�
/// </summary>
/// <param name="vPosition">�e�̏o�����W</param>
void Bullet::Create(const VECTOR& vPosition)
{
	if (nBulletNumber > nBulletMaxCount - 1)
	{
		nBulletNumber = 0;
	}
	else
	{
		vBulletsPosition_[nBulletNumber].x = vPosition.x;
		vBulletsPosition_[nBulletNumber].y = vPosition.y;
		vBulletsPosition_[nBulletNumber].z = fDefaultPos;
	}
	
	nBulletNumber++;
}
/// <summary>
/// �e�̉摜�傫���擾�֐�
/// </summary>
/// <returns>�e�摜�̕�</returns>
const float& Bullet::Scale()
{
	return fScale_;
}
/// <summary>
/// �e�̍��W�擾�֐�
/// </summary>
/// <param name="nBulletnumber">�e�̔ԍ�</param>
/// <returns>�e�̍��W</returns>
const VECTOR& Bullet::GetPosition(int nBulletnumber)
{
	return vBulletsPosition_[nBulletnumber];
}
/// <summary>
/// �e�̍��W�������֐�
/// </summary>
/// <param name="nBulletnumber">�e�̔ԍ�</param>
void Bullet::ResetSetPosition(int nBulletnumber)
{
	bBullet_[nBulletnumber] = false;
	fBulletspeed_[nBulletnumber] = fBulletInitSpeed;
	vBulletsPosition_[nBulletnumber] = VGet(fDefaultPos, fDefaultPos, fDefaultPos);
}
/// <summary>
/// �e�̕\���t���O�擾�֐�
/// </summary>
/// <param name="num">�e�̔ԍ�</param>
/// <returns>�e�̕\���������͔�\���t���O</returns>
const bool& Bullet::GetBulletExist(int nEnemyNum)
{
	return bBullet_[nEnemyNum];
}