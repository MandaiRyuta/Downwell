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
private:
	int texhandle, pshandle;
	VERTEX2DSHADER Vert[4];
	unsigned short Index[6];
	VECTOR Position_;
	VECTOR Scale_;
};