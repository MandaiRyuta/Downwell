#pragma once

class EnemyParameter;	//敵パラメータクラス

class JudgmentBase
{
public:
	/// <summary>
	/// 判定関数
	/// </summary>
	/// <param name="enemy">敵情報クラス</param>
	/// <returns>判定	true : 判定終了		false : 判定続行</returns>
	virtual bool Judgment(EnemyParameter* enemy) = 0;
};