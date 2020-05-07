#include "Stage.h"
#include "../Resource/StageDataBase.h"
#include "../Constant.h"

Stage::Stage()
{
	int nx = 0, ny = 0;
	StageDataBase::GetInstance().InitStage();

	for (int type = 0; type < 5; type++)
	{
		for (int y = 0; y < 50; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				ny = y + (type * 50);
				Stage_[ny][x] = (StageDataBase::GetInstance().GetStageType(type, x, y));
			}
		}
	}
	StageBlockHandle_ = LoadGraph("Background.png");

	BlockTexture_ = LoadGraph("Resource/block.png");
	InSideBlockTexture_ = LoadGraph("Resource/insideblock.png");
	NonBlockTexture_ = LoadGraph("Resource/nonblock.png");
}

Stage::~Stage()
{
}

void Stage::Update()
{
	/// <summary>
	/// 各マップチップの座標とカメラの矩形を判定して、フラグを指定する　true || false 
	/// true の場合　描画、　false の場合　描画させない。
	/// </summary>
}
#include "Character.h"
void Stage::Draw()
{
	int MapDrawPointX = -Character::GetPos().x + ((640 / 20 + 2) / 2 - 1);
	int MapDrawPointY = -Character::GetPos().y + ((640 / 20 + 2) / 2 - 1);
	
	int numcount = 0;
	for (int y = 0; y < 250; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			//画面外のステージオブジェクトはカリング
			if (y + MapDrawPointY < 0 || y + MapDrawPointY >= y + MapDrawPointY + 50)	continue;
			
			if (Stage_[y][x] == 0)
			{
				DrawBillboard3D(VGet(150 + x * 18 + 1, 50 + -y * 18 + 1, 0.0f), 0.5f, 0.5f, 18, 0, BlockTexture_,false);
			}																 
			if (Stage_[y][x] == 1)											 
			{																 
				DrawBillboard3D(VGet(150 + x * 18 + 1, 50 + -y * 18 + 1, 0.0f), 0.5f, 0.5f, 18, 0, InSideBlockTexture_, false);
			}																 
			if (Stage_[y][x] == 2)											 
			{
				DrawBillboard3D(VGet(150 + x * 18 + 1, 50 + -y * 18 + 1, 0.0f), 0.5f, 0.5f, 18, 0, NonBlockTexture_, false);
			}
			if (Stage_[y][x] == 3)
			{
				DrawBillboard3D(VGet(150 + x * 18 + 1, 50 + -y * 18 + 1, 0.0f), 0.5f, 0.5f, 18, 0, NonBlockTexture_, false);
			}
			numcount++;
		}
	}
}
