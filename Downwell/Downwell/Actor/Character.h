#pragma once
#include "Actor.h"
#include "../Constant.h"

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
	int texhandle, pshandle;
	VERTEX2D Vert[6];
	unsigned short Index[6];
	static VECTOR Position_;
	VECTOR Scale_;
	MATRIX Wrold_;
	float SizeX_;
	float SizeY_;
};