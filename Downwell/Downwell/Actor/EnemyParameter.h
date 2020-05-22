#pragma once
#include "../Constant.h"
#include "../DownwellConstant.h"
class EnemyParameter
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	EnemyParameter();
	/// <summary>
	/// デストラクター
	/// </summary>
	virtual ~EnemyParameter() {};
	/// <summary>
	/// 更新関数
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 描画関数
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// 敵のHP取得関数
	/// </summary>
	/// <returns>敵のHP</returns>
	const int& GetHp()
	{
		return nHp_;
	}
	/// <summary>
	/// 敵の最大HP取得関数
	/// </summary>
	/// <returns>敵の最大HP</returns>
	const int& GetMaxHp()
	{
		return nMaxHp_;
	}
	/// <summary>
	/// 敵の座標取得関数
	/// </summary>
	/// <returns>敵の現在の座標</returns>
	const VECTOR& GetPosition()
	{
		return vPosition_;
	}
	/// <summary>
	/// 敵の座標を設定する関数
	/// </summary>
	/// <param name="vPosition">指定座標</param>
	void SetPosition(VECTOR vPosition)
	{
		vPosition_.x = vPosition.x;
		vPosition_.y = vPosition.y;
		vPosition_.z = vPosition.z;
	}
	/// <summary>
	/// 敵の移動関数
	/// </summary>
	/// <param name="vMove">移動量</param>
	void MovePosition(VECTOR vMove)
	{
		vMove_.x = vMove.x;
		vMove_.y = vMove.y;
		vMove_.z = vMove.z;
	}
	/// <summary>
	/// 敵のY座標移動関数
	/// </summary>
	/// <param name="fMovey">Y座標の移動量</param>
	void AddMovePositionY(float fMovey)
	{
		vMove_.y += fMovey;
	}
	/// <summary>
	/// 敵のX座標移動関数
	/// </summary>
	/// <param name="fMovex">X座標の移動量</param>
	void AddMovePositionX(float fMovex)
	{
		vMove_.x += fMovex;
	}
	/// <summary>
	/// 敵の移動種類指定関数
	/// </summary>
	/// <param name="nType">移動種類</param>
	void SetMoveType(int nType)
	{
		nMoveType_ = nType;
	}
	/// <summary>
	/// 敵の移動情報取得関数
	/// </summary>
	/// <returns>指定した移動種類</returns>
	const int& GetMoveType()
	{
		return nMoveType_;
	}
	/// <summary>
	/// 敵の衝突関数
	/// </summary>
	/// <param name="bBottomtouch">true : 着地	false : 着地していない</param>
	void SetBottomTouch(bool bBottomtouch)
	{
		bBottomtouch_ = bBottomtouch;
	}
	/// <summary>
	/// 敵の描画番号設定関数
	/// </summary>
	/// <param name="nNumber">描画番号</param>
	void SetEnemyNumber(int nNumber)
	{
		nEnemyNumber_ = nNumber;
	}
	/// <summary>
	/// 敵の描画番号取得関数
	/// </summary>
	/// <returns>指定した描画番号</returns>
	const int& GetEnemyNumber()
	{
		return nEnemyNumber_;
	}
	/// <summary>
	/// 敵の生存取得関数
	/// </summary>
	/// <returns>true : 生存している　false : 死んでいる</returns>
	const bool& GetbLifeExist()
	{
		return bLife_;
	}
	/// <summary>
	/// 敵の生存指定関数
	/// </summary>
	/// <param name="bLife">true : 生存している　false : 死んでいる</param>
	void SetbLife(bool bLife)
	{
		bLife_ = bLife;
	}
protected:
	bool bLife_;	//生存フラグ
	int nEnemyNumber_;	//敵の描画番号
	int nMoveType_;	//敵の移動種類
	int nHp_;	//敵のHP
	int nMaxHp_;	//敵の最大HP
	bool bBottomtouch_;	//敵の地面衝突フラグ
	VECTOR vPosition_;	//敵の座標
	VECTOR vMove_;	//敵の移動量
};