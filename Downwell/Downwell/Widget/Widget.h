#pragma once
#include "../Actor/Actor.h"
#include "../Resource/TextureData.h"

class Widget
{
public:
	Widget() {}
	virtual ~Widget() {}
public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
};