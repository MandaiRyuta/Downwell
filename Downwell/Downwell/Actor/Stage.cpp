#include "Stage.h"
#include "../Resource/StageDataBase.h"
#include "Character.h"
#include "EnemySeaUrchin.h"
#include "../Resource/TextureData.h"
#include "Bullet.h"
#include "../Collision/MapHitCheck.h"
#include <random>

std::array<std::array<int, StageWidth>, StageHeigh> Stage::Stage_ = {};	//ステージ上のブロック種類を管理
std::array<std::array<VECTOR, StageWidth>, StageHeigh> Stage::Blockpos_ = {};	//ステージ上のブロックを配置する座標を管理
/// <summary>
/// コンストラクター
/// </summary>
Stage::Stage():
	nSceneNumber_(nInitStageLevelNumber),
	nBlockSideBlockTexture_(nInitBlockSideBlockTexture),
	nNonBlockTexture_(nInitNonBlockTexture),
	nSideBlockTexture_(nInitSideBlockTexture),
	nBlockTexture_(nInitBlockTexture),
	nInSideBlockTexture_(nInitInSideBlockTexture),
	nNotBrokenBlockTexture_(nInitNotBrokenBlockTexture)
{}
/// <summary>
/// デストラクター
/// </summary>
Stage::~Stage(){}
/// <summary>
/// 初期化関数
/// </summary>
/// <param name="nscenenumber">シーン番号</param>
void Stage::Init(int nscenenumber)
{
	nSceneNumber_ = nscenenumber;

	int nx = 0, ny = 0, stagetype = 0;
	StageDataBase::GetInstance().InitStage();
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> randset(1, 10);
	float blockwidth = static_cast<float>(BlockWidth);
	float blockheight = static_cast<float>(BlockHeight);

	for (int type = 0; type < nAreaMax; type++)
	{
		stagetype = randset(mt);
		for (int y = 0; y < OneBlockHeight; y++)
		{
			for (int x = 0; x < OneBlockWidth; x++)
			{
				ny = y + (type * OneBlockHeight);

				if (type == nBackGroundType)
				{
					Stage_[ny][x] = (StageDataBase::GetInstance().GetStageType(0, x, y));
					Blockpos_[ny][x] = VGet(171.0f + static_cast<float>(x)* (float)blockwidth, (static_cast<float>(-ny)* blockheight) + (blockheight * -0.5f), 0.0f);
				}
				else if (type == nGoalType)
				{
					Stage_[ny][x] = (StageDataBase::GetInstance().GetStageType(11, x, y));
					Blockpos_[ny][x] = VGet(171.0f + static_cast<float>(x)* (float)blockwidth, (static_cast<float>(-ny)* blockheight) + (blockheight * -0.5f), 0.0f);
				}
				else
				{
					Stage_[ny][x] = (StageDataBase::GetInstance().GetStageType(stagetype, x, y));
					Blockpos_[ny][x] = VGet(171.0f + static_cast<float>(x)* (float)blockwidth, (static_cast<float>(-ny)* blockheight) + (blockheight * -0.5f), 0.0f);
				}
			}
		}
	}

	if (nSceneNumber_ == nTitleLevel)
	{
		nBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetTitleTextureData(TextureDataBase::TitleTextureNumber::TBackgroundBlock);
		nInSideBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetTitleTextureData(TextureDataBase::TitleTextureNumber::TOutBlock);
	}
	else if (nSceneNumber_ == nGameLevel)
	{
		nBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GBackgroundBlock);
		nInSideBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GOutBlock);
		nNonBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GBlock);
		nSideBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GSideBlock);
		nBlockSideBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GBlockInSideBlock);
		nNotBrokenBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetGameTextureData(TextureDataBase::GameTextureNumber::GNotBrokenBlock);
	}
	else if (nSceneNumber_ == nResultLevel)
	{
		nBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::RBackgroundBlock);
		nInSideBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetResultTextureData(TextureDataBase::ResultTextureNumber::ROutBlock);
	}
}
/// <summary>
/// 更新関数
/// </summary>
void Stage::Update()
{
	/// <summary>
	/// 各マップチップの座標とカメラの矩形を判定して、フラグを指定する　true || false 
	/// true の場合　描画、　false の場合　描画させない。
	/// </summary>
	if (nSceneNumber_ == nGameLevel)
	{
		for (int i = 0; i < nBulletMaxCount; i++)
		{
			if (MapHitChecker::GetChipParam(VGet(Bullet::GetPosition(i).x - 5.0f, Bullet::GetPosition(i).y - 8.0f, 0.0f)) == 3 ||
				MapHitChecker::GetChipParam(VGet(Bullet::GetPosition(i).x + 5.0f, Bullet::GetPosition(i).y - 8.0f, 0.0f)) == 3 ||
				MapHitChecker::GetChipParam(VGet(Bullet::GetPosition(i).x , Bullet::GetPosition(i).y - 8.0f, 0.0f)) == 3)
			{
				int x = static_cast<int>(Bullet::GetPosition(i).x / BlockSize - (BlockSize * 0.5f));
				int y = static_cast<int>(Bullet::GetPosition(i).y / -BlockSize);

				Stage_[y][x] = 0;
				int up = y - 1;
				int right = x + 1;
				int left = x - 1;

				if (Stage_[y][right] == nBackGroundType)
				{
					Stage_[up][right] = nLeftChangeType;
				}
				if (Stage_[y][left] == nBackGroundType)
				{
					Stage_[up][left] = nRightChangeType;
				}
				if (Stage_[y][right] == nBackGroundType && Stage_[y][left] == nMoveBlockType)
				{
					Stage_[up][right] = nLeftChangeType;
				}
				if (Stage_[y][left] == nBackGroundType && Stage_[y][right] == nMoveBlockType)
				{
					Stage_[up][left] = nRightChangeType;
				}

				Bullet::ResetSetPosition(i);
			}
		}
	}
}
/// <summary>
/// 描画関数
/// </summary>
void Stage::Draw()
{
	int MapDrawPointX, MapDrawPointY;
	MapDrawPointX = MapDrawPointY = 0;
	MapDrawPointX = static_cast<int>(-Character::GetPos().x + ((640 / 20 + 2) / 2 - 1));
	MapDrawPointY = static_cast<int>(-Character::GetPos().y + ((640 / 20 + 2) / 2 - 1));
	
	int numcount = 0;
	for (int y = 0; y < StageHeigh; y++)
	{
		for (int x = 0; x < StageWidth; x++)
		{
			//画面外のステージオブジェクトはカリング
			if (y + MapDrawPointY < 0 || y + MapDrawPointY >= y + MapDrawPointY + 50)	continue;
			
			if (nSceneNumber_ == nTitleLevel)
			{
				if (Stage_[y][x] == nMoveBlockType)
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nInSideBlockTexture_, false);
				}
				else
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nBlockTexture_, false);
				}
			}
			if (nSceneNumber_ == nGameLevel)
			{
				if (Stage_[y][x] == nMoveBlockType)
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nInSideBlockTexture_, false);
				}
				else if (Stage_[y][x] == nFloatingBlockType)
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nNotBrokenBlockTexture_, false);
				}
				else if (Stage_[y][x] == nBlokenBlockType)
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nNonBlockTexture_, false);
				}
				else if (Stage_[y][x] == nSideBlockType)
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nSideBlockTexture_, false);
				}
				else if (Stage_[y][x] == nInSideBlockType)
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nSideBlockTexture_, false);
				}
				else
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nBlockTexture_, false);
				}
			}
			if (nSceneNumber_ == nResultLevel)
			{
				if (Stage_[y][x] == nMoveBlockType)
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nInSideBlockTexture_, false);
				}
				else
				{
					DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, nBlockTexture_, false);
				}
			}
			numcount++;
		}
	}
}
/// <summary>
/// ステージの座標関数
/// </summary>
/// <param name="x">プレイヤーもしくは敵のX座標</param>
/// <param name="y">プレイヤーもしくは敵のY座標</param>
/// <returns></returns>
const VECTOR& Stage::GetStagePos(int x, int y)
{
	return Blockpos_[y][x];
}
/// <summary>
/// ステージのブロック種類を調べる関数
/// </summary>
/// <param name="x">プレイヤーもしくは敵のX座標</param>
/// <param name="y">プレイヤーもしくは敵のY座標</param>
/// <returns></returns>
const int& Stage::GetStageType(int x, int y)
{
	return Stage_[y][x];
}
/// <summary>
/// ブロックの種類を変更する関数
/// </summary>
/// <param name="type">変更する種類の番号</param>
/// <param name="x">ブロックの横列</param>
/// <param name="y">ブロックの縦列</param>
void Stage::SetStageType(int type, int x, int y)
{
	Stage_[y][x] = type;
}
