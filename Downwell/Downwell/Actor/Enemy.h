#pragma once
#include "Actor.h"
#include "Factory.h"
#include "EnemyParameter.h"

class Enemy : public Actor
{
public:
	Enemy(int ntype, int nhp, int nspeed);
	~Enemy();
public:
	virtual void Update() override; 
	virtual void Draw() override;
private:
	Factory* cFactory_;
	EnemyParameter* cProduct_;
};