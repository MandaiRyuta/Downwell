#include "Character.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"
#include "Stage.h"
#include "EnemyParameter.h"
#include "../Resource/TextureData.h"
#include "../Collision/MapHitCheck.h"
#include "../Level/LevelsResponsible.h"
#include <random>

VECTOR Character::vPosition_ = VGet(0.0f, 0.0f, 0.0f);	//プレイヤー座標
bool Character::bHitEnemy_ = false;	//プレイヤーの足元が敵の真上着地した際のフラグ
bool Character::bDamage_ = false;	//ダメージフラグ
bool Character::bLeftDamage_ = false;	//プレイヤーの左側面が敵に衝突した際のフラグ
bool Character::bRightDamage_ = false;	//プレイヤーの右側面が敵に衝突した際のフラグ
int Character::nLife_ = 0;	//プレイヤーHP
/// <summary>
/// コンストラクター
/// </summary>
/// <param name="nscenenumber">シーン番号</param>
Character::Character(int nscenenumber) : nNowScene_(nscenenumber)
{
	if (nNowScene_ == 0)
	{
		vPosition_ = VGet(ScreenWidth / 2 - 150.0f, -300.0f, 0.0f);
		vOldPosition_ = VGet(ScreenWidth / 2 - 150.0f, -300.0f, 0.0f);
		nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetTitleTextureData(TextureDataBase::TitleTextureNumber::TPlayer);
	}
	if (nNowScene_ == 1)
	{
		vPosition_ = VGet(ScreenWidth / 2 + 18.0f, -700.0f, 0.0f);
		vOldPosition_ = VGet(ScreenWidth / 2 + 18.0f, -700.0f, 0.0f);
		nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GPlayer);
	}
	if (nNowScene_ == 2)
	{
		vPosition_ = VGet(ScreenWidth / 2 + 18.0f, -900.0f, 0.0f);
		vOldPosition_ = VGet(ScreenWidth / 2 + 18.0f, -900.0f, 0.0f);
		nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::RPlayer);
	}

	nLife_ = 5;
	fSize_ = 16;
	bPlayershake_ = false;
	fPlayershake_ = 2.5f;


	vSpeed_.x = 0.0f;
	vSpeed_.y = 0.0f;
	vSpeed_.z = 0.0f;

	bHitEnemy_ = false;
	bLeftDamage_ = false;
	bRightDamage_ = false;
	fGravity_ = 0.0f;
	nCharacterActionState_ = 0;
	nHitCooltime_ = 0;
	bInvincible_ = false;
}
/// <summary>
/// デストラクター
/// </summary>
Character::~Character()
{
}
/// <summary>
/// 更新関数
/// </summary>
void Character::Update()
{
	if (nNowScene_ == 0)
	{
		if (MapHitCheck::GetChipParam(VGet(vPosition_.x + 8, vPosition_.y + 8, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false ||
			MapHitCheck::GetChipParam(VGet(vPosition_.x - 8, vPosition_.y - 8, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false)
		{
			LevelsResponsible::GetInstance().SetNowLevel(1);
			LevelsResponsible::GetInstance().SetChangeLevel(true);
		}

		if (MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 0 && LevelsResponsible::GetInstance().GetNextStageExist() == true ||
			MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 0 && LevelsResponsible::GetInstance().GetNextStageExist() == true)
		{
			LevelsResponsible::GetInstance().SetNextStage(false);
		}
		else if (MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false ||
			MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false)
		{
			LevelsResponsible::GetInstance().NextStage();
		}
	}
	if (nNowScene_ == 1)
	{
		if (MapHitCheck::GetChipParam(VGet(vPosition_.x + 8, vPosition_.y + 8, 0.0f)) == 18 || MapHitCheck::GetChipParam(VGet(vPosition_.x - 8, vPosition_.y - 8, 0.0f)) == 18)
		{
			LevelsResponsible::GetInstance().SetLevelState(false);
			LevelsResponsible::GetInstance().SetNowLevel(2);
			LevelsResponsible::GetInstance().SetChangeLevel(true);
		}
		if (nLife_ == 0)
		{
			LevelsResponsible::GetInstance().SetLevelState(true);
			LevelsResponsible::GetInstance().SetNowLevel(2);
			LevelsResponsible::GetInstance().SetChangeLevel(true);
		}
		if (MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 0 && LevelsResponsible::GetInstance().GetNextStageExist() == true ||
			MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 0 && LevelsResponsible::GetInstance().GetNextStageExist() == true)
		{
			LevelsResponsible::GetInstance().SetNextStage(false);
		}
		else if (MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false ||
			MapHitCheck::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false)
		{
			LevelsResponsible::GetInstance().NextStage();
		}
	}

	if (nNowScene_ == 0 || nNowScene_ == 1)
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

		MoveState_.SideMove(vPosition_,vSpeed_.x,vSpeed_.y, fGravity_, fSize_);
		AttackState_.Attack(vPosition_, JumpState_.GetJumpExist(), JumpState_.GetBulletJumpExist(), nCharacterActionState_, fGravity_, bPlayershake_);
		JumpState_.JumpState(vPosition_, vSpeed_, fGravity_, nCharacterActionState_);

		vPosition_.y += vSpeed_.y;
	}
}
/// <summary>
/// 描画関数
/// </summary>
void Character::Draw()
{
	DrawBillboard3D(VGet(vPosition_.x, vPosition_.y, 0.0f), 0.5f, 0.5f, fSize_, 0, nTexhandle_,false);
	
	AttackState_.Draw(); 
}
/// <summary>
/// 座標取得関数
/// </summary>
/// <returns>プレイヤー座標</returns>
const VECTOR& Character::GetPos()
{
    return vPosition_;
}
/// <summary>
/// 敵の真上に足元が着地したときの衝突関数
/// </summary>
/// <param name="bhit"> true : 衝突   false : 非衝突</param>
void Character::SetHitEnemy(bool bhit)
{
	bHitEnemy_ = bhit;
}
/// <summary>
/// 敵と衝突時のダメージ関数
/// </summary>
/// <param name="bdamage"> true : ダメージを受ける  false : ダメージを受けない</param>
void Character::SetHitDamage(bool bdamage)
{
	bDamage_ = bdamage;
}
/// <summary>
/// プレイヤーの側面と敵の衝突判定
/// </summary>
/// <param name="bdamage">true : 衝突  false : 非衝突</param>
void Character::SetHitLeftDamage(bool bdamage)
{
	bLeftDamage_ = bdamage;
}
/// <summary>
/// プレイヤーの側面と敵の衝突判定
/// </summary>
/// <param name="bdamage">true : 衝突　false : 非衝突</param>
void Character::SetHitRightDamage(bool bdamage)
{
	bRightDamage_ = bdamage;
}
/// <summary>
/// プレイヤーの残りHP取得関数
/// </summary>
/// <returns>残りHP</returns>
const int& Character::GetCharacterLife()
{
	return nLife_;
}


