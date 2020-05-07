#pragma once
#include <string>

class EnemyParameter;

class Factory
{
public:
	EnemyParameter* Create(int ntype, int nhp, int nspeed) {
		return CreateInstance(ntype, nhp, nspeed);
	}
private:
	virtual EnemyParameter* CreateInstance(int ntype, int nhp, int nspeed) = 0;
};

class CreateFactory : public Factory
{
private:
	EnemyParameter* CreateInstance(int ntype, int nhp, int nspeed);
};

//専用コントローラーを作っても良い
//拡張性を持たせるなら、ビヘイビアツリーを内部で用意しておいたら楽。