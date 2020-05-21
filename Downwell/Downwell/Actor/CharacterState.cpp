#include "CharacterState.h"
#include "../Input/Input.h"
#include "../DownwellConstant.h"
#include "../Collision/MapHitCheck.h"
#include "../Camera/Camera.h"
#include <random>

int CharacterState::nBullet_ = 10;
/// <summary>
/// 攻撃開始する関数
/// </summary>
/// <param name="vpos">座標</param>
/// <param name="bJump">ジャンプフラグ</param>
/// <param name="bAttackjump">攻撃ジャンプフラグ</param>
/// <param name="nstate">行動ステート</param>
/// <param name="fgravity">重力</param>
/// <param name="bshake">振動フラグ</param>
void CharacterState::Attack(VECTOR& vpos, bool& bJump, int& nstate, float& fgravity, bool& bshake, bool& bAttackJump)
{
	Camera::GetInstance().SetShake(false);

	bshake = false;
	
	if (MapHitChecker::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 1 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 1 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitChecker::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 2 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 2 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitChecker::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 3 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 3 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitChecker::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 4 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 4 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitChecker::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 5 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitChecker::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 5 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 && bJump)
	{
		nstate = 0;
		bJump = false;
		bAttackJump = false;
		nAttackFrame_ = 0;
		nBullet_ = 10;
	}
	
	if (nstate == 1 && bJump && !bAttackJump && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001)
	{
		if (MapHitChecker::GetChipParam(VGet(vpos.x, vpos.y - 9.0f, 0.0f)) == 1 ||
			MapHitChecker::GetChipParam(VGet(vpos.x, vpos.y - 9.0f, 0.0f)) == 2 ||
			MapHitChecker::GetChipParam(VGet(vpos.x, vpos.y - 9.0f, 0.0f)) == 3 ||
			MapHitChecker::GetChipParam(VGet(vpos.x, vpos.y - 9.0f, 0.0f)) == 4 ||
			MapHitChecker::GetChipParam(VGet(vpos.x, vpos.y - 9.0f, 0.0f)) == 5)
		{
			bAttackJump = false;
			nAttackFrame_ = 0;
			nBullet_ = 10;
		}
		if (nBullet_ <= 0)
		{
			nAttackFrame_ = 0;
			nstate = 2;
		}
		if (nAttackFrame_ > 3)
		{
			if (nAttackFrame_ % nGravityFrame == 0)
			{
				fgravity += 0.25f;
				cBullet_.Create(vpos);
				nBullet_--;
				Camera::GetInstance().SetShake(true);
			}
		}

		nAttackFrame_++;
	}
 
	if (nstate == 0 && !bJump && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x001)
	{
		nstate = 1;
		fgravity += fJump_v0;
		bJump = true;
	}
}
/// <summary>
/// 更新関数
/// </summary>
void CharacterState::Update()
{
	cBullet_.Update();
}
/// <summary>
/// 描画関数
/// </summary>
void CharacterState::Draw()
{
	cBullet_.Draw();
}
/// <summary>
/// 攻撃フラグ設定関数
/// </summary>
/// <param name="battack">攻撃フラグ　true : 攻撃する　false : 攻撃しない </param>
void CharacterState::SetAttackExist(bool battack)
{
	bAttack_ = battack;
}
/// <summary>
/// 弾補充関数
/// </summary>
/// <param name="nbullet">補充する弾の量</param>
void CharacterState::SetBullet(int nbullet)
{
	nBullet_ = nbullet;
}
/// <summary>
/// 弾の残弾数を受け取る関数
/// </summary>
/// <returns>弾の残弾数</returns>
const int& CharacterState::GetBullet()
{
	return nBullet_;
}
