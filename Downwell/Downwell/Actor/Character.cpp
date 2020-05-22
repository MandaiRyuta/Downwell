#include "Character.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"
#include "Stage.h"
#include "EnemyParameter.h"
#include "CharacterState.h"
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
Character::Character(int nSceneNumber) : nNowScene_(nSceneNumber), vSpeed_(VGet(fDefaultPos,fDefaultPos,fDefaultPos)), fJumpPower_(0.0f)
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
	bDamage_ = false;
	bJump_ = false;
	bAttackJump_ = false;
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
		if (MapHitChecker::GetChipParam(VGet(vPosition_.x + 8, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false ||
			MapHitChecker::GetChipParam(VGet(vPosition_.x - 8, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false)
		{
			LevelsResponsible::GetInstance().SetNowLevel(1);
			LevelsResponsible::GetInstance().SetChangeLevel(true);
		}

		if (MapHitChecker::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 98 && LevelsResponsible::GetInstance().GetNextStageExist() == true ||
			MapHitChecker::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 98 && LevelsResponsible::GetInstance().GetNextStageExist() == true)
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
		if (nLife_ <= 0)
		{
			LevelsResponsible::GetInstance().SetLevelState(true);
			LevelsResponsible::GetInstance().SetNowLevel(2);
			LevelsResponsible::GetInstance().SetChangeLevel(true);
		}
		if (MapHitChecker::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 98 && LevelsResponsible::GetInstance().GetNextStageExist() == true)
		{
			LevelsResponsible::GetInstance().SetNextStage(false);
		}
		else if (MapHitChecker::GetChipParam(VGet(vPosition_.x, vPosition_.y, 0.0f)) == 99 && LevelsResponsible::GetInstance().GetNextStageExist() == false)
		{
			LevelsResponsible::GetInstance().NextStage();
		}
	}

	if (nNowScene_ == nGameLevel)
	{
		if (bInvincible_)
		{
			if (bLeftDamage_)
			{
				if (nHitCooltime_ > 200)
				{
					bLeftDamage_ = false;
					bInvincible_ = false;
					nHitCooltime_ = 0;
				}
				nHitCooltime_++;
			}
			if (bRightDamage_)
			{
				if (nHitCooltime_ > 200)
				{
					bRightDamage_ = false;
					bInvincible_ = false;
					nHitCooltime_ = 0;
				}
				nHitCooltime_++;
			}
		}
		if (fGravity_ > -10.0f)
		{
			fGravity_ += fGravity;
		}

		vSpeed_.y = fGravity_;

		//if (bPlayershake_)
		//{
		//	vSpeed_.y = vSpeed_.y + (fPlayershake_ * -1.0f);
		//}

		if(bHitEnemy_)
		{
			vSpeed_.y += 20.0f;
			bHitEnemy_ = false;
		}

		float hitmove = 5.0f;
		float dammy = 0.0f;
		MapHitChecker::MapHitCollision(VGet(vPosition_.x - 8.0f, vPosition_.y + 8.0f, 0.0f), hitmove, dammy, 1);
		MapHitChecker::MapHitCollision(VGet(vPosition_.x + 8.0f, vPosition_.y + 8.0f, 0.0f), hitmove, dammy, 1);
		MapHitChecker::MapHitCollision(VGet(vPosition_.x - 8.0f, vPosition_.y - 8.0f, 0.0f), hitmove, dammy, 1);
		MapHitChecker::MapHitCollision(VGet(vPosition_.x + 8.0f, vPosition_.y - 8.0f, 0.0f), hitmove, dammy, 1);

		if (bLeftDamage_ && !bInvincible_)
		{
			nHitCooltime_ = 0;
			nLife_ -= 1;
			vPosition_.y += 1;
			vPosition_.x += hitmove;
			bInvincible_ = true;
		}
		if (bRightDamage_ && !bInvincible_)
		{
			nHitCooltime_ = 0;
			nLife_ -= 1;
			vPosition_.y += 1.0f;
			vPosition_.x -= hitmove;
			bInvincible_ = true;
		}

		MoveState_.SideMove(vPosition_,vSpeed_.x,vSpeed_.y, fGravity_, fSize_);
		CharacterState_.Attack(vPosition_, bJump_, nCharacterActionState_, fGravity_, bPlayershake_, bAttackJump_);
		CharacterState_.Update();
		vPosition_.y += vSpeed_.y;
	}
	else if (nNowScene_ == nTitleLevel)
	{

		if (fGravity_ > -10.0f)
		{
			fGravity_ += fGravity;
		}	
		vSpeed_.y = fGravity_;
		
		MoveState_.SideMove(vPosition_, vSpeed_.x, vSpeed_.y, fGravity_, fSize_);
		CharacterState_.Attack(vPosition_, bJump_, nCharacterActionState_, fGravity_, bPlayershake_, bAttackJump_);
		CharacterState_.Update();
		vPosition_.y += vSpeed_.y;
	}
}
/// <summary>
/// 描画関数
/// </summary>
void Character::Draw()
{
#ifdef DEBUG
	if (bJump_)
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "JumpON");
		DrawFormatString(100, 0, GetColor(255, 255, 255), "Speed.Y :  %f", vSpeed_.y);
	}
	else
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "JumpOFF");
		DrawFormatString(100, 0, GetColor(255, 255, 255), "Speed.Y :  %f", vSpeed_.y);
	}
#endif
	DrawBillboard3D(VGet(vPosition_.x, vPosition_.y, 0.0f), 0.5f, 0.5f, fSize_, 0, nTexhandle_,false);
	
	CharacterState_.Draw(); 
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
/// <param name="bHit"> true : 衝突   false : 非衝突</param>
void Character::SetHitEnemy(bool bHit)
{
	bHitEnemy_ = bHit;
}
/// <summary>
/// 敵と衝突時のダメージ関数
/// </summary>
/// <param name="bDamage"> true : ダメージを受ける  false : ダメージを受けない</param>
void Character::SetHitDamage(bool bDamage)
{
	bDamage_ = bDamage;
}

/// <summary>
/// 左のダメージ判定取得関数
/// </summary>
/// <returns>左側のダメージ判定フラグ</returns>
const bool Character::GetLeftDamageExist()
{
	return bLeftDamage_;
}
/// <summary>
/// 右のダメージ判定取得関数
/// </summary>
/// <returns>右側のダメージ判定フラグ</returns>
const bool Character::GetRightDamageExist()
{
	return bRightDamage_;
}
/// <summary>
/// プレイヤーの側面と敵の衝突判定
/// </summary>
/// <param name="bDamage">true : 衝突  false : 非衝突</param>
void Character::SetHitLeftDamage(bool bDamage)
{
	bLeftDamage_ = bDamage;
}
/// <summary>
/// プレイヤーの側面と敵の衝突判定
/// </summary>
/// <param name="bDamage">true : 衝突　false : 非衝突</param>
void Character::SetHitRightDamage(bool bDamage)
{
	bRightDamage_ = bDamage;
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
