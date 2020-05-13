#include "Stage.h"
#include "../Resource/StageDataBase.h"
#include "Character.h"
#include "EnemySeaUrchin.h"
#include "../Resource/TextureData.h"
#include <random>

std::array<std::array<int, StageWidth>, StageHeigh> Stage::Stage_ = {};
std::array<std::array<VECTOR, StageWidth>, StageHeigh> Stage::Blockpos_ = {};
std::array<std::array<Rect, StageWidth>, StageHeigh> Stage::Blockrect_ = {};

Stage::Stage()
{
	int nx = 0, ny = 0, stagetype = 0;
	StageDataBase::GetInstance().InitStage();
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> randset(1, 10);
	float blockwidth = static_cast<float>(BlockWidth);
	float blockheight = static_cast<float>(BlockHeight);

	for (int type = 0; type < 7; type++)
	{
		stagetype = randset(mt);
		for (int y = 0; y < OneBlockHeight; y++)
		{
			for (int x = 0; x < OneBlockWidth; x++)
			{
				ny = y + (type * OneBlockHeight);

				if (type == 0)
				{
					Stage_[ny][x] = (StageDataBase::GetInstance().GetStageType(0, x, y));
					Blockpos_[ny][x] = VGet(171.0f + static_cast<float>(x) * (float)blockwidth, (static_cast<float>(-ny) * blockheight) + (blockheight * -0.5f), 0.0f);
				}
				else if (type == 6)
				{
					Stage_[ny][x] = (StageDataBase::GetInstance().GetStageType(11, x, y));
					Blockpos_[ny][x] = VGet(171.0f + static_cast<float>(x) * (float)blockwidth, (static_cast<float>(-ny) * blockheight) + (blockheight * -0.5f), 0.0f);
				}
				else
				{
					Stage_[ny][x] = (StageDataBase::GetInstance().GetStageType(stagetype, x, y));
					Blockpos_[ny][x] = VGet(171.0f + static_cast<float>(x) * (float)blockwidth, (static_cast<float>(-ny) * blockheight) + (blockheight * -0.5f), 0.0f);
				}

				Blockrect_[ny][x].x = Blockpos_[ny][x].x;
				Blockrect_[ny][x].y = Blockpos_[ny][x].y;
				Blockrect_[ny][x].width = blockwidth;
				Blockrect_[ny][x].height = blockheight;
			}
		}
	}

	BlockTexture_ = TextureDataBase::TextureData::GetInstance().GetTextureData(TextureDataBase::TextureNumber::BackgroundBlock);
	InSideBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetTextureData(TextureDataBase::TextureNumber::OutBlock);
	NonBlockTexture_ = TextureDataBase::TextureData::GetInstance().GetTextureData(TextureDataBase::TextureNumber::Block);
}

Stage::~Stage()
{
}
#include "Bullet.h"
#include "../Collision/MapHitCheck.h"

void Stage::Update()
{
	/// <summary>
	/// 各マップチップの座標とカメラの矩形を判定して、フラグを指定する　true || false 
	/// true の場合　描画、　false の場合　描画させない。
	/// </summary>

	for (int i = 0; i < 10; i++)
	{
		if (MapHitCheck::GetChipParam(VGet(Bullet::GetPosition(i).x - 2.0f, Bullet::GetPosition(i).y - 1.0f, 0.0f)) == 3 ||
			MapHitCheck::GetChipParam(VGet(Bullet::GetPosition(i).x + 2.0f, Bullet::GetPosition(i).y - 1.0f, 0.0f)) == 3)
		{
			int x = Bullet::GetPosition(i).x / BlockSize - (BlockSize * 0.5f);
			int y = Bullet::GetPosition(i).y / -BlockSize;

			Stage_[y][x] = 0;

			if (Stage_[y][x + 1] == 0)
			{
				Stage_[y - 1][x + 1] = 7;
			}
			else if (Stage_[y][x - 1] == 0)
			{
				Stage_[y - 1][x - 1] = 8;
			}
			else if (Stage_[y][x + 1] == 0 && Stage_[y][x - 1] == 1)
			{
				Stage_[y - 1][x + 1] = 7;
			}
			else if (Stage_[y][x - 1] == 0 && Stage_[y][x + 1] == 1)
			{
				Stage_[y - 1][x - 1] = 8;
			}
				

			//if (EnemySeaUrchin::GetPosition().x < Bullet::GetPosition(i).x)
			//{
			//	Stage_[y + 1][x] = 11;
			//	Stage_[y - 1][x] = 10;
			//}
			//if (EnemySeaUrchin::GetPosition().x >= Bullet::GetPosition(i).x)
			//{
			//	Stage_[y + 1][x] = 12;
			//	Stage_[y - 1][x] = 13;
			//}

			Bullet::ResetSetPosition(i);
		}
	}
}

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
			
			if (Stage_[y][x] == 0)
			{
				DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, BlockTexture_,false);
			}																 
			if (Stage_[y][x] == 1)											 
			{																 
				DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, InSideBlockTexture_, false);
			}																 
			if (Stage_[y][x] == 2)											 
			{
				DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, NonBlockTexture_, false);
			}
			if (Stage_[y][x] == 3)
			{
				DrawBillboard3D(Blockpos_[y][x], 0.5f, 0.5f, BlockSize, 0, NonBlockTexture_, false);
			}
			numcount++;
		}
	}
}

const VECTOR& Stage::GetStagePos(int x, int y)
{
	return Blockpos_[y][x];
}

const int& Stage::GetStageType(int x, int y)
{
	return Stage_[y][x];
}

const Rect& Stage::GetStageRect(int x, int y)
{
	return Blockrect_[y][x];
}

void Stage::SetStageType(int type, int x, int y)
{
	Stage_[y][x] = type;
}
