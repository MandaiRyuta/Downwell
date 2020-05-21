#include "CharacterMove.h"
#include "../Input/Input.h"
#include "../Collision/MapHitCheck.h"
#include "CharacterState.h"
/// <summary>
/// 左右の加速移動関数
/// </summary>
/// <param name="vPos">座標</param>
/// <param name="fspeedx">X座標の移動量</param>
void CharacterMove::SideAcceleration(VECTOR& vPos, float fspeedx)
{

	switch (nSideType_)
	{
	case 0:
		if (unLeftAcceleration_ == nInitLeftAcceleration)
		{
			unLeftAcceleration_ = nFirstAcceleration;
		}
		else if (nMoveFrame_ > nMaxMoveFrame&& unLeftAcceleration_ == nFirstAcceleration)
		{
			unLeftAcceleration_ = nSecondAcceleration;
			nMoveFrame_ = nInitMoveFrame;
		}
		break;
	case 1:
		if (unRightAcceleration_ == nInitRightAcceleration)
		{
			unRightAcceleration_ = nFirstAcceleration;
		}
		if (nMoveFrame_ > nMaxMoveFrame && unRightAcceleration_ == nFirstAcceleration)
		{
			unRightAcceleration_ = nSecondAcceleration;
			nMoveFrame_ = nInitMoveFrame;
		}
		break;
	default:
		break;
	}

	//指定の左座標＋画像の幅の半分
	if (vPos.x > nGameLeftLine)
	{
		switch (unLeftAcceleration_)
		{
		case 0:
			vPos.x += fspeedx;
			break;
		case 1:
			vPos.x += fspeedx;
			break;
		default:
			break;
		}
	}

	//指定の右座標＋画像の幅の半分
	if (vPos.x < nGameRightLine)
	{
		switch (unRightAcceleration_)
		{
		case 0:
			vPos.x += fspeedx;
			break;
		case 1:
			vPos.x += fspeedx;
			break;
		default:
			break;
		}
	}


}
/// <summary>
/// 左右移動関数
/// </summary>
/// <param name="vposition">プレイヤー座標</param>
/// <param name="fspeedx">X座標の移動量</param>
/// <param name="fspeedy">Y座標の移動量</param>
/// <param name="fgravitypower">重力</param>
/// <param name="fsize">画像サイズ</param>
void CharacterMove::SideMove(VECTOR& vposition, float& fspeedx, float& fspeedy, float& fgravitypower, float fsize)
{

	if (Input::GetInstance().GetKeyPress(KEY_INPUT_LEFT))
	{
		nSideType_ = nLeftType;
		if (unLeftAcceleration_ == nFirstAcceleration) fspeedx = -fFirstAccelerationSpeed;
		if (unLeftAcceleration_ == nSecondAcceleration) fspeedx = -fSecondAccelerationSpeed;
		nMoveFrame_++;
	}
	else if (!Input::GetInstance().GetKeyPress(KEY_INPUT_LEFT))
	{
		unLeftAcceleration_ = nInitLeftAcceleration;
	}
	if (Input::GetInstance().GetKeyPress(KEY_INPUT_RIGHT))
	{
		nSideType_ = nRightType;
		if (unRightAcceleration_ == nFirstAcceleration) fspeedx = fFirstAccelerationSpeed;
		if (unRightAcceleration_ == nSecondAcceleration) fspeedx = fSecondAccelerationSpeed;
		nMoveFrame_++;
	}
	else if (!Input::GetInstance().GetKeyPress(KEY_INPUT_RIGHT))
	{
		unRightAcceleration_ = nInitRightAcceleration;
	}

	if (!Input::GetInstance().GetKeyPress(KEY_INPUT_LEFT) && !Input::GetInstance().GetKeyPress(KEY_INPUT_RIGHT))
	{
		fspeedx = fNonSpeed;
		nMoveFrame_ = nInitMoveFrame;
	}

	float halfsize;
	float dammy = 0.0f;
	halfsize = fsize * 0.5f;
	
	{
		if (MapHitChecker::MapHitCollision(VGet(vposition.x - halfsize, vposition.y + halfsize, 0.0f), dammy, fspeedy) == 3)
		{
			fgravitypower = fNonGravity;
			fspeedy = 0.0f;
		}
		if (MapHitChecker::MapHitCollision(VGet(vposition.x + halfsize, vposition.y + halfsize, 0.0f), dammy, fspeedy) == 3)
		{
			fgravitypower = fNonGravity;
			fspeedy = 0.0f;
		}
		if (MapHitChecker::MapHitCollision(VGet(vposition.x - halfsize, vposition.y - halfsize, 0.0f), dammy, fspeedy) == 4)
		{
			fgravitypower = fNonGravity;
			fspeedy = 0.0f;
			CharacterState::SetBullet(nBulletMaxCount);
		}
		if (MapHitChecker::MapHitCollision(VGet(vposition.x + halfsize, vposition.y - halfsize, 0.0f), dammy, fspeedy) == 4)
		{
			fgravitypower = fNonGravity;
			fspeedy = 0.0f;
			CharacterState::SetBullet(nBulletMaxCount);
		}
	}

	{
		MapHitChecker::MapHitCollision(VGet(vposition.x - halfsize, vposition.y + halfsize, 0.0f), fspeedx, dammy);
		MapHitChecker::MapHitCollision(VGet(vposition.x + halfsize, vposition.y + halfsize, 0.0f), fspeedx, dammy);
		MapHitChecker::MapHitCollision(VGet(vposition.x - halfsize, vposition.y - halfsize, 0.0f), fspeedx, dammy);
		MapHitChecker::MapHitCollision(VGet(vposition.x + halfsize, vposition.y - halfsize, 0.0f), fspeedx, dammy);
	
		SideAcceleration(vposition, fspeedx);
	}
}
