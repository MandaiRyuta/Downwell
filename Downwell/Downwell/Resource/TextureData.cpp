#include "TextureData.h"
#include "../Constant.h"

void TextureDataBase::TextureData::Init()
{
	for (auto itr : TitleTexture_)
	{
		itr = 0;
	}
	for (auto itr : GameTexture_)
	{
		itr = 0;
	}
	for (auto itr : Resulttexture_)
	{
		itr = 0;
	}
}

void TextureDataBase::TextureData::Loading(int& scenetype)
{
	switch (scenetype)
	{
	case 0:
		TitleTexture_[0] = LoadGraph("Resource/block.png");
		TitleTexture_[1] = LoadGraph("Resource/insideblock.png");
		TitleTexture_[2] = LoadGraph("Resource/nonblock.png");
		TitleTexture_[3] = LoadGraph("Resource/bullet.png");
		TitleTexture_[4] = LoadGraph("Resource/player.png");
		TitleTexture_[5] = LoadGraph("Resource/titlelogo.png");
		break;
	case 1:
		GameTexture_[0] = LoadGraph("Resource/block.png");
		GameTexture_[1] = LoadGraph("Resource/insideblock.png");
		GameTexture_[2] = LoadGraph("Resource/nonblock.png");
		GameTexture_[3] = LoadGraph("Resource/sideblock.png");
		GameTexture_[4] = LoadGraph("Resource/blockinsideblock.png");
		GameTexture_[5] = LoadGraph("Resource/bullet.png");
		GameTexture_[6] = LoadGraph("Resource/player.png");
		GameTexture_[7] = LoadGraph("Resource/enemybird.png");
		GameTexture_[8] = LoadGraph("Resource/enemyurchin.png");
		GameTexture_[9] = LoadGraph("Resource/enemyturtle.png");
		GameTexture_[10] = LoadGraph("Resource/uibullet.png");
		GameTexture_[11] = LoadGraph("Resource/uinonbullet.png");
		GameTexture_[12] = LoadGraph("Resource/hp.png");
		break;
	case 2:
		Resulttexture_[0] = LoadGraph("Resource/block.png");
		Resulttexture_[1] = LoadGraph("Resource/insideblock.png");;
		Resulttexture_[2] = LoadGraph("Resource/bullet.png");
		Resulttexture_[3] = LoadGraph("Resource/player.png");
		Resulttexture_[4] = LoadGraph("Resource/resultlogo.png");
		Resulttexture_[5] = LoadGraph("Resource/clear.png");
		Resulttexture_[6] = LoadGraph("Resource/failed.png");
		break;
	}
}

void TextureDataBase::TextureData::Release(int& scenetype)
{
	switch (scenetype)
	{
	case 0:
		DeleteGraph(TitleTexture_[0]);
		DeleteGraph(TitleTexture_[1]);
		DeleteGraph(TitleTexture_[2]);
		DeleteGraph(TitleTexture_[3]);
		DeleteGraph(TitleTexture_[4]);
		DeleteGraph(TitleTexture_[5]);
		break;
	case 1:
		DeleteGraph(GameTexture_[0]);
		DeleteGraph(GameTexture_[1]);
		DeleteGraph(GameTexture_[2]);
		DeleteGraph(GameTexture_[3]);
		DeleteGraph(GameTexture_[4]);
		DeleteGraph(GameTexture_[5]);
		DeleteGraph(GameTexture_[6]);
		DeleteGraph(GameTexture_[7]);
		DeleteGraph(GameTexture_[8]);
		DeleteGraph(GameTexture_[9]);
		DeleteGraph(GameTexture_[10]);
		DeleteGraph(GameTexture_[11]);
		DeleteGraph(GameTexture_[12]);
		break;
	case 2:
		DeleteGraph(Resulttexture_[0]);
		DeleteGraph(Resulttexture_[1]);
		DeleteGraph(Resulttexture_[2]);
		DeleteGraph(Resulttexture_[3]);
		DeleteGraph(Resulttexture_[4]);
		DeleteGraph(Resulttexture_[5]);
		DeleteGraph(Resulttexture_[6]);
		break;
	}
}

const int& TextureDataBase::TextureData::GetTitleTextureData(TextureDataBase::TitleTextureNumber number)
{
	int texturenumber = static_cast<int>(number);
	return TitleTexture_[texturenumber];
}

const int& TextureDataBase::TextureData::GetGameTextureData(TextureDataBase::GameTextureNumber number)
{
	int texturenumber = static_cast<int>(number);
	return GameTexture_[texturenumber];
}

const int& TextureDataBase::TextureData::GetResultTextureData(TextureDataBase::ResultTextureNumber number)
{
	int texturenumber = static_cast<int>(number);
	return Resulttexture_[texturenumber];
}

