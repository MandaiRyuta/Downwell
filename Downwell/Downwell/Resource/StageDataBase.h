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
	/// <param name="nType">区画</param>
	/// <param name="nX">X座標</param>
	/// <param name="nY">Y座標</param>
	/// <returns>ステージ情報</returns>
	int GetStageType(int nType, int nX, int nY);
private:
	int nStage_[12][50][20];	//区画情報
};