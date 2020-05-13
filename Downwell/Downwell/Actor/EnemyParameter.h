#pragma once
#include "../Constant.h"
#include "../DownwellConstant.h"
class EnemyParameter
{
public:
	EnemyParameter();
	virtual ~EnemyParameter() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;

	const int& GetHp()
	{
		return nHp_;
	}
	const int& GetMaxHp()
	{
		return nMaxHp_;
	}
	const int& GetSpeed()
	{
		return nSpeed_;
	}
	const int& GetMaxSpeed()
	{
		return nMaxSpeed_;
	}
	const VECTOR& GetPosition()
	{
		return vPosition_;
	}
	void SetPosition(VECTOR position)
	{
		vPosition_.x = position.x;
		vPosition_.y = position.y;
		vPosition_.z = position.z;
	}
	void MovePosition(VECTOR move)
	{
		vMove_.x = move.x;
		vMove_.y = move.y;
		vMove_.z = move.z;
	}
	void AddMovePositionY(float fmovey)
	{
		vMove_.y += fmovey;
	}
	void AddMovePositionX(float fmovex)
	{
		vMove_.x += fmovex;
	}
	void SetMoveType(int ntype)
	{
		nMoveType_ = ntype;
	}
	const int& GetMoveType()
	{
		return nMoveType_;
	}
	void SetBottomTouch(bool bbottomtouch)
	{
		bBottomtouch_ = bbottomtouch;
	}

	void SetEnemyNumber(int nnumber)
	{
		nEnemyNumber_ = nnumber;
	}

	const int& GetEnemyNumber()
	{
		return nEnemyNumber_;
	}

	const bool& GetbLifeExist()
	{
		return bLife_;
	}
	
	void SetbLife(bool blife)
	{
		bLife_ = blife;
	}
protected:
	bool bLife_;
	int nEnemyNumber_;
	int nMoveType_;
	int nHp_;
	int nMaxHp_;
	int nSpeed_;
	int nMaxSpeed_;
	bool bBottomtouch_;
	VECTOR vPosition_;
	VECTOR vMove_;
};