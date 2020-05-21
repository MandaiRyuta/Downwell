#pragma once
#include "Actor.h"
#include "../Constant.h"
#include "CharacterMove.h"
#include "CharacterState.h"

class Character : public Actor
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	/// <param name="nscenenumber">シーン番号</param>
	Character(int nscenenumber);
	/// <summary>
	/// デストラクター
	/// </summary>
	~Character();
public:
	/// <summary>
	/// 更新関数
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// 座標取得関数
	/// </summary>
	/// <returns>プレイヤー座標</returns>
	static const VECTOR& GetPos();
	/// <summary>
	/// 敵の真上に足元が着地したときの衝突関数
	/// </summary>
	/// <param name="bhit"> true : 衝突   false : 非衝突</param>
	static void SetHitEnemy(bool bhit);
	/// <summary>
	/// 敵と衝突時のダメージ関数
	/// </summary>
	/// <param name="bdamage"> true : ダメージを受ける  false : ダメージを受けない</param>
	static void SetHitDamage(bool bdamage);
	/// <summary>
	/// 左のダメージ判定取得関数
	/// </summary>
	/// <returns>左側のダメージ判定フラグ</returns>
	static const bool GetLeftDamageExist();
	/// <summary>
	/// 右のダメージ判定取得関数
	/// </summary>
	/// <returns>右側のダメージ判定フラグ</returns>
	static const bool GetRightDamageExist();
	/// <summary>
	/// プレイヤーの側面と敵の衝突判定
	/// </summary>
	/// <param name="bdamage">true : 衝突  false : 非衝突</param>
	static void SetHitLeftDamage(bool bdamage);
	/// <summary>
	/// プレイヤーの側面と敵の衝突判定
	/// </summary>
	/// <param name="bdamage">true : 衝突　false : 非衝突</param>
	static void SetHitRightDamage(bool bdamage);
	/// <summary>
	/// プレイヤーの残りHP取得関数
	/// </summary>
	/// <returns>残りHP</returns>
	static const int& GetCharacterLife();

	/// <summary>
	/// ジャンプフラグ取得関数
	/// </summary>
	/// <returns>ジャンプフラグ true : ジャンプしている		false : ジャンプしていない</returns>
	static const bool& GetJumpExist();
private:
	float fJumpPower_;	//ジャンプ力
	int nNowScene_;	//現在の表示シーン番号
	static int nLife_;	//プレイヤーHP
	int nCharacterActionState_;	//キャラクター行動ステート
	int nTexhandle_;	//テクスチャーハンドル
	static VECTOR vPosition_;	//プレイヤー座標
	float fSize_;	//画像の大きさ
	CharacterState CharacterState_;	//攻撃ステートクラス
	CharacterMove MoveState_;	//移動ステートクラス
	VECTOR vSpeed_;	//移動量
	VECTOR vOldPosition_;	//1フレーム前の座標
	float fGravity_;	//重力
	float fPlayershake_;	//振動力
	bool bPlayershake_;	//振動フラグ
	static bool bHitEnemy_;	//プレイヤーの足元が敵の真上着地した際のフラグ
	static bool bLeftDamage_;	//プレイヤーの左側面が敵に衝突した際のフラグ
	static bool bRightDamage_;	//プレイヤーの右側面が敵に衝突した際のフラグ
	static bool bDamage_;	//ダメージフラグ
	int nHitCooltime_;	//衝突してからのプレイヤー無敵時間用の変数
	bool bInvincible_;	//プレイヤーの無敵状態フラグ
	static bool bJump_;	//ジャンプフラグ
	bool bAttackJump_;	//攻撃中のジャンプフラグ
};