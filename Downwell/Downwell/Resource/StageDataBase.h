#pragma once

class StageDataBase
{
private:
	/// <summary>
	/// コンストラクター
	/// </summary>
	StageDataBase() : nStage_() {}
	/// <summary>
	/// デストラクター
	/// </summary>
	~StageDataBase() {}
public:
	/// <summary>
	/// インスタンス取得関数
	/// </summary>
	/// <returns>静的なStageDataBaseインスタンス</returns>
	static StageDataBase& GetInstance()
	{
		static StageDataBase Inst;
		return Inst;
	}
	/// <summary>
	/// ステージ初期化関数
	/// </summary>
	void InitStage();
	/// <summary>
	/// 指定したブロックの情報を取得する関数
	/// </summary>
	/// <param name="type">区画</param>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	/// <returns></returns>
	int GetStageType(int type, int x, int y);
private:
	int nStage_[12][50][20];	//区画情報
};