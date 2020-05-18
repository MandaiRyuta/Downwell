#include "MapHitCheck.h"
#include "../Actor/Stage.h"
/// <summary>
/// �X�e�[�W�̃u���b�N�Ƃ̏Փ˔��肷��֐�
/// </summary>
/// <param name="vposition">���W</param>
/// <param name="fspeedx">�Ώۂ�X�ړ���</param>
/// <param name="fspeedy">�Ώۂ�Y�ړ���</param>
/// <returns>�Փ˂��Ă��镔��</returns>
int MapHitCheck::MapHitCollision(VECTOR vposition, float& fspeedx, float& fspeedy)
{
	float affterx, afftery;

	affterx = vposition.x + fspeedx;
	afftery = vposition.y + fspeedy;

	if (GetChipParam(VGet(affterx, afftery, 0.0f)) == 1 || GetChipParam(VGet(affterx, afftery, 0.0f)) == 2 || GetChipParam(VGet(affterx, afftery, 0.0f)) == 3|| GetChipParam(VGet(affterx, afftery, 0.0f)) == 4 || GetChipParam(VGet(affterx, afftery, 0.0f)) ==5)
	{
		float blx, bty, brx, bby;

		// �������Ă�����ǂ��痣���������s��

		// �u���b�N�̏㉺���E�̍��W���Z�o
		blx = (float)((int)affterx / BlockWidth) * BlockWidth;        // ���ӂ� X ���W
		brx = (float)((int)affterx / BlockWidth + 1) * BlockWidth;    // �E�ӂ� X ���W

		bty = (float)((int)afftery / BlockHeight) * BlockHeight;        // ��ӂ� Y ���W
		bby = (float)((int)afftery / BlockHeight + 1) * BlockHeight;    // ���ӂ� Y ���W

		if (fspeedx > 0.0f)
		{
			fspeedx = blx - vposition.x - 1.0f;
			return 1;
		}
		if (fspeedx < 0.0f)
		{
			fspeedx = brx - vposition.x;
			return 2;
		}
		if (fspeedy > 0.0f)
		{
			fspeedy = 0.0f;
			return 3;
		}
		if (fspeedy < 0.0f)
		{
			fspeedy = 0.0f;
			return 4;
		}

		return 4;
	}

	return 0;
}
/// <summary>
/// �X�e�[�W�ɔz�u���Ă���u���b�N�̎�ނ��擾����֐�
/// </summary>
/// <param name="vposition">���ׂ����X�e�[�W���̍��W</param>
/// <returns>�z�u����Ă���u���b�N�̎��</returns>
int MapHitCheck::GetChipParam(VECTOR vposition)
{
	int x,y;
	x = (int)vposition.x / BlockSize  - (BlockSize / 2);
	y = (int)vposition.y / -BlockSize;

	if (x >= StageWidth || y >= StageHeigh || x < 0 || y < 0) return 0;

	int dd = Stage::GetStageType(x, y);

	return Stage::GetStageType(x,y);
}
