#include "LevelsResponsible.h"
#include "GameLevel.h"
#include "../Resource/TextureData.h"

void LevelsResponsible::Init()
{
	NowLevel_ = 1;
	TextureDataBase::TextureData::GetInstance().Init();
	TextureDataBase::TextureData::GetInstance().Loading(NowLevel_);

	Level_ = new GameLevel(1);
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
		int defaultnumber = 0;
		int titlenumber = 0;
		int gamenumber = 1;
		int resultnumber = 2;
		switch (type)
		{
		case 0:
			TextureDataBase::TextureData::GetInstance().Release(resultnumber);
			TextureDataBase::TextureData::GetInstance().Loading(type);
			return new GameLevel(0);
			break;
		case 1:
			TextureDataBase::TextureData::GetInstance().Release(titlenumber);
			TextureDataBase::TextureData::GetInstance().Loading(type);
			return new GameLevel(1);
			break;
		case 2:
			TextureDataBase::TextureData::GetInstance().Release(gamenumber);
			TextureDataBase::TextureData::GetInstance().Loading(type);
			return new GameLevel(2);
			break;
		default:
			TextureDataBase::TextureData::GetInstance().Release(type);
			TextureDataBase::TextureData::GetInstance().Loading(defaultnumber);
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
