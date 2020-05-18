#pragma once
#include "JudgmentBase.h"
#include "../Constant.h"
#include "../DownwellConstant.h"

class EnemyParameter;	//敵パラメータクラス

class LifeJudgment : public JudgmentBase
{
public:
	/// <summary>
	/// インスタンスを取得する関数
	/// </summary>
	/// <returns>静的なLifeJudgmentのインスタンス</returns>
	static LifeJudgment* GetInstance()
	{
		static LifeJudgment Instance;
		return &Instance;
	}
	/// <summary>
	/// 判定関数
	/// </summary>
	/// <param name="enemy">敵情報クラス</param>
	/// <returns>判定	true : 判定終了		false : 判定続行</returns>
	virtual bool Judgment(EnemyParameter* enemy) override;
};