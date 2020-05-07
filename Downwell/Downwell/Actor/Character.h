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

	static VECTOR GetPos();
private:
	void CreatePolygon();
private:
	VERTEX3D vtx3d_vert[6];
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
	VECTOR vSpeed;
};