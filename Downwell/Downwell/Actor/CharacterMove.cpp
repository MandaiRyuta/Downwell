#include "CharacterMove.h"
#include "../Input/Input.h"
#include "../Collision/MapHitCheck.h"
#include "CharacterAttack.h"
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
		if (unLeftAcceleration_ == -1)
		{
			unLeftAcceleration_ = 0;
		}
		else if (nMoveFrame_ > 3 && unLeftAcceleration_ == 0)
		{
			unLeftAcceleration_ = 1;
			nMoveFrame_ = 0;
		}
		break;
	case 1:
		if (unRightAcceleration_ == -1)
		{
			unRightAcceleration_ = 0;
		}
		if (nMoveFrame_ > 3 && unRightAcceleration_ == 0)
		{
			unRightAcceleration_ = 1;
			nMoveFrame_ = 0;
		}
		break;
	default:
		break;
	}

	//指定の左座標＋画像の幅の半分
	if (vPos.x > 150 + 25)
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
	if (vPos.x < 505)
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
		nSideType_ = 0;
		if (unLeftAcceleration_ == 0) fspeedx = -1.0f;
		if (unLeftAcceleration_ == 1) fspeedx = -3.0f;
		nMoveFrame_++;
	}
	else if (!Input::GetInstance().GetKeyPress(KEY_INPUT_LEFT))
	{
		unLeftAcceleration_ = -1;
	}
	if (Input::GetInstance().GetKeyPress(KEY_INPUT_RIGHT))
	{
		nSideType_ = 1;
		if (unRightAcceleration_ == 0) fspeedx = 1.0f;
		if (unRightAcceleration_ == 1) fspeedx = 3.0f;
		nMoveFrame_++;
	}
	else if (!Input::GetInstance().GetKeyPress(KEY_INPUT_RIGHT))
	{
		unRightAcceleration_ = -1;
	}

	if (!Input::GetInstance().GetKeyPress(KEY_INPUT_LEFT) && !Input::GetInstance().GetKeyPress(KEY_INPUT_RIGHT))
	{
		fspeedx = 0.0f;
		nMoveFrame_ = 0;
	}

	float halfsize;
	float dammy = 0.0f;
	halfsize = fsize * 0.5f;
	
	{
		if (MapHitCheck::MapHitCollision(VGet(vposition.x - halfsize, vposition.y + halfsize, 0.0f), dammy, fspeedy) == 3)
		{
			fgravitypower = 0.0f;
		}
		if (MapHitCheck::MapHitCollision(VGet(vposition.x + halfsize, vposition.y + halfsize, 0.0f), dammy, fspeedy) == 3)
		{
			fgravitypower = 0.0f;
		}
		if (MapHitCheck::MapHitCollision(VGet(vposition.x - halfsize, vposition.y - halfsize, 0.0f), dammy, fspeedy) == 4)
		{
			fgravitypower = 0.0f;
			fspeedy = 0.0f;
			CharacterAttack::SetBullet(10);
		}
		if (MapHitCheck::MapHitCollision(VGet(vposition.x + halfsize, vposition.y - halfsize, 0.0f), dammy, fspeedy) == 4)
		{
			fgravitypower = 0.0f;
			fspeedy = 0.0f;
			CharacterAttack::SetBullet(10);
		}
	}

	{
		MapHitCheck::MapHitCollision(VGet(vposition.x - halfsize, vposition.y + halfsize, 0.0f), fspeedx, dammy);
		MapHitCheck::MapHitCollision(VGet(vposition.x + halfsize, vposition.y + halfsize, 0.0f), fspeedx, dammy);
		MapHitCheck::MapHitCollision(VGet(vposition.x - halfsize, vposition.y - halfsize, 0.0f), fspeedx, dammy);
		MapHitCheck::MapHitCollision(VGet(vposition.x + halfsize, vposition.y - halfsize, 0.0f), fspeedx, dammy);
	
		SideAcceleration(vposition, fspeedx);
	}
}
