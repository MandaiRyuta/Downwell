#include "StageWidget.h"
#include "../Resource/TextureData.h"
#include "../Level/LevelsResponsible.h"
#include "../Constant.h"
/// <summary>
/// コンストラクター
/// </summary>
StageWidget::StageWidget()
{

}
/// <summary>
/// デストラクター
/// </summary>
StageWidget::~StageWidget()
{
}
/// <summary>
/// 更新関数
/// </summary>
void StageWidget::Update()
{
}
/// <summary>
/// 描画関数
/// </summary>
void StageWidget::Draw()
{
	int nowlevel = LevelsResponsible::GetInstance().GetNowStage();
	DrawFormatString(0, 50, GetColor(255, 255, 255), "NowStage : %d / 7", nowlevel);
}
