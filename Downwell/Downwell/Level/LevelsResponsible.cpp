#include "LevelsResponsible.h"
#include "GameLevel.h"

void LevelsResponsible::Init()
{
	Level_ = new GameLevel;
	NowLevel_ = 1;
}

void LevelsResponsible::Update()
{
	Level_->Update();
}

void LevelsResponsible::Draw()
{
	Level_->Draw();
}

void LevelsResponsible::Release()
{
	delete[] Level_;
}

int& LevelsResponsible::GetNowLevel()
{
	return NowLevel_;
}
