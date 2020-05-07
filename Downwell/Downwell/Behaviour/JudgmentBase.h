#pragma once

class EnemyParameter;

class JudgmentBase
{
public:
	virtual bool Judgment(EnemyParameter* enemy) = 0;
};