#include "Stage.h"
#include "../Resource/StageDataBase.h"
#include "Character.h"

std::array<std::array<int, StageWidth>, StageHeigh> Stage::Stage_ = {};
std::array<std::array<VECTOR, StageWidth>, StageHeigh> Stage::Blockpos_ = {};
std::array<std::array<Rect, StageWidth>, StageHeigh> Stage::Blockrect_ = {};

Stage::Stage()
{
	int nx = 0, ny = 0;
	StageDataBase::GetInstance().InitStage();

	for (int type = 0; type < 5; type++)
	{
		for (int y = 0; y < OneBlockHeight; y++)
		{
			for (int x = 0; x < OneBlockWidth; x++)
			{
				ny = y + (type * OneBlockHeight);
				Stage_[ny][x] = (StageDataBase::GetInstance().GetStageType(type, x, y));
				Blockpos_[ny][x] = VGet(171 + x * BlockWidth, (-ny * BlockHeight) + (BlockHeight * -0.5f), 0.0f);
				Blockrect_[ny][x].x = Blockpos_[ny][x].x;
				Blockrect_[ny][x].y = Blockpos_[ny][x].y;
				Blockrect_[ny][x].width = BlockWidth;
				Blockrect_[ny][x].height = BlockHeight;
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
	/// �e�}�b�v�`�b�v�̍��W�ƃJ�����̋�`�𔻒肵�āA�t���O���w�肷��@true || false 
	/// true �̏ꍇ�@�`��A�@false �̏ꍇ�@�`�悳���Ȃ��B
	/// </summary>
}

void Stage::Draw()
{
	int MapDrawPointX = -Character::GetPos().x + ((640 / 20 + 2) / 2 - 1);
	int MapDrawPointY = -Character::GetPos().y + ((640 / 20 + 2) / 2 - 1);
	
	int numcount = 0;
	for (int y = 0; y < StageHeigh; y++)
	{
		for (int x = 0; x < StageWidth; x++)
		{
			//��ʊO�̃X�e�[�W�I�u�W�F�N�g�̓J�����O
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
