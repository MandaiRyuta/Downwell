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
	/// <param name="enemynumber">“G‚Ì•`‰æ”Ô†</param>
	/// <param name="ntype">“G‚Ìí—Ş</param>
	/// <param name="nhp">“G‚ÌHP</param>
	/// <param name="nspeed">“G‚ÌˆÚ“®—Ê</param>
	/// <param name="vposition">“G‚ÌoŒ»À•W</param>
	/// <returns></returns>
	EnemyParameter* Create(int enemynumber, int ntype, int nhp, VECTOR vposition) {
		return CreateInstance(enemynumber, ntype, nhp, vposition);
	}
private:
	/// <summary>
	/// “G¶¬ŠÖ”
	/// </summary>
	/// <param name="enemynumber">“G‚Ì•`‰æ”Ô†</param>
	/// <param name="ntype">“G‚Ìí—Ş</param>
	/// <param name="nhp">“G‚ÌHP</param>
	/// <param name="nspeed">“G‚ÌˆÚ“®—Ê</param>
	/// <param name="vposition">“G‚ÌoŒ»À•W</param>
	/// <returns></returns>
	virtual EnemyParameter* CreateInstance(int enemynumber, int ntype, int nhp, VECTOR vposition) = 0;
};

class CreateFactory : public Factory
{
private:
	/// <summary>
	/// “G¶¬ŠÖ”
	/// </summary>
	/// <param name="enemynumber">“G‚Ì•`‰æ”Ô†</param>
	/// <param name="ntype">“G‚Ìí—Ş</param>
	/// <param name="nhp">“G‚ÌHP</param>
	/// <param name="nspeed">“G‚ÌˆÚ“®—Ê</param>
	/// <param name="vposition">“G‚ÌoŒ»À•W</param>
	/// <returns></returns>
	EnemyParameter* CreateInstance(int enemynumber, int ntype, int nhp, VECTOR vposition);
};