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

	void Init(VECTOR pos);
	void Update();

	void DebugCamera();
	MATRIX GetMatrix();
	void SetPosition(VECTOR pos);
private:
	VECTOR Position_;
	VECTOR Offset_;
};


