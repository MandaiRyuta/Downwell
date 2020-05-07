#pragma once

//mob毎の移動パターンを作るための仮想クラス
class EnemyParameter;

class ActionBase
{
public:
	enum STATE
	{
		MOVE,
		FAILED,
		COMPLETE,
	};

	virtual STATE Run(EnemyParameter* enemy) = 0;
};