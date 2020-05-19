#include "Character.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"
#include "Stage.h"
#include "EnemyParameter.h"
#include "../Resource/TextureData.h"
#include "../Collision/MapHitCheck.h"
#include "../Level/LevelsResponsible.h"
#include "../DownwellConstant.h"
#include <random>

VECTOR Character::vPosition_ = VGet(fDefaultPos, fDefaultPos, fDefaultPos);	//プレイヤー座標
bool Character::bHitEnemy_ = bInitHitEnemy;	//プレイヤーの足元が敵の真上着地した際のフラグ
bool Character::bDamage_ = bInitDamage;	//ダメージフラグ
bool Character::bLeftDamage_ = bInitLeftDamage;	//プレイヤーの左側面が敵に衝突した際のフラグ
bool Character::bRightDamage_ = bInitRightDamage;	//プレイヤーの右側面が敵に衝突した際のフラグ
int Character::nLife_ = nCharacterLife;	//プレイヤーHP
bool Character::bJump_ = bInitCharacterJump;	//ジャンプの初期化
/// <summary>
/// コンストラクター
/// </summary>
/// <param name="nscenenumber">シーン番号</param>
Character::Character(int nscenenumber) : nNowScene_(nscenenumber)
{
	if (nNowScene_ == nTitleLevel)
	{
		vPosition_ = VGet(ScreenWidth / 2 - 150.0f, -300.0f, 0.0f);
		vOldPosition_ = VGet(ScreenWidth / 2 - 150.0f, -300.0f, 0.0f);
		nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetTitleTextureData(TextureDataBase::TitleTextureNumber::TPlayer);
	}
	if (nNowScene_ == nGameLevel)
	{
		vPosition_ = VGet(ScreenWidth / 2 + 18.0f, -700.0f, 0.0f);
		vOldPosition_ = VGet(ScreenWidth / 2 + 18.0f, -700.0f, 0.0f);
		nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GPlayer);
	}
	if (nNowScene_ == nResultLevel)
	{
		vPosition_ = VGet(ScreenWidth / 2 + 18.0f, -900.0f, 0.0f);
		vOldPosition_ = VGet(ScreenWidth / 2 + 18.0f, -900.0f, 0.0f);
		nTexhandle_ = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::RPlayer);
	}

	nLife_ = nCharacterLife;
	fSize_ = nCharacterSize;
	bPlayershake_ = bInitShake;
	fPlayershake_ = fCharacterShakePower;


	vSpeed_.x = fDefaultPos;
	vSpeed_.y = fDefaultPos;
	vSpeed_.z = fDefaultPos;

	bHitEnemy_ = bInitHitEnemy;
	bLeftDamage_ = bInitLeftDamage;
	bRightDamage_ = bInitRightDamage;
	fGravity_ = fInitGravity;
	nCharacterActionState_ = nInitCharacterActionState;
	nHitCooltime_ = nInitCharacterHitCoolTime;
	bInvincible_ = bInitInvincible;
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
	if (nNowScene_ == nTitleLevel)
	{
		if (MapHitChecker::GetChipParam(VGet(vPosition_.x + 8, vPosition_.y + 8, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false ||
			MapHitChecker::GetChipParam(VGet(vPosition_.x - 8, vPosition_.y - 8, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false)
		{
			LevelsResponsible::GetInstance().SetNowLevel(1);
			LevelsResponsible::GetInstance().SetChangeLevel(true);
		}

		if (MapHitChecker::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 0 && LevelsResponsible::GetInstance().GetNextStageExist() == true ||
			MapHitChecker::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 0 && LevelsResponsible::GetInstance().GetNextStageExist() == true)
		{
			LevelsResponsible::GetInstance().SetNextStage(false);
		}
		else if (MapHitChecker::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false ||
			MapHitChecker::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false)
		{
			LevelsResponsible::GetInstance().NextStage();
		}
	}
	if (nNowScene_ == nGameLevel)
	{
		if (MapHitChecker::GetChipParam(VGet(vPosition_.x + 8, vPosition_.y + 8, 0.0f)) == 18 || MapHitChecker::GetChipParam(VGet(vPosition_.x - 8, vPosition_.y - 8, 0.0f)) == 18)
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
		if (MapHitChecker::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 0 && LevelsResponsible::GetInstance().GetNextStageExist() == true ||
			MapHitChecker::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 0 && LevelsResponsible::GetInstance().GetNextStageExist() == true)
		{
			LevelsResponsible::GetInstance().SetNextStage(false);
		}
		else if (MapHitChecker::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false ||
			MapHitChecker::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false)
		{
			LevelsResponsible::GetInstance().NextStage();
		}
	}

	if (nNowScene_ == nTitleLevel || nNowScene_ == nGameLevel)
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
		AttackState_.Attack(vPosition_, bJump_, JumpState_.GetBulletJumpExist(), nCharacterActionState_, fGravity_, bPlayershake_);
		JumpState_.JumpState(vPosition_, vSpeed_, fGravity_, nCharacterActionState_, bJump_);

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

/// <summary>
/// ジャンプフラグ取得関数
/// </summary>
/// <returns>ジャンプフラグ true : ジャンプしている		false : ジャンプしていない</returns>
const bool& Character::GetJumpExist()
{
	return bJump_;
}
