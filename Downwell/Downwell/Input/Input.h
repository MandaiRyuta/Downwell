#pragma once
#include "../Constant.h"
class Input
{
private:
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
	~Input(){}
public:

	static Input& GetInstance()
	{
		static Input Inst;
		return Inst;
	}
	void Init();

	signed short int GetKeyPress(int Key);
	signed short int GetKeyDown(int Key);
	signed short int GetKeyUp(int Key);
#ifdef DEBUG
	void DebugFont(int Key);
#endif	
private:
	Array<int, 256> DownKeyNum_;
	Array<int, 256> UpKeyNum_;
	Array<int, 256> PressKeyNum_;
	Array<signed short int, 256> DownKey_;
	Array<signed short int, 256> UpKey_;
	Array<signed short int, 256> PressKey_;
};