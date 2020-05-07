#pragma once
#include "../Constant.h"

class EnemyParameter
{
public:
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
		vPosition_.x += position.x;
		vPosition_.y += position.y;
	}
protected:
	int nHp_;
	int nMaxHp_;
	int nSpeed_;
	int nMaxSpeed_;
	VECTOR vPosition_;
};