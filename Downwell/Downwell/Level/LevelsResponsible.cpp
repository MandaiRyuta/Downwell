#include "LevelsResponsible.h"
#include "GameLevel.h"

void LevelsResponsible::Init()
{
	Level_ = new GameLevel(1);
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
	delete Level_;
}

void LevelsResponsible::ChangeLevel(int type)
{
	NowLevel_ = type;

	if (Level_ != nullptr)
	{
		delete Level_;
	}

	auto chengelevel = [](int type)
	{
		switch (type)
		{
		case 0:
			return new GameLevel(0);
			break;
		case 1:
			return new GameLevel(1);
			break;
		case 2:
			return new GameLevel(2);
			break;
		default:
			return new GameLevel(0);
			break;
		}
	};

	Level_ = chengelevel(type);

}

int& LevelsResponsible::GetNowLevel()
{
	return NowLevel_;
}
