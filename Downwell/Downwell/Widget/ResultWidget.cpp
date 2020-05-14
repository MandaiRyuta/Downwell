#include "ResultWidget.h"
#include "../Resource/TextureData.h"
#include "../Constant.h"
ResultWidget::ResultWidget()
{
	nResultLogoTexture_ = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::RResultLogo);
}

ResultWidget::~ResultWidget()
{
}

void ResultWidget::Update()
{
}

void ResultWidget::Draw()
{
	VECTOR vposition = VGet(ScreenWidth / 2 + 18.0f, -850.0f, 0.0f);
	DrawBillboard3D(vposition, 0.5f, 0.5f, 120.0f, 0.0f, nResultLogoTexture_, false);
}
