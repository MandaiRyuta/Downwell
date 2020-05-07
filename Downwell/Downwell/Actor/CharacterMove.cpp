#include "CharacterMove.h"
#include "../Input/Input.h"

void CharacterMove::SideAcceleration(VECTOR& vPos)
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
	if (vPos.x > 150 + 10)
	{
		switch (unLeftAcceleration_)
		{
		case 0:
			vPos.x += -1.0f * fMove_;
			MoveRemainingPower_ = -1 * fMove_;
			break;
		case 1:
			vPos.x += -5.0f * fMove_;
			MoveRemainingPower_ = -5 * fMove_;
			break;
		default:
			break;
		}
	}

	//指定の右座標＋画像の幅の半分
	if (vPos.x < 500 - 10)
	{
		switch (unRightAcceleration_)
		{
		case 0:
			vPos.x += 1.0f * fMove_;
			MoveRemainingPower_ = 1 * fMove_;
			break;
		case 1:
			vPos.x += 5.0f * fMove_;
			MoveRemainingPower_ = 5 * fMove_;
			break;
		default:
			break;
		}
	}

	if (fMove_ == 0.0f)
	{
		if (MoveRemainingPower_ != 0)
		{
			if (MoveRemainingPower_ < 0)
			{
				MoveRemainingPower_++;
			}
			if (MoveRemainingPower_ > 0)
			{
				MoveRemainingPower_--;
			}
		}

		vPos.x += MoveRemainingPower_;
	}
}

void CharacterMove::SideMove(VECTOR& vPos)
{
	if (Input::GetInstance().GetKeyPress(KEY_INPUT_LEFT))
	{
		nSideType_ = 0;
		fMove_ = 0.75f;
		nMoveFrame_++;
	}
	else if (!Input::GetInstance().GetKeyPress(KEY_INPUT_LEFT))
	{
		unLeftAcceleration_ = -1;
	}
	if (Input::GetInstance().GetKeyPress(KEY_INPUT_RIGHT))
	{
		nSideType_ = 1;
		fMove_ = 0.75f;
		nMoveFrame_++;
	}
	else if (!Input::GetInstance().GetKeyPress(KEY_INPUT_RIGHT))
	{
		unRightAcceleration_ = -1;
	}

	if (!Input::GetInstance().GetKeyPress(KEY_INPUT_LEFT) && !Input::GetInstance().GetKeyPress(KEY_INPUT_RIGHT))
	{
		fMove_ = 0.0f;
		nMoveFrame_ = 0;
	}
	SideAcceleration(vPos);
}
