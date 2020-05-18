#pragma once
#include "../Constant.h"

class Application
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	Application();
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~Application();
public:
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	/// <param name="OnResolved">�����������֐�</param>
	/// <param name="OnRejected">��������������������Ȃ��������̊֐�</param>
	void Run(const Function<void()>& OnResolved, const Function<void()>& OnRejected);

	/// <summary>
	/// �E�B���h�E���[�h�ݒ�֐�
	/// </summary>
	/// <param name="bWindow">true : �E�B���h�E���[�h�@false : �t���X�N���[��</param>
	/// <returns>�E�B���h�E���</returns>
	Application& SetWindowMode(bool bWindow);
	/// <summary>
	/// 3D�ݒ�֐�
	/// </summary>
	/// <param name="bEnabled">true : 3D�ɐݒ肷��	false : 2D�ɐݒ肷��</param>
	/// <returns>3D�ݒ��</returns>
	Application& SetUse3DFlag(bool bEnabled);
	/// <summary>
	/// ���������ݒ�֐�
	/// </summary>
	/// <param name="bEnabled">true : ������������	false : �����������Ȃ�</param>
	/// <returns></returns>
	Application& SetWaitVSyncFlag(bool bEnabled);

	/// <summary>
	/// �������֐�
	/// </summary>
	void Init();
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	void Update();
	/// <summary>
	/// ����֐�
	/// </summary>
	void Release();
};