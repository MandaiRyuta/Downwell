#pragma once
#include <string>
#include "../Constant.h"
class EnemyParameter;	//Gp[^[NX

class Factory
{
public:
	/// <summary>
	/// ěŹNX
	/// </summary>
	/// <param name="enemynumber">GĚ`ćÔ</param>
	/// <param name="ntype">GĚíŢ</param>
	/// <param name="nhp">GĚHP</param>
	/// <param name="nspeed">GĚÚŽĘ</param>
	/// <param name="vposition">GĚoťŔW</param>
	/// <returns></returns>
	EnemyParameter* Create(int enemynumber, int ntype, int nhp, int nspeed, VECTOR vposition) {
		return CreateInstance(enemynumber, ntype, nhp, nspeed, vposition);
	}
private:
	/// <summary>
	/// GśŹÖ
	/// </summary>
	/// <param name="enemynumber">GĚ`ćÔ</param>
	/// <param name="ntype">GĚíŢ</param>
	/// <param name="nhp">GĚHP</param>
	/// <param name="nspeed">GĚÚŽĘ</param>
	/// <param name="vposition">GĚoťŔW</param>
	/// <returns></returns>
	virtual EnemyParameter* CreateInstance(int enemynumber, int ntype, int nhp, int nspeed, VECTOR vposition) = 0;
};

class CreateFactory : public Factory
{
private:
	/// <summary>
	/// GśŹÖ
	/// </summary>
	/// <param name="enemynumber">GĚ`ćÔ</param>
	/// <param name="ntype">GĚíŢ</param>
	/// <param name="nhp">GĚHP</param>
	/// <param name="nspeed">GĚÚŽĘ</param>
	/// <param name="vposition">GĚoťŔW</param>
	/// <returns></returns>
	EnemyParameter* CreateInstance(int enemynumber, int ntype, int nhp, int nspeed, VECTOR vposition);
};