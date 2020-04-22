#include "GameLevel.h"
#include <DxLib.h>
#include "../Actor/Character.h"

GameLevel::GameLevel()
{
	obj_.push_back(new Character);
}

GameLevel::~GameLevel()
{
	for (auto itr : obj_)
	{
		delete itr;
	}
}

void GameLevel::Update()
{
	for (auto itr : obj_)
	{
		itr->Update();
	}
}

void GameLevel::Draw()
{
	for (auto itr : obj_)
	{
		itr->Draw();
	}
	//DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), true);
}
