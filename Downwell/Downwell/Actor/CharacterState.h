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
public:
	/// <summary>
	/// 攻撃開始する関数
	/// </summary>
	/// <param name="vpos">座標</param>
	/// <param name="bJump">ジャンプフラグ</param>
	/// <param name="bAttackjump">攻撃ジャンプフラグ</param>
	/// <param name="nstate">行動ステート</param>
	/// <param name="fgravity">重力</param>
	/// <param name="bshake">振動フラグ</param>
	void Attack(VECTOR& vpos, bool& bJump, int& nstate, float& fgravity, bool& bshake, bool& bAttackJump);
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
	/// <param name="battack">攻撃フラグ　true : 攻撃する　false : 攻撃しない </param>
	void SetAttackExist(bool battack);
	/// <summary>
	/// 弾補充関数
	/// </summary>
	/// <param name="nbullet">補充する弾の量</param>
	static void SetBullet(int nbullet);
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