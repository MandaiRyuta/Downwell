#include "BulletShotWidget.h"
#include "../Resource/TextureData.h"
#include "../Actor/CharacterState.h"
#include "../DownwellConstant.h"
/// <summary>
/// コンストラクター
/// </summary>
BulletShotWidget::BulletShotWidget() :
	nBulletTexture_(nInitBulletTexture),
	nNonBulletTexture_(nInitNonBulletTexture),
	nBulletCount_(nBulletMaxCount)
{
	nBulletTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GBulletUI);
	nNonBulletTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GNonBulletUI);
}
/// <summary>
/// デストラクター
/// </summary>
BulletShotWidget::~BulletShotWidget()
{
}
/// <summary>
/// 更新関数
/// </summary>
void BulletShotWidget::Update()
{
}
/// <summary>
/// 描画関数
/// </summary>
void BulletShotWidget::Draw()
{
	nBulletCount_ = CharacterState::GetBullet();
	int npositiony = 240;
	int npositionx = 540;
	for (int i = 0; i < nBulletMaxCount; ++i)
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
