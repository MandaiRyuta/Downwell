#include "Camera.h"
#include "../Input/Input.h"
#include "../Constant.h"
#include "../Actor/Character.h"
/// <summary>
/// �������֐�
/// </summary>
/// <param name="pos">�������W</param>
void Camera::Init(VECTOR pos)
{
	vPosition_.x = pos.x;
	vPosition_.y = pos.y;
	fShakePower_ = 2.0f;
	bShake_ = false;
}
/// <summary>
/// �X�V�֐�
/// </summary>
void Camera::Update()
{
	//�w��̍��E���W�͈͓̔��ɂ͂����Ă�Ƃ��̂݁AY���W�𓯊�
	if (Character::GetPos().x > 150 && Character::GetPos().x < 550 && !bShake_)
	{
		vPosition_.y = Character::GetPos().y;
	}
	else if (Character::GetPos().x > 150 && Character::GetPos().x < 550 && !bShake_)
	{
		vPosition_.y = Character::GetPos().y + (fShakePower_ * -1.0f);
	}

	SetCameraPositionAndTarget_UpVecY(VGet(vPosition_.x, vPosition_.y, -300.0f),VGet(vPosition_.x, vPosition_.y, 0.0f));
}
/// <summary>
/// �f�o�b�O�p�֐�
/// </summary>
void Camera::DebugCamera()
{
#ifdef DEBUG
	DrawFormatString(0, 32 * 8, GetColor(255, 255, 255), "Player���W : %f, %f, %f", Character::GetPos().x, Character::GetPos().y, Character::GetPos().z);
	DrawFormatString(0, 32 * 5, GetColor(255, 255, 255), "Target���͈͓��ɓ����Ă��邩 : %d", CheckCameraViewClip_Dir(Character::GetPos()));
	DrawFormatString(0, 32 * 6, GetColor(255, 255, 255), "�J�����̈ʒu�@: %f, %f, %f", GetCameraPosition().x, GetCameraPosition().y, GetCameraPosition().z);
	DrawFormatString(0, 32 * 7, GetColor(255, 255, 255), "�J�����̒����_ : %f, %f, %f", GetCameraTarget().x, GetCameraTarget().y, GetCameraTarget().z);
	//�s�񂪂ǂ��Ȃ��Ă邩�\��
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
/// <summary>
/// �J�����s��擾�֐�
/// </summary>
/// <returns>�J�����s��</returns>
MATRIX Camera::GetMatrix()
{
	return GetCameraViewMatrix();
}
/// <summary>
/// �J�������W��ݒ肷��֐�
/// </summary>
/// <param name="pos">�ݒ肷��J�������W</param>
void Camera::SetPosition(VECTOR pos)
{
	vPosition_ = pos;
}
/// <summary>
/// �J������U��������֐�
/// </summary>
/// <param name="bshake">�J�����̐U���t���O	true : �U��������	false : �U�������Ȃ�</param>
void Camera::SetShake(bool bshake)
{
	bShake_ = bshake;
}
