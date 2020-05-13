#pragma once
#include "Widget.h"

class StageWidget : public Widget
{
public:
	StageWidget();
	~StageWidget();

	virtual void Update() override;
	virtual void Draw() override;
};