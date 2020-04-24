#pragma once
#include <DxLib.h>

class Camera {
private:
	Camera() {}		//�R���X�g���N�^
	~Camera() {}
public:
	static Camera& GetInstance()
	{
		static Camera Inst;
		return Inst;
	}

	void Init(VECTOR pos);
	void Update();
	void GetPlayerPosition();
	MATRIX GetMatrix();
	void SetPosition(VECTOR pos);
private:
	VECTOR Position_;
};