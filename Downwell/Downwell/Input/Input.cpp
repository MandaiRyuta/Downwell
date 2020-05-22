#include "Input.h"
#include "../DownwellConstant.h"
/// <summary>
/// 初期化関数
/// </summary>
void Input::Init()
{
	for (int i = 0; i < 256; i++)
	{
		PressKey_[i] = False;
		DownKey_[i] = False;
		UpKey_[i] = False;
		DownKeyNum_[i] = 0;
		UpKeyNum_[i] = 0;
		PressKeyNum_[i] = 0;
	}
}
/// <summary>
/// キーを押した時の判定関数
/// </summary>
/// <param name="nKey">入力キー</param>
/// <returns>true : 押している	false : 押していない</returns>
signed short int Input::GetKeyPress(int nKey)
{
	PressKeyNum_[nKey] = nKey;
	PressKey_[nKey] = 0x000;
	
	if (CheckHitKey(nKey) == 1)
	{
		PressKey_[nKey] = 0x001;
#ifdef DEBUG
		DebugFont(nKey);
#endif // DEBUG
		return PressKey_[nKey];
	}

	return PressKey_[nKey];
}
/// <summary>
/// キーを押した時に1度だけ判定を返す関数
/// </summary>
/// <param name="nKey">入力キー</param>
/// <returns>true : 押している	false : 押していない</returns>
signed short int Input::GetKeyDown(int nKey)
{
	DownKey_[nKey] = 0x000;

	if (CheckHitKey(nKey) == 1 && DownKey_[nKey] == 0x000)
	{
		DownKey_[nKey] = 0x001;
#ifdef DEBUG
		DebugFont(nKey);
 #endif // DEBUG
		return DownKey_[nKey];
	}
	else if (CheckHitKey(nKey) == 0 && DownKey_[nKey] == 0x001)
	{
		DownKey_[nKey] = 0x000;
#ifdef DEBUG
		DebugFont(nKey);
#endif // DEBUG
		return DownKey_[nKey];
	}
	else
	{
		DownKey_[nKey] = 0x000;
#ifdef DEBUG
		DebugFont(nKey);
#endif // DEBUG
		return DownKey_[nKey];
	}
	return DownKey_[nKey];
}
/// <summary>
/// キーを離した時に1度だけ判定を返す関数
/// </summary>
/// <param name="nKey">入力キー</param>
/// <returns>true : 離している	false : 離していない</returns>
signed short int Input::GetKeyUp(int nKey)
{
	UpKeyNum_[nKey] = nKey;
	if (CheckHitKey(nKey) == 1)
	{
		UpKey_[nKey] = 0x001;
#ifdef DEBUG
		DebugFont(nKey);
#endif // DEBUG
	}
	else if (CheckHitKey(nKey) == 0 && UpKey_[nKey] == 0x001)
	{
		UpKey_[nKey] = 0x000;
#ifdef DEBUG
		DebugFont(nKey);
#endif // DEBUG
		return UpKey_[nKey];
	}
	else
	{
		UpKey_[nKey] = 0x000;
#ifdef DEBUG
		DebugFont(nKey);
#endif // DEBUG
		return UpKey_[nKey];
	}

	return 0x000;
}
#ifdef DEBUG
/// <summary>
/// デバッグ関数
/// </summary>
/// <param name="nKey">入力キー</param>
void Input::DebugFont(int nKey)
{
	DrawFormatString(0, 50, GetColor(0, 0, 0), "%d nKey : %d", PressKeyNum_[nKey], PressKey_[nKey]);
	DrawFormatString(50,50, GetColor(0, 0, 0), "%d nKey : %d", UpKeyNum_[nKey], UpKey_[nKey]);
	DrawFormatString(100,50, GetColor(0, 0, 0), "%d nKey : %d", DownKeyNum_[nKey], DownKey_[nKey]);
}
#endif // DEBUG
