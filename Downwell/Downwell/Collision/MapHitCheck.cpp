#include "MapHitCheck.h"
#include "../Actor/Stage.h"
/// <summary>
/// ステージのブロックとの衝突判定する関数
/// </summary>
/// <param name="vposition">座標</param>
/// <param name="fspeedx">対象のX移動量</param>
/// <param name="fspeedy">対象のY移動量</param>
/// <returns>衝突している部位</returns>
int MapHitCheck::MapHitCollision(VECTOR vposition, float& fspeedx, float& fspeedy)
{
	float affterx, afftery;

	affterx = vposition.x + fspeedx;
	afftery = vposition.y + fspeedy;

	if (GetChipParam(VGet(affterx, afftery, 0.0f)) == 1 || GetChipParam(VGet(affterx, afftery, 0.0f)) == 2 || GetChipParam(VGet(affterx, afftery, 0.0f)) == 3|| GetChipParam(VGet(affterx, afftery, 0.0f)) == 4 || GetChipParam(VGet(affterx, afftery, 0.0f)) ==5)
	{
		float blx, bty, brx, bby;

		// 当たっていたら壁から離す処理を行う

		// ブロックの上下左右の座標を算出
		blx = (float)((int)affterx / BlockWidth) * BlockWidth;        // 左辺の X 座標
		brx = (float)((int)affterx / BlockWidth + 1) * BlockWidth;    // 右辺の X 座標

		bty = (float)((int)afftery / BlockHeight) * BlockHeight;        // 上辺の Y 座標
		bby = (float)((int)afftery / BlockHeight + 1) * BlockHeight;    // 下辺の Y 座標

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
/// ステージに配置しているブロックの種類を取得する関数
/// </summary>
/// <param name="vposition">調べたいステージ内の座標</param>
/// <returns>配置されているブロックの種類</returns>
int MapHitCheck::GetChipParam(VECTOR vposition)
{
	int x,y;
	x = (int)vposition.x / BlockSize  - (BlockSize / 2);
	y = (int)vposition.y / -BlockSize;

	if (x >= StageWidth || y >= StageHeigh || x < 0 || y < 0) return 0;

	int dd = Stage::GetStageType(x, y);

	return Stage::GetStageType(x,y);
}
