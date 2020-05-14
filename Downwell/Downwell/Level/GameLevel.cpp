#include "GameLevel.h"
#include <DxLib.h>
#include "../Actor/Character.h"
#include "../Actor/Stage.h"
#include "../Actor/Enemy.h"
#include "../Actor/EnemyBird.h"
#include "../Actor/EnemySeaUrchin.h"
#include "../Actor/EnemyTurtle.h"
#include "../Actor/EnemyParameter.h"
#include "LevelsResponsible.h"
#include "../Input/Input.h"
#include "../Widget/TitleWidget.h"
#include "../Widget/ResultWidget.h"
#include "../Widget/LifeWidget.h"
#include "../Widget/BulletShotWidget.h"
#include "../Widget/StageWidget.h"
#include <random>

GameLevel::GameLevel(int type)
{
	int enemyturtlecount = 0;
	int enemyseaurchincount = 0;
	int enemybirdcount = 0;
	std::random_device rnd;
	std::default_random_engine engine(rnd());
	std::normal_distribution<> dist(0.0, 1.0);
	double probability = 0;
	LevelsResponsible::GetInstance().SetChangeScene(false);

	nNowLevel_ = type;

	TextureDataBase::TextureData::GetInstance().Loading(type);
	int titletexture = 0;
	int gametexture = 1;
	int resulttexture = 2;

	switch (type)
	{
	case 0:
		widgetobj_[0].push_back(new TitleWidget);
		TextureDataBase::TextureData::GetInstance().Release(resulttexture);
		obj_[0].push_back(new Stage(type));
		obj_[1].push_back(new Character(type));
		break;
	case 1:
		//背景 0
		//ステージ キャラ　エネミー　弾 2
		//UI 3
		widgetobj_[0].push_back(new LifeWidget);
		widgetobj_[0].push_back(new BulletShotWidget);
		TextureDataBase::TextureData::GetInstance().Release(titletexture);
		obj_[0].push_back(new Stage(type));
		obj_[1].push_back(new Character(type));
		for (int i = 0; i < 350; i++)
		{
			for (int t = 0; t < 20; t++)
			{
				if (Stage::GetStageType(t, i) == 9)
				{
					probability = dist(engine);
					if (probability > 0.0 && probability < 0.8)
					{
						obj_[2].push_back(new Enemy(enemyturtlecount, 0, 1, 1, Stage::GetStagePos(t, i)));
						enemyturtlecount++;
					}
				}
				if (Stage::GetStageType(t, i) == 14)
				{
					probability = dist(engine);
					if (probability > 0.0 && probability < 0.7)
					{
						obj_[2].push_back(new Enemy(enemyseaurchincount, 1, 1, 1, Stage::GetStagePos(t, i)));
						enemyseaurchincount++;
					}
				}
				if (Stage::GetStageType(t, i) == 20)
				{
					probability = dist(engine);
					if (probability > 0.0 && probability < 0.6)
					{
						obj_[2].push_back(new Enemy(enemybirdcount, 2, 1, 1, Stage::GetStagePos(t, i)));
						enemybirdcount++;
					}
				}
			}
		}
		break;
	case 2:
		TextureDataBase::TextureData::GetInstance().Release(gametexture);
		widgetobj_[0].push_back(new ResultWidget);
		widgetobj_[0].push_back(new StageWidget);
		obj_[0].push_back(new Stage(type));
		obj_[1].push_back(new Character(type));
		break;
	}
}

GameLevel::~GameLevel()
{
	for (int i = 0; i < 3; i++)
	{
		for (auto itr : obj_[i])
		{
			if(itr != nullptr)	delete itr;
		}
		for (auto itr : widgetobj_[i])
		{
			if (itr != nullptr) delete itr;
		}
	}
}
//カリング　画面外行ったら消してしまう。
//
void GameLevel::Update()
{
	if (Input::GetInstance().GetKeyDown(KEY_INPUT_ESCAPE))
	{
		LevelsResponsible::GetInstance().Exit();
	}
	for (int i = 0; i < 3; i++)
	{
		for (auto itr : obj_[i])
		{
			if (itr == nullptr) return;
			itr->Update();
		}
		for (auto itr : widgetobj_[i])
		{
			if (itr == nullptr) return;
			itr->Update();
		}
	}
}

void GameLevel::Draw()
{
	for (int i = 0; i < 3; i++)
	{
		for (auto itr : obj_[i])
		{
			if (itr == nullptr) return;
			itr->Draw();
		}
		for (auto itr : widgetobj_[i])
		{
			if (itr == nullptr) return;
			itr->Draw();
		}
	}
}
