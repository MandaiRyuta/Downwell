#pragma once

//mob���̈ړ��p�^�[������邽�߂̉��z�N���X
class EnemyParameter;

class ActionBase
{
public:
	enum class STATE
	{
		MOVE,
		FAILED,
		COMPLETE,
	};

	virtual STATE Run(EnemyParameter* enemy) = 0;
};