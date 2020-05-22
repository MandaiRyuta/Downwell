#pragma once
#include "../Constant.h"
class Input
{
private:
	/// <summary>
	/// コンストラクター
	/// </summary>
	Input() : DownKeyNum_(),UpKeyNum_(),PressKeyNum_(),DownKey_(),UpKey_(),PressKey_()
	{
		for (int i = 0; i < 256; i++)
		{
			DownKeyNum_[i] = 0;
			UpKeyNum_[i] = 0;
			PressKeyNum_[i] = 0;
			DownKey_[i] = 0x000;
			UpKey_[i] = 0x000;
			PressKey_[i] = 0x000;
		}
	}
	/// <summary>
	/// デストラクター
	/// </summary>
	~Input(){}
public:
	/// <summary>
	/// インスタンス取得関数
	/// </summary>
	/// <returns>静的なInputインスタンス</returns>
	static Input& GetInstance()
	{
		static Input Inst;
		return Inst;
	}
	/// <summary>
	/// 初期化関数
	/// </summary>
	void Init();
	/// <summary>
	/// キーを押した時の判定関数
	/// </summary>
	/// <param name="nKey">入力キー</param>
	/// <returns>true : 押している	false : 押していない</returns>
	signed short int GetKeyPress(int nKey);
	/// <summary>
	/// キーを押した時に1度だけ判定を返す関数
	/// </summary>
	/// <param name="nKey">入力キー</param>
	/// <returns>true : 押している	false : 押していない</returns>
	signed short int GetKeyDown(int nKey);
	/// <summary>
	/// キーを離した時に1度だけ判定を返す関数
	/// </summary>
	/// <param name="nKey">入力キー</param>
	/// <returns>true : 離している	false : 離していない</returns>
	signed short int GetKeyUp(int nKey);
#ifdef DEBUG
	/// <summary>
	/// デバッグ関数
	/// </summary>
	/// <param name="nKey">入力キー</param>
	void DebugFont(int nKey);
#endif	
private:
	std::array<int, 256> DownKeyNum_;	//押した時用のキー番号
	std::array<int, 256> UpKeyNum_;	//離した時用のキー番号
	std::array<int, 256> PressKeyNum_;	//押しっぱなしの時のキー番号
	std::array<signed short int, 256> DownKey_;	//押した時用のキーフラグ
	std::array<signed short int, 256> UpKey_;	//離した時用のキーフラグ
	std::array<signed short int, 256> PressKey_;	//押しっぱなしの時のキーフラグ
};