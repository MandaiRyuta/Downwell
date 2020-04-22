#pragma once

class Level
{
public:
	Level() {}
	virtual ~Level() {};
	
	virtual void Update() = 0;
	virtual void Draw() = 0;
};