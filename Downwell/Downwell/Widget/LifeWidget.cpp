#include "LifeWidget.h"
#include "../Resource/TextureData.h"
#include "../Constant.h"
#include "../Actor/Character.h"

LifeWidget::LifeWidget() : nGameCharacterLifeTexture_(0), nTextureWidth_(25)
{
	nGameCharacterLifeTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GCharacterLife);
}

LifeWidget::~LifeWidget()
{
}

void LifeWidget::Update()
{
}

void LifeWidget::Draw()
{
	int nowlife = Character::GetCharacterLife();
	
	switch (nowlife)
	{
	case 1:
		DrawGraph(0, 0, nGameCharacterLifeTexture_, false);
		break;
	case 2:
		for (int i = 0; i < 2; i++)
		{
			DrawGraph(0 + i * nTextureWidth_, 0, nGameCharacterLifeTexture_, false);
		}
		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{
			DrawGraph(0 + i * nTextureWidth_, 0, nGameCharacterLifeTexture_, false);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++)
		{
			DrawGraph(0 + i * nTextureWidth_, 0, nGameCharacterLifeTexture_, false);
		}
		break;
	case 5:
		for (int i = 0; i < 5; i++)
		{
			DrawGraph(0 + i * nTextureWidth_, 0, nGameCharacterLifeTexture_, false);
		}
		break;
	}
}
