#pragma once
#include "../Constant.h"

namespace MapHitChecker
{
	/// <summary>
	/// �X�e�[�W�̃u���b�N�Ƃ̏Փ˔��肷��֐�
	/// </summary>
	/// <param name="vPosition">���W</param>
	/// <param name="fSpeedx">�Ώۂ�X�ړ���</param>
	/// <param name="fSpeedy">�Ώۂ�Y�ړ���</param>
	/// <param name="nType">���肷��Ώ� 0�͔��ł���Ώ�,1���ł��Ȃ��Ώۂƃv���C���[</param>
	/// <returns>�Փ˂��Ă��镔��</returns>
	int MapHitCollision(VECTOR vPosition, float& fSpeedx, float& fSpeedy, int nType);

	/// <summary>
	/// �X�e�[�W�ɔz�u���Ă���u���b�N�̎�ނ��擾����֐�
	/// </summary>
	/// <param name="vPosition">���ׂ����X�e�[�W���̍��W</param>
	/// <returns>�z�u����Ă���u���b�N�̎��</returns>
	int GetChipParam(VECTOR vPosition);
}