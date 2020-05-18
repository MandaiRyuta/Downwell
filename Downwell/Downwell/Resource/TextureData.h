#pragma once

#include "../Constant.h"

namespace TextureDataBase
{
	/// <summary>
	/// タイトルのテクスチャーハンドル番号
	/// </summary>
	enum class TitleTextureNumber
	{
		TBackgroundBlock = 0,
		TOutBlock,
		TBlock,
		TBullet,
		TPlayer,
		TTitleLogo,
	};
	/// <summary>
	/// ゲームのテクスチャーハンドル番号
	/// </summary>
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
	/// <summary>
	/// リザルトのテクスチャーハンドル番号
	/// </summary>
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
		/// <summary>
		/// コンストラクター
		/// </summary>
		TextureData() : TitleTexture_(),GameTexture_(),Resulttexture_() {};
		/// <summary>
		/// デストラクター
		/// </summary>
		~TextureData() {};
	public:
		/// <summary>
		/// インスタンス取得関数
		/// </summary>
		/// <returns>静的なTextureDataインスタンス</returns>
		static TextureData& GetInstance()
		{
			static TextureData Inst;
			return Inst;
		}
		/// <summary>
		/// 初期化関数
		/// </summary>
		void Init();
		/// <summary>
		/// ローディング関数
		/// </summary>
		/// <param name="scenetype">レベル番号</param>
		void Loading(int& level);
		/// <summary>
		/// 解放関数
		/// </summary>
		/// <param name="scenetype">レベル番号</param>
		void Release(int& level);

		/// <summary>
		/// タイトルのテクスチャーハンドル取得関数
		/// </summary>
		/// <param name="number">テクスチャーハンドル番号</param>
		/// <returns>テクスチャーハンドル</returns>
		const int& GetTitleTextureData(TextureDataBase::TitleTextureNumber number);
		/// <summary>
		/// ゲームのテクスチャーハンドル取得関数
		/// </summary>
		/// <param name="number">テクスチャーハンドル番号</param>
		/// <returns>テクスチャーハンドル</returns>
		const int& GetGameTextureData(TextureDataBase::GameTextureNumber number);
		/// <summary>
		/// リザルトのテクスチャーハンドル取得関数
		/// </summary>
		/// <param name="number">テクスチャーハンドル番号</param>
		/// <returns>テクスチャーハンドル</returns>
		const int& GetResultTextureData(TextureDataBase::ResultTextureNumber number);
	private:
		std::array<int, 6> TitleTexture_;	//タイトルのテクスチャーハンドル
		std::array<int, 13> GameTexture_;	//ゲームのテクスチャーハンドル
		std::array<int, 7> Resulttexture_;	//リザルトのテクスチャーハンドル
	};
}