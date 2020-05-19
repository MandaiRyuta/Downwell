#pragma once
#include "../Constant.h"
#include "../DownwellConstant.h"

class CharacterMove
{
public:
	/// <summary>
	/// コンストラクター
	/// </summary>
	CharacterMove() : vSpeed(VGet(fDefaultPos, fDefaultPos, fDefaultPos))
	{
		nSideType_ = nInitSideType;
		unLeftAcceleration_ = nInitLeftAcceleration;
		unRightAcceleration_ = nInitRightAcceleration;
		nMoveFrame_ = nInitMoveFrame;
	}
	/// <summary>
	/// デストラクター
	/// </summary>
	~CharacterMove() {}
public:
	/// <summary>
	/// 左右の加速移動関数
	/// </summary>
	/// <param name="vPos">座標</param>
	/// <param name="fspeedx">X座標の移動量</param>
	void SideAcceleration(VECTOR& vPos, float fspeedx);
	/// <summary>
	/// 左右移動関数
	/// </summary>
	/// <param name="vposition">プレイヤー座標</param>
	/// <param name="fspeedx">X座標の移動量</param>
	/// <param name="fspeedy">Y座標の移動量</param>
	/// <param name="fgravitypower">重力</param>
	/// <param name="fsize">画像サイズ</param>
	void SideMove(VECTOR& vposition, float& fspeedx, float& fspeedy, float& fgravitypower, float fsize);
private:
	VECTOR vSpeed;	//移動量
	int nSideType_;	//左右移動判断
	unsigned int unLeftAcceleration_;	//左移動加速量
	unsigned int unRightAcceleration_;	//右移動加速量
	int nMoveFrame_;	//移動フレーム
};