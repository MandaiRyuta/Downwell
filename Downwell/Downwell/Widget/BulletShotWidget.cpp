#include "BulletShotWidget.h"
#include "../Resource/TextureData.h"
#include "../Actor/CharacterAttack.h"

BulletShotWidget::BulletShotWidget() : nBulletTexture_(0),nNonBulletTexture_(0), nBulletCount_(10)
{
	nBulletTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GBulletUI);
	nNonBulletTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GNonBulletUI);
}

BulletShotWidget::~BulletShotWidget()
{
}

void BulletShotWidget::Update()
{
}

void BulletShotWidget::Draw()
{
	nBulletCount_ = CharacterAttack::GetBullet();
	int npositiony = 240;
	int npositionx = 540;
	for (int i = 0; i < 10; i++)
	{
		if (i < nBulletCount_)
		{
			DrawGraph(npositionx, npositiony + 20 * i, nBulletTexture_, 0);
		}
		else
		{
			DrawGraph(npositionx, npositiony + 20 * i, nNonBulletTexture_, 0);
		}
	}
}
