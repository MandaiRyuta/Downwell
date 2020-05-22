#pragma once
#include "../Constant.h"

namespace MapHitChecker
{
	/// <summary>
	/// ステージのブロックとの衝突判定する関数
	/// </summary>
	/// <param name="vPosition">座標</param>
	/// <param name="fSpeedx">対象のX移動量</param>
	/// <param name="fSpeedy">対象のY移動量</param>
	/// <param name="nType">判定する対象 0は飛んでいる対象,1飛んでいない対象とプレイヤー</param>
	/// <returns>衝突している部位</returns>
	int MapHitCollision(VECTOR vPosition, float& fSpeedx, float& fSpeedy, int nType);

	/// <summary>
	/// ステージに配置しているブロックの種類を取得する関数
	/// </summary>
	/// <param name="vPosition">調べたいステージ内の座標</param>
	/// <returns>配置されているブロックの種類</returns>
	int GetChipParam(VECTOR vPosition);
}