#include "TextureData.h"

void TextureDataBase::TextureData::Init()
{
	Texture_["Background"] = 0;
	Texture_["Player"] = 0;
}

void TextureDataBase::TextureData::Loading(int& scenetype)
{
	switch (scenetype)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	}
}

const int& TextureDataBase::TextureData::GetTextureData(String name)
{
	return Texture_[name.c_str()];
}
