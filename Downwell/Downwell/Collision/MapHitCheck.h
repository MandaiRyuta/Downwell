#pragma once
#include "../Constant.h"

class MapHitCheck
{
public:
	/// <summary>
	/// �R���X�g���N�^�[
	/// </summary>
	MapHitCheck(){}
	/// <summary>
	/// �f�X�g���N�^�[
	/// </summary>
	~MapHitCheck(){}
public:
	/// <summary>
	/// �X�e�[�W�̃u���b�N�Ƃ̏Փ˔��肷��֐�
	/// </summary>
	/// <param name="vposition">���W</param>
	/// <param name="fspeedx">�Ώۂ�X�ړ���</param>
	/// <param name="fspeedy">�Ώۂ�Y�ړ���</param>
	/// <returns>�Փ˂��Ă��镔��</returns>
	static int MapHitCollision(VECTOR vposition, float& fspeedx, float& fspeedy);
	/// <summary>
	/// �X�e�[�W�ɔz�u���Ă���u���b�N�̎�ނ��擾����֐�
	/// </summary>
	/// <param name="vposition">���ׂ����X�e�[�W���̍��W</param>
	/// <returns>�z�u����Ă���u���b�N�̎��</returns>
	static int GetChipParam(VECTOR vposition);
};