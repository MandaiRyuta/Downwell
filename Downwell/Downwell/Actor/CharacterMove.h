#pragma once
#include "../Constant.h"
#include "../DownwellConstant.h"

class CharacterMove
{
public:
	CharacterMove() 
	{
		nSideType_ = -1;
		unLeftAcceleration_ = -1;
		unRightAcceleration_ = -1;
		nMoveFrame_ = 0;
		fMove_ = 0;
		MoveRemainingPower_ = 0.0f;
	}
	~CharacterMove() {}
public:
	void SideAcceleration(VECTOR& vPos);
	void SideMove(VECTOR& vPos);
private:
	VECTOR vSpeed;
	int nSideType_;
	unsigned int unLeftAcceleration_;
	unsigned int unRightAcceleration_;
	int MoveRemainingPower_;
	float fMove_;
	int nMoveFrame_;
};