#pragma once
#include "Widget.h"

class StageWidget : public Widget
{
public:
	StageWidget();
	~StageWidget();

	virtual void Update() override;
	virtual void Draw() override;
private:
	int nClearTexture_;
	int nFailedTexture_;
};