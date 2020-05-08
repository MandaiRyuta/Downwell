#pragma once
#include "../Constant.h"

class MapHitCheck
{
public:
	MapHitCheck(){}
	~MapHitCheck(){}
public:
	static int MapHitCollision(VECTOR vposition, float& fspeedx, float& fspeedy);
	static int GetChipParam(VECTOR vposition);
};