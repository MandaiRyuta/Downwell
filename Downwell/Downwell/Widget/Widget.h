#pragma once
#include "../Actor/Actor.h"
#include "../Resource/TextureData.h"

class Widget
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	Widget() {}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	virtual ~Widget() {}
public:
	/// <summary>
	/// �X�V�֐�
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// �`��֐�
	/// </summary>
	virtual void Draw() = 0;
};