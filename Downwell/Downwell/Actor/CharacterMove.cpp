#include "CharacterMove.h"
#include "../Input/Input.h"
#include "../Collision/MapHitCheck.h"
#include "CharacterState.h"
/// <summary>
/// ���E�̉����ړ��֐�
/// </summary>
/// <param name="vPos">���W</param>
/// <param name="fspeedx">X���W�̈ړ���</param>
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

	//�w��̍����W�{�摜�̕��̔���
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

	//�w��̉E���W�{�摜�̕��̔���
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
/// ���E�ړ��֐�
/// </summary>
/// <param name="vposition">�v���C���[���W</param>
/// <param name="fspeedx">X���W�̈ړ���</param>
/// <param name="fspeedy">Y���W�̈ړ���</param>
/// <param name="fgravitypower">�d��</param>
/// <param name="fsize">�摜�T�C�Y</param>
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
