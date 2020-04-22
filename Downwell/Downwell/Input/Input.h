#pragma once
#include "../Constant.h"
class Input
{
private:
	Input() {}
	/*Input()
		: InputKeyFrame_(0),
		InputState_(False),
		FirstStateCount_(0),
		FirstStateCheck_(False),
		SecondStateCount_(0),
		SecondStateCheck_(False),
		InputKeyFrameFirstCount_(60),
		InputKeyFrameSecondCount_(30)
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
	}*/

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