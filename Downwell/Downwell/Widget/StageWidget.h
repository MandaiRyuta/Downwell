#pragma once
#include "Widget.h"

class StageWidget : public Widget
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	StageWidget();
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~StageWidget();
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`��֐�
	/// </summary>
	virtual void Draw() override;
};