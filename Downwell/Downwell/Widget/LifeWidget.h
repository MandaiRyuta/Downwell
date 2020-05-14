#pragma once
#include "Widget.h"

class LifeWidget : public Widget
{
public:
	LifeWidget();
	~LifeWidget();
public:
	virtual void Update() override;
	virtual void Draw() override;
private:
	int nTextureWidth_;
	int nGameCharacterLifeTexture_;
};