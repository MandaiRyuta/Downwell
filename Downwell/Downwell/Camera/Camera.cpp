#include "Camera.h"
#include "../Input/Input.h"
#include "../Constant.h"
#include "../Actor/Character.h"

void Camera::Init(VECTOR pos)
{
	Position_.x = pos.x;
	Position_.y = pos.y;
}

void Camera::Update()
{
	
	Position_.x = Character::GetPos().x;
	Position_.y = -(Character::GetPos().y);

	
	SetCameraPositionAndTarget_UpVecY(VGet(Position_.x, Position_.y, -10),VGet(Character::GetPos().x, -Character::GetPos().y, 0.0f));

	SetupCamera_Ortho(2000);
	SetCameraNearFar(1.0f, 1000.0f);

#ifdef DEBUG
	DrawFormatString(0, 32 * 5, GetColor(255, 255, 255), "Targetが範囲内に入っているか : %d", CheckCameraViewClip_Dir(Character::GetPos()));
	DrawFormatString(0, 32 * 6, GetColor(255, 255, 255), "カメラの位置　: %f, %f, %f", GetCameraPosition().x, GetCameraPosition().y, GetCameraPosition().z);
	DrawFormatString(0, 32 * 7, GetColor(255, 255, 255), "カメラの注視点 : %f, %f, %f", GetCameraTarget().x, GetCameraTarget().y, GetCameraTarget().z);
	//行列がどうなってるか表示
	DrawFormatString(0, 32, GetColor(255, 255, 255), "m[0][0] %f  m[0][1] %f  m[0][2] %f m[0][3] %f",
		GetCameraViewMatrix().m[0][0], GetCameraViewMatrix().m[0][1], GetCameraViewMatrix().m[0][2], GetCameraViewMatrix().m[0][3]);
	DrawFormatString(0, 32 * 2, GetColor(255, 255, 255), "m[1][0] %f  m[1][1] %f  m[1][2] %f m[1][3] %f",
		GetCameraViewMatrix().m[1][0], GetCameraViewMatrix().m[1][1], GetCameraViewMatrix().m[1][2], GetCameraViewMatrix().m[1][3]);
	DrawFormatString(0, 32 * 3, GetColor(255, 255, 255), "m[2][0] %f  m[2][1] %f  m[2][2] %f m[2][3] %f",
		GetCameraViewMatrix().m[2][0], GetCameraViewMatrix().m[2][1], GetCameraViewMatrix().m[2][2], GetCameraViewMatrix().m[2][3]);
	DrawFormatString(0, 32 * 4, GetColor(255, 255, 255), "m[3][0] %f  m[3][1] %f  m[3][2] %f m[3][3] %f",
		GetCameraViewMatrix().m[3][0], GetCameraViewMatrix().m[3][1], GetCameraViewMatrix().m[3][2], GetCameraViewMatrix().m[3][3]);
#endif
}

MATRIX Camera::GetMatrix()
{
	return GetCameraViewMatrix();
}

void Camera::SetPosition(VECTOR pos)
{
	Position_ = pos;
}
