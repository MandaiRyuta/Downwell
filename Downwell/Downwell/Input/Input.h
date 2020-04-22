#pragma once
#include "../Constant.h"
class Input
{
private:
	Input() {}
	~Input(){}
public:

	static Input& GetInstance()
	{
		Input Inst;
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