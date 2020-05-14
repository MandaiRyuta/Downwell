#include "LevelsResponsible.h"
#include "GameLevel.h"
#include "../Resource/TextureData.h"
#include "../Input/Input.h"


void LevelsResponsible::Init()
{
	bLevelState_ = false;
	nNowLevel_ = 2;
	bChangeScene_ = false;
	TextureDataBase::TextureData::GetInstance().Init();

	Level_ = new GameLevel(2);
}

void LevelsResponsible::Update()
{
	if (nNowLevel_ == 2 && bChangeScene_ == false)
	{
		if (Input::GetInstance().GetKeyDown(KEY_INPUT_SPACE) == 0x001)
		{
			nNowLevel_ = 0;
			bChangeScene_ = true;
		}
	}
	     
	if (bChangeScene_)
	{
		switch (nNowLevel_)
		{
		case 0:
			ChangeLevel(0);
			bChangeScene_ = false;
			break;
		case 1:
			ChangeLevel(1);
			bChangeScene_ = false;
			break;
		case 2:
			ChangeLevel(2);
			bChangeScene_ = false;
			break;
		default:
			break;
		}
	}

	if (Level_ == nullptr) return;
	Level_->Update();
}

void LevelsResponsible::Draw()
{
	if (Level_ == nullptr) return;
	Level_->Draw();
}

void LevelsResponsible::Release()
{
	delete Level_;
}

void LevelsResponsible::Exit()
{
	nNowLevel_ = 3;
}

void LevelsResponsible::ChangeLevel(int type)
{
	if (Level_ != nullptr)
	{
		delete Level_;
	}

	auto chengelevel = [](int type)
	{
		switch (type)
		{
		case 0:
			return new GameLevel(type);
			break;
		case 1:
			return new GameLevel(type);
			break;
		case 2:
			return new GameLevel(type);
			break;
		}
	};

	Level_ = chengelevel(type);

}

const int& LevelsResponsible::GetNowLevel()
{
	return nNowLevel_;
}

void LevelsResponsible::SetChangeScene(bool bchangescene)
{
	bChangeScene_ = bchangescene;
}

const bool& LevelsResponsible::GetChengeSceneExist()
{
	return bChangeScene_;
}

void LevelsResponsible::SetNowLevel(int nlevel)
{
	nNowLevel_ = nlevel;
}

const bool& LevelsResponsible::GetLevelState()
{
	return bLevelState_;
}

void LevelsResponsible::SetLevelState(bool bstate)
{
	bLevelState_ = bstate;
}
