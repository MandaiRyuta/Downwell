#include "GameLevel.h"
#include <DxLib.h>
#include "../DownwellConstant.h"
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
/// <summary>
/// コンストラクター
/// </summary>
/// <param name="nType">シーン番号</param>
GameLevel::GameLevel(int nType)
{
	int enemyturtlecount = 0;
	int enemyseaurchincount = 0;
	int enemybirdcount = 0;
	std::random_device rnd;
	std::default_random_engine engine(rnd());
	std::normal_distribution<> dist(dMinDis, dMaxDis);
	double probability = 0;
	LevelsResponsible::GetInstance().SetChangeLevel(false);

	nNowLevel_ = nType;

	TextureDataBase::TextureData::GetInstance().Loading(nType);
	int titletexture = 0;
	int gametexture = 1;
	int resulttexture = 2;

	switch (nType)
	{
	case 0:
		LevelsResponsible::GetInstance().ResetNowStage();
		Widgetobj_[0].push_back(new StageWidget);
		Widgetobj_[0].push_back(new TitleWidget);
		TextureDataBase::TextureData::GetInstance().Release(resulttexture);
		Stage::GetInstance().Init(nType);
		Obj_[0].push_back(new Character(nType));
		break;
	case 1:
		//背景 0
		//ステージ キャラ　エネミー　弾 2
		//UI 3
		Widgetobj_[0].push_back(new StageWidget);
		Widgetobj_[0].push_back(new LifeWidget);
		Widgetobj_[0].push_back(new BulletShotWidget);
		TextureDataBase::TextureData::GetInstance().Release(titletexture);
		Stage::GetInstance().Init(nType); 
		Obj_[0].push_back(new Character(nType));
		for (int i = 0; i < 350; i++)
		{
			for (int t = 0; t < 20; t++)
			{
				if (Stage::GetInstance().GetStageType(t, i) == 9)
				{
					probability = dist(engine);
					if (probability > 0.0 && probability < 1.0)
					{
						Obj_[1].push_back(new Enemy(enemyturtlecount, 0, 1, Stage::GetInstance().GetStagePos(t, i)));
						enemyturtlecount++;
					}
				}
				if (Stage::GetInstance().GetStageType(t, i) == 14)
				{
					probability = dist(engine);
					if (probability > 0.0 && probability < 1.0)
					{
						Obj_[1].push_back(new Enemy(enemyseaurchincount, 1, 1, Stage::GetInstance().GetStagePos(t, i)));
						enemyseaurchincount++;
					}
				}
				if (Stage::GetInstance().GetStageType(t, i) == 20)
				{
					probability = dist(engine);
					if (probability > 0.0 && probability < 1.0)
					{
						Obj_[1].push_back(new Enemy(enemybirdcount, 2, 1, Stage::GetInstance().GetStagePos(t, i)));
						enemybirdcount++;
					}
				}
			}
		}
		break;
	case 2:
		TextureDataBase::TextureData::GetInstance().Release(gametexture);
		Widgetobj_[0].push_back(new ResultWidget);
		Stage::GetInstance().Init(nType);
		Obj_[0].push_back(new Character(nType));
		break;
	}
}
/// <summary>
/// デストラクター
/// </summary>
GameLevel::~GameLevel()
{
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			for (auto itr : Widgetobj_[i])
			{
				if (itr != nullptr) delete itr;
			}
		}
		for (auto itr : Obj_[i])
		{
			if (itr != nullptr)	delete itr;
		}
	}
}
/// <summary>
/// 更新関数
/// </summary>
void GameLevel::Update()
{
	if (Input::GetInstance().GetKeyDown(KEY_INPUT_ESCAPE))
	{
		LevelsResponsible::GetInstance().Exit();
	}
	Stage::GetInstance().Update();
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			for (auto itr : Widgetobj_[i])
			{
				if (itr == nullptr) return;
				itr->Update();
			}
		}
		for (auto itr : Obj_[i])
		{
			if (itr == nullptr) return;
			itr->Update();
		}
	}
}
/// <summary>
/// 描画関数
/// </summary>
void GameLevel::Draw()
{
	Stage::GetInstance().Draw();
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			for (auto itr : Widgetobj_[i])
			{
				if (itr == nullptr) return;
				itr->Draw();
			}
		}
		for (auto itr : Obj_[i])
		{
			if (itr == nullptr) return;
			itr->Draw();
		}
	}
}
