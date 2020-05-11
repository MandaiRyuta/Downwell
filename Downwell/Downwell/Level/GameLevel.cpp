#include "GameLevel.h"
#include <DxLib.h>
#include "../Actor/Character.h"
#include "../Actor/Stage.h"
#include "../Actor/Enemy.h"

GameLevel::GameLevel(int type)
{
	int EnemyCount = 0;

	switch (type)
	{
	case 0:
		break;
	case 1:
		//背景 0
		//ステージ キャラ　エネミー　弾 2
		//UI 3
		obj_[0].push_back(new Stage);
		obj_[2].push_back(new Character);
		for (int i = 0; i < 350; i++)
		{
			for (int t = 0; t < 20; t++)
			{
				if (Stage::GetStageType(t, i) == 9)
				{
					obj_[3].push_back(new Enemy(EnemyCount, 1, 1, 1,Stage::GetStagePos(t,i)));
					EnemyCount++;
				}
			}
		}
		EnemyCount = EnemyCount;
		break;
	case 2:
		break;
	}
}

GameLevel::~GameLevel()
{
	for (int i = 0; i < 10; i++)
	{
		for (auto itr : obj_[i])
		{
			if(itr != nullptr)	delete itr;
		}
	}
}
//カリング　画面外行ったら消してしまう。
//
void GameLevel::Update()
{
	for (int i = 0; i < 10; i++)
	{
		for (auto itr : obj_[i])
		{
			if (itr == nullptr) return;
			itr->Update();
		}
	}
}

void GameLevel::Draw()
{
	for (int i = 0; i < 10; i++)
	{
		for (auto itr : obj_[i])
		{
			if (itr == nullptr) return;
			itr->Draw();
		}
	}
	//DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), true);
}
