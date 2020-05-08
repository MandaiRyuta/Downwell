#pragma once
#include "Actor.h"
#include "../Constant.h"
#include "CharacterJump.h"
#include "CharacterMove.h"
#include "CharacterAttack.h"
#include "../Collision/QuadTree.h"

class Character : public Actor
{
public:
	Character();
	~Character();
	virtual void Update() override;
	virtual void Draw() override;

	static VECTOR GetPos();
private:
	int nCharacterActionState_;
	int ntexhandle;
	static VECTOR vPosition_;
	VECTOR vScale_;
	float fSizeX_;
	float fSizeY_;
	bool bGround;
	CharacterAttack cAttackState_;
	CharacterJump cJumpState_;
	CharacterMove cMoveState_;
	VECTOR vSpeed_;
	VECTOR vOldPosition_;
	Rect rPlayer_;
	float fGravity_;
	float fPlayershake_;
	bool bPlayershake_;
};