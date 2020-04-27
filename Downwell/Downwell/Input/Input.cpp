#include "Input.h"

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

signed short int Input::GetKeyPress(int Key)
{
	PressKeyNum_[Key] = Key;
	PressKey_[Key] = False;
	
	if (CheckHitKey(Key) == 1)
	{
		PressKey_[Key] = True;
#ifdef DEBUG
		DebugFont(Key);
#endif // DEBUG
		return PressKey_[Key];
	}

	return PressKey_[Key];
}

signed short int Input::GetKeyDown(int Key)
{
	DownKey_[Key] = 0x000;

	if (CheckHitKey(Key) == 1 && DownKey_[Key] == 0x000)
	{
		DownKey_[Key] = 0x001;
#ifdef DEBUG
		DebugFont(Key);
 #endif // DEBUG
		return DownKey_[Key];
	}
	else if (CheckHitKey(Key) == 0 && DownKey_[Key] == 0x001)
	{
		DownKey_[Key] = 0x000;  
#ifdef DEBUG
		DebugFont(Key);
#endif // DEBUG
		return DownKey_[Key];
	}
	else
	{
		DownKey_[Key] = 0x000;
#ifdef DEBUG
		DebugFont(Key);
#endif // DEBUG
		return DownKey_[Key];
	}
	return DownKey_[Key];
}

signed short int Input::GetKeyUp(int Key)
{
	UpKeyNum_[Key] = Key;
	if (CheckHitKey(Key) == 1)
	{
		UpKey_[Key] = 0x001;
#ifdef DEBUG
		DebugFont(Key);
#endif // DEBUG
	}
	else if (CheckHitKey(Key) == 0 && UpKey_[Key] == 0x001)
	{
		UpKey_[Key] = True;
#ifdef DEBUG
		DebugFont(Key);
#endif // DEBUG
		return UpKey_[Key];
	}
	else
	{
		UpKey_[Key] = 0x000;
#ifdef DEBUG
		DebugFont(Key);
#endif // DEBUG
		return UpKey_[Key];
	}

	return 0x000;
}
#ifdef DEBUG
void Input::DebugFont(int Key)
{
	DrawFormatString(0, 50, GetColor(0, 0, 0), "%d Key : %d", PressKeyNum_[Key], PressKey_[Key]);
	DrawFormatString(50,50, GetColor(0, 0, 0), "%d Key : %d", UpKeyNum_[Key], UpKey_[Key]);
	DrawFormatString(100,50, GetColor(0, 0, 0), "%d Key : %d", DownKeyNum_[Key], DownKey_[Key]);
}
#endif // DEBUG
