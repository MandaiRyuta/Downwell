#pragma once
#include "../Constant.h"
#include "../DownwellConstant.h"

class CharacterMove
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	CharacterMove() : vSpeed(VGet(0.0f,0.0f,0.0f))
	{
		nSideType_ = -1;
		unLeftAcceleration_ = -1;
		unRightAcceleration_ = -1;
		nMoveFrame_ = 0;
	}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~CharacterMove() {}
public:
	/// <summary>
	/// ���E�̉����ړ��֐�
	/// </summary>
	/// <param name="vPos">���W</param>
	/// <param name="fspeedx">X���W�̈ړ���</param>
	void SideAcceleration(VECTOR& vPos, float fspeedx);
	/// <summary>
	/// ���E�ړ��֐�
	/// </summary>
	/// <param name="vposition">�v���C���[���W</param>
	/// <param name="fspeedx">X���W�̈ړ���</param>
	/// <param name="fspeedy">Y���W�̈ړ���</param>
	/// <param name="fgravitypower">�d��</param>
	/// <param name="fsize">�摜�T�C�Y</param>
	void SideMove(VECTOR& vposition, float& fspeedx, float& fspeedy, float& fgravitypower, float fsize);
private:
	VECTOR vSpeed;	//�ړ���
	int nSideType_;	//���E�ړ����f
	unsigned int unLeftAcceleration_;	//���ړ�������
	unsigned int unRightAcceleration_;	//�E�ړ�������
	int nMoveFrame_;	//�ړ��t���[��
};