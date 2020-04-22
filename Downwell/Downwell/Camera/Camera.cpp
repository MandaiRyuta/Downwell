#include "Camera.h"
#include "../Input/Input.h"
#include "../Constant.h"


void Camera::Init(VECTOR pos, VECTOR at, VECTOR rotate, VECTOR offset)
{
	Position_ = pos;
	At_ = at;
	Rotate_ = rotate;
	Front_ = VGet(0.0f, 0.0f, 1.0f);
	Right_ = VGet(1.0f, 0.0f, 0.0f);
	UP_ = VGet(0.0f, 1.0f, 0.0f);
	Offset_ = offset;
	YRot = 0;
	Right_ = VCross(Front_, UP_);
}

void Camera::Update()
{
	VECTOR eye, scale, up;
	eye.x = (Offset_.x + Position_.x);
	eye.y = (Offset_.y + Position_.y);
	eye.z = (Offset_.z + Position_.z);
	At_ = Position_;
	CreateLookAtMatrix(&View_,&eye, &At_, &UP_);

	SetupCamera_Ortho(ScreenHeight);
	SetCameraNearFar(1.0f, 1000.0f);

	SetCameraViewMatrix(View_);


#ifdef DEBUG
	//�s�񂪂ǂ��Ȃ��Ă邩�\��
	DrawFormatString(0, 32, GetColor(255, 255, 255), "m[0][0] %f  m[0][1] %f  m[0][2] %f m[0][3] %f",
		View_.m[0][0], View_.m[0][1], View_.m[0][2], View_.m[0][3]);
	DrawFormatString(0, 32 * 2, GetColor(255, 255, 255), "m[1][0] %f  m[1][1] %f  m[1][2] %f m[1][3] %f",
		View_.m[1][0], View_.m[1][1], View_.m[1][2], View_.m[1][3]);
	DrawFormatString(0, 32 * 3, GetColor(255, 255, 255), "m[2][0] %f  m[2][1] %f  m[2][2] %f m[2][3] %f",
		View_.m[2][0], View_.m[2][1], View_.m[2][2], View_.m[2][3]);
	DrawFormatString(0, 32 * 4, GetColor(255, 255, 255), "m[3][0] %f  m[3][1] %f  m[3][2] %f m[3][3] %f",
		View_.m[3][0], View_.m[3][1], View_.m[3][2], View_.m[3][3]);
#endif
}

MATRIX Camera::GetMatrix()
{
	return View_;
}

void Camera::SetPosition(VECTOR pos)
{
	Position_ = pos;
}
