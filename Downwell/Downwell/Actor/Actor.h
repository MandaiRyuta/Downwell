#pragma once

class Actor
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	Actor(){}
	/// <summary>
	/// ���z�f�X�g���N�^�[
	/// </summary>
	virtual ~Actor(){}
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// �`��֐�
	/// </summary>
	virtual void Draw() = 0;
};