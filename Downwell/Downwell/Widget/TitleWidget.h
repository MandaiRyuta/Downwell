#pragma once
#include "Widget.h"

class TitleWidget : public Widget
{
public:
	TitleWidget();
	~TitleWidget();
public:
	virtual void Update() override;
	virtual void Draw() override;
};