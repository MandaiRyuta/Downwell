#include "CharacterJump.h"
#include "../Input/Input.h"
#include "../Collision/MapHitCheck.h"
#include "CharacterAttack.h"

bool CharacterJump::bJump = false;	//ジャンプフラグ
/// <summary>
/// 更新関数
/// </summary>
void CharacterJump::JumpUpdate()
{
	if (CharacterAttack::GetBullet() <= 0)
	{
		bBulletJump_ = false;
	}
}
/// <summary>
/// ジャンプステート関数
/// </summary>
/// <param name="vpos">プレイヤー座標</param>
/// <param name="vspeed">プレイヤー移動量</param>
/// <param name="fgravity">重力</param>
/// <param name="nstate">行動ステート</param>
void CharacterJump::JumpState(VECTOR& vpos, VECTOR& vspeed, float& fgravity, int& nstate)
{
	if (MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 1 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 1 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 2 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 2 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 3 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 3 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 4 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 4 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 ||
		MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 5 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 5 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000)
	{
		bJump = true;
		CharacterAttack::SetBullet(10);
		bBulletJump_ = false;
	}
	else if(MapHitCheck::GetChipParam(VGet(vpos.x - 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 0 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000 || MapHitCheck::GetChipParam(VGet(vpos.x + 16 * 0.5f, vpos.y - (16 * 0.5f + 1.0f), 0.0f)) == 0 && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x000)
	{
		bJump = false;
	}

	if (bJump && Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x001)
	{
		nstate = 0;
		bBulletJump_ = true;
		fgravity = fJump_v0;
		bJump = false;
	}
}
/// <summary>
/// ジャンプフラグ取得関数
/// </summary>
/// <returns>ジャンプフラグ true : ジャンプしている		false : ジャンプしていない</returns>
const bool& CharacterJump::GetJumpExist()
{
	return bJump;
}
/// <summary>
/// ジャンプフラグ設定関数
/// </summary>
/// <param name="bjump">ジャンプフラグ　true : ジャンプする		false : ジャンプしない</param>
void CharacterJump::SetJumpExist(bool bjump)
{
	bJump = bjump;
}
/// <summary>
/// 攻撃ジャンプフラグ取得関数
/// </summary>
/// <returns>攻撃ジャンプフラグ取得　true : 攻撃ジャンプしている	false : 攻撃ジャンプしていない</returns>
const bool& CharacterJump::GetBulletJumpExist()
{
	return bBulletJump_;
}
/// <summary>
/// 攻撃ジャンプフラグ設定関数
/// </summary>
/// <param name="bjump"> true : 攻撃ジャンプする	false : 攻撃ジャンプしない</param>
void CharacterJump::SetBulletJumpExist(bool bbulletjump)
{
	bBulletJump_ = bbulletjump;
}



