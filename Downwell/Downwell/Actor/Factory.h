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

//��p�R���g���[���[������Ă��ǂ�
//�g��������������Ȃ�A�r�w�C�r�A�c���[������ŗp�ӂ��Ă�������y�B