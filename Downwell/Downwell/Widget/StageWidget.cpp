#include "StageWidget.h"
#include "../Resource/TextureData.h"
#include "../Level/LevelsResponsible.h"
#include "../Constant.h"
/// <summary>
/// �R���X�g���N�^�[
/// </summary>
StageWidget::StageWidget()
{

}
/// <summary>
/// �f�X�g���N�^�[
/// </summary>
StageWidget::~StageWidget()
{
}
/// <summary>
/// �X�V�֐�
/// </summary>
void StageWidget::Update()
{
}
/// <summary>
/// �`��֐�
/// </summary>
void StageWidget::Draw()
{
	int nowlevel = LevelsResponsible::GetInstance().GetNowStage();
	DrawFormatString(0, 50, GetColor(255, 255, 255), "NowStage : %d / 7", nowlevel);
}
