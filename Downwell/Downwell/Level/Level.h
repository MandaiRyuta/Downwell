#pragma once

class Level
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	Level() {}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	virtual ~Level() {};
	
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// �`��֐�
	/// </summary>
	virtual void Draw() = 0;
};