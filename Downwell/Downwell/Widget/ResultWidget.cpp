#include "ResultWidget.h"
#include "../Resource/TextureData.h"
#include "../Level/LevelsResponsible.h"
#include "../Constant.h"
/// <summary>
/// �R���X�g���N�^�[
/// </summary>
ResultWidget::ResultWidget()
{
	nResultLogoTexture_ = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::RResultLogo);

	nClearTexture_ = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::RClear);
	nFailedTexture_ = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::RFailed);
}
/// <summary>
/// �f�X�g���N�^�[
/// </summary>
ResultWidget::~ResultWidget()
{
}
/// <summary>
/// �X�V�֐�
/// </summary>
void ResultWidget::Update()
{
}
/// <summary>
/// �`��֐�
/// </summary>
void ResultWidget::Draw()
{
	VECTOR vposition = VGet(ScreenWidth / 2 + 18.0f, -850.0f, 0.0f);
	DrawBillboard3D(vposition, 0.5f, 0.5f, 120.0f, 0.0f, nResultLogoTexture_, false);

	VECTOR vresultposition = VGet(ScreenWidth / 2 + 18.0f, -800.0f, 0.0f);

	//�m�F
	if (LevelsResponsible::GetInstance().GetLevelState() == true)
	{
		DrawBillboard3D(vresultposition, 0.5f, 0.5f, 200.0f, 0.0f, nClearTexture_, false);
	}
	else
	{
		DrawBillboard3D(vresultposition, 0.5f, 0.5f, 200.0f, 0.0f, nFailedTexture_, false);
	}
}
