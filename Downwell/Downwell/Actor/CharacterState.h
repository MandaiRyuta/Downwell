#pragma once
#include "../Constant.h"
#include "Bullet.h"
#include "../DownwellConstant.h"

class CharacterState
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	CharacterState() :
		bAttack_(bInitAttack), nAttackFrame_(nInitAttackFrame), nSideAttackFrame_(nInitSideAttackFrame), bAttackJump_(false) 
	{
		nBullet_ = nBulletMaxCount;
	}
	/// <summary>
	/// デストラクター
	/// </summary>
	~CharacterState() {}
	/// <summary>
	/// 攻撃開始する関数
	/// </summary>
	/// <param name="vPosition">座標</param>
	/// <param name="bJump">ジャンプフラグ</param>
	/// <param name="bAttackjump">攻撃ジャンプフラグ</param>
	/// <param name="nState">行動ステート</param>
	/// <param name="fGravity">重力</param>
	/// <param name="bShake">振動フラグ</param>
	void Attack(VECTOR& vPosition, bool& bJump, int& nState, float& fGravity, bool& bShake, bool& bAttackJump);
	/// <summary>
	/// 更新関数
	/// </summary>
	void Update();
	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();
	/// <summary>
	/// 攻撃フラグ設定関数
	/// </summary>
	/// <param name="bAttack">攻撃フラグ　true : 攻撃する　false : 攻撃しない </param>
	void SetAttackExist(bool bAttack);
	/// <summary>
	/// 弾補充関数
	/// </summary>
	/// <param name="nBullet">補充する弾の量</param>
	static void SetBullet(int nBullet);
	/// <summary>
	/// 弾の残弾数を受け取る関数
	/// </summary>
	/// <returns>弾の残弾数</returns>
	static const int& GetBullet();
private:
	bool bAttack_; //攻撃フラグ
	int nAttackFrame_;	//攻撃中のフレーム
	int nSideAttackFrame_;	//着地状態で左右の端から真下に攻撃する際にキー入力を受け取るようにするフレーム
	bool bAttackJump_;
	static int nBullet_; //弾の数
	Bullet cBullet_;	//弾クラス
};