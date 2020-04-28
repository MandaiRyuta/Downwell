#pragma once
#include "Actor.h"
#include "../Constant.h"
#include "CharacterJump.h"
#include "CharacterMove.h"
#include "CharacterAttack.h"

class Character : public Actor
{
public:
	Character();
	~Character();
	virtual void Update() override;
	virtual void Draw() override;

	void PolygonCreate();
	static VECTOR GetPos();

private:
	int nCharacterActionState_;
	int ntexhandle;
	VERTEX2D vtx2d_Vert[6];
	unsigned short usIndex[6];
	static VECTOR vPosition_;
	VECTOR vScale_;
	float fSizeX_;
	float fSizeY_;
	bool bGround;
	CharacterAttack cAttackState_;
	CharacterJump cJumpState_;
	CharacterMove cMoveState_;
	VECTOR vSpeed;
};