#include "GameLevel.h"
#include <DxLib.h>
#include "../Actor/Character.h"

GameLevel::GameLevel(int type)
{
	switch (type)
	{
	case 0:
		break;
	case 1:
		//�w�i 0
		//�X�e�[�W �L�����@�G�l�~�[�@�e 2
		//UI 3
		obj_[2].push_back(new Character);
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
			delete itr;
		}
	}
}
//�J�����O�@��ʊO�s����������Ă��܂��B
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
