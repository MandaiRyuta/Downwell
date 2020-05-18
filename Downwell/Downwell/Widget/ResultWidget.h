#pragma once
#include "Widget.h"

class ResultWidget : public Widget
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	ResultWidget();
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~ResultWidget();
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
	int nResultLogoTexture_;	//���U���g�̃��S�e�N�X�`���[
	int nClearTexture_;	//�Q�[���N���A�e�N�X�`���[
	int nFailedTexture_;	//�Q�[���I�[�o�[�e�N�X�`���[
};