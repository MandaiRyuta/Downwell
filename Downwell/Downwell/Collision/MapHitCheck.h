#pragma once
#include "../Constant.h"

namespace MapHitChecker
{
	/// <summary>
	/// ステージのブロックとの衝突判定する関数
	/// </summary>
	/// <param name="vposition">座標</param>
	/// <param name="fspeedx">対象のX移動量</param>
	/// <param name="fspeedy">対象のY移動量</param>
	/// <returns>衝突している部位</returns>
	int MapHitCollision(VECTOR vposition, float& fspeedx, float& fspeedy);

	/// <summary>
	/// ステージに配置しているブロックの種類を取得する関数
	/// </summary>
	/// <param name="vposition">調べたいステージ内の座標</param>
	/// <returns>配置されているブロックの種類</returns>
	int GetChipParam(VECTOR vposition);
}