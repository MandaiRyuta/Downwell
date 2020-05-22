#include "Application.h"
#include "../DownwellConstant.h"

/// <summary>
/// �R���X�g���N�^�[
/// </summary>
Application::Application()
{
}
/// <summary>
/// �f�X�g���N�^�[
/// </summary>
Application::~Application()
{
}
/// <summary>
/// �X�V�֐�
/// </summary>
/// <param name="OnResolved">�����������֐�</param>
/// <param name="OnRejected">��������������������Ȃ��������̊֐�</param>
void Application::Run(const std::function<void()>& OnResolved, const std::function<void()>& OnRejected)
{
	if (DxLib_Init() == Error)
	{
		ErrorLogAdd("Dxlib���������s");
		return;
	}

	Init();

	OnResolved();
}
/// <summary>
/// �E�B���h�E���[�h�ݒ�֐�
/// </summary>
/// <param name="bWindow">true : �E�B���h�E���[�h�@false : �t���X�N���[��</param>
/// <returns>�E�B���h�E���</returns>
Application& Application::SetWindowMode(bool bWindow)
{
	ChangeWindowMode(bWindow ? TRUE : FALSE);
	return *this;
}
/// <summary>
/// 3D�ݒ�֐�
/// </summary>
/// <param name="bEnabled">true : 3D�ɐݒ肷��	false : 2D�ɐݒ肷��</param>
/// <returns>3D�ݒ��</returns>
Application& Application::SetUse3DFlag(bool bEnabled)
{
	DxLib::SetUse3DFlag(bEnabled ? TRUE : FALSE);
	return *this;
}
/// <summary>
/// ���������ݒ�֐�
/// </summary>
/// <param name="bEnabled">true : ������������	false : �����������Ȃ�</param>
/// <returns></returns>
Application& Application::SetWaitVSyncFlag(bool bEnabled)
{
	DxLib::SetWaitVSyncFlag(bEnabled ? TRUE : FALSE);
	return *this;
}
/// <summary>
/// �������֐�
/// </summary>
void Application::Init()
{
	SetGraphMode(static_cast<int>(ScreenWidth), static_cast<int>(ScreenHeight), 32);
	SetDrawScreen(DX_SCREEN_BACK);
}
/// <summary>
/// �X�V�֐�
/// </summary>
void Application::Update()
{
	ClearDrawScreen();
}
/// <summary>
/// ����֐�
/// </summary>
void Application::Release()
{
	DxLib_End();
}
