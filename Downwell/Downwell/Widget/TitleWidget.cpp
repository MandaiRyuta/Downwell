#include "TitleWidget.h"
#include "../Resource/TextureData.h"
#include "../Constant.h"
/// <summary>
/// コンストラクター
/// </summary>
TitleWidget::TitleWidget()
{
	nTitleLogoTexture_ = TextureDataBase::TextureData::GetInstance().GetTitleTextureData(TextureDataBase::TitleTextureNumber::TTitleLogo);
}
/// <summary>
/// デストラクター
/// </summary>
TitleWidget::~TitleWidget()
{
}
/// <summary>
/// 更新関数
/// </summary>
void TitleWidget::Update()
{
}
/// <summary>
/// 描画関数
/// </summary>
void TitleWidget::Draw()
{
	VECTOR vposition = VGet(ScreenWidth / 2 + 18.0f, -280.0f, 0.0f);
	DrawBillboard3D(vposition, 0.5f, 0.5f, 120.0f, 0.0f, nTitleLogoTexture_, false);
}
