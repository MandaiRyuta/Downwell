#pragma once
#include "Level.h"
#include "../Constant.h"
#include "../Actor/Actor.h"

class GameLevel : public Level
{
public:
	GameLevel();
	~GameLevel();
public:
	virtual void Update() override;
	virtual void Draw() override;

private:
	std::vector<Actor*> obj_;
};