#pragma once
#include "Widget.h"

class ResultWidget : public Widget
{
public:
	ResultWidget();
	~ResultWidget();
public:
	virtual void Update() override;
	virtual void Draw() override;
private:
	int nResultLogoTexture_;
};