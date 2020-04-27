#pragma once
#include "Level.h"
#include "../Constant.h"
#include "../Actor/Actor.h"

class GameLevel : public Level
{
public:
	GameLevel(int type);
	~GameLevel();
public:
	virtual void Update() override;
	virtual void Draw() override;

private:
	std::list<Actor*> obj_[10];
};