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
	/// <summary>
	/// 左右の加速移動関数
	/// </summary>
	/// <param name="vPosition">座標</param>
	/// <param name="fSpeedx">X座標の移動量</param>
	void SideAcceleration(VECTOR& vPosition, float fSpeedx);
	/// <summary>
	/// 左右移動関数
	/// </summary>
	/// <param name="vPosition">プレイヤー座標</param>
	/// <param name="fSpeedx">X座標の移動量</param>
	/// <param name="fSpeedy">Y座標の移動量</param>
	/// <param name="fGravityPower">重力</param>
	/// <param name="fSize">画像サイズ</param>
	void SideMove(VECTOR& vPosition, float& fSpeedx, float& fSpeedy, float& fGravityPower, float fSize);
private:
	VECTOR vSpeed;	//移動量
	int nSideType_;	//左右移動判断
	unsigned int unLeftAcceleration_;	//左移動加速量
	unsigned int unRightAcceleration_;	//右移動加速量
	int nMoveFrame_;	//移動フレーム
};