#include "EnemyParameter.h"
/// <summary>
/// コンストラクター
/// </summary>
EnemyParameter::EnemyParameter() : 
	bBottomtouch_(false),
	bLife_(false),
	nEnemyNumber_(0),
	nHp_(0),
	nMaxHp_(0),
	nMaxSpeed_(0),
	nMoveType_(0),
	nSpeed_(0),
	vMove_(VGet(0.0f,0.0f,0.0f)),
	vPosition_(VGet(0.0f,0.0f,0.0f))
{
}
