#pragma once
#include "Widget.h"

class LifeWidget : public Widget
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	LifeWidget();
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~LifeWidget();
public:
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`��֐�
	/// </summary>
	virtual void Draw() override;
private:
	int nTextureWidth_;	//�e�N�X�`���[��
	int nGameCharacterLifeTexture_;	//�v���C���[�̗̑̓e�N�X�`���[
};