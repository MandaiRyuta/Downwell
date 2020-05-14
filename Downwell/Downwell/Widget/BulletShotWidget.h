#pragma once
#include "Widget.h"

class BulletShotWidget : public Widget
{
public:
	BulletShotWidget();
	~BulletShotWidget();

public:
	virtual void Update() override;
	virtual void Draw() override;
private:
	int nBulletTexture_;
	int nNonBulletTexture_;
	int nBulletCount_;
};