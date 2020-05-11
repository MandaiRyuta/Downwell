#pragma once
#include <string>
#include "../Constant.h"
class EnemyParameter;

class Factory
{
public:
	EnemyParameter* Create(int enemynumber, int ntype, int nhp, int nspeed, VECTOR vposition) {
		return CreateInstance(enemynumber, ntype, nhp, nspeed, vposition);
	}
private:
	virtual EnemyParameter* CreateInstance(int enemynumber, int ntype, int nhp, int nspeed, VECTOR vposition) = 0;
};

class CreateFactory : public Factory
{
private:
	EnemyParameter* CreateInstance(int enemynumber, int ntype, int nhp, int nspeed, VECTOR vposition);
};

//��p�R���g���[���[������Ă��ǂ�
//�g��������������Ȃ�A�r�w�C�r�A�c���[������ŗp�ӂ��Ă�������y�B