#include "Input.h"
#include "../DownwellConstant.h"
/// <summary>
/// �������֐�
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
/// �L�[�����������̔���֐�
/// </summary>
/// <param name="nKey">���̓L�[</param>
/// <returns>true : �����Ă���	false : �����Ă��Ȃ�</returns>
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
/// �L�[������������1�x���������Ԃ��֐�
/// </summary>
/// <param name="nKey">���̓L�[</param>
/// <returns>true : �����Ă���	false : �����Ă��Ȃ�</returns>
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
/// �L�[�𗣂�������1�x���������Ԃ��֐�
/// </summary>
/// <param name="nKey">���̓L�[</param>
/// <returns>true : �����Ă���	false : �����Ă��Ȃ�</returns>
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
/// �f�o�b�O�֐�
/// </summary>
/// <param name="nKey">���̓L�[</param>
void Input::DebugFont(int nKey)
{
	DrawFormatString(0, 50, GetColor(0, 0, 0), "%d nKey : %d", PressKeyNum_[nKey], PressKey_[nKey]);
	DrawFormatString(50,50, GetColor(0, 0, 0), "%d nKey : %d", UpKeyNum_[nKey], UpKey_[nKey]);
	DrawFormatString(100,50, GetColor(0, 0, 0), "%d nKey : %d", DownKeyNum_[nKey], DownKey_[nKey]);
}
#endif // DEBUG
