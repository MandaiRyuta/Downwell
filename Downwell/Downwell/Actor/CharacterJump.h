#pragma once

#include "../Constant.h"
#include "../DownwellConstant.h"

class CharacterJump
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	CharacterJump() : bBulletJump_(false) {}
	/// <summary>
	/// デストラクター
	/// </summary>
	~CharacterJump() {}
public:
	/// <summary>
	/// 更新関数
	/// </summary>
	void JumpUpdate();
	/// <summary>
	/// ジャンプステート関数
	/// </summary>
	/// <param name="vpos">プレイヤー座標</param>
	/// <param name="vspeed">プレイヤー移動量</param>
	/// <param name="fgravity">重力</param>
	/// <param name="nstate">行動ステート</param>
	void JumpState(VECTOR& vpos, VECTOR& vspeed, float& fgravity, int& nstate);
	/// <summary>
	/// ジャンプフラグ取得関数
	/// </summary>
	/// <returns>ジャンプフラグ true : ジャンプしている		false : ジャンプしていない</returns>
	static const bool& GetJumpExist();
	/// <summary>
	/// ジャンプフラグ設定関数
	/// </summary>
	/// <param name="bjump">ジャンプフラグ　true : ジャンプする		false : ジャンプしない</param>
	void SetJumpExist(bool bjump);
	/// <summary>
	/// 攻撃ジャンプフラグ取得関数
	/// </summary>
	/// <returns>攻撃ジャンプフラグ取得　true : 攻撃ジャンプしている	false : 攻撃ジャンプしていない</returns>
	const bool& GetBulletJumpExist();
	/// <summary>
	/// 攻撃ジャンプフラグ設定関数
	/// </summary>
	/// <param name="bjump"> true : 攻撃ジャンプする	false : 攻撃ジャンプしない</param>
	void SetBulletJumpExist(bool bjump);
private:
	static bool bJump;	//ジャンプフラグ
	bool bBulletJump_;	//攻撃ジャンプフラグ
};