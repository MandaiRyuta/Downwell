#pragma once
#include "../Constant.h"
#include "../Collision/Collision.h"
class Level;	//レベルクラス

class LevelsResponsible :
	public Initialize,
	public Clear
{
private:
	/// <summary>
	/// コンストラクター
	/// </summary>
	LevelsResponsible() : nNowLevel_(0), Level_(nullptr), bChangeLevel_(false), bLevelState_(false), bNextStage_(false), nNowStage_(1) {}
	/// <summary>
	/// デストラクター
	/// </summary>
	~LevelsResponsible() {}
public:
	/// <summary>
	/// インスタンス取得関数
	/// </summary>
	/// <returns>静的なLevelsResponsibleインスタンス</returns>
	static LevelsResponsible& GetInstance()
	{
		static LevelsResponsible Inst;
		return Inst;
	}
	/// <summary>
	/// 初期化関数
	/// </summary>
	virtual void Init() override;
	/// <summary>
	/// 更新関数
	/// </summary>
	void Update();
	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();
	/// <summary>
	/// 解放関数
	/// </summary>
	virtual void Release() override;
	/// <summary>
	/// 終了関数
	/// </summary>
	void Exit();
	/// <summary>
	/// レベル切り替え関数
	/// </summary>
	/// <param name="nType">切り替えたいレベル</param>
	void ChangeLevel(int nType);
	/// <summary>
	/// レベル取得関数
	/// </summary>
	/// <returns>現在のレベル</returns>
	const int& GetNowLevel();
	/// <summary>
	/// レベル切り替えフラグ設定関数
	/// </summary>
	/// <param name="bchangescene">	true : 切り替える	false : 切り替えない</param>
	void SetChangeLevel(bool bChangeLevel);
	/// <summary>
	/// レベル切り替えフラグ取得関数
	/// </summary>
	/// <returns>レベル切り替えフラグ</returns>
	const bool& GetChengeLevelExist();
	/// <summary>
	/// レベル設定関数
	/// </summary>
	/// <param name="nLevel">指定したいレベル</param>
	void SetNowLevel(int nLevel);
	/// <summary>
	/// 現在のレベルを切り替えてるか確認する関数
	/// </summary>
	/// <returns>true : 切り替える		false : 切り替えない</returns>
	const bool& GetLevelState();
	/// <summary>
	/// 現在のレベルを切り替えるか指定する関数
	/// </summary>
	/// <param name="bState">true : 切り替える		false : 切り替えない</param>
	void SetLevelState(bool bState);
	/// <summary>
	/// 次のレベルを呼ぶ関数
	/// </summary>
	void NextStage();
	/// <summary>
	/// 現在の区画情報を初期化する関数
	/// </summary>
	void ResetNowStage();
	/// <summary>
	/// 現在プレイヤーがいる区画を取得する関数
	/// </summary>
	/// <returns>現在プレイヤーが位置する区画</returns>
	const int& GetNowStage();
	/// <summary>
	/// 次の区画に切り替える関数
	/// </summary>
	/// <param name="bNextStage">true : 切り替える	false : 切り替えない</param>
	void SetNextStage(bool bNextStage);
	/// <summary>
	/// 次のレベルに切り替えたか確認する関数
	/// </summary>
	/// <returns>true : 切り替えている	false : 切り替えてない</returns>
	const bool& GetNextStageExist();
	/// <summary>
	/// エリア情報取得関数
	/// </summary>
	/// <param name="nArea">エリア番号</param>
	/// <returns></returns>
	Rect& GetQuadTree(int nArea);
private:
	int nNowStage_;	//現在のステージ
	bool bNextStage_;	//次の切り替えるフラグ
	bool bLevelState_;	//レベルを切り替えているか確認するフラグ
	bool bChangeLevel_;	//レベルを切り替えるフラグ
	int nNowLevel_;	//現在のレベル
	Level* Level_;	//レベルクラス
	Rect Quadtree_[4];	//クアッドツリー
};