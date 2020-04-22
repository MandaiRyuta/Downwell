#pragma once
#include "Level.h"

class GameLevel : public Level
{
public:
	GameLevel();
	~GameLevel();
public:
	virtual void Update() override;
	virtual void Draw() override;
};