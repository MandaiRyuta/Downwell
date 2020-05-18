#include "CharacterAttack.h"
#include "../Input/Input.h"
#include "../DownwellConstant.h"
#include "../Collision/MapHitCheck.h"
#include "../Camera/Camera.h"
#include <random>

int CharacterAttack::nBullet_ = 0;	//弾の数
/// <summary>
/// 攻撃開始する関数
/// </summary>
/// <param name="vpos">座標</param>
/// <param name="bJump">ジャンプフラグ</param>
/// <param name="bAttackjump">攻撃ジャンプフラグ</param>
/// <param name="nstate">行動ステート</param>
/// <param name="fgravity">重力</param>
/// <param name="bshake">振動フラグ</param>
void CharacterAttack::Attack(VECTOR& vpos, const bool& bJump, const bool& bAttackjump, int& nstate, float& fgravity, bool& bshake)
{
	Camera::GetInstance().SetShake(false);
	bshake = false;
	if (nBullet_ <= 0)
	{
		nSideAttackFrame_ = 0;
	}

	if (Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001)
	{
		nSideAttackFrame_++;
	}

	if (nstate == 0 && !bJump && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x000)
	{
		nstate = 1;
	}

 	if (nstate == 1 && !bJump && bAttackjump && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001 && nBullet_ > 0)
	{
       	if (MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 8.0f), 0.0f)) == 0 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 8.0f), 0.0f)) == 0)
		{
			if (nAttackFrame_ % 5 == 0)
			{
				fgravity += 0.4f;
				nBullet_--;
				cBullet_.Create(vpos);
				Camera::GetInstance().SetShake(true);
			}
			if (nAttackFrame_ % 2 == 0)
			{
				bshake = true;
			}
			nAttackFrame_++;
		}
	}
	
	if(nSideAttackFrame_ > 10 && Input::GetInstance().GetKeyPress(KEY_INPUT_SPACE) == 0x001 && nBullet_ > 0)
	{
		if (MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 8.0f), 0.0f)) == 0 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 8.0f), 0.0f)) == 0)
		{
			if (nAttackFrame_ % 5 == 0)
			{
				fgravity += 0.4f;
				nBullet_--;
				cBullet_.Create(vpos);
				Camera::GetInstance().SetShake(true);
			}
			if (nAttackFrame_ % 2 == 0)
			{
				bshake = true;
			}
			nAttackFrame_++;
		}
	}

	cBullet_.Update();
}
/// <summary>
/// 描画関数
/// </summary>
void CharacterAttack::Draw()
{
	cBullet_.Draw();
}
/// <summary>
/// 攻撃フラグ設定関数
/// </summary>
/// <param name="battack">攻撃フラグ　true : 攻撃する　false : 攻撃しない </param>
void CharacterAttack::SetAttackExist(bool battack)
{
	bAttack_ = battack;
}
/// <summary>
/// 弾補充関数
/// </summary>
/// <param name="nbullet">補充する弾の量</param>
void CharacterAttack::SetBullet(int nbullet)
{
	nBullet_ = nbullet;
}
/// <summary>
/// 弾の残弾数を受け取る関数
/// </summary>
/// <returns>弾の残弾数</returns>
const int& CharacterAttack::GetBullet()
{
	return nBullet_;
}
