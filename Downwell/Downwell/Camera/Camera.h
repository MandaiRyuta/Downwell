#pragma once
#include <DxLib.h>



class Camera {
private:
	Camera()
	{
		fShakePower_ = 0.0f;
		bShake_ = false;
		Position_ = VGet(0.0f, 0.0f, 0.0f);
		Offset_ = VGet(0.0f, 0.0f, 0.0f);
	}		//コンストラクタ
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
	void SetShake(bool bshake);
private:
	VECTOR Position_;
	VECTOR Offset_;
	bool bShake_;
	float fShakePower_;
};


