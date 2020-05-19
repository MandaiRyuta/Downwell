#include "Bullet.h"
#include "../Input/Input.h"
#include <math.h>
#include "../Collision/MapHitCheck.h"
#include "Stage.h"
#include "Character.h"
#include "../Resource/TextureData.h"
#include "../Level/LevelsResponsible.h"
VECTOR Bullet::vPosition_[10] = {};	//弾の座標
bool Bullet::bBullet_[10] = {};	//弾の表示フラグ
float Bullet::fBulletspeed_[10] = {};	//弾の移動距離

/// <summary>
/// コンストラクター
/// </summary>
Bullet::Bullet() : nBulletCount_()
{
	for (int i = 0; i < nBulletMaxCount; i++)
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
/// デストラクター
/// </summary>
Bullet::~Bullet()
{
}
/// <summary>
/// 更新関数
/// </summary>
void Bullet::Update()
{
	float dammy = 0.0f;

	if (Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001)
	{
		bBullet_[nBulletNumber] = true;
	}

	if (bBullet_[nBulletNumber])
	{
		switch (nBulletType_)
		{
		case 0:
			for (int i = 0; i < nBulletMaxCount; i++)
			{
				fBulletspeed_[i] = fBulletSpeed;

				if (nBulletCount_[i] > nBulletDeadMaxCount)
				{
					nBulletCount_[i] = 0;
					bBullet_[i] = false;
					fBulletspeed_[i] = fBulletInitSpeed;
					vPosition_[i] = VGet(fDefaultPos, fDefaultPos, fDefaultPos);
				}
				if (LevelsResponsible::GetInstance().GetNowLevel() == 0)
				{
					if (MapHitChecker::GetChipParam(VGet(vPosition_[i].x - (fScale_ * 0.5f), vPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 1 ||
						MapHitChecker::GetChipParam(VGet(vPosition_[i].x + (fScale_ * 0.5f), vPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 1 ||
						MapHitChecker::GetChipParam(VGet(vPosition_[i].x - (fScale_ * 0.5f), vPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 2 ||
						MapHitChecker::GetChipParam(VGet(vPosition_[i].x + (fScale_ * 0.5f), vPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 2 ||
						MapHitChecker::GetChipParam(VGet(vPosition_[i].x - (fScale_ * 0.5f), vPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 4 ||
						MapHitChecker::GetChipParam(VGet(vPosition_[i].x + (fScale_ * 0.5f), vPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 4 ||
						MapHitChecker::GetChipParam(VGet(vPosition_[i].x - (fScale_ * 0.5f), vPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 5 ||
						MapHitChecker::GetChipParam(VGet(vPosition_[i].x + (fScale_ * 0.5f), vPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 5)
					{
						bBullet_[i] = false;
						fBulletspeed_[i] = fBulletInitSpeed;
						vPosition_[i] = VGet(fDefaultPos, fDefaultPos, fDefaultPos);
					}
				}
				else
				{
					if (MapHitChecker::GetChipParam(VGet(vPosition_[i].x - (fScale_ * 0.5f), vPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 2 ||
						MapHitChecker::GetChipParam(VGet(vPosition_[i].x + (fScale_ * 0.5f), vPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 2 ||
						MapHitChecker::GetChipParam(VGet(vPosition_[i].x - (fScale_ * 0.5f), vPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 4 ||
						MapHitChecker::GetChipParam(VGet(vPosition_[i].x + (fScale_ * 0.5f), vPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 4 ||
						MapHitChecker::GetChipParam(VGet(vPosition_[i].x - (fScale_ * 0.5f), vPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 5 ||
						MapHitChecker::GetChipParam(VGet(vPosition_[i].x + (fScale_ * 0.5f), vPosition_[i].y - (fScale_ * 0.5f + 1.0f), 0.0f)) == 5)
					{
						bBullet_[i] = false;
						fBulletspeed_[i] = fBulletInitSpeed;
						vPosition_[i] = VGet(fDefaultPos, fDefaultPos, fDefaultPos);
					}
				}
				vPosition_[i].y -= fBulletspeed_[i];
				nBulletCount_[i]++;
			}
			break;
		}
	}
}
/// <summary>
/// 描画関数
/// </summary>
void Bullet::Draw()
{
	if (bBullet_[nBulletNumber])
	{
		for (int i = 0; i < nBulletMaxCount; i++)
		{
			DrawBillboard3D(vPosition_[i], 0.5f, 0.5f, fScale_, 0, nBulletTexture_, false);
		}
	}
}
/// <summary>
/// 弾作成関数
/// </summary>
/// <param name="vpos">弾の出現座標</param>
void Bullet::Create(const VECTOR& vpos)
{
	if (nBulletNumber > nBulletMaxCount - 1)
	{
		nBulletNumber = 0;
	}
	else
	{
		vPosition_[nBulletNumber].x = vpos.x;
		vPosition_[nBulletNumber].y = vpos.y;
		vPosition_[nBulletNumber].z = fDefaultPos;
	}
	
	nBulletNumber++;
}
/// <summary>
/// 弾の画像大きさ取得関数
/// </summary>
/// <returns>弾画像の幅</returns>
const float& Bullet::Scale()
{
	return fScale_;
}
/// <summary>
/// 弾の座標取得関数
/// </summary>
/// <param name="nbulletnumber">弾の番号</param>
/// <returns>弾の座標</returns>
const VECTOR& Bullet::GetPosition(int nbulletnumber)
{
	return vPosition_[nbulletnumber];
}
/// <summary>
/// 弾の座標初期化関数
/// </summary>
/// <param name="nbulletnumber">弾の番号</param>
void Bullet::ResetSetPosition(int nbulletnumber)
{
	bBullet_[nbulletnumber] = false;
	fBulletspeed_[nbulletnumber] = fBulletInitSpeed;
	vPosition_[nbulletnumber] = VGet(fDefaultPos, fDefaultPos, fDefaultPos);
}
/// <summary>
/// 弾の表示フラグ取得関数
/// </summary>
/// <param name="num">弾の番号</param>
/// <returns>弾の表示もしくは非表示フラグ</returns>
const bool& Bullet::GetBulletExist(int num)
{
	return bBullet_[num];
}