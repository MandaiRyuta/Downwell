#pragma once

#include "../Constant.h"

namespace TextureDataBase
{
	enum TextureNumber
	{
		BackgroundBlock = 0,
		OutBlock,
		Block,
		Bullet,
		Player,
		Bird,
		Urchin,
		Turtle,
	};

	class TextureData
	{
	private:
		TextureData() {};
		~TextureData() {};
	public:
		static TextureData& GetInstance()
		{
			static TextureData Inst;
			return Inst;
		}

		void Init();
		void Loading(int& scenetype);
		void Release(int& scenetype);
		const int& GetTextureData(TextureDataBase::TextureNumber number);
	private:
		std::array<int,8> Texture_;
	};
}