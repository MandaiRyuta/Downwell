#include "CharacterMove.h"
#include "../Input/Input.h"
#include "../Collision/MapHitCheck.h"
#include "CharacterState.h"
/// <summary>
/// ���E�̉����ړ��֐�
/// </summary>
/// <param name="vPosition">���W</param>
/// <param name="fSpeedx">X���W�̈ړ���</param>
void CharacterMove::SideAcceleration(VECTOR& vPosition, float fSpeedx)
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
	if (vPosition.x > nGameLeftLine)
	{
		switch (unLeftAcceleration_)
		{
		case 0:
			vPosition.x += fSpeedx;
			break;
		case 1:
			vPosition.x += fSpeedx;
			break;
		default:
			break;
		}
	}

	//�w��̉E���W�{�摜�̕��̔���
	if (vPosition.x < nGameRightLine)
	{
		switch (unRightAcceleration_)
		{
		case 0:
			vPosition.x += fSpeedx;
			break;
		case 1:
			vPosition.x += fSpeedx;
			break;
		default:
			break;
		}
	}


}
/// <summary>
/// ���E�ړ��֐�
/// </summary>
/// <param name="vPosition">�v���C���[���W</param>
/// <param name="fSpeedx">X���W�̈ړ���</param>
/// <param name="fSpeedy">Y���W�̈ړ���</param>
/// <param name="fGravityPower">�d��</param>
/// <param name="fSize">�摜�T�C�Y</param>
void CharacterMove::SideMove(VECTOR& vPosition, float& fSpeedx, float& fSpeedy, float& fGravityPower, float fSize)
{

	if (Input::GetInstance().GetKeyPress(KEY_INPUT_LEFT))
	{
		nSideType_ = nLeftType;
		if (unLeftAcceleration_ == nFirstAcceleration) fSpeedx = -fFirstAccelerationSpeed;
		if (unLeftAcceleration_ == nSecondAcceleration) fSpeedx = -fSecondAccelerationSpeed;
		nMoveFrame_++;
	}
	else if (!Input::GetInstance().GetKeyPress(KEY_INPUT_LEFT))
	{
		unLeftAcceleration_ = nInitLeftAcceleration;
	}
	if (Input::GetInstance().GetKeyPress(KEY_INPUT_RIGHT))
	{
		nSideType_ = nRightType;
		if (unRightAcceleration_ == nFirstAcceleration) fSpeedx = fFirstAccelerationSpeed;
		if (unRightAcceleration_ == nSecondAcceleration) fSpeedx = fSecondAccelerationSpeed;
		nMoveFrame_++;
	}
	else if (!Input::GetInstance().GetKeyPress(KEY_INPUT_RIGHT))
	{
		unRightAcceleration_ = nInitRightAcceleration;
	}

	if (!Input::GetInstance().GetKeyPress(KEY_INPUT_LEFT) && !Input::GetInstance().GetKeyPress(KEY_INPUT_RIGHT))
	{
		fSpeedx = fNonSpeed;
		nMoveFrame_ = nInitMoveFrame;
	}

	float halfSize;
	float dammy = 0.0f;
	halfSize = fSize * 0.5f;
	
	{
		if (MapHitChecker::MapHitCollision(VGet(vPosition.x - halfSize, vPosition.y + halfSize, 0.0f), dammy, fSpeedy, 1) == 3)
		{
			fGravityPower = fNonGravity;
			fSpeedy = 0.0f;
		}
		if (MapHitChecker::MapHitCollision(VGet(vPosition.x + halfSize, vPosition.y + halfSize, 0.0f), dammy, fSpeedy, 1) == 3)
		{
			fGravityPower = fNonGravity;
			fSpeedy = 0.0f;
		}
		if (MapHitChecker::MapHitCollision(VGet(vPosition.x - halfSize, vPosition.y - halfSize, 0.0f), dammy, fSpeedy, 1) == 4)
		{
			fGravityPower = fNonGravity;
			fSpeedy = 0.0f;
			CharacterState::SetBullet(nBulletMaxCount);
		}
		if (MapHitChecker::MapHitCollision(VGet(vPosition.x + halfSize, vPosition.y - halfSize, 0.0f), dammy, fSpeedy, 1) == 4)
		{
			fGravityPower = fNonGravity;
			fSpeedy = 0.0f;
			CharacterState::SetBullet(nBulletMaxCount);
		}
	}

	{
		MapHitChecker::MapHitCollision(VGet(vPosition.x - halfSize, vPosition.y + halfSize, 0.0f), fSpeedx, dammy, 1);
		MapHitChecker::MapHitCollision(VGet(vPosition.x + halfSize, vPosition.y + halfSize, 0.0f), fSpeedx, dammy, 1);
		MapHitChecker::MapHitCollision(VGet(vPosition.x - halfSize, vPosition.y - halfSize, 0.0f), fSpeedx, dammy, 1);
		MapHitChecker::MapHitCollision(VGet(vPosition.x + halfSize, vPosition.y - halfSize, 0.0f), fSpeedx, dammy, 1);
	
		SideAcceleration(vPosition, fSpeedx);
	}
}