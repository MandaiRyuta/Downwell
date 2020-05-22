#include "MapHitCheck.h"
#include "../Actor/Stage.h"
/// <summary>
/// �X�e�[�W�̃u���b�N�Ƃ̏Փ˔��肷��֐�
/// </summary>
/// <param name="vPosition">���W</param>
/// <param name="fSpeedx">�Ώۂ�X�ړ���</param>
/// <param name="fSpeedy">�Ώۂ�Y�ړ���</param>
/// <param name="nType">���肷��Ώ� 0�͔��ł���Ώ�,1���ł��Ȃ��Ώۂƃv���C���[</param>
/// <returns>�Փ˂��Ă��镔��</returns>
int MapHitChecker::MapHitCollision(VECTOR vPosition, float& fSpeedx, float& fSpeedy,int nType)
{
	float affterx, afftery;

	affterx = vPosition.x + fSpeedx;
	afftery = vPosition.y + fSpeedy;

	if (GetChipParam(VGet(affterx, afftery, 0.0f)) == 1 || GetChipParam(VGet(affterx, afftery, 0.0f)) == 2 || GetChipParam(VGet(affterx, afftery, 0.0f)) == 3|| GetChipParam(VGet(affterx, afftery, 0.0f)) == 4 || GetChipParam(VGet(affterx, afftery, 0.0f)) ==5)
	{
		float blx, bty, brx, bby;

		// �������Ă�����ǂ��痣���������s��

		// �u���b�N�̏㉺���E�̍��W���Z�o
		blx = (float)((int)affterx / BlockWidth) * BlockWidth;        // ���ӂ� X ���W
		brx = (float)((int)affterx / BlockWidth + 1) * BlockWidth;    // �E�ӂ� X ���W

		bty = (float)((int)afftery / BlockHeight) * BlockHeight;        // ��ӂ� Y ���W
		bby = (float)((int)afftery / BlockHeight + 1) * BlockHeight;    // ���ӂ� Y ���W

		if (fSpeedx > 0.0f)
		{
			fSpeedx = blx - vPosition.x - 1.0f;
			return 1;
		}
		if (fSpeedx < 0.0f)
		{
			fSpeedx = brx - vPosition.x;
			return 2;
		}
		if (nType == 0)
		{
			if (fSpeedy > 0.0f)
			{
				fSpeedy = -1.0f;
				return 3;
			}
			if (fSpeedy < 0.0f)
			{
				//float set = vPosition.y - bby;

				fSpeedy = 1.0f;
				return 4;
			}
		}
		else if (nType == 1)
		{
			if (fSpeedy > 0.0f)
			{
				fSpeedy = bty - vPosition.y - 1.0f;
				return 3;
			}
			if (fSpeedy < 0.0f)
			{
				float set = vPosition.y - bby;

				fSpeedy = bby - vPosition.y + (set);
				return 4;
			}
		}
		return 4;
	}

	return 0;
}
/// <summary>
/// �X�e�[�W�ɔz�u���Ă���u���b�N�̎�ނ��擾����֐�
/// </summary>
/// <param name="vPosition">���ׂ����X�e�[�W���̍��W</param>
/// <returns>�z�u����Ă���u���b�N�̎��</returns>
int MapHitChecker::GetChipParam(VECTOR vPosition)
{
	int x,y;
	x = (int)vPosition.x / BlockSize  - (BlockSize / 2);
	y = (int)vPosition.y / -BlockSize;

	if (x >= StageWidth || y >= StageHeigh || x < 0 || y < 0) return 0;

	int dd = Stage::GetInstance().GetStageType(x, y);

	return Stage::GetInstance().GetStageType(x,y);
}
