#pragma once
#include "Level.h"
#include "../Constant.h"
#include "../Actor/Actor.h"
#include "../Widget/Widget.h"

class GameLevel : public Level
{
public:
	GameLevel(int type);
	~GameLevel();
public:
	virtual void Update() override;
	virtual void Draw() override;

private:
	int nNowLevel_;
	std::list<Actor*> obj_[3];
	std::list<Widget*> widgetobj_[3];
};