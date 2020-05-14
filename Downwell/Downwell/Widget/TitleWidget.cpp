#include "TitleWidget.h"
#include "../Resource/TextureData.h"
#include "../Constant.h"

TitleWidget::TitleWidget()
{
	nTitleLogoTexture_ = TextureDataBase::TextureData::GetInstance().GetTitleTextureData(TextureDataBase::TitleTextureNumber::TTitleLogo);
}

TitleWidget::~TitleWidget()
{
}

void TitleWidget::Update()
{
}

void TitleWidget::Draw()
{
	VECTOR vposition = VGet(ScreenWidth / 2 + 18.0f, -280.0f, 0.0f);
	DrawBillboard3D(vposition, 0.5f, 0.5f, 120.0f, 0.0f, nTitleLogoTexture_, false);
}
