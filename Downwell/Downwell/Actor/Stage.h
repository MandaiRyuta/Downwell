#pragma once
#include "Actor.h"
#include <array>
#include <algorithm>
#include "../Constant.h"
#include "../Collision/Collision.h"

constexpr int StageWidth = 20;	//ステージの幅
constexpr int StageHeigh = 350;	//ステージの高さ
constexpr int OneBlockHeight = 50;	//1区画の高さ
constexpr int OneBlockWidth = 20;	//1区画の幅
constexpr int BlockWidth = 18;	//ブロックの高さ
constexpr int BlockHeight = 18;	//ブロックの幅
constexpr int BlockSize = 18;	//ブロックのサイズ

class Stage
{
private:
	/// <summary>
	/// コンストラクター
	/// </summary>
	Stage();
	/// <summary>
	/// デストラクター
	/// </summary>
	~Stage();
public:
	/// <summary>
	/// インスタンス取得関数
	/// </summary>
	/// <returns>静的なStageのインスタンス</returns>
	static Stage& GetInstance()
	{
		static Stage Instance;
		return Instance;
	}
	/// <summary>
	/// 初期化関数
	/// </summary>
	/// <param name="nSceneNumber">シーン番号</param>
	void Init(int nSceneNumber);
	/// <summary>
	/// 更新関数
	/// </summary>
	void Update();
	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();

	/// <summary>
	/// ステージの座標関数
	/// </summary>
	/// <param name="nX">プレイヤーもしくは敵のX座標</param>
	/// <param name="nY">プレイヤーもしくは敵のY座標</param>
	/// <returns></returns>
	const VECTOR& GetStagePos(int nX, int nY);
	/// <summary>
	/// ステージのブロック種類を調べる関数
	/// </summary>
	/// <param name="nX">プレイヤーもしくは敵のX座標</param>
	/// <param name="nY">プレイヤーもしくは敵のY座標</param>
	/// <returns></returns>
	const int& GetStageType(int nX, int nY);
	/// <summary>
	/// ブロックの種類を変更する関数
	/// </summary>
	/// <param name="nType">変更する種類の番号</param>
	/// <param name="nX">ブロックの横列</param>
	/// <param name="nY">ブロックの縦列</param>
	void SetStageType(int nType, int nX, int nY);
	/// <summary>
	/// ブロックに弾が衝突したときの処理
	/// </summary>
	void BlockHittingChange();
	/// <summary>
	/// カリングしたブロックを描画する関数
	/// </summary>
	void BlockCurringDraw();
private:
	std::array<std::array<int, StageWidth>, StageHeigh> Stage_;	//ステージ上のブロック種類を管理
	std::array<std::array<VECTOR, StageWidth>, StageHeigh> Blockpos_; //ステージ上のブロックを配置する座標を管理

	int nSceneNumber_;	//シーン番号
	int nBlockTexture_;	//背景テクスチャーハンドル
	int nNonBlockTexture_;	//ブロックテクスチャーハンドル
	int nInSideBlockTexture_;	//外側に配置しているブロックテクスチャーハンドル
	int nSideBlockTexture_;	//壁ブロックのテクスチャーハンドル
	int nBlockSideBlockTexture_;	//外側に配置しているブロックの内側に用のテクスチャーハンドル
	int nNotBrokenBlockTexture_;	//破壊されないブロック
};