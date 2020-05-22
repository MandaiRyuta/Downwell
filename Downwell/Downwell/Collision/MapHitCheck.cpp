#include "MapHitCheck.h"
#include "../Actor/Stage.h"
/// <summary>
/// ステージのブロックとの衝突判定する関数
/// </summary>
/// <param name="vPosition">座標</param>
/// <param name="fSpeedx">対象のX移動量</param>
/// <param name="fSpeedy">対象のY移動量</param>
/// <param name="nType">判定する対象 0は飛んでいる対象,1飛んでいない対象とプレイヤー</param>
/// <returns>衝突している部位</returns>
int MapHitChecker::MapHitCollision(VECTOR vPosition, float& fSpeedx, float& fSpeedy,int nType)
{
	float affterx, afftery;

	affterx = vPosition.x + fSpeedx;
	afftery = vPosition.y + fSpeedy;

	if (GetChipParam(VGet(affterx, afftery, 0.0f)) == 1 || GetChipParam(VGet(affterx, afftery, 0.0f)) == 2 || GetChipParam(VGet(affterx, afftery, 0.0f)) == 3|| GetChipParam(VGet(affterx, afftery, 0.0f)) == 4 || GetChipParam(VGet(affterx, afftery, 0.0f)) ==5)
	{
		float blx, bty, brx, bby;

		// 当たっていたら壁から離す処理を行う

		// ブロックの上下左右の座標を算出
		blx = (float)((int)affterx / BlockWidth) * BlockWidth;        // 左辺の X 座標
		brx = (float)((int)affterx / BlockWidth + 1) * BlockWidth;    // 右辺の X 座標

		bty = (float)((int)afftery / BlockHeight) * BlockHeight;        // 上辺の Y 座標
		bby = (float)((int)afftery / BlockHeight + 1) * BlockHeight;    // 下辺の Y 座標

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
/// ステージに配置しているブロックの種類を取得する関数
/// </summary>
/// <param name="vPosition">調べたいステージ内の座標</param>
/// <returns>配置されているブロックの種類</returns>
int MapHitChecker::GetChipParam(VECTOR vPosition)
{
	int x,y;
	x = (int)vPosition.x / BlockSize  - (BlockSize / 2);
	y = (int)vPosition.y / -BlockSize;

	if (x >= StageWidth || y >= StageHeigh || x < 0 || y < 0) return 0;

	int dd = Stage::GetInstance().GetStageType(x, y);

	return Stage::GetInstance().GetStageType(x,y);
}
