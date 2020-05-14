#include "StageWidget.h"
#include "../Resource/TextureData.h"
#include "../Level/LevelsResponsible.h"
#include "../Constant.h"

StageWidget::StageWidget() : nClearTexture_(0), nFailedTexture_(0)
{
	nClearTexture_ = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::RClear);
	nFailedTexture_ = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::RFailed);
}

StageWidget::~StageWidget()
{
}

void StageWidget::Update()
{
}

void StageWidget::Draw()
{
	VECTOR vposition = VGet(ScreenWidth / 2 + 18.0f, -800.0f, 0.0f);

	//Šm”F
	if (LevelsResponsible::GetInstance().GetLevelState() == true)
	{
		DrawBillboard3D(vposition, 0.5f, 0.5f, 200.0f, 0.0f, nClearTexture_, false);
	}
	else
	{
		DrawBillboard3D(vposition, 0.5f, 0.5f, 200.0f, 0.0f, nFailedTexture_, false);
	}
}
