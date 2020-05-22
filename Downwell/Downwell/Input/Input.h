#pragma once
#include "../Constant.h"
class Input
{
private:
	/// <summary>
	/// �R���X�g���N�^�[
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
	/// �f�X�g���N�^�[
	/// </summary>
	~Input(){}
public:
	/// <summary>
	/// �C���X�^���X�擾�֐�
	/// </summary>
	/// <returns>�ÓI��Input�C���X�^���X</returns>
	static Input& GetInstance()
	{
		static Input Inst;
		return Inst;
	}
	/// <summary>
	/// �������֐�
	/// </summary>
	void Init();
	/// <summary>
	/// �L�[�����������̔���֐�
	/// </summary>
	/// <param name="nKey">���̓L�[</param>
	/// <returns>true : �����Ă���	false : �����Ă��Ȃ�</returns>
	signed short int GetKeyPress(int nKey);
	/// <summary>
	/// �L�[������������1�x���������Ԃ��֐�
	/// </summary>
	/// <param name="nKey">���̓L�[</param>
	/// <returns>true : �����Ă���	false : �����Ă��Ȃ�</returns>
	signed short int GetKeyDown(int nKey);
	/// <summary>
	/// �L�[�𗣂�������1�x���������Ԃ��֐�
	/// </summary>
	/// <param name="nKey">���̓L�[</param>
	/// <returns>true : �����Ă���	false : �����Ă��Ȃ�</returns>
	signed short int GetKeyUp(int nKey);
#ifdef DEBUG
	/// <summary>
	/// �f�o�b�O�֐�
	/// </summary>
	/// <param name="nKey">���̓L�[</param>
	void DebugFont(int nKey);
#endif	
private:
	std::array<int, 256> DownKeyNum_;	//���������p�̃L�[�ԍ�
	std::array<int, 256> UpKeyNum_;	//���������p�̃L�[�ԍ�
	std::array<int, 256> PressKeyNum_;	//�������ςȂ��̎��̃L�[�ԍ�
	std::array<signed short int, 256> DownKey_;	//���������p�̃L�[�t���O
	std::array<signed short int, 256> UpKey_;	//���������p�̃L�[�t���O
	std::array<signed short int, 256> PressKey_;	//�������ςȂ��̎��̃L�[�t���O
};