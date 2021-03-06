#pragma once
#include <string>
#include "../Constant.h"
class EnemyParameter;	//敵パラメータークラス

class Factory
{
public:
	/// <summary>
	/// 作成クラス
	/// </summary>
	/// <param name="nEnemyNumber">敵の描画番号</param>
	/// <param name="nType">敵の種類</param>
	/// <param name="nHp">敵のHP</param>
	/// <param name="vPosition">敵の出現座標</param>
	/// <returns></returns>
	EnemyParameter* Create(int nEnemyNumber, int nType, int nHp, VECTOR vPosition)
	{
		return CreateInstance(nEnemyNumber, nType, nHp, vPosition);
	}
private:
	/// <summary>
	/// 敵生成関数
	/// </summary>
	/// <param name="nEnemyNumber">敵の描画番号</param>
	/// <param name="nType">敵の種類</param>
	/// <param name="nHp">敵のHP</param>
	/// <param name="vPosition">敵の出現座標</param>
	/// <returns></returns>
	virtual EnemyParameter* CreateInstance(int nEnemyNumber, int nType, int nHp, VECTOR vPosition) = 0;
};

class CreateFactory : public Factory
{
private:
	/// <summary>
	/// 敵生成関数
	/// </summary>
	/// <param name="nEnemyNumber">敵の描画番号</param>
	/// <param name="nType">敵の種類</param>
	/// <param name="nHp">敵のHP</param>
	/// <param name="vPosition">敵の出現座標</param>
	/// <returns></returns>
	EnemyParameter* CreateInstance(int nEnemyNumber, int nType, int nHp, VECTOR vPosition);
};