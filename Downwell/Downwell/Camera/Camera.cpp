#include "Camera.h"
#include "../Input/Input.h"
#include "../Constant.h"
#include "../Actor/Character.h"

void Camera::Init(VECTOR pos)
{
	Position_.x = pos.x;
	Position_.y = pos.y;
	fShakePower_ = 2.0f;
	bShake_ = false;
}

void Camera::Update()
{
	//指定の左右座標の範囲内にはいってるときのみ、Y座標を同期
	if (Character::GetPos().x > 150 && Character::GetPos().x < 500 && !bShake_)
	{
		Position_.y = Character::GetPos().y;
	}
	else if (Character::GetPos().x > 150 && Character::GetPos().x < 500 && !bShake_)
	{
		Position_.y = Character::GetPos().y + (fShakePower_ * -1.0f);
	}

	SetCameraPositionAndTarget_UpVecY(VGet(Position_.x, Position_.y, -300.0f),VGet(Position_.x, Position_.y, 0.0f));
}

void Camera::DebugCamera()
{
	#ifdef DEBUG
	DrawFormatString(0, 32 * 8, GetColor(255, 255, 255), "Player座標 : %f, %f, %f", Character::GetPos().x, Character::GetPos().y, Character::GetPos().z);
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

void Camera::SetShake(bool bshake)
{
	bShake_ = bshake;
}
