#pragma once
#include "Widget.h"

class TitleWidget : public Widget
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	TitleWidget();
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~TitleWidget();
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
	int nTitleLogoTexture_;	//�^�C�g�����S�e�N�X�`���[
};