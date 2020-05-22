#pragma once
#include <string>
#include "../Constant.h"
class EnemyParameter;	//“Gƒpƒ‰ƒ[ƒ^[ƒNƒ‰ƒX

class Factory
{
public:
	/// <summary>
	/// ì¬ƒNƒ‰ƒX
	/// </summary>
	/// <param name="nEnemyNumber">“G‚Ì•`‰æ”Ô†</param>
	/// <param name="nType">“G‚Ìí—Ş</param>
	/// <param name="nHp">“G‚ÌHP</param>
	/// <param name="vPosition">“G‚ÌoŒ»À•W</param>
	/// <returns></returns>
	EnemyParameter* Create(int nEnemyNumber, int nType, int nHp, VECTOR vPosition)
	{
		return CreateInstance(nEnemyNumber, nType, nHp, vPosition);
	}
private:
	/// <summary>
	/// “G¶¬ŠÖ”
	/// </summary>
	/// <param name="nEnemyNumber">“G‚Ì•`‰æ”Ô†</param>
	/// <param name="nType">“G‚Ìí—Ş</param>
	/// <param name="nHp">“G‚ÌHP</param>
	/// <param name="vPosition">“G‚ÌoŒ»À•W</param>
	/// <returns></returns>
	virtual EnemyParameter* CreateInstance(int nEnemyNumber, int nType, int nHp, VECTOR vPosition) = 0;
};

class CreateFactory : public Factory
{
private:
	/// <summary>
	/// “G¶¬ŠÖ”
	/// </summary>
	/// <param name="nEnemyNumber">“G‚Ì•`‰æ”Ô†</param>
	/// <param name="nType">“G‚Ìí—Ş</param>
	/// <param name="nHp">“G‚ÌHP</param>
	/// <param name="vPosition">“G‚ÌoŒ»À•W</param>
	/// <returns></returns>
	EnemyParameter* CreateInstance(int nEnemyNumber, int nType, int nHp, VECTOR vPosition);
};