#pragma once
#include <DxLib.h>



class Camera {
private:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	Camera()
	{
		fShakePower_ = 0.0f;
		bShake_ = false;
		vPosition_ = VGet(0.0f, 0.0f, 0.0f);
	}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~Camera() {}
public:
	/// <summary>
	/// �J�����C���X�^���X�֐�
	/// </summary>
	/// <returns>�ÓI��Camera�̃C���X�^���X</returns>
	static Camera& GetInstance()
	{
		static Camera Inst;
		return Inst;
	}
	/// <summary>
	/// �������֐�
	/// </summary>
	/// <param name="pos">�������W</param>
	void Init(VECTOR pos);
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	void Update();
	/// <summary>
	/// �f�o�b�O�p�֐�
	/// </summary>
	void DebugCamera();
	/// <summary>
	/// �J�����s��擾�֐�
	/// </summary>
	/// <returns>�J�����s��</returns>
	MATRIX GetMatrix();
	/// <summary>
	/// �J�������W��ݒ肷��֐�
	/// </summary>
	/// <param name="pos">�ݒ肷��J�������W</param>
	void SetPosition(VECTOR pos);
	/// <summary>
	/// �J������U��������֐�
	/// </summary>
	/// <param name="bshake">�J�����̐U���t���O	true : �U��������	false : �U�������Ȃ�</param>
	void SetShake(bool bshake);
private:
	VECTOR vPosition_;	//���W
	bool bShake_;	//�U���t���O
	float fShakePower_;	//�U����
};


