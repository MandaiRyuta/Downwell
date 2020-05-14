#pragma once

#include "../Constant.h"

namespace TextureDataBase
{
	enum class TitleTextureNumber
	{
		TBackgroundBlock = 0,
		TOutBlock,
		TBlock,
		TBullet,
		TPlayer,
		TTitleLogo,
	};
	enum class GameTextureNumber
	{
		GBackgroundBlock = 0,
		GOutBlock,
		GBlock,
		GSideBlock,
		GBlockInSideBlock,
		GBullet,
		GPlayer,
		GBird,
		GUrchin,
		GTurtle,
		GBulletUI,
		GNonBulletUI,
		GCharacterLife,
	};
	enum class ResultTextureNumber
	{
		RBackgroundBlock = 0,
		ROutBlock,
		RBullet,
		RPlayer,
		RResultLogo,
		RClear,
		RFailed,
	};

	class TextureData
	{
	private:
		TextureData() : TitleTexture_(),GameTexture_(),Resulttexture_() {};
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

		const int& GetTitleTextureData(TextureDataBase::TitleTextureNumber number);
		const int& GetGameTextureData(TextureDataBase::GameTextureNumber number);
		const int& GetResultTextureData(TextureDataBase::ResultTextureNumber number);
	private:
		std::array<int, 6> TitleTexture_;
		std::array<int, 13> GameTexture_;
		std::array<int, 7> Resulttexture_;
	};
}