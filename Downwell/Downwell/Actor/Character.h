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
	Character(int nscenenumber);
	~Character();
	virtual void Update() override;
	virtual void Draw() override;

	static const VECTOR& GetPos();
	static void SetHitEnemy(bool bhit);
	static void SetHitDamage(bool bdamage);
	static void SetHitLeftDamage(bool bdamage);
	static void SetHitRightDamage(bool bdamage);
	static const int& GetCharacterLife();
private:
	int nNowScene_;
	static int nLife_;
	int nCharacterActionState_;
	int nTexhandle_;
	static VECTOR vPosition_;
	float fSize_;
	CharacterAttack AttackState_;
	CharacterJump JumpState_;
	CharacterMove MoveState_;
	VECTOR vSpeed_;
	VECTOR vOldPosition_;
	float fGravity_;
	float fPlayershake_;
	bool bPlayershake_;
	static bool bHitEnemy_;
	static bool bLeftDamage_;
	static bool bRightDamage_;
	static bool bDamage_;
	int nHitCooltime_;
	bool bInvincible_;
};