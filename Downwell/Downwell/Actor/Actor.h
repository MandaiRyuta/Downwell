#pragma once

class Actor
{
public:
	Actor(){}
	~Actor(){}
	virtual void Update() = 0;
	virtual void Draw() = 0;
};