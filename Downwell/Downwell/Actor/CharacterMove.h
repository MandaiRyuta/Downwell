#pragma once
#include "../Constant.h"
#include "../DownwellConstant.h"

class CharacterMove
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	CharacterMove() : vSpeed(VGet(fDefaultPos, fDefaultPos, fDefaultPos))
	{
		nSideType_ = nInitSideType;
		unLeftAcceleration_ = nInitLeftAcceleration;
		unRightAcceleration_ = nInitRightAcceleration;
		nMoveFrame_ = nInitMoveFrame;
	}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~CharacterMove() {}
	/// <summary>
	/// ���E�̉����ړ��֐�
	/// </summary>
	/// <param name="vPosition">���W</param>
	/// <param name="fSpeedx">X���W�̈ړ���</param>
	void SideAcceleration(VECTOR& vPosition, float fSpeedx);
	/// <summary>
	/// ���E�ړ��֐�
	/// </summary>
	/// <param name="vPosition">�v���C���[���W</param>
	/// <param name="fSpeedx">X���W�̈ړ���</param>
	/// <param name="fSpeedy">Y���W�̈ړ���</param>
	/// <param name="fGravityPower">�d��</param>
	/// <param name="fSize">�摜�T�C�Y</param>
	void SideMove(VECTOR& vPosition, float& fSpeedx, float& fSpeedy, float& fGravityPower, float fSize);
private:
	VECTOR vSpeed;	//�ړ���
	int nSideType_;	//���E�ړ����f
	unsigned int unLeftAcceleration_;	//���ړ�������
	unsigned int unRightAcceleration_;	//�E�ړ�������
	int nMoveFrame_;	//�ړ��t���[��
};