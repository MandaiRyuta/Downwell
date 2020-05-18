#pragma once
#include "Widget.h"

class BulletShotWidget : public Widget
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	BulletShotWidget();
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~BulletShotWidget();
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
	int nBulletTexture_;	//�e�̃e�N�X�`���[
	int nNonBulletTexture_;	//�e���g�����Ƃ��̃e�N�X�`���[
	int nBulletCount_;	//�e�̎c�e��
};