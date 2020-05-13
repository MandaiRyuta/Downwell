#include "TextureData.h"
#include "../Constant.h"

void TextureDataBase::TextureData::Init()
{
	for (auto itr : Texture_)
	{
		itr = 0;
	}
}

void TextureDataBase::TextureData::Loading(int& scenetype)
{
	switch (scenetype)
	{
	case 0:
		Texture_[0] = LoadGraph("Resource/block.png");
		Texture_[1] = LoadGraph("Resource/insideblock.png");
		Texture_[2] = LoadGraph("Resource/nonblock.png");
		Texture_[3] = LoadGraph("Resource/bullet.png");
		Texture_[4] = LoadGraph("Resource/player.png");
		break;
	case 1:
		Texture_[0] = LoadGraph("Resource/block.png");
		Texture_[1] = LoadGraph("Resource/insideblock.png");
		Texture_[2] = LoadGraph("Resource/nonblock.png");
		Texture_[3] = LoadGraph("Resource/bullet.png");
		Texture_[4] = LoadGraph("Resource/player.png");
		Texture_[5] = LoadGraph("Resource/enemybird.png");
		Texture_[6] = LoadGraph("Resource/enemyurchin.png");
		Texture_[7] = LoadGraph("Resource/enemyturtle.png");
		break;
	case 2:
		Texture_[0] = LoadGraph("Resource/block.png");
		Texture_[1] = LoadGraph("Resource/insideblock.png");;
		Texture_[2] = LoadGraph("Resource/bullet.png");
		Texture_[3] = LoadGraph("Resource/player.png");
		break;
	}
}

void TextureDataBase::TextureData::Release(int& scenetype)
{
	switch (scenetype)
	{
	case 0:
		DeleteGraph(Texture_[0]);
		DeleteGraph(Texture_[1]);
		DeleteGraph(Texture_[2]);
		DeleteGraph(Texture_[3]);
		DeleteGraph(Texture_[4]);
		break;
	case 1:
		DeleteGraph(Texture_[0]);
		DeleteGraph(Texture_[1]);
		DeleteGraph(Texture_[2]);
		DeleteGraph(Texture_[3]);
		DeleteGraph(Texture_[4]);
		DeleteGraph(Texture_[5]);
		DeleteGraph(Texture_[6]);
		DeleteGraph(Texture_[7]);
		break;
	case 2:
		DeleteGraph(Texture_[0]);
		DeleteGraph(Texture_[1]);
		DeleteGraph(Texture_[2]);
		DeleteGraph(Texture_[3]);
		break;
	}
}

const int& TextureDataBase::TextureData::GetTextureData(TextureDataBase::TextureNumber number)
{
	int texturenumber = static_cast<int>(number);
	return Texture_[texturenumber];
}
