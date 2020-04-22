#pragma once
#include <DxLib.h>

class Camera {
private:
	Camera() {}		//コンストラクタ
	~Camera() {}
public:
	static Camera& GetInstance()
	{
		static Camera Inst;
		return Inst;
	}

	void Init(VECTOR pos, VECTOR at, VECTOR rotate, VECTOR offset);
	void Update();
	void GetPlayerPosition();
	MATRIX GetMatrix();
	void SetPosition(VECTOR pos);
private:
	VECTOR Position_, At_, Rotate_;
	VECTOR Front_, Right_, UP_;
	VECTOR Offset_;
	MATRIX View_;
	MATRIX Proj_;
	float YRot;
};