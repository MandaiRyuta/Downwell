#pragma once
#include "Actor.h"
#include <array>
#include <algorithm>

class Stage : public Actor
{
public:
	Stage();
	~Stage();
public:
	virtual void Update() override;
	virtual void Draw() override;
private:
	std::array<std::array<int,20>,250> stage_;
};